#pragma once

using namespace std;

template <typename T> void printVector(vector<T>& v)
{
	cout << endl << "Vector have:" <<  " ";
	cout << "size = " << v.size()<< "\t";
	cout << "capacity = " << v.capacity() <<  "\t";
	cout << "max_size = " << v.max_size() << endl;
	for (size_t i = 0; i < v.size(); i++) cout << v[i] << " ";
}

template <typename T> void printVector(vector<T*>& v)
{
	cout << endl << "pVector have:" << " ";
	cout << "size = " << v.size() << "\t";
	cout << "capacity = " << v.capacity() << "\t";
	cout << "max_size = " << v.max_size() << endl;
	for (size_t i = 0; i < v.size(); i++) cout << *v[i] << " ";
}

template<typename T> void unic_push(vector<T>& v, T& t)
{
	typename vector<T>::iterator it = v.begin(), it_end=v.end();
	for (it; it != it_end; ++it)
		if (*it == t) return;
	v.insert(v.begin,t);
}