#pragma once

#include "./INCLUDE"

#include "./Token.hpp"
#include "./Script.hpp"
#include "./Exception.hpp"

namespace LOT {
    namespace Temple {
        enum ParserExitcodes {
            PARSER_OK,
            PARSER_SYNTAX_ERROR
        };

        class Parser {
        public: Parser() {};
            void Assign(LOT::Temple::Script *p_Script) {Script = p_Script;};
            std::vector <LOT::Temple::Token> Extract() {return Script->Tokens;};

            int Parse() {
                unsigned int idx = 0;
                std::string token;
                unsigned int line = 1;

                while (!(idx > Script->Source.length() - 1)) {
                    token = "";

                    while ((int)std::string(" \n \0 \t").find(Script->Source[idx]) == -1 && !(idx > Script->Source.length() - 1)) token += Script->Source[idx ++];

                    // Checking if the token is a number
                    if (token[0] == '#') {
                        int number = GetNumber(token);
                        Script->Add(LOT::Temple::Token(LOT::Temple::TokenTypes::NUMBER, number, line));
                    // Else its an instruction
                    } else {
                        int instruction = GetInstruction(token);
                        if (instruction < 0) {
                            std::cout << LOT::Temple::Exception::Throw("Unknown instruction \"" + token + "\"", line, true) << std::endl;

                            return LOT::Temple::ParserExitcodes::PARSER_SYNTAX_ERROR;
                        } else Script->Add(LOT::Temple::Token(LOT::Temple::TokenTypes::INSTRUCTION, instruction, line));
                    };

                    // Line counter
                    if (Script->Source[idx] == '\n') ++ line;
                    ++ idx;
                };

                return LOT::Temple::ParserExitcodes::PARSER_OK;
            };

        private:
            LOT::Temple::Script *Script;

            uint32_t GetNumber(std::string p_Tok) {
                long int number = std::stoi(p_Tok.substr(1, p_Tok.length() - 1));

                return number <= UINT32_MAX? number : 0;
            };

            int GetInstruction(std::string p_Tok) {
                if (p_Tok == "push") return LOT::Temple::InstructionTokens::PUSH;
                if (p_Tok == "pop") return LOT::Temple::InstructionTokens::POP;
                if (p_Tok == "halt") return LOT::Temple::InstructionTokens::HALT;
                if (p_Tok == "add") return LOT::Temple::InstructionTokens::ADD;
                if (p_Tok == "sub") return LOT::Temple::InstructionTokens::SUBSTRACT;
                if (p_Tok == "mult") return LOT::Temple::InstructionTokens::MULTIPLY;
                if (p_Tok == "div") return LOT::Temple::InstructionTokens::DIVIDE;
                if (p_Tok == "mod") return LOT::Temple::InstructionTokens::MODULUS;
                
                return -1;
            };
        };
    };
};