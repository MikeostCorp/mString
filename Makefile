all: myString clean

myString: main.o mString.o
	g++ main.cpp -o main mString.cpp

main.o: main.cpp
	g++ -c main.cpp

mString.o: mString.cpp mString.h
	g++ -c mString.cpp

clean:
	rm -rf *.o myString