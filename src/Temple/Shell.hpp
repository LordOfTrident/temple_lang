#pragma once

#include "./INCLUDE"
//#include "./Interpreter.hpp"

namespace LOT {
    namespace Temple {
        namespace Shell {
            inline void Start() {
                //LOT::Temple::Interpreter interpreter;

                bool running = true;
                std::cout << (std::string)cc_GREEN + NAME + " shell " + cc_CYAN + "v" + VER + (std::string)cc_NC + "\nTo exit, type in " + (std::string)cc_GREEN + "\"exit();\"" + cc_NC + ".";

                while (running) {
                    std::string input;
                    std::cout << std::endl << (std::string)cc_red + "> " + cc_NC; std::getline(std::cin, input);

                    if (LOT::plusplus::LowerCase(input) == "exit();") running = false;
                    else {}; //interpreter.Exec("string '" + input.substr(0, 15) + (input.length() <= 15? "'":"...'"), input);
                };
            };
        };
    };
};