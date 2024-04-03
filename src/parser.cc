#include "parser.hh"
#include <cctype>
#include <sstream>

// Función para eliminar los paréntesis de una cadena.
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

// Función para eliminar los comentarios "#" de una línea.
std::string removeComments(const std::string& line) {
    std::string result = line;
    size_t pos = result.find('#');
    if (pos != std::string::npos) {
        result.erase(pos);
    }
    return result;
}

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

InstructionComponents Parser::parseInstruction(const std::string& line) {
    InstructionComponents components;

    // Eliminar paréntesis y comentarios
    std::string cleanLine = removeParentheses(removeComments(line));

    std::istringstream stream(cleanLine);
    std::string word;

    // Extraer los operandos
    while (stream >> word) {
        components.operands.push_back(word);
    }

    return components;
}
