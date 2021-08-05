#include "nave.h"
#include <allegro.h>


Nave :: Nave() : Entidades("covid.bmp",5,5)
{
   velocidad = 3;
   direccion = 1;
   vivo      = 1;
}

Nave :: ~Nave()
{
   destroy_bitmap(img);
}

void Nave :: Mover()
{

   if (vivo)
   {

     if (direccion == 1)
     {

         col += velocidad;
         lin += velocidad;
     }
     else
      {
         lin += velocidad;
         col += velocidad;
       }
       if ( direccion == 0 && col <= 0 )
          direccion = 1;
     else
       if ( direccion == 1 && col >= (SCREEN_W - img->w) )
         direccion = 0;

     if (direccion == 1)
       lin += velocidad  ;

     if ( lin >= (SCREEN_H - img->h) )
      lin = 1;
   }
}

void Nave :: Imprimir(BITMAP* bmp)
{
   if (vivo)
   {

      draw_sprite(bmp, img, col, lin);
      draw_sprite(bmp, img, col, lin);
      draw_sprite(bmp, img, col, lin);
      draw_sprite(bmp, img, col, lin);
      draw_sprite(bmp, img, col, lin);
      draw_sprite(bmp, img, col, lin);
   }
}

void Nave :: Morir()
{

   vivo = 0;
}

void Nave :: Colision(Tiro *t)
{
   if ( vivo && t->EstaVivo() )
   {

      if ( t->getLin() < img->h && t->getCol() >= col && t->getCol() <= (col + img->w) )
      {

         vivo = 0;

         t->Morir();
      }
   }
}

