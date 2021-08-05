#include "entidades.h"

Entidades::Entidades()
{

   img = NULL;
   lin = col = 0;
   velocidad = 1;
}

Entidades::Entidades(char *nombreImg)
{
   img = load_bitmap(nombreImg, NULL);
   lin = col = 0;
   velocidad = 1;
}

Entidades::Entidades(char *nombreImg,char *nombreImg2,char *nombreImg3,char *nombreImg4)
{


   img = load_bitmap(nombreImg, NULL);
   img2= load_bitmap(nombreImg2, NULL);
   img3= load_bitmap(nombreImg3, NULL);
   explotar= load_bitmap(nombreImg4, NULL);

   lin = col = 0;
   velocidad = 1;
}

Entidades::Entidades(char *nombreImg, int lin, int col)
{

   img = load_bitmap(nombreImg, NULL);
   this->lin = lin;
   this->col = col;
   velocidad = 10;//1
}


Entidades::~Entidades()
{
   destroy_bitmap(img);
   destroy_bitmap(img2);
   destroy_bitmap(img3);
   destroy_bitmap(explotar);
}
