#ifndef ENCODER_HH
#define ENCODER_HH

#include <cstdint>
#include <string>

enum class InstructionType {
    R_Type,
    I_Type,
    S_Type,
    B_Type,
    U_Type,
    J_Type,
    Unknown
};

class RTypeInstruction {
public:
    uint8_t funct7;
    uint8_t rs2;
    uint8_t rs1;
    uint8_t funct3;
    uint8_t rd;
    uint8_t opcode;
};

class ITypeInstruction {
public:
    uint32_t imm;
    uint8_t rs1;
    uint8_t funct3;
    uint8_t rd;
    uint8_t opcode;
};

class STypeInstruction {
public:
    uint32_t imm;
    uint8_t rs2;
    uint8_t rs1;
    uint8_t funct3;
    uint8_t opcode;
};

class BTypeInstruction {
public:
    uint32_t imm;
    uint8_t rs2;
    uint8_t rs1;
    uint8_t funct3;
    uint8_t opcode;
};

class UTypeInstruction {
public:
    uint32_t imm;
    uint8_t rd;
    uint8_t opcode;
};

class JTypeInstruction {
public:
    uint32_t imm;
    uint8_t rd;
    uint8_t opcode;
};

class Encoder {
public:
    static uint32_t encodeRType(const RTypeInstruction& instruction);
    static uint32_t encodeIType(const ITypeInstruction& instruction);
    static uint32_t encodeSType(const STypeInstruction& instruction);
    static uint32_t encodeBType(const BTypeInstruction& instruction);
    static uint32_t encodeUType(const UTypeInstruction& instruction);
    static uint32_t encodeJType(const JTypeInstruction& instruction);
    static uint8_t getOpcode(const std::string& mnemonic);
    static InstructionType getInstructionType(const std::string& mnemonic);
};

#endif // ENCODER_HH
