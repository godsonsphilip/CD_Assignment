#include "parser.h"
#include "tokenizer.h"
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void parseMULADD(const vector<Token>& tokens) {
    ofstream postfix("outputs/postfix.txt");
    ofstream tac("outputs/tac.txt");

    if (tokens.size() < 11 || tokens[2].type != MULADD) {
        cerr << "Syntax Error: Expected MULADD\n";
        return;
    }

    string dest = tokens[0].value;
    string A = tokens[3].value;
    string B = tokens[5].value;
    string C = tokens[7].value;
    string D = tokens[9].value;

    // --- Postfix ---
    postfix << A << " " << B << " * "
            << C << " " << D << " * +\n";

    // --- 3AC ---
    tac << "t1 = " << A << " * " << B << "\n";
    tac << "t2 = " << C << " * " << D << "\n";
    tac << dest << " = t1 + t2\n";

    postfix.close();
    tac.close();
}
