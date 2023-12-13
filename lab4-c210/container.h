#pragma once

template <typename AdapterContainer>
void printContainer(AdapterContainer c)
{
	while (!c.empty())
	{
		std::cout << c.top() << " ";
		c.pop();
	}
	std::cout <<"\n=============\n";
}


template <typename T>
void printContainer(std::queue<T> e)
{
	while (!e.empty())
	{
		std::cout << e.front() << " ";
		e.pop();
	}
	std::cout << "\n=============\n";
}

template <typename T, typename ContainerBase>
void printContainer(std::queue<T*,ContainerBase> e)//делаем копии адресов, но деинициализировать не нужно?
{
	while (!e.empty())
	{
		std::cout << *e.front() << " ";
		e.pop();
	}
	std::cout << "\n=============\n";
}


template<typename AdapterContainer>
void randFillIntContainer(AdapterContainer &c)
{
	for (int i = 0; i < 5; ++i)
		c.push(rand() % 100);
}

struct lessString{
bool operator()(const char* str1, const char* str2) const
	{ return strcmp(str1, str2) < 0; }
};