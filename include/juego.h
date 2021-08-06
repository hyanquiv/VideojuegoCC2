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

      //singleton
      static Juego* instance;

      static Juego& getInstance();

      Juego();

      ~Juego();

      Juego(Juego const&) = delete;

      Juego& operator=(Juego const&) = delete;

   public:

      void Jugar();

};
#endif // JUEGO_H
