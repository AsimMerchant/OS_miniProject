all:	main
	./main
main:	main.o	deldupli.o	details.o	display.o	dupli.o	search.o
	gcc -o main main.o deldupli.o details.o display.o dupli.o search.o
main.o:	main.c
	gcc -o main.o -c main.c
deldupli.o:	deldupli.c
	gcc -o deldupli.o -c deldupli.c
details.o:	details.c
	gcc -o details.o -c details.c
display.o:	display.c
	gcc -o display.o -c display.c
dupli.o:	dupli.c
	gcc -o dupli.o -c dupli.c
search.o:	search.c
	gcc -o search.o -c search.c
clean:
	rm -rf *.o
	rm -rf main
