#ifndef SHAPELIST_H
#define SHAPELIST_H
#include "Shape.h"

class Triangle : public Shape
{

public:
	int arr[3][2];

	Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
	{
		arr[0][0] = x1;
		arr[0][1] = y1;
		arr[1][0] = x2;
		arr[1][1] = y2;
		arr[2][0] = x3;
		arr[2][1] = y3;

		this->add_line(arr[0][0], arr[0][1], arr[1][0], arr[1][1]);
		this->add_line(arr[1][0], arr[1][1], arr[2][0], arr[2][1]);
		this->add_line(arr[2][0], arr[2][1], arr[0][0], arr[0][1]);
	}

	void rotate(int xc, int yc, double alpha)
	{
		for (int i = 0; i < 3; i++)
		{
			int x_sh = arr[i][0] - xc;
			int y_sh = arr[i][1] - yc;

			arr[i][0] = xc + x_sh * COS(alpha) - y_sh * SIN(alpha);
			arr[i][1] = yc + x_sh * SIN(alpha) + y_sh * COS(alpha);
		}

		this->point_list.clear();
		this->add_line(arr[0][0], arr[0][1], arr[1][0], arr[1][1]);
		this->add_line(arr[1][0], arr[1][1], arr[2][0], arr[2][1]);
		this->add_line(arr[2][0], arr[2][1], arr[0][0], arr[0][1]);
	}
};

class MovingShape : public Shape
{
public:
	int xCenter;
	int yCenter;

	MovingShape()
	{
	}

	MovingShape(int xc, int yc)
	{
		this->xCenter = xc;
		this->yCenter = yc;
	}

	void move_up()
	{
		Shape::move_up();
		this->yCenter++;
	}

	void move_down()
	{
		Shape::move_down();
		this->yCenter--;
	}

	void move_left()
	{
		Shape::move_left();
		this->xCenter--;
	}

	void move_right()
	{
		Shape::move_right();
		this->xCenter++;
	}
};

#endif