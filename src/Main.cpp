#include "../include/COMPONENTS"

#include "./Temple/Shell.hpp"

int main(int argc, char* argv[]) {
    std::string File = "";

    // Reading parameters
    bool skip = false;
    for (int i = 1; i < argc; ++ i) {
        if (!skip) {
            std::string arg = argv[i];

            if (arg == "-f") {

                skip = true;
                if (i + 1 != argc) File = argv[i + 1];
                else {
                    std::cout << "Expected file name" << std::endl;

                    return 1;
                };
            };
        } else skip = false;
    };

    LOT::Temple::Temple TM_Compiler;

    if (File == "") LOT::Temple::Shell::Start();
    else if (LOT::plusplus::FileExists(File)) return TM_Compiler.Compile(LOT::plusplus::FileToString(File));
    
    std::cout << "File '" + File + "' not found." << std::endl;
    
    return 0;
};