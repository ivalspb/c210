#include "MyCircle.h"

#include<iostream>
#include <math.h>

MyCircle::MyCircle() :radius(0) {}
MyCircle::MyCircle(const Point& center, const float radius,
	MyColor circle_color, size_t circle_thickness, MyStyle circle_line_style)
	:MyShape(circle_color, circle_thickness, circle_line_style), circle_center(center), radius(radius)
{}
MyCircle::MyCircle(const float center_x, const float center_y, float radius,
	MyColor circle_color, size_t circle_thickness, MyStyle circle_line_style)
	:MyShape(circle_color, circle_thickness, circle_line_style), circle_center(center_x, center_y),
	radius(radius)
{}


void MyCircle::SetAll(const Point& center, const float radius)
{
	circle_center = center;//try default operand for Point
	this->radius = radius;
}
void MyCircle::GetAll(Point& center, float& radius) const
{
	center = circle_center;
	radius = this->radius;
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

float MyCircle::GetSquare()
{
	return 3.14*radius*radius;
}


ostream& operator<<(ostream& stream, MyCircle& circle)
{
	stream << circle.circle_center << circle.radius << endl;//укороченная версия без shape
	return stream;
}