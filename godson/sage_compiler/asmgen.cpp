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
    output_fmt    db "Result Z = %d", 10, 0
    sprintf_fmt   db "Result Z = %d", 0
    msg_title     db "MULADD Result", 0
    msg_text      db 64 dup(0)

    promptA db "Enter value for A: ", 0
    promptB db "Enter value for B: ", 0
    promptC db "Enter value for C: ", 0
    promptD db "Enter value for D: ", 0

section .bss
    A resd 1
    B resd 1
    C resd 1
    D resd 1
    t1 resd 1
    t2 resd 1
    Z  resd 1

section .text
Start:

    print_str promptA
    read_int A

    print_str promptB
    read_int B

    print_str promptC
    read_int C

    print_str promptD
    read_int D

    ; --- Compute t1 = A * B ---
    mov eax, [A]
    imul eax, [B]
    mov [t1], eax

    ; --- Compute t2 = C * D ---
    mov eax, [C]
    imul eax, [D]
    mov [t2], eax

    ; --- Compute Z = t1 + t2 ---
    mov eax, [t1]
    add eax, [t2]
    mov [Z], eax

    ; Print & MessageBox
    print_int [Z]
    msgbox_int [Z]

    push 0
    call ExitProcess
)";
}
