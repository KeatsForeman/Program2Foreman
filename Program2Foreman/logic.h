#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <utility>
#include <vector>

class logic {
public:
	logic();
	~logic();
	 std::pair<int, int> Get_Mouse_Input(int x, int y);
	 int get_shape(int x, int y);

private:
	int shapes[5][5];
	bool already_played[5][5];
};
