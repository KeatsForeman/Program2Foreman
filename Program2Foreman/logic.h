#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <utility>
#include <vector>
#ifndef LOGIC_H
#define LOGIC_H

class logic {
public:
	logic();
	~logic();
	 std::vector<std::pair<int, int>> Get_Mouse_Input(int x, int y);
	 int get_shape(int x, int y);
	 void make_move(int x, int y);
	 bool compare_shapes(int x, int y);
	 bool get_square_status(int x, int y);


private:
	int shapes[5][5];
	bool already_played[5][5];
};
#endif