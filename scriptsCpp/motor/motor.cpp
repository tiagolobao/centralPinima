#include "motor.h"


Motor::Motor(int esquerdaHorario, int esquerdaAntiHorario, int direitaHorario, int direitaAntiHorario){
   this->esquerdaHorario = esquerdaHorario;
   this->esquerdaAntiHorario = esquerdaAntiHorario;
   this->direitaHorario = direitaHorario;
   this->direitaAntiHorario = direitaAntiHorario;
}

void Motor::irParaFrente(){
   this->WritePin(direitaAntiHorario,1);
   this->WritePin(esquerdaHorario,1);

   this->WritePin(direitaHorario,0);
   this->WritePin(esquerdaAntiHorario,0);
}

void Motor::irParaTras(){
   this->WritePin(direitaAntiHorario,0);
   this->WritePin(esquerdaHorario,0);

   this->WritePin(direitaHorario,1);
   this->WritePin(esquerdaAntiHorario,1);
}

void Motor::virarDireita(){
   this->WritePin(direitaAntiHorario,0);
   this->WritePin(esquerdaAntiHorario,0);

   this->WritePin(esquerdaHorario,1);
   this->WritePin(direitaHorario,1);
}

void Motor::virarEsquerda(){
   this->WritePin(direitaAntiHorario,1);
   this->WritePin(esquerdaAntiHorario,1);

   this->WritePin(esquerdaHorario,0);
   this->WritePin(direitaHorario,0);
}

void Motor::parar(){
   this->WritePin(direitaAntiHorario,0);
   this->WritePin(esquerdaHorario,0);

   this->WritePin(direitaHorario,0);
   this->WritePin(esquerdaAntiHorario,0);
}




/* COMANDOS DE GPIO */
void Motor::WritePin(int GPIO, int value){
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

int Motor::ReadPin(int GPIO){
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
