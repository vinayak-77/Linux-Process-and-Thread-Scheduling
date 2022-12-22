all: q1.1 q1.2
q1.1: Q1.1.c
	gcc Q1.1.c -o q1.1

q1.2: Q1.2.c
	gcc Q1.2.c -o q1.2

clean:
	rm q1.1 q1.2