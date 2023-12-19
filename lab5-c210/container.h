#pragma once

#define _USE_MATH_DEFINES


#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <math.h>
#include <string>
#include <iostream>


using namespace std;

template< typename T1, typename T2>
ostream& printElemContainer(ostream& os, pair<T1, T2> const& p)
{
	return os << p.first << "|" << p.second << " ";
}

template< typename T>
ostream& printElemContainer(ostream& os, T const& p)
{
	return os << p<<" ";
}

template <typename AdapterContainer>
void printAdapterContainer(AdapterContainer c)
{
	while (!c.empty())
	{
		std::cout << c.top() << " ";
		c.pop();
	}
	std::cout <<"\n=============\n";
}


template <typename T, typename ContainerBase=deque<T>>
void printAdapterContainer(std::queue<T, ContainerBase> e)
{
	while (!e.empty())
	{
		std::cout << e.front() << " ";
		e.pop();
	}
	std::cout << "\n=============\n";
}

template <typename T, typename ContainerBase=deque<T>>
void printAdapterContainer(std::queue<T*,ContainerBase> e)//делаем копии адресов, но деинициализировать не нужно?
{
	while (!e.empty())
	{
		std::cout << *e.front() << " ";
		e.pop();
	}
	std::cout << "\n=============\n";
}


template<typename AdapterContainer>
void randFillIntContainer(AdapterContainer &c)
{
	for (int i = 0; i < 5; ++i)
		c.push(rand() % 100);
}

struct lessString{
bool operator()(const char* str1, const char* str2) const
	{ return strcmp(str1, str2) < 0; }
};

template <typename Container> 
void printContainer(const Container& x)
{
	cout << endl << typeid(x).name() << endl;
	cout << "size = " << x.size() << "\t";
	cout << "max_size = " << x.max_size() << endl;
	if (x.size())
	{
		cout << "{";
		typename Container::const_iterator it = x.cbegin(), it_end1 = --x.end();
		for (; it != it_end1; ++it)
			printElemContainer(cout, *it);
		printElemContainer(cout, *it);
		cout << "}" << endl;
	}
}



template< typename Container, typename T= typename Container::value_type>
ostream& operator<<(ostream& os, const Container& v)
{
	typename Container::const_iterator it_end = v.cend();
	typename Container::const_iterator it = v.cbegin();
	os << "{";
	for (; it != it_end; ++it)
		os << *it << " ";
	return os << "}";
}



template<typename T>
void out(T& t)
{
	cout << t<<" ";
}

template<typename T>
void addPi(T& t) 
{
	t += M_PI;
}

bool is_odd_pair(pair<string, int> p);
bool is_even_pair(pair<string, int> p);