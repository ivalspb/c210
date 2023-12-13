#pragma once

using namespace std;

template <typename AdapterContainer>
void printAdapterContainer(AdapterContainer c)
{
	while (!c.empty())
	{
		std::cout << c.top() << " ";
		c.pop();
	}
	std::cout <<"\n=============\n";
}


template <typename T, typename ContainerBase=deque<T>>
void printAdapterContainer(std::queue<T, ContainerBase> e)
{
	while (!e.empty())
	{
		std::cout << e.front() << " ";
		e.pop();
	}
	std::cout << "\n=============\n";
}

template <typename T, typename ContainerBase=deque<T>>
void printAdapterContainer(std::queue<T*,ContainerBase> e)//делаем копии адресов, но деинициализировать не нужно?
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

template <typename Container> 
void printContainer(const Container& x)
{
	cout << endl << typeid(x).name() << endl;
	cout << "size = " << x.size() << "\t";
	cout << "max_size = " << x.max_size() << endl;
	if (x.size())
	{
		cout << "{";
		typename Container::const_iterator it = x.begin(), it_end1 = --x.end();
		for (; it != it_end1; ++it)
			cout << *it << ",";
		cout << *it << "}" << endl;
	}
}

//template <typename Key, typename Val, typename Traits=less<Key>, typename Allocator=allocator<pair<const Key, Val>>>

template <typename Key, typename Val>
void printContainer(const map<Key,Val>& x)
{
	cout << endl << typeid(x).name() << endl;
	cout << "size = " << x.size() << "\t";
	cout << "max_size = " << x.max_size() << endl;
	if (x.size())
	{
		cout << "{";
		typename map<Key,Val>::const_iterator it = x.begin(), it_end1 = --x.end();
		for (; it != it_end1; ++it)
			cout << it->first<<"|"<<it->second << ",";
		cout << it->first<<"|"<<it->second << "}" << endl;
	}
}
