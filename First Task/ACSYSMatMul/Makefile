CC = g++

main.exe : main.o basic.o multi.o single.o

	g++ -g main.o basic.o multi.o single.o

main.o : main.cpp

	g++ -c main.cpp

multi.o : multi.cpp

	g++ -c multi.cpp

single.o : single.cpp

	g++ -c single.cpp

basic.o : basic.cpp

	g++ -c basic.cpp

clean:
	rm basic.o single.o multi.o main.o main.exe