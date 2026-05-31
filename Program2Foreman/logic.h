#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <utility>

class logic {
public:
	logic();
	~logic();
	 std::pair<int, int> Get_Mouse_Input(int x, int y);

};
