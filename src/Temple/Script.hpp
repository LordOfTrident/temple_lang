#pragma once

#include "./INCLUDE"

#include "./Token.hpp"

namespace LOT {
    namespace Temple {
        class Script {
        public: Script(std::string p_Code): Source(p_Code) {};
            std::vector <LOT::Temple::Token> GetAll() {return Tokens;};
            void Add(LOT::Temple::Token p_Token) {Tokens.push_back(p_Token);};

            void Debug_PrintTokens() {
                for (int i = 0; i < (int)Tokens.size(); ++ i) {
                    std::cout << "[" << Tokens[i].Type << ":" << Tokens[i].Data << "|" << Tokens[i].Line << "];" << std::endl;
                };
            };

            std::string Source;
            
        private:
            std::vector <LOT::Temple::Token> Tokens;
        };
    };
};