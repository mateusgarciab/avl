parametrosCompilacao=-Wall #-Wshadow
nomePrograma=trab1_20221261_20224378

all: $(nomePrograma)

run: $(nomePrograma)
	valgrind --leak-check=full ./$(nomePrograma) 

$(nomePrograma): main.o avl.o fila.o
	gcc -o $(nomePrograma) main.o avl.o fila.o $(parametrosCompilacao)

main.o: main.c
	gcc -c main.c $(parametrosCompilacao)

ordenacao.o: avl.h avl.c
	gcc -c avl.c $(parametrosCompilacao)
	
fila.o: fila.h fila.c
	gcc -c fila.c $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
