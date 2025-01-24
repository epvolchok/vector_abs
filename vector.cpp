#include "vector.h"
#include <cassert>
#include <initializer_list>
#include <algorithm>

template < typename T>
abstract_vector<T>& abstract_vector<T>::operator=(const abstract_vector<T>& v) &
{
	if (this == &v)
		return *this;
	assert(size == v.size);
	for (unsigned i=0; i<size; ++i)
	{
		data[i]=v.data[i];
	}
	return *this;
}
template < typename T>
const T& abstract_vector<T>::operator[](unsigned i) const &//value can not be changed
{
	assert(i >= 0 || i < size);
	return data[i];
}
template < typename T>
T& abstract_vector<T>::operator[](unsigned i) & //to lvalue
{
	assert(i >= 0 || i < size);
	return data[i];
}
template < typename T>
abstract_vector<T>& abstract_vector<T>::operator=(abstract_vector<T> && v)
{
	assert(size == 0 || size == abstract_vector<T>(v.size));
	std::swap(data, abstract_vector<T>(v.data));
	return *this;
}
template < typename T>
unsigned  abstract_vector< T >::get_size() const
{ 
	return size;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, abstract_vector<T>& v)
{
	os << "(";
	for (unsigned i=0; i<(v.size-1); ++i)
		os << (v.data[i]) << ", ";
	os << (v.data[v.size-1]) << ")";
	return os;
}

