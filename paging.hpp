#ifndef BASE_HPP_
#define BASE_HPP_

#include <queue>
#include <stdio.h>
using namespace std;
typedef char Page;
#define PAGE_TABLE_SIZE 8

class base {
  protected:
    int clock;
    Page page_table[PAGE_TABLE_SIZE];
    int page_info[PAGE_TABLE_SIZE];
    bool debug_mode = false;

  public:
    base() {
        clock = 0;
        for (int i = 0; i < PAGE_TABLE_SIZE; i++) {
            page_table[i] = 0;
            page_info[i] = 0;
        }
    }
    void print_page_table();
    // @return int Page faultの発生回数
    int process_queue(queue<Page> que);
    void enable_debug_mode();
    virtual bool browse_page(Page page) { return false; }
};

class FINUFO final : public base {
  public:
    bool browse_page(Page page);
};

class LFU final : public base {
  public:
    bool browse_page(Page page);
};

class LRU final : public base {
  public:
    bool browse_page(Page page);
};

#endif /* BASE_HPP_ */
