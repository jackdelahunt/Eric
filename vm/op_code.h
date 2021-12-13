#pragma once

namespace Eric::VM {
    enum OPCode : int32_t {
        ICONST = 1,
        IADD = 2,
        IF_ICMP_EQ = 3,
        PRINT = 4,
        HALT = 5,
    };
}