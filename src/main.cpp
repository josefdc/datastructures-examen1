#include <iostream>
#include <fstream>
#include <vector>
//#include "parser.hh"
//#include "encoder.hh" // Incluir el encabezado encoder.hh

using namespace std;

bool hasComment(string& l) {
    return l.find("#") != l.npos;
    }

 void removeComment(string& l) {
    if (hasComment(l)){
        l.erase(l.find("#"));
    }
 }

bool isTypeS(string& l) {
    if(l.find("sw") != l.npos){
        return 1;
    } else if(l.find("sb") != l.npos){
        return 1;
    } else if(l.find("sh") != l.npos){
        return 1;
    } else {
        return 0;
    }
}

string extractInst(string& l){
    if(l.find("sw") != l.npos){
        l.erase(l.find("sw"), 2);
        return "sw";
    } else if(l.find("sb") != l.npos){
        l.erase(l.find("sb"), 2);
        return "sb";
    } else if(l.find("sh") != l.npos){
        l.erase(l.find("sh"), 2);
        return "sh";
    }
    return "";
}

vector<string> split(string& l){
    vector<string> result;
    while(l.find(',') != l.npos){
        size_t pos = l.find(',');
        result.push_back(l.substr(0, pos));
        l.erase(0, pos + 1); // Avanzar más allá del carácter de coma
    }
    result.push_back(l.substr(0, l.length()));
    //print the vector
    for (const auto& element : result) {
        cout << element << " ";
    }
    cout << endl;

    return result;
}

int main() {
    ifstream inputFile("../test/input.asm");
    if (!inputFile.is_open()) {
        cerr << "Error al abrir el archivo de entrada." << endl;
        return 1;
    }

    ofstream outputFile("../test/output.txt");
    if (!outputFile.is_open()) {
        cerr << "Error al abrir el archivo de salida." << endl;
        return 1;
    }


    // Procesar cada línea del archivo de entrada
    string line;
    while (getline(inputFile, line)) {
        if (hasComment(line)) {
            removeComment(line);
            cout << line << endl;
        }
        if (isTypeS(line)){
            cout << "Tipo S" << endl;
            cout << extractInst(line) << " extraido." << endl;
            split(line);
        }
    }

    inputFile.close();
    outputFile.close();

    cout << "Proceso completado. Se ha generado el archivo output.txt." << endl;
    return 0;
}
