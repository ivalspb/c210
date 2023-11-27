#pragma once
#include "MyShape.h"
#include <fstream>

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
	friend ifstream& operator>>(ifstream& file_stream, List& list);
	friend ofstream& operator<<(ofstream& file_stream, List& list);

	Node Head, Tail;
	size_t m_size;

	bool GreaterBySquare(Node* node1,Node* node2);
	bool GreaterByColor(Node* node1, Node* node2);
	void SwapNode(Node* node1, Node* node2);

public:
	static const enum SortType { AREA, COLOR /* .... */ };

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
	List& operator=(List&&) noexcept;

	void SortMyList(SortType);

	const size_t GetSize() const;
	Node* GetFirstAdr() const;
	Node* GetNextAdr(const Node*) const;
	MyShape& GetShape(Node*) const;
};

