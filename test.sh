#! bin/bash

echo "running test ..."
gcc -c ./test/test.c
mv ./test.o ./test/test.o
gcc -o ./test/test ./test/test.o ./piece.o

./test/test
echo "RESULT : $?"
echo "test is done"