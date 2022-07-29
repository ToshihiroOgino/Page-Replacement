#include "paging.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>

#define QUEUE_SIZE 256

queue<Page> random_que() {
    queue<Page> que;
    for (int i = 0; i < QUEUE_SIZE; i++)
        que.push((rand() % ('Z' + 1 - 'A')) + 'A');
    return que;
}

queue<Page> small_chunk_que() {
    queue<Page> que;
    Page p;
    int n;
    for (int i = 0; i < QUEUE_SIZE; i += n) {
        p = (rand() % ('Z' + 1 - 'A')) + 'A';
        n = rand() % 5 + 1;
        for (int j = 0; j < n && i + j < QUEUE_SIZE; j++)
            que.push(p);
        i += n;
    }
    return que;
}

queue<Page> large_chunk_que() {
    queue<Page> que;
    Page p;
    int n;
    for (int i = 0; i < QUEUE_SIZE; i += n) {
        p = (rand() % ('Z' + 1 - 'A')) + 'A';
        n = rand() % 20 + 1;
        for (int j = 0; j < n && i + j < QUEUE_SIZE; j++)
            que.push(p);
        i += n;
    }
    return que;
}

int main() {
    // generate task
    srand((unsigned)time(NULL));
    queue<Page> que;
    int mode = 0;
    printf("Choose Mode (Random:0, Small Chunk:1, Large Chunk:2) ? ");
    cin >> mode;
    switch (mode) {
    case 0:
        que = random_que();
        break;
    case 1:
        que = small_chunk_que();
        break;
    case 2:
        que = large_chunk_que();
        break;
    default:
        que = random_que();
        break;
    }

    // process task
    FINUFO finufo;
    LFU lfu;
    LRU lru;
    int pf_finufo = finufo.process_queue(que);
    int pf_lfu = lfu.process_queue(que);
    int pf_lru = lru.process_queue(que);

    printf("Page Fault (Task Size = %d, Page Table Size = %d)\n", QUEUE_SIZE, PAGE_TABLE_SIZE);
    printf("  FINUFO:%3d\n", pf_finufo);
    printf("  LFU   :%3d\n", pf_lfu);
    printf("  LRU   :%3d", pf_lru);

    return 0;
}
