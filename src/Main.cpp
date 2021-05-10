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
                if (!LOT::plusplus::FileExists(File + ".tm")) {
                    std::cout << "File \"" + File + "\" not found." << std::endl;
                    
                    return 1;
                };

                File += ".tm";
            };

            skip = true;
            continue;
        };

        std::cout << "Unknown parameter \"" + arg + "\"." << std::endl; 
        
        return 1;
    };

    if (params.size() == 0) {
        std::cout << cc_YELLOW << " _..__ ________  _________ _      _____\n|_|| _|  ___|  \\/\\_|| ___ \\ |    |  __/\n  ||| | |__ | . \\._/| |,/ /\\\\    | |__  \n  | |/|  _||| |\\/|_||  \\|/| \\|   |  _|| \n .| ||| |_``| | / _|| ||| | ||.._| |_|| \n \\\\_/\\\\____/\\_| ||_/\\_|   \\___||/\\____/ \n ||   |/        ||            //     ||\n" << 
        cc_NC << (std::string) "\nTemple Programming Language\nby Reinhold A. B.\ncurrent version " + VER + " (" + DATE + ")\nparameters:\n  -c            compile mode\n  -f <name>     attach a file\n  -v            show the version\nversions:\n  (5/10/2021)\n  0.0.1         working parser, compiler\n" << std::endl;

        return 0;
    };

    if (std::count(params.begin(),params.end(), "-v")) {
        std::cout << (std::string) "v" + VER + " (" + DATE + ")" << std::endl;

        return 0;
    };

    if (std::count(params.begin(),params.end(), "-c")) {
        if (std::count(params.begin(),params.end(), "-f")) {
            LOT::Temple::Temple TM_Compiler;
            int result = TM_Compiler.Compile(File + "bc", LOT::plusplus::FileToString(File));

            if (result != LOT::Temple::CompilerExitcodes::COMPILER_OK) std::cout << "Compilation failed." << std::endl;

            return 1;
        };
        
        LOT::Temple::Shell::Start();

        return 0;
    };

    std::cout << "..." << std::endl;
    
    return 0;
};