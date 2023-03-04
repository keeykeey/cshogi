all: cshogi.c ./src/piece.c ./src/board.c
	gcc -c cshogi.c
	gcc -c ./src/piece.c
	gcc -c ./src/board.c
	mv *.o ./bin/
	gcc -o cshogi ./bin/cshogi.o ./bin/piece.o ./bin/board.o
	touch test.sh

piece: ./src/piece.c
	gcc -c ./src/piece.c
	mv piece.o ./bin
	touch test.sh

board: ./src/board.c
	gcc -c ./src/board.c
	touch test.sh

test: test.sh
	sh test.sh

clean:
	rm -f cshogi ./bin/*.o ./test/*.o ./test/test