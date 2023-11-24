//------------------------------------------------------------------------------
// ��������� ������������� ������
//------------------------------------------------------------------------------
#include "MyRect.h"
#include "MyCircle.h"
#include "List.h"
#include <tchar.h>

const char* sep = "------------------------------------\n";


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(0, "Russian");

	//
	// 1. ������� ������
	//
	List ls1;
	
	ls1.AddToTail(MyCircle(1, 1, 1, MyShape::BLACK));	//��������� �������� � ������
	ls1.AddToTail(MyCircle(5, 5, 5, MyShape::RED));
	ls1.AddToTail(MyRect(2, 3, 4, 5, MyShape::RED));
	ls1.AddToTail(MyRect(4, 6, 8, 10, MyShape::GREEN));
	ls1.AddToTail(MyCircle(2, 2, 2, MyShape::BLACK));
	ls1.AddToTail(MyRect(3, 5, 6, 7, MyShape::GREEN));
	std::cout << ls1;								//������� ������	

	ls1.RemoveOne(MyCircle(5, 5, 5, MyShape::RED));		// ������� ������ �������, ������ ���������
	std::cout << sep << endl;
	std::cout << ls1; 
	ls1.RemoveOne(MyRect(4, 6, 8, 10, MyShape::GREEN));
	std::cout << sep << endl;
	std::cout << ls1;
	
	//
	// 2. ����������� ���� ��� ������ ����������� ���������	
	//
	List ls2 = ls1;	
	List ls3 = ls2;
	std::cout << sep << endl;
	std::cout << ls2; 

	ls2.AddToHead(MyCircle(5, 5, 5, MyShape::RED));
	ls2.AddToHead(MyRect(5, 7, 9, 11, MyShape::BLACK));

	std::cout << sep << endl;
	std::cout << ls2;	
	ls1 = ls2;			// �� "��������" ������ � "���������"
	std::cout << sep << endl;
	std::cout << ls1;
	
	ls1 = ls3;			// �� "����������" ������ � "�������"
	std::cout << sep << endl;
	std::cout << ls1 << sep;
	//
	std::cout << "3. ���������� ��� ��������� �����������\n";
	//
	List ls4 = std::move(ls2);
	std::cout << sep <<"ls4 = std::move(ls2)\n"<<sep;
	std::cout << ls4;
	std::cout << sep << endl<<"ls2=\n";
	std::cout << ls2;

	std::cout << sep << endl << "ls3 = std::move(ls4)\n";
	ls3 = std::move(ls4);
	std::cout << sep <<"ls3=" << endl;
	std::cout << ls3;
	std::cout << sep << "ls4=" << endl;
	std::cout << ls4 << sep;
	//
	std::cout << "4.  ���������� �� ����������� ������� ������\n"<<sep;
	//
	std::cout << ls3<<sep<<"sort by AREA\n"<<sep;
	ls3.SortMyList(List::AREA);
	std::cout << ls3 << sep<<"sort by color\n"<<sep;

	ls3.SortMyList(List::COLOR);
	std::cout << ls3 << sep;

	//
	// 5. �������� ����/�����
	//
	//std::ofstream fout("list.txt");
	//fout << ls3;	// ������� ������ � ����
	//fout.close();
	//	
	//std::ifstream fin("list.txt");
	//List ls5;		// ������ ������ �� �����
	//fin >> ls5;
	//fin.close();
	//
	//std::cout << ls5;
	// 
	// 6. �������������� ��������
	//
	// ...

	return 0;
}