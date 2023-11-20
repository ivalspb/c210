#pragma once

#include "Point.h"

class MyShape
{
public:
	enum MyColor { BLACK, RED, GREEN, BLUE };
	enum MyStyle { SOLID, DOTTED };
protected:
	MyColor color;
	size_t thickness;
	MyStyle line_type;
public:
	MyShape();
	MyShape(MyColor color, size_t thickness, MyStyle line_type);
	//virtual ~MyShape();
	//так как объекты наследники могут быть разных типов, надо виртуальный деструктор если объекты динамические

	void GetAll(MyColor& shape_color, size_t& shape_thickness, MyStyle& shape_line) const;
	void SetAll(MyColor const shape_color,
		size_t const shape_thickness, MyStyle const shape_line);
	
	virtual float GetSquare()=0;//обязываем каждого наследника реализовывать чисто виртуальный метод

	virtual bool operator==(const MyShape&) const;
	virtual MyShape& operator=(const MyShape& shp_src);
	virtual MyShape& operator=(MyShape&& tmp_shp_src);
};

