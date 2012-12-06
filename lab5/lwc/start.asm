section .text

global _start
global read
global write
global open
global close
global strlen

extern main
_start:
	add 	 esp,4
	mov	     ecx,esp
	sub      esp,4
	push	 ecx
	push	 DWORD [esp+4]
	call	 main
	mov	     ebx,eax
	mov	     eax,1
	int 0x80

read:
	mov eax, 3
	mov ebx, [esp+4]
	mov ecx, [esp+8]
	mov edx, [esp+12]
	int 0x80
	ret
write:
	mov eax, 4
	mov ebx, [esp+4]
	mov ecx, [esp+8]
	mov edx, [esp+12]
	int 0x80
	ret
open:
	mov eax, 5
	mov ebx, [esp+4]
	mov ecx, [esp+8]
	mov edx, [esp+12]
	int 0x80
	ret
close:
	mov eax, 6
	mov ebx, [esp+4]
	mov ecx, [esp+8]
	mov edx, [esp+12]
	int 0x80
	ret
strlen:
	push ebp
	mov ebp, esp
	mov eax, -1
.L2:
	add eax, 1
	mov ebx, eax
	add ebx, [ebp+8]
	movzx ebx, BYTE [ebx]
	test bl, bl
	jne .L2
	pop ebp
	ret




