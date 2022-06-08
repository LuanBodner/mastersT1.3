
heap:
	gcc -c fila_prioridade_heap.c -o fila_prioridade_heap.o
	gcc main_heap.c fila_prioridade_heap.o -o main_heap

encadeada:
	gcc -c fila_prioridade_encadeada.c -o fila_prioridade_encadeada.o
	gcc main_encadeada.c fila_prioridade_encadeada.o -o main_encadeada

clean:
	rm -f main_encadeada
	rm -f main_heap
	rm -f *.o