#! bin/bash

echo "running test ..."
echo "compiling piece.c"
gcc -c ./test/test.c
mv ./test.o ./test/test.o
gcc -o ./test/test ./test/test.o ./bin/piece.o ./bin/board.o

./test/test
echo "test is done"