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
		MyStack2<T>* pNext;
		friend class MyStack2<T>;
		template<typename T> friend ostream& operator<<(ostream& stream, const Node2& node_to_print)
		{
			return stream << node_to_print.p_data << " ";
		};
	public:
		Node2();
		~Node2();
		//Node2(Node2& other_node);
		//Node(Node&& tmp_node);
		Node2(const T& data_src);
		Node2(T&& data_tmp);
		//Node& operator=(const Node& other);
		//Node& operator=(Node&& tmp);
	};
	size_t m_size;
	Node2 Head;

public:
	MyStack2();
	MyStack2(const MyStack2& other_stack_list);
	//MyStack2(const MyStack2&& temp_stack_list);
	MyStack2& operator=(const MyStack2& source_stack_list);
	MyStack2& operator=(MyStack2&& temp_src_list_stack);
	~MyStack2();
	
	void push(const T& elem_to_push);
	void push(T&& tmp_e);
	T& pop();

	template<typename U>
	friend ostream& operator<<(ostream& out, const MyStack2<U>& stack_to_print);
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
inline MyStack2<T>::Node2::Node2(const T& data_src):data(data_src){}

template<typename T>
inline MyStack2<T>::Node2::Node2(T&& data_tmp)
{
	data = std::move(data_tmp);
}

template<typename T>
inline MyStack2<T>::MyStack2()
{
	Head.pNext = nullptr;
	m_size = 0;
}


template<typename T>
inline MyStack2<T>::MyStack2(const MyStack2<T>& other_stack_list)//в голове данных не будет, это просто страж
{
	if (other_stack_list.m_size)//если источник не пустой
	{
		MyStack2<T>* pCurrent_other = other_stack_list.pNext;
		do
		{
			MyStack2<T>* newNode = new MyStack2 <T>;
			p_data = pCurrent_other->p_data;
			newNode->pNext = this;
			this = newNode;
			m_size++;
			pCurrent_other = pCurrent_other->pNext;
		} while (pCurrent_other);
	}
}

//template<typename T>
//inline MyStack2<T>::MyStack2(const MyStack2&& temp_stack_list)
//{
//}

template<typename T>
inline MyStack2<T>& MyStack2<T>::operator=(const MyStack2<T>& source_stack_list)
{
	if (&source_stack_list != this)
	{
		//стек приемник больше копируемого, удаляем лишнее
		size_t this_size = m_size;
		for(size_t i= source_stack_list.m_size;i<this_size;i++)
		{
			MyStack2<T>* head_toDelete = this;
			this = this->pNext;
			m_size--;
			delete head_toDelete;
		}
		//проходим по существующим узлам стека приемника
		MyStack2<T>* pThis = this->pNext;
		MyStack2<T>* pOther = source_stack_list.pNext;
		while (pThis)
		{
			pThis->p_data = pOther->p_data;
			pOther = pOther->pNext;
			pThis = pThis->pNext;
		}
		//стек приемник меньше копируемого, добавляем в приемник оставшиеся узлы
		while (pOther)
		{
			MyStack2<T>* node_for_Tail = new MyStack2<T>();
			node_for_Tail->p_data= pOther->p_data;
			pThis->pNext = node_for_Tail;
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
		while (pNext)	pop();
		pNext = temp_src_list_stack.pNext;
		m_size = temp_src_list_stack.m_size;
		delete temp_src_list_stack;
		temp_src_list_stack.m_size = 0;
		temp_src_list_stack.pNext = nullptr;
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
	Node2* tmp_node = new Node2;
	tmp_node->pNext = &Head;
	Head = *tmp_node;
	Head.pNext->data= e;
	m_size++;
}

template<typename T>
inline void MyStack2<T>::push(T&& e)
{
	Node2* tmp_node = new Node2;
	tmp_node->pNext = &Head;
	Head = *tmp_node;
	Head.pNext->data = std::move(e);
	m_size++;
}


template<typename T>
inline T& MyStack2<T>::pop()
{
	if (m_size)
	{
		T res = std::move(Head.pNext->data);
		m_size--;
		Node* node_to_delete = &Head;
		Head=Head.pNext;
		delete node_to_delete;
		return res;
	}
	else throw std::out_of_range("pop from epty stack!");
}

 template<typename T> /*MyStack2<T>::*/
ostream& operator<<(ostream& out, const MyStack2<T>& stack_to_print)
{
	MyStack2<T>* pCur = stack_to_print.pNext;
	while (pCur)
	{
		out<<pCur.
	}
}
