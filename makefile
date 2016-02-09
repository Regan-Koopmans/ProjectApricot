main: main.C
	g++ main.C -Wall -Werror -pedantic -o main

clean:
	rm *.out

run:
	./main
