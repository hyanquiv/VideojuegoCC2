#ifndef TIRO_H
#define TIRO_H

#include "Entidades.h"

class Tiro : public Entidades{

   protected:

      int vivo;

   public:
      Tiro();
      Tiro(int lin, int col);
      ~Tiro();

      void Mover();
      void Disparo(int lin, int col);
      int  EstaVivo();
      void Morir()   {vivo = 0;};
      void Imprimir(BITMAP* bmp);
};


#endif // TIRO_H
