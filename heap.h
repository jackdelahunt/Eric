#pragma once
#include "c_array.h"
#include <string.h>

class Heap {
public:
    Heap();

    template<typename T>
    u_int16_t alloc(T* t) {
        auto start_location = heap_ptr;
        auto end_location = heap_ptr + sizeof(T);
        memcpy(&data[start_location], t, sizeof(T));
        heap_ptr = end_location;
        return start_location;
    }

private:
    size_t heap_ptr;
    u_int8_t * data;
};


