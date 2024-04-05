#include <iostream>
#include <fstream>
#include "parser.hh"
#include "encoder.hh" // Incluir el encabezado encoder.hh

int main() {
    std::ifstream inputFile("../test/input.asm");
    if (!inputFile.is_open()) {
        std::cerr << "Error al abrir el archivo de entrada." << std::endl;
        return 1;
    }

    std::ofstream outputFile("../test/output.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Error al abrir el archivo de salida." << std::endl;
        return 1;
    }

    Parser parser;

    // Procesar cada línea del archivo de entrada
    std::string line;
    while (std::getline(inputFile, line)) {
        // Si es una instrucción, parsearla y escribir sus componentes en el archivo de salida
        if (parser.identifyLineType(line) == LineType::Instruction) {
            InstructionComponents components = parser.parseInstruction(line);
            InstructionType type = Encoder::getInstructionType(components.opcode);

            switch (type) {
                case InstructionType::R_Type:
                    // Aquí podrías construir el RTypeInstruction y asignarlo a components.rTypeInstruction
                    break;
                case InstructionType::I_Type:
                    // Construye y asigna el ITypeInstruction
                    break;
                case InstructionType::S_Type:
                    // Construye y asigna el STypeInstruction
                    break;
                case InstructionType::B_Type:
                    // Construye y asigna el BTypeInstruction
                    break;
                case InstructionType::U_Type:
                    // Construye y asigna el UTypeInstruction
                    break;
                case InstructionType::J_Type:
                    // Construye y asigna el JTypeInstruction
                    break;
                default:
                    std::cerr << "Tipo de instrucción desconocido." << std::endl;
                    continue;
            }
            uint32_t encodedInstruction = 0; 
            outputFile << encodedInstruction << std::endl;
        }
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Proceso completado. Se ha generado el archivo output.txt." << std::endl;
    return 0;
}
