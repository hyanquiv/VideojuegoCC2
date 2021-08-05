#include "juego.h"

Juego::Juego()
{

   int i;
   t  = new Persona();

   for (i=0; i<N_NAVES; i++)
      n[i] = new Nave();

   c  = new fondo();
}

Juego::~Juego()
{

   int i;
   delete t;
   for (i=0; i<N_NAVES; i++)
      delete n[i];
}

void Juego::Jugar()
{

   int ii=1;
   int aciertos=0;

   BITMAP *fondo2 =load_bitmap("fondo2.bmp", NULL);

   BITMAP *doublebmp = create_bitmap(SCREEN_W, SCREEN_H);
/*
    n[ii]->setLin(1500);
    n[ii]->setCol(15);
    n[ii++]->setVelocidade(5);
    n[ii]->setLin(1250);
    n[ii]->setCol(10);
    n[ii++]->setVelocidade(5);

    n[ii]->setLin(1000);
    n[ii]->setCol(30);
    n[ii++]->setVelocidade(5);
    n[ii]->setLin(750);
    n[ii]->setCol(40);
    n[ii++]->setVelocidade(5);

    n[ii]->setLin(500);
    n[ii]->setCol(20);
    n[ii++]->setVelocidade(5);
*/


   while(!key[KEY_ESC])
   {

   c->crearfondo(fondo2);

      draw_sprite(doublebmp, fondo2, 0, 0);

      t->Imprimir(doublebmp);


      if ( key[KEY_LEFT] )
         t->MoverIzquierda(doublebmp);
      if ( key[KEY_RIGHT] )
         t->MoverDerecha(doublebmp);
      if ( key[KEY_UP] )
         t->MoverArriba(doublebmp);
      if ( key[KEY_DOWN] )
         t->MoverAbajo();

      for (ii=0; ii<N_NAVES; ii++)
      {
         n[ii]->Mover();
         n[ii]->Imprimir(doublebmp);
      }



      if ( key[KEY_A] )
      {
         t->Disparo();
      }


      t->MoverTiro();

     int cont = 2 ;

      if (  t->Colision_Nave(n[0]) == 1  || t->Colision_Nave(n[1]) == 1 || t->Colision_Nave(n[2]) == 1
         || t->Colision_Nave(n[3]) == 1  || t->Colision_Nave(n[4]) == 1 || t->Colision_Nave(n[5]) == 1)


        {

         cont--;
         if (cont == 0)
         {
            rest(125000);
            break;

         }
      }

      if (!n[0]->EstaVivo() && !n[1]->EstaVivo()&&
          !n[2]->EstaVivo() && !n[3]->EstaVivo()&&
          !n[4]->EstaVivo() && !n[5]->EstaVivo()&&
          !n[6]->EstaVivo() && !n[7]->EstaVivo()&&
          !n[8]->EstaVivo())
      {

         rest(40000);

         allegro_message("Fin del juego");
         break;
      }


         blit(doublebmp, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
   }

   //libera a memoria do fundo e da imagem de double bufferig
   destroy_bitmap(fondo2);

   destroy_bitmap(doublebmp);
}
