#include "MyRect.h"

#include <iostream>

MyRect::MyRect(const Point left_top, const float height, const float width,
	const MyColor rect_color, const size_t rect_thickness, const MyStyle rect_line_style)
	:MyShape(rect_color, rect_thickness, rect_line_style)
{
	vertex = left_top;
	this->height = height;
	this->width = width;
	Rect_normilize();
}
MyRect::MyRect()// :MyShape(GREEN, 1, SOLID)//����������� �� ��������
{
	/*height = 0;
	width = 0;*/
}

MyRect::MyRect(const float left_top_x, const float left_top_y, 
				const float rigt_bottom_x, const float rigt_bottom_y,
				const MyColor rect_color, const size_t rect_thickness, const MyStyle rect_line_style)
	:MyShape(rect_color, rect_thickness, rect_line_style)
{
	vertex = { left_top_x,left_top_y };
	height = rigt_bottom_y - left_top_y;
	width = rigt_bottom_x - left_top_x;
	Rect_normilize();
}

MyRect::MyRect(const MyRect& other_rect):MyShape(other_rect),vertex(other_rect.vertex),height(other_rect.height),width(other_rect.width)
{
}

MyRect::~MyRect()
{
	//std::cout << "\nRect destructor\n";
}

void MyRect::Rect_normilize()
{
	if (height < 0)//��� ������������� ������ ������� ����� �� ������, � �����, ������.
	{
		height = -height;
		vertex -= {0,height};
	}
	if (width < 0)
	{
		width = -width;
		vertex -= {width,0};
	}
}

void MyRect::SetAll(const float& left_coord, const float& right_coord,
	const float& top_coord, const float& bottom_coord,
	MyColor const shape_color, size_t const shape_thickness, MyStyle const shape_line)
{
	vertex = { left_coord,	top_coord };
	height = bottom_coord - top_coord;
	width = right_coord - left_coord;
	Rect_normilize();
	this->MyShape::SetAll(shape_color, shape_thickness, shape_line);
}
void MyRect::GetAll(float& left_coord, float& right_coord, float& top_coord, float& bottom_coord,
					MyColor& shape_color, size_t& shape_thickness, MyStyle& shape_line) const
{
	left_coord = vertex.get_x();
	right_coord = vertex.get_x() + width;
	top_coord = vertex.get_y();
	bottom_coord = vertex.get_y() + height;
	this->MyShape::GetAll(shape_color, shape_thickness, shape_line);
}
void MyRect::GetAll(Point& left_top, float& height, float& width,
					MyColor& shape_color, size_t& shape_thickness, MyStyle& shape_line) const
{
	left_top = vertex;
	height = this->height;
	width = this->width;
	this->MyShape::GetAll(shape_color, shape_thickness, shape_line);
}

bool MyRect::operator==(const MyRect& other_rect) const
{
	return (vertex == other_rect.vertex)&&
			(height==other_rect.height)&&
			(width==other_rect.width)&&
			this->MyShape::operator==(other_rect);
}

bool MyRect::operator==(const MyShape& other_shape) const
{
	const MyRect* temp_rect = dynamic_cast<const MyRect*>(&other_shape);
	if (temp_rect == nullptr) return false;
	else return *temp_rect==*this;
}

MyRect& MyRect::operator=(const MyRect& rect_src)
{
	if (this != &rect_src)
	{
		vertex = rect_src.vertex;
		height = rect_src.height;
		width = rect_src.width;
		this->MyShape::operator=(rect_src);
	}
	return *this;
}

float MyRect::GetSquare()
{
	return height*width;
}

ostream& operator<<(ostream& stream, const MyRect& rect)
{
	stream <<"Rect vertex " << rect.vertex 
			<<"Rect height " << rect.height<<endl 
			<<"Rect width " << rect.width<<endl
			<<static_cast<const MyShape&>(rect) <<endl;

	return stream;
}
