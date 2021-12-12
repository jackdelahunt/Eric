#pragma once
#include "c_array.h"
#include <string.h>

#define PAGE_SIZE sizeof(u_int64_t)

class Heap {
public:
    Heap();

    template<typename T>
    u_int16_t alloc(T* t) {
        auto start_location = heap_ptr;
        memcpy(&data[start_location], t, PAGE_SIZE);
        heap_ptr += PAGE_SIZE;
        return start_location;
    }

    u_int64_t lookup(u_int16_t address) {
        return data[address];
    }

private:
    size_t heap_ptr;
    u_int8_t * data;
};


