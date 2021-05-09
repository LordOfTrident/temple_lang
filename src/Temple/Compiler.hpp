#pragma once

#include "./INCLUDE"

#include "./Token.hpp"
#include "./Script.hpp"
#include "./Exception.hpp"
#include "./Bytebuffer.hpp"

namespace LOT {
    namespace Temple {
        enum CompilerExitcodes {
            COMPILER_OK,
            COMPILER_ERROR
        };

        class Compiler {
        public: Compiler() {};
            void Assign(LOT::Temple::Script *p_Script, LOT::Temple::Bytebuffer *p_Bytecode) {Script = p_Script; Bytecode = p_Bytecode;};
            std::vector <LOT::Temple::Token> Extract() {return Script->Tokens;};

            int Compile() {
                for (int i = 0; i < (int)Script->Tokens.size(); ++ i) {
                    LOT::Temple::Token *token = &Script->Tokens[i];

                    if (token->Type == LOT::Temple::TokenTypes::INSTRUCTION) {
                        switch (token->Data) {
                            case LOT::Temple::InstructionTokens::PUSH: {
                                if (Script->Tokens[i + 1].Type == LOT::Temple::TokenTypes::NUMBER) {
                                    Bytecode->Write8(LOT::Temple::Opcode::PUSH_OP);
                                    Bytecode->Write32(Script->Tokens[i + 1].Data);

                                    ++ i;
                                } else {
                                    std::cout << LOT::Temple::Exception::Throw("Unexpected token after push", Script->Tokens[i + 1].Line, true) << std::endl;

                                    return LOT::Temple::CompilerExitcodes::COMPILER_ERROR;
                                };

                                break;
                            };

                            case LOT::Temple::InstructionTokens::POP: { 
                                Bytecode->Write8(LOT::Temple::Opcode::POP_OP);

                                break;
                            };

                            case LOT::Temple::InstructionTokens::HALT: { 
                                Bytecode->Write8(LOT::Temple::Opcode::HALT_OP);

                                break;
                            };

                            case LOT::Temple::InstructionTokens::ADD: { 
                                Bytecode->Write8(LOT::Temple::Opcode::ADD_OP);

                                break;
                            };

                            case LOT::Temple::InstructionTokens::SUBSTRACT: {
                                Bytecode->Write8(LOT::Temple::Opcode::SUB_OP);

                                break;
                            };

                            case LOT::Temple::InstructionTokens::MULTIPLY: {
                                Bytecode->Write8(LOT::Temple::Opcode::MULT_OP);

                                break;
                            };

                            case LOT::Temple::InstructionTokens::DIVIDE: {
                                Bytecode->Write8(LOT::Temple::Opcode::DIV_OP);

                                break;
                            };

                            case LOT::Temple::InstructionTokens::MODULUS: {
                                Bytecode->Write8(LOT::Temple::Opcode::MOD_OP);

                                break;
                            };

                            default: {
                                std::cout << LOT::Temple::Exception::Throw("Unknown token", Script->Tokens[i + 1].Line, true) << std::endl;

                                return LOT::Temple::CompilerExitcodes::COMPILER_ERROR;
                            };
                        };
                    };
                };

                return LOT::Temple::CompilerExitcodes::COMPILER_OK;
            };
        
        private:
            LOT::Temple::Script *Script;
            LOT::Temple::Bytebuffer *Bytecode;
        };
    };
};