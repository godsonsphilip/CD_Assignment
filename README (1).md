[![GitHub Repo](https://img.shields.io/badge/GitHub-CD_Assignment-blue?logo=github)](https://github.com/godsonsphilip/CD_Assignment)


# 🛠️📦 Make a Custom Instruction in Compiler for a Given Expression

> **Assignment Topic**: _Make a custom instruction in a compiler for a given expression._

This project implements a complete compilation pipeline for a **custom instruction** called `MULADD`, designed specifically to evaluate expressions of the form:

```plaintext
Z = (A * B) + (C * D)
```

The system reads an expression from a `.sage` file, parses it using a custom lexer and parser, and then generates intermediate code and NASM-compatible assembly to produce a working `.exe` that shows the result both in the console and a GUI popup.

---

## 📂 File Structure

```plaintext
.
├── example.sage         # Input file with MULADD expression
├── main.cpp             # Main driver file
├── tokenizer.h/cpp      # Lexer for tokenizing input
├── parser.h/cpp         # Recursive-descent parser
├── ast.h/cpp            # AST and evaluation logic
├── asmgen.h/cpp         # NASM code generation from TAC
├── codegen.h/cpp        # Assembly utilities and helpers
├── macros.inc           # NASM macros for I/O
├── program.asm          # Generated NASM assembly
├── program.obj          # Object file from NASM
├── program.exe          # Final Windows executable
├── sage.exe             # Expression evaluator (C++)
├── sage_compiler.exe    # Compiles .sage to .asm/.exe
├── GoLink.exe           # Windows linker
├── build.bat            # Windows build script (optional)
├── outputs/
│   ├── postfix.txt      # Postfix expression output
│   └── tac.txt          # Three Address Code output
```

---

## 📝 Input Format

The compiler accepts input in the `.sage` file in the following format:

```plaintext
Z = MULADD A, B, C, D;
```

This corresponds to the arithmetic operation:

```plaintext
Z = (A * B) + (C * D)
```

During execution, the user is prompted to provide values for A, B, C, and D.

---

## 🧠 Technologies Used

- 🧾 **C++** – Lexical analysis, parsing, AST, and intermediate code generation
- 🛠️ **NASM (Netwide Assembler)** – x86 Assembly code generation
- 🪟 **Win32 API** – Message box for displaying GUI output
- 🔗 **GoLink** – Object to EXE linker for Windows
- 📁 **Custom DSL** – `.sage` source files for expression input

---

## ✅ Requirements

- ✅ C++ Compiler (`g++`)
- ✅ NASM installed
- ✅ GoLink (Windows linker)
- ✅ Windows OS
- ✅ Command-line interface

---

## ⚙️ How to Run the Project

### 🔧 Step-by-Step Setup

#### 1. **Build the Compiler**

```bash
g++ main.cpp tokenizer.cpp parser.cpp ast.cpp asmgen.cpp codegen.cpp -o sage_compiler.exe
```

#### 2. **Prepare Input File**

Edit `example.sage` to contain a valid `MULADD` expression:

```plaintext
Z = MULADD A, B, C, D;
```

#### 3. **Run the Compiler**

```bash
./sage_compiler.exe
```

This will:
- Prompt for input values
- Generate:
  - `outputs/postfix.txt`
  - `outputs/tac.txt`
  - `program.asm`

#### 4. **Assemble the `.asm` file**

```bash
nasm -f win32 program.asm -o program.obj
```

#### 5. **Link the Object File**

```bash
GoLink.exe /console program.obj
```

#### 6. **Run the Executable**

```bash
./program.exe
```

---

## 📤 Generated Outputs

- 🧮 `outputs/postfix.txt` – Postfix form of the input expression  
- 🛠️ `outputs/tac.txt` – Three Address Code  
- ⚙️ `program.asm` – NASM-compatible Assembly code  
- 🧱 `program.obj` – Object file  
- 🖥️ `program.exe` – Final Windows Executable

---

## 📈 Sample Output

**Input File (`example.sage`)**:
```plaintext
Z = MULADD A, B, C, D;
```

**User Input at Runtime**:
```plaintext
Enter value for A: 2
Enter value for B: 3
Enter value for C: 4
Enter value for D: 5
```

**Terminal Output**:
```plaintext
Result Z = 26
```

**GUI Popup (Windows MessageBox)**:
```
[ MessageBoxA ]
"Result Z = 26"
```

---

## 📎 Notes

- 🔍 Supports only `MULADD` operation as a custom instruction.
- 💡 Postfix and TAC help visualize intermediate steps in compilation.
- 🔧 GUI output is shown using `MessageBoxA` from `user32.dll`.
- 🧱 Assembly follows x86 architecture (32-bit, NASM syntax).
- 📦 Easily extensible for future expressions or instruction formats.

---

## 🪪 License

> Add your license here (e.g., MIT, GPL, etc.)

---

💻✨ _Crafted with C++, NASM, and ❤️ to bring custom compiler instructions to life!_


---

## 🔗 Repository

📁 GitHub Repository: [CD_Assignment](https://github.com/godsonsphilip/CD_Assignment)
