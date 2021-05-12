#include "./runtime.hpp"

LOT::Temple::Runtime::Runtime() {};

void LOT::Temple::Runtime::Assign(std::vector <uint8_t> p_Code) {
    Code = p_Code;

    // Debug
    /*for (int i = 0; i < (int)Code.size(); ++ i) {
        switch(Code[i]) {
            case LOT::Temple::PUSH_OP: {
                std::cout << "PUSH\n";
                break;
            };
            case LOT::Temple::ADD_OP: {
                std::cout << "ADD\n";
                break;
            };
            case LOT::Temple::HALT_OP: {
                std::cout << "HALT\n";
                break;
            };
            default: {
                std::cout << "OTHER " << (int)Code[i] << std::endl;
                break;
            };
        };
    };*/
};

int LOT::Temple::Runtime::Run() {
    running = true;
    InstructionPointer = 0;
    exitcode = 0;
    
    while (running) {
        // Check instruction
        switch(Code[InstructionPointer]) {
            case LOT::Temple::Opcode::PUSH_OP: {
                Stack.Push32(Read32());
                InstructionPointer += 4;

                break;
            };

            case LOT::Temple::Opcode::POP_OP: {
                Stack.Pop32();

                break;
            };

            case LOT::Temple::Opcode::INC_OP: {
                uint32_t a = Stack.Pop32();
                
                a = ((a & 0xFF000000) >> 24) | ((a & 0x00FF0000) >> 16) | ((a & 0x0000FF00) >> 8) | (a & 0x000000FF);

                Stack.Push32(++ a);

                break;
            };

            case LOT::Temple::Opcode::ADD_OP: {
                uint32_t a = Stack.Pop32();
                uint32_t b = Stack.Pop32();
                
                a = ((a & 0xFF000000) >> 24) | ((a & 0x00FF0000) >> 16) | ((a & 0x0000FF00) >> 8) | (a & 0x000000FF);
                b = ((b & 0xFF000000) >> 24) | ((b & 0x00FF0000) >> 16) | ((b & 0x0000FF00) >> 8) | (b & 0x000000FF);

                Stack.Push32(a + b);

                break;
            };

            case LOT::Temple::Opcode::MULT_OP: {
                uint32_t a = Stack.Pop32();
                uint32_t b = Stack.Pop32();
                
                a = ((a & 0xFF000000) >> 24) | ((a & 0x00FF0000) >> 16) | ((a & 0x0000FF00) >> 8) | (a & 0x000000FF);
                b = ((b & 0xFF000000) >> 24) | ((b & 0x00FF0000) >> 16) | ((b & 0x0000FF00) >> 8) | (b & 0x000000FF);

                Stack.Push32(a * b);

                break;
            };

            case LOT::Temple::Opcode::HALT_OP: {
                exitcode = (Stack.Pop32() & 0xFF000000) >> 24;
                running = false;

                break;
            };
        };

        ++ InstructionPointer;
    };

    return exitcode;
};

uint16_t LOT::Temple::Runtime::Read16() {
    return (Code[InstructionPointer + 1] << 8) | Code[InstructionPointer + 2];
};

uint32_t LOT::Temple::Runtime::Read32() {
    return (Code[InstructionPointer + 1] << 24) | (Code[InstructionPointer + 2] << 16) | (Code[InstructionPointer + 3] << 8) | Code[InstructionPointer + 4];
};