#pragma once
#include <vector>
#include <string>

enum TokenType {
    IDENTIFIER, NUMBER, EQUAL, COMMA, DISCRIMINANT, SEMICOLON, END
};

struct Token {
    TokenType type;
    std::string value;
};

std::vector<Token> tokenizeFile(const std::string& filename);
std::string tokenTypeToString(TokenType type);
