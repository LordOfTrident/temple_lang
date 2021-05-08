#pragma once

#include <iostream>

namespace LOT {
    namespace Units {
        class Vector2f {
        public:
            Vector2f(float p_x, float p_y):
            x(p_x),
            y(p_y) {};

            float x, y;
            
            friend std::ostream& operator << (std::ostream& p_stream, LOT::Units::Vector2f p_Vector2f);
            
            Vector2f operator + (const LOT::Units::Vector2f& p_Vector2f_b) {
                Vector2f Result(0, 0);
                Result.x = this->x + p_Vector2f_b.x;
                Result.y = this->y + p_Vector2f_b.y;

                return Result;
            };

            Vector2f operator - (const LOT::Units::Vector2f& p_Vector2f_b) {
                Vector2f Result(0, 0);
                Result.x = this->x - p_Vector2f_b.x;
                Result.y = this->y - p_Vector2f_b.y;

                return Result;
            };

            Vector2f operator * (const LOT::Units::Vector2f& p_Vector2f_b) {
                Vector2f Result(0, 0);
                Result.x = this->x * p_Vector2f_b.x;
                Result.y = this->y * p_Vector2f_b.y;

                return Result;
            };

            Vector2f operator / (const LOT::Units::Vector2f& p_Vector2f_b) {
                Vector2f Result(0, 0);
                Result.x = this->x / p_Vector2f_b.x;
                Result.y = this->y / p_Vector2f_b.y;

                return Result;
            };

            Vector2f operator += (const Vector2f& p_Vector2f_b) {
                this->x += p_Vector2f_b.x;
                this->y += p_Vector2f_b.y;

                return Vector2f(this->x, this->y);
            };

            Vector2f operator -= (const Vector2f& p_Vector2f_b) {
                this->x -= p_Vector2f_b.x;
                this->y -= p_Vector2f_b.y;

                return Vector2f(this->x, this->y);
            };

            Vector2f operator *= (const Vector2f& p_Vector2f_b) {
                this->x *= p_Vector2f_b.x;
                this->y *= p_Vector2f_b.y;

                return Vector2f(this->x, this->y);
            };

            Vector2f operator /= (const Vector2f& p_Vector2f_b) {
                this->x /= p_Vector2f_b.x;
                this->y /= p_Vector2f_b.y;

                return Vector2f(this->x, this->y);
            };
        };

        inline std::ostream& operator << (std::ostream& p_stream, LOT::Units::Vector2f p_Vector2f) {
            p_stream << "{" + std::to_string(p_Vector2f.x) + "," + std::to_string(p_Vector2f.y) + "}";

            return p_stream;
        };
    };
};