// Program2Foreman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Keats Foreman

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
    int frames = 0;

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
    ALLEGRO_FONT* font = al_load_font("Cat.ttf", 30, 0);
    ALLEGRO_TIMER* timer = NULL;
    
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


    timer = al_create_timer(1.0);
    //event registrations
    al_register_event_source(EventQueue, al_get_mouse_event_source());
    al_register_event_source(EventQueue, al_get_display_event_source(screen));
    al_register_event_source(EventQueue, al_get_timer_event_source(timer));

    bool gaming = true;

    while (gaming) {
        ALLEGRO_EVENT ev;
        al_clear_to_color(al_map_rgb(0, 0, 0));

        logic logic;
        graphics graphic(&logic);

        bool Done = false;
        int guesses = 0;
        bool make_guess = false;
        int firstGuess;
        int secondGuess;
        int firstx;
        int firsty;
        int secondx;
        int secondy;
        int score = 0;
        int remaining = 12;
        int time = 0;
        frames = 0;

        al_start_timer(timer);

        while (!Done) {

            std::string pairs = std::to_string(score);
            std::string pairsLeft = std::to_string(remaining);
            std::string times = std::to_string(time);

            bool making_move = false;
            graphic.clear_squares();
            graphic.clear_text();
            graphic.Draw_grid();
            graphic.Draw_status();
            graphic.Draw_x();
            al_draw_text(font, al_map_rgb(255, 255, 255), 800, 40, 0, "score: ");
            al_draw_text(font, al_map_rgb(255, 255, 255), 890, 40, 0, pairs.c_str());
            al_draw_text(font, al_map_rgb(255, 255, 255), 800, 80, 0, "left: ");
            al_draw_text(font, al_map_rgb(255, 255, 255), 890, 80, 0, pairsLeft.c_str());
            al_draw_text(font, al_map_rgb(255, 255, 255), 800, 120, 0, "time: ");
            al_draw_text(font, al_map_rgb(255, 255, 255), 890, 120, 0, times.c_str());
            al_flip_display();

            
            al_wait_for_event(EventQueue, &ev);

            if (ev.type == ALLEGRO_EVENT_TIMER) {
                time += 1;
            }

            if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { Done = true; }

            else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
                making_move = true;

                if (ev.mouse.button & 1 && guesses < 2) {
                    int x = ev.mouse.x;
                    int y = ev.mouse.y;
                    std::vector<std::pair<int, int>> coords = logic.Get_Mouse_Input(x, y);
                    int ansShape = logic.get_shape(coords[0].first, coords[0].second);
                    graphic.Draw_shape(ansShape, coords[1].first, coords[1].second);
                    if (guesses == 0) {
                        firstGuess = ansShape;
                        firstx = coords[0].first;
                        firsty = coords[0].second;
                    }
                    else if (guesses == 1) {
                        secondGuess = ansShape;
                        secondx = coords[0].first;
                        secondy = coords[0].second;
                    }
                    guesses += 1;
                }
                else if (guesses >= 2) {
                    make_guess = true;
                    if (make_guess) {
                        
                        int x = ev.mouse.x;
                        int y = ev.mouse.y;
                        std::vector<std::pair<int, int>> coords = logic.Get_Mouse_Input(x, y);
                        if (logic.get_shape(coords[0].first, coords[0].second) == 0) {
                            //make comparison
                            make_guess = false;
                            if (logic.compare_shapes(firstGuess, secondGuess)) {
                                logic.make_move(firstx, firsty);
                                logic.make_move(secondx, secondy);
                                score += 1;
                                remaining -= 1;
                                if (remaining == 0) {
                                    Done = true;
                                    remaining = 12;
                                }
                            }
                            else {
                                //al_rest(5);
                                al_clear_to_color(al_map_rgb(0, 0, 0));
                            }
                        }
                        else {
                            continue;
                        }
                    }

                    guesses = 0;
                }
            }
        }
        al_stop_timer(timer);
        al_draw_filled_rectangle(0, 0, width/2, height, al_map_rgb(0, 255, 0));
        al_draw_filled_rectangle(width/2, 0, width, height, al_map_rgb(255, 0, 0));
        std::string times = std::to_string(time); 
        al_draw_text(font, al_map_rgb(255, 255, 255), width/2, height/2, 0, "you finished in: ");
        al_draw_text(font, al_map_rgb(255, 255, 255), width/2 + 200, height/2, 0, times.c_str());
        al_draw_text(font, al_map_rgb(255, 255, 255), width / 2 - 200, 200, 0, "play Again? <yes, no>");
        al_flip_display();
        while (true) {
            al_wait_for_event(EventQueue, &ev);
            if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
                int x = ev.mouse.x;
                if (x <= width / 2) {
                    break;
                }
                else if (x > width / 2) {
                    gaming = false;
                    break;
                }
            }
        }
        // here I must put would you LIKE TOL CONTINUE PLASSE
    }
}

