#include "asmgen.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void generateAssembly(const string& tacFile, const string& outputAsmFile) {
    ifstream tac(tacFile);
    ofstream out(outputAsmFile);
    if (!tac || !out) {
        cerr << "File error\n";
        return;
    }

    // Header and externals
    out << R"(; Auto-generated from tac.txt

extern printf
extern scanf
extern sprintf
extern MessageBoxA
extern ExitProcess
global Start

%include "macros.inc"

section .data
    input_fmt     db "%d", 0
    output_fmt    db "Result D = %d", 10, 0
    sprintf_fmt   db "Result D = %d", 0
    msg_title     db "Discriminant Result", 0
    msg_text      db 64 dup(0)

    promptA db "Enter value for A: ", 0
    promptB db "Enter value for B: ", 0
    promptC db "Enter value for C: ", 0

section .bss
    A resd 1
    B resd 1
    C resd 1
    t1 resd 1
    t2 resd 1
    D resd 1

section .text
Start:

    print_str promptA
    read_int A

    print_str promptB
    read_int B

    print_str promptC
    read_int C

    ; --- Compute t1 = B * B ---
    mov eax, [B]
    imul eax, [B]
    mov [t1], eax

    ; --- Compute t2 = 4 * A * C ---
    mov eax, 4
    imul eax, [A]
    imul eax, [C]
    mov [t2], eax

    ; --- Compute D = t1 - t2 ---
    mov eax, [t1]
    sub eax, [t2]
    mov [D], eax

    ; Print & MessageBox
    print_int [D]
    msgbox_int [D]

    push 0
    call ExitProcess
)";
}
