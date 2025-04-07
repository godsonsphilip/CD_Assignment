#include "parser.h"
#include "tokenizer.h"
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void parseDISCRIMINANT(const vector<Token>& tokens) {
    ofstream postfix("outputs/postfix.txt");
    ofstream tac("outputs/tac.txt");

    if (tokens.size() < 9 || tokens[2].type != DISCRIMINANT) {
        cerr << "Syntax Error: Expected DISCRIMINANT\n";
        return;
    }

    string dest = tokens[0].value;
    string A = tokens[3].value;
    string B = tokens[5].value;
    string C = tokens[7].value;

    // --- Postfix ---
    postfix << B << " " << B << " * "
            << "4 " << A << " * " << C << " * -\n";

    // --- 3AC ---
    tac << "t1 = " << B << " * " << B << "\n";
    tac << "t2 = 4 * " << A << "\n";
    tac << "t3 = t2 * " << C << "\n";
    tac << dest << " = t1 - t3\n";

    postfix.close();
    tac.close();
}
