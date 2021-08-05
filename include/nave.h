#ifndef NAVE_H
#define NAVE_H
#include <allegro.h>
#include "Entidades.h"
#include "Tiro.h"

class Nave : public Entidades{

   private:

      int direccion;
      int vivo;

   public:

      Nave();
      ~Nave();

      inline int EstaVivo()   {return vivo;};;
      void Mover();
      void Imprimir(BITMAP* bmp);
      void Morir();
      void Colision(Tiro *t);
      int getAltura() {return img->h;};
      int getLargo() {return img->w;};
      int IsAlive()    {return vivo;};
};


#endif // NAVE_H
