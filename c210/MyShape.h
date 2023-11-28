#pragma once

#include "Point.h"

class MyShape
{
	friend ostream& operator<<(ostream& stream, const MyShape& shape);
	friend ofstream& operator<<(ofstream& stream, const MyShape& shape);

public:
	static enum MyColor { WHITE, BLACK, RED, GREEN, BLUE };
	static enum MyStyle { SOLID, DOTTED };
	//static const char* MyColorString[];
	//static const char* MyStyleString[];
protected:
	MyColor color=BLACK;
	size_t thickness=1;
	MyStyle line_type=SOLID;
public:
	MyShape();
	MyShape(const MyColor color, const size_t thickness, const MyStyle line_type);
	MyShape(const MyShape& other_shape);
	virtual ~MyShape();
	//так как объекты наследники могут быть разных типов, надо виртуальный деструктор если объекты динамические

	void GetAll(MyColor& shape_color, size_t& shape_thickness, MyStyle& shape_line) const;
	void SetAll(MyColor const shape_color,
		size_t const shape_thickness, MyStyle const shape_line);
	
	virtual float GetSquare()=0;//обязываем каждого наследника реализовывать чисто виртуальный метод
	virtual MyColor& GetColor();

	virtual bool operator==(const MyShape&) const;
	virtual MyShape& operator=(const MyShape& shp_src);

	virtual MyShape& Clone() const = 0 ;

	//virtual MyShape& operator=(MyShape&& tmp_shp_src);
};

