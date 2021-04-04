CC=gcc
FLAGS=-Wall -g
all: main1_1 main1_2 main1_3

main1_1: main1_1.o hello_ariel.o 
	$(CC) $(FLAGS) -o $@ main1_1.o hello_ariel.o

main1_2: libHello.so
	$(CC) $(FLAGS) main1_2.c -L. -l Hello -o $@

main1_3: main1_3.o libHello.so
	$(CC) $(FLAGS) -o main1_3 main1_3.o -ldl

libHello.so: hello_ariel.c hello_ariel.h
	$(CC) $(FLAGS) -o $@ -shared -fPIC hello_ariel.c

main1_1.o: main1_1.c hello_ariel.h
	$(CC) $(FLAGS) -c main1_1.c -o $@

main1_3.o: main1_3.c
	$(CC) $(FLAGS) -c $^ -o $@

hello_ariel.o: hello_ariel.c hello_ariel.h
	$(CC) $(FLAGS) -c hello_ariel.c -o $@

.PHONY: clean all

clean:
	rm -rf *.o *.so main1_3 main1_2 main1_1 