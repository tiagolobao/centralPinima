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
   long travelTime = 0;
   long startTime = 0;
   //Send trig pulse
   this->WritePin(trigPin,1);
   delayMicroseconds(onTimeMicrosseconds);
   this->WritePin(trigPin,0);
   //Wait for echo start
   while(this->ReadPin(echoPin) == 0);
   //Wait for echo end
   startTime = micros();
   while( (this->ReadPin(echoPin) == 1) && (travelTime < timeOut) ){
      travelTime = micros() - startTime;
   }
   double distance = (double)travelTime / 5880.0;
   distance /= 100;
   return distance;
}



/* COMANDOS DE GPIO */
void Ultrassom::WritePin(int GPIO, int value){
   char temp[25] = "gpio write ";
   char buff[5];

   //conversões de int para string e concatenações
   snprintf(buff, sizeof buff, "%d", GPIO);
   strcat(temp,buff);
   snprintf(buff, sizeof buff, "%d", value);
   strcat(temp," ");
   strcat(temp,buff);

   //roda o comando
   system( temp );
}

int Ultrassom::ReadPin(int GPIO){
   FILE *fp;
   char path[3];
   char temp[25] = "gpio read ";
   char buff[5];

   //conversões de int para string e concatenações
   snprintf(buff, sizeof buff, "%d", GPIO);
   strcat(temp,buff);

   //roda o comando
   fp = popen(temp, "r");
   fgets(path,sizeof(path),fp);
   if(path[0]=='0'){
      return 0;
   }
   else if(path[0]=='1'){
      return 1;
   }
}
