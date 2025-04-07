
# 📘 Custom Instruction: DISCRIMINANT - Compiler Design Assignment

Welcome to this compiler design assignment project! This walkthrough details the full implementation of a custom instruction `DISCRIMINANT`, which evaluates the **DISCRIMINANT** of a quadratic equation using the formula:

```
Z = B^2 - 4 * A * C
```

This value helps determine the nature of roots of a quadratic equation `Ax² + Bx + C = 0`. The project shows how a compiler is modified to recognize a new instruction and generate intermediate as well as assembly code for it.

---

## 🛠️ Objective

**Design a custom compiler instruction** for computing the DISCRIMINANTriminant and show its impact through:

- Tokenization
- Parsing
- Abstract Syntax Tree (AST)
- Three Address Code (3AC)
- Assembly Code Generation
- Custom NASM Output

---

## 📁 File Structure

```
.
├── asmgen.h / asmgen.cpp         # Assembly code generation
├── ast.h / ast.cpp               # AST representation & evaluator
├── tokenizer.h / tokenizer.cpp   # Token definitions & tokenizer
├── parser.h / parser.cpp         # Parser for DISCRIMINANT instruction
├── main.cpp                      # Main I/O & compiler interface
├── macros.inc                    # NASM macro definitions
├── output.asm                    # Generated NASM Assembly
├── outputs/
│   ├── postfix.txt               # Postfix representation
│   └── tac.txt                   # Three Address Code
├── example.sage                  # Input source file
└── README.md                     # Project documentation
```

---

## 🌳 Parse Tree & Expression

**Input:**  
```
Z = DISCRIMINANT B , A , C ;
```

**Parse Tree:**
```
     =
   /   \
  Z    DISCRIMINANT
       / | \
      B  A  C
```

---

## 🔁 Three Address Code (TAC)

```
t1 = B * B
t2 = 4 * A * C
Z = t1 - t2
```

---

## 🪄 NASM Assembly (output.asm)

This NASM assembly reads values for A, B, and C, computes the DISCRIMINANTriminant, and shows the result using both `printf` (terminal) and `MessageBoxA` (GUI popup).

**MessageBox Output Example:**

```
📐 DISCRIMINANT = B² - 4AC
📊 DISCRIMINANT = 16
🔍 Real & Equal roots! ✔️
```

---

## 🚀 Running the Program

1. Open the solution in an IDE (Visual Studio or any NASM-supported IDE).
2. Provide input values when prompted.
3. Observe the output in terminal and Windows message box.

---

## 🔗 GitHub Repository

Explore the full code and updates at:  
👉 [https://github.com/godsonsphilip/CD_Assignment](https://github.com/godsonsphilip/CD_Assignment)

---

Made with ❤️ for Compiler Design.
