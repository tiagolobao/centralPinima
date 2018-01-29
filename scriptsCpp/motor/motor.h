#include<wiringPi.h>
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>

class Motor{
   private:
   int esquerdaHorario;
   int esquerdaAntiHorario;
   int direitaHorario;
   int direitaAntiHorario;

   public:
   Motor(int esquerdaHorario, int esquerdaAntiHorario, int direitaHorario, int direitaAntiHorario);
   void irParaFrente();
   void irParaTras();
   void virarDireita();
   void virarEsquerda();
   void parar();


   private:
   void WritePin(int GPIO, int value);
   int ReadPin(int GPIO);
};
