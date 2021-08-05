#ifndef JUEGO_H
#define JUEGO_H

#include "fondo.h"
#include "persona.h"
#include "nave.h"
#include "controlgrafico.h"
#define N_NAVES 6


class Juego {

   private:

      fondo *c;

      Persona *t;

      Nave *n[N_NAVES];

      BITMAP *doublebmp;

   public:
      Juego();
      ~Juego();

      void Jugar();

};
#endif // JUEGO_H
