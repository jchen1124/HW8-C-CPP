CXX = g++
CXXFLAGS = -Wall -g

test: test.cpp matrix.o
	$(CXX) $(CXXFLAGS) test.cpp matrix.o -o test

matrix.o: matrix.cpp matrix.h
	$(CXX) $(CXXFLAGS) -c matrix.cpp -o matrix.o

matrix_c: matrix.c
	gcc $(CXXFLAGS) -std=c99 matrix.c -o matrix_c

clean:
	rm -f *.o
	rm -f test
	rm -f matrix_c

run:
	./test

val_cpp: test
	valgrind --leak-check=full ./test

val_c: matrix_c
	valgrind --leak-check=full ./matrix_c