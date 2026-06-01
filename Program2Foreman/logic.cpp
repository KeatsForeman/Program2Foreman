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

//returns the middle of the square as well as the adjacent array coords
std::vector<std::pair<int, int>> logic::Get_Mouse_Input(int x, int y) {
	//row 0
	std::vector<std::pair<int, int>> coords;
	if (y < 120) {
		if (x < 150) {
			coords.push_back(std::make_pair(0, 0));
			coords.push_back(std::make_pair(75, 60));
		}
		if (x > 150 && x < 300) {
			coords.push_back(std::make_pair(0, 1));
			coords.push_back(std::make_pair(225, 60));
		}
		if (x > 300 && x < 450) {
			coords.push_back(std::make_pair(0, 2));
			coords.push_back(std::make_pair(375, 60));
		}
		if (x > 450 && x < 600) {
			coords.push_back(std::make_pair(0, 3));
			coords.push_back(std::make_pair(525, 60));
		}
		if (x > 600 && x < 750) {
			coords.push_back(std::make_pair(0, 4));
			coords.push_back(std::make_pair(675, 60));
		}
	}
	//row 1
	if (y > 120 && y < 240) {
		if (x < 150) {
			coords.push_back(std::make_pair(1, 0));
			coords.push_back(std::make_pair(75, 180));
		}
		if (x > 150 && x < 300) {
			coords.push_back(std::make_pair(1, 1));
			coords.push_back(std::make_pair(225, 180));
		}
		if (x > 300 && x < 450) {
			coords.push_back(std::make_pair(1, 2));
			coords.push_back(std::make_pair(375, 180));
		}
		if (x > 450 && x < 600) {
			coords.push_back(std::make_pair(1, 3));
			coords.push_back(std::make_pair(525, 180));
		}
		if (x > 600 && x < 750) {
			coords.push_back(std::make_pair(1, 4));
			coords.push_back(std::make_pair(675, 180));
		}
	}
	//row 2
	if (y > 240 && y < 360) {
		if (x < 150) {
			coords.push_back(std::make_pair(2, 0));
			coords.push_back(std::make_pair(75, 300));
		}
		if (x > 150 && x < 300) {
			coords.push_back(std::make_pair(2, 1));
			coords.push_back(std::make_pair(225, 300));
		}
		if (x > 300 && x < 450) {
			coords.push_back(std::make_pair(2, 2));
			coords.push_back(std::make_pair(375, 300));
		}
		if (x > 450 && x < 600) {
			coords.push_back(std::make_pair(2, 3));
			coords.push_back(std::make_pair(525, 300));
		}
		if (x > 600 && x < 750) {
			coords.push_back(std::make_pair(2, 4));
			coords.push_back(std::make_pair(675, 300));
		}
	}
	//row 3
	if (y > 360 && y < 480) {
		if (x < 150) {
			coords.push_back(std::make_pair(3, 0));
			coords.push_back(std::make_pair(75, 420));
		}
		if (x > 150 && x < 300) {
			coords.push_back(std::make_pair(3, 1));
			coords.push_back(std::make_pair(225, 420));
		}
		if (x > 300 && x < 450) {
			coords.push_back(std::make_pair(3, 2));
			coords.push_back(std::make_pair(375, 420));
		}
		if (x > 450 && x < 600) {
			coords.push_back(std::make_pair(3, 3));
			coords.push_back(std::make_pair(525, 420));
		}
		if (x > 600 && x < 750) {
			coords.push_back(std::make_pair(3, 4));
			coords.push_back(std::make_pair(675, 420));
		}
	}
	//row 4
	if (y > 480 && y < 600) {
		if (x < 150) {
			coords.push_back(std::make_pair(4, 0));
			coords.push_back(std::make_pair(75, 540));
		}
		if (x > 150 && x < 300) {
			coords.push_back(std::make_pair(4, 1));
			coords.push_back(std::make_pair(225, 540));
		}
		if (x > 300 && x < 450) {
			coords.push_back(std::make_pair(4, 2));
			coords.push_back(std::make_pair(375, 540));
		}
		if (x > 450 && x < 600) {
			coords.push_back(std::make_pair(4, 3));
			coords.push_back(std::make_pair(525, 540));
		}
		if (x > 600 && x < 750) {
			coords.push_back(std::make_pair(4, 4));
			coords.push_back(std::make_pair(675, 540));
		}
	}
	return coords;
}
int logic::get_shape(int x, int y) {
	return shapes[x][y];
}
