// Контейнеры STL: 
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

	
	//Напишите шаблон функции для вывода значений stack, queue, priority_queue
	//обратите внимание на то, что контейнеры предоставляют РАЗНЫЕ методы для 
	//получения значений
	
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

	//Создайте стек таким образом, чтобы
	//а) элементы стека стали копиями элементов вектора
	//б) при выводе значений как вектора, так и стека порядок значений был одинаковым 

	vector<int> v1 = { 1,2,3,4,5 };
	cout << "\nprint vector\n" << v1;
	stack<int> s1;
	for (vector<int>::reverse_iterator i = v1.rbegin(), end = v1.rend(); i != end; ++i)
		s1.push(*i);
	cout << "\nprinting stack\n";
	printAdapterContainer(s1);
	
	


	////////////////////////////////////////////////////////////////////////////////////
	//queue

	//Создайте очередь, которая содержит указатели на объекты типа Point,
	//при этом явно задайте базовый контейнер.
	//Измените значения первого и последнего элементов посредством front() и back()
	//Подумайте, что требуется сделать при уничтожении такой очереди?
	
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
	//а) создайте очередь с приоритетами, которая будет хранить адреса строковых литералов - const char*
	//б) проинициализируйте очередь при создании с помощью вспомогательного массива с элементами const char*
	//в) проверьте "упорядоченность" значений (с помощью pop() ) - если они оказываются не упорядоченными, подумайте:
	//		что сравнивается при вставке?
	
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
		//a) создайте множество с элементами типа Point - подумайте, что необходимо определить
		//		в классе Point (и каким образом)
		//б) распечатайте значения элементов с помощью шаблона, реализованного в предыдущей лаб. работе
		//в) попробуйте изменить любое значение...
		//г) Создайте два множества, которые будут содержать одинаковые значения
		//		типа int, но занесенные в разном порядке
		//д) Вставьте в любое множество диапазон элементов из любого другого
		//	контейнера, например, элементов массива	(что происходит, если в массиве имеются дубли?)

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
	//а) создайте map, который хранит пары "фамилия, зарплата" - pair<const char*, int>,
	//	при этом строки задаются строковыми литералами
	//б) заполните контейнер значениями посредством operator[] и insert()
	//в) распечатайте содержимое

	map<const char*, int> m;
	m["Ivanova"] = 100;
	m["Sidorov"] = 150; 
	m.insert({ { "Kolmogorov",50 },{"Zadornov",200} });
	printContainer(m);
	//г) замените один из КЛЮЧЕЙ на новый (была "Иванова", вышла замуж => стала "Петрова")
	int tmp_salary = m["Ivanova"];
	m.erase("Ivanova"); 
	m["Petrova"] = tmp_salary;
	printContainer(m);
	stop




		//д) Сформируйте любым способом вектор с элементами типа string.
		//Создайте (и распечатайте для проверки) map<string, int>, который будет
		//содержать упорядоченные по алфавиту строки и
		//количество повторений каждой строки в векторе

		vector<string> vString = { "Aaa","Bbb","Aaa","Ccc","Aaa","Bbb","Ddd" };
		


		//е) 
		//задан массив:
		//const char* words[] = {"Abba", "Alfa", "Beta", "Beauty" ,...};
		//создайте map, в котором каждой букве будет соответствовать совокупность 
		//лексиграфически упорядоченных слов, начинающихся с этой буквы.
		//Подсказка: не стоит хранить дубли одной и той же строки
	
		//'A' -  "Abba" "Alfa"
		//'B' -  "Beauty" "Beta"  ...
		//...
		

		//ж)
		//создайте структуру данных, которая будет хранить информацию о студенческих группах.
		//Для каждой группы должны хранится фамилии студентов (по алфавиту). При этом 
		//фамилии могут дублироваться
		//Сами группы тоже должны быть упорядочены по номеру
		//
		//номера 




	////////////////////////////////////////////////////////////////////////////////////
	//multimap
	//а) создайте "англо-русский" словарь, где одному и тому же ключу будут соответствовать
	//		несколько русских значений - pair<string,string>, например: strange: чужой, странный...
	//б) Заполните словарь парами с помощью метода insert или проинициализируйте с помощью 
	//		вспомогательного массива пара (пары можно конструировать или создавать с помощью шаблона make_pair)
	//в) Выведите все содержимое словаря на экран
	//г) Выведите на экран только варианты "переводов" для заданного ключа. Подсказка: для нахождения диапазона
	//		итераторов можно использовать методы lower_bound() и upper_bound()




   

  stop

	return 0;
}

