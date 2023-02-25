piece.o: piece.c
	gcc -c piece.c
	touch test.sh
test: test.sh
	sh test.sh
clean:
	rm -f *.o ./test/*.o ./test/test