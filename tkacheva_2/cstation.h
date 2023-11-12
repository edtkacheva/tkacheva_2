#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class cstation {
private:
	int id;
public:
	string name;
	int workshop;
	int workingwshop;
	int efficiency;
	cstation();
	friend istream& operator >> (istream& in, cstation& cs);
	friend ostream& operator << (ostream& out, cstation& cs);
	friend ifstream& operator >> (ifstream& fin, cstation& cs);
	friend ofstream& operator << (ofstream& fout, cstation& cs);
	void changeworkshops(unordered_map <int, cstation>& cstations);
	void deletecstations(unordered_map <int, cstation>& cstations);
	unordered_map<int, int> selectcs(unordered_map<int, cstation> cstations);
};