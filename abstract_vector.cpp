#include <iostream>
#include "vector.h"
#include "vector.cpp"

int main()
{
	{
		abstract_vector<double> v={1.0, 2.0, 3.0};
		v[1] = 2;
		std::cout << v << std::endl;
		//std::cout << v[2] << std::endl;
		
	}
	
	return 0;
}
