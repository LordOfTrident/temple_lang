#pragma once

#include "./INCLUDE"

#include "./token.hpp"
#include "./script.hpp"
#include "./exception.hpp"
#include "./bytebuffer.hpp"

namespace LOT {
    namespace Temple {
        enum CompilerExitcodes {
            COMPILER_OK,
            COMPILER_ERROR
        };

        class Compiler {
        public: Compiler();
            void Assign(LOT::Temple::Script *p_Script, LOT::Temple::Bytebuffer *p_Bytecode);
            std::vector <LOT::Temple::Token> Extract();
            int Compile();
        
        private:
            LOT::Temple::Script *Script;
            LOT::Temple::Bytebuffer *Bytecode;
        };
    };
};