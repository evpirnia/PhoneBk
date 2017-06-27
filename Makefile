default: llist.cpp llist.h main.cpp record.h
	g++ -c main.cpp llist.cpp
	g++ *.o -o project2
	./project2

clear: main.o llist.o
	rm main.o llist.o

debug: llist.cpp llist.h main.cpp record.h
	g++ -DDEBUGMODE -c main.cpp llist.cpp
	g++ *.o -o project2
	./project2
