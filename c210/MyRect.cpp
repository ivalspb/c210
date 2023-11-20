#include "MyRect.h"

#include <iostream>

MyRect::MyRect(Point left_top, float height, float width,
	MyColor rect_color, size_t rect_thickness, MyStyle rect_line_style)
	:MyShape(rect_color, rect_thickness, rect_line_style)
{
	vertex = left_top;
	this->height = height;
	this->width = width;
	Rect_normilize();
}
MyRect::MyRect() :MyShape(GREEN, 1, SOLID)//конструктор по умолчнию
{
	height = 0;
	width = 0;
}

MyRect::~MyRect()
{
	std::cout << "\nRect destructor!\n";
}

void MyRect::Rect_normilize()
{
	if (height < 0)//при отрицательной высоте вершина будет не вверху, а внизу, меняем.
	{
		height = -height;
		vertex.y -= height;
	}
	if (width < 0)
	{
		width = -width;
		vertex.x -= width;
	}
}

void MyRect::SetAll(const float& left_coord, const float& right_coord,
	const float& top_coord, const float& bottom_coord)
{
	vertex.x = left_coord;
	vertex.y = top_coord;
	height = bottom_coord - top_coord;
	width = right_coord - left_coord;
	Rect_normilize();
}
void MyRect::GetAll(float& left_coord, float& right_coord, float& top_coord, float& bottom_coord) const
{
	left_coord = vertex.x;
	right_coord = vertex.x + width;
	top_coord = vertex.y;
	bottom_coord = vertex.y + height;
}
void MyRect::GetAll(Point& left_top, float& height, float& width) const
{
	left_top = vertex;
	height = this->height;
	width = this->width;
}


