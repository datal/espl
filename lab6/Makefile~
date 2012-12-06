.PHONY: all clean

all: bcmp 

bcmp: bcmp.o bcmpa.o 
	gcc -m32 -o bcmo bcmp.o bcmpa.o

bcmp.o: bcmp.c 
	cc -c -m32 bcmp.c
	
bcmpa.o: bcmpa.asm
	nasm -g -f elf bcmpa.asm

clean:
	rm -f *.o