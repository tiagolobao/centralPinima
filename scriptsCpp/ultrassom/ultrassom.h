#include​ <wiringPi.h>
#include <iostream.h>

class Ultrassom{
   private:
   uint_8 echoPin;
   uint_8 trigPin;
   uint_8 onTimeMicrosseconds;
   uint_8 timeOut;

   public:
   Ultrassom(uint_8 echoPin, uint_8 trigPin);
   Ultrassom(uint_8 echoPin, uint_8 trigPin, uint_8 onTimeMicrosseconds, uint_8 timeOut);
   double getDistancia();
}
