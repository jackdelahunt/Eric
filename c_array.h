#pragma once
#include <cstdlib>
#include "exception.h"

template <typename T>
class dyn_c_array {
public:
    int length;
    int capacity;
    T* data;

    dyn_c_array(){
        length = 0;
        capacity = 1;
        data = (T *)malloc(capacity * sizeof(T));
    }

    void append(T value) {
        if(length + 1 >= capacity) grow();
        data[length++] = value;
    }

    T& at(size_t index) {
        return data[index];
    }

private:
    void grow() {
        data = (T *)realloc(data, (capacity * 1.5) * sizeof(T));
    }
};

static const size_t capacity = 10;

template <typename T>
class static_c_array {
public:
    size_t length = capacity;
    T data[capacity];

    void set(size_t index, T value) {
        if(index < 0 || index >= capacity) THROW("index out of bounds")
        data[index] = value;
    }

    T& at(size_t index) {
        return data[index];
    }
};



