#include "ast.h"
#include <stdexcept>

int evaluate(const ASTNode& node, const std::map<std::string, int>& vars) {
    if (node.op == "DISCRIMINANT") {
        int a = vars.at(node.args[0]);
        int b = vars.at(node.args[1]);
        int c = vars.at(node.args[2]);
        return b * b - 4 * a * c;
    }
    throw std::runtime_error("Unknown operation");
}
