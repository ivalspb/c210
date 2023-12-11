#pragma once
#include <list>

using namespace std;

template <typename T>
void remove(list<T>& l, const T& e)
{
	typename list<T>::iterator it = l.begin(), it_end = l.end();
	for (; it != it_end; ++it)
		if (*it == e)
		{
			l.erase(it);
			break;
		}
}