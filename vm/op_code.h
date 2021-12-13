#pragma once

namespace Eric::VM {
    enum OPCode : int32_t {
        ICONST = 1,
        IADD = 2,
        PRINT = 3,
        HALT = 4,
    };
}