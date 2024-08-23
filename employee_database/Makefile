p2: p2-supportc.o cmsc257-p2.o
	clang -Wall p2-supportc.o cmsc257-p2.o -o p2

cmsc257-p2.o: cmsc257-p2.c
	clang -c -Wall cmsc257-p2.c -o cmsc257-p2.o

p2-supportc.o: p2-support.c
	clang -c -Wall p2-support.c -o p2-supportc.o

clean:
	rm *.o p2