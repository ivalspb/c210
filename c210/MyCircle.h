#pragma once
#include "MyShape.h"

class MyCircle :public MyShape
{
	Point circle_center;
	float radius;
	friend ostream& operator<<(ostream& stream, const MyCircle& circle);
public:
	MyCircle();
	MyCircle(const Point& center, const float radius,
		const MyColor = BLACK, const size_t circle_thickness = 1,
		const MyStyle circle_line_style = SOLID);
	MyCircle(const float center_x, const float center_y, const float radius,
		const MyColor circle_color = BLACK, const size_t circle_thickness = 1,
		const MyStyle circle_line_style = SOLID);
	MyCircle(const MyCircle& other_circle);

	~MyCircle();

	void SetAll(const Point& center, const float radius,
				MyColor const shape_color, size_t const shape_thickness, MyStyle const shape_line);
	void GetAll(Point& center, float& raduis,
				MyColor& shape_color, size_t& shape_thickness, MyStyle& shape_line) const;

	bool operator==(const MyCircle&) const;
	bool operator==(const MyShape&) const;

	MyCircle& operator=(const MyCircle& crl_src);

	float GetSquare();
};
