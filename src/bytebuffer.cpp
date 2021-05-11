#include "./bytebuffer.hpp"

LOT::Temple::Bytebuffer::Bytebuffer(int p_Size) {
    Buffer.resize(p_Size); 
    Pointer = 0;
};

void LOT::Temple::Bytebuffer::Write8(uint8_t p_Data) {
    Buffer.push_back(0);
    Buffer[Pointer ++] = p_Data;
};

void LOT::Temple::Bytebuffer::Write16(uint16_t p_Data) {
    Write8((p_Data & 0xFF00) >> 8);
    Write8((p_Data & 0x00FF));
};

void LOT::Temple::Bytebuffer::Write32(uint32_t p_Data) {
    Write8((p_Data & 0xFF000000) >> 24);
    Write8((p_Data & 0x00FF0000) >> 16);
    Write8((p_Data & 0x0000FF00) >> 8);
    Write8((p_Data & 0x000000FF));
};