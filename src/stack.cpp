#include "./stack.hpp"

extern const uint16_t LOT::Temple::STACK_MAX_SIZE = 1024;

LOT::Temple::Stack::Stack() {
    Buffer.resize(STACK_MAX_SIZE);
    Pointer = -1;
};

void LOT::Temple::Stack::Push8(uint8_t p_Data) {
    Buffer[++ Pointer] = p_Data;
};

void LOT::Temple::Stack::Push16(uint16_t p_Data) {
    Push8((p_Data & 0xFF00) >> 8);
    Push8(p_Data & 0x00FF);
};

void LOT::Temple::Stack::Push32(uint32_t p_Data) {
    Push8((p_Data & 0xFF000000) >> 24);
    Push8((p_Data & 0x00FF0000) >> 16);
    Push8((p_Data & 0x0000FF00) >> 8);
    Push8(p_Data & 0x000000FF);
};

uint8_t LOT::Temple::Stack::Pop8() {
    return Buffer[(int)Pointer == -1? 0 : Pointer --];
};

uint16_t LOT::Temple::Stack::Pop16() {
    uint8_t b = Pop8(), a = Pop8();

    return (a << 8) | b;
};

uint32_t LOT::Temple::Stack::Pop32() {
   uint8_t d = Pop8(), c = Pop8(), b = Pop8(), a = Pop8();
   
   return (a << 24) | (b << 16) | (c << 8) | d; 
};