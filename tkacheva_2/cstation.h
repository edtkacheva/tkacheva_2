#pragma once
#include <iostream>
#include <string>
using namespace std;
class cstation {
private:
	int id;
public:
	string name;
	int workshop;
	int workingwshop;
	int efficiency;
	friend istream& operator >> (istream& in, cstation& cs);
	friend ostream& operator << (ostream& out, cstation& cs);
	friend ifstream& operator >> (ifstream& fin, cstation& cs);
	friend ofstream& operator << (ofstream& fout, cstation& cs);
	void changeworkshops(vector <cstation>& cstations, int index);
	vector <cstation> selectcs(vector <cstation> cstations);
};