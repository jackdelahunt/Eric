#pragma once

namespace Eric::VM {
    enum OPCode : int32_t {
        ICONST          = -1,
        IADD            = -2,
        IF_ICMP_EQ      = -3,
        LOCAL           = -4,
        CALL            = -5,
        CALL_TO         = -6,
        RET             = -7,
        PRINT           = -8,
        NO_OP           = -9,
        HALT            = -10,
    };
}