#pragma once

#include "./INCLUDE"

#include "./parser.hpp"
#include "./compiler.hpp"
#include "./runtime.hpp"
#include "./utils.hpp"

namespace LOT {
    namespace Temple {
        class Temple {
        public: Temple();
            int Compile(std::string p_OutputName, std::string p_Code);
            int Run(std::string p_BinFileName);

        private:
            LOT::Temple::Parser parser;
            LOT::Temple::Compiler compiler;
            LOT::Temple::Runtime runtime;
        };
    };
};