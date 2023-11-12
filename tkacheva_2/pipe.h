#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class pipe {
private: 
	int id;
public:
	string name;
	double length;
	double diameter;
	bool inrepair;
	pipe();
	void changeinrepair(unordered_map<int, pipe>& pipes);
	void deletepipes(unordered_map<int, pipe>& pipes);
	unordered_map<int, int> selectpipe(unordered_map<int, pipe> pipes);
	friend ostream& operator << (ostream& out, pipe& p);
	friend istream& operator >> (istream& in, pipe& p);
	friend ofstream& operator << (ofstream& fout, pipe& p);
	friend ifstream& operator >> (ifstream& fin, pipe& p);
};