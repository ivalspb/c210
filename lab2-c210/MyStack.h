#pragma once

#include <stdexcept>
#include <iostream>
using namespace std;

template<typename T,size_t stack_max_size>
class MyStack
{
	T stack[stack_max_size];
	size_t stack_size=0;
	public:
	MyStack& operator<<(const T& a);//push stack
	MyStack& operator>>(T& a);//pop stack
	T& operator[](size_t i);//

	template<typename T, size_t stack_max_size>
	friend ostream& operator<<(ostream& out, const MyStack<T, stack_max_size>& stack);

};

template<typename T, size_t stack_max_size>
MyStack<T, stack_max_size>& MyStack<T, stack_max_size>::operator<<(const T& a)
{
	if (stack_size < stack_max_size)
	{
		stack[stack_size] = a;
		stack_size++;
		return *this;
	}
	else throw std::out_of_range("stack overflow!");
}

template<typename T, size_t stack_max_size>
MyStack<T, stack_max_size>& MyStack<T, stack_max_size>::operator>>(T& a)
{
	if (stack_size > 0) 
	{
		stack_size--;
		a= stack[stack_size];
		return *this;
	}
	else throw std::out_of_range("stack is empty!");
}

template<typename T, size_t stack_max_size>
inline T& MyStack<T, stack_max_size>::operator[](size_t i)
{
	if (i < stack_size - 1 && i >= 0)
		return stack[i];
	else throw std::out_of_range("out of stack!");
}

template<typename T, size_t stack_max_size>
ostream& operator<<(ostream& out, const MyStack<T, stack_max_size>& stack)
{
	for (size_t i = 0; i < stack.stack_size; i++) out << stack.stack[i];
	return out;
}
