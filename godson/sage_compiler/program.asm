; Z = A * B + C * D
; Assembly program using NASM + GoLink + WinAPI
; Outputs result in both terminal and MessageBox

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

    promptA       db "Enter value for A: ", 0
    promptB       db "Enter value for B: ", 0
    promptC       db "Enter value for C: ", 0
    promptD       db "Enter value for D: ", 0
    fmt_combined  db "Result Z = %d", 0

section .bss
    A   resd 1
    B   resd 1
    C   resd 1
    D   resd 1
    t1  resd 1
    t2  resd 1
    Z   resd 1

section .text
Start:

    ; Read A
    print_str promptA
    read_int A

    ; Read B
    print_str promptB
    read_int B

    ; Read C
    print_str promptC
    read_int C

    ; Read D
    print_str promptD
    read_int D

    ; Compute t1 = A * B
    mov eax, [A]
    imul eax, [B]
    mov [t1], eax

    ; Compute t2 = C * D
    mov eax, [C]
    imul eax, [D]
    mov [t2], eax

    ; Compute Z = t1 + t2
    mov eax, [t1]
    add eax, [t2]
    mov [Z], eax

    ; -------- Terminal output --------
    push dword [Z]
    push output_fmt
    call printf
    add esp, 8

    ; -------- MessageBox output --------
    push dword [Z]
    push fmt_combined
    push msg_text
    call sprintf
    add esp, 12

    push 0
    push msg_title
    push msg_text
    push 0
    call MessageBoxA

    push 0
    call ExitProcess
