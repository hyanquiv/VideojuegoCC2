#include "persona.h"
#include <allegro.h>

Persona::Persona() : Entidades("Personita.bmp","Personita_izq.bmp","Personita_der.bmp","Muerto.bmp")
{
   lin = SCREEN_H - img->h - 10;
   col = ( SCREEN_W / 2 ) - ( img->w / 2 );
   velocidad = 0.001;
   ti = new Tiro();
   puntos=0;
}

Persona::~Persona()
{
   delete ti;
   destroy_bitmap(img);
   destroy_bitmap(img2);
   destroy_bitmap(img3);
}

void Persona::MoverIzquierda(BITMAP *db)
{

   int r =  getr(getpixel(db, col-velocidad, lin));
   int g =  getg(getpixel(db, col-velocidad, lin));
   int b =  getb(getpixel(db, col-velocidad, lin));

   col-=velocidad;
   if ( col <=0 ){
        col = 0 ;
   }
}

void Persona::MoverDerecha(BITMAP *db)
{

   int r =  getr(getpixel(db, col+velocidad, lin));
   int g =  getg(getpixel(db, col+velocidad, lin));
   int b =  getb(getpixel(db, col+velocidad, lin));

   col+=velocidad;
   if ( col >= (SCREEN_W - img->w + 4) )
      col = SCREEN_W - img->w + 4;
}

void Persona::MoverArriba(BITMAP *db)
	{

   int r =  getr(getpixel(db, col-velocidad, lin));
   int g =  getg(getpixel(db, col-velocidad, lin));
   int b =  getb(getpixel(db, col-velocidad, lin));

   lin-=velocidad;

   if ( lin <= 50 )
      lin = 50;
}

void Persona:: MoverAbajo()
{
   lin+=velocidad;

   if ( lin >= (SCREEN_H - img->h) )
      lin = SCREEN_H - img->h;
}

void Persona::MoverTiro()
{

   ti->Mover();
}

void Persona::Disparo()
{


   ti->Disparo(lin-1, col+20);
}

void Persona::Imprimir(BITMAP* doublebmp)
{
   draw_sprite(doublebmp, img,col,lin);
   ti->Imprimir(doublebmp);
}


int Persona::Colision_Nave(Nave *nave)
{

   if ( nave->IsAlive() )
   {

      int liNave = nave->getLin();
      int lfNave = nave->getLin() + nave->getAltura();
      int liPersona = lin;
      int lfPersona = lin + img->h;

      int ciNave = nave-> getCol();
      int cfNave = nave-> getCol() + nave->getLargo();
      int ciPersona= col;
      int cfPersona= col + img->w;
      int batidas=1;

      if ( ((liNave < lfPersona && liNave > liPersona) || ( lfNave > liPersona && lfNave < lfPersona)) &&
          ((ciNave < cfPersona && ciNave > ciPersona) || (cfNave  > ciPersona && cfNave < cfPersona)) )
      {

         nave->Morir();
         return 1;
      }
   }
   return 0;
}
