#include "Point.h"

Point::Point() :x(0), y(0) {}
Point::Point(float x, float y) :x(x), y(y) {}

Point& Point::operator+= (const Point& inc_point)
{
	x += inc_point.x;
	y += inc_point.y;
	return *this;
}
Point& Point::operator+= (const float incr)
{
	x += incr;
	y += incr;
	return *this;
}

Point& operator-=(Point& minuend, const Point& subtrahend)
{
	minuend.x -= subtrahend.x;
	minuend.y -= subtrahend.y;
	return minuend;
}
Point& operator-=(Point& minuend, const float subtrahend)
{
	minuend.x -= subtrahend;
	minuend.y -= subtrahend;
	return minuend;
}

Point Point::operator+(const Point& p2) const
{
	Point temp_p(x + p2.x, y + p2.y);
	return temp_p;
}
Point Point::operator+(const float p2) const
{
	Point temp_p(x + p2, y + p2);
	return temp_p;
}
Point operator+(const float p1, const Point& p2)
{
	Point temp_p(p1 + p2.x, p1 + p2.y);
	return temp_p;
}

Point operator-(const Point& p1, const Point& p2)
{
	Point temp_p(p1.x - p2.x, p1.y - p2.y);
	return temp_p;
}
Point operator-(const float p1, const Point& p2)
{
	Point temp_p(p1 - p2.x, p1 - p2.y);
	return temp_p;
}
Point operator-(const Point& p1, const float p2)
{
	Point temp_p(p1.x - p2, p1.y - p2);
	return temp_p;
}

Point operator-(const Point& p1)
{
	Point temp(-p1.x, -p1.y);
	return temp;
}

const Point& Point::operator+() const
{
	return *this;
}

ostream& operator<<(ostream& os, const Point& p1)
{
	os << p1.x << endl << p1.y << endl;
	return os;
}

bool Point::operator==(const Point& other_point) const
{
	return (x == other_point.x) && (y == other_point.y);
}