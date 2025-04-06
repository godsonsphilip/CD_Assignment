#pragma once
#include "parser.h"
#include <map>

int evaluate(const ASTNode& node, const std::map<std::string, int>& vars);
