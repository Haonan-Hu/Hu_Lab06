Lab6: main.o Executive.o BinaryTree.o
	g++ -std=c++11 -g -Wall main.o Executive.o BinaryTree.o -o Lab6

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp BinaryTree.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

BinaryTree.o: BinaryTree.h BinaryTree.cpp
	g++ -std=c++11 -g -Wall -c BinaryTree.cpp

clean:
	rm *.o Lab6
