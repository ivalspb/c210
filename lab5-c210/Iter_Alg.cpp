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
#include <functional>
#include "Point.h"
#include "container.h"
#include "my_vector.h"
#include "MyRect.h"

using namespace std;	
#define	  stop __asm nop

string MultiStrTrnsfromToLower(string s)
{
	transform(s.begin(), s.end(), s.begin(), tolower);
	return s;
}



int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(0));

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

	deque<MyRect> d_rect(5);
	for (deque<MyRect>::iterator i = d_rect.begin(); i != d_rect.end(); ++i)
		*i = MyRect(rand() % 20-10, rand() % 20-10, rand() % 20-10, rand() % 20-10);
	printContainer(d_rect);
	sort(d_rect.begin(), d_rect.end(), CompareByRectCenter);
	cout << "\nsorted by distance of center from (0,0)\n";
	printContainer(d_rect);



	{//transform
		//�������� �������, ������� � ������� ��������� transform ��������� 
		//���������� ������� string � ������ �������.
		//���������: ����� string - ��� "�����" ���������, ������� ��� ����
		// ���������� ������ begin() � end()
		string str1 = "The Test String";
		transform(str1.begin(), str1.end(), str1.begin(), tolower);

		//��������� list ��������� string. � ������� ��������� transform ����������
		//�������� "�������" set, ����������� ������ � ������ �������
	
		list<string> ls;
		ls.push_back("Xxx");
		ls.push_back("Bbb");
		ls.push_back("Yyy");
		ls.push_back("Ddd");
		ls.push_back("Eee");
		set<string> ss;
		//copy(ls.begin(), ls.end(), inserter(ss,ss.begin()));
		transform(ls.begin(), ls.end(), inserter(ss,ss.begin()), MultiStrTrnsfromToLower);
		printContainer(ls);
		printContainer(ss);
		stop
	
	
	//copy_if
		//��� ������ � ���������� ���� string. � ������� copy_if() ���������
		//������� ������� ������, ������������ � ����� "�" ��� "�", ����� � "�"...
		//��� ���� ������� ����� � �������� ������� ������ �� �����!
		vector<string> vs;
		copy(ls.begin(), ls.end(), back_inserter(vs));
		vs.push_back("eee"); vs.push_back("eEe");
		printContainer(vs);
		for (char c = 'a'; c <= 'z'; c++) 
			copy_if(vs.cbegin(), vs.cend(), ostream_iterator<string>(cout, "-> "), bind(beginFromChar, std::placeholders::_1, c));
		//copy_if(vs.cbegin(), vs.cend(), ostream_iterator<string>(cout, "-> "), [c](const string& s) {return tolower(s[0]) == c; });

		stop

		//��� multimap, ���������� ����: "����� - ���������� ���� � ������"
		//pair<string, int>. � ������� copy_if ����������� ��� map-�: ������ -
		//� ������, ����������� ������ ���������� ����, 2-�� - ��������.
		multimap<string, int> month {
			{"January", 31}, {"February", 28}, {"February", 29}, { "March", 31},
			{"April", 30}, {"May",31}, {"June", 30}, {"July", 31}, {"August",31},
			{"September",30}, {"October", 31}, {"November",30}, {"December",31}
		};

		multimap<string, int> month_odd, month_even;
		copy_if(month.cbegin(), month.cend(), inserter(month_odd, month_odd.begin()), is_odd_pair);
		copy_if(month.cbegin(), month.cend(), inserter(month_even, month_even.begin()), is_even_pair);

		stop

			//������������ multimap � map-�, ��������� ���������� ���� ����� ������
			//�������, ��������� �������� ������ ���������� �� ������.
			//��� ����� ������� ������������� ��� ������ ����?

			printContainer(month);
			printContainer(month_odd); 
			printContainer(month_even);
		stop
	}

	return 0;
}


