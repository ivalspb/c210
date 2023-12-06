#pragma once

using namespace std;

template <typename T> void printVector(vector<T>& v)
{
	cout << endl << "Vector have:" <<  " ";
	cout << "size = " << v.size()<< " ";
	cout << "capacity = " << v.capacity() <<  " ";
	cout << "max_size = " << v.max_size() << endl;
	for (size_t i = 0; i < v.size(); i++) cout << v[i] << " ";
}