all: piece.c board.c
	gcc -c piece.c
	gcc -c board.c
	touch test.sh

piece.o: piece.c
	gcc -c piece.c
board.o: board.c
	gcc -c board.c
	touch test.sh

test: test.sh
	sh test.sh
clean:
	rm -f *.o ./test/*.o ./test/test