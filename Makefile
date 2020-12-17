all: DoubleShutter

DoubleShutter: main.o DSBoard.o
	g++ -o DoubleShutter main.o DSBoard.o

main.o: main.cpp DSBoard.h
	g++ -c main.cpp

DSBoard.o: DSBoard.cpp DSBoard.h
	g++ -c DSBoard.cpp

test: testDiePrint.cpp
	g++ -o testDice testDiePrint.cpp

clean:
	rm *.o
	rm DoubleShutter

