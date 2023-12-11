#pragma once

using namespace std;

template <typename Container> void printContainer(Container const& x)
{
	cout << endl<<typeid(x).name() << endl;
	cout << "size = " << x.size() << "\t";
	//cout << "capacity = " << x.capacity() << "\t";
	cout << "max_size = " << x.max_size() << endl<<"{";
	for (auto &y:x) 
		cout << y << " ";
	cout << "}" << endl;
}

template<typename Container> void reverse(Container& x)
{
	Container y(x.rbegin(), x.rend());
	x.assign(y.begin(), y.end());
}