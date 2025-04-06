#include <iostream>
#include <map>
#include "tokenizer.h"
#include "parser.h"
#include "ast.h"      
#include "asmgen.h"

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

int main() {
    map<string, int> variables;

    cout << "Enter value for A: ";
    cin >> variables["A"];
    cout << "Enter value for B: ";
    cin >> variables["B"];
    cout << "Enter value for C: ";
    cin >> variables["C"];
    cout << "Enter value for D: ";
    cin >> variables["D"];

    auto tokens = tokenizeFile("example.sage");
    auto ast = parseMULADD(tokens);
    generateAssembly("outputs/tac.txt", "output.asm");
    int result = evaluate(ast, variables);

    cout << "Result Z = " << result << endl;

#ifdef _WIN32
    MessageBoxA(NULL, ("Result Z = " + to_string(result)).c_str(), "Output", MB_OK);
#endif

    return 0;
}
