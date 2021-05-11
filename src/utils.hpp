#pragma once

#include "./INCLUDE"

#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <algorithm>
#include <cctype>

#include "./bytebuffer.hpp"

namespace LOT {
    namespace Temple {
        namespace Utils {
            bool FileExists(std::string p_Name);
            std::string FileToString(std::string p_FileName);
            void WriteBinFile(std::string p_FileName, LOT::Temple::Bytebuffer *p_Bytecode);
            
            std::string LowerCase(std::string p_s);
        };
    };
};