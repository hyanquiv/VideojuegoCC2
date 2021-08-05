#ifndef PERSONA_H
#define PERSONA_H
#include "entidades.h"
#include "Tiro.h"
#include "nave.h"
#include "fondo.h"

class Persona : public Entidades{

   private:
      Tiro *ti;

   public:
      int puntos;
      Persona();
      ~Persona();

      inline Tiro * getTiro()   {return ti;};

      void MoverIzquierda(BITMAP *db);
      void MoverDerecha(BITMAP *db);
      void MoverArriba(BITMAP *db);
      void MoverAbajo();
      void Disparo();
      void MoverTiro();
      void Imprimir(BITMAP* bmp);
      int Colision_Nave(Nave *nave);
      int Colision_Persona(Persona *persona);
};


#endif // PERSONA_H
