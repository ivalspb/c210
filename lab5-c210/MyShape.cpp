#include "MyShape.h"
#include <iostream>

static const char* MyColorString[] = {"WHITE", "BLACK", "RED", "GREEN", "BLUE"};
static const char* MyStyleString[] = {"SOLID", "DOTTED"};

MyShape::MyShape()//:color(BLACK),thickness(1),line_type(SOLID)
{}
MyShape::MyShape(const MyColor color, const  size_t thickness, const  MyStyle line_type):
	color(color),thickness(thickness),line_type(line_type)
{}

MyShape::MyShape(const MyShape & other_shape):color(other_shape.color),thickness(other_shape.thickness),line_type(other_shape.line_type)
{
}

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

MyShape::MyColor& MyShape::GetColor()
{
	return color;
}

bool MyShape::operator==(const MyShape& other) const
{
	return (other.color == color)&&(other.line_type==line_type)&&(other.thickness==thickness);
}

MyShape& MyShape::operator=(const MyShape& shp_src)
{
	if (&shp_src != this)//если адрес источника и приемника совпадают, значит присваивать зацикленно не нужно 
	{
		color = shp_src.color;
		thickness = shp_src.thickness;
		line_type = shp_src.line_type;
	}
	return *this;
}

//MyShape& MyShape::operator=(MyShape&& tmp_shp_src)
//{
//	if (&tmp_shp_src != this)
//	{
//		*this = tmp_shp_src;
//	}
//	return *this;
//}

ostream& operator<<(ostream& stream, const MyShape& shape)
{
	stream << MyColorString[shape.color] << "\t " << shape.thickness << "\t" << MyStyleString[shape.line_type];
	return stream;
}

ofstream& operator<<(ofstream& stream, const MyShape& shape)
{
	stream << MyColorString[shape.color] << endl << shape.thickness << endl << MyStyleString[shape.line_type];
	return stream;
}
