run : main.o square.o rectangle.o shape2D.o
	g++ -o run main.o square.o rectangle.o shape2D.o -std=c++11
main.o : main.cpp
	g++ -c main.cpp -std=c++11
square.o : square.cpp
	g++ -c square.cpp -std=c++11
rectangle.o : rectangle.cpp
	g++ -c rectangle.cpp -std=c++11
shape2D.o : shape2D.cpp
	g++ -c shape2D.cpp -std=c++11
