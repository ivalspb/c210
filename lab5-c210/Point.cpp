#include "Point.h"
#define _USE_MATH_DEFINES
#include <math.h>

Point::Point() :x(0), y(0) {}
Point::Point(float x, float y) :x(x), y(y) 
{}

float Point::get_x() const
{
	return x;
}

float Point::get_y() const
{
	return y;
}

void Point::set_x(const float value)
{
	x = value;
}

void Point::set_y(const float value)
{
	y = value;
}

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
	os <<"(" << p1.x << ", " << p1.y <<")";
	return os;
}

ofstream& operator<<(ofstream& fin, const Point&p)
{
	fin << p.x << endl << p.y << endl;
	return fin;
}

bool has_negative_coord(const Point& p1)
{
	return (p1.get_x()<0)||(p1.get_y()<0);
}

bool in_n_m(const Point& p1)
{
	const float n = M_PI, m = M_2_SQRTPI;
	return (p1.get_x() >= -n)&&(p1.get_x()<=m)&&(p1.get_y()>=-n)&&(p1.get_y()<=m);
}

bool Point::operator==(const Point& other_point) const
{
	return (x == other_point.x) && (y == other_point.y);
}

bool Point::operator<(const Point& p1) const
{
	return (x * x + y * y)<(p1.x*p1.x+p1.y*p1.y);//compare vector lenght
}

