CC=gcc
all: estimator.c 
	gcc estimator.c estimator.S -std=c89 -o estimator
	gcc -c -std=c89 -g -Wall sorter.c -I$PWD 
	ar rcs libsort.a sorter.o
	gcc -c -std=c89 -g -Wall sorter.c -I$PWD -fPIC
	gcc -shared -o libsort.so sorter.o
	
clean:
	rm -f estimator libsort.so libsort.a sorter.o
run: estimator
	./estimator
