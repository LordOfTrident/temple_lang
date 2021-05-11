#pragma once

#include "./INCLUDE"

#include "./token.hpp"

namespace LOT {
    namespace Temple {
        class Script {
        public: Script(std::string p_Code);
            void Add(LOT::Temple::Token p_Token);

            std::string Source;
            std::vector <LOT::Temple::Token> Tokens;
        };
    };
};