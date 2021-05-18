#include "./compiler.hpp"

LOT::Temple::Compiler::Compiler() {};

void LOT::Temple::Compiler::Assign(LOT::Temple::Script *p_Script, LOT::Temple::Bytebuffer *p_Bytecode) {
    Script = p_Script; 
    Bytecode = p_Bytecode;
};

std::vector <LOT::Temple::Token> LOT::Temple::Compiler::Extract() {
    return Script->Tokens;
};

int LOT::Temple::Compiler::Compile() {
    for (int i = 0; i < (int)Script->Tokens.size(); ++ i) {
        LOT::Temple::Token *token = &Script->Tokens[i];

        if (token->Type == LOT::Temple::TokenTypes::INSTRUCTION) {
            switch (token->Data) {
                case LOT::Temple::InstructionTokens::PUSH: {
                    Bytecode->Write8(LOT::Temple::Opcode::PUSH_OP);

                    // Parameter 1
                    switch (Script->Tokens[i + 1].Type) {

                        // Mode 0, take in a register value
                        case LOT::Temple::TokenTypes::REGISTER: {
                            Bytecode->Write8(0);
                            Bytecode->Write8(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Mode 1, take in a constant
                        case LOT::Temple::TokenTypes::NUMBER: {
                            Bytecode->Write8(1);
                            Bytecode->Write32(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Else error
                        default: {
                            std::cout << LOT::Temple::Exception::Throw("Unexpected parameter #1 at push", Script->Tokens[i + 1].Line, true) << std::endl;

                            return LOT::Temple::CompilerExitcodes::COMPILER_ERROR;
                        };
                    };

                    break;
                };

                case LOT::Temple::InstructionTokens::GOTO: {
                    Bytecode->Write8(LOT::Temple::Opcode::GOTO_OP);

                    // Parameter 1
                    switch (Script->Tokens[i + 1].Type) {

                        // Mode 0, take in a register value
                        case LOT::Temple::TokenTypes::REGISTER: {
                            Bytecode->Write8(0);
                            Bytecode->Write8(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Mode 1, take in a constant
                        case LOT::Temple::TokenTypes::NUMBER: {
                            Bytecode->Write8(1);
                            Bytecode->Write32(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Else error
                        default: {
                            std::cout << LOT::Temple::Exception::Throw("Unexpected parameter #1 at goto", Script->Tokens[i + 1].Line, true) << std::endl;

                            return LOT::Temple::CompilerExitcodes::COMPILER_ERROR;
                        };
                    };

                    break;
                };

                case LOT::Temple::InstructionTokens::EQUALGOTO: {
                    Bytecode->Write8(LOT::Temple::Opcode::EGOTO_OP);

                    // Parameter 1
                    switch (Script->Tokens[i + 1].Type) {

                        // Mode 0, take in a register value
                        case LOT::Temple::TokenTypes::REGISTER: {
                            Bytecode->Write8(0);
                            Bytecode->Write8(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Mode 1, take in a constant
                        case LOT::Temple::TokenTypes::NUMBER: {
                            Bytecode->Write8(1);
                            Bytecode->Write32(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Else error
                        default: {
                            std::cout << LOT::Temple::Exception::Throw("Unexpected parameter #1 at egoto", Script->Tokens[i + 1].Line, true) << std::endl;

                            return LOT::Temple::CompilerExitcodes::COMPILER_ERROR;
                        };
                    };

                    break;
                };

                case LOT::Temple::InstructionTokens::NOTEQUALGOTO: {
                    Bytecode->Write8(LOT::Temple::Opcode::NEGOTO_OP);

                    // Parameter 1
                    switch (Script->Tokens[i + 1].Type) {

                        // Mode 0, take in a register value
                        case LOT::Temple::TokenTypes::REGISTER: {
                            Bytecode->Write8(0);
                            Bytecode->Write8(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Mode 1, take in a constant
                        case LOT::Temple::TokenTypes::NUMBER: {
                            Bytecode->Write8(1);
                            Bytecode->Write32(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Else error
                        default: {
                            std::cout << LOT::Temple::Exception::Throw("Unexpected parameter #1 at negoto", Script->Tokens[i + 1].Line, true) << std::endl;

                            return LOT::Temple::CompilerExitcodes::COMPILER_ERROR;
                        };
                    };

                    break;
                };

                case LOT::Temple::InstructionTokens::GREATERGOTO: {
                    Bytecode->Write8(LOT::Temple::Opcode::GGOTO_OP);

                    // Parameter 1
                    switch (Script->Tokens[i + 1].Type) {

                        // Mode 0, take in a register value
                        case LOT::Temple::TokenTypes::REGISTER: {
                            Bytecode->Write8(0);
                            Bytecode->Write8(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Mode 1, take in a constant
                        case LOT::Temple::TokenTypes::NUMBER: {
                            Bytecode->Write8(1);
                            Bytecode->Write32(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Else error
                        default: {
                            std::cout << LOT::Temple::Exception::Throw("Unexpected parameter #1 at ggoto", Script->Tokens[i + 1].Line, true) << std::endl;

                            return LOT::Temple::CompilerExitcodes::COMPILER_ERROR;
                        };
                    };

                    break;
                };

                case LOT::Temple::InstructionTokens::LESSGOTO: {
                    Bytecode->Write8(LOT::Temple::Opcode::LGOTO_OP);

                    // Parameter 1
                    switch (Script->Tokens[i + 1].Type) {

                        // Mode 0, take in a register value
                        case LOT::Temple::TokenTypes::REGISTER: {
                            Bytecode->Write8(0);
                            Bytecode->Write8(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Mode 1, take in a constant
                        case LOT::Temple::TokenTypes::NUMBER: {
                            Bytecode->Write8(1);
                            Bytecode->Write32(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Else error
                        default: {
                            std::cout << LOT::Temple::Exception::Throw("Unexpected parameter #1 at lgoto", Script->Tokens[i + 1].Line, true) << std::endl;

                            return LOT::Temple::CompilerExitcodes::COMPILER_ERROR;
                        };
                    };

                    break;
                };

                case LOT::Temple::InstructionTokens::POP: { 
                    Bytecode->Write8(LOT::Temple::Opcode::POP_OP);

                    // Parameter 1
                    switch (Script->Tokens[i + 1].Type) {

                        // Mode 0, take in a register
                        case LOT::Temple::TokenTypes::REGISTER: {
                            Bytecode->Write8(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Else error
                        default: {
                            std::cout << LOT::Temple::Exception::Throw("Unexpected parameter #1 at pop", Script->Tokens[i + 1].Line, true) << std::endl;

                            return LOT::Temple::CompilerExitcodes::COMPILER_ERROR;
                        };
                    };

                    break;
                };

                case LOT::Temple::InstructionTokens::SLOAD: {
                    Bytecode->Write8(LOT::Temple::Opcode::SLOAD_OP);

                    // Parameter 1
                    switch (Script->Tokens[i + 1].Type) {

                        // Mode 0, take in a register value
                        case LOT::Temple::TokenTypes::REGISTER: {
                            Bytecode->Write8(0);
                            Bytecode->Write8(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Mode 1, take in a constant
                        case LOT::Temple::TokenTypes::NUMBER: {
                            Bytecode->Write8(1);
                            Bytecode->Write32(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Else error
                        default: {
                            std::cout << LOT::Temple::Exception::Throw("Unexpected parameter #1 at sload", Script->Tokens[i + 1].Line, true) << std::endl;

                            return LOT::Temple::CompilerExitcodes::COMPILER_ERROR;
                        };
                    };

                    // Parameter 2
                    switch (Script->Tokens[i + 1].Type) {

                        // Mode 0, take in a register value
                        case LOT::Temple::TokenTypes::REGISTER: {
                            Bytecode->Write8(0);
                            Bytecode->Write8(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Mode 1, take in a constant
                        case LOT::Temple::TokenTypes::NUMBER: {
                            Bytecode->Write8(1);
                            Bytecode->Write32(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Else error
                        default: {
                            std::cout << LOT::Temple::Exception::Throw("Unexpected parameter #2 at sload", Script->Tokens[i + 1].Line, true) << std::endl;

                            return LOT::Temple::CompilerExitcodes::COMPILER_ERROR;
                        };
                    };

                    break;
                };

                case LOT::Temple::InstructionTokens::LOAD: {
                    Bytecode->Write8(LOT::Temple::Opcode::LOAD_OP);

                    // Parameter 1
                    switch (Script->Tokens[i + 1].Type) {

                        // Mode 0, take in a register value
                        case LOT::Temple::TokenTypes::REGISTER: {
                            Bytecode->Write8(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Else error
                        default: {
                            std::cout << LOT::Temple::Exception::Throw("Unexpected parameter #1 at load", Script->Tokens[i + 1].Line, true) << std::endl;

                            return LOT::Temple::CompilerExitcodes::COMPILER_ERROR;
                        };
                    };

                    // Parameter 2
                    switch (Script->Tokens[i + 1].Type) {

                        // Mode 0, take in a register value
                        case LOT::Temple::TokenTypes::REGISTER: {
                            Bytecode->Write8(0);
                            Bytecode->Write8(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Mode 1, take in a constant
                        case LOT::Temple::TokenTypes::NUMBER: {
                            Bytecode->Write8(1);
                            Bytecode->Write32(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Else error
                        default: {
                            std::cout << LOT::Temple::Exception::Throw("Unexpected parameter #2 at load", Script->Tokens[i + 1].Line, true) << std::endl;

                            return LOT::Temple::CompilerExitcodes::COMPILER_ERROR;
                        };
                    };

                    break;
                };

                case LOT::Temple::InstructionTokens::HALT: { 
                    Bytecode->Write8(LOT::Temple::Opcode::HALT_OP);

                    break;
                };

                case LOT::Temple::InstructionTokens::COMPARE: { 
                    Bytecode->Write8(LOT::Temple::Opcode::COMP_OP);

                    // Parameter 1
                    switch (Script->Tokens[i + 1].Type) {

                        // Mode 0, take in a register value
                        case LOT::Temple::TokenTypes::REGISTER: {
                            Bytecode->Write8(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Else error
                        default: {
                            std::cout << LOT::Temple::Exception::Throw("Unexpected parameter #1 at add", Script->Tokens[i + 1].Line, true) << std::endl;

                            return LOT::Temple::CompilerExitcodes::COMPILER_ERROR;
                        };
                    };

                    // Parameter 2
                    switch (Script->Tokens[i + 1].Type) {

                        // Mode 0, take in a register value
                        case LOT::Temple::TokenTypes::REGISTER: {
                            Bytecode->Write8(0);
                            Bytecode->Write8(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Mode 1, take in a constant
                        case LOT::Temple::TokenTypes::NUMBER: {
                            Bytecode->Write8(1);
                            Bytecode->Write32(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Else error
                        default: {
                            std::cout << LOT::Temple::Exception::Throw("Unexpected parameter #2 at add", Script->Tokens[i + 1].Line, true) << std::endl;

                            return LOT::Temple::CompilerExitcodes::COMPILER_ERROR;
                        };
                    };

                    break;
                };

                case LOT::Temple::InstructionTokens::ADD: { 
                    Bytecode->Write8(LOT::Temple::Opcode::ADD_OP);

                    // Parameter 1
                    switch (Script->Tokens[i + 1].Type) {

                        // Mode 0, take in a register value
                        case LOT::Temple::TokenTypes::REGISTER: {
                            Bytecode->Write8(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Else error
                        default: {
                            std::cout << LOT::Temple::Exception::Throw("Unexpected parameter #1 at add", Script->Tokens[i + 1].Line, true) << std::endl;

                            return LOT::Temple::CompilerExitcodes::COMPILER_ERROR;
                        };
                    };

                    // Parameter 2
                    switch (Script->Tokens[i + 1].Type) {

                        // Mode 0, take in a register value
                        case LOT::Temple::TokenTypes::REGISTER: {
                            Bytecode->Write8(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Else error
                        default: {
                            std::cout << LOT::Temple::Exception::Throw("Unexpected parameter #2 at add", Script->Tokens[i + 1].Line, true) << std::endl;

                            return LOT::Temple::CompilerExitcodes::COMPILER_ERROR;
                        };
                    };

                    // Parameter 3
                    switch (Script->Tokens[i + 1].Type) {

                        // Mode 0, take in a register value
                        case LOT::Temple::TokenTypes::REGISTER: {
                            Bytecode->Write8(0);
                            Bytecode->Write8(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Mode 1, take in a constant
                        case LOT::Temple::TokenTypes::NUMBER: {
                            Bytecode->Write8(1);
                            Bytecode->Write32(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Else error
                        default: {
                            std::cout << LOT::Temple::Exception::Throw("Unexpected parameter #3 at add", Script->Tokens[i + 1].Line, true) << std::endl;

                            return LOT::Temple::CompilerExitcodes::COMPILER_ERROR;
                        };
                    };

                    break;
                };

                case LOT::Temple::InstructionTokens::SUBSTRACT: { 
                    Bytecode->Write8(LOT::Temple::Opcode::SUB_OP);

                    // Parameter 1
                    switch (Script->Tokens[i + 1].Type) {

                        // Mode 0, take in a register value
                        case LOT::Temple::TokenTypes::REGISTER: {
                            Bytecode->Write8(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Else error
                        default: {
                            std::cout << LOT::Temple::Exception::Throw("Unexpected parameter #1 at sub", Script->Tokens[i + 1].Line, true) << std::endl;

                            return LOT::Temple::CompilerExitcodes::COMPILER_ERROR;
                        };
                    };

                    // Parameter 2
                    switch (Script->Tokens[i + 1].Type) {

                        // Mode 0, take in a register value
                        case LOT::Temple::TokenTypes::REGISTER: {
                            Bytecode->Write8(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Else error
                        default: {
                            std::cout << LOT::Temple::Exception::Throw("Unexpected parameter #2 at sub", Script->Tokens[i + 1].Line, true) << std::endl;

                            return LOT::Temple::CompilerExitcodes::COMPILER_ERROR;
                        };
                    };

                    // Parameter 3
                    switch (Script->Tokens[i + 1].Type) {

                        // Mode 0, take in a register value
                        case LOT::Temple::TokenTypes::REGISTER: {
                            Bytecode->Write8(0);
                            Bytecode->Write8(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Mode 1, take in a constant
                        case LOT::Temple::TokenTypes::NUMBER: {
                            Bytecode->Write8(1);
                            Bytecode->Write32(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Else error
                        default: {
                            std::cout << LOT::Temple::Exception::Throw("Unexpected parameter #3 at sub", Script->Tokens[i + 1].Line, true) << std::endl;

                            return LOT::Temple::CompilerExitcodes::COMPILER_ERROR;
                        };
                    };

                    break;
                };

                case LOT::Temple::InstructionTokens::MULTIPLY: { 
                    Bytecode->Write8(LOT::Temple::Opcode::MULT_OP);

                    // Parameter 1
                    switch (Script->Tokens[i + 1].Type) {

                        // Mode 0, take in a register value
                        case LOT::Temple::TokenTypes::REGISTER: {
                            Bytecode->Write8(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Else error
                        default: {
                            std::cout << LOT::Temple::Exception::Throw("Unexpected parameter #1 at mult", Script->Tokens[i + 1].Line, true) << std::endl;

                            return LOT::Temple::CompilerExitcodes::COMPILER_ERROR;
                        };
                    };

                    // Parameter 2
                    switch (Script->Tokens[i + 1].Type) {

                        // Mode 0, take in a register value
                        case LOT::Temple::TokenTypes::REGISTER: {
                            Bytecode->Write8(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Else error
                        default: {
                            std::cout << LOT::Temple::Exception::Throw("Unexpected parameter #2 at mult", Script->Tokens[i + 1].Line, true) << std::endl;

                            return LOT::Temple::CompilerExitcodes::COMPILER_ERROR;
                        };
                    };

                    // Parameter 3
                    switch (Script->Tokens[i + 1].Type) {

                        // Mode 0, take in a register value
                        case LOT::Temple::TokenTypes::REGISTER: {
                            Bytecode->Write8(0);
                            Bytecode->Write8(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Mode 1, take in a constant
                        case LOT::Temple::TokenTypes::NUMBER: {
                            Bytecode->Write8(1);
                            Bytecode->Write32(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Else error
                        default: {
                            std::cout << LOT::Temple::Exception::Throw("Unexpected parameter #3 at mult", Script->Tokens[i + 1].Line, true) << std::endl;

                            return LOT::Temple::CompilerExitcodes::COMPILER_ERROR;
                        };
                    };

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

                case LOT::Temple::InstructionTokens::INCREMENT: {
                    Bytecode->Write8(LOT::Temple::Opcode::INC_OP);

                    // Parameter 1
                    switch (Script->Tokens[i + 1].Type) {

                        // Mode 0, take in a register
                        case LOT::Temple::TokenTypes::REGISTER: {
                            Bytecode->Write8(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Else error
                        default: {
                            std::cout << LOT::Temple::Exception::Throw("Unexpected parameter #1 at inc", Script->Tokens[i + 1].Line, true) << std::endl;

                            return LOT::Temple::CompilerExitcodes::COMPILER_ERROR;
                        };
                    };

                    break;
                };

                case LOT::Temple::InstructionTokens::DECREMENT: {
                    Bytecode->Write8(LOT::Temple::Opcode::DEC_OP);

                    // Parameter 1
                    switch (Script->Tokens[i + 1].Type) {

                        // Mode 0, take in a register
                        case LOT::Temple::TokenTypes::REGISTER: {
                            Bytecode->Write8(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Else error
                        default: {
                            std::cout << LOT::Temple::Exception::Throw("Unexpected parameter #1 at dec", Script->Tokens[i + 1].Line, true) << std::endl;

                            return LOT::Temple::CompilerExitcodes::COMPILER_ERROR;
                        };
                    };

                    break;
                };

                case LOT::Temple::InstructionTokens::OUTCHAR: {
                    Bytecode->Write8(LOT::Temple::Opcode::OUTCH_OP);

                    // Parameter 1
                    switch (Script->Tokens[i + 1].Type) {

                        // Mode 0, take in a register
                        case LOT::Temple::TokenTypes::REGISTER: {
                            Bytecode->Write8(0);
                            Bytecode->Write8(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Mode 1, take in a constant
                        case LOT::Temple::TokenTypes::NUMBER: {
                            Bytecode->Write8(1);
                            Bytecode->Write32(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Else error
                        default: {
                            std::cout << LOT::Temple::Exception::Throw("Unexpected parameter #1 at outch", Script->Tokens[i + 1].Line, true) << std::endl;

                            return LOT::Temple::CompilerExitcodes::COMPILER_ERROR;
                        };
                    };

                    // Parameter 2
                    switch (Script->Tokens[i + 1].Type) {

                        // Mode 0, take in a register
                        case LOT::Temple::TokenTypes::REGISTER: {
                            Bytecode->Write8(0);
                            Bytecode->Write8(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Mode 1, take in a constant
                        case LOT::Temple::TokenTypes::NUMBER: {
                            Bytecode->Write8(1);
                            Bytecode->Write32(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Else error
                        default: {
                            std::cout << LOT::Temple::Exception::Throw("Unexpected parameter #2 at outch", Script->Tokens[i + 1].Line, true) << std::endl;

                            return LOT::Temple::CompilerExitcodes::COMPILER_ERROR;
                        };
                    };

                    break;
                };

                case LOT::Temple::InstructionTokens::OUT: {
                    Bytecode->Write8(LOT::Temple::Opcode::OUT_OP);

                    // Parameter 1
                    switch (Script->Tokens[i + 1].Type) {

                        // Mode 0, take in a register
                        case LOT::Temple::TokenTypes::REGISTER: {
                            Bytecode->Write8(0);
                            Bytecode->Write8(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Mode 1, take in a constant
                        case LOT::Temple::TokenTypes::NUMBER: {
                            Bytecode->Write8(1);
                            Bytecode->Write32(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Else error
                        default: {
                            std::cout << LOT::Temple::Exception::Throw("Unexpected parameter #1 at out", Script->Tokens[i + 1].Line, true) << std::endl;

                            return LOT::Temple::CompilerExitcodes::COMPILER_ERROR;
                        };
                    };

                    break;
                };

                case LOT::Temple::InstructionTokens::OUTSTRING: {
                    Bytecode->Write8(LOT::Temple::Opcode::OUTSTR_OP);

                    // Parameter 1
                    switch (Script->Tokens[i + 1].Type) {

                        // Mode 0, take in a register
                        case LOT::Temple::TokenTypes::REGISTER: {
                            Bytecode->Write8(0);
                            Bytecode->Write8(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Mode 1, take in a constant
                        case LOT::Temple::TokenTypes::NUMBER: {
                            Bytecode->Write8(1);
                            Bytecode->Write32(Script->Tokens[i + 1].Data);

                            ++ i;

                            break;
                        };

                        // Else error
                        default: {
                            std::cout << LOT::Temple::Exception::Throw("Unexpected parameter #1 at outstr", Script->Tokens[i + 1].Line, true) << std::endl;

                            return LOT::Temple::CompilerExitcodes::COMPILER_ERROR;
                        };
                    };

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