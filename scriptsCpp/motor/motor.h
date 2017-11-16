#include​ <wiringPi.h>
#include <iostream.h>

class Motor{
   private:
   uint_8 esquerdaHorario;
   uint_8 esquerdaAntiHorario;
   uint_8 direitaHorario;
   uint_8 direitaAntiHorario;

   public:
   Motor(uint_8 esquerdaHorario, uint_8 esquerdaAntiHorario, uint_8 direitaHorario, uint_8 direitaAntiHorario);
   void irParaFrente();
   void irParaTras();
   void virarDireita();
   void virarEsquerda();
   void parar();
}
