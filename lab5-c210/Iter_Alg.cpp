// Iter_Alg.cpp : Defines the entry point for the console application.
//
//���������. ����������� ���������. ���������.

#include <iostream>
#include <tchar.h>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include "Point.h"
#include "container.h"
#include "my_vector.h"

using namespace std;	
#define	  stop __asm nop


int _tmain(int argc, _TCHAR* argv[])
{

	///////////////////////////////////////////////////////////////////

		//������� 1. ���������

		//����������� ���������. ����������� set<Point>. ���������, ���
		//����� ����������� � ������ Point. �������� ������, �������� �������� 
		//�������� ������� ��������� set, �� ����������� �� ��������
	set<Point> s1;
	s1.insert(Point(1, 1));
	s1.insert(Point(2, 2));
	s1.insert(Point(0, 0.3));
	s1.insert(Point(4, 4));
	//printContainer(s1);
	vector<Point> v1(s1.rbegin(), s1.rend());
	//printContainer(v1);
	//��������� ���������. � ������� ostream_iterator �������� ����������
	//vector � set �� ����������� ������� �� �����.
	//cout << endl<<s1 << endl<<v1<<endl;

	copy(v1.begin(), v1.end(), ostream_iterator<Point>(cout, " ")); cout << endl;
	copy(s1.begin(), s1.end(), ostream_iterator<Point>(cout, " "));
	//��������� �������. � ������� ������������ ���������:
	//back_inserter()
	fill_n(back_inserter(v1), 2, Point(5, 5));
	//front_inserter()
	list<Point>l1;
	copy(v1.begin(), v1.end(), front_inserter(l1));
	printContainer(l1);
	//inserter()
	copy(l1.rbegin(), l1.rend(), inserter(v1,v1.begin()));
	printContainer(v1);
	//���������� ������� �������� �������� � ����� �� ��������� �����������. ���������:
	//����� �� ���������� ������� ����� ������������ � ������ �����������.



///////////////////////////////////////////////////////////////////

	//������� 2. ���������� ��������� (������������ ���� <algorithm>). ���������.

	// �������� for_each() - ����� �������� ������� ��� ������� �������� ����� ������������������
	//(������, vector, list...)
	//� ������� ��������� for_each � ����� ������������������ � ���������� ������ ����
	//������������ �������� ���������
	//��������� : ������� ���������� ������� ���������� ��� ������

	for_each(v1.begin(), v1.end(), out<Point>);


	stop

		//� ������� ��������� for_each � ����� ������������������ � ���������� ���� Point
		//�������� "����������" �� ��������� �������� (����� �������� ���� ����� ����������� 
		//��� ������) � �������� ��������� � ������� ����������� ���������
	cout << "\naddPi\n";
	for_each(l1.begin(), l1.end(), addPi<Point>);
	for_each(l1.begin(), l1.end(), out<Point>);

	//� ������� ��������� find() ������� � ����� ������������������ ��������� Point
	//��� ��������� �� ������� Point � ��������� ���������.

	vector<vector<Point>::iterator> vi;
	Point p1(1, 1);
	vector<Point>::iterator it=find(v1.begin(),v1.end(), p1);
	while (it != v1.end())
	{
		fill_n(back_inserter(vi), 1, it);
		it = find(++it, v1.end(),p1);
	}

	stop

		//� ������� ��������� sort() ������������ ����� ������������������ ��������� Point. 
		////�� ��������� �������� ��������� ������������������ �� �����������.
		//��� ������ ���� ���������� � ������ Point?
		// ���������: ���������� �������� sort �� �������� �� �������, ��� ���
		//��� ���� �� �� ���������� => ��� ������ ���������� ����������� ������� ������!!!

	cout << "\nuntil sorted\n" << v1;
	sort(v1.begin(), v1.end());
	cout << "\nafter sorted\n" << v1;
	stop
		//� ������� ��������� find_if() ������� � ����� ������������������ ��������� Point
		//�������� �� ������� Point, ��������������� �������: ���������� x � y ����� � ����������
		//[-n, +m].

	it = find_if(v1.begin(), v1.end(), in_n_m);
	stop
	//� ������� ��������� sort() ������������ ����� ������������������ ��������� Rect,
	//���������� �������������� �� �������� ������ �� ������ ���������.
	






	{//transform
		//�������� �������, ������� � ������� ��������� transform ��������� 
		//���������� ������� string � ������ �������.
		//���������: ����� string - ��� "�����" ���������, ������� ��� ����
		// ���������� ������ begin() � end()


		//��������� list ��������� string. � ������� ��������� transform ����������
		//�������� "�������" set, ����������� ������ � ������ �������
	



		stop
	}
	
	{//copy_if
		//��� ������ � ���������� ���� string. � ������� copy_if() ���������
		//������� ������� ������, ������������ � ����� "�" ��� "�", ����� � "�"...
		//��� ���� ������� ����� � �������� ������� ������ �� �����!



		stop

		//��� multimap, ���������� ����: "����� - ���������� ���� � ������"
		//pair<string, int>. � ������� copy_if ����������� ��� map-�: ������ -
		//� ������, ����������� ������ ���������� ����, 2-�� - ��������.
		std::multimap<string, int> month {
			{"January", 31}, {"February", 28}, {"February", 29}, { "March", 31},
			{"April", 30}, {"May",31}, {"June", 30}, {"July", 31}, {"August",31},
			{"September",30}, {"October", 31}, {"November",30}, {"December",31}
		};



		stop

		//������������ multimap � map-�, ��������� ���������� ���� ����� ������
		//�������, ��������� �������� ������ ���������� �� ������.
		//��� ����� ������� ������������� ��� ������ ����?


	
		stop
	}

	return 0;
}

