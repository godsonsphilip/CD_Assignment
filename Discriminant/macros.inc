%macro print_str 1
    push %1
    call printf
    add esp, 4
%endmacro

%macro read_int 1
    push %1
    push input_fmt
    call scanf
    add esp, 8
%endmacro
