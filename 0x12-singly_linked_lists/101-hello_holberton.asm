extern printf

global main


section .text

main:
  push rbp

    mov     rax, 0x2000004 ; write
    mov     rdi, 1 ; stdout
    lea     rsi, [rel msg]
    ; mov     rsi, msg
    mov     rdx, msg.len
    syscall

    mov     rax, 0x2000001 ; exit
    mov     rdi, 0
    call printf


section .data

msg: db "Hello, Holberton!", 0
fmt: db "%s", 10,0
