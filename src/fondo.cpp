#include "fondo.h"
#include <allegro.h>

fondo::fondo() : Entidades("fondo2.bmp")
{
    velocidad = 2;
    pantallaDElinea = img->h - SCREEN_H;
}

fondo::fondo(int velocidad)
{
    this->velocidad=velocidad;
    pantallaDElinea = img->h - SCREEN_H;
}

void fondo::crearfondo(BITMAP* bmp)
{



   pantallaDElinea -= velocidad;

   if (pantallaDElinea <= 0)
   {
      blit(img, bmp, 0, img->h + pantallaDElinea, 0, 0, bmp->w, -pantallaDElinea);
     blit(img, bmp, 0, 0, 0, -pantallaDElinea, bmp->w, SCREEN_H + pantallaDElinea);

     if ( -pantallaDElinea >= SCREEN_H )
         pantallaDElinea = img->h - SCREEN_H;

   } else {

      blit(img, bmp, 0, pantallaDElinea, 0, 0, bmp->w, bmp->h);
   }
}
