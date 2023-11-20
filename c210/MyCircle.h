#pragma once
#include "MyShape.h"

class MyCircle :public MyShape
{
	Point circle_center;
	float radius;
	friend ostream& operator<<(ostream& stream, MyCircle& circle);
public:
	MyCircle();
	MyCircle(const Point& center, const float radius,
		MyColor = BLACK, size_t circle_thickness = 1,
		MyStyle circle_line_style = SOLID);
	MyCircle(const float center_x, const float center_y, float radius,
		MyColor circle_color = BLACK, size_t circle_thickness = 1,
		MyStyle circle_line_style = SOLID);

	void SetAll(const Point& center, const float radius);
	void GetAll(Point& center, float& raduis) const;

	bool operator==(const MyCircle&) const;
	bool operator==(const MyShape&) const;

	MyCircle& operator=(const MyCircle& crl_src);

	virtual float GetSquare();
};
