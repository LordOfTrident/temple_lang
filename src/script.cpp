#include "./script.hpp"

LOT::Temple::Script::Script(std::string p_Code): 
Source(p_Code) {};

void LOT::Temple::Script::Add(LOT::Temple::Token p_Token) {
    Tokens.push_back(p_Token);
};