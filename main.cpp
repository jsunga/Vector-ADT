#include "Vector.h"

Vector v;

int main() {
	while (1) {
		cout << "1) pushBack	" << "2) insert	" << "3) popBack	" << "4) resize	" << "5) shrinkToFit	" << endl << endl;
		cout << "6) getCapacity	" << "7) getSize	" << "8) isEmpty	" << "9) test Copy	" << "10) test Operator" << endl << endl;
		cout << "0) exit" << endl << endl;
		int input;
		int index;
		int size;
		int data;
		cin >> input;
		
		if (input == 1) {
			cout << endl;
			cout << "Enter data: ";
			cin >> data;
			v.pushBack(data);
			cout << endl;
			cout << v << endl << endl;
		} else if (input == 2) {
			cout << endl;
			cout << "Enter index(1 is first element): ";
			cin >> index;
			cout << "Enter data: ";
			cin >> data;
			v.insert(index, data);
			cout << endl;
			cout << v << endl << endl;
		} else if (input == 3) {
			v.popBack();
			cout << endl;
			cout << v << endl << endl;
		} else if (input == 4) {
			cout << endl;
			cout << "Enter new size: ";
			cin >> size;
			v.resize(size);
			cout << endl;
			cout << v << endl << endl;
		} else if (input == 5) {
			v.shrinkToFit();
			cout << endl;
		} else if (input == 6) {
			cout << endl;
			cout << "Capacity: " << v.getCapacity() << endl << endl;
		} else if (input == 7) {
			cout << endl;
			cout << "Size: " << v.getSize() << endl << endl;
		} else if (input == 8) {
			cout << endl;
			if (v.isEmpty() == true) {
				cout << "Empty" << endl << endl;
			}
			else {
				cout << "Not empty" << endl << endl;
			}
		} else if (input == 9) {
			cout << endl;
			cout << "1st " << v << endl;
			Vector v2(v);
			cout << "Copying 1st Vector to 2nd Vector..." << endl;
			cout << "2nd " << v2 << endl << endl;
		} else if (input == 10) {
			cout << endl;
			Vector test;
			test.pushBack(7);
			test.pushBack(7);
			test.pushBack(7);
			cout << "Test " << test << endl;
			cout << "1st " << v << endl;
			cout << "Testing assignment operating Test = 1st..." << endl;
			test = v;
			cout << "Test " << test << endl << endl;
		} else if (input == 0) {
			exit(1);
		} else {
			cout << endl;
			cout << "Wrong input!" << endl << endl;
		}
	}
	return 0;
}
