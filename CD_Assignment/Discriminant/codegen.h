#pragma once
#include "ast.h"
#include <string>

std::string generateAssembly(const ASTNode& expr);  // Changed from vector<Statement> to ASTNode
