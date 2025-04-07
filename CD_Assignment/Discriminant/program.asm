; Z = B * B - 4 * A * C
; NASM + GoLink + WinAPI
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
    sprintf_fmt   db "📊 The discriminant is: %d", 0
    msg_title     db "🎉 Quadratic Discriminant", 0
    msg_text      db 128 dup(0)

    intro_msg     db "🧠 Let's calculate the discriminant of a quadratic equation!", 10, \
                      "📘 Example: 2x^2 + 3x + 1", 10, \
                      "📐 Formula: D = B^2 - 4AC", 10, 0

    promptA       db "📌 Enter coefficient A: ", 0
    promptB       db "📌 Enter coefficient B: ", 0
    promptC       db "📌 Enter coefficient C: ", 0

section .bss
    A   resd 1
    B   resd 1
    C   resd 1
    t1  resd 1     ; t1 = B * B
    t2  resd 1     ; t2 = 4 * A * C
    Z   resd 1     ; Z = t1 - t2

section .text
Start:

    print_str intro_msg

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

    ; --- Compute Z = t1 - t2 ---
    mov eax, [t1]
    sub eax, [t2]
    mov [Z], eax

    ; --- Terminal Output ---
    push dword [Z]
    push output_fmt
    call printf
    add esp, 8

    ; --- MessageBox Output (Creative) ---
    push dword [Z]
    push sprintf_fmt
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
