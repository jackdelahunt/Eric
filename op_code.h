#pragma once

namespace Eric {
    enum OPCode : char8_t {
        ADD = 1,
        LOAD = 2,
        SET_VAR = 3,
        GET_VAR = 4,
        MOV = 5,
    };
}