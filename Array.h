#include "stdafx.h"

class Array
{
	private:
		int* arr = nullptr;
		size_t size;
		size_t buf;

	public:
		Array();//1
		Array(const size_t size);
		Array(const size_t size, const int& number);
		Array(const Array& arr);
		Array(Array&& arr);
		Array(const size_t size, const int& number, const size_t buf);//2
		~Array();//1

		size_t getSize() const;//1
		int& operator[](size_t i);//1
		const int& operator[](size_t i) const;
		void resize(const size_t newSize);//1
		Array& operator=(const Array& array);//1
		Array& operator=(Array&& array);//1
		bool operator==(const Array& array) const;//1
		bool operator!=(const Array& array) const;//1
		bool operator<(const Array& array) const;//1
		bool operator<=(const Array& array) const;//1
		bool operator>(const Array& array) const;//1
		bool operator>=(const Array& array) const;//1

		void reserve(const size_t& n);//2
		size_t capacity() const;//2
		void push_back(const int& elem);//2
		void pop_back();//2

		friend std::ostream& operator<<(std::ostream& out, const Array& arr);//1
		friend std::istream& operator>>(std::istream& in, Array& arr);//1
		friend Array operator+(const Array& arr1, const Array& arr2);//1
};



class OutOfBoundsException : public std::exception {};