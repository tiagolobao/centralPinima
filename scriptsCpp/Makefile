.cpp.o:	$*.h
	g++ -c $*.cpp -lwiringPi

all: main

main: comandos.o motor/motor.o ultrassom/ultrassom.o
	g++ -o $@ $^ main -lwiringPi

clean:
	rm *.o *.*~ *~ main
