#pragma once
#include <iostream>
#include <string>
using namespace std;
class pipe {
private: 
	int id;
public:
	string name;
	double length;
	double diameter;
	bool inrepair;
	friend ostream& operator << (ostream& out, pipe& p);
	friend istream& operator >> (istream& in, pipe& p);
	friend ofstream& operator << (ofstream& fout, pipe& p);
	friend ifstream& operator >> (ifstream& fin, pipe& p);
	void changeinrepair(vector<pipe>& pipes, int index);
	void deletepipes(vector<pipe>& pipes, vector<pipe>& selectpipes);
	vector <pipe> selectpipe(vector <pipe> pipes);
};