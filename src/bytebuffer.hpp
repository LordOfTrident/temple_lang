#pragma once

#include "./INCLUDE"

#include "./bytecode.hpp"

namespace LOT {
    namespace Temple {
        class Bytebuffer {
        public: Bytebuffer(int p_Size);
            void Write8(uint8_t p_Data);
            void Write16(uint16_t p_Data);
            void Write32(uint32_t p_Data);
            void Back();

            std::vector <uint8_t> Buffer;
            int Pointer;
        };
    };
};