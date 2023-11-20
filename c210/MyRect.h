#pragma once
#include "MyShape.h"
class MyRect :
    public MyShape
{
	Point vertex;
	float height, width;
	void Rect_normilize();
public:
	MyRect(Point left_top, float height, float width,
		MyColor, size_t rect_thickness, MyStyle rect_line_style);
	MyRect();//конструктор по умолчнию
	//virtual ~MyRect();
	~MyRect();

	void SetAll(const float& left_coord, const float& right_coord,
		const float& top_coord, const float& bottom_coord);
	void GetAll(float& left_coord, float& right_coord,
		float& top_coord, float& bottom_coord) const;
	void GetAll(Point& left_top, float& height, float& width) const;

};

