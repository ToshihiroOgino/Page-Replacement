#include "paging.hpp"

void base::print_page_table() {
    for (int i = 0; i < PAGE_TABLE_SIZE; i++) {
        if (page_table[i] != 0)
            printf("%c(%d)", page_table[i], page_info[i]);
        else
            printf("NULL");
        if (i + 1 != PAGE_TABLE_SIZE)
            printf(", ");
    }
    printf("\n");
}

int base::process_queue(queue<Page> que) {
    int count = 0;
    while (!que.empty()) {
        count += browse_page(que.front());
        que.pop();
    }
    return count;
}

void base::enable_debug_mode() {
    debug_mode = true;
}
