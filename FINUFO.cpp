#include "paging.hpp"

bool FINUFO::browse_page(Page page) {
    clock += 1;
    int idx = 0;
    int min_clock = clock;
    bool pagefault = true;

    for (int i = 0; i < PAGE_TABLE_SIZE; i++) {
        if (page == page_table[i]) {
            pagefault = false;
            break;
        } else if (min_clock > page_info[i]) {
            idx = i;
            min_clock = page_info[i];
        }
        if (min_clock == 0)
            break;
    }

    if (pagefault) {
        page_table[idx] = page;
        page_info[idx] = clock;
        if (debug_mode) {
            printf("%4d:%c %c ", clock, page, pagefault ? 'O' : 'X');
            print_page_table();
        }
    }
    return pagefault;
}
