// ���������� STL: 
//stack, queue, priority_queue
//set, multiset, map, multimap

//#include "stdafx.h"
#include <stack>
#include <tchar.h>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <clocale>
#include <iostream>
#include "container.h"
#include "my_vector.h"
#include "Point.h"

using namespace std;

#define stop __asm nop

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	
	//�������� ������ ������� ��� ������ �������� stack, queue, priority_queue
	//�������� �������� �� ��, ��� ���������� ������������� ������ ������ ��� 
	//��������� ��������
	
	stack<int> s;
	randFillIntContainer(s);
	cout << "printing stack\n";
	printAdapterContainer(s);
	queue<int> q;
	randFillIntContainer(q);
	cout << "printing queue\n";
	printAdapterContainer(q);
	priority_queue<int> prq;
	randFillIntContainer(prq);
	cout << "printing priority queue\n";
	printAdapterContainer(prq);




	////////////////////////////////////////////////////////////////////////////////////
	//stack

	//�������� ���� ����� �������, �����
	//�) �������� ����� ����� ������� ��������� �������
	//�) ��� ������ �������� ��� �������, ��� � ����� ������� �������� ��� ���������� 

	vector<int> v1 = { 1,2,3,4,5 };
	cout << "\nprint vector\n" << v1;
	stack<int> s1;
	for (vector<int>::reverse_iterator i = v1.rbegin(), end = v1.rend(); i != end; ++i)
		s1.push(*i);
	cout << "\nprinting stack\n";
	printAdapterContainer(s1);
	
	


	////////////////////////////////////////////////////////////////////////////////////
	//queue

	//�������� �������, ������� �������� ��������� �� ������� ���� Point,
	//��� ���� ���� ������� ������� ���������.
	//�������� �������� ������� � ���������� ��������� ����������� front() � back()
	//���������, ��� ��������� ������� ��� ����������� ����� �������?
	
	queue < Point*, list<Point*>> ql;
	ql.push(new Point(1,1));
	ql.push(new Point(2,2));
	ql.push(new Point(3,3));
	ql.push(new Point(4,4));
	cout << "\nqueue of pointers\n"; 
	printAdapterContainer(ql);
	*(ql.front()) = { -1,1 };
	*(ql.back()) = { -2,-2 };
	printAdapterContainer(ql);
	while (!ql.empty())
	{
		delete ql.front();
		ql.pop();
	}


	////////////////////////////////////////////////////////////////////////////////////
	//priority_queue
	//�) �������� ������� � ������������, ������� ����� ������� ������ ��������� ��������� - const char*
	//�) ������������������ ������� ��� �������� � ������� ���������������� ������� � ���������� const char*
	//�) ��������� "���������������" �������� (� ������� pop() ) - ���� ��� ����������� �� ��������������, ���������:
	//		��� ������������ ��� �������?
	
	const char* ar_str[] = { "Aaa","Xxx", "Vvv" ,"Ccc", "Bbb"};
	priority_queue < const char*> pq_str0(ar_str, ar_str + sizeof(ar_str) / sizeof(ar_str[0]));
	priority_queue < const char*, vector<const char*>, lessString> pq_str(ar_str,ar_str+sizeof(ar_str)/sizeof(ar_str[0]));
	cout << "\npriority queue: \n by addres\n";
	printAdapterContainer(pq_str0);
	cout << "\nby string\n";
	printAdapterContainer(pq_str);
	stop


		////////////////////////////////////////////////////////////////////////////////////
		//set
		//a) �������� ��������� � ���������� ���� Point - ���������, ��� ���������� ����������
		//		� ������ Point (� ����� �������)
		//�) ������������ �������� ��������� � ������� �������, �������������� � ���������� ���. ������
		//�) ���������� �������� ����� ��������...
		//�) �������� ��� ���������, ������� ����� ��������� ���������� ��������
		//		���� int, �� ���������� � ������ �������
		//�) �������� � ����� ��������� �������� ��������� �� ������ �������
		//	����������, ��������, ��������� �������	(��� ����������, ���� � ������� ������� �����?)

	set<Point> st;
	st.insert(Point(2, 2));
	st.insert(Point(4, 4));
	st.insert(Point(3, 3));
	st.insert(Point(1, 1));
	printContainer(st);

	st.erase({1,1});
	st.insert(Point(0,0));
	printContainer(st);

	set<int> si1({ 1,2,3,4,5 }); 
	printContainer(si1);
	set<int> si2({ 4,5,3,1,2 });
	printContainer(si2);
	v1.push_back(7);
	si1.insert(v1.begin(), v1.end());
	printContainer(si1);


	////////////////////////////////////////////////////////////////////////////////////
	//map, multiset
	//�) �������� map, ������� ������ ���� "�������, ��������" - pair<const char*, int>,
	//	��� ���� ������ �������� ���������� ����������
	//�) ��������� ��������� ���������� ����������� operator[] � insert()
	//�) ������������ ����������

	map<const char*, int> m;
	m["Ivanova"] = 100;
	m["Sidorov"] = 150; 
	m.insert({ { "Kolmogorov",50 },{"Zadornov",200} });
	printContainer(m);
	//�) �������� ���� �� ������ �� ����� (���� "�������", ����� ����� => ����� "�������")
	if(m.find("Ivanova")!=m.end())
	{
		int tmp_salary = m["Ivanova"];
		m.erase("Ivanova");
		m["Petrova"] = tmp_salary;
	}
	printContainer(m);
	stop




		//�) ����������� ����� �������� ������ � ���������� ���� string.
		//�������� (� ������������ ��� ��������) map<string, int>, ������� �����
		//��������� ������������� �� �������� ������ �
		//���������� ���������� ������ ������ � �������

	vector<string> vStr = { "Ddd", "Aaa","Bbb","Aaa","Ccc","Aaa","Bbb","Ddd" };
	vector<string>::const_iterator i = vStr.begin(), end = vStr.end();
	map<string, size_t> wrd_counter;
	for (; i != end; ++i)
	{
		cout << *i << " ";
		++wrd_counter[*i];
	}
	printContainer(wrd_counter);

		//�) 
		//����� ������:
	const char* words[] = {"Abba", "Alfa", "Beta", "Beauty"};
		//�������� map, � ������� ������ ����� ����� ��������������� ������������ 
		//��������������� ������������� ����, ������������ � ���� �����.
		//���������: �� ����� ������� ����� ����� � ��� �� ������
	
	map<char, set<const char*,lessString>> alphabet_words;
	//map<char, set<const char*>> alphabet_words;

	for (size_t i = 0; i < sizeof(words) / sizeof(words[0]); ++i)
	{
		alphabet_words[words[i][0]].insert(words[i]);
	}
	stop
		//'A' -  "Abba" "Alfa"
		//'B' -  "Beauty" "Beta"  ...
		//...


		//�)
		//�������� ��������� ������, ������� ����� ������� ���������� � ������������ �������.
		//��� ������ ������ ������ �������� ������� ��������� (�� ��������). ��� ���� 
		//������� ����� �������������
		//���� ������ ���� ������ ���� ����������� �� ������
		//
		//������ 

	map<size_t, multiset<const char*, lessString>> st_groups;
	st_groups[1] = { "Sidorov","Ivanov","Petrov" };
	st_groups[2] = { "Nazarov","Bunina","Sergeev","Arkadov" };
	stop

		////////////////////////////////////////////////////////////////////////////////////
		//multimap
		//�) �������� "�����-�������" �������, ��� ������ � ���� �� ����� ����� ���������������
		//		��������� ������� �������� - pair<string,string>, ��������: strange: �����, ��������...
		//�) ��������� ������� ������ � ������� ������ insert ��� ������������������ � ������� 
		//		���������������� ������� ���� (���� ����� �������������� ��� ��������� � ������� ������� make_pair)
		//�) �������� ��� ���������� ������� �� �����
		

	multimap<string, string> en_ru_dic;
	en_ru_dic.insert({ "strange","�����" });
	en_ru_dic.insert({ "strange","��������" });
	en_ru_dic.insert({ "alphabet","�������" });
	en_ru_dic.insert({ "notebook","�������� ������" });
	en_ru_dic.insert({ "notebook","�������" });
	en_ru_dic.insert({ "notebook","�������" });
	en_ru_dic.insert({ "notebook","�������" });


	for (multimap<string, string>::const_iterator i = en_ru_dic.begin(), end = en_ru_dic.end();	i != end; ++i)
	{
		cout << i->first << " " << i->second << endl;
	}
	cout<<"�) �������� �� ����� ������ �������� \"���������\" ��� ��������� �����. ���������: ��� ���������� ���������\n";
	cout << "���������� ����� ������������ ������ lower_bound() � upper_bound()\n";

	string word_to_translate = "notebook";
	for(multimap<string,string>::const_iterator i=en_ru_dic.lower_bound(word_to_translate),end=en_ru_dic.upper_bound(word_to_translate);i!=end;++i)
		cout <<  i->second << endl;
  

  stop

	return 0;
}

