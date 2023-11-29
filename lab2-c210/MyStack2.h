#pragma once

#include <stdexcept>
#include <iostream>
using namespace std;

template<typename T>
class MyStack2
{
public:
	template<typename T>
	class Node
	{
		T p_data;
		Node* pNext;
		template<typename T> friend class MyStack2;

		template<typename T>
		friend ostream& operator<<(ostream& out, const Node<T>& node_to_print);
	public:
		Node() :p_data(nullptr), pNext(nullptr) {};
		~Node();//удаляться в стеке может только голова, из середины удаление исключено
		Node(const Node& other_node)
		{

		};
		Node(Node&& other_node);
		Node& operator=(const Node& other_node);
		Node& operator=(Node&& tmp_other_node);

	};
private:
	template<typename T> Node<T> Head;

public:
	MyStack2();
	MyStack2(const MyStack2& other_stack_list);
	MyStack2(const MyStack2&& temp_stack_list);
	MyStack2& operator=(const MyStack2& source_stack_list);
	MyStack2& operator=(MyStack2&& temp_src_list_stack);
	~MyStack2();
	
	void push(const T& elem_to_push);
	T& pop();

	template<typename T>
	friend ostream& operator<<(ostream& out, const MyStack2<T>& stack_to_print);
};



template<typename T>
inline MyStack2<T>::MyStack2(){}//по дефолту создаем пустой стек

template<typename T>
inline MyStack2<T>::MyStack2(const MyStack2& other_stack_list)
{
	if (other_stack_list)//если источник не пустой
	{
		MyStack2* pCurrent_other = &other_stack_list, *pCurrent=this;
		do
		{
			p_data = new T(pCurrent_other->p_data);

		}
		while()
	}
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
inline MyStack2<T>::~MyStack2()
{
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


