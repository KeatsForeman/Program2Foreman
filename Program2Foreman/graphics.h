#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>

class graphics {

public:
	graphics();
	~graphics();
	void Draw_grid();
	void Draw_status();
	void Draw_shape(int shape, int x, int y);


};