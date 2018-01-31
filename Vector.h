#include <iostream>

using namespace std;

class Vector {
private:
	double* arr;
	int cap;
	int size;

public:
	Vector();
	
	Vector(const Vector& rhs);
	Vector& operator=(const Vector& rhs);
	~Vector();
	
	void pushBack(double data);
	void insert(int index, double data);
	void popBack();
	void resize(int newSize);
	void shrinkToFit();
	int getCapacity();
	int getSize();
	bool isEmpty();
	friend ostream& operator<<(ostream& out, const Vector& rhs);
};
