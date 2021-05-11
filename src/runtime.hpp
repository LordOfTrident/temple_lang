#pragma once

#include "./INCLUDE"

#include "./bytebuffer.hpp"
#include "./bytecode.hpp"
#include "./stack.hpp"

namespace LOT {
    namespace Temple {
        class Runtime {
        public: Runtime();
            void Assign(std::vector <uint8_t> p_Code);
            int Run();

            uint16_t Read16();
            uint32_t Read32();

        private:
            std::vector <uint8_t> Code;
            LOT::Temple::Stack Stack;
            bool running;
            uint8_t exitcode;
            uint32_t InstructionPointer;
        };
    };
};