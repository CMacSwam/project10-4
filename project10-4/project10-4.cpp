#include <iostream>

using namespace std; 

int doubleOdd(int array[], int size);
int reversesum(int array[], int size);

int main() {

	while (true) {
		int creditcard = 0;
		cout << "Enter 8-digit credit card # or Q to quit: ";
		cin >> creditcard;
		if (cin.fail()) {
			break;
		}
		int array[8];
		for (int i = 7; i >= 0; i--) {
			array[i] = creditcard % 10;
			creditcard = creditcard / 10;
		}
		
		int sum = doubleOdd(array, 8) + reversesum(array, 8);
		
		if (sum == 50) {
			cout << "Card is valid" << endl;
		}
		else cout << "Card is not valid" << endl;
	}
}

int reversesum(int array[], int size) {
	int sum = 0;
	for (int i = size - 1; i>=0; i-=2) {
			sum = sum + array[i];
	}
	return sum;
}

int doubleOdd(int array[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i+=2) {
			int doubling = array[i] * 2;
			int remainder = doubling % 10;
			int tens = doubling / 10;
			sum = sum + remainder + tens;
	}
	return sum;
}