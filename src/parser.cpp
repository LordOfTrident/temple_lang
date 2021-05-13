#include "./parser.hpp"

LOT::Temple::Parser::Parser() {};

void LOT::Temple::Parser::Assign(LOT::Temple::Script *p_Script) {
    Script = p_Script;
};

std::vector <LOT::Temple::Token> LOT::Temple::Parser::Extract() {
    return Script->Tokens;
};

int LOT::Temple::Parser::Parse() {
    unsigned int idx = 0;
    std::string token;
    unsigned int line = 1;

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

uint32_t LOT::Temple::Parser::GetNumber(std::string p_Tok) {
    // Skipping the first character in the token, which is # in the case of numbers
    long int number = std::stoi(p_Tok.substr(1, p_Tok.length() - 1));

    return number <= UINT32_MAX? number : 0;
};

int LOT::Temple::Parser::GetInstruction(std::string p_Tok) {
    if (p_Tok == "push") return LOT::Temple::InstructionTokens::PUSH;
    if (p_Tok == "pop") return LOT::Temple::InstructionTokens::POP;
    if (p_Tok == "halt") return LOT::Temple::InstructionTokens::HALT;
    if (p_Tok == "add") return LOT::Temple::InstructionTokens::ADD;
    if (p_Tok == "sub") return LOT::Temple::InstructionTokens::SUBSTRACT;
    if (p_Tok == "mult") return LOT::Temple::InstructionTokens::MULTIPLY;
    if (p_Tok == "div") return LOT::Temple::InstructionTokens::DIVIDE;
    if (p_Tok == "mod") return LOT::Temple::InstructionTokens::MODULUS;
    if (p_Tok == "inc") return LOT::Temple::InstructionTokens::INCREMENT;
    if (p_Tok == "out") return LOT::Temple::InstructionTokens::OUT;
    if (p_Tok == "outch") return LOT::Temple::InstructionTokens::OUTCHAR;
    
    return -1;
};