#pragma once

#include "./INCLUDE"

#include "./token.hpp"
#include "./script.hpp"
#include "./exception.hpp"

namespace LOT {
    namespace Temple {
        enum ParserExitcodes {
            PARSER_OK,
            PARSER_SYNTAX_ERROR
        };

        class Parser {
        public: Parser();
            void Assign(LOT::Temple::Script *p_Script);
            std::vector <LOT::Temple::Token> Extract();
            int Parse();

        private:
            LOT::Temple::Script *Script;

            uint32_t GetNumber(std::string p_Tok);
            uint32_t GetHexNumber(std::string p_Tok);
            uint32_t GetCharNumber(std::string p_Tok);
            int GetInstruction(std::string p_Tok);
            int GetRegister(std::string p_Tok);
        };
    };
};