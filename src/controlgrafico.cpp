#include "controlgrafico.h"
#include "allegro.h"


int ControlGrafico::IniciaAllegro()
{

    allegro_init();

	install_keyboard();

    set_color_depth(16);

   if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0) != 0)
   {
      set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);

      allegro_message("No es posible seleccionar el modo grafico.\n%s\n", allegro_error);
      return 0;
   }

   return 1;
}


void ControlGrafico::FinalizaAllegro()
{
   allegro_exit();
}
