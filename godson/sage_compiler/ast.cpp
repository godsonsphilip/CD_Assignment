#include "ast.h"
#include <stdexcept>

int evaluate(const ASTNode& node, const std::map<std::string, int>& vars) {
    if (node.op == "MULADD") {
        int a = vars.at(node.args[0]);
        int b = vars.at(node.args[1]);
        int c = vars.at(node.args[2]);
        int d = vars.at(node.args[3]);
        return (a + b) * (c - d);
    }
    throw std::runtime_error("Unknown operation");
}
