#pragma once
#include <string>

// Generates NASM assembly for the discriminant formula: d = b*b - 4*a*c
void generateAssembly(const std::string& tacFile, const std::string& outputAsmFile);
