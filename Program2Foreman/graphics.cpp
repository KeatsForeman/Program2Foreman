#include "graphics.h"
#include "logic.h"


graphics::graphics(logic* l) {
	gamelogic = l;
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
void graphics::Draw_status() {
	al_draw_filled_rectangle(600, 480, 750, 600, al_map_rgb(0, 255, 0));
}
void graphics::Draw_shape(int shape, int x, int y) {
	if (shape == 1) {
		al_draw_filled_circle(x, y, 20, al_map_rgb(255, 0, 0));
	}
	if (shape == 2) {
		al_draw_filled_circle(x, y, 20, al_map_rgb(0, 255, 0));
	}
	if (shape == 3) {
		al_draw_filled_circle(x, y, 20, al_map_rgb(0, 0, 255));
	}
	if (shape == 4) {
		al_draw_filled_circle(x, y, 20, al_map_rgb(255, 0, 255));
	}
	if (shape == 5) {
		al_draw_filled_circle(x, y, 20, al_map_rgb(0, 255, 255));
	}
	if (shape == 6) {
		al_draw_filled_circle(x, y, 20, al_map_rgb(255, 255, 255));
	}
	if (shape == 7) {
		al_draw_filled_rectangle(x-20, y-20, x + 20, y+20, al_map_rgb(255, 0, 0));
	}
	if (shape == 8) {
		al_draw_filled_rectangle(x - 20, y - 20, x + 20, y + 20, al_map_rgb(0, 255, 0));
	}
	if (shape == 9) {
		al_draw_filled_rectangle(x - 20, y - 20, x + 20, y + 20, al_map_rgb(0, 0, 255));
	}
	if (shape == 10) {
		al_draw_filled_rectangle(x - 20, y - 20, x + 20, y + 20, al_map_rgb(255, 0, 255));
	}
	if (shape == 11) {
		al_draw_filled_rectangle(x - 20, y - 20, x + 20, y + 20, al_map_rgb(0, 255, 255));
	}
	if (shape == 12) {
		al_draw_filled_rectangle(x - 20, y - 20, x + 20, y + 20, al_map_rgb(255, 255, 255));
	}
}
void graphics::Draw_x() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (gamelogic->get_square_status(i, j)) {
				int x = (j * 150) + 75;
				int y = (i * 120) + 60;
				al_draw_line(x - 30, y - 20, x + 30, y + 20, al_map_rgb(255, 255, 255), 2);
				al_draw_line(x - 30, y + 20, x + 30, y - 20, al_map_rgb(255, 255, 255), 2);
			}
		}
	}
}
void graphics::clear_squares() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (gamelogic->get_square_status(i, j)) {
				int x = (j * 150);
				int y = (i * 120);
				al_draw_filled_rectangle(x, y, x + 150, y + 120, al_map_rgb(0, 0, 0));
			}
		}
	}
}
void graphics::clear_text() {
	al_draw_filled_rectangle(750, 0, 950, 600, al_map_rgb(0, 0, 0));
}
