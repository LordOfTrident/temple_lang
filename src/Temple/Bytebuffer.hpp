#pragma once

#include "./INCLUDE"

#include "./Bytecode.hpp"

namespace LOT {
    namespace Temple {
        class Bytebuffer {
        public: Bytebuffer(int p_Size) {Buffer.resize(p_Size); Pointer = 0;};
            void Write8(uint8_t p_Data) {
                Buffer.push_back(0);
                Buffer[Pointer ++] = p_Data;
            };
            void Write16(uint16_t p_Data) {
                Write8((p_Data & 0xFF00) >> 8);
                Write8((p_Data & 0x00FF));
            };
            void Write32(uint32_t p_Data) {
                Write8((p_Data & 0xFF000000) >> 24);
                Write8((p_Data & 0x00FF0000) >> 16);
                Write8((p_Data & 0x0000FF00) >> 8);
                Write8((p_Data & 0x000000FF));
            };
            void Back() {
                if (Pointer == 0) return;

                Buffer.pop_back();
                -- Pointer;
            };

            std::vector <uint8_t> Buffer;
            int Pointer;
        };

        inline void WriteBinFile(std::string p_FileName, LOT::Temple::Bytebuffer *p_Bytecode) {
            char buffer[p_Bytecode->Buffer.size() - 1];
            std::copy(p_Bytecode->Buffer.begin(), p_Bytecode->Buffer.end(), buffer);

            std::ofstream BinFile("a.tmbc", std::ios::out | std::ios::binary);
            BinFile.write(buffer, p_Bytecode->Buffer.size());

            BinFile.close();
        };
    };
};