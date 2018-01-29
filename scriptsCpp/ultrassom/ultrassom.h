#include<wiringPi.h>
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>


class Ultrassom{
   private:
   int echoPin;
   int trigPin;
   int onTimeMicrosseconds;
   int timeOut;

   public:
   Ultrassom(int echoPin, int trigPin);
   Ultrassom(int echoPin, int trigPin, int onTimeMicrosseconds, int timeOut);
   double getDistancia();

   private:
   void WritePin(int GPIO, int value);
   int ReadPin(int GPIO);
};
