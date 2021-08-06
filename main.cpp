#include <iostream>
#include "allegro.h"
#include "juego.h"

int main()
{
    allegro_init();
   set_color_depth(32);
   set_gfx_mode(GFX_AUTODETECT_WINDOWED, 500, 700, 0, 0);

    install_mouse();
    if(install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL)!=0){
        allegro_message("Error:inicializando istema de sonido\n",allegro_error);
        return 1;
    }
    set_volume(100,100);

    BITMAP *buffer = create_bitmap (500,700);
    BITMAP *fondo0=load_bitmap("fondo0.bmp",NULL);
    BITMAP *fondo01=load_bitmap("fondo01.bmp",NULL);
    BITMAP *fondo02=load_bitmap("fondo02.bmp",NULL);
    BITMAP *cursor=load_bitmap("cursor.bmp",NULL);
    BITMAP *MORIDO=load_bitmap("morido.bmp",NULL);
    SAMPLE *sonido1=load_wav("musica.wav");

    bool salida = false;

    while(!salida){

            play_sample(sonido1,200,150,1000,1);
        if(mouse_x > 170 && mouse_x < 450 &&
           mouse_y > 430 && mouse_y < 460)
           {

        blit(fondo01,buffer,0,0,0,0,500,700);

         if(mouse_b & 1){
            salida = true;
            ControlGrafico *cg = new ControlGrafico();


   if ( cg->IniciaAllegro() != 1 )
      return 1;

   Juego *j = new Juego();

   j->Jugar();

   delete j;
   blit(MORIDO,buffer,0,0,0,0,640,480);

   cg->FinalizaAllegro();
   delete cg;


         }

    } else if(mouse_x > 170 && mouse_x < 315 &&
           mouse_y > 540 && mouse_y < 565)
           {

               blit(fondo02,buffer,0,0,0,0,500,700);
               if(mouse_b & 1){
                salida = true;
                break;
               }
           }else  blit(fondo0,buffer,0,0,0,0,500,700);

           masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,13,22);
           blit(buffer,screen,0,0,0,0,500,700);

    }
    destroy_bitmap(buffer);


   return 0;

}
END_OF_MAIN()

