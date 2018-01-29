.cpp.o:	$*.h
	g++ -c $*.cpp -lwiringPi

all: main

main: comandos.o motor.o ultrassom.o
	g++ -o $@ $^ main -lwiringPi

clean:
	rm *.o *.*~ *~ main
