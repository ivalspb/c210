#pragma once

using namespace std;

template <typename Container> void printContainer(const Container& x)
{
	cout << endl << typeid(x).name() << endl;
	cout << "size = " << x.size() << "\t";
	cout << "max_size = " << x.max_size() << endl;
	if(x.size())
	{
		cout<<"{";
		typename Container::const_iterator it = x.begin(), it_end1 = --x.end();
		for (; it != it_end1; ++it)
			cout << *it << ",";
		cout << *it << "}" << endl;
	}
}

//
//template <typename Container> void printContainer(Container const& x)
//{
//	cout << endl<<typeid(x).name() << endl;
//	cout << "size = " << x.size() << "\t";
//	cout << "max_size = " << x.max_size() << endl<<"{";
//	for (auto &y:x) 
//		cout << y << " ";
//	cout << "}" << endl;
//}

template<typename Container> void reverse(Container& x)
{
	Container y(x.rbegin(), x.rend());
	x.assign(y.begin(), y.end());
}