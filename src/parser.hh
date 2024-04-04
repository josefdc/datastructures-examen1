/**
 * @file parser.h
 * @brief Defines the Parser class used to analyze and extract components from assembly lines.
 *
 * This header file defines the structure and functionalities for parsing assembly lines,
 * identifying their types (e.g., instructions, labels, directives), and extracting instruction components.
 */

#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>

/**
 * @enum LineType
 * @brief Represents the possible types of lines found in assembly code.
 */
enum class LineType {
    Label,       ///< A label marking a location in code.
    Instruction, ///< An assembly instruction.
    Directive,   ///< A directive to the assembler.
    Comment,     ///< A comment line.
    Unknown      ///< An unknown line type.
};

/**
 * @struct InstructionComponents
 * @brief Holds the opcode and operands of an assembly instruction.
 *
 * This structure is used to store the decomposed parts of an assembly instruction,
 * including its opcode and any operands it may have.
 */
struct InstructionComponents {
    std::string opcode;                 ///< The opcode of the instruction.
    std::vector<std::string> operands;  ///< The operands of the instruction, if any.
};

/**
 * @class Parser
 * @brief Provides functionalities for parsing assembly code lines.
 *
 * The Parser class includes methods for identifying the type of a given line of assembly code
 * and for extracting the components of an instruction from a line.
 */
class Parser {
public:
    /**
     * @brief Identifies the type of a given line of assembly code.
     * @param line The assembly code line to be analyzed.
     * @return The LineType enumeration value corresponding to the type of the line.
     */
    LineType identifyLineType(const std::string& line);

    /**
     * @brief Extracts the opcode and operands from an assembly instruction line.
     * @param line The assembly instruction line to be parsed.
     * @return An InstructionComponents struct containing the opcode and operands.
     */
    InstructionComponents parseInstruction(const std::string& line);
};

#endif // PARSER_H
