#pragma once
#include <iostream>
using namespace std;
template <typename T>
void getcorrectnumber(T& x) {
	cin >> x;
	while (cin.fail() || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Try again!" << endl;
		cin >> x;
	}
}
template<class C, typename T>
bool contains(C&& c, T t) {
	return find(begin(c), end(c), t) != end(c);
};
void printmenu() {
	cout << "Menu: " << endl
		<< "1. Add a pipe." << endl
		<< "2. Add a compressor station." << endl
		<< "3. View all pipes." << endl
		<< "4. View all compressor stations." << endl
		<< "5. Save data to file." << endl
		<< "6. Load data from file." << endl
		<< "7. Delete pipes." << endl
		<< "8. Delete cstations." << endl
		<< "9. Edit pipes." << endl
		<< "10. Edit cstations" << endl
		<< "0. Exit." << endl
		<< "--------------------------------" << endl
		<< "Enter the required number:" << endl;
}