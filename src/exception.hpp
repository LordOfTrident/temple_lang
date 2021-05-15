#pragma once

#include "./INCLUDE"

namespace LOT {
    namespace Temple {
        namespace Exception {
            std::string Throw(std::string p_Msg, unsigned int p_Location, bool p_Colored);
            std::string Runtime(std::string p_Msg, bool p_Colored);
        };
    };
};