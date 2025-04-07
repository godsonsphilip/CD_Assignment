@echo off
nasm -f win32 program.asm -o program.obj
gcc -m32 program.obj -o program.exe -Wl,--subsystem,console -luser32 -lkernel32 -lmsvcrt
program.exe
pause
