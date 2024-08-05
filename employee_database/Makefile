p2: p2-supportc.o cmsc257-p2.o
	gcc -Wall p2-supportc.o cmsc257-p2.o -o p2

cmsc257-p2.o: cmsc257-p2.c
	gcc -c -Wall cmsc257-p2.c -o cmsc257-p2.o

p2-supportc.o: p2-support.c
	gcc -c -Wall p2-support.c -o p2-supportc.o

clean:
	rm *.o p2