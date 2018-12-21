run : pfarrayd.o main.o PFADbackup.o
	g++ -o run main.o pfarrayd.o PFADbackup.o
main.o : main.cpp
	g++ -c main.cpp -std=c++11
pfarrayd.o : pfarrayd.cpp
	g++ -c pfarrayd.cpp -std=c++11
PFADbackup.o : PFADbackup.o
	g++ -c PFADbackup.cpp -std=c++11