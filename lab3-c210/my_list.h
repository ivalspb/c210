#pragma once
//#include <list>
//#include "Point.h"
//
//using namespace std;

//template <typename T>
//void remove(list<T>& l, const T& e)
//{
//	typename list<T>::iterator it = l.begin(), it_end = l.end();
//	for (; it != it_end; ++it)
//		if (*it == e)
//		{
//			l.erase(it);
//			break;
//		}
//}
//
//void remove_if(list<Point>& l)
//{
//	if (l.size())
//	{
//		list<Point>::iterator it = l.begin(), it_end = l.end();
//		for (; it != it_end; ++it)
//			if ((it->get_x() < 0) || (it->get_y() < 0))
//			{
//				l.erase(it);
//				break;
//			}
//	}
//}