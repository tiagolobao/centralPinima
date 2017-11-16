#include "motor.h"


Motor::Motor(uint_8 esquerdaHorario, uint_8 esquerdaAntiHorario, uint_8 direitaHorario, uint_8 direitaAntiHorario){
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
