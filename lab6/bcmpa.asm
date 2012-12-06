section .text
	
    global main
    global old_main
    extern compare
    extern fopen
    
main:
    push 	ebp
    mov		ebp,esp
    push 	DWORD [ebp+12]
    push	DWORD [ebp+8]
    call	old_main
    mov		esp,ebp
    pop 	ebp
    ret


old_main:
    push	ebp
    mov		ebp,esp
    sub		esp,8 ; local var file1 + file2
    
    ; file1 = fopen(argv[1], "r")
    mov		ebx, [ebp+12] 
    mov		ebx, [ebx+4]  
    push	romode
    push	ebx
    call	fopen
    mov		[ebp-4], eax
    
    ; file2 = fopen(argv[2], "r")
    mov		ebx, [ebp+12] 
    mov		ebx, [ebx+8]  
    push	romode
    push	ebx
    call	fopen
    mov		[ebp-8], eax
    
    ; compare(file1, file2)
    push	DWORD [ebp-8]
    push	DWORD [ebp-4]
    call	compare
    
    mov		esp,ebp
    pop		ebp
    ret
    
    
section .data
    romode db "r",0
    
    
