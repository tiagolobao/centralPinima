#include</home/pi/centralpinima/scriptsCpp/motor/motor.h>
#include</home/pi/centralpinima/scriptsCpp/ultrassom/ultrassom.h>
#include<wiringPi.h>
#include<iostream>

using namespace std;

Ultrassom sensorEsquerda(4,11);
Ultrassom sensorDireita(3,9);
Ultrassom sensorFrente(2,10);
Motor motor(5,6,7,8);

int main( int argc, char *argv[] ){

   char comandos[][20] = {
      "frente",
      "tras",
      "esquerda",
      "direita",
      "parar",
      "aleatorio"
   };

   FILE *fp;
   char path[3];

   //printf("	Inicializando função main. \n");
   wiringPiSetup () ;
   wiringPiSetupGpio () ;

   //printf("	Setup inicializado. \n");
   system("gpio mode 0 out");
   //printf("	pinMode inicializado. \n");
   //LER
   fp = popen("gpio read 0","r");
   fgets(path,sizeof(path),fp);
   if (path[0]=='0') {printf("PINO 0 TA EM 0 NESSA DESGRAÇA \n");}
   if (path[0]=='1') {printf("PINO 0 TA EM 1 NESSA DESGRAÇA \n");}


	//Constantes:
	int tempoON = 5000;  //milissegundos
	double distanciaMAX = 5; //centímetros
	unsigned int inicio;

	//comando ir para a frente:
	//Vai pra frente até dar o tempoON ou bater em algo
	motor.irParaFrente;
	inicio = millis();
	while(millis()-inicio<tempoON){
	 if (sensorFrente.getDistancia() < distanciaMAX){
	  motor.parar();
	  exit
	 }
	}


	//comando ir para direita:
	//Vira se não tiver objetos na direita
	if (sensorDireita.getDistancia() > distanciaMAX) then {
	 motor.virarDireita;
	 pause(2000);
	//Vai pra frente até dar o tempoON ou bater em algo
        motor.irParaFrente;
	inicio = millis();
	while(milis()-inicio<tempoON){
	 if (sensorFrente.getDistancia() < distanciaMAX) {
	  motor.parar();
	  exit
	 }
	}
	}


	//comando ir para esquerda:
	//Vira se não tiver objetos na esquerda
	if (sensorEsquerda.getDistancia() > distanciaMAX){
	 motor.virarEsquerda;
	 pause(2000);
	//Vai pra frente até dar o tempoON ou bater em alg
        motor.irParaFrente;
	inicio = millis();
	while(millis()-inicio<tempoON){
	 if (sensorFrente.getDistancia() < distanciaMAX){
	  motor.parar();
	  exit
	 }
	}
	}



//	for (;;){
//	printf("OFF");
//	system("gpio write 0 0");
//	delay (1000);
//
//	printf("ON");
//	system("gpio write 0 1");
//	delay (1000);
//	}
	return 0 ;




   /* Exemplo de acesso aos argumentos */
   /*
   for(int i=0; i<argc; i++){
      cout << argv[i];
   }
   */


//double buffer = sensorFrente.getDistancia();
//printf(" FRENTE: %f ", buffer);

//double buffer = sensorDireita.getDistancia();
//printf(" DIREITA: %f ", buffer);

//double buffer = sensorEsquerda.getDistancia();
//printf(" ESQUERDA: %f ", buffer);


   //CONSTANTES:
//   double tempoON = 5000;     //milissegundos
//   double distanciaMAX = 5.0; //centímetros

   //COMANDO IR PRA FRENTE:
   //Vai pra frente até dar o tempoON ou bater em algo
//   motor.irParaFrente();
//   double inicio = millis();
//   while(millis()-inicio<tempoON){
//    if (sensorFrente.getDistancia() < distanciaMAX) {
//     motor.parar();
//     exit;
//    }
//   }



}
