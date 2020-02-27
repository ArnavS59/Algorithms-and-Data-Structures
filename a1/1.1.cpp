#include <iostream>
#include <cstdlib>
#include <type_traits>
using namespace std;

class Complex
{
private:
	double re, im;

public:
	Complex(double ren, double imn)
	{
		re = ren;
		im = imn;
	}
	bool const operator==(const Complex &o)//overloading the == operator for complex objects 
	{

		if ((re == o.re) && (im == o.im))
			return true;
		else
			return false;
	}
};

template <typename T>
int array_search(T arr[], int size, T find_element)//search functions
{
	int i;
	for (i = 0; i < size; i++)
	{

		if (arr[i] == find_element)
			return i;
	}
	return -1;
}

int main()
{
	int integer_array[] = {1, 2, 3, 4, 5, 6, 7, 8};//for integers
	cout<<"The position is:"<<endl;
	cout << array_search(integer_array, 8, 4) << endl;

	double float_array[] = {1.5, 5.7, 66.3, 69.99};//for floats
	cout<<"The position is:"<<endl;
	cout << array_search(float_array, 4, 5.7)<< endl;

	string string_array[] = {"hello", "world", "is"};//for strings
	cout<<"The position is:"<<endl;
	cout << array_search(string_array, 3, std::string("hello")) << endl;

	Complex x(1, 4);//for complex objects
	Complex y(2, 4);
	Complex z(3, 5);
	Complex p(4, 2);
	Complex com_array[3] = {x, y, z};
	cout<<"The position is:"<<endl;
	cout << array_search(com_array, 3, p)<<endl;
}