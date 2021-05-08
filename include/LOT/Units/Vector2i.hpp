#pragma once

#include <iostream>

namespace LOT {
    namespace Units {
        class Vector2i {
        public:
            Vector2i(int p_x, int p_y):
            x(p_x),
            y(p_y) {};

            int x, y;

            friend std::ostream& operator << (std::ostream& p_stream, LOT::Units::Vector2i p_Vector2i);

            Vector2i operator + (const LOT::Units::Vector2i& p_Vector2i_b) {
                Vector2i Result(0, 0);
                Result.x = this->x + p_Vector2i_b.x;
                Result.y = this->y + p_Vector2i_b.y;

                return Result;
            };

            Vector2i operator - (const LOT::Units::Vector2i& p_Vector2i_b) {
                Vector2i Result(0, 0);
                Result.x = this->x - p_Vector2i_b.x;
                Result.y = this->y - p_Vector2i_b.y;

                return Result;
            };

            Vector2i operator * (const LOT::Units::Vector2i& p_Vector2i_b) {
                Vector2i Result(0, 0);
                Result.x = this->x * p_Vector2i_b.x;
                Result.y = this->y * p_Vector2i_b.y;

                return Result;
            };

            Vector2i operator / (const LOT::Units::Vector2i& p_Vector2i_b) {
                Vector2i Result(0, 0);
                Result.x = this->x / p_Vector2i_b.x;
                Result.y = this->y / p_Vector2i_b.y;

                return Result;
            };

            Vector2i operator += (const Vector2i& p_Vector2i_b) {
                this->x += p_Vector2i_b.x;
                this->y += p_Vector2i_b.y;

                return Vector2i(this->x, this->y);
            };

            Vector2i operator -= (const Vector2i& p_Vector2i_b) {
                this->x -= p_Vector2i_b.x;
                this->y -= p_Vector2i_b.y;

                return Vector2i(this->x, this->y);
            };

            Vector2i operator *= (const Vector2i& p_Vector2i_b) {
                this->x *= p_Vector2i_b.x;
                this->y *= p_Vector2i_b.y;

                return Vector2i(this->x, this->y);
            };

            Vector2i operator /= (const Vector2i& p_Vector2i_b) {
                this->x /= p_Vector2i_b.x;
                this->y /= p_Vector2i_b.y;

                return Vector2i(this->x, this->y);
            };
        };

        inline std::ostream& operator << (std::ostream& p_stream, LOT::Units::Vector2i p_Vector2i) {
            p_stream << "{" + std::to_string(p_Vector2i.x) + "," + std::to_string(p_Vector2i.y) + "}";

            return p_stream;
        };
    };
};