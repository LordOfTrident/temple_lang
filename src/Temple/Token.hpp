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
            MODULUS
        };

        /*namespace TokenTypes {
            inline const uint8_t INSTRUCTION = 0;
            inline const uint8_t NUMBER = 1;
        };

        namespace InstructionTokens {
            inline const uint8_t PUSH = 0;
            inline const uint8_t POP = 1;
            inline const uint8_t HALT = 2;
            
            inline const uint8_t ADD = 3;
            inline const uint8_t SUBSTRACT = 4;

            inline const uint8_t MULTIPLY = 5;
            inline const uint8_t DIVIDE = 6;
            inline const uint8_t MODULUS = 7;
        };*/

        class Token {
        public: Token(int p_Type, int p_Data, int p_Line):
            Type(p_Type),
            Data(p_Data),
            Line(p_Line) {};

            int Type, Data, Line;
        };
    };
};