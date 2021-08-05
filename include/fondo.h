#ifndef FONDO_H
#define FONDO_H


#include "Entidades.h"


class fondo : public Entidades
{
    protected:
        int velocidad;
        int pantallaDElinea;

    public:
        fondo();
        fondo(int velocidad);
        ~fondo();
        void crearfondo(BITMAP* bmp);

};

#endif // FONDO_H
