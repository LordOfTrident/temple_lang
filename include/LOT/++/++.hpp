#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <algorithm>
#include <cctype>

namespace LOT {
	namespace plusplus {
	    inline void Wait(float p_Seconds) {
		    clock_t waitEnd = clock() + p_Seconds * CLOCKS_PER_SEC;
		    while (clock() < waitEnd) {};
		};

	    inline std::string FileToString(std::string p_FileName) {
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

	    inline bool FileExists(std::string p_Name) {
		    return (access(p_Name.c_str(), F_OK) != -1);
		};

	    inline std::string LowerCase(std::string p_s) {
		    std::transform(p_s.begin(), p_s.end(), p_s.begin(), [](unsigned char c) {
		        return std::tolower(c);
		    });

		    return p_s;
		};
	};
};