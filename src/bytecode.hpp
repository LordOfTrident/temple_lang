#pragma once

#include "./INCLUDE"

namespace LOT {
    namespace Temple {
        enum Opcode {
            NO_OP = 0x00,
            PUSH_OP = 0x01,
            POP_OP = 0x02,
            HALT_OP = 0xFF,

            ADD_OP = 0x10,
            SUB_OP = 0x11,

            MULT_OP = 0x12,
            DIV_OP = 0x13,
            MOD_OP = 0x14,
            INC_OP = 0x15,

            OUT_OP = 0x20,
            OUTCH_OP = 0x21
        };
    };
};