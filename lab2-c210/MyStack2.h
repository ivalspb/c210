#pragma once

#include <stdexcept>
#include <iostream>
using namespace std;

template<typename T>
class MyStack2
{
	class Node2
	{
		T data;
		Node2* pNext;
		friend class MyStack2<T>;
		
		
	public:

		template<typename T>
		friend ostream& operator<< (ostream& out, const typename MyStack2<T>& stack_to_print);
		/*template<typename T2>
		friend ostream& operator<< (ostream& stream, const typename MyStack2<T2>::Node2& node_to_print);*/

		Node2();
		~Node2();
		Node2(const T& data_src);
		Node2(T&& data_tmp);
		};
	size_t m_size;
	Node2 Head;
	friend class Node2;

public:
	MyStack2();
	MyStack2(const MyStack2& other_stack_list);
	MyStack2(MyStack2&& temp_stack_list);
	MyStack2& operator=(const MyStack2& source_stack_list);
	MyStack2& operator=(MyStack2&& temp_src_list_stack);
	~MyStack2();
	
	void push(const T& elem_to_push);
	void push(T&& tmp_e);
	T pop();

	/*template<typename T2>
	friend ostream& operator<< (ostream& stream, const typename MyStack2<T2>::Node2& node_to_print);*/

	template<typename T>
	friend ostream& operator<< (ostream& out, const MyStack2<T>& stack_to_print);
};


template<typename T>
inline MyStack2<T>::Node2::Node2():data(T()),pNext(nullptr){}

template<typename T>
inline MyStack2<T>::Node2::~Node2()
{
	/*if (this) this = this->pNext;
	else throw std::out_of_range("try to del empty node!");*/
}

template<typename T>
inline MyStack2<T>::Node2::Node2(const T& data_src):data(data_src),pNext(nullptr){}

template<typename T>
inline MyStack2<T>::Node2::Node2(T&& data_tmp) : data(std::move(data_tmp)), pNext(nullptr) {}

template<typename T>
inline MyStack2<T>::MyStack2()
{
	Head.pNext = nullptr;
	m_size = 0;
}


template<typename T>
inline MyStack2<T>::MyStack2(const MyStack2<T>& other_stack_list) :m_size(other_stack_list.m_size)
//в голове данных не будет, это просто страж
{
	if (other_stack_list.m_size)//если источник не пустой
	{
		Node2* pOther = other_stack_list.Head.pNext;
		Node2* pThis = &Head;
		do
		{
			Node2* newCur=new Node2(pOther->data);
			pOther = pOther->pNext;
			pThis->pNext = newCur;
			pThis = newCur;
		} while (pOther);
	}
}

template<typename T>
inline MyStack2<T>::MyStack2(MyStack2&& temp_stack_list):m_size(temp_stack_list.m_size)
{
	Head.pNext = temp_stack_list.Head.pNext;
	temp_stack_list.m_size = 0;
	temp_stack_list.Head.pNext = nullptr;
}

template<typename T>
inline MyStack2<T>& MyStack2<T>::operator=(const MyStack2<T>& source_stack_list)
{
	if (&source_stack_list != this)
	{
		//стек приемник больше копируемого, удаляем лишнее
		size_t this_size = m_size;
		for (size_t i = source_stack_list.m_size; i < this_size; i++) 
			pop();
		//проходим по существующим узлам стека приемника
		Node2* pThis = &Head;
		Node2* pOther = source_stack_list.Head.pNext;
		while (pThis->pNext)
		{
			pThis->pNext->data = pOther->data;
			pOther = pOther->pNext;
			pThis = pThis->pNext;
		}
		//стек приемник меньше копируемого, добавляем в приемник оставшиеся узлы
		while (pOther)
		{
			pThis->pNext = new Node2(pOther->data);
			pThis = pThis->pNext;
			m_size++;
			pOther = pOther->pNext;
		}
	}
	return *this;
}

template<typename T>
inline MyStack2<T>& MyStack2<T>::operator=(MyStack2<T>&& temp_src_list_stack)
{
	if (this != &temp_src_list_stack)
	{
		while (Head.pNext)	
		{
			pop();//очищаем список приемник
		}
		Head.pNext = temp_src_list_stack.Head.pNext;
		m_size = temp_src_list_stack.m_size;
		temp_src_list_stack.m_size = 0;
		temp_src_list_stack.Head.pNext = nullptr;
		//temp_src_list_stack.~MyStack2();
	}
	return *this;
}

template<typename T>
inline MyStack2<T>::~MyStack2()
{
	Node2* node_to_delete = Head.pNext;
	while (Head.pNext) 
	{
		Head.pNext = Head.pNext->pNext;
		delete node_to_delete;
		node_to_delete = Head.pNext;
	}
	m_size = 0;
}

template<typename T>
inline void MyStack2<T>::push(const T& e)
{
	Node2* tmp_node = new Node2(e);
	tmp_node->pNext = Head.pNext;
	Head.pNext = tmp_node;
	//Head.pNext->data= e;
	m_size++;
}

template<typename T>
inline void MyStack2<T>::push(T&& e)
{
	Node2* tmp_node = new Node2(std::move(e));
	tmp_node->pNext = Head.pNext;
	Head.pNext = tmp_node;
	//Head.pNext->data = std::move(e);
	m_size++;
}


template<typename T>
inline T MyStack2<T>::pop()
{
	if (m_size)
	{
		T res = Head.pNext->data;
		m_size--;
		Node2* node_to_delete = Head.pNext;
		Head.pNext=Head.pNext->pNext;
		delete node_to_delete;
		return res;
	}
	else throw std::out_of_range("pop from epty stack!");
}

template<typename T>
ostream& operator<< (ostream& out, const MyStack2<T>& stack_to_print)
{
	if(stack_to_print.m_size)
	{
		typename MyStack2<T>::Node2** node_ar = new typename MyStack2<T>::Node2* [stack_to_print.m_size];
		node_ar[0] = stack_to_print.Head.pNext;
		for (size_t i = 1; i < stack_to_print.m_size; i++)	
			node_ar[i] = node_ar[i - 1]->pNext;
		for (size_t i = stack_to_print.m_size; i > 0; --i) 
			out << node_ar[i-1]->data << " ";
		delete[] node_ar;
	}
	else out << "empty stack" << endl; 
	return out<<endl << "====END OF LIST========" << endl;
	//MyStack2<T> revList;//лучше добавлять не список, а просто создавать node
	//for (typename MyStack2<T>::Node2* cur = stack_to_print.Head.pNext; cur != nullptr; cur = cur->pNext)
	//{
	//	revList.push(cur->data);
	//}
	//while (revList.Head.pNext)
	//{
	//	out << revList.pop();
	//}
	//return out << endl << "====END OF LIST========"<<endl;
}

//template<typename T> 
//ostream& operator<< (ostream& stream,  const typename MyStack2<T>::Node2& node_to_print)
//{
//	if (!node_to_print.pNext)
//		return stream << node_to_print.p_data << " ";
//	else
//		stream << *node_to_print.pNext <<" ";
//	return stream << endl;
//}
