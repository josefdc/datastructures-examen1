#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#include <string>

using namespace std;

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

string extractInst(string& l){
    if(l.find("sw") != l.npos){ l.erase(l.find("sw"), 2);return "sw";}
    if(l.find("sb") != l.npos){ l.erase(l.find("sb"), 2);return "sb";}
    if(l.find("sh") != l.npos){ l.erase(l.find("sh"), 2);return "sh";}
    if(l.find("addi") != l.npos){ l.erase(l.find("addi"), 4);return "addi";}
    if(l.find("lw") != l.npos){ l.erase(l.find("lw"), 2);return "lw";}
    if(l.find("add") != l.npos){ l.erase(l.find("add"), 3);return "add";}
    if(l.find("sub") != l.npos){ l.erase(l.find("sub"), 3);return "sub";}
    if(l.find("xor") != l.npos){ l.erase(l.find("xor"), 3);return "xor";}
    if(l.find("beq") != l.npos){ l.erase(l.find("beq"), 3);return "beq";}
    if(l.find("bne") != l.npos){ l.erase(l.find("bne"), 3);return "bne";}
    if(l.find("blt") != l.npos){ l.erase(l.find("blt"), 3);return "blt";}
    if(l.find("lui") != l.npos){ l.erase(l.find("lui"), 3);return "lui";}
    if(l.find("auipc") != l.npos){ l.erase(l.find("auipc"), 5);return "auipc";}
    if(l.find("jal") != l.npos){ l.erase(l.find("jal"), 3);return "jal";}
    return "";
}

string extractFunc3(string& inst){
    if( inst=="sw" )return "010";
    if( inst=="sh" )return "001";
    if( inst=="sb" )return "000";
    return "";
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

string processTypeB(string inst, string rest) {
    cout << "processTypeB" << endl;
    vector<string> args = split(rest);
    vector<string> numberConst= separeConstNumber(encodeConstNumber(args[2]));
    string rs2 = encodeRegister(args[1]);
    string rs1 = encodeRegister(args[0]);
    string func3;
    if(inst == "beq"){ func3 = "000"; }
    if(inst == "bne"){ func3 = "001"; }
    if(inst == "blt"){ func3 = "100"; }
    string opcode = "1100011";
    string result = numberConst[0] + rs2 +rs1 + func3 + numberConst[1] + opcode;

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

    // Procesar cada línea del archivo de entrada
    string line;
    while (getline(inputFile, line)) {
        if (hasComment(line)) {
            removeComment(line);
        }
        string inst = extractInst(line);
        if(isTypeS(inst)) {
            string typeS = processTypeS(inst, line);
            cout << typeS << endl;
        }
        if(isTypeR(inst)) {
            string typeR = processTypeR(inst, line);
            cout << typeR << endl;
        }
        if(isTypeI(inst)){
            string typeI = processTypeI(inst, line);
            cout << typeI << endl;
        }
        if(isTypeB(inst)){
            string typeB = processTypeB(inst, line);
            cout << typeB << endl;
        }
        if(isTypeU(inst)){
            string typeJ = processTypeJ(inst, line);
            cout << typeJ << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    cout << "Proceso completado. Se ha generado el archivo output.txt." << endl;
    return 0;
}
