#pragma once

#include "./INCLUDE"

#include "./parser.hpp"
#include "./compiler.hpp"
#include "./utils.hpp"

namespace LOT {
    namespace Temple {
        class Temple {
        public: Temple();
            int Compile(std::string p_OutputName, std::string p_Code);

        private:
            LOT::Temple::Parser parser;
            LOT::Temple::Compiler compiler;
        };
    };
};