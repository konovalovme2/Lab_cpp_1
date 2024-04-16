#include "stdafx.h"
#include "Array.h"

Array::Array() : size(1), buf(0)
{
	this->arr = new int[1];
	this->arr[0] = 0;
}

Array::Array(const size_t size) : size(size), buf(0)
{
	this->arr = new int[size + buf];
	for (size_t i = 0; i < size + buf; ++i) {
		this->arr[i] = 0;
	}
}

Array::Array(const size_t size, const int& number) : size(size), buf(0)
{
	this->arr = new int[size + buf];
	for (size_t i = 0; i < size; ++i) {
		this->arr[i] = number;
	}
	for (size_t i = size; i < size + buf; ++i) {
		this->arr[i] = 0;
	}
}

Array::Array(const Array& arr) : size(arr.size), buf(arr.buf)
{
	this->arr = new int[size + buf];
	for (size_t i = 0; i < size; ++i) {
		this->arr[i] = arr.arr[i];
	}
	for (size_t i = size; i < size + buf; ++i) {
		this->arr[i] = 0;
	}
}

Array::Array(Array&& arr) : size(arr.size), buf(arr.buf)
{
	this->arr = new int[size + buf];
	for (size_t i = 0; i < size; ++i) {
		this->arr[i] = arr.arr[i];
	}
	for (size_t i = size; i < size + buf; ++i) {
		this->arr[i] = 0;
	}
	arr.arr = nullptr;
	arr.size = 0;
	arr.buf = 0;
}

Array::Array(const size_t size, const int& number, const size_t buf): buf(buf), size(size)
{
	this->arr = new int[size+buf];
	for (size_t i = 0; i < size; ++i) {
		this->arr[i] = number;
	}
	for (size_t i = size; i < size + buf; ++i) {
		this->arr[i] = 0;
	}
}

Array::~Array()
{
	delete[] arr;
	arr = nullptr;
}

size_t Array::getSize() const
{
	return size;
}

int& Array::operator[](size_t i)
{
	if (i > this->size) {
		throw OutOfBoundsException();
	}
	return arr[i];
}

const int& Array::operator[](size_t i) const
{
	if (i > this->size) {
		throw OutOfBoundsException();
	}
	return arr[i];
}

void Array::resize(const size_t newSize) //rewrite
{
	/*if (this->size == newSize) { return; }
	int* arrCopy = new int[newSize + this->buf];
	if (this->size < newSize && this->size > 0) {
		for (size_t i = 0; i < this->size; i++) {
			arrCopy[i] = this->arr[i];
		}
		for (size_t i = this->size; i < newSize + this->size; i++) {
			arrCopy[i] = 0;
		}
	}
	else if (this->size > newSize){
		for (size_t i = 0; i < newSize; i++) {
			arrCopy[i] = this->arr[i];
		}
	}
	if (this->arr) { delete[] this->arr; }
	this->arr = arrCopy;
	this->size = newSize;*/
}


Array& Array::operator=(const Array& array)
{
	if (this == &array) { return *this; }
	Array copy(array);
	std::swap(size, copy.size);
	std::swap(buf, copy.buf);
	std::swap(arr, copy.arr);
	return *this;
}

Array& Array::operator=(Array&& array)
{
	if (this == &array) { return *this; }
	std::swap(arr, array.arr);
	std::swap(size, array.size);
	std::swap(buf, array.buf);
	return *this;
}

bool Array::operator==(const Array& array) const
{
	if (this == &array) { return true; }
	if (this->size != array.size) {
		return false;
	}
	for (size_t i = 0; i < size; ++i)
	{
		if (this->arr[i] != array.arr[i]) {
			return false;
		}
	}
	return true;
}

bool Array::operator!=(const Array& array) const
{
	if (this == &array) { return false; }
	if (this->size != array.size) {
		return true;
	}
	for (size_t i = 0; i < size; ++i)
	{
		if (this->arr[i] != array.arr[i]) {
			return true;
		}
	}
	return false;
}

bool Array::operator<(const Array& array) const
{
	if (this == &array) { return false; }
	for (size_t i = 0; i < std::min(this->size, array.size); ++i)
	{
		if (this->arr[i] < array.arr[i]) {
			return true;
		}
		else if (this->arr[i] > array.arr[i]) {
			return false;
		}
	}
	if (this->size < array.size) {
		return true;
	}
	return false;
}

bool Array::operator<=(const Array& array) const
{
	if (this == &array) { return true; }
	for (size_t i = 0; i < std::min(this->size, array.size); ++i)
	{
		if (this->arr[i] < array.arr[i]) {
			return true;
		}
		else if (this->arr[i] > array.arr[i]) {
			return false;
		}
	}
	if (this->size <= array.size) {
		return true;
	}
	return false;
}

bool Array::operator>(const Array& array) const
{
	if (this == &array) { return false; }
	for (size_t i = 0; i < std::min(this->size, array.size); ++i)
	{
		if (this->arr[i] > array.arr[i]) {
			return true;
		}
		else if (this->arr[i] < array.arr[i]) {
			return false;
		}
	}
	if (this->size > array.size) {
		return true;
	}
	return false;
}

bool Array::operator>=(const Array& array) const
{
	if (this == &array) { return true; }
	for (size_t i = 0; i < std::min(this->size, array.size); ++i)
	{
		if (this->arr[i] > array.arr[i]) {
			return true;
		}
		else if (this->arr[i] < array.arr[i]) {
			return false;
		}
	}
	if (this->size >= array.size) {
		return true;
	}
	return false;
}

void Array::reserve(const size_t& n)
{
	if (this->buf == n) { return; }
	int* arrCopy = new int[size + n];
	if (arr) {
		for (size_t i = 0; i < size; ++i) {
			arrCopy[i] = this->arr[i];
		}
		delete[] this->arr;
	}
	this->arr = arrCopy;
	this->buf = n;
}

size_t Array::capacity() const
{
	return this->buf;
}

void Array::push_back(const int& elem)
{
	if (this->buf == 0) {
		throw OutOfBoundsException();
	}
	this->size++;
	this->buf--;
	this->arr[size - 1] = elem;
}

void Array::pop_back()
{
	if (this->size == 0) {
		throw OutOfBoundsException();
	}
	this->size--;
	this->buf++;
}

std::ostream& operator<<(std::ostream& out, const Array& arr)
{
	for (size_t i = 0; i < arr.getSize(); ++i) {
		out << arr[i] << " ";
	}
	return out;
}

std::istream& operator>>(std::istream& in, Array& arr)
{
	int size;
	in >> size;
	arr = Array(size);
	for (size_t i = 0; i < size; ++i) {
		in >> arr[i];
	}
	return in;
}

Array operator+(const Array& m1, const Array& m2)
{
	int a;
	Array sum(m1.getSize() + m2.getSize());
	for (size_t i = 0; i < m1.getSize(); ++i) {
		a = m1[i];
		sum[i] = a;
	}
	for (size_t i = 0; i < m2.getSize(); ++i) {
		sum[i + m1.getSize()] = m2[i];
	}
	return sum;
}
