#ifndef USERTABLE_H
#define USERTABLE_H



#include <vector>
#include <math.h>
#define COS(x) cos(x * 3.141592653589 / 180)
#define SIN(x) sin(x * 3.141592653589 / 180)
#include "Shape.h"
#include "Painter.h"


class UserTable{
	
public:
	
	static int COL; // 211
	static int ROW; // 125
	static int DTX; // 301 ( DELTA , the dif of x1 and x2 <=> |x1-x2|
	static int DTY; // 101
	
	

private:
	
	static int MULTI;
	static int PIXEL_SZ; 


	void put_to_table(int x, int y, int color)
	{
		Painter::set_color_will_fill(color);
		bar( DTX + 1 + MULTI*x , DTY + 1 + MULTI*y, 
		     DTX + 1 +PIXEL_SZ+MULTI*x, DTY + 1 + PIXEL_SZ + MULTI*y);
	}

	
public:
	
	

	
	
	
	static void make_change_ratote(int& user_x, int& user_y, double alpha)
	{
		 
		int x = user_x;
		int y = user_y;
		user_x = x*COS(alpha) - y*SIN(alpha);
		user_y = x*SIN(alpha) + y*COS(alpha);
		
		if(user_x < 0 && abs(user_x) < 12)
			user_x--;
		if(user_x > 0 && abs(user_x) < 12)
			user_x++;	
	}
	
	
	
	UserTable()
	{
		Pencil::set_color(LIGHTGRAY);
		
		for (int i = 0; i < COL+1; i++)
			line(DTX+MULTI*i, DTY, DTX+MULTI*i, DTY+MULTI*ROW);
		
		for(int i = 0; i < ROW+1; i++)
			line(DTX, DTY+MULTI*i, DTX+MULTI*COL, DTY+MULTI*i);
	
		
		Pencil::set_color(RED);
		
		int HALF_MUL = MULTI/2;
		
		line( DTX+HALF_MUL*(COL-1)      , DTY, DTX+HALF_MUL*(COL-1)      ,  DTY+MULTI*ROW );
		line( DTX+HALF_MUL*(COL-1)+MULTI, DTY, DTX+HALF_MUL*(COL-1)+MULTI,  DTY+MULTI*ROW     );
		
		line( DTX, DTY+HALF_MUL*(ROW-1)      , DTX+MULTI*COL, DTY+HALF_MUL*(ROW-1)       );
		line( DTX, DTY+HALF_MUL*(ROW-1)+MULTI, DTX+MULTI*COL, DTY+HALF_MUL*(ROW-1)+MULTI  );
	}
	
	
	
	void draw_shape(Shape* shape, int color)
	{
		int SZ = shape->point_list.size();
		for(int i = 0; i < SZ; i++)
			this->put_to_table(shape->point_list.at(i).x, shape->point_list.at(i).y, color);

	}
	
	void draw_shape(Shape& shape, int color)
	{
		int SZ = shape.point_list.size();
		for(int i = 0; i < SZ; i++)
			this->put_to_table(shape.point_list.at(i).x, shape.point_list.at(i).y, color);
	}
	
	
	void clear_shape(Shape* shape)
	{
		int SZ = shape->point_list.size();
		for(int i = 0; i < SZ; i++)
			this->put_to_table(shape->point_list.at(i).x, shape->point_list.at(i).y, WHITE);
	}
	
	void clear_shape(Shape& shape)
	{
		int SZ = shape.point_list.size();
		for(int i = 0; i < SZ; i++)
			this->put_to_table(shape.point_list.at(i).x, shape.point_list.at(i).y, WHITE);
	}

};


int UserTable::PIXEL_SZ = 5; // = 1,3,5,7,9,11
int UserTable::MULTI = UserTable::PIXEL_SZ+1;
int UserTable::COL = 211; // 2k+1
int UserTable::ROW = 125; // 2k+1
int UserTable::DTX = 250;
int UserTable::DTY = 0;



#endif
