#include "./INCLUDE"

#include "./utils.hpp"
#include "./temple.hpp"

int main(int argc, char* argv[]) {
    std::vector <std::string> params;
    bool skip = false;
    std::string File = "";

    // Reading parameters
    for (int i = 1; i < argc; ++ i) {
        if (skip) {skip = false; continue;};

        std::string arg = argv[i];

        // Checking if the parameter was passed before
        if (std::count(params.begin(),params.end(), arg)) {
            std::cout << "Too many identical \"" + arg + "\" parameters." << std::endl; 
            
            return 1;         
        };

        // Comparing parameters
        if (arg == "-c" || arg == "-v" || arg == "-r") {params.push_back(arg); continue;}; // Modes
        if (arg == "-f") {
            params.push_back(arg); 

            if (argc - 1 > i) File = argv[i + 1];
            else {std::cout << "Expected a file name." << std::endl; return 1;};

            // Figuring out the file name and if it exists
            if (!LOT::Temple::Utils::FileExists(File)) {
                if (!LOT::Temple::Utils::FileExists(File + ".tm")) {
                    std::cout << "File \"" + File + "\" not found." << std::endl;
                    
                    return 1;
                };

                File += ".tm";
            };

            skip = true;
            continue;
        };

        // If comparison failed, the parameter doesnt exist
        std::cout << "Unknown parameter \"" + arg + "\"." << std::endl; 
        
        return 1;
    };

    // Checking if no parameters were passed
    if (params.size() == 0) {
        std::cout << cc_YELLOW << " _..__ ________  _________ _      _____\n|_|| _|  ___|  \\/\\_|| ___ \\ |    |  __/\n  ||| | |__ | . \\._/| |,/ /\\\\    | |__  \n  | |/|  _||| |\\/|_||  \\|/| \\|   |  _|| \n .| ||| |_``| | / _|| ||| | ||.._| |_|| \n \\\\_/\\\\____/\\_| ||_/\\_|   \\___||/\\____/ \n ||   |/        ||            //     ||\n" << 
        cc_NC << (std::string) "\nTemple Programming Language\nby LordOfTrident\ncurrent version " + VER + " (" + DATE + ") pre-release\nusage:\n  temple <parameters>\nparameters:\n  -c            compile mode\n  -r            run mode\n  -f <name>     attach a file\n  -v            show the version\nversions:\n  pre-release\n    (5/8/2021)\n    0.0.1       working parser, compiler\n" << std::endl;

        return 0;
    };

    // Checking if version parameter was specified
    if (std::count(params.begin(),params.end(), "-v")) {
        std::cout << (std::string) "v" + VER + " (" + DATE + ")" << std::endl;

        return 0;
    };

    // Checkng if compile mode was enabled
    if (std::count(params.begin(),params.end(), "-c")) {
        if (std::count(params.begin(),params.end(), "-f")) {
            LOT::Temple::Temple TM_Compiler;
            int result = TM_Compiler.Compile(File.substr(File.length() - 3, File.length()) == ".tm"? File + "bc" : "out.tmbc", LOT::Temple::Utils::FileToString(File));

            if (result != LOT::Temple::CompilerExitcodes::COMPILER_OK) {
                std::cout << "Compilation failed." << std::endl;

                return 1;
            };

            return 0;
        };
        
        std::cout << "Expected file input." << std::endl;

        return 0;
    };

    if (std::count(params.begin(),params.end(), "-r")) {
        if (std::count(params.begin(),params.end(), "-f")) {
            LOT::Temple::Temple TM_Runner;

            int result = TM_Runner.Run(File);

            std::cout << "Exited with exitcode " << result << "." << std::endl;

            return 0;
        };
        
        std::cout << "Expected file input." << std::endl;

        return 0;
    };

    // Else if no modes specified but a parameter was passed just output three dots
    std::cout << "..." << std::endl;
    
    return 0;
};