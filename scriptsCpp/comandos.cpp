#include "motor/motor.h"
#include "ultrassom/ultrassom.h"
#include <iostream>

using namespace std;

Ultrassom sensorFrente(2,9);
Ultrassom sensorEsquerda(3,10);
Ultrassom sensorDireita(4,11);
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

   /* Exemplo de acesso aos argumentos */
   /*
   for(int i=0; i<argc; i++){
      cout << argv[i];
   }
   */

}
