all: DoubleShutter

DoubleShutter: main.o DSBoard.o parseHelper.o
	g++ -o DoubleShutter main.o DSBoard.o parseHelper.o -std=c++11

main.o: main.cpp DSBoard.h parseHelper.h
	g++ -c main.cpp -std=c++11

DSBoard.o: DSBoard.cpp DSBoard.h
	g++ -c DSBoard.cpp -std=c++11

parseHelper.o: parseHelper.cpp parseHelper.h DSBoard.h
	g++ -c parseHelper.cpp -std=c++11

test: testDiePrint.cpp
	g++ -o testDice testDiePrint.cpp -std=c++11

clean:
	rm *.o
	rm DoubleShutter

