#include<wiringPi.h>
#include<iostream>

class Motor{
   private:
   int esquerdaHorario;
   int esquerdaAntiHorario;
   int direitaHorario;
   int direitaAntiHorario;

   public:
   void Motor(int esquerdaHorario, int esquerdaAntiHorario, int direitaHorario, int direitaAntiHorario);
   void irParaFrente();
   void irParaTras();
   void virarDireita();
   void virarEsquerda();
   void parar();
};
