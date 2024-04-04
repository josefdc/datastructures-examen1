#include "encoder.hh"

// Codifica instrucciones de tipo R
uint32_t Encoder::encodeRType(const RTypeInstruction& instruction) {
    return (instruction.funct7 << 25) |
            (instruction.rs2 << 20) |
            (instruction.rs1 << 15) |
            (instruction.funct3 << 12) |
            (instruction.rd << 7) |
            instruction.opcode;
}

// Codifica instrucciones de tipo I
uint32_t Encoder::encodeIType(const ITypeInstruction& instruction) {
    return (instruction.imm << 20) |
            (instruction.rs1 << 15) |
            (instruction.funct3 << 12) |
            (instruction.rd << 7) |
            instruction.opcode;
}

// Codifica instrucciones de tipo S
uint32_t Encoder::encodeSType(const STypeInstruction& instruction) {
    uint32_t imm11_5 = (instruction.imm & 0xfe0) << 20; // Mueve los bits 5-11 al lugar correcto
    uint32_t imm4_0 = (instruction.imm & 0x1f) << 7; // Mantiene los bits 0-4 en su lugar
    return imm11_5 |
            (instruction.rs2 << 20) |
            (instruction.rs1 << 15) |
            (instruction.funct3 << 12) |
            imm4_0 |
            instruction.opcode;
}

// Codifica instrucciones de tipo B
uint32_t Encoder::encodeBType(const BTypeInstruction& instruction) {
    uint32_t imm12_10_5 = ((instruction.imm & 0x800) << 20) | ((instruction.imm & 0x7e0) << 20); // Mueve los bits 10-5 y 12 al lugar correcto
    uint32_t imm4_1_11 = ((instruction.imm & 0x1e) << 7) | ((instruction.imm & 0x800) >> 4); // Mueve los bits 1-4 y 11 al lugar correcto
    return imm12_10_5 |
            (instruction.rs2 << 20) |
            (instruction.rs1 << 15) |
            (instruction.funct3 << 12) |
            imm4_1_11 |
            instruction.opcode;
}

// Codifica instrucciones de tipo U
uint32_t Encoder::encodeUType(const UTypeInstruction& instruction) {
    return (instruction.imm << 12) |
            (instruction.rd << 7) |
            instruction.opcode;
}

// Codifica instrucciones de tipo J
uint32_t Encoder::encodeJType(const JTypeInstruction& instruction) {
    uint32_t imm20 = (instruction.imm & 0x100000) >> 20;
    uint32_t imm10_1 = (instruction.imm & 0x7FE) >> 1;
    uint32_t imm11 = (instruction.imm & 0x800) >> 11;
    uint32_t imm19_12 = (instruction.imm & 0xFF000) >> 12;
    return (imm20 << 31) | (imm19_12 << 12) | (imm11 << 20) | (imm10_1 << 21) |
            (instruction.rd << 7) | instruction.opcode;
}

// Retorna el opcode basado en el mnemónico de la instrucción
uint8_t Encoder::getOpcode(const std::string& mnemonic) {
    if (mnemonic == "add") return 0x33; // Tipo R
    if (mnemonic == "addi") return 0x13; // Tipo I
    if (mnemonic == "sb") return 0x23; // Tipo S
    if (mnemonic == "beq") return 0x63; // Tipo B
    if (mnemonic == "lui") return 0x37; // Tipo U
    if (mnemonic == "jal") return 0x6F; // Tipo J
    if (mnemonic == "jalr") return 0x67; // Tipo I (JALR es especial)
    if (mnemonic == "lw") return 0x03; // Tipo I (LW es especial)
    return 0x00; // Opcode no encontrado
}

// Determina el tipo de instrucción basado en el mnemónico
InstructionType Encoder::getInstructionType(const std::string& mnemonic) {
    if (mnemonic == "add" || mnemonic == "sub" || mnemonic == "xor" || mnemonic == "or" || mnemonic == "and") {
        return InstructionType::R_Type;
    }
    if (mnemonic == "addi" || mnemonic == "lw" || mnemonic == "jalr") {
        return InstructionType::I_Type;
    }
    if (mnemonic == "sb" || mnemonic == "sw") {
        return InstructionType::S_Type;
    }
    if (mnemonic == "beq" || mnemonic == "bne" || mnemonic == "blt" || mnemonic == "bge") {
        return InstructionType::B_Type;
    }
    if (mnemonic == "lui" || mnemonic == "auipc") {
        return InstructionType::U_Type;
    }
    if (mnemonic == "jal") {
        return InstructionType::J_Type;
    }
    return InstructionType::Unknown;
}
