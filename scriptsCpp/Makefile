.cpp.o:	$*.h
	g++ -c $*.cpp -lwiringPi

all: main

main: comandos.o motor.o ultrassom.o
	g++ -o $@ $^ -lwiringPi

clean:
	rm *.o *.*~ *~ main
