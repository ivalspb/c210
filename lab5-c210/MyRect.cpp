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
MyRect::MyRect()// :MyShape(GREEN, 1, SOLID)//конструктор по умолчнию
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
	if (height < 0)//при отрицательной высоте вершина будет не вверху, а внизу, меняем.
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

MyRect& MyRect::operator=(const MyShape& shape_src)
{
	if (this != &shape_src)
	{
		const MyRect* temp_rect = dynamic_cast<const MyRect*>(&shape_src);
		if (temp_rect) this->operator=(*temp_rect);
		else throw "\nassigned different type of shape to rect!\n";
	}
	return *this;
}

MyShape& MyRect::Clone() const
{
	return *(new MyRect(*this));
}

float MyRect::GetSquare()
{
	return height*width;
}

ostream& operator<<(ostream& stream, const MyRect& rect)
{
	stream << rect.vertex <<" h= " << rect.height<<" w= " << rect.width<<"\t" << static_cast<const MyShape&>(rect);
	return stream<<endl;
}

ofstream& operator<<(ofstream& stream, const MyRect& rect)
{
	stream << "MyRect" << endl;
	stream << rect.vertex <<  rect.height << endl << rect.width << endl;
	stream << static_cast<const MyShape&>(rect);
	return stream;
}

bool CompareByRectCenter(MyRect& r1, MyRect& r2)
{
	float bottom, top, right, left;
	MyShape::MyColor clr;
	size_t thinkness;
	MyShape::MyStyle stl;
	r1.GetAll(left, right, top, bottom, clr, thinkness, stl);
	Point r1center(right-left, bottom - top);
	r2.GetAll(left, right, top, bottom, clr, thinkness, stl);
	Point r2center(right - left, bottom - top);
	return r1center<r2center;
}
