#pragma once

#include <stdexcept>
#include <iostream>
using namespace std;

template<typename T>
class MyStack2
{
	T* p_data;
	size_t m_n;//?
	MyStack* pNext;
public:
	MyStack2();
	MyStack2(const MyStack2& other_stack_list);
	MyStack2(const MyStack2&& temp_stack_list);
	MyStack2& operator=(const MyStack2& source_stack_list);
	MyStack2& operator=(MyStack2&& temp_src_list_stack);
	
	void push(const T& e);
	T& pop();

};

template<typename T>
inline MyStack2<T>::MyStack2()
{
}

template<typename T>
inline MyStack2<T>::MyStack2(const MyStack2& other_stack_list)
{
}

template<typename T>
inline MyStack2<T>::MyStack2(const MyStack2&& temp_stack_list)
{
}

template<typename T>
inline MyStack2& MyStack2<T>::operator=(const MyStack2& source_stack_list)
{
	// TODO: вставьте здесь оператор return
}

template<typename T>
inline MyStack2& MyStack2<T>::operator=(MyStack2&& temp_src_list_stack)
{
	// TODO: вставьте здесь оператор return
}

template<typename T>
inline void MyStack2<T>::push(const T& e)
{
}

template<typename T>
inline T& MyStack2<T>::pop()
{
	// TODO: вставьте здесь оператор return
}
