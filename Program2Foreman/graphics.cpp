#include "graphics.h"


graphics::graphics() {
}
graphics::~graphics() {
}
void graphics::Draw_grid() {
	al_draw_line(150, 0, 150, 600, al_map_rgb(255, 255, 255), 2);
	al_draw_line(300, 0, 300, 600, al_map_rgb(255, 255, 255), 2);
	al_draw_line(450, 0, 450, 600, al_map_rgb(255, 255, 255), 2);
	al_draw_line(600, 0, 600, 600, al_map_rgb(255, 255, 255), 2);
	al_draw_line(750, 0, 750, 600, al_map_rgb(255, 255, 255), 2);

	al_draw_line(0, 120, 750, 120, al_map_rgb(255, 255, 255), 2);
	al_draw_line(0, 240, 750, 240, al_map_rgb(255, 255, 255), 2);
	al_draw_line(0, 360, 750, 360, al_map_rgb(255, 255, 255), 2);
	al_draw_line(0, 480, 750, 480, al_map_rgb(255, 255, 255), 2);
}

