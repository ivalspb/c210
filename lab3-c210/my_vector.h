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

template<typename T> void unic_push(vector<T>& v, const T &t)
{
	typename vector<T>::iterator it = v.begin(), it_end=v.end();
	for (it; it != it_end; ++it)
		if (*it == t) return;
	v.insert(v.begin(), t);
}

template<typename T> void push_for_all(vector<T>& v, const T& t)
{
	typename vector<T>::iterator it = v.begin();
	for (it; it != v.end(); ++it)
	{
		it = v.insert(it, t);
		++it;
	}
}

template<typename T> void delete_not_unic_sequence(vector<T>& v)
{
	bool not_unic_all = false;
	for (typename vector<T>::iterator cur = v.begin(); cur != v.end() - 1; ++cur)
	{
		bool not_unic = false;
		while ((cur!=v.end()-1)&& (*cur == *(cur + 1)))
			{
				not_unic_all=not_unic = true;
				v.erase(cur+1);
			}
		if (not_unic) 
		{
			if(cur!=v.begin())
			{
				--cur;
				v.erase(cur+1);
				if (cur + 1 == v.end()) break;
			}
			else
			{
				v.erase(cur);
				cur = v.begin();
			}

		}
	}
	if(not_unic_all) delete_not_unic_sequence(v);
}
