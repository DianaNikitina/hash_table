global crc32_hash_asm_no_strlen

section .text
crc32_hash_asm_no_strlen:
    mov     eax, 0xFFFFFFFF     
    
    mov     r8d, 0x01010101
    mov     r9d, 0x80808080

.read_4bytes:
    mov     ecx, dword [rdi]     
    
    mov     edx, ecx
    sub     edx, r8d             
    mov     esi, ecx
    not     esi                  
    and     edx, esi             
    and     edx, r9d            
    
    test    edx, edx            
    jnz     .tail

    crc32   eax, ecx              
    add     rdi, 4               
    jmp     .read_4bytes

.tail:
    mov     cl, byte [rdi]        
    test    cl, cl               
    jz      .end               
    crc32   eax, cl              
    inc     rdi                  
    jmp     .tail

.end:
    xor     eax, 0xFFFFFFFF      
    ret