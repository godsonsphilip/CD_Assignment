#pragma once
#include "parser.h"
#include <map>

// Evaluates the ASTNode based on the "DISCRIMINANT" operation
int evaluate(const ASTNode& node, const std::map<std::string, int>& vars);
