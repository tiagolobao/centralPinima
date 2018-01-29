//#include​<wiringPi.h>
#include<iostream>

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
};
