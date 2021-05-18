#include "./parser.hpp"

LOT::Temple::Parser::Parser() {};

void LOT::Temple::Parser::Assign(LOT::Temple::Script *p_Script) {
    Script = p_Script;
};

std::vector <LOT::Temple::Token> LOT::Temple::Parser::Extract() {
    return Script->Tokens;
};

int LOT::Temple::Parser::Parse() {
    unsigned int idx = 0, line = 1;
    std::string token;

    while (!(idx > Script->Source.length() - 1)) {
        token = "";

        // While the current character is not a whitespace, add it to the token string
        while ((int)std::string(" \n \0 \t").find(Script->Source[idx]) != -1) ++ idx;

        if (Script->Source[idx] == ';') {
            while (Script->Source[idx] != '\n') ++ idx;
            ++ idx;

            continue;
        };

        while ((int)std::string(" \n \0 \t").find(Script->Source[idx]) == -1 && !(idx > Script->Source.length() - 1)) token += Script->Source[idx ++];

        if (token == "") continue;

        // Checking if the token is a number
        if (token[0] == '#') {
            int number = GetNumber(token);

            Script->Add(LOT::Temple::Token(LOT::Temple::TokenTypes::NUMBER, number, line));

        // Else check if its a character
        } else if (token[0] == '\'') {
            // Error if it isnt ended with '
            if (token[(int)token.length() - 1] != '\'') {
                std::cout << LOT::Temple::Exception::Throw("Expected ' to end character \"" + token + "\"", line, true) << std::endl;

                break;
            };

            // Error if its not just one character
            if ((int)token.length() > 3) {
                std::cout << LOT::Temple::Exception::Throw("Unexpected character size \"" + token + "\"", line, true) << std::endl;
            
                break;
            };

            int number = GetCharNumber(token);
            Script->Add(LOT::Temple::Token(LOT::Temple::TokenTypes::NUMBER, number, line));

        // Else check if its a hex number
        } else if (token[0] == '0' && token[1] == 'x') {
            int number = GetHexNumber(token);

            Script->Add(LOT::Temple::Token(LOT::Temple::TokenTypes::NUMBER, number, line));

        // Else check if its a register
        } else if (token[0] == '&') {
            int reg = GetRegister(token);

            if (reg < 0) {
                std::cout << LOT::Temple::Exception::Throw("Unknown register \"" + token + "\"", line, true) << std::endl;

                return LOT::Temple::ParserExitcodes::PARSER_SYNTAX_ERROR;
            } else Script->Add(LOT::Temple::Token(LOT::Temple::TokenTypes::REGISTER, reg, line));

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

uint32_t LOT::Temple::Parser::GetCharNumber(std::string p_Tok) {
    char NumCharacter = p_Tok[1];

    return (uint32_t)NumCharacter;
};

uint32_t LOT::Temple::Parser::GetNumber(std::string p_Tok) {
    // Skipping the first character in the token, which is # in the case of numbers
    long int number = std::stoi(p_Tok.substr(1, p_Tok.length() - 1));

    return number <= UINT32_MAX? number : 0;
};

uint32_t LOT::Temple::Parser::GetHexNumber(std::string p_Tok) {
    return std::stoi(p_Tok.substr(2), 0, 16);
};

int LOT::Temple::Parser::GetInstruction(std::string p_Tok) {
    if (p_Tok == "push") return LOT::Temple::InstructionTokens::PUSH;
    if (p_Tok == "pop") return LOT::Temple::InstructionTokens::POP;
    if (p_Tok == "halt") return LOT::Temple::InstructionTokens::HALT;

    if (p_Tok == "load") return LOT::Temple::InstructionTokens::LOAD;
    if (p_Tok == "sload") return LOT::Temple::InstructionTokens::SLOAD;

    if (p_Tok == "goto") return LOT::Temple::InstructionTokens::GOTO;
    if (p_Tok == "egoto") return LOT::Temple::InstructionTokens::EQUALGOTO;
    if (p_Tok == "lgoto") return LOT::Temple::InstructionTokens::LESSGOTO;
    if (p_Tok == "ggoto") return LOT::Temple::InstructionTokens::GREATERGOTO;
    if (p_Tok == "negoto") return LOT::Temple::InstructionTokens::NOTEQUALGOTO;

    if (p_Tok == "add") return LOT::Temple::InstructionTokens::ADD;
    if (p_Tok == "sub") return LOT::Temple::InstructionTokens::SUBSTRACT;
    if (p_Tok == "mult") return LOT::Temple::InstructionTokens::MULTIPLY;
    if (p_Tok == "div") return LOT::Temple::InstructionTokens::DIVIDE;

    if (p_Tok == "mod") return LOT::Temple::InstructionTokens::MODULUS;
    if (p_Tok == "inc") return LOT::Temple::InstructionTokens::INCREMENT;

    if (p_Tok == "comp") return LOT::Temple::InstructionTokens::COMPARE;

    if (p_Tok == "out") return LOT::Temple::InstructionTokens::OUT;
    if (p_Tok == "outch") return LOT::Temple::InstructionTokens::OUTCHAR;
    if (p_Tok == "outstr") return LOT::Temple::InstructionTokens::OUTSTRING;
    
    return -1;
};

int LOT::Temple::Parser::GetRegister(std::string p_Tok) {
    if (p_Tok == "&r0") return LOT::Temple::RegisterTokens::R0;
    if (p_Tok == "&r1") return LOT::Temple::RegisterTokens::R1;
    if (p_Tok == "&r2") return LOT::Temple::RegisterTokens::R2;
    if (p_Tok == "&r3") return LOT::Temple::RegisterTokens::R3;
    if (p_Tok == "&r4") return LOT::Temple::RegisterTokens::R4;
    if (p_Tok == "&r5") return LOT::Temple::RegisterTokens::R5;
    if (p_Tok == "&r6") return LOT::Temple::RegisterTokens::R6;
    if (p_Tok == "&r7") return LOT::Temple::RegisterTokens::R7;
    if (p_Tok == "&r8") return LOT::Temple::RegisterTokens::R8;
    if (p_Tok == "&r9") return LOT::Temple::RegisterTokens::R9;

    if (p_Tok == "&ip") return LOT::Temple::RegisterTokens::IP;
    if (p_Tok == "&sp") return LOT::Temple::RegisterTokens::SP;
    if (p_Tok == "&ex") return LOT::Temple::RegisterTokens::EX;
    if (p_Tok == "&cn") return LOT::Temple::RegisterTokens::COND;
    
    return -1;
};