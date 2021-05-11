#include "./temple.hpp"

LOT::Temple::Temple::Temple() {};

int LOT::Temple::Temple::Compile(std::string p_OutputName, std::string p_Code) {
    LOT::Temple::Script script(p_Code);
    int result;

    parser.Assign(&script); result = parser.Parse();
    if (result != LOT::Temple::ParserExitcodes::PARSER_OK) return result;

    LOT::Temple::Bytebuffer Bytecode(0);

    compiler.Assign(&script, &Bytecode); result = compiler.Compile();
    if (result != LOT::Temple::ParserExitcodes::PARSER_OK) return result;

    LOT::Temple::Utils::WriteBinFile(p_OutputName, &Bytecode);

    return result;
};