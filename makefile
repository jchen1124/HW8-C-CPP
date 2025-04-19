CXX = g++
CXXFLAGS = -Wall

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

val:
	$(CXX) -s test.cpp matrix.o -o test