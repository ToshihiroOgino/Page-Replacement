#include "paging.hpp"

bool LRU::browse_page(Page page) {
    clock += 1;
    int idx = 0;
    int min_recently_used = clock;
    bool pagefault = true;

    for (int i = 0; i < PAGE_TABLE_SIZE; i++) {
        if (page == page_table[i]) {
            page_info[i] = clock;
            pagefault = false;
            break;
        } else if (min_recently_used > page_info[i]) {
            idx = i;
            min_recently_used = page_info[i];
        }
        if (min_recently_used == 0)
            break;
    }

    if (pagefault) {
        page_table[idx] = page;
        page_info[idx] = clock;
    }
    if (debug_mode) {
        printf("%2d:%c %c ", clock, page, pagefault ? 'O' : 'X');
        print_page_table();
    }
    return pagefault;
}
