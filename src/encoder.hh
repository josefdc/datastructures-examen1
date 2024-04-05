/**
 * @file encoder.h
 * @brief Defines the structure and encoding functions for RISC-V assembly instructions.
 *
 * The Encoder class provides a collection of static methods to encode RISC-V instructions into their binary format. 
 * Static methods are used because these operations are relevant to the class as a whole rather than to any particular instance of it.
 * This allows for encoding operations to be performed without the need to instantiate the Encoder class.
 *
 * Usage of static methods facilitates:
 * - Accessing utility functions without creating an instance of the class.
 * - Efficient resource use, as no instance is required to utilize these functionalities.
 * - Organizational clarity, grouping related functionalities within a logical structure without requiring object context.
 */

#ifndef ENCODER_HH
#define ENCODER_HH

#include <cstdint>
#include <string>
#include "parser.hh"


/**
 * @enum InstructionType
 * @brief Enumerates the types of instructions supported by RISC-V.
 */
enum class InstructionType {
    R_Type, ///< R-type instruction.
    I_Type, ///< I-type instruction.
    S_Type, ///< S-type instruction.
    B_Type, ///< B-type instruction.
    U_Type, ///< U-type instruction.
    J_Type, ///< J-type instruction.
    Unknown ///< Unknown instruction type.
};

/**
 * @class RTypeInstruction
 * @brief Represents an R-type instruction.
 */
class RTypeInstruction {
public:
    RTypeInstruction(uint8_t _funct7, uint8_t _rs2, uint8_t _rs1, uint8_t _funct3, uint8_t _rd, uint8_t _opcode) 
        : funct7(_funct7), rs2(_rs2), rs1(_rs1), funct3(_funct3), rd(_rd), opcode(_opcode) {}

    uint8_t funct7; ///< Function code, part 7.
    uint8_t rs2;    ///< Source register 2.
    uint8_t rs1;    ///< Source register 1.
    uint8_t funct3; ///< Function code, part 3.
    uint8_t rd;     ///< Destination register.
    uint8_t opcode; ///< Opcode of the instruction.
};

class ITypeInstruction {
public:
    ITypeInstruction(uint32_t _imm, uint8_t _rs1, uint8_t _funct3, uint8_t _rd, uint8_t _opcode) 
        : imm(_imm), rs1(_rs1), funct3(_funct3), rd(_rd), opcode(_opcode) {}

    uint32_t imm;   ///< Immediate value.
    uint8_t rs1;    ///< Source register 1.
    uint8_t funct3; ///< Function code, part 3.
    uint8_t rd;     ///< Destination register.
    uint8_t opcode; ///< Opcode of the instruction.
};

class STypeInstruction {
public:
    STypeInstruction(uint32_t _imm, uint8_t _rs2, uint8_t _rs1, uint8_t _funct3, uint8_t _opcode) 
        : imm(_imm), rs2(_rs2), rs1(_rs1), funct3(_funct3), opcode(_opcode) {}

    uint32_t imm; ///< Immediate value.
    uint8_t rs2; ///< Source register 2.
    uint8_t rs1; ///< Source register 1.
    uint8_t funct3; ///< Function code, part 3.
    uint8_t opcode; ///< Opcode of the instruction.
};

class BTypeInstruction {
public:
    BTypeInstruction(uint32_t _imm, uint8_t _rs2, uint8_t _rs1, uint8_t _funct3, uint8_t _opcode) 
        : imm(_imm), rs2(_rs2), rs1(_rs1), funct3(_funct3), opcode(_opcode) {}

    uint32_t imm;
    uint8_t rs2;
    uint8_t rs1;
    uint8_t funct3;
    uint8_t opcode;
};

class UTypeInstruction {
public:
    UTypeInstruction(uint32_t _imm, uint8_t _rd, uint8_t _opcode) 
        : imm(_imm), rd(_rd), opcode(_opcode) {}

    uint32_t imm;
    uint8_t rd;
    uint8_t opcode;
};

class JTypeInstruction {
public:
    JTypeInstruction(uint32_t _imm, uint8_t _rd, uint8_t _opcode) 
        : imm(_imm), rd(_rd), opcode(_opcode) {}

    uint32_t imm;
    uint8_t rd;
    uint8_t opcode;
};

/**
 * @class Encoder
 * @brief Provides encoding functionality for different types of RISC-V instructions.
 *
 * This class includes a series of static methods designed to encode various types of RISC-V instructions into their binary representation.
 * Being static, these methods can be called without the need to instantiate the Encoder class, making them easily accessible
 * for any part of a program that needs to perform instruction encoding. These methods cover encoding for all major instruction types
 * in the RISC-V specification, including R-Type, I-Type, S-Type, B-Type, U-Type, and J-Type instructions.
 */
class Encoder {
public:
    /**
     * @brief Encodes an R-Type instruction into its 32-bit binary representation.
     * @param instruction The RTypeInstruction to be encoded.
     * @return The 32-bit binary representation of the R-Type instruction.
     */
    static uint32_t encodeRType(const RTypeInstruction& instruction);

    /**
     * @brief Encodes an I-Type instruction into its 32-bit binary representation.
     * @param instruction The ITypeInstruction to be encoded.
     * @return The 32-bit binary representation of the I-Type instruction.
     */
    static uint32_t encodeIType(const ITypeInstruction& instruction);

    /**
     * @brief Encodes an S-Type instruction into its 32-bit binary representation.
     * @param instruction The STypeInstruction to be encoded.
     * @return The 32-bit binary representation of the S-Type instruction.
     */
    static uint32_t encodeSType(const STypeInstruction& instruction);

    /**
     * @brief Encodes a B-Type instruction into its 32-bit binary representation.
     * @param instruction The BTypeInstruction to be encoded.
     * @return The 32-bit binary representation of the B-Type instruction.
     */
    static uint32_t encodeBType(const BTypeInstruction& instruction);

    /**
     * @brief Encodes a U-Type instruction into its 32-bit binary representation.
     * @param instruction The UTypeInstruction to be encoded.
     * @return The 32-bit binary representation of the U-Type instruction.
     */
    static uint32_t encodeUType(const UTypeInstruction& instruction);

    /**
     * @brief Encodes a J-Type instruction into its 32-bit binary representation.
     * @param instruction The JTypeInstruction to be encoded.
     * @return The 32-bit binary representation of the J-Type instruction.
     */
    static uint32_t encodeJType(const JTypeInstruction& instruction);

    /**
     * @brief Retrieves the opcode corresponding to a given instruction mnemonic.
     * @param mnemonic The mnemonic of the instruction for which the opcode is desired.
     * @return The opcode associated with the given mnemonic.
     */
    static uint8_t getOpcode(const std::string& mnemonic);

    /**
     * @brief Determines the instruction type based on a given mnemonic.
     * @param mnemonic The mnemonic of the instruction.
     * @return The type of the instruction as an InstructionType enum value.
     */
    static InstructionType getInstructionType(const std::string& mnemonic);

        // Métodos para inicializar diferentes tipos de instrucciones

    /**
     * @brief Initializes an R-Type instruction with the provided components.
     * @param instruction The RTypeInstruction to initialize.
     * @param funct7 Function code, part 7.
     * @param rs2 Source register 2.
     * @param rs1 Source register 1.
     * @param funct3 Function code, part 3.
     * @param rd Destination register.
     * @param opcode Opcode of the instruction.
     */
    static void initializeRTypeInstruction(RTypeInstruction& instruction, uint8_t funct7, uint8_t rs2, uint8_t rs1, uint8_t funct3, uint8_t rd, uint8_t opcode) {
        instruction.funct7 = funct7;
        instruction.rs2 = rs2;
        instruction.rs1 = rs1;
        instruction.funct3 = funct3;
        instruction.rd = rd;
        instruction.opcode = opcode;
    }

    /**
     * @brief Initializes an I-Type instruction with the provided components.
     * @param instruction The ITypeInstruction to initialize.
     * @param imm Immediate value.
     * @param rs1 Source register 1.
     * @param funct3 Function code, part 3.
     * @param rd Destination register.
     * @param opcode Opcode of the instruction.
     */
    static void initializeITypeInstruction(ITypeInstruction& instruction, uint32_t imm, uint8_t rs1, uint8_t funct3, uint8_t rd, uint8_t opcode) {
        instruction.imm = imm;
        instruction.rs1 = rs1;
        instruction.funct3 = funct3;
        instruction.rd = rd;
        instruction.opcode = opcode;
    }

    /**
     * @brief Initializes an S-Type instruction with the provided components.
     * @param instruction The STypeInstruction to initialize.
     * @param imm Immediate value.
     * @param rs2 Source register 2.
     * @param rs1 Source register 1.
     * @param funct3 Function code, part 3.
     * @param opcode Opcode of the instruction.
     */
    static void initializeSTypeInstruction(STypeInstruction& instruction, uint32_t imm, uint8_t rs2, uint8_t rs1, uint8_t funct3, uint8_t opcode) {
        instruction.imm = imm;
        instruction.rs2 = rs2;
        instruction.rs1 = rs1;
        instruction.funct3 = funct3;
        instruction.opcode = opcode;
    }

    /**
     * @brief Initializes a B-Type instruction with the provided components.
     * @param instruction The BTypeInstruction to initialize.
     * @param imm Immediate value.
     * @param rs2 Source register 2.
     * @param rs1 Source register 1.
     * @param funct3 Function code, part 3.
     * @param opcode Opcode of the instruction.
     */
    static void initializeBTypeInstruction(BTypeInstruction& instruction, uint32_t imm, uint8_t rs2, uint8_t rs1, uint8_t funct3, uint8_t opcode) {
        instruction.imm = imm;
        instruction.rs2 = rs2;
        instruction.rs1 = rs1;
        instruction.funct3 = funct3;
        instruction.opcode = opcode;
    }

    /**
     * @brief Initializes a U-Type instruction with the provided components.
     * @param instruction The UTypeInstruction to initialize.
     * @param imm Immediate value.
     * @param rd Destination register.
     * @param opcode Opcode of the instruction.
     */
    static void initializeUTypeInstruction(UTypeInstruction& instruction, uint32_t imm, uint8_t rd, uint8_t opcode) {
        instruction.imm = imm;
        instruction.rd = rd;
        instruction.opcode = opcode;
    }

    /**
     * @brief Initializes a J-Type instruction with the provided components.
     * @param instruction The JTypeInstruction to initialize.
     * @param imm Immediate value.
     * @param rd Destination register.
     * @param opcode Opcode of the instruction.
     */
    static void initializeJTypeInstruction(JTypeInstruction& instruction, uint32_t imm, uint8_t rd, uint8_t opcode) {
        instruction.imm = imm;
        instruction.rd = rd;
        instruction.opcode = opcode;
    }
};


#endif // ENCODER_HH
