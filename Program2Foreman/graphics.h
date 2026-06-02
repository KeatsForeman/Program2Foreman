#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include "logic.h"

class graphics {

public:
	graphics(logic* l);
	~graphics();
	void Draw_grid();
	void Draw_status();
	void Draw_shape(int shape, int x, int y);
	void Draw_x();
	void clear_squares();
	void clear_text();

private:
	logic* gamelogic;
};