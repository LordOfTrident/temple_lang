#include "./runtime.hpp"

LOT::Temple::Runtime::Runtime() {
    Registers.resize(13);
    Stack.Pointer = &Registers[LOT::Temple::Registers::SP_REG];
};

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
    Registers[LOT::Temple::Registers::EX_REG] = 0;
    Registers[LOT::Temple::Registers::SP_REG] = 0;
    
    while (running) {
        // Check instruction
        switch(Code[InstructionPointer]) {
            case LOT::Temple::Opcode::PUSH_OP: {
                uint8_t mode = Read8();
                ++ InstructionPointer;

                switch (mode) {
                    case 0: {
                        Stack.Push32(Registers[Read8()]);
                        ++ InstructionPointer;

                        break;
                    };

                    case 1: {
                        Stack.Push32(Read32());
                        InstructionPointer += 4;

                        break;
                    };
                };

                break;
            };

            case LOT::Temple::Opcode::POP_OP: {
                Registers[Read8()] = Stack.Pop32();
                ++ InstructionPointer;

                break;
            };

            case LOT::Temple::Opcode::GOTO_OP: {
                uint8_t mode = Read8();
                ++ InstructionPointer;

                switch (mode) {
                    case 0: {
                        InstructionPointer = Registers[Read8()];
                        -- InstructionPointer;

                        break;
                    };

                    case 1: {
                        InstructionPointer = Read32();
                        -- InstructionPointer;

                        break;
                    };
                };

                break;
            };

            case LOT::Temple::Opcode::EGOTO_OP: {
                uint8_t mode = Read8();
                ++ InstructionPointer;

                switch (mode) {
                    case 0: {
                        if (Registers[COND_REG] != LOT::Temple::Conditions::EQUAL_COND) {
                            ++ InstructionPointer;

                            break;
                        };

                        InstructionPointer = Registers[Read8()];
                        -- InstructionPointer;

                        break;
                    };

                    case 1: {
                        if (Registers[COND_REG] != LOT::Temple::Conditions::EQUAL_COND) {
                            InstructionPointer += 4;

                            break;
                        };

                        InstructionPointer = Read32();
                        -- InstructionPointer;

                        break;
                    };
                };

                break;
            };

            case LOT::Temple::Opcode::NEGOTO_OP: {
                uint8_t mode = Read8();
                ++ InstructionPointer;

                switch (mode) {
                    case 0: {
                        if (Registers[COND_REG] == LOT::Temple::Conditions::EQUAL_COND) {
                            ++ InstructionPointer;

                            break;
                        };

                        InstructionPointer = Registers[Read8()];
                        -- InstructionPointer;

                        break;
                    };

                    case 1: {
                        if (Registers[COND_REG] == LOT::Temple::Conditions::EQUAL_COND) {
                            InstructionPointer += 4;

                            break;
                        };

                        InstructionPointer = Read32();
                        -- InstructionPointer;

                        break;
                    };
                };

                break;
            };

            case LOT::Temple::Opcode::GGOTO_OP: {
                uint8_t mode = Read8();
                ++ InstructionPointer;

                switch (mode) {
                    case 0: {
                        if (Registers[COND_REG] != LOT::Temple::Conditions::GREATER_COND) {
                            ++ InstructionPointer;

                            break;
                        };

                        InstructionPointer = Registers[Read8()];
                        -- InstructionPointer;

                        break;
                    };

                    case 1: {
                        if (Registers[COND_REG] != LOT::Temple::Conditions::GREATER_COND) {
                            InstructionPointer += 4;

                            break;
                        };

                        InstructionPointer = Read32();
                        -- InstructionPointer;

                        break;
                    };
                };

                break;
            };

            case LOT::Temple::Opcode::LGOTO_OP: {
                uint8_t mode = Read8();
                ++ InstructionPointer;

                switch (mode) {
                    case 0: {
                        if (Registers[COND_REG] != LOT::Temple::Conditions::LESS_COND) {
                            ++ InstructionPointer;

                            break;
                        };

                        InstructionPointer = Registers[Read8()];
                        -- InstructionPointer;

                        break;
                    };

                    case 1: {
                        if (Registers[COND_REG] != LOT::Temple::Conditions::LESS_COND) {
                            InstructionPointer += 4;

                            break;
                        };

                        InstructionPointer = Read32();
                        -- InstructionPointer;

                        break;
                    };
                };

                break;
            };

            case LOT::Temple::Opcode::LOAD_OP: {
                uint8_t reg_res = Read8();
                ++ InstructionPointer;

                uint8_t mode = Read8();
                ++ InstructionPointer;

                switch (mode) {
                    case 0: {
                        Registers[reg_res] = Registers[Read8()];

                        ++ InstructionPointer;

                        break;
                    };

                    case 1: {
                        Registers[reg_res] = Read32();

                        InstructionPointer += 4;

                        break;
                    };
                };

                break;
            };

            case LOT::Temple::Opcode::SLOAD_OP: {
                uint8_t mode = Read8();
                ++ InstructionPointer;

                uint32_t loc = 0;

                switch (mode) {
                    case 0: {
                        loc = Registers[Read8()];

                        ++ InstructionPointer;

                        break;
                    };

                    case 1: {
                        loc = Read32();

                        InstructionPointer += 4;

                        break;
                    };
                };

                if (loc > *Stack.Pointer) {
                    std::cout << "\n" << LOT::Temple::Exception::Runtime("SLOAD INVALID STACK LOCATION " + std::to_string(loc) + " AT INSTRUCTION " + std::to_string(InstructionPointer), true) << std::endl;

                    Registers[LOT::Temple::Registers::EX_REG] = 1;
                    running = false;
                
                    break;
                };

                mode = Read8();
                ++ InstructionPointer;

                switch (mode) {
                    case 0: {
                        Stack.Buffer[loc] = Registers[Read8()];

                        ++ InstructionPointer;

                        break;
                    };

                    case 1: {
                        Stack.Buffer[loc] = Read32();

                        InstructionPointer += 4;

                        break;
                    };
                };

                break;
            };

            case LOT::Temple::Opcode::INC_OP: {
                ++ Registers[Read8()];
                ++ InstructionPointer;

                break;
            };

            case LOT::Temple::Opcode::DEC_OP: {
                -- Registers[Read8()];
                ++ InstructionPointer;

                break;
            };

            case LOT::Temple::Opcode::ADD_OP: {
                uint8_t reg_res = Read8();
                ++ InstructionPointer;

                uint8_t reg_a = Read8();
                ++ InstructionPointer;

                uint8_t mode = Read8();
                ++ InstructionPointer;

                switch (mode) {
                    case 0: {
                        uint8_t reg_b = Read8();
                        ++ InstructionPointer;

                        Registers[reg_res] = Registers[reg_a] + Registers[reg_b];

                        break;
                    };

                    case 1: {
                        uint32_t b = Read32();
                        InstructionPointer += 4;

                        Registers[reg_res] = Registers[reg_a] + b;

                        break;
                    };
                };

                break;
            };

            case LOT::Temple::Opcode::MULT_OP: {
                uint8_t reg_res = Read8();
                ++ InstructionPointer;

                uint8_t reg_a = Read8();
                ++ InstructionPointer;

                uint8_t mode = Read8();
                ++ InstructionPointer;

                switch (mode) {
                    case 0: {
                        uint8_t reg_b = Read8();
                        ++ InstructionPointer;

                        Registers[reg_res] = Registers[reg_a] * Registers[reg_b];

                        break;
                    };

                    case 1: {
                        uint32_t b = Read32();
                        InstructionPointer += 4;

                        Registers[reg_res] = Registers[reg_a] * b;

                        break;
                    };
                };

                break;
            };

            case LOT::Temple::Opcode::SUB_OP: {
                uint8_t reg_res = Read8();
                ++ InstructionPointer;

                uint8_t reg_a = Read8();
                ++ InstructionPointer;

                uint8_t mode = Read8();
                ++ InstructionPointer;

                switch (mode) {
                    case 0: {
                        uint8_t reg_b = Read8();
                        ++ InstructionPointer;

                        Registers[reg_res] = Registers[reg_a] - Registers[reg_b];

                        break;
                    };

                    case 1: {
                        uint32_t b = Read32();
                        InstructionPointer += 4;

                        Registers[reg_res] = Registers[reg_a] - b;

                        break;
                    };
                };

                break;
            };

            case LOT::Temple::Opcode::DIV_OP: {
                ++ InstructionPointer;

                break;
            };

            case LOT::Temple::Opcode::COMP_OP: {
                uint8_t reg_a = Read8();
                ++ InstructionPointer;

                uint8_t mode = Read8();
                ++ InstructionPointer;

                switch (mode) {
                    case 0: {
                        uint8_t reg_b = Read8();
                        ++ InstructionPointer;

                        if (Registers[reg_a] > Registers[reg_b]) Registers[COND_REG] = LOT::Temple::Conditions::GREATER_COND;
                        else if (Registers[reg_a] < Registers[reg_b]) Registers[COND_REG] = LOT::Temple::Conditions::LESS_COND;
                        else if (Registers[reg_a] == Registers[reg_b]) Registers[COND_REG] = LOT::Temple::Conditions::EQUAL_COND;

                        break;
                    };

                    case 1: {
                        uint32_t b = Read32();
                        InstructionPointer += 4;

                        if (Registers[reg_a] > b) Registers[COND_REG] = LOT::Temple::Conditions::GREATER_COND;
                        else if (Registers[reg_a] < b) Registers[COND_REG] = LOT::Temple::Conditions::LESS_COND;
                        else if (Registers[reg_a] == b) Registers[COND_REG] = LOT::Temple::Conditions::EQUAL_COND;

                        break;
                    };
                };

                break;
            };

            case LOT::Temple::Opcode::HALT_OP: {
                running = false;

                break;
            };

            case LOT::Temple::Opcode::OUT_OP: {
                uint8_t mode = Read8();
                ++ InstructionPointer;

                uint32_t loc = 0;

                switch (mode) {
                    case 0: {
                        loc = Registers[Read8()];

                        ++ InstructionPointer;

                        break;
                    };

                    case 1: {
                        loc = Read32();

                        InstructionPointer += 4;

                        break;
                    };
                };

                if (loc > *Stack.Pointer) {
                    std::cout << "\n" << LOT::Temple::Exception::Runtime("OUT INVALID STACK LOCATION " + std::to_string(loc) + " AT INSTRUCTION " + std::to_string(InstructionPointer), true) << std::endl;

                    Registers[LOT::Temple::Registers::EX_REG] = 1;
                    running = false;
                
                    break;
                };

                if (loc + 3 <= Stack.Buffer.size()) {
                    uint8_t d = Stack.Buffer[loc + 3], c = Stack.Buffer[loc + 2], b = Stack.Buffer[loc + 1], a = Stack.Buffer[loc];
                
                    std::cout << ((a << 24) | (b << 16) | (c << 8) | d); 
                } else if (loc + 1 <= Stack.Buffer.size()) {
                    uint8_t b = Stack.Buffer[loc + 1], a = Stack.Buffer[loc];

                    std::cout << ((a << 8) | b);
                } else std::cout << Stack.Buffer[loc];

                break;
            };

            case LOT::Temple::Opcode::OUTCH_OP: {
                uint8_t mode = Read8();
                ++ InstructionPointer;

                uint32_t loc = 0, amount = 0;

                switch (mode) {
                    case 0: {
                        loc = Registers[Read8()];

                        ++ InstructionPointer;

                        break;
                    };

                    case 1: {
                        loc = Read32();

                        InstructionPointer += 4;

                        break;
                    };
                };

                if (loc > *Stack.Pointer) {
                    std::cout << "\n" << LOT::Temple::Exception::Runtime("OUTCH INVALID STACK LOCATION " + std::to_string(loc) + " AT INSTRUCTION " + std::to_string(InstructionPointer), true) << std::endl;

                    Registers[LOT::Temple::Registers::EX_REG] = 1;
                    running = false;
                
                    break;
                };

                mode = Read8();
                ++ InstructionPointer;

                switch (mode) {
                    case 0: {
                        amount = Registers[Read8()];

                        ++ InstructionPointer;

                        break;
                    };

                    case 1: {
                        amount = Read32();

                        InstructionPointer += 4;

                        break;
                    };
                };

                if (loc + amount - 1 > *Stack.Pointer) {
                    std::cout << "\n" << LOT::Temple::Exception::Runtime(std::to_string(amount) + " BYTES IN THE STACK NOT AVAILABLE " + std::to_string(InstructionPointer), true) << std::endl;

                    Registers[LOT::Temple::Registers::EX_REG] = 1;
                    running = false;
                
                    break;
                };

                for (uint32_t i = loc; i < loc + amount; ++ i) {
                    uint8_t chr = Stack.Buffer[i];

                    if (chr > 127) {
                        chr -= 128;
                        std::cout << LOT::Temple::AsciiColors[(int)chr > (int)LOT::Temple::AsciiColors.size() - 1? 0 : (int)chr];
                    } else std::cout << char(chr);
                };

                break;
            };

            case LOT::Temple::Opcode::OUTSTR_OP: {
                uint8_t mode = Read8();
                ++ InstructionPointer;

                uint32_t loc = 0;

                switch (mode) {
                    case 0: {
                        loc = Registers[Read8()];

                        ++ InstructionPointer;

                        break;
                    };

                    case 1: {
                        loc = Read32();

                        InstructionPointer += 4;

                        break;
                    };
                };

                if (loc > *Stack.Pointer) {
                    std::cout << "\n" << LOT::Temple::Exception::Runtime("OUTSTR INVALID STACK LOCATION " + std::to_string(loc) + " AT INSTRUCTION " + std::to_string(InstructionPointer), true) << std::endl;

                    Registers[LOT::Temple::Registers::EX_REG] = 1;
                    running = false;
                
                    break;
                };

                for (int i = loc; i < (int)Stack.Buffer.size(); ++ i) {
                    uint8_t chr = Stack.Buffer[i];

                    if (chr == 0) break;

                    if (chr > 127) {
                        chr -= 128;
                        std::cout << LOT::Temple::AsciiColors[(int)chr > (int)LOT::Temple::AsciiColors.size() - 1? 0 : (int)chr];
                    } else std::cout << char(chr);
                };

                break;
            };

            default: {
                std::cout << "\n" << LOT::Temple::Exception::Runtime("UNKNOWN INSTRUCTION " + std::to_string(InstructionPointer), true) << std::endl;

                Registers[LOT::Temple::Registers::EX_REG] = 1;
                running = false;
            
                break;
            };
        };

        ++ InstructionPointer;

        if (InstructionPointer > (uint32_t)Code.size()) {
            std::cout << "\n" << LOT::Temple::Exception::Runtime("RAN OUT OF INSTRUCTIONS BEFORE HALT", true) << std::endl;

            Registers[LOT::Temple::Registers::EX_REG] = 1;
            running = false;
        };

        if ((int)*Stack.Pointer > (int)Stack.Buffer.size()) {
            std::cout << "\n" << LOT::Temple::Exception::Runtime("STACK POINTER WENT OFF THE STACK", true) << std::endl;

            Registers[LOT::Temple::Registers::EX_REG] = 1;
            running = false;
        };
    };

    return (uint8_t)Registers[LOT::Temple::Registers::EX_REG];
};

uint8_t LOT::Temple::Runtime::Read8() {
    return Code[InstructionPointer + 1];
};

uint16_t LOT::Temple::Runtime::Read16() {
    return (Code[InstructionPointer + 1] << 8) | Code[InstructionPointer + 2];
};

uint32_t LOT::Temple::Runtime::Read32() {
    return (Code[InstructionPointer + 1] << 24) | (Code[InstructionPointer + 2] << 16) | (Code[InstructionPointer + 3] << 8) | Code[InstructionPointer + 4];
};