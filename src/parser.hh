#ifndef PARSER_HH
#define PARSER_HH

#include <string>
#include <vector>


class InstructionComponents {
public:
    RTypeInstruction rTypeInstruction;
    ITypeInstruction iTypeInstruction;
    STypeInstruction sTypeInstruction;
    BTypeInstruction bTypeInstruction;
    UTypeInstruction uTypeInstruction;
    JTypeInstruction jTypeInstruction;
    std::string opcode;
    std::vector<std::string> operands;
};

/**
 * @enum LineType
 * @brief Enumerates the types of lines in an assembly file.
 */
enum class LineType {
    Instruction, ///< Assembly instruction.
    Label,       ///< Label definition.
    Directive,   ///< Directive.
    Comment      ///< Comment.
};

/**
 * @struct InstructionComponents
 * @brief Contains the components of an assembly instruction.
 */

/**
 * @class Parser
 * @brief Provides methods for parsing assembly code.
 */
class Parser {
public:
    /**
     * @brief Identifies the type of a given line of assembly code.
     * @param line The assembly code line to be analyzed.
     * @return The LineType enumeration value corresponding to the type of the line.
     */
    static LineType identifyLineType(const std::string& line);

    /**
     * @brief Parses an assembly instruction line to extract its components.
     * @param line The assembly instruction line to be parsed.
     * @return An InstructionComponents struct containing the opcode and operands extracted from the line.
     */
    static InstructionComponents parseInstruction(const std::string& line);
};

#endif // PARSER_HH
