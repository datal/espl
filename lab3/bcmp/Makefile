%.o: %.c
	gcc -c -o $@ $<

all: bcmp bfix

bcmp.o: bcmp.c
	gcc -c -o bcmp.o bcmp.c

bcmp: bcmp.o
	gcc -o bcmp bcmp.o

bfix: bfix.o diff.o

bfix.o: bfix.c diff.h
diff.o: diff.c diff.h

clean:
	rm *.o