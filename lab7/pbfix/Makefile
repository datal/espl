%.o: %.c
	gcc -c -o $@ $<

all: pbfix

pbfix: pbfix.o diff.o

pbfix.o: pbfix.c diff.h
diff.o: diff.c diff.h

clean:
	rm *.o