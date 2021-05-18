#pragma once

#include "./INCLUDE"

namespace LOT {
    namespace Temple {
        extern const uint16_t STACK_MAX_SIZE;

        class Stack {
        public: Stack();
            void Push8(uint8_t p_Data);
            void Push16(uint16_t p_Data);
            void Push32(uint32_t p_Data);

            uint8_t Pop8();
            uint16_t Pop16();
            uint32_t Pop32();
            
            std::vector <uint8_t> Buffer;
            //uint32_t Pointer;
            uint32_t *Pointer;
        };
    };
};