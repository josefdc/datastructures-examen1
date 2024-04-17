#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// Función para eliminar espacios en blanco al principio de la cadena
void ltrim(std::string &s) {
    while (!s.empty() && std::isspace(s.front())) {
        s.erase(s.begin()); // Elimina el primer carácter
    }
}

// Función para eliminar espacios en blanco al final de la cadena
void rtrim(std::string &s) {
    while (!s.empty() && std::isspace(s.back())) {
        s.pop_back(); // Elimina el último carácter
    }
}

// Función que combina ltrim y rtrim para eliminar espacios de ambos lados
void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

bool hasComment(string& l) {
    return l.find("#") != l.npos;
    }

void removeComment(string& l) {
    if (hasComment(l)){
        l.erase(l.find("#"));
    }
}

string encodeRegister(string n) {
    int arg = stoi(n.substr(2,n.length()));
    bitset<5> binary(arg);
    return binary.to_string();
}

string encodeRs1 (string n) {
    int arg = stoi(n.substr(1,n.length()));
    bitset<5> binary(arg);
    return binary.to_string();
}

string encodeConstNumber(string n ) {
    int arg = stoi(n.substr(0,n.length()));
    bitset<12> binary(arg);
    return binary.to_string();
}

string encodeConstNumberTypeU(string n ) {
    int arg = stoi(n.substr(0,n.length()));
    bitset<20> binary(arg);
    return binary.to_string();
}

vector<string> separeConstNumber( string n ) {
    vector<string> result;
    result.push_back(n.substr(0, 7));
    result.push_back(n.substr(7, n.length()));
    return result;
}
vector<string> separeBtypeconst (string n ) {

    vector<string> result;
    result.push_back(n.substr(11,1)); // 12
    cout << n.substr(11,1) << endl;
    string parte2 = n.substr(5,10);
    cout << parte2 << endl;
    //reverse(parte2.begin(), parte2.end());
    result.push_back(parte2);
    string parte3 = n.substr(1,4);
    cout << parte3 << endl;
    //reverse(parte3.begin(), parte3.end());
    result.push_back(parte3);
    result.push_back(n.substr(10,1)); //11
    cout << n.substr(10,1) << endl;
    return result;
}


// beq x0, x0, swap
bool isTypeS(string& l) {
    if(l.find("sw") != l.npos) return 1;
    if(l.find("sb") != l.npos) return 1;
    if(l.find("sh") != l.npos) return 1;
    return 0;
}

bool isTypeR(string& l) {
    if(l.find("addi") != l.npos) return 0;
    if(l.find("add") != l.npos) return 1;
    if(l.find("sub") != l.npos) return 1;
    if(l.find("xor") != l.npos) return 1;
    return 0;
}

bool isTypeI(string& l) {
    if(l.find("addi") != l.npos) return 1;
    if(l.find("lw") != l.npos) return 1;
    return 0;
}

bool isTypeB( string& l ) {
    if(l.find("beq") != l.npos) return 1;
    if(l.find("bne") != l.npos) return 1;
    if(l.find("blt") != l.npos) return 1;
    return 0;
}

bool isTypeU( string& l ) {
    if(l.find("lui") != l.npos) return 1;
    if(l.find("auipc") != l.npos) return 1;
    return 0;
}

bool isTypeJ( string& l ) {
    if(l.find("jal") != l.npos) return 1;
    return 0;
}

string extractInst(string& l) {
    // Instrucciones de tipo S
    if (l.find("sw") != l.npos) { l.erase(l.find("sw"), 2); return "sw"; }
    if (l.find("sb") != l.npos) { l.erase(l.find("sb"), 2); return "sb"; }
    if (l.find("sh") != l.npos) { l.erase(l.find("sh"), 2); return "sh"; }

    // Instrucciones de tipo I
    if (l.find("addi") != l.npos) { l.erase(l.find("addi"), 4); return "addi"; }
    if (l.find("ori") != l.npos) { l.erase(l.find("ori"), 3); return "ori"; }
    if (l.find("lw") != l.npos) { l.erase(l.find("lw"), 2); return "lw"; }

    // Instrucciones de tipo R
    if (l.find("add") != l.npos) { l.erase(l.find("add"), 3); return "add"; }
    if (l.find("sub") != l.npos) { l.erase(l.find("sub"), 3); return "sub"; }
    if (l.find("xor") != l.npos) { l.erase(l.find("xor"), 3); return "xor"; }
    if (l.find("and") != l.npos) { l.erase(l.find("and"), 3); return "and"; }
    if (l.find("sll") != l.npos) { l.erase(l.find("sll"), 3); return "sll"; }

    // Instrucciones de tipo B
    if (l.find("beq") != l.npos) { l.erase(l.find("beq"), 3); return "beq"; }
    if (l.find("bne") != l.npos) { l.erase(l.find("bne"), 3); return "bne"; }
    if (l.find("blt") != l.npos) { l.erase(l.find("blt"), 3); return "blt"; }

    // Instrucciones de tipo U
    if (l.find("lui") != l.npos) { l.erase(l.find("lui"), 3); return "lui"; }
    if (l.find("auipc") != l.npos) { l.erase(l.find("auipc"), 5); return "auipc"; }

    // Instrucción de tipo J
    if (l.find("jal") != l.npos) { l.erase(l.find("jal"), 3); return "jal"; }

    return "";
}


string extractFunc3(string& inst) {
    if (inst == "beq") return "000";
    else if (inst == "bne") return "001";
    else if (inst == "blt") return "100";
    else if (inst == "bge") return "101";
    else if (inst == "bltu") return "110";
    else if (inst == "bgeu") return "111";
    else if (inst == "sw") return "010";
    else if (inst == "sh") return "001";
    else if (inst == "sb") return "000";
    
    else {
        cerr << "Error: Instrucción desconocida o no soportada '" << inst << "' para extractFunc3." << endl;
        throw std::invalid_argument("Instrucción desconocida para extractFunc3");
    }
}


vector<string> separeImn(string l){
    vector<string> result;
    while(l.find('(') != l.npos){
        size_t pos = l.find('(');
        result.push_back(l.substr(0, pos));
        l.erase(0, pos + 1);
    }
    while(l.find(')') != l.npos){
        size_t pos = l.find(')');
        result.push_back(l.substr(0, pos));
        l.erase(0, pos + 1);
    }

    return result;
}


vector<string> encodeBType(const string& label, int currentAddress, const map<string, int>& labelAddressMap) {
    if (labelAddressMap.find(label) == labelAddressMap.end()) {
        cerr << "Error: La etiqueta '" << label << "' no está definida." << endl;
        throw std::out_of_range("La etiqueta no está definida en el mapa.");
    }

    int targetAddress = labelAddressMap.at(label);
    int offset = targetAddress - currentAddress;

    // offset es un múltiplo de 2.
    if (offset % 2 != 0) {
        throw std::runtime_error("El offset no es un múltiplo de 2.");
    }
    offset >>= 1 ; // Desplazar 1 bit a la derecha, ya que el bit en la posicion cero no se tiene en cuenta

    bitset<13> offsetBits(offset); 
    string imm13 = offsetBits.to_string();

    // b12 es el bit más significativo de offsetBits.
    string b12 = imm13.substr(0, 1);

    // b11 es el segundo bit menos significativo de offsetBits.
    string b11 = imm13.substr(11, 1);

    // b10_5 son los bits 10 a 5 de offsetBits.
    string b10_5 = imm13.substr(1, 6);

    // b4_1 son los bits 4 a 1 de offsetBits.
    string b4_1 = imm13.substr(7, 4);

    return {b12, b11, b10_5, b4_1};
}

    






vector<string> split(string& l){
    vector<string> result;
    while(l.find(',') != l.npos){
        size_t pos = l.find(',');
        result.push_back(l.substr(0, pos));
        l.erase(0, pos + 1); // Avanzar más allá del carácter de coma
    }
    result.push_back(l.substr(0, l.length()));

    return result;
}

string processTypeS(string inst, string rest) {
    cout << "processTypeS" << endl;
    vector<string> args = split(rest);
    string opcode = "0100011";
    string rs2 = encodeRegister(args[0]);
    string func3 = extractFunc3(inst);
    string dest = args[1];
    vector<string> imn = separeImn(dest);
    //las constantes
    vector<string> numberConst= separeConstNumber(encodeConstNumber(imn[0]));
    string rs1= encodeRs1(imn[1]);
    // cout << "opcode " << opcode << endl;
    // cout << "rs2 " << rs2 << endl;
    // cout << "func3 " << func3 << endl;
    // cout << "rs1 " << rs1 << endl;
    string result = numberConst[0] + rs2 + rs1 + func3 + numberConst[1] + opcode;
    return result;
}

string processTypeR(string inst, string rest) {
    cout << "processTypeR" << endl;
    string func7;
    string func3;
    if(inst == "add"){ func7 = "0000000"; func3 = "000"; }
    if(inst == "sub"){ func7 = "0100000"; func3 = "000"; }
    if(inst == "xor"){ func7 = "0000000"; func3 = "100"; }
    vector<string> args = split(rest);
    string rs2 = encodeRegister(args[2]);
    string rs1 = encodeRegister(args[1]);
    string rd = encodeRegister(args[0]);
    string opcode = "0110011";
    // cout << "func7: " << func7 << endl;
    // cout << "rs2: " << rs2 << endl;
    // cout << "rs1: " << rs1 << endl;
    // cout << "func3: " << func3 << endl;
    // cout << "rd: " << rd << endl;
    string result = func7 + rs2 + rs1 + func3 +rd + opcode;
    return result;
    }

string processTypeI(string inst, string rest) {
    cout << "processTypeI" << endl;
    vector<string> args = split(rest);
    if (inst == "addi")
    {
        string imn = encodeConstNumber(args[2]);
        string rs1 = encodeRegister(args[1]);
        string func3 = "000";
        string rd = encodeRegister(args[0]);
        string opcode = "0010011";
        // cout << "imn: " << imn << endl;
        // cout << "rs1: " << rs1 << endl;
        // cout << "rd: " << rd << endl;
        string result = imn + rs1 + func3 + rd + opcode;
        return result;
    }
    if ( inst == "lw" ) {
        string dest = args[1];
        vector<string> imn = separeImn(dest);
        string numberConst= encodeConstNumber(imn[0]);
        string rs1= encodeRs1(imn[1]);
        string func3 = "010";
        string rd = encodeRegister(args[0]);
        string opcode = "0000011";
        string result = numberConst + rs1 + func3 + rd + opcode;
        return result;
    }
    return "";
}

string processTypeB(string inst, string rest, int currentAddress, const map<string, int>& labelAddressMap) {
    vector<string> args = split(rest);
    string label = args[2];
    trim(label);

    vector<string> imm = encodeBType(label, currentAddress, labelAddressMap);

    string rs2 = encodeRegister(args[1]);
    string rs1 = encodeRegister(args[0]);
    string func3 = extractFunc3(inst);
    string opcode = "1100011";

    // Asegura el orden correcto del inmediato y otros campos
    string result = imm[0] + imm[1] + rs2 + rs1 + func3 + imm[2] + imm[3] + opcode;

    // Verifica que la longitud de la instrucción es de 32 bits.
    if (result.size() != 32) {
        cerr << "La longitud de la instrucción codificada no es de 32 bits: " << result.size() << " bits." << endl;
        throw std::runtime_error("La instrucción codificada no tiene 32 bits.");
    }

    cout << "processTypeB" << endl;
    cout << result << endl;
    return result;
}





string processTypeU(string inst, string rest) {
    cout << "processTypeU" << endl;
    vector<string> args = split(rest);
    string numberConst = encodeConstNumberTypeU(args[1]);
    string rd = encodeRegister(args[0]);
    string opcode = "0110111";
    string result = numberConst + rd + opcode;
    return result;
}

string processTypeJ(string inst, string rest) {
    cout << "processTypeJ" << endl;
    vector<string> args = split(rest);
    string numberConst = encodeConstNumberTypeU(args[1]);
    string rd = encodeRegister(args[0]);
    string opcode = "1101111";
    string result = numberConst + rd + opcode;
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

    map<string, int> labelAddressMap;
    vector<pair<int, string>> instructions; // Para almacenar las instrucciones y su dirección
    string line;
    int currentAddress = 0;

    // Primera pasada: construir el mapa de etiquetas y guardar las instrucciones
    while (getline(inputFile, line)) {
    if (hasComment(line)) {
        removeComment(line);
    }
    trim(line); 

    if (line.empty()) continue;

    // Verificar si la línea define una etiqueta
    size_t colonPos = line.find(':');
    if (colonPos != string::npos) {
        string label = line.substr(0, colonPos);
        trim(label); 
        labelAddressMap[label] = currentAddress;
        continue; // No incrementar la dirección aún, las etiquetas no ocupan espacio
    }

    instructions.push_back(make_pair(currentAddress, line));
    currentAddress += 4; // cada instrucción ocupa 4 bytes
}


    inputFile.clear(); // Limpia el estado del flujo
    inputFile.seekg(0); // Vuelve al principio del archivo

    // Segunda pasada: procesar las instrucciones
    for (const auto& inst : instructions) {
        currentAddress = inst.first;
        string line = inst.second;

        string instType = extractInst(line);
        string encodedInst;
        if (isTypeS(instType)) {
            encodedInst = processTypeS(instType, line);
        } else if (isTypeR(instType)) {
            encodedInst = processTypeR(instType, line);
        } else if (isTypeI(instType)) {
            encodedInst = processTypeI(instType, line);
        } else if (isTypeB(instType)) {
            encodedInst = processTypeB(instType, line, currentAddress, labelAddressMap);
        } else if (isTypeU(instType)) {
            encodedInst = processTypeU(instType, line);
        } else if (isTypeJ(instType)) {
            encodedInst = processTypeJ(instType, line);
        }

        outputFile << encodedInst << endl;
        cout << encodedInst << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "Proceso completado. Se ha generado el archivo output.txt." << endl;
    return 0;
}

