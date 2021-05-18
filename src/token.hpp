#pragma once

#include "./INCLUDE"

namespace LOT {
    namespace Temple {
        enum TokenTypes {
            INSTRUCTION,
            NUMBER,
            REGISTER
        };

        enum InstructionTokens {
            PUSH,
            POP,
            HALT,

            LOAD,
            SLOAD,

            GOTO,
            EQUALGOTO,
            LESSGOTO,
            GREATERGOTO,
            NOTEQUALGOTO,

            ADD,
            SUBSTRACT,

            MULTIPLY,
            DIVIDE,
            MODULUS,

            INCREMENT,
            DECREMENT,

            COMPARE,

            OUT,
            OUTCHAR,
            OUTSTRING
        };

        enum RegisterTokens {
            R0,
            R1,
            R2,
            R3,
            R4,
            R5,
            R6,
            R7,
            R8,
            R9,
            IP,
            SP,
            EX,
            COND
        };

        class Token {
        public: Token(int p_Type, int p_Data, int p_Line);

            int Type, Data, Line;
        };
    };
};