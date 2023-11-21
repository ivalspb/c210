#include "List.h"
#include "MyRect.h"
#include "MyCircle.h"

List::Node::Node() :pNext(nullptr), pPrev(nullptr)
{
}

List::Node::~Node()
{
	if (pNext) pNext->pPrev = pPrev;
	if (pPrev) pPrev->pNext = pNext;
	delete m_pData;
}

// встроенный объект m_pData должен стать копией объекта, на который указывает p_shape
List::Node::Node(Node* p_node_to_paste, const MyShape&  p_shape)
{
	if (typeid(p_shape) == typeid(MyCircle))	m_pData = new MyCircle;
	else m_pData = new MyRect;
	*m_pData = p_shape;
	pPrev = p_node_to_paste;
	pNext = p_node_to_paste->pNext;
	p_node_to_paste->pNext = this;
	pNext->pPrev = this;
}

//List::Node::Node(const Node& source_node):
//	pPrev(source_node.pPrev),pNext(source_node.pNext),m_Data(source_node.m_Data)
//{}

bool List::Node::operator<(const Node& p_other_node) const
{
	return this->m_pData->GetSquare()< p_other_node.m_pData->GetSquare();
}

List::List() :m_size(0)
{
	Head.pNext = &Tail;
	Tail.pPrev = &Head;
}
List::~List()
{
	FlushList();
}
void List::AddToHead(const MyShape&  shape)
{
	new Node(&Head, shape);
	m_size++;
}
void List::AddToTail(const MyShape& shape)
{
	new Node(Tail.pPrev, shape);
	m_size++;
}


bool List::RemoveOne(const MyShape& shape)
{
	Node* p_temp = Head.pNext;
	while (p_temp != &Tail)
	{
		if (*p_temp->m_pData == shape)
		{
			m_size--;
			delete p_temp;
			return true;
		}
		p_temp = p_temp->pNext;
	}
	return false;
}
size_t List::RemoveEveryone(const MyShape& shape)
{
	size_t count_deleted_nodes = 0;
	Node* p1_temp = Head.pNext;
	while (p1_temp != &Tail)
	{
		Node* n = p1_temp->pNext;
		if (*p1_temp->m_pData == shape)
		{
			delete p1_temp;
			count_deleted_nodes++;
		}
		p1_temp = n;
	}
	m_size -= count_deleted_nodes;
	return count_deleted_nodes;
}

void List::FlushList()
{
	while (Head.pNext != &Tail)
	{
		delete Head.pNext;
	}
	m_size = 0;
}

List::List(const List& other) :m_size(other.m_size)
{
	//подготовка к копированию
	Head.pNext = &Tail;
	Tail.pPrev = &Head;
	//копирование
	Node* pThis = &Head;
	Node* pOther = other.Head.pNext;
	for (size_t i = 0; i < m_size; i++)
	{
		pThis = new Node(pThis, *pOther->m_pData);
		pOther = pOther->pNext;
	}
}

List::List(List&& other) :m_size(other.m_size)
{
	if (other.Head.pNext != &other.Tail)//проверка на пустой список
	{
		Head.pNext = other.Head.pNext;
		Tail.pPrev = other.Tail.pPrev;
		Head.pNext->pPrev = &Head;
		Tail.pPrev->pNext = &Tail;

		other.Head.pNext = &other.Tail;
		other.Tail.pPrev = &other.Head;
		other.m_size = 0;
	}
	else
	{//наш список тоже пустой
		Head.pNext = &Tail;
		Tail.pPrev = &Head;
	}
}
List& List::operator=(const List& source_list)
{
	if (&source_list != this)
	{

		for (size_t i = source_list.m_size; i < m_size; i++)
		{
			delete Head.pNext;
		}

		Node* pThis = Head.pNext;
		Node* pOther = source_list.Head.pNext;

		while (pThis != &Tail)
		{
			*pThis->m_pData = *pOther->m_pData;
			pOther = pOther->pNext;
			pThis = pThis->pNext;
		}
		while (pOther != &source_list.Tail)
		{
			new Node(Tail.pPrev, *pOther->m_pData);
			pOther = pOther->pNext;
		}
		m_size = source_list.m_size;
	}
	return *this;
}
List& List::operator=(List&& source_tmp_list)
{
	if (&source_tmp_list != this)
	{
		this->FlushList();
		Head.pNext = source_tmp_list.Head.pNext;
		Tail.pPrev = source_tmp_list.Tail.pPrev;
		Head.pNext->pPrev = &Head;
		Tail.pPrev->pNext = &Tail;
		m_size = source_tmp_list.m_size;

		source_tmp_list.Head.pNext = &source_tmp_list.Tail;
		source_tmp_list.Tail.pPrev = &source_tmp_list.Head;
		source_tmp_list.m_size = 0;
	}
	return *this;
}

void List::sort()
{
	if (m_size > 1)//если в списке больше 1 узла, иначе нечего сортировать
	{
		Node** list_ar = new Node * [m_size];
		Node* pThis = &Head;
		for (size_t i = 0; i < m_size; i++)
		{
			list_ar[i] = pThis->pNext;
			pThis = pThis->pNext;
		}
		for (size_t i = 0; i < m_size - 1; i++)
		{
			size_t min_ind = i;
			for (size_t j = i + 1; j < m_size; j++)
			{
				if (*list_ar[j] < *list_ar[min_ind])
				{
					min_ind = j;
				}
			}
			pThis = list_ar[i];
			list_ar[i] = list_ar[min_ind];
			list_ar[min_ind] = pThis;
		}
		Head.pNext = list_ar[0];//крайние два узла расставляем связи вручную
		Head.pNext->pPrev = &Head;
		Head.pNext->pNext = list_ar[1];
		Tail.pPrev = list_ar[m_size - 1];
		Tail.pPrev->pNext = &Tail;
		Tail.pPrev->pPrev = list_ar[m_size - 2];
		pThis = Head.pNext->pNext;//указатель выставляем на второй узел
		for (size_t i = 1; i < m_size - 1; i++)
		{
			pThis->pPrev = list_ar[i - 1];
			pThis->pNext = list_ar[i + 1];
			pThis = pThis->pNext;
		}
	}
}

const size_t List::GetSize() const
{
	return m_size;
}
List::Node* List::GetFirstAdr() const
{
	return Head.pNext;
}
List::Node* List::GetNextAdr(const Node* current_node_adr) const
{
	return current_node_adr->pNext;
}
MyShape& List::GetShape(Node* current_node_adr) const
{
	return current_node_adr->m_pData;
}

ostream& operator<<(ostream& stream, List& list)
{
	if (list.GetSize() > 0)
	{
		List::Node* p_node = list.GetFirstAdr();
		for (size_t i = 0; i < list.GetSize(); i++)
		{
			stream << "Node #" << i + 1 << " contains circle:\n" << list.GetCircle(p_node) << endl;
			p_node = list.GetNextAdr(p_node);
		}
	}
	return stream;
}

ofstream& operator<<(ofstream& stream, List& list)
{
	if (list.GetSize() > 0)
	{
		stream << list.GetSize() << endl;
		List::Node* p_node = list.GetFirstAdr();
		for (size_t i = 0; i < list.GetSize(); i++)
		{
			stream << list.GetShape(p_node);
			p_node = list.GetNextAdr(p_node);
		}
	}
	return stream;
}

List::List(ifstream& file_stream) :m_size(0)
{
	size_t my_size = 0;
	file_stream >> my_size;
	Head.pNext = &Tail;
	Tail.pPrev = &Head;
	float x, y, r;
	for (size_t i = 0; i < my_size; i++)
	{
		file_stream >> x >> y >> r;
		this->AddToTail({ x,y,r });
	}
}
