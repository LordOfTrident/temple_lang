#pragma once

#include "./INCLUDE"

#include "./bytebuffer.hpp"
#include "./bytecode.hpp"
#include "./stack.hpp"
#include "./asciicolors.hpp"
#include "./exception.hpp"

namespace LOT {
    namespace Temple {
        class Runtime {
        public: Runtime();
            void Assign(std::vector <uint8_t> p_Code);
            int Run();

            uint8_t Read8();
            uint16_t Read16();
            uint32_t Read32();

        private:
            std::vector <uint8_t> Code;
            LOT::Temple::Stack Stack;
            std::vector <uint32_t> Registers;
            bool running;
            uint32_t InstructionPointer;
        };
    };
};