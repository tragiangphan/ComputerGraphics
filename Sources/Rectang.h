#ifndef RECTANG_H
#define RECTANG_H

#include <winbgim.h> 
#include "Pencil.h"
#include "Const.h"

class Rectang {
	
public:
	
	int x1;
	int y1;
	int x2;
	int y2;
	int thickness;
	
	Rectang(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, int thickness = 1)
	{
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
		this->thickness = thickness;
	}
	
	virtual void set(int x1, int y1, int x2, int y2, int thickness)
	{
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
		this->thickness = thickness;
	}
	
	virtual void update_pos(int delta_x, int delta_y)
	{
		x1 += delta_x;
		y1 += delta_y;
		x2 += delta_x;
		y2 += delta_y;	
	}
	
	virtual void draw_and_fill()
	{
		setlinestyle(0, 0, this->thickness);
		bar(x1, y1, x2, y2);	
	}
	
	virtual void draw()
	{
		setlinestyle(0, 0, this->thickness);
		rectangle(x1, y1, x2, y2);
	}
	
	
	virtual void draw_color(int color)
	{
		setcolor(color);
		rectangle(x1, y1, x2, y2);
		setcolor(BLACK);
	}
	
	virtual void draw_3D(int length, int height)
	{
		setlinestyle(0,0,this->thickness);
		bar3d(x1, y1, x2, y2, length, height);
	}
	
	virtual void operator=(Rectang& rectang)
	{
		this->x1 = rectang.x1;
		this->x2 = rectang.x2;
		this->y1 = rectang.y1;
		this->y2 = rectang.y2;
		this->thickness = rectang.thickness;
	}
	


};

#endif 
