#include "tokenizer.h"
#include <fstream>
#include <sstream>
#include <cctype>

using namespace std;

vector<Token> tokenizeFile(const string& filename) {
    ifstream in(filename);
    ofstream out("outputs/tokens.txt");
    vector<Token> tokens;

    string line;
    while (getline(in, line)) {
        istringstream iss(line);
        string word;

        while (iss >> word) {
            // Check for attached semicolon (e.g. D;)
            if (!word.empty() && word.back() == ';') {
                word.pop_back();
                if (word == "=") tokens.push_back({EQUAL, word});
                else if (word == ",") tokens.push_back({COMMA, word});
                else if (word == "DISCRIMINANT") tokens.push_back({DISCRIMINANT, word});
                else if (isalpha(word[0])) tokens.push_back({IDENTIFIER, word});
                else tokens.push_back({NUMBER, word});

                tokens.push_back({SEMICOLON, ";"});
                continue;
            }

            if (word == "=") tokens.push_back({EQUAL, word});
            else if (word == ",") tokens.push_back({COMMA, word});
            else if (word == "DISCRIMINANT") tokens.push_back({DISCRIMINANT, word});
            else if (word == ";") tokens.push_back({SEMICOLON, word});
            else if (isalpha(word[0])) tokens.push_back({IDENTIFIER, word});
            else tokens.push_back({NUMBER, word});
        }
    }

    tokens.push_back({END, ""});

    // Output to tokens.txt
    for (const auto& token : tokens) {
        out << tokenTypeToString(token.type) << " (" << token.value << ")" << endl;
    }

    return tokens;
}

// Optional: Convert TokenType to string
string tokenTypeToString(TokenType type) {
    switch (type) {
        case IDENTIFIER:    return "IDENTIFIER";
        case EQUAL:         return "EQUAL";
        case COMMA:         return "COMMA";
        case DISCRIMINANT:  return "DISCRIMINANT";
        case NUMBER:        return "NUMBER";
        case SEMICOLON:     return "SEMICOLON";
        case END:           return "END";
        default:            return "UNKNOWN";
    }
}
