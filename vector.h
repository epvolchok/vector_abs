#pragma once
#include <cassert>
#include <iostream>
#include <memory>
template <typename T>
class abstract_vector;

template < typename T>
std::ostream& operator<<(std::ostream& os, abstract_vector<T>& v);

template <typename T>
class abstract_vector
{
	private:
	unsigned size = 0;
	std::unique_ptr<T[]> data = nullptr;
	
	public:
	//construstors
	//empty
	abstract_vector() : size{0}, data{nullptr} {}
	//default
	explicit abstract_vector(unsigned size) : size{size}, data{new T[size]} {}
	//with initializing list
	abstract_vector(std::initializer_list<T> values) : size{(unsigned)values.size()}, data{new T[size]}
	{
		std::copy(std::begin(values), std::end(values), &data[0]);
	}
	//copying constructor
	abstract_vector(const abstract_vector& v) : size{v.size}, data{new T[size]}
	{
		std::copy(&v.data[0], &v.data[v.size], &data[0]);
	}
	
	//~abstract_vector() // - don't need cause of use unique_ptr
	//{ delete[] data; }
		//std::cout << "inside the destructor" << std::endl; }
		
	//abstract_vector(abstract_vector && v) : size{v.size}, data{v.data} //перемещающий конструктор
	//{
	//	v.data = nullptr;
	//	v.size = 0;
	//}
	
	//basic operators
	abstract_vector& operator=(const abstract_vector& v) &;
	
	
	const T& operator[](unsigned i) const &;//the value is forbiden to change, for consts
	
	T& operator[](unsigned i) &; //can be changed
	
	abstract_vector& operator=(abstract_vector && v); //moving assignment
	
	
	friend std::ostream& operator<<<T>(std::ostream& os, abstract_vector& v);
	
	
	
	unsigned get_size() const;
	
};
