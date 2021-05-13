#pragma once

#include "./INCLUDE"

namespace LOT {
    namespace Temple {
        enum TokenTypes {
            INSTRUCTION,
            NUMBER
        };

        enum InstructionTokens {
            PUSH,
            POP,
            HALT,

            ADD,
            SUBSTRACT,

            MULTIPLY,
            DIVIDE,
            MODULUS,
            INCREMENT,

            OUT,
            OUTCHAR
        };

        class Token {
        public: Token(int p_Type, int p_Data, int p_Line);

            int Type, Data, Line;
        };
    };
};