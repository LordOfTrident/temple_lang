#pragma once

#include "./INCLUDE"

namespace LOT {
    namespace Temple {
        enum Opcode {
            NO_OP = 0x00,
            PUSH_OP = 0x01,
            POP_OP = 0x02,
            HALT_OP = 0xFF,

            LOAD_OP = 0x03,
            SLOAD_OP = 0x04,
            
            GOTO_OP = 0x05,
            EGOTO_OP = 0x06,
            LGOTO_OP = 0x07,
            GGOTO_OP = 0x08,
            NEGOTO_OP = 0x09,

            ADD_OP = 0x10,
            SUB_OP = 0x11,

            MULT_OP = 0x12,
            DIV_OP = 0x13,
            MOD_OP = 0x14,

            INC_OP = 0x15,
            DEC_OP = 0x16,

            COMP_OP = 0x17,

            OUT_OP = 0x20,
            OUTCH_OP = 0x21,
            OUTSTR_OP = 0x22
        };

        enum Registers {
            R0_REG,
            R1_REG,
            R2_REG,
            R3_REG,
            R4_REG,
            R5_REG,
            R6_REG,
            R7_REG,
            R8_REG,
            R9_REG,
            IP_REG,
            SP_REG,
            EX_REG,
            COND_REG
        };

        enum Conditions {
            EQUAL_COND,
            LESS_COND,
            GREATER_COND,
        };
    };
};