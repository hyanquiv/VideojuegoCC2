#include "tiro.h"

Tiro :: Tiro() : Entidades("vacuna.bmp")
{
   velocidad = 50;
   vivo = 0;
}

Tiro :: Tiro(int lin, int col) : Entidades("vacuna.bmp", lin, col)
{
   velocidad = 9;
   vivo = 0;
}

Tiro :: ~Tiro()
{
    destroy_bitmap(img);
}

void Tiro :: Mover()
{
   if (vivo)
      lin -= velocidad;

   if ( vivo && lin <= (-1 * img->h) )
      vivo = 0;
}

void Tiro :: Disparo(int lin, int col)
{
   if (!vivo)
   {
      vivo = 1;
      this->lin = lin;
      this->col = col;
   }
}

int Tiro :: EstaVivo()
{
   return 0;
}

void Tiro :: Imprimir(BITMAP* bmp)
{
   if (vivo)
      draw_sprite(bmp, img, col, lin);
}

