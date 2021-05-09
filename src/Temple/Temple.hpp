#pragma once

#include "./INCLUDE"

#include "./Parser.hpp"
#include "./Compiler.hpp"

namespace LOT {
    namespace Temple {
        class Temple {
        public: Temple() {};
            int Compile(std::string p_Code) {
                LOT::Temple::Script script(p_Code);
                int result;

                parser.Assign(&script); result = parser.Parse();

                script.Debug_PrintTokens();

                if (result != LOT::Temple::ParserExitcodes::PARSER_OK) return result;

                LOT::Temple::Bytebuffer Bytecode(0);
                compiler.Assign(&script, &Bytecode); result = compiler.Compile();

                if (result != LOT::Temple::ParserExitcodes::PARSER_OK) return result;

                LOT::Temple::WriteBinFile("a.tmbc", &Bytecode);

                return result;
            };

        private:
            LOT::Temple::Parser parser;
            LOT::Temple::Compiler compiler;
        };
    };
};