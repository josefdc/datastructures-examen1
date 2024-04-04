#include "parser.hh"
#include <cctype>
#include <sstream>


/**
 * @brief Removes parentheses from a given string.
 * 
 * This function iterates through the provided string and removes any open or close parentheses found.
 * @param line The string from which to remove parentheses.
 * @return A new string without any parentheses.
 */
std::string removeParentheses(const std::string& line) {
    std::string result = line;
    size_t pos = 0;
    while ((pos = result.find('(')) != std::string::npos) {
        result.erase(pos, 1);
    }
    while ((pos = result.find(')')) != std::string::npos) {
        result.erase(pos, 1);
    }
    return result;
}

/**
 * @brief Removes comments from a given string.
 * 
 * This function looks for the '#' character and removes it along with any following text, effectively removing comments from the line.
 * @param line The string from which to remove comments.
 * @return A new string without any comments.
 */
std::string removeComments(const std::string& line) {
    std::string result = line;
    size_t pos = result.find('#');
    if (pos != std::string::npos) {
        result.erase(pos);
    }
    return result;
}

/**
 * @brief Identifies the type of a given line of assembly code.
 * 
 * This method analyzes a line of assembly code to determine its type based on its first character or its syntax.
 * @param line The assembly code line to be analyzed.
 * @return The LineType enumeration value corresponding to the type of the line.
 */
LineType Parser::identifyLineType(const std::string& line) {
    if (line.empty() || line[0] == ';' || line[0] == '#') {
        return LineType::Comment;
    } else if (line.back() == ':') {
        return LineType::Label;
    } else if (line[0] == '.') {
        return LineType::Directive;
    } else {
        return LineType::Instruction;
    }
}

/**
 * @brief Parses an assembly instruction line to extract its components.
 * 
 * This method first removes comments and parentheses from the line. Then, it separates the line into words using whitespace as a delimiter, treating each word as an operand.
 * @param line The assembly instruction line to be parsed.
 * @return An InstructionComponents struct containing the opcode and operands extracted from the line.
 */
InstructionComponents Parser::parseInstruction(const std::string& line) {
    InstructionComponents components;

    // Remove parentheses and comments from the line
    std::string cleanLine = removeParentheses(removeComments(line));

    std::istringstream stream(cleanLine);
    std::string word;

    // Extract operands from the line
    while (stream >> word) {
        components.operands.push_back(word);
    }

    // Assuming the first operand is the opcode
    if (!components.operands.empty()) {
        components.opcode = components.operands.front();
        components.operands.erase(components.operands.begin());
    }

    return components;
}
