#pragma once

#include <stdexcept>
#include <iostream>
using namespace std;

template<typename T>
class MyStack2
{
	T p_data;
	static MyStack2<T>* pNext;
	static size_t m_size;

public:
	MyStack2();
	MyStack2(const MyStack2& other_stack_list);
	//MyStack2(const MyStack2&& temp_stack_list);
	MyStack2& operator=(const MyStack2& source_stack_list);
	MyStack2& operator=(MyStack2&& temp_src_list_stack);
	~MyStack2();
	
	void push(const T& elem_to_push);
	T& pop();

	template<typename T>
	friend ostream& operator<<(ostream& out, const MyStack2<T>& stack_to_print);
};

template<typename T>
inline MyStack2<T>::MyStack2():p_data(),pNext(nullptr),m_size(0){}//по дефолту создаем пустой стек


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
			this->push(pOther->p_data);
			pOther = pOther->pNext;
		}
	}
	return *this;
}

template<typename T>
inline MyStack2<T>& MyStack2<T>::operator=(MyStack2<T>&& temp_src_list_stack)
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
	//MyStack2<T>* tmp_node = malloc(MyStack2<T>);
	MyStack2<T>* tmp_node = new MyStack2<T>;
	tmp_node->p_data= new T(e);
	tmp_node->pNext = this;
	this = tmp_node;
}

template<typename T>
inline T& MyStack2<T>::pop()
{
	// TODO: вставьте здесь оператор return
}


