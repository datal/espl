.PHONY: all clean

all: bcmp 

bcmp: bcmpa.o 
	gcc -m32 -o bcmp bcmpa.o

	
bcmpa.o: bcmpa.asm
	nasm -g -f elf bcmpa.asm

clean:
	rm -f *.o