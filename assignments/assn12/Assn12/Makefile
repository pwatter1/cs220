CC=gcc

all: loader.c 
	gcc -std=c89 -m32 -Wl,-z,execstack loader.c -o loader
	
clean:
	rm -f loader
