#include "Vector.h"

Vector::Vector(): arr(NULL), cap(0), size(0) {}

Vector::Vector(const Vector& rhs) {
//copy capacity, size, and elements
	cap = rhs.cap;
	size = rhs.size;
	arr = new double[cap];
	for (int i = 0; i < size; i++)
		arr[i] = rhs.arr[i];
}

Vector& Vector::operator=(const Vector& rhs) {
//same as copy constructor but delete vector before copying elements
	delete [] arr;
	cap = rhs.cap;
	size = rhs.size;
	arr = new double[cap];
	for (int i = 0; i < size; i++)
		arr[i] = rhs.arr[i];	
}

Vector::~Vector() {
	if (arr != NULL) {
		delete [] arr;
		arr = NULL;
		cap = 0;
		size = 0;
	}
}

void Vector::pushBack(double data) {
	if (cap == 0) { //if vector is empty then create a darray with capacity 1
		arr = new double[1];
		arr[0] = data;
		cap++;
		size++;
	} else if (cap > size) { //if there is space for another element then just add the element to the next empty slot
		arr[size] = data;
		size ++;
	} else {
/*
default case: capacity = size
create a temporary darray with a capacity of one more than original darray.
copy the original to the temp and add new element as well
then delete original array and set it to temp
*/
		double* temp = new double[cap + 1];
		for (int i = 0; i < size; i++)
			temp[i] = arr[i];
		temp[size] = data;
		delete [] arr;
		arr = temp;
		cap++;
		size++;
	}
}

void Vector::insert(int index, double data) {
	if (index == size + 1) { 
		pushBack(data);
	} else if (index == 1) {
/*
case: this case is like pushFront
create a new temp darray
insert data to the front
then copy the rest of the original darray
delete original darray and set it to temp
*/
		double* temp = new double[cap + 1];
		temp[0] = data;
		for (int i = 1; i <= size; i++)
			temp[i] = arr[i-1];
		delete [] arr;
		arr = temp;
		if (size == cap) {
			cap++;
			size++;
		} else {
			size++;
		}
	} else if (index > 1 && index <= size) {
/*
case: anything in between
create a new temp darray
enter data to the desired position
use two for loops to copy the original darray data
*/
		double* temp = new double[cap + 1];
		temp[index-1] = data;
		for (int i = 0; i < index-1; i++)
			temp[i] = arr[i];
		for (int i = index; i <= size; i++) 
			temp[i] = arr[i-1];
		delete [] arr;
		arr = temp;
		if (size == cap) {
			cap++;
			size++;
		} else {
			size++;
		}
	} else if (size == 0) {
		pushBack(data);
	} else {
		cout << "Invalid Insert!" << endl;
	}
}

void Vector::popBack() {
	if (size > 0)
		size--;
	else
		size = 0;
}

void Vector::resize(int newSize) {
	if (newSize <= size) //if newSize is less than size then elements will be deleted
		size = newSize;
	else {
/*
create a new temp darray
copy the data with the new capacity
*/
		double* temp = new double[newSize];
		for (int i = 0; i < size; i++)
			temp[i] = arr[i];
		for (int i = size; i < newSize; i++)
			temp[i] = 0;
		delete [] arr;
		arr = temp;
		cap = newSize;
	}
}

void Vector::shrinkToFit() {
/*
create a new temp darray
copy the data with the new capacity (same as size)
*/
	if (cap > size) {
		double* temp = new double[size];
		for (int i = 0; i < size; i++)
			temp[i] = arr[i];
		delete [] arr;
		arr = temp;
		cap = size;
	}
}

int Vector::getCapacity() {
	return cap;
}

int Vector::getSize() {
	return size;
}

bool Vector::isEmpty() {
	return size == 0;
}

ostream& operator<<(ostream& out, const Vector& rhs) {
	if (rhs.size == 0) {
		out << "Vector is empty";
		return out;
	}
	out << "Vector: ";
	for (int i = 0; i < rhs.size; i++) {
		out << rhs.arr[i] << " ";
	}
	return out;
}
