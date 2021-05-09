#pragma once

#include "./INCLUDE"
#include "../../include/COLORS"

namespace LOT {
    namespace Temple {
        namespace Exception {
            inline std::string Throw(std::string p_Msg, unsigned int p_Location, bool p_Colored) {
                if (p_Colored) {
                    return (std::string) cc_NC + "(" + cc_GREEN "tm" + cc_NC + "): Exception at line " + cc_CYAN + std::to_string(p_Location) + cc_NC + ": " + cc_RED + p_Msg + cc_NC;
                } else {
                    return "(tm): Exception at line " + std::to_string(p_Location) + ": " + p_Msg;
                };
            };
        };
    };
};