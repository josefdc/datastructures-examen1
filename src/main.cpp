#include <iostream>
#include <fstream>
#include "parser.hh" // Ruta relativa al directorio actual

int main() {
    // Abrir el archivo de entrada
    std::ifstream inputFile("../test/input.asm"); // Ruta relativa al directorio actual
    if (!inputFile.is_open()) {
        std::cerr << "Error al abrir el archivo de entrada." << std::endl;
        return 1;
    }

    // Abrir el archivo de salida
    std::ofstream outputFile("../test/output.txt"); // Ruta relativa al directorio actual
    if (!outputFile.is_open()) {
        std::cerr << "Error al abrir el archivo de salida." << std::endl;
        return 1;
    }

    // Instancia del Parser
    Parser parser;

    // Procesar cada línea del archivo de entrada
    std::string line;
    while (std::getline(inputFile, line)) {
        // Si es una instrucción, parsearla y escribir sus componentes en el archivo de salida
        if (parser.identifyLineType(line) == LineType::Instruction) {
            InstructionComponents components = parser.parseInstruction(line);
            for (const auto& operand : components.operands) {
                outputFile << operand << " ";
            }
            outputFile << std::endl;
        }
    }

    // Cerrar los archivos
    inputFile.close();
    outputFile.close();

    std::cout << "Proceso completado. Se ha generado el archivo output.txt." << std::endl;
    return 0;
}
