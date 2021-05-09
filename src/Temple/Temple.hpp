#pragma once

#include "./INCLUDE"

#include "./Parser.hpp"

namespace LOT {
    namespace Temple {
        class Temple {
        public: Temple() {};
            int Compile(std::string p_Code) {
                LOT::Temple::Script script(p_Code);
                //parser.Assign(&script); return parser.Parse(); -- non-debug
                parser.Assign(&script); int result = parser.Parse(); // -- debug

                script.Debug_PrintTokens();

                return result;
            };

        private:
            LOT::Temple::Parser parser;
        };
    };
};