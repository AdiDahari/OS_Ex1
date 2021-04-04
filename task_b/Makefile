CC=gcc
FLAGS=-Wall -g
all: main2_1 main2_2 main2_3

main2_1: main2_1.c
	$(CC) $(FLAGS) -o $@ $^

main2_2: main2_2.c
	$(CC) $(FLAGS) -o $@ $^

main2_3: main2_3.c
	$(CC) $(FLAGS) -o $@ $^

main2_4: all main2_4.c
	$(CC) $(FLAGS) -o $@ main2_4.c

.PHONY: clean all

clean:
	rm -rf main2_4 main2_3 main2_2 main2_1