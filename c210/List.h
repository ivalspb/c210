#pragma once
#include "MyShape.h"

class List
{
	class Node
	{
		Node* pPrev;
		Node* pNext;
		MyShape *m_pData;
		friend class List;
	public:
		Node();//скорее всего понадобитс€ дл€ создани€ вспомогательных оберток Ц Ђстражейї (Head, Tail)
		Node(Node* p_node_to_paste, const MyShape& );	//конструктор, посредством которого создаваемый Node Ђподключаетс€ї в список.
		~Node();//деструктор должен Ђисключатьї уничтожаемый Node из списка

		bool operator<(const Node&) const;
	};

	friend ostream& operator<<(ostream& stream, List& list);
	//friend ofstream& operator<<(ofstream& file_stream, List& list);

	Node Head, Tail;
	size_t m_size;
public:
	List();
	~List();
	List(const List&);	//копирование, перемещение, присваивание и тд
	List(List&&);
	//List(ifstream&);

	void AddToHead(const MyShape&);
	void AddToTail(const MyShape&);
	bool RemoveOne(const MyShape&);
	size_t RemoveEveryone(const MyShape&);
	void FlushList();

	List& operator=(const List&);
	List& operator=(List&&);

	void sort();

	const size_t GetSize() const;
	Node* GetFirstAdr() const;
	Node* GetNextAdr(const Node*) const;
	MyShape& GetShape(Node*) const;
};

