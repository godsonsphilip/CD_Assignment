# 📘 Custom Instruction Compiler Enhancement – `DISC` for Discriminant Calculation

Welcome to the official repository for our **Compiler Design Assignment**, where we crafted a **custom instruction named `DISC`** to compute the discriminant of a quadratic equation using:

> **Z = B × B - 4 × A × C**

This README offers a full walkthrough: from lexical analysis and parse trees to assembly generation and execution – all tailored for a better understanding and appreciation of compiler internals.

---

## ✨ What’s This All About?
This project demonstrates how to extend a compiler to support a **custom mathematical instruction**. We replaced the generic instruction `MULADD` with a newly designed instruction:

### ✅ `DISC`: Computes the discriminant of a quadratic equation
Formula:
```
Z = B * B - 4 * A * C
```
> 📌 Sample Equation: 3x² + 2x + 4 → Discriminant = 2² - 4×3×4 = 4 - 48 = -44

This showcases how real-world compiler enhancement allows optimization, better semantics, and tighter integration for specific operations.

---

## 🌳 Parse Tree
A single-line instruction like:
```txt
Z = DISC B , A , C ;
```
is parsed into:
```
    =
   / \
  Z  DISC
       / | \
      B  A  C
```

---

## ⚙️ Three Address Code (TAC)
```
t1 = B * B
t2 = 4 * A * C
Z = t1 - t2
```
This intermediate representation helps bridge the gap between high-level source and low-level machine code.

---

## 🗃️ Pseudo Register Execution (Assembly Perspective)
```
; t1 = B * B
mov eax, [B]       ; move value of B into register
imul eax, [B]      ; multiply it with B (B * B)
mov [t1], eax      ; store result in t1

; t2 = 4 * A * C
mov eax, 4         ; move 4 into register
imul eax, [A]      ; multiply with A (4 * A)
imul eax, [C]      ; multiply with C (4 * A * C)
mov [t2], eax      ; store result in t2

; Z = t1 - t2
mov eax, [t1]      ; move t1 into register
sub eax, [t2]      ; subtract t2 (t1 - t2)
mov [Z], eax       ; store final result in Z
```
This showcases the exact pseudo-register movement used in our NASM output file – a precise realization of the `DISC` logic.

---

## 🛠️ File Structure
```
📁 CD_Assignment
├── main.cpp              → Entry point (C++)
├── parser.h/.cpp         → Contains grammar parsing logic for DISC
├── tokenizer.h/.cpp      → Lexical analysis
├── asmgen.h/.cpp         → Assembly generator for x86 NASM
├── macros.inc            → NASM I/O macros
├── output.asm            → Generated Assembly file
├── outputs/
│   ├── tac.txt           → Three-address code output
│   ├── postfix.txt       → Postfix representation
│   └── tokens.txt        → Token stream
├── example.sage          → Source code input (DISC instruction)
└── README.md             → You’re here :)
```

---

## 🔁 Flow of Execution
1. **Input**: Provide values for A, B, and C.
2. **Lexical Analysis**: Tokenizes the custom `DISC` instruction.
3. **Parsing**: Converts tokens to a parse tree.
4. **TAC Generation**: Intermediate code using temp variables.
5. **Assembly Generation**: Translates to NASM-compatible x86 code.
6. **Execution**: Prints result to terminal and a MessageBox (Windows).

---

## 📋 Prerequisites
Install the following tools:

### 🧰 Required Software & Why We Use Them
- 🔧 **NASM** – Netwide Assembler: Used to assemble the low-level `.asm` file into object code.  
  👉 [Download NASM](https://www.nasm.us/)
  - *Why?* Converts our custom `DISC` logic into Windows-compatible machine code.

- 🔗 **GoLink** – A lightweight Windows linker to bind object files with Windows DLLs.  
  👉 [Download GoLink](https://www.godevtool.com/Golink.zip)
  - *Why?* Helps link WinAPI functions like `MessageBoxA` into our NASM output.

- 🪟 **Windows OS** – Required to use the `MessageBoxA` WinAPI for GUI output.
  - *Why?* For fun and friendly visual results alongside terminal output!

---

## 🧑‍💻 Installation & Setup (via CMD)
Make sure your terminal points to the project directory, then:

### ⚙️ Compile the Assembly File
```bash
nasm -f win32 output.asm -o output.obj
```

### 🔗 Link Using GoLink
```bash
GoLink /console output.obj kernel32.dll user32.dll msvcrt.dll
```

### ▶️ Run the Executable
```bash
output.exe
```

> 💡 **TIP**: Add NASM and GoLink to your system PATH for smoother CLI usage.

---

## 💡 Why DISC? – Significance of This Custom Instruction
✅ **Tailored Instruction**: Instead of using multiple MUL and ADD instructions, `DISC` condenses this into a semantic unit, providing better readability and abstraction.

✅ **Optimization Friendly**: This can be optimized at the compiler backend for faster execution and smaller binary sizes.

✅ **Domain-Specific Enhancement**: Since discriminants are common in quadratic problems, this instruction brings DSL-like power to our language.

✅ **Pedagogical Clarity**: Great for understanding how high-level mathematical ideas map down to machine instructions.

✅ **Compiler Design Practice**: Illustrates how to modify lexer, parser, intermediate code generator, and backend emitter.

> 💬 The goal was to enhance the language and compiler to feel intuitive, powerful, and specialized. Mission accomplished! 🚀

---

## 📸 Program Output
### Console:
```
Enter value for A: 3
Enter value for B: 2
Enter value for C: 4
Result Z = -44
```

### MessageBox:
🧮 *"📐 The discriminant is -44 📐\nThis is computed using Z = B² - 4AC"*

---

## 🔗 GitHub Repository
[👉 Visit GitHub Repository](https://github.com/godsonsphilip/CD_Assignment)

---

⭐ If this helped you understand compiler construction better, consider giving the repo a star and trying your own custom instructions!

