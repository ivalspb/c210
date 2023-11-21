#pragma once
#include "MyShape.h"
class MyRect :
    public MyShape
{
	Point vertex;
	float height, width;
	void Rect_normilize();
	friend ostream& operator<<(ostream& stream, const MyRect& rect);
public:
	MyRect(const Point left_top, const float height, const  float width,
			const MyColor rect_color, const size_t rect_thickness,
			const MyStyle rect_line_style);
	MyRect();//конструктор по умолчнию
	MyRect(const float left_top_x, const float left_top_y,
			const float rigt_bottom_x, const float rigt_bottom_y,
			const MyColor rect_color, const size_t rect_thickness,
			const MyStyle rect_line_style);
	~MyRect();

	void SetAll(const float& left_coord, const float& right_coord,
		const float& top_coord, const float& bottom_coord, 
		MyColor const shape_color, size_t const shape_thickness, MyStyle const shape_line);
	void GetAll(float& left_coord, float& right_coord,
		float& top_coord, float& bottom_coord,
		MyColor& shape_color, size_t& shape_thickness, MyStyle& shape_line) const;
	void GetAll(Point& left_top, float& height, float& width,
		MyColor& shape_color, size_t& shape_thickness, MyStyle& shape_line) const;

	bool operator==(const MyRect&) const;
	bool operator==(const MyShape&) const;

	MyRect& operator=(const MyRect& crl_src);

	float GetSquare();

};

