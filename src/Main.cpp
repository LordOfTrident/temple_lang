#include "../include/COMPONENTS"

#include "./Temple/Shell.hpp"

int main(int argc, char* argv[]) {
    std::string File = "";

    bool skip = false;
    for (int i = 1; i < argc; ++ i) {
        if (!skip) {
            std::string arg = argv[i];

            if (arg == "-f") {

                skip = true;
                if (i + 1 != argc) File = argv[i + 1];
            };
        } else skip = false;
    };

    //LOT::Temple::Interpreter interpreter;

    if (File == "") 
        LOT::Temple::Shell::Start();
    else 
        if (LOT::plusplus::FileExists(File)) {
            //interpreter.Exec(File, LOT::plusplus::FileToString(File));
            std::cout << std::endl;
        } else 
            std::cout << "File '" + File + "' not found." << std::endl; 
    
    return 0;
};