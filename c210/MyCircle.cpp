#include "MyCircle.h"

#include<iostream>
#define _USE_MATH_DEFINES
#include <math.h>

MyCircle::MyCircle() :radius(0) {}
MyCircle::MyCircle(const Point& center, const float radius,
	const MyColor circle_color, const size_t circle_thickness, const MyStyle circle_line_style)
	:MyShape(circle_color, circle_thickness, circle_line_style), circle_center(center), radius(radius)
{}
MyCircle::MyCircle(const float center_x, const float center_y, const float radius,
	const MyColor circle_color, const size_t circle_thickness, const MyStyle circle_line_style)
	:MyShape(circle_color, circle_thickness, circle_line_style), circle_center(center_x, center_y),
	radius(radius)
{}

MyCircle::MyCircle(const MyCircle & other_circle):MyShape(other_circle),circle_center(other_circle.circle_center),radius(other_circle.radius)
{
}

MyCircle::~MyCircle()
{
	//std::cout << "\nCyrcle destructor\n";
}


void MyCircle::SetAll(const Point& center, const float radius,
						MyColor const shape_color, size_t const shape_thickness, MyStyle const shape_line)
{
	circle_center = center;//try default operand for Point
	this->radius = radius;
	this->MyShape::SetAll(shape_color, shape_thickness, shape_line);
}
void MyCircle::GetAll(Point& center, float& radius,
						MyColor& shape_color, size_t& shape_thickness, MyStyle& shape_line) const
{
	center = circle_center;
	radius = this->radius;
	this->MyShape::GetAll(shape_color, shape_thickness, shape_line);
}

bool MyCircle::operator==(const MyCircle& other_circle) const
{
	return (circle_center == other_circle.circle_center)
		&& (radius == other_circle.radius)
		&& MyShape::operator==(other_circle);
}

bool MyCircle::operator==(const MyShape& otherShape) const
{ 
	const MyCircle* tempCyrcle = dynamic_cast<const MyCircle*>(&otherShape);
	if (tempCyrcle == nullptr) return false;
	else return *this == *tempCyrcle;
}

MyCircle& MyCircle::operator=(const MyCircle& crl_src)
{
	if (&crl_src != this)
	{
		circle_center= crl_src.circle_center;
		radius = crl_src.radius;
		this->MyShape::operator=(crl_src);
	}
	return *this;
}

MyCircle& MyCircle::operator=(const MyShape& shp_src)
{
	if (&shp_src != this)
	{
		const MyCircle* p_temp_circle = dynamic_cast<const MyCircle*>(&shp_src);
		if (p_temp_circle) this->operator=(*p_temp_circle);
		else throw "\nassigned different type of shape to circle!\n";
	}
	return *this;
}

MyShape& MyCircle::Clone() const
{
	return *(new MyCircle(*this));
}

float MyCircle::GetSquare()
{
	return M_PI*radius*radius;
}


ostream& operator<<(ostream& stream, const MyCircle& circle)
{
	stream << circle.circle_center <<" r= " << circle.radius <<"\t\t" << static_cast<const MyShape&>(circle);
	return stream;
}