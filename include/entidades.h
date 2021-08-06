#ifndef ENTIDADES_H
#define ENTIDADES_H
#include <allegro.h>


class Entidades {

   protected:

      int lin, col;
      BITMAP *img;
      BITMAP *img2;
      BITMAP *img3;
      BITMAP *explotar;
      int velocidad;

   public:

      Entidades();
      Entidades(char *nombreImg);
      Entidades(char *nombreImg,char *nombreImg2,char *nombreImg3,char *nombreImg4);
      Entidades(char *nombreImg, int lin, int col);

      ~Entidades();

      inline int  getLin()        {return lin;};
      inline void setLin(int lin) {this->lin = lin;};
      inline int  getCol()        {return col;};
      inline void setCol(int col) {this->col = col;};
      inline void setVelocidad(int velocidad) {this->velocidad = velocidad;};
};

#endif // ENTIDADES_H
