%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: canalyze testfgn  

test: canalyze testfgn 
	./canalyze
	./testfgn

canalyze: canalyze.o namelist.o fgetname.o
	$(CC) $(CFLAGS) -o $@ $^
testfgn: testfgn.o fgetname.o
	$(CC) $(CFLAGS) -o $@ -DTESTBC=1 $^

canalyze.o: canalyze.c namelist.h 
namelist.o: namelist.c namelist.h	

testfgn.o: testfgn.c fgetname.h
fgetname.o: fgetname.c fgetname.h

clean:
	rm -f canalyze testfgn *.o

