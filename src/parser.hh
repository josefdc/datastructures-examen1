// parser.h
#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>

// Definimos un enum para los tipos de líneas que podemos encontrar.
enum class LineType {
    Label,
    Instruction,
    Directive,
    Comment,
    Unknown
};

// Una estructura para almacenar los componentes de una instrucción.
struct InstructionComponents {
    std::string opcode;
    std::vector<std::string> operands;
};

class Parser {
public:
    // Analiza una línea y determina su tipo.
    LineType identifyLineType(const std::string& line);

    // Extrae los componentes de una instrucción.
    InstructionComponents parseInstruction(const std::string& line);
};

#endif // PARSER_H
