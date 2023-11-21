//------------------------------------------------------------------------------
// Тестируем разработанный список
//------------------------------------------------------------------------------
#include "MyRect.h"
#include "MyCircle.h"
#include "MyList.h"

const char* sep = "------------------------------------\n";

enum SortType { AREA, COLOR /* .... */ };

int _tmain(int argc, _TCHAR* argv[])
{
	//
	// 1. Создаем список
	//
	MyList ls1;
	
	ls1.AddToTail(MyCircle(1, 1, 1, MyShape::BLACK));	//добавляем элементы в список
	ls1.AddToTail(MyCircle(5, 5, 5, MyShape::RED));
	ls1.AddToTail(MyRect(2, 3, 4, 5, MyShape::RED));
	ls1.AddToTail(MyRect(4, 6, 8, 10, MyShape::GREEN));
	ls1.AddToTail(MyCircle(2, 2, 2, MyShape::BLACK));
	ls1.AddToTail(MyRect(3, 5, 6, 7, MyShape::GREEN));
	std::cout << ls1;								//выводим список	

	ls1.Remove(MyCircle(5, 5, 5, MyShape::RED));		// удаляем первый элемент, равный заданному
	std::cout << ls1; 
	ls1.Remove(MyRect(4, 6, 8, 10, MyShape::GREEN));
	std::cout << ls1;
	
	//
	// 2. Приведенный ниже код должен выполняться корректно	
	//
	MyList ls2 = ls1;	
	MyList ls3 = ls2;
	std::cout << ls2; 

	ls2.AddToHead(MyCircle(5, 5, 5, MyShape::RED));
	ls2.AddToHead(MyRect(5, 7, 9, 11, MyShape::BLACK));
	
	std::cout << ls2;	
	ls1 = ls2;			// из "большого" списка в "маленький"
	std::cout << ls1;	
	
	ls1 = ls3;			// из "маленького" списка в "большой"
	std::cout << ls1 << sep;	
	//
	// 3. Вспоминаем про семантику перемещения	
	//
	MyList ls4 = std::move(ls2);
	std::cout << ls4; 
	std::cout << ls2; 	

	ls3 = std::move(ls4);
	std::cout << ls3; 
	std::cout << ls4 << sep;
	//
	//4.  Сортировка по возрастанию площади кружка
	//
	std::cout << ls3;
	ls3.SortMyList(AREA);
	std::cout << ls3 << sep;

	ls3.SortMyList(COLOR);
	std::cout << ls3 << sep;

	//
	// 5. Файловый ввод/вывод
	//
	std::ofstream fout("list.txt");
	fout << ls3;	// выводим список в файл
	fout.close();
		
	std::ifstream fin("list.txt");
	MyList ls5;		// читаем список из файла
	fin >> ls5;
	fin.close();
	
	std::cout << ls5;
	// 
	// 6. Дополнительные проверки
	//
	// ...

	return 0;
}