#include "ultrassom.h"


Ultrassom::Ultrassom(int echoPin, int trigPin){
   this->echoPin = echoPin;
   this->trigPin = trigPin;
   this->timeOut = 2400;
   this->onTimeMicrosseconds = 20;
}

Ultrassom::Ultrassom(int echoPin, int trigPin, int onTimeMicrosseconds, int timeOut){
   this->echoPin = echoPin;
   this->trigPin = trigPin;
   this->timeOut = timeOut;
   this->onTimeMicrosseconds = onTimeMicrosseconds;
}


double Ultrassom::getDistancia(){
​ ​ ​ long​ travelTime​ ​= ​0;
​ ​ ​ long​ startTime​ ​=​ 0;
   //Send​ ​trig​ ​pulse
   digitalWrite(trigPin,​ HIGH);
   delayMicroseconds(onTimeMicrosseconds);
   digitalWrite(trigPin,​​ LOW);
   //Wait​ for​​ echo​ start
   while(digitalRead(echoPin)​ ==​ 0);
   //Wait​ for​ ​echo​ end
   startTime​ = micros();
   while(​ ​ (digitalRead(echoPin)​ ​==​ ​1)​ ​ &&​ ​ (travelTime​ ​< ​timeOut)​ ​ ){
      travelTime​​ =​ micros()​ -​ startTime;
   }
   double​ ​distance​​ =​ (double)travelTime​​ /​ 5880.0;
   distance /= 100;
   return​ distance;
}
