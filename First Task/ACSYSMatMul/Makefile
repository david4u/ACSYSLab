CC = g++

main.exe : main.o basic.o multi.o single.o

	g++ -g -pthread -march=znver2 main.o basic.o multi.o single.o

main.o : main.cpp

	g++ -c -pthread -march=znver2 main.cpp

multi.o : multi.cpp

	g++ -c -pthread -march=znver2 multi.cpp

single.o : single.cpp

	g++ -c -march=znver2 single.cpp

basic.o : basic.cpp

	g++ -c -march=znver2 basic.cpp

clean:
	rm basic.o single.o multi.o main.o main.exe