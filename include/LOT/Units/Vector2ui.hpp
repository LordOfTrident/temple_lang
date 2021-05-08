#pragma once

#include <iostream>

namespace LOT {
    namespace Units {
        class Vector2ui {
        public:
            Vector2ui(unsigned int p_x, unsigned int p_y):
            x(p_x),
            y(p_y) {};

            unsigned int x, y;

            friend std::ostream& operator << (std::ostream& p_stream, LOT::Units::Vector2ui p_Vector2ui);

            Vector2ui operator + (const LOT::Units::Vector2ui& p_Vector2ui_b) {
                Vector2ui Result(0, 0);
                Result.x = this->x + p_Vector2ui_b.x;
                Result.y = this->y + p_Vector2ui_b.y;

                return Result;
            };

            Vector2ui operator - (const LOT::Units::Vector2ui& p_Vector2ui_b) {
                Vector2ui Result(0, 0);
                Result.x = this->x - p_Vector2ui_b.x;
                Result.y = this->y - p_Vector2ui_b.y;

                return Result;
            };

            Vector2ui operator * (const LOT::Units::Vector2ui& p_Vector2ui_b) {
                Vector2ui Result(0, 0);
                Result.x = this->x * p_Vector2ui_b.x;
                Result.y = this->y * p_Vector2ui_b.y;

                return Result;
            };

            Vector2ui operator / (const LOT::Units::Vector2ui& p_Vector2ui_b) {
                Vector2ui Result(0, 0);
                Result.x = this->x / p_Vector2ui_b.x;
                Result.y = this->y / p_Vector2ui_b.y;

                return Result;
            };

            Vector2ui operator += (const Vector2ui& p_Vector2iu_b) {
                this->x += p_Vector2iu_b.x;
                this->y += p_Vector2iu_b.y;

                return Vector2ui(this->x, this->y);
            };

            Vector2ui operator -= (const Vector2ui& p_Vector2iu_b) {
                this->x -= p_Vector2iu_b.x;
                this->y -= p_Vector2iu_b.y;

                return Vector2ui(this->x, this->y);
            };

            Vector2ui operator *= (const Vector2ui& p_Vector2iu_b) {
                this->x *= p_Vector2iu_b.x;
                this->y *= p_Vector2iu_b.y;

                return Vector2ui(this->x, this->y);
            };

            Vector2ui operator /= (const Vector2ui& p_Vector2iu_b) {
                this->x /= p_Vector2iu_b.x;
                this->y /= p_Vector2iu_b.y;

                return Vector2ui(this->x, this->y);
            };
        };

        inline std::ostream& operator << (std::ostream& p_stream, LOT::Units::Vector2ui p_Vector2ui) {
            p_stream << "{" + std::to_string(p_Vector2ui.x) + "," + std::to_string(p_Vector2ui.y) + "}";

            return p_stream;
        };
    };
};