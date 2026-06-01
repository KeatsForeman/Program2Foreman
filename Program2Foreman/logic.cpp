#include "logic.h"

logic::logic() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			already_played[i][j] = false;
		}
	}
	srand(time(0));
	//used to randomly fill grid
	std::vector<int> shape_filler = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12};
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i == 4 && j == 4) {
				shapes[i][j] = 0;
				break;
			}
			int num = rand() % shape_filler.size();
			shapes[i][j] = shape_filler.at(num);
			shape_filler.erase(shape_filler.begin() + num);
		}
	}
}
logic::~logic() {
}

std::pair<int, int> logic::Get_Mouse_Input(int x, int y) {
	//row 0
	if (y < 120) {
		if (x < 150) {
			return std::make_pair(0, 0);
		}
		if (x > 150 && x < 300) {
			return std::make_pair(0, 1);
		}
		if (x > 300 && x < 450) {
			return std::make_pair(0, 2);
		}
		if (x > 450 && x < 600) {
			return std::make_pair(0, 3);
		}
		if (x > 600 && x < 750) {
			return std::make_pair(0, 4);
		}
	}
	//row 1
	if (y > 120 && y < 240) {
		if (x < 150) {
			return std::make_pair(1, 0);
		}
		if (x > 150 && x < 300) {
			return std::make_pair(1, 1);
		}
		if (x > 300 && x < 450) {
			return std::make_pair(1, 2);
		}
		if (x > 450 && x < 600) {
			return std::make_pair(1, 3);
		}
		if (x > 600 && x < 750) {
			return std::make_pair(1, 4);
		}
	}
	//row 2
	if (y > 240 && y < 360) {
		if (x < 150) {
			return std::make_pair(2, 0);
		}
		if (x > 150 && x < 300) {
			return std::make_pair(2, 1);
		}
		if (x > 300 && x < 450) {
			return std::make_pair(2, 2);
		}
		if (x > 450 && x < 600) {
			return std::make_pair(2, 3);
		}
		if (x > 600 && x < 750) {
			return std::make_pair(2, 4);
		}
	}
	//row 3
	if (y > 360 && y < 480) {
		if (x < 150) {
			return std::make_pair(3, 0);
		}
		if (x > 150 && x < 300) {
			return std::make_pair(3, 1);
		}
		if (x > 300 && x < 450) {
			return std::make_pair(3, 2);
		}
		if (x > 450 && x < 600) {
			return std::make_pair(3, 3);
		}
		if (x > 600 && x < 750) {
			return std::make_pair(3, 4);
		}
	}
	//row 4
	if (y > 480 && y < 600) {
		if (x < 150) {
			return std::make_pair(4, 0);
		}
		if (x > 150 && x < 300) {
			return std::make_pair(4, 1);
		}
		if (x > 300 && x < 450) {
			return std::make_pair(4, 2);
		}
		if (x > 450 && x < 600) {
			return std::make_pair(4, 3);
		}
		if (x > 600 && x < 750) {
			return std::make_pair(4, 4);
		}
	}
}
int logic::get_shape(int x, int y) {
	return shapes[x][y];
}