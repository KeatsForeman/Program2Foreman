// Program2Foreman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <utility>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "graphics.h"
#include "logic.h"

int width = 950;
int height = 600;

int main(int argc, char** argv) {

    graphics graphic;
    logic logic;
    
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



    bool Done = false;

    al_clear_to_color(al_map_rgb(0, 0, 0));

    while (!Done) {
        graphic.Draw_grid();
        graphic.Draw_status();
        al_flip_display();

        ALLEGRO_EVENT ev;
        al_wait_for_event(EventQueue, &ev);

        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { Done = true; }

        else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            if (ev.mouse.button & 1) {
                int x = ev.mouse.x;
                int y = ev.mouse.y;
                std::vector<std::pair<int, int>> coords = logic.Get_Mouse_Input(x, y);
                int ansShape = logic.get_shape(coords[0].first, coords[0].second);
                int ansx = coords[1].first;
                int ansy = coords[1].second;
                std::cout << ansx << " " << ansy << "\n";
                graphic.Draw_shape(ansShape, ansx, ansy);

            }
        }

    }
}

