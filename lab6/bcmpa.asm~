section .text
	
    global main
    extern fread
    extern printf
    
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
    push	DWORD [ebp-8] ;file2
    push	DWORD [ebp-4] ;file1
    call	compare
    
    mov		esp,ebp
    pop		ebp
    ret

fopen:
    push	ebp
    mov		ebp, esp
    
    mov 	eax, 5
    mov 	ebx, [ebp+8] ;file1
    mov 	ecx, [ebp+12] ;"r"
    int 	0x80
    
    mov		esp,ebp
    pop		ebp
    ret
    
compare:
    push	ebp
    mov		ebp, esp
    sub		esp, 12 ; local var counter, ch1, ch2
     
    mov		DWORD [ebp-4], 0 ;counter
    mov		DWORD [ebp-8], 0 ;ch1 
    mov		DWORD [ebp-12], 0 ;ch2

.LOOP:    
    ; fread(&ch1, 1, 1, file1) 
    lea		ebx, [ebp-8] ;&ch1
    push	DWORD [ebp+8] ;file1
    push	1
    push	1
    push	ebx ;&ch1
    call	fread
    mov		ecx, eax
    
    ; fread(&ch2, 1, 1, file2) 
    lea		ebx, [ebp-12] ;&ch2
    push	DWORD [ebp+12] ;file2
    push	1
    push	1
    push	ebx ;&ch2
    call	fread
    mov		edx, eax
    
    ; if (!fread(&ch1, 1, 1, file1) && !fread(&ch2, 1, 1, file2))  
    test 	cl,cl
    je		.END
    test	dl,dl	
    je		.END
    mov		eax, DWORD [ebp-12] ; ch2
    mov		ebx, DWORD [ebp-8]  ; ch1
    cmp		eax, ebx
    je		.AFTER_PRINT
    push	eax ;ch2
    push	ebx ;ch1
    mov		ecx, DWORD [ebp-4]
    add		ecx, 1
    push	ecx
    push	msg
    call	printf



.AFTER_PRINT:
    add		DWORD [ebp-4], 1
    jmp		.LOOP


.END:
    mov		esp,ebp
    pop		ebp
    ret
    
section .data
    romode db "r",0
    msg db "byte %d -%d +%d\n", 0xa 
    
    
