#include "motor.h"


void Motor::Motor(uint8_t esquerdaHorario, uint8_t esquerdaAntiHorario, uint8_t direitaHorario, uint8_t direitaAntiHorario){
   this->esquerdaHorario = esquerdaHorario;
   this->esquerdaAntiHorario = esquerdaAntiHorario;
   this->direitaHorario = direitaHorario;
   this->direitaAntiHorario = direitaAntiHorario;
}

void Motor::irParaFrente(){
   digitalWrite(direitaAntiHorario,HIGH);
   digitalWrite(esquerdaHorario,HIGH);

   digitalWrite(direitaHorario,LOW);
   digitalWrite(esquerdaAntiHorario,LOW);
}

void Motor::irParaTras(){
   digitalWrite(direitaAntiHorario,LOW);
   digitalWrite(esquerdaHorario,LOW);

   digitalWrite(direitaHorario,HIGH);
   digitalWrite(esquerdaAntiHorario,HIGH);
}

void Motor::virarDireita(){
   digitalWrite(direitaAntiHorario,LOW);
   digitalWrite(esquerdaAntiHorario,LOW);

   digitalWrite(esquerdaHorario,HIGH);
   digitalWrite(direitaHorario,HIGH);
}

void Motor::virarEsquerda(){
   digitalWrite(direitaAntiHorario,HIGH);
   digitalWrite(esquerdaAntiHorario,HIGH);

   digitalWrite(esquerdaHorario,LOW);
   digitalWrite(direitaHorario,LOW);
}

void Motor::parar(){
   digitalWrite(direitaAntiHorario,LOW);
   digitalWrite(esquerdaHorario,LOW);

   digitalWrite(direitaHorario,LOW);
   digitalWrite(esquerdaAntiHorario,LOW);
}
