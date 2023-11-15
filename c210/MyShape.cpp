#include "MyShape.h"
#include <iostream>

MyShape::MyShape():color(BLACK),thickness(1),line_type(SOLID)
{}
MyShape::MyShape(MyColor color, size_t thickness, MyStyle line_type):
	color(color),thickness(thickness),line_type(line_type)
{}

MyShape::~MyShape()
{
}

void MyShape::GetAll(MyColor& shape_color, size_t& shape_thickness, MyStyle& shape_line) const
{
	shape_color = color;
	shape_thickness = thickness;
	shape_line = line_type;
}

void MyShape::SetAll(MyColor const shape_color, size_t const shape_thickness, MyStyle const shape_line)
{
	color = shape_color;
	thickness = shape_thickness;
	line_type = shape_line;
}

bool MyShape::operator==(const MyShape& other) const
{
	return (other.color == color)&&(other.line_type==line_type)&&(other.thickness==thickness);
}
