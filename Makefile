all: cshogi.c piece.c board.c
	gcc -c cshogi.c
	gcc -c piece.c
	gcc -c board.c
	mv *.o ./bin/
	gcc -o cshogi ./bin/cshogi.o ./bin/piece.o ./bin/board.o
	touch test.sh

piece.o: piece.c
	gcc -c piece.c
board.o: board.c
	gcc -c board.c
	touch test.sh

test: test.sh
	sh test.sh
clean:
	rm -f cshogi ./bin/*.o ./test/*.o ./test/test