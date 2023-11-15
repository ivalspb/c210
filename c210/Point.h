#pragma once
#include <iostream>

using namespace std;


class Point
	{
		float x, y;

		friend Point& operator-=(Point& minuend, const Point& subtrahend);
		friend Point& operator-=(Point& minuend, const float subtrahend);
		friend Point operator+(const float p1, const Point& p2);

		friend Point operator-(const Point& p1, const Point& p2);
		friend Point operator-(const float p1, const Point& p2);
		friend Point operator-(const Point& p1, const float p2);

		friend Point operator-(const Point& p1);

		friend ostream& operator<<(ostream&, const Point&);

	public:
		Point();
		Point(float, float);
		//конструкторы копирования и перемещения а также деструктор устраивают автоматические
		//их можно создать только чтобы заглянуть под капот создания и уничтожения объектов

		Point& operator+= (const Point& inc_point);
		Point& operator+= (const float incr);

		Point operator+(const Point& p2) const;
		Point operator+(const float p2) const;

		const Point& operator+() const;

		bool operator==(const Point&) const;

	};



