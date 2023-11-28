#include "List.h"
#include "MyRect.h"
#include "MyCircle.h"

List::Node::Node() :pNext(nullptr), pPrev(nullptr), m_pData(nullptr)
{
}

List::Node::~Node()
{
	delete m_pData;
	if (pPrev) 
		pPrev->pNext = pNext;
	if (pNext) 
		pNext->pPrev = pPrev;
}

// встроенный объект m_pData должен стать копией объекта, на который указывает p_shape
List::Node::Node(Node* p_node_to_paste, const MyShape&  p_shape)
{
	m_pData= &p_shape.Clone();
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

bool List::GreaterBySquare(Node* p_node1, Node* p_node2)
{
	return p_node1->m_pData->GetSquare()> p_node2->m_pData->GetSquare();
}

bool List::GreaterByColor(Node* node1, Node* node2)
{
	return node1->m_pData->GetColor()>node2->m_pData->GetColor();
}

void List::SwapNode(Node* node1, Node* node2)
{
	if ((node1 != node2)&&node1&&node2)
	{
		//swap only pointers
		Node** n1pn = &node1->pPrev->pNext,
			** n2pn = &node2->pPrev->pNext,
			** n1np = &node1->pNext->pPrev,
			** n2np = &node2->pNext->pPrev,
			* ntmp;
		*n1pn = node2;
		*n2pn = node1;
		*n1np = node2;
		*n2np = node1;
		ntmp = node1->pPrev;
		node1->pPrev = node2->pPrev;
		node2->pPrev = ntmp;
		ntmp = node1->pNext;
		node1->pNext = node2->pNext;
		node2->pNext = ntmp;

	}
}


void List::SortMyList(SortType sort_by)
{
	bool(List:: * p_greater_func)(Node*, Node*) = nullptr;
	switch (sort_by)
	{
	case List::AREA:
		p_greater_func = &List::GreaterBySquare;
		break;
	case List::COLOR:
		p_greater_func = &List::GreaterByColor;
	}
	//sorting
	
	for (int i = 0; i < m_size-1; i++)
	{
		Node* i_node = Head.pNext;
		for(int k=0;k<i;k++)
		{
			i_node = i_node->pNext;
		}
		Node* min_node = i_node;
		Node* j_node = i_node->pNext;
		for (int j = i + 1; j < m_size; j++)
		{
			if (!(this->*p_greater_func)(j_node, min_node))
				min_node = j_node;
			j_node = j_node->pNext;
		}
		SwapNode(i_node, min_node);
	}


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
			//Замечание 1: Но!Механизм обработки исключений дорогой ⇒ 
			/*Следует отметить, что целью обработки исключений является решение «нелокальных» по своей природе проблем.
				Поэтому, если проблема может быть решена локально, почти всегда так ее и следует решать.*/
			try
			{
				*pThis->m_pData = *pOther->m_pData;
			}
			catch (const char* err_msg)//может создать приватный метод вместо этого?
			{
				delete pThis->m_pData;
				pThis->m_pData = &pOther->m_pData->Clone();//создаем новый экземпляр фигуры в памяти и сахраняем адрес на него
			}
			pOther = pOther->pNext;
			pThis = pThis->pNext;
		}
		while ((pOther != &source_list.Tail)&&(pOther->m_pData!=nullptr))
		{
			new Node(Tail.pPrev, *pOther->m_pData);
			pOther = pOther->pNext;
		}
		m_size = source_list.m_size;
	}
	return *this;
}

List& List::operator=(List&& source_tmp_list) noexcept
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
	return *current_node_adr->m_pData;
}

ostream& operator<<(ostream& stream, List& list)
{
	if (list.GetSize() > 0)
	{
		List::Node* p_node = list.GetFirstAdr();
		for (size_t i = 0; i < list.GetSize(); i++)
		{
			stream << "Node #" << i + 1 << " contains ";
			if (typeid(list.GetShape(p_node)) == typeid(MyCircle)) 
			{
				stream << "Circle:\n";
				stream << static_cast<MyCircle&>(list.GetShape(p_node)) << endl;

			}
			else 
			{
				stream << "Rectangle:\n";
				stream << static_cast<MyRect&>(list.GetShape(p_node))  << endl;
			}
					
			p_node = list.GetNextAdr(p_node);
		}
	}
	return stream;
}

ofstream& operator<<(ofstream& stream, List& list)
{
	if (list.GetSize() > 0)
	{
		List::Node* p_node = list.GetFirstAdr();
		for (size_t i = 0; i < list.GetSize(); i++)
		{
			if (typeid(list.GetShape(p_node)) == typeid(MyCircle))
				stream << static_cast<MyCircle&>(list.GetShape(p_node)) << endl;
			else
				stream << static_cast<MyRect&>(list.GetShape(p_node)) << endl;
			p_node = list.GetNextAdr(p_node);
		}
	}
	return stream;
}

ifstream& operator>>(ifstream& file_stream, List& list)
{
	while (!file_stream.eof())
	{
		char figure_type[9];
		file_stream >> figure_type;
		if (strcmp(figure_type, "MyCircle") == 0)
		{
			MyCircle cur_circle;
			float x, y, r;
			char color_str[6], style[7];
			int thickness;
			MyShape::MyColor color;
			MyShape::MyStyle line_style;
			file_stream >> x >> y >> r >> color_str >> thickness >> style;
			
			if (strcmp(color_str, "BLACK") == 0) color = MyShape::MyColor::BLACK;
			else if (strcmp(color_str, "WHITE") == 0) color = MyShape::MyColor::WHITE;
			else if (strcmp(color_str, "RED") == 0) color = MyShape::MyColor::RED; 
			else if (strcmp(color_str, "GREEN") == 0) color = MyShape::MyColor::GREEN;
			else if (strcmp(color_str, "BLUE") == 0) color = MyShape::MyColor::BLUE;

			if (strcmp(style, "SOLID") == 0) line_style = MyShape::MyStyle::SOLID;
			else if (strcmp(style, "DOTTED") == 0) line_style = MyShape::MyStyle::DOTTED;

			cur_circle.SetAll({ x,y }, r, color, thickness, line_style);
			list.AddToTail(cur_circle);
		}
		else if (strcmp(figure_type, "MyRect") == 0)
		{
			MyRect cur_rect;
			float x, y, h,w;
			char color_str[6], style[7];
			int thickness;
			MyShape::MyColor color;
			MyShape::MyStyle line_style;
			file_stream >> x >> y >> h>>w >> color_str >> thickness >> style;

			if (strcmp(color_str, "BLACK") == 0) color = MyShape::MyColor::BLACK;
			else if (strcmp(color_str, "WHITE") == 0) color = MyShape::MyColor::WHITE;
			else if (strcmp(color_str, "RED") == 0) color = MyShape::MyColor::RED;
			else if (strcmp(color_str, "GREEN") == 0) color = MyShape::MyColor::GREEN;
			else if (strcmp(color_str, "BLUE") == 0) color = MyShape::MyColor::BLUE;

			if (strcmp(style, "SOLID") == 0) line_style = MyShape::MyStyle::SOLID;
			else if (strcmp(style, "DOTTED") == 0) line_style = MyShape::MyStyle::DOTTED;

			cur_rect.SetAll( x, x+h, y , y+w , color, thickness, line_style);
			list.AddToTail(cur_rect);
		}
	}
	return file_stream;
}


//ifstream& operator>>(ifstream& file_stream, List& list)
//{
//	if(file_stream.is_open())
//	{
//		while (!file_stream.eof())
//		{
//			char first_str[30], shp_str[10];
//			MyShape* tmp_shp = new MyRect;
//			try
//			{
//				file_stream.getline(first_str, 30);
//				strncpy_s(shp_str,30, first_str + 17, 10);
//				shp_str[9] = 0;
//
//				if (strcmp(shp_str, "Rectangle") == 0)
//				{
//					float left_coord, right_coord, top_coord, bottom_coord;
//					MyShape::MyColor shape_color;
//					size_t shape_thickness;
//					MyShape::MyStyle shape_line;
//					char second_str[40], color_str[6],style_str[7];
//					file_stream.getline(second_str, 40);
//					
//					/*sscanf_s(second_str, "(%f,\0x20%f)\0x20h=\0x20%fw=\0x20%f\t%5s\t\0x20%d\t%6s",
//						&left_coord, &top_coord, &bottom_coord, &right_coord,
//						color_str,7, &shape_thickness, style_str,8);*/
//
//					second_str>>
//
//					//переводим полученные ширину и длинну в координаты для соответсвующего конструктора
//					bottom_coord += top_coord;
//					right_coord += left_coord;
//					//переводим цвет и тип линии в соотв тип enum из строки
//					if (strcmp(color_str, "WHITE") == 0) shape_color = MyShape::WHITE;
//					else if (strcmp(color_str, "BLACK") == 0) shape_color = MyShape::BLACK;
//					else if (strcmp(color_str, "RED") == 0) shape_color = MyShape::RED;
//					else if (strcmp(color_str, "GREEN") == 0) shape_color = MyShape::GREEN;
//					else if (strcmp(color_str, "BLUE") == 0) shape_color = MyShape::BLUE;
//					else throw("Bad rect colour!");
//				
//					if (strcmp(style_str, "SOLID") == 0) shape_line = MyShape::SOLID;
//					else if (strcmp(style_str, "DOTTED") == 0) shape_line = MyShape::DOTTED;
//					else throw("Bad rect line style!");
//
//					static_cast<MyRect*>(tmp_shp)->SetAll(left_coord, right_coord, top_coord, bottom_coord,
//						shape_color, shape_thickness, shape_line);
//					list.AddToTail(*tmp_shp);
//				}
//				else if (strcmp(shp_str, "Circle:  ") == 0)
//					{
//					float x_center, y_center, radius;
//					MyShape::MyColor shape_color;
//					size_t shape_thickness;
//					MyShape::MyStyle shape_line;
//					char second_str[40], color_str[6], style_str[7];
//					file_stream.getline(second_str, 40);
//					sscanf_s(second_str, "(%f,\0x20%f)\0x20r=\0x20%f\t%5s\t\0x20%d\t%6s",
//						&x_center, &y_center, &radius,
//						color_str,7,&shape_thickness, style_str,8);
//					if (strcmp(color_str, "WHITE") == 0) shape_color = MyShape::WHITE;
//					else if (strcmp(color_str, "BLACK") == 0) shape_color = MyShape::BLACK;
//					else if (strcmp(color_str, "RED") == 0) shape_color = MyShape::RED;
//					else if (strcmp(color_str, "GREEN") == 0) shape_color = MyShape::GREEN;
//					else if (strcmp(color_str, "BLUE") == 0) shape_color = MyShape::BLUE;
//					else throw("Bad circle colour!");
//
//					if (strcmp(style_str, "SOLID") == 0) shape_line = MyShape::SOLID;
//					else if (strcmp(style_str, "DOTTED") == 0) shape_line = MyShape::DOTTED;
//					else throw("Bad circle line style!");
//
//					static_cast<MyCircle*>(tmp_shp)->SetAll({ x_center, y_center },radius,
//						shape_color, shape_thickness, shape_line);
//					list.AddToTail(*tmp_shp);
//					}
//				else throw("Bad shape type!");
//			}
//			catch (char* err_msg)
//			{
//				std::cout << "Error reading list from file:\n" << err_msg;
//				throw("Error reading list from file");//утечка tmp_shp?
//			}
//			delete tmp_shp;
//
//
//		}
//	}
//}


