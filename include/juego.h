#ifndef JUEGO_H
#define JUEGO_H
#include "fondo.h"
#include "persona.h"
#include "nave.h"
#include "controlgrafico.h"
#include "linkedlist.h"
#define N_NAVES 6


class Juego {

   private:

      fondo *c;

      Persona *t;

      //implementacion iterator

      LinkedList<Nave> *n;

      BITMAP *doublebmp;

      //singleton
      static Juego* instance;

      Juego();

      ~Juego();

      Juego(Juego const&) = delete;

      Juego& operator=(Juego const&) = delete;

   public:

      static Juego& getInstance();

      void Jugar();

};
#endif // JUEGO_H
