#pragma once

#include <iostream>
#include <cmath>

#ifndef PI
#define PI 3.14159265359
#endif

namespace LOT {
    namespace plusplus {
        namespace Math {
            inline float Distance(float x_1, float y_1, float x_2, float y_2) {
                return sqrt((x_2 - x_1) * (x_2 - x_1) + (y_2 - y_1) * (y_2 - y_1)); 
            };

            inline float DegToRad(float p_Degrees) {
                return p_Degrees * (PI / 180);
            };

            inline float RadToDeg(float p_Radians) {
                return p_Radians * (180 / PI);
            };
            
            inline int ScaleBetween(int unscaledNum, int minAllowed, int maxAllowed, int min, int max) {
                return (maxAllowed - minAllowed) * (unscaledNum - min) / (max - min) + minAllowed;
            };
        };
    };
};