// Program2Foreman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "graphics.h"

int width = 950;
int height = 600;

int main(int argc, char** argv) {

    graphics graphic;
    
    //initializations
    if (!al_init()) {
        fprintf(stderr, "failed to initialize allegro\n");
    }
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    if (!al_install_mouse()) {
        fprintf(stderr, "failed to connect keyboard");
    }

    //allegro variables
    ALLEGRO_EVENT_QUEUE* EventQueue = NULL;
    ALLEGRO_EVENT Event;
    ALLEGRO_MOUSE_STATE state;
    ALLEGRO_DISPLAY* screen;
    ALLEGRO_FONT* font = al_load_font("Cat.ttf", 50, 0);
    
    EventQueue = al_create_event_queue();
    screen = al_create_display(width, height);

    if (!screen) {
        fprintf(stderr, "failed to load screen\n");
    }
    if (EventQueue == NULL) {
        fprintf(stderr, "failed to create event queue");
    }
    if (font == NULL) {
        fprintf(stderr, "failed to load font");
    }


    //event registrations
    al_register_event_source(EventQueue, al_get_mouse_event_source());
    al_register_event_source(EventQueue, al_get_display_event_source(screen));



    bool ExitLoop = false;

    al_clear_to_color(al_map_rgb(0, 0, 0));

    while (true) {
        graphic.Draw_grid();
        al_flip_display();
    }



}

