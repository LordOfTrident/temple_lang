#include "./utils.hpp"

void LOT::Temple::Utils::WriteBinFile(std::string p_FileName, LOT::Temple::Bytebuffer *p_Bytecode) {
    char buffer[p_Bytecode->Buffer.size() - 1];
    std::copy(p_Bytecode->Buffer.begin(), p_Bytecode->Buffer.end(), buffer);

    std::ofstream BinFile(p_FileName, std::ios::out | std::ios::binary);
    BinFile.write(buffer, p_Bytecode->Buffer.size());

    BinFile.close();
};

std::vector <uint8_t> LOT::Temple::Utils::ReadBinFile(std::string p_FileName) {
    /*char buffer[0];

    std::ifstream BinFile(p_FileName, std::ios::in | std::ios::binary);
    BinFile.read(buffer, p_Bytecode->Buffer.size());

    BinFile.close();//p_Bytecode->Buffer.size() - 1
    
    std::vector <uint8_t> Buffer(buffer, buffer + sizeof buffer / sizeof buffer[0]);

    p_Bytecode->Buffer = Buffer;*/

    std::ifstream BinFile(p_FileName, std::ios::in | std::ios::binary);

    std::vector <uint8_t> Buffer(std::istreambuf_iterator<char>(BinFile), {});
    //p_Bytecode->Buffer = Buffer;
    //p_Bytecode->Pointer = p_Bytecode->Buffer.size() - 2;

    BinFile.close();

    return Buffer;
};

std::string LOT::Temple::Utils::FileToString(std::string p_FileName) {
    std::string f_string = "";
    std::ifstream f_Handle(p_FileName.c_str());

    if (f_Handle.is_open()) {
        std::string f_line = "";

        while (getline(f_Handle, f_line)) {
            f_string += f_line + '\n';
        };
    };

    f_Handle.close();

    return f_string;
};

bool LOT::Temple::Utils::FileExists(std::string p_Name) {
    return (access(p_Name.c_str(), F_OK) != -1);
};

std::string LOT::Temple::Utils::LowerCase(std::string p_s) {
    std::transform(p_s.begin(), p_s.end(), p_s.begin(), [](unsigned char c) {
        return std::tolower(c);
    });

    return p_s;
};