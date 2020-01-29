#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_image.h>
#include <stdatomic.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Juego.h"

enum KEYS{UP,DOWN,LEFT,RIGHT};
const int width = 600;
const int height = 764;


int main(int argc, char** argv) {
    int pp=-3;

    setbuf(stdout,NULL);
    char username[50];
    printf("Ingrese su Nombre de Usuario:  ");
    scanf("%s",&user.username);
    users(user.username);

    bool done = false;
    bool redraw=true;
    int pos_x =width / 4;
    int pos_y = height / 4;

    bool keys[4]={false,false,false,false};

    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer=NULL;
    ALLEGRO_BITMAP *image;



    if(!al_init())
        return -1;

    display = al_create_display(width, height);
    display=al_create_display(600,764);
    if(!display)
        return -1;

    al_init_primitives_addon();
    al_install_keyboard();

    event_queue =al_create_event_queue();

    al_register_event_source(event_queue, al_get_keyboard_event_source());

    while(!done){

        ALLEGRO_EVENT ev;
        ALLEGRO_DISPLAY *display = NULL;
        al_wait_for_event(event_queue, &ev);
        if(ev.type == ALLEGRO_EVENT_KEY_DOWN){


            switch(ev.keyboard.keycode){
                case ALLEGRO_KEY_UP:
                    pos_y-=70;
                    if(ALLEGRO_KEY_UP < pos_y)
                        break;
                case ALLEGRO_KEY_DOWN:
                    pos_y+=70;
                    if(pos_y>260){
                        pos_y=259;
                    }

                    if(ALLEGRO_KEY_DOWN < pos_x)
                        break;
                case ALLEGRO_KEY_ENTER:
                    if(pos_y>=259){
                        return 0;   //Salir
                    }
                    else if(pos_y<=120){
                        ball.ball_x=2;
                        ball.ball_y=2;
                        ball.tempX=(width/2);
                        ball.tempY=648;
                        ball.f=-1;


                        int x=ball.ball_x,y=ball.ball_y;
                        bool done = false;
                        bool redraw=true;
                        //prototypes
                        float gameTime=0;
                        int frames=0;
                        int gameFPS;
//object variables

                        int pos_x = (width / 2)-60;  //barra
                        int pos_y =  658;  //barra
                        int FPS=60;
                        ball.score=0;
                        ball.lives=1;


                        block1.gross=3;
                        //linea 1
                        block1.blockx1=50;
                        block1.blocky1=180;
                        block2.blockx1=145;
                        block2.blocky1=180;
                        block3.blockx1=245;
                        block3.blocky1=180;
                        block4.blockx1=345;
                        block4.blocky1=180;
                        block5.blockx1=445;
                        block5.blocky1=180;
                        //linea2
                        block6.blockx1=50;
                        block6.blocky1=80;
                        block7.blockx1=145;
                        block7.blocky1=80;
                        block8.blockx1=245;
                        block8.blocky1=80;
                        block9.blockx1=345;
                        block9.blocky1=80;
                        block10.blockx1=445;
                        block10.blocky1=80;

                        bar.barx=pos_x;
                        bar.bary=pos_y;


                        bool keys[4]={false,false,false,false};

                        ALLEGRO_DISPLAY *display = NULL;
                        ALLEGRO_EVENT_QUEUE *event_queue = NULL;
                        ALLEGRO_TIMER *timer=NULL;
                        ALLEGRO_BITMAP *image;

                        if (!al_init()) { //initialize allegro
                            return -1;
                        }

                        display = al_create_display(width, height); //create our display object
                        if (!display) {
                            return -1;    //test display object
                        }
                        //l_clear_to_color(al_map_rgb(255, 0, 255));
                        al_init_primitives_addon();
                        al_install_keyboard();
                        al_init_font_addon();
                        al_init_ttf_addon();
                        al_init_image_addon();

                        event_queue = al_create_event_queue();
                        timer=al_create_timer(1.0/FPS);


                        al_register_event_source(event_queue,al_get_timer_event_source(timer));
                        al_register_event_source(event_queue, al_get_keyboard_event_source());
                        al_register_event_source(event_queue,al_get_display_event_source(display));

                        al_start_timer(timer);

                        ALLEGRO_FONT *font18= al_load_font("3X5_____.TTF",25,0);

                        while(!done){
                            MoveBALL();
                            if(ball.lives !=0){
                            al_draw_textf(font18,al_map_rgb(255,255,255),width/2,height/2,ALLEGRO_ALIGN_CENTRE,"Score: %i",ball.score);
                            al_draw_textf(font18,al_map_rgb(255,255,255),600/2,450,ALLEGRO_ALIGN_CENTRE,"Lives:  %d",ball.lives);
                            }else if(ball.lives<=0){
                                ALLEGRO_FONT *font19= al_load_font("3X5_____.TTF",30,0);
                                al_draw_textf(font19,al_map_rgb(255,255,255),600/2,764/2+50,ALLEGRO_ALIGN_CENTRE,"You LOOSE");
                                al_draw_textf(font18,al_map_rgb(255,255,255),600/2,764/2,ALLEGRO_ALIGN_CENTRE,"Your Score: %d",ball.score);
                                userScore(user.username,ball.score);
                                TopScores();
                                break;
                                }else if(ball.lives>0){
                                ALLEGRO_FONT *font19= al_load_font("3X5_____.TTF",30,0);
                                al_draw_textf(font19,al_map_rgb(255,255,255),600/2,764/2+50,ALLEGRO_ALIGN_CENTRE,"You Win, press ESC");
                                al_draw_textf(font18,al_map_rgb(255,255,255),600/2,764/2,ALLEGRO_ALIGN_CENTRE,"Your Score: %d",ball.score);
                                userScore(user.username,ball.score);
                                TopScores();
                                break;
                                }
                                ALLEGRO_EVENT ev;
                                al_wait_for_event(event_queue, &ev);
                            if(ev.type== ALLEGRO_EVENT_KEY_DOWN){

                                switch(ev.keyboard.keycode){
                                    case ALLEGRO_KEY_LEFT:

                                        keys[LEFT]=true;

                                        break;
                                    case ALLEGRO_KEY_RIGHT:
                                        keys[RIGHT]=true;
                                        break;
                                }

                            }
                            else if(ev.type==ALLEGRO_EVENT_KEY_UP){
                                switch(ev.keyboard.keycode){
                                    case ALLEGRO_KEY_LEFT:
                                        keys[LEFT]=false;
                                        break;
                                    case ALLEGRO_KEY_RIGHT:
                                        keys[RIGHT]=false;
                                        break;
                                    case ALLEGRO_KEY_ESCAPE:
                                        userScore(user.username,ball.score);
                                        done=true;
                                        break;
                                }
                            }
                            if(ev.type==ALLEGRO_EVENT_DISPLAY_CLOSE){

                                done=true;
                            }
                            else if(ev.type == ALLEGRO_EVENT_TIMER){
                                pos_y -=keys[UP]*10;
                                pos_y +=keys[DOWN]*10;
                                if(pos_x<4){
                                    pos_x=5;
                                }else if(pos_x>478){
                                    pos_x=477;
                                }
                                pos_x -=keys[LEFT]*10;
                                pos_x += keys[RIGHT]*10;
                                redraw=true;
                            }
                            bar.barx=pos_x;
                            bar.bary=pos_y;
                            if(redraw && al_event_queue_is_empty(event_queue)){
                                redraw=false;


                                //al_draw_rectangle(block1.blockx1,block1.blocky1,block1.blockx2,block1.blocky2,al_map_rgb(255,0,255),pp);
                                if(block1.blockx1!=0){
                                    al_draw_filled_rectangle(block1.blockx1,block1.blocky1,block1.blockx1+100,block1.blocky1+30,al_map_rgb(rand(),rand(),rand()));
                                }
                                if(block2.blockx1!=0){
                                    al_draw_filled_rectangle(block2.blockx1,block2.blocky1,block2.blockx1+100,block2.blocky1+30,al_map_rgb(rand(),rand(),rand()));
                                }
                                if(block3.blockx1!=0){
                                    al_draw_filled_rectangle(block3.blockx1,block3.blocky1,block3.blockx1+100,block3.blocky1+30,al_map_rgb(rand(),rand(),rand()));
                                }
                                if(block4.blockx1!=0){
                                    al_draw_filled_rectangle(block4.blockx1,block4.blocky1,block4.blockx1+100,block4.blocky1+30,al_map_rgb(rand(),rand(),rand()));
                                }if(block5.blockx1!=0){
                                    al_draw_filled_rectangle(block5.blockx1,block5.blocky1,block5.blockx1+100,block5.blocky1+30,al_map_rgb(rand(),rand(),rand()));
                                }
                                if(block6.blockx1!=0){
                                    al_draw_filled_rectangle(block6.blockx1,block6.blocky1,block6.blockx1+100,block6.blocky1+30,al_map_rgb(rand(),rand(),rand()));
                                }
                                if(block7.blockx1!=0){
                                    al_draw_filled_rectangle(block7.blockx1,block7.blocky1,block7.blockx1+100,block7.blocky1+30,al_map_rgb(rand(),rand(),rand()));
                                }
                                if(block8.blockx1!=0){
                                    al_draw_filled_rectangle(block8.blockx1,block8.blocky1,block8.blockx1+100,block8.blocky1+30,al_map_rgb(rand(),rand(),rand()));
                                }
                                if(block9.blockx1!=0){
                                    al_draw_filled_rectangle(block9.blockx1,block9.blocky1,block9.blockx1+100,block9.blocky1+30,al_map_rgb(rand(),rand(),rand()));
                                }if(block10.blockx1!=0){
                                    al_draw_filled_rectangle(block10.blockx1,block10.blocky1,block10.blockx1+100,block10.blocky1+30,al_map_rgb(rand(),rand(),rand()));
                                }

                                al_draw_filled_rectangle(pos_x,pos_y,pos_x+120,pos_y+15,al_map_rgb(255,255,255));
                                al_draw_filled_circle(ball.tempX,ball.tempY,8,al_map_rgb(164, 221, 232));
                                al_flip_display();
                                al_clear_to_color(al_map_rgb(0,0,0));
                            }

                        }


                        al_draw_line(100, 100, width - 100, 100,al_map_rgb(255,150,0),1);


                        al_destroy_bitmap(image);
                        al_destroy_event_queue(event_queue);
                        al_destroy_display(display);	//destroy our display object
                        al_destroy_font(font18);

                        //Juego
                    }
                    else{

                       FILE *archivo;
                        char caracter[150];
                        archivo = fopen("UserScores.txt","r");

                        if (archivo == NULL)
                        {
                            printf("\nError de apertura del archivo. \n\n");
                        }
                        else
                        {
                            printf("\nLos top Scores son: \n\n");
                            while(fgets(caracter,150,archivo))
                            {

                                printf("%s", caracter);
                            }
                        }
                        fclose(archivo);

                    }
                    break;
            }

        }


        al_init_font_addon();
        al_init_ttf_addon();

        ALLEGRO_FONT *font24=al_load_font("crackman.ttf", 35, 0);

        al_draw_filled_rectangle(pos_x,pos_y,pos_x+60,pos_y+16, al_map_rgb(247, 151, 27));
        al_flip_display();
        al_clear_to_color(al_map_rgb(0,0,0));
        al_draw_text(font24, al_map_rgb(255,255,255), 269,110,0, "JUGAR");
        al_draw_text(font24, al_map_rgb(255,255,255), 269,180,0, "TOP SCORES");
        al_draw_text(font24, al_map_rgb(255,255,255), 269,250,0, "SALIR");

    }
    al_destroy_display(display);
    return 0;
}

