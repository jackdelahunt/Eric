#include "heap.h"

Heap::Heap() {
    data = (u_int8_t*)malloc(65536);
    heap_ptr = 0;
}