#include "paging.hpp"

bool LFU::browse_page(Page page) {
    clock += 1;
    int idx = 0;
    int min_frequently = clock;
    bool pagefault = true;

    for (int i = 0; i < PAGE_TABLE_SIZE; i++) {
        if (page == page_table[i]) {
            page_info[i]++;
            pagefault = false;
            break;
        } else if (min_frequently > page_info[i]) {
            idx = i;
            min_frequently = page_info[i];
        }
        if (min_frequently == 0)
            break;
    }

    if (pagefault) {
        page_table[idx] = page;
        page_info[idx] = 1;
    }
    if (debug_mode) {
        printf("%2d:%c %c ", clock, page, pagefault ? 'O' : 'X');
        print_page_table();
    }
    return pagefault;
}
