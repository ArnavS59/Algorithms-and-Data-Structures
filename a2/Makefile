p1: 2.1.cpp
	g++ -Wall -o p1 2.1.cpp

p2: 2.2.cpp
	g++ -Wall -o p2 2.2.cpp

p3: WindGauge.cpp testWindGauge.cpp 
	g++ -Wall -o p3 WindGauge.cpp testWindGauge.cpp

p4: 2.4.cpp
	g++ -Wall -o p4 2.4.cpp

p5: 2.5.cpp
	g++ -Wall -o p5 2.5.cpp

p7: 2.7.cpp
	g++ -Wall -o p7 2.7.cpp


all: p1 p2 p3 p4 p5 p7
	./p1
	./p2
	./p3
	./p4
	./p5
	./p7

clean:
	rm p1 p2 p3 p4 p5 p7