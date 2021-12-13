#pragma once

namespace Eric::VM {
    enum OPCode : int32_t {
        ICONST      = -1,
        IADD        = -2,
        IF_ICMP_EQ  = -3,
        LOCAL       = -4,
        CALL        = -5,
        RET         = -6,
        PRINT       = -7,
        NO_OP       = -8,
        HALT        = -9,
    };
}