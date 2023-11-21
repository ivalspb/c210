//------------------------------------------------------------------------------
// ��������� ������������� ������
//------------------------------------------------------------------------------
#include "MyRect.h"
#include "MyCircle.h"
#include "MyList.h"

const char* sep = "------------------------------------\n";

enum SortType { AREA, COLOR /* .... */ };

int _tmain(int argc, _TCHAR* argv[])
{
	//
	// 1. ������� ������
	//
	MyList ls1;
	
	ls1.AddToTail(MyCircle(1, 1, 1, MyShape::BLACK));	//��������� �������� � ������
	ls1.AddToTail(MyCircle(5, 5, 5, MyShape::RED));
	ls1.AddToTail(MyRect(2, 3, 4, 5, MyShape::RED));
	ls1.AddToTail(MyRect(4, 6, 8, 10, MyShape::GREEN));
	ls1.AddToTail(MyCircle(2, 2, 2, MyShape::BLACK));
	ls1.AddToTail(MyRect(3, 5, 6, 7, MyShape::GREEN));
	std::cout << ls1;								//������� ������	

	ls1.Remove(MyCircle(5, 5, 5, MyShape::RED));		// ������� ������ �������, ������ ���������
	std::cout << ls1; 
	ls1.Remove(MyRect(4, 6, 8, 10, MyShape::GREEN));
	std::cout << ls1;
	
	//
	// 2. ����������� ���� ��� ������ ����������� ���������	
	//
	MyList ls2 = ls1;	
	MyList ls3 = ls2;
	std::cout << ls2; 

	ls2.AddToHead(MyCircle(5, 5, 5, MyShape::RED));
	ls2.AddToHead(MyRect(5, 7, 9, 11, MyShape::BLACK));
	
	std::cout << ls2;	
	ls1 = ls2;			// �� "��������" ������ � "���������"
	std::cout << ls1;	
	
	ls1 = ls3;			// �� "����������" ������ � "�������"
	std::cout << ls1 << sep;	
	//
	// 3. ���������� ��� ��������� �����������	
	//
	MyList ls4 = std::move(ls2);
	std::cout << ls4; 
	std::cout << ls2; 	

	ls3 = std::move(ls4);
	std::cout << ls3; 
	std::cout << ls4 << sep;
	//
	//4.  ���������� �� ����������� ������� ������
	//
	std::cout << ls3;
	ls3.SortMyList(AREA);
	std::cout << ls3 << sep;

	ls3.SortMyList(COLOR);
	std::cout << ls3 << sep;

	//
	// 5. �������� ����/�����
	//
	std::ofstream fout("list.txt");
	fout << ls3;	// ������� ������ � ����
	fout.close();
		
	std::ifstream fin("list.txt");
	MyList ls5;		// ������ ������ �� �����
	fin >> ls5;
	fin.close();
	
	std::cout << ls5;
	// 
	// 6. �������������� ��������
	//
	// ...

	return 0;
}