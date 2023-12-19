// Iter_Alg.cpp : Defines the entry point for the console application.
//
//Итераторы. Стандартные алгоритмы. Предикаты.

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

		//Задание 1. Итераторы

		//Реверсивные итераторы. Сформируйте set<Point>. Подумайте, что
		//нужно перегрузить в классе Point. Создайте вектор, элементы которого 
		//являются копиями элементов set, но упорядочены по убыванию
	set<Point> s1;
	s1.insert(Point(1, 1));
	s1.insert(Point(2, 2));
	s1.insert(Point(0, 0.3));
	s1.insert(Point(4, 4));
	//printContainer(s1);
	vector<Point> v1(s1.rbegin(), s1.rend());
	//printContainer(v1);
	//Потоковые итераторы. С помощью ostream_iterator выведите содержимое
	//vector и set из предыдущего задания на экран.
	//cout << endl<<s1 << endl<<v1<<endl;

	copy(v1.begin(), v1.end(), ostream_iterator<Point>(cout, " ")); cout << endl;
	copy(s1.begin(), s1.end(), ostream_iterator<Point>(cout, " "));
	//Итераторы вставки. С помощью возвращаемых функциями:
	//back_inserter()
	fill_n(back_inserter(v1), 2, Point(5, 5));
	//front_inserter()
	list<Point>l1;
	copy(v1.begin(), v1.end(), front_inserter(l1));
	printContainer(l1);
	//inserter()
	copy(l1.rbegin(), l1.rend(), inserter(v1,v1.begin()));
	printContainer(v1);
	//итераторов вставки добавьте элементы в любой из созданных контейнеров. Подумайте:
	//какие из итераторов вставки можно использовать с каждым контейнером.



///////////////////////////////////////////////////////////////////

	//Задание 2. Обобщенные алгоритмы (заголовочный файл <algorithm>). Предикаты.

	// алгоритм for_each() - вызов заданной функции для каждого элемента любой последовательности
	//(массив, vector, list...)
	//С помощью алгоритма for_each в любой последовательности с элементами любого типа
	//распечатайте значения элементов
	//Подсказка : неплохо вызываемую функцию определить как шаблон

	for_each(v1.begin(), v1.end(), out<Point>);


	stop

		//С помощью алгоритма for_each в любой последовательности с элементами типа Point
		//измените "координаты" на указанное значение (такой предикат тоже стоит реализовать 
		//как шаблон) и выведите результат с помощью предыдущего предиката
	cout << "\naddPi\n";
	for_each(l1.begin(), l1.end(), addPi<Point>);
	for_each(l1.begin(), l1.end(), out<Point>);

	//С помощью алгоритма find() найдите в любой последовательности элементов Point
	//все итераторы на элемент Point с указанным значением.

	vector<vector<Point>::iterator> vi;
	Point p1(1, 1);
	vector<Point>::iterator it=find(v1.begin(),v1.end(), p1);
	while (it != v1.end())
	{
		fill_n(back_inserter(vi), 1, it);
		it = find(++it, v1.end(),p1);
	}

	stop

		//С помощью алгоритма sort() отсортируйте любую последовательность элементов Point. 
		////По умолчанию алгоритм сортирует последовательность по возрастанию.
		//Что должно быть определено в классе Point?
		// Замечание: обобщенный алгоритм sort не работает со списком, так как
		//это было бы не эффективно => для списка сортировка реализована методом класса!!!

	cout << "\nuntil sorted\n" << v1;
	sort(v1.begin(), v1.end());
	cout << "\nafter sorted\n" << v1;
	stop
		//С помощью алгоритма find_if() найдите в любой последовательности элементов Point
		//итератор на элемент Point, удовлетворяющий условию: координаты x и y лежат в промежутке
		//[-n, +m].

	it = find_if(v1.begin(), v1.end(), in_n_m);
	stop
		//С помощью алгоритма sort() отсортируйте любую последовательность элементов Rect,
		//располагая прямоугольники по удалению центра от начала координат.

	deque<MyRect> d_rect(5);
	for (deque<MyRect>::iterator i = d_rect.begin(); i != d_rect.end(); ++i)
		*i = MyRect(rand() % 20-10, rand() % 20-10, rand() % 20-10, rand() % 20-10);
	printContainer(d_rect);
	sort(d_rect.begin(), d_rect.end(), CompareByRectCenter);
	cout << "\nsorted by distance of center from (0,0)\n";
	printContainer(d_rect);



	{//transform
		//Напишите функцию, которая с помощью алгоритма transform переводит 
		//содержимое объекта string в нижний регистр.
		//Подсказка: класс string - это "почти" контейнер, поэтому для него
		// определены методы begin() и end()
		string str1 = "The Test String";
		transform(str1.begin(), str1.end(), str1.begin(), tolower);

		//Заполните list объектами string. С помощью алгоритма transform сформируте
		//значения "пустого" set, конвертируя строки в нижний регистр
	
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
		//Дан вектор с элементами типа string. С помощью copy_if() требуется
		//вывести сначала строки, начинающиеся с буквы "А" или "а", затем с "Б"...
		//При этом порядок строк в исходном векторе менять не нужно!
		vector<string> vs;
		copy(ls.begin(), ls.end(), back_inserter(vs));
		vs.push_back("eee"); vs.push_back("eEe");
		printContainer(vs);
		for (char c = 'a'; c <= 'z'; c++) 
			copy_if(vs.cbegin(), vs.cend(), ostream_iterator<string>(cout, "-> "), bind(beginFromChar, std::placeholders::_1, c));
		//copy_if(vs.cbegin(), vs.cend(), ostream_iterator<string>(cout, "-> "), [c](const string& s) {return tolower(s[0]) == c; });

		stop

		//Дан multimap, содержаций пары: "месяц - количество денй в месяце"
		//pair<string, int>. С помощью copy_if сформируйте ДВА map-а: первый -
		//с парами, содержащими четное количество дней, 2-ой - нечетное.
		multimap<string, int> month {
			{"January", 31}, {"February", 28}, {"February", 29}, { "March", 31},
			{"April", 30}, {"May",31}, {"June", 30}, {"July", 31}, {"August",31},
			{"September",30}, {"October", 31}, {"November",30}, {"December",31}
		};

		multimap<string, int> month_odd, month_even;
		copy_if(month.cbegin(), month.cend(), inserter(month_odd, month_odd.begin()), is_odd_pair);
		copy_if(month.cbegin(), month.cend(), inserter(month_even, month_even.begin()), is_even_pair);

		stop

			//Распечатайте multimap и map-ы, используя написанный вами ранее шаблон
			//функции, выводящей элементы ЛЮБОГО контейнера на печать.
			//Что нужно сделать дополнительно для вывода пары?

			printContainer(month);
			printContainer(month_odd); 
			printContainer(month_even);
		stop
	}

	return 0;
}


