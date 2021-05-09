#include "../include/COMPONENTS"
#include "../include/INFO"

#include "./Temple/Shell.hpp"

int main(int argc, char* argv[]) {
    std::vector <std::string> params;
    bool skip = false;
    std::string File = "";

    // Reading parameters
    for (int i = 1; i < argc; ++ i) {
        if (skip) {skip = false; continue;};

        std::string arg = argv[i];

        if (std::count(params.begin(),params.end(), arg)) {
            std::cout << "Too many identical \"" + arg + "\" parameters." << std::endl; 
            
            return 1;         
        };

        if (arg == "-c" || arg == "-v") {params.push_back(arg); continue;};
        if (arg == "-f") {
            params.push_back(arg); 

            if (argc - 1 > i) File = argv[i + 1];
            else {std::cout << "Expected a file name." << std::endl; return 1;};

            if (!LOT::plusplus::FileExists(File)) {
                std::cout << "File \"" + File + "\" not found." << std::endl;
                
                return 1;
            };

            skip = true;
            continue;
        };

        std::cout << "Unknown parameter \"" + arg + "\"." << std::endl; 
        
        return 1;
    };

    if (std::count(params.begin(),params.end(), "-v")) std::cout << (std::string) "v" + VER << std::endl;
    if (std::count(params.begin(),params.end(), "-c")) {
        if (std::count(params.begin(),params.end(), "-f")) {
            LOT::Temple::Temple TM_Compiler;
            return TM_Compiler.Compile(LOT::plusplus::FileToString(File));
        } else LOT::Temple::Shell::Start();
    };
    
    return 0;
};