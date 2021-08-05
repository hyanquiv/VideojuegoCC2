#include "allegro.h"
#include "juego.h"

int main()
{

  ControlGrafico *cg = new ControlGrafico();


   if ( cg->IniciaAllegro() != 1 )
      return 1;

   Juego *j = new Juego();

   j->Jugar();

   delete j;

   cg->FinalizaAllegro();
   delete cg;

   return 0;

}
END_OF_MAIN()

