//����������� ���������� �������� - STL 
	//���������� ����������� ���������� - vector
	//���������

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "my_vector.h"
#include "my_container.h"
#include "myString.h"
#include "Point.h"
//#include "my_list.h"

#pragma warning(disable: 4786)


using namespace std;	

#define	  stop __asm nop


int main()
{
	// ��������� ����������� ���������� vector 
	setlocale(LC_ALL, "Russian");
	//////////////////////////////////////////////////////////////////////
	//�������� ��������. 

	//�������� ��������� �������:
	//---------------------------
	//������ ������ ����� ����� - vInt � ��������� � ������� ������� size(),
	//��� ��� ������ �������. 
	vector<int> vInt;
	size_t s = vInt.size();
	
	
	//���������������� ��������� ��������, ��������� - ��� �� ���������
	//���� ���� ��������������, - ���������
	vInt.push_back(0);
	vInt.front()=1;


	//� ������� ������� push_back() � ����� ��������� ������ ������-���� ����������.
	//�� ������ �������� ����� ������� �� �������� ������� � ������� �������
	//size(), capacity(), max_size() � �������� �������� ���������. 
	//
	//���������: ��� ��� ����� �������� ����������� ��� � � ��������� ��������,
	//�������� ������ �������, ������� ��� �������, ����������� �������� ������ ����
	//������� ��� "���������" � �������� ��������� �� �������.
	for(size_t i=0;i<10;i++)
	{
		vInt.push_back(rand() % 100);
		printVector(vInt);
	}
	stop
	//������ ������������ - vDouble1 � �������� ���� ��������� ��������  �
	//��������� ��������� � ������� ���������� ���� �������. ��� �����
	//������������������� �������� �������?
	vector<double> vDouble(10);
	printVector(vDouble);
	stop
		//������ �������� ���� MyString � ��������� �������� - 5 ���������
		//� �������������� ������� �������� ������� "A"
		//C ������� ������� at() � ����� � ������� ���������
		//�������������� []  �������� �������� �����-���� ���������.
		//���������� "�����" �� ������� ������� � ������� at() �
		//� ������� []. 

	vector<MyString> vMyString(5, "A");
	vMyString[2] = "Dbc";
	try {
		vMyString.at(3) = "Abc";
		printVector(vMyString);
//		vMyString.at(5) = "error!";
	//	printVector(vMyString);
//		vMyString[5] = "error!";
	//	printVector(vMyString);
	}
	catch (const exception& e)
	{
		cerr << endl << "Caught: " << e.what() << endl;
		cerr << "Type: " << typeid(e).name() << endl;
	}
	
	stop

		//������ ������������ - vDouble3, ������� �������� ������ ���������
		// [0,5) ������� ������������ ����� dMas. �������������� ������ dMas 
		//����� ������� � �������������������!

	double dMas[5] = { 1,2,3,4,5 };
	vector<double>vDouble3(dMas, dMas + sizeof(dMas)/sizeof(dMas[0]));
	printVector(vDouble3);
	stop

		//������ ������������ - vDouble4, ������� �������� ������ ���������
		// [2,5) ������� vDouble3. 

	vector<double>vDouble4(vDouble3.begin() + 2, vDouble3.end());
	printVector(vDouble4);
	stop

		//������ ��������� ���� Point - vPoint1 �) � ��������� �������� 3. ����� �����������
		//����� ������ ��� ������� ��������?
		//b) vPoint2 � ��������� �������� 5 � ������������������ ������ ������� ������������ (1,1).

	vector<Point>vPoint1(3);
	printVector(vPoint1);
	vector<Point>vPoint2(5, { 1,1 });
	printVector(vPoint2);
	stop
		//������ ���������� �� Point - vpPoint � ��������� �������� 5
		//���������: ��� ��������� ��������� ��� ��������� "���������" �� ������� Point
	{
	vector<Point*>vpPoint(5);
	vector<Point*>::iterator it = vpPoint.begin();
	vector<Point*>::iterator itend = vpPoint.end();
	for (it; it != itend; ++it) *it = new Point;
	printVector(vpPoint);
	for (it=vpPoint.begin(); it != itend; ++it) delete *it;
	stop
	//���������: ��� ������ �� ������ �������� ������ ����� ��� �����������
		//�) ������������� ����� ��������� �������
		//�) ��� ���������� operator<< ��� Point*

	}//����� �������������� �������� ����� ����������� ��� ������ �������?


	///////////////////////////////////////////////////////////////////////
	//�������������� ������.
	//���������, ������ �� ����� ����������� ���� ��������?
		
	{
		size_t n = 10;
		vector<int> v(n);
		v.resize(n/2);
		if (v.capacity() == n) cout<<"\ncapacity is the same!\n";//true?
		printVector(v);
	}
		
	{
		int n=10;
		size_t m = 20;
		vector<int> v(n);
		v.reserve(m);
		if (v.capacity() == m) cout << "\ntrue";
		printVector(v);
	}
		
	{
		vector<int> v(3,5);
		printVector(v);
		v.resize(4,10); //��������?
		printVector(v);
		v.resize(5); //��������?
		printVector(v);
	}

	//�������� ��� "������" ������� � ����������
	//������ (�� ������ � ���� �� ����) ����. 
	//� ������ ������� �������������� ������ ��� 5 ���������, � ����� ���������
	//��� ���������� � ������� push_back.
	//������ ������ ������ ��������� ���������� ����������� push_back.
	//
	cout << "\n�������� ������, ������� �������� � �������� ���������\n";

	vector<int>v1;
	vector<int>v2;
	v1.reserve(5);
	for (size_t i = 0; i < 5;i++) v1.push_back(rand() % 10);
	printVector(v1);
	for (size_t i = 0; i < 5; i++) v2.push_back(rand() % 10);
	printVector(v2);

	//!!! shrink_to_fit - ���������� ������� �������.
	//��� ������ ������� �� ����������� ������� ��������� ��������� �������
	//�� size.

	v2.shrink_to_fit();
	printVector(v2);
	
	//�������� "����������� �������" - ������� ��������
	//����� ���������� ������ int ar[] = {11,2,4,3,5};
	int ar[] = { 11,2,4,3,5 };
	//�������� ������ �������� ��������� �������:
	//������ vv[0] - �������� 11 ��������� �� ��������� 11
	//vv[1] - �������� 2,2
	//vv[2] - �������� 4,4,4,4
	//...
	//������������ ���������� ������ ����������� ������� �� �������
	//� �������:
	
	vector<vector<int>>vv(sizeof(ar) / sizeof(ar[0]));
	for (size_t i = 0; i < sizeof(ar) / sizeof(ar[0]); i++) 
		vv[i].resize(ar[i], ar[i]);

	/*for (size_t i = 0; i < sizeof(ar) / sizeof(ar[0]); i++) 
		printVector(vv[i]);*/
	std::cout<<endl<<"<< vetcor out"<<endl << vv ;
	printContainer(vv);
	//printVector(vv);
	stop

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//������� �������� ������������������ insert().
			//���������� �������, ������� ������ ��������� ����� �������
				//� ������ ������� ������ ��� �������, ��� � ������� ������
				 //�������� ��� ���.
			//��������� ����������������� ������� - � ������ vChar2 �������� � ������ ������� ������ ������ ���
			//�������, ��� � ������� ������ ������� ��� ���.
				 //��������: vChar2 - abc 
				 //��� ������� �������� 'a' ������� ������ ���� ���������������
				 //��� ������� �������� 'q' vChar2 - qabc 
	vector<char>vChar2 = {'a','b','c'};
	printVector(vChar2);
	unic_push(vChar2, 'a');
	printVector(vChar2);
	unic_push(vChar2, 'q');
	printVector(vChar2);
	//���������� �������, ������� ������ ��������� ����� �������
		 //����� ������ ��������� �������
	//��������� ����������������� ������� - �������� ����� ������ ��������� ������� vChar2 ����� 'W'
	push_for_all(vChar2, 'W');
	printVector(vChar2);


///////////////////////////////////////////////////////////////////
	//�������� �������, ������� ������ ������� ������ ������������� ������������������.
	//��������: ���� - "qwerrrrty12222r3", ����� - "qwety1r3"
	string st = "qqwerrrrty12212233";
	vector<char>vChar3(st.begin(), st.end());
	printVector(vChar3);
	delete_not_unic_sequence(vChar3);
	printVector(vChar3);

	stop

		///////////////////////////////////////////////////////////////////

			//�������� �������� ������������������ erase()
			//�������� ������� �������� �� ������ ������� ���� ������ 
				 //��������: ���� - "qwerrrrty12222r3", ����� - "qwerty123"

	st = "qwerrrrty12222r3";
	vChar3.assign(st.begin(),st.end());
	printVector(vChar3);
	make_unic_vect(vChar3);
	printVector(vChar3);
	

///////////////////////////////////////////////////////////////////
	//�������� ����� ������ ����� �������, ����� ��� �������� �����
	//������� ��������� ������ �� ��������� ����� ��������, �� �����������
	//���� �� � �������� �������
	vector<char>vChar1(vChar3.rbegin(), vChar3.rend());
	printVector(vChar1);





///////////////////////////////////////////////////////////////////

	//������� 1. ������. ��������, ����������� ��� �������.
	//�������� ������ ������ �� ��������� Point - ptList1 � ���������
	//��� ���������� � ������� ������� push_back(),
	//push_front, insert()(
	list<Point> ptList1;
	ptList1.push_back({ 0,1 });
	ptList1.push_front({ 1,1 });
	ptList1.push_front({ -14,1.54 });
	ptList1.insert(++ptList1.begin(), { 2,2 });

	//�������� ������ �������, ������� ����� �������� ��������
	//������ ���������� �� ������. ��������� ������ ������� �� �����������
	//vector � list. ��������� - �������� �� ������� ��� ����������.
	printContainer(ptList1);

	//�������� ����� �� ������� "�����������" - reverse()

	reverse(ptList1);
	printContainer(ptList1);

	//�������� ������ ptList2 �� ��������� Point ����� �������, ����� �� ���� 
	//������ ������� ��������� ���� Point, �� �������� ��������� ������ �������������
	//�� � �������� ������� 
	list<Point> ptList2(ptList1.rbegin(), ptList1.rend());
	printContainer(ptList2);


	//������������ ������  ptList1 � ptList2 - ������� ������ list - sort()
	//�� �����������.
	//���������: ��� ������ ���� ����������� � ������ Point ��� ����, �����
	//�������� ����������
	ptList1.push_back({ 0,0 });
	ptList1.push_back({ 0,2 });
	printContainer(ptList1);
	ptList1.sort();
	printContainer(ptList1);
	ptList2.sort();
	printContainer(ptList2);
	stop

		//���������� ��������������� ������ - merge(). ����������: ���
		//��� ���� ���������� � ������ �������.
	ptList1.merge(ptList2);
	printContainer(ptList1);
	printContainer(ptList2);
	stop

		//���������� �������� �� ������ - remove()
		//��������� �� ������ ������� � ������������ ���������.
		//���������: ��� ������ ���� ����������� � ������ Point?
	ptList1.remove({ 0,2 });
	cout << "\n{0,2} removed\n";
	printContainer(ptList1);
	//���������� �������� �� ������, ���������������� ��������� �������:
	//����� �� ��������� ������������ - remove_if(). 
	ptList1.remove_if(has_negative_coord);
	printContainer(ptList1);

	//���������� �� ������ ������ ������������� ������ - unique(). 
	ptList1.unique();
	printContainer(ptList1);
	stop

		///////////////////////////////////////////////////////////////////
			//������� 2.������� � ����� ������� - ��������� deque

			//�������� ������ deque � ���������� ���� Point. � �������
			//assign ��������� deque ������� ��������� �������. � �������
			//�������������� ���� � ���������� ������� �������������� �������
			//�������� �������� ��������� �� ������
	deque<Point> dq;
	dq.assign(vPoint2.begin(), vPoint2.end());
	printContainer(dq);


	//�������� deque � ���������� ���� MyString. ��������� ��� ����������
	//� ������� push_back(), push_front(), insert()
	//� ������� erase ������� �� deque ��� ��������, � ������� �������
	//���������� � 'A' ��� 'a'
	deque<MyString>dqStr;
	dqStr.push_back("Aaaa");
	dqStr.push_back("bbBBb");
	dqStr.push_front("Vvv"); 
	dqStr.insert(++dqStr.begin(), "fffF");
	dqStr.push_back("aaa");
	printContainer(dqStr);

	for (deque<MyString>::iterator it = dqStr.begin(); it != dqStr.end();++it)
		if (it->is_begin_allcases('a'))	
		{
			it = dqStr.erase(it);
			--it;
		}
	printContainer(dqStr);


	return 0;
}