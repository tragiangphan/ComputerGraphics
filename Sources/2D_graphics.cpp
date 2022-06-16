#include "UserTable.h"
#include "Rectang.h"
#include "ShapeList.h"
#include "Pixel.h"
#include "Text.h"

using namespace std;

class Point
{
public:
	int x;
	int y;
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

class Point3D
{
public:
	int x;
	int y;
	int z;
	Point3D(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

int main()
{
	initwindow(1790, 770);
	Painter::fill_background(WHITE);
	UserTable user_table;

	//===== The sun =====
	Shape theSun;
	int x = 50, y = 10;
	theSun.add_circle(0 + x, 30 - y, 7);
	theSun.add_line(0 + x, 40 - y, 0 + x, 45 - y);
	theSun.add_line(-8 + x, 37 - y, -13 + x, 40 - y);
	theSun.add_line(-10 + x, 30 - y, -15 + x, 30 - y);
	theSun.add_line(-8 + x, 23 - y, -13 + x, 20 - y);
	theSun.add_line(0 + x, 20 - y, 0 + x, 15 - y);
	theSun.add_line(8 + x, 37 - y, 12 + x, 39 - y);
	theSun.add_line(8 + x, 23 - y, 12 + x, 20 - y);
	theSun.add_line(10 + x, 30 - y, 15 + x, 30 - y);

	//===== Air_balloon =====
	Shape hotAirBalloonShape;
	hotAirBalloonShape.add_circle(-55, 51, 9);
	hotAirBalloonShape.add_line(-62, 45, -60, 40);
	hotAirBalloonShape.add_line(-48, 45, -50, 40);
	hotAirBalloonShape.add_line(-60, 39, -50, 39);
	hotAirBalloonShape.add_line(-60, 34, -50, 34);
	hotAirBalloonShape.add_line(-60, 34, -60, 39);
	hotAirBalloonShape.add_line(-50, 34, -50, 39);

	//===== Mountain =====
	Shape mountain_shape;
	mountain_shape.add_triangle(-105, 0, -80, 50, -55, 0);
	mountain_shape.add_triangle(-55, 0, -30, 35, 0, 0);
	// Fill first mountain
	mountain_shape.add_line(-95, 0, -75, 40);
	mountain_shape.add_line(-85, 0, -70, 31);
	mountain_shape.add_line(-75, 0, -65, 22);
	mountain_shape.add_line(-65, 0, -60, 11);
	// Fill second mountain
	mountain_shape.add_line(-45, 0, -24, 28);
	mountain_shape.add_line(-35, 0, -20, 20);
	mountain_shape.add_line(-25, 0, -14, 14);
	mountain_shape.add_line(-15, 0, -8, 8);

	// Water wheel
	Shape waterWheel;
	waterWheel.add_circle(-60, -15, 1);
	waterWheel.add_circle(-60, -15, 7);
	waterWheel.add_line(-60, -14, -60, -9);
	waterWheel.add_line(-61, -14, -66, -11);
	waterWheel.add_line(-61, -16, -66, -18);
	waterWheel.add_line(-60, -16, -60, -21);
	waterWheel.add_line(-59, -16, -54, -18);
	waterWheel.add_line(-59, -14, -54, -12);
	waterWheel.add_circle(-60, -15, 8);
	waterWheel.add_line(-57, -23, -54, -30);
	waterWheel.add_line(-56, -23, -53, -30);
	waterWheel.add_line(-64, -23, -67, -30);
	waterWheel.add_line(-63, -23, -66, -30);
	waterWheel.add_line(-63, -26, -56, -26);
	waterWheel.add_line(-64, -27, -55, -27);

	//===== Grass =====
	Shape grass;
	// line
	grass.add_line(-20, -1, -60, -62);
	grass.add_line(-60, -62, -105, -62);
	grass.add_line(-105, -62, -105, -1);

	//===== The house =====
	// the bone
	Shape theHouse;
	theHouse.add_rectangle(50, -20, 70, -40);
	theHouse.add_triangle(50, -20, 59, -11, 70, -20);
	// the roof
	Shape houseFurnitures;
	houseFurnitures.add_rectangle(52, -22, 58, -28);
	houseFurnitures.add_line(55, -22, 55, -28);
	houseFurnitures.add_line(52, -25, 58, -25);
	houseFurnitures.add_rectangle(61, -30, 67, -40);
	houseFurnitures.add_pixel(63, -35);

	//===== Trees =====
	// Trunks
	Shape trunks;
	trunks.add_line(91, -47, 91, -20);
	trunks.add_line(91, -40, 82, -35);
	trunks.add_line(91, -37, 97, -32);
	// Leaves
	Shape leaves;
	leaves.add_circle(91, -20, 9);
	leaves.add_circle(97, -32, 4);
	leaves.add_circle(82, -35, 7);

	user_table.draw_shape(&waterWheel, MAGENTA);

	user_table.draw_shape(&grass, LIGHTGREEN);
	user_table.draw_shape(grass.get_symmetry_oy(), LIGHTGREEN);

	user_table.draw_shape(&theHouse, RED);
	user_table.draw_shape(&houseFurnitures, LIGHTBLUE);

	user_table.draw_shape(&leaves, GREEN);
	user_table.draw_shape(&trunks, BROWN);
	user_table.draw_shape(trunks.get_symmetry_oy(), BROWN);
	user_table.draw_shape(leaves.get_symmetry_oy(), GREEN);

	int countFrame = 0;
	int sunUpCount = -10;
	while (true)
	{

		user_table.draw_shape(&mountain_shape, DARKGRAY);
		user_table.draw_shape(mountain_shape.get_symmetry_oy(), DARKGRAY);

		delay(30);

		// clear objects
		user_table.clear_shape(&theSun);
		user_table.clear_shape(&hotAirBalloonShape);

		//=============================================================
		// We code here : move and then draw an object

		// move and then drawing Object1
		if (countFrame % 5 == 0)
		{

			if (sunUpCount < 15)
			{
				theSun.move_up();
			}
			else
			{
				theSun.move_down();
			}

			sunUpCount++;
		}

		user_table.draw_shape(&theSun, LIGHTRED);

		// move and then drawing move and then drawing Object2
		if (countFrame < 26)
		{
			hotAirBalloonShape.move_right();
		}
		else
		{
			hotAirBalloonShape.move_left();
		}

		user_table.draw_shape(&hotAirBalloonShape, LIGHTMAGENTA);

		//=============================================================

		if (countFrame == 50)
		{
			countFrame = 0;
		}
		countFrame++;

		if (sunUpCount == 30)
		{
			sunUpCount = 0;
		}
	}

	getchar();
	return 0;
}
