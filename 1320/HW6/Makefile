output: main.o stack_queue.o hw6.o 
	gcc main.c stack_queue.c hw6.c -o output

main.o: main.c
	gcc -c main.c

stack_queue.o: stack_queue.c stack_queue.h
	gcc -c stack_queue.c

hw6.o: hw6.c hw6.h
	gcc -c hw6.c

clean:
	rm *.o output