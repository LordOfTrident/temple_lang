#pragma once

#include <iostream>

namespace LOT {
    namespace Units {
        class Color3 {
        public:
            Color3(unsigned char p_r, unsigned char p_g, unsigned char p_b):
            r(p_r),
            g(p_g),
            b(p_b) {};

            unsigned char r, g, b;

            friend std::ostream& operator << (std::ostream& p_stream, LOT::Units::Color3 p_Color3);

            Color3 operator + (const LOT::Units::Color3& p_Color3_b) {
                Color3 Result(0, 0, 0);
                Result.r = this->r + p_Color3_b.r;
                Result.g = this->g + p_Color3_b.g;
                Result.b = this->b + p_Color3_b.b;

                return Result;
            };

            Color3 operator - (const LOT::Units::Color3& p_Color3_b) {
                Color3 Result(0, 0, 0);
                Result.r = this->r - p_Color3_b.r;
                Result.g = this->g - p_Color3_b.g;
                Result.b = this->b - p_Color3_b.b;

                return Result;
            };

            Color3 operator * (const LOT::Units::Color3& p_Color3_b) {
                Color3 Result(0, 0, 0);
                Result.r = this->r * p_Color3_b.r;
                Result.g = this->g * p_Color3_b.g;
                Result.b = this->b * p_Color3_b.b;

                return Result;
            };

            Color3 operator / (const LOT::Units::Color3& p_Color3_b) {
                Color3 Result(0, 0, 0);
                Result.r = this->r / p_Color3_b.r;
                Result.g = this->g / p_Color3_b.g;
                Result.b = this->b / p_Color3_b.b;

                return Result;
            };

            Color3 operator += (const Color3& p_Color3_b) {
                this->r += p_Color3_b.r;
                this->g += p_Color3_b.g;
                this->b += p_Color3_b.b;

                return Color3(this->r, this->g, this->b);
            };

            Color3 operator -= (const Color3& p_Color3_b) {
                this->r -= p_Color3_b.r;
                this->g -= p_Color3_b.g;
                this->b -= p_Color3_b.b;

                return Color3(this->r, this->g, this->b);
            };

            Color3 operator *= (const Color3& p_Color3_b) {
                this->r *= p_Color3_b.r;
                this->g *= p_Color3_b.g;
                this->b *= p_Color3_b.b;

                return Color3(this->r, this->g, this->b);
            };

            Color3 operator /= (const Color3& p_Color3_b) {
                this->r /= p_Color3_b.r;
                this->g /= p_Color3_b.g;
                this->b /= p_Color3_b.b;

                return Color3(this->r, this->g, this->b);
            };
        };

        inline std::ostream& operator << (std::ostream& p_stream, LOT::Units::Color3 p_Color3) {
            p_stream << "{" + std::to_string(p_Color3.r) + "," + std::to_string(p_Color3.g) + "," + std::to_string(p_Color3.b) + "}";

            return p_stream;
        };
    };
};