#include "header.h"
#include "cstation.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
istream& operator >> (istream& in, cstation& cs) {
	cout << "Enter the name of the compressor station: " << endl;
	in.ignore();
	getline(in, cs.name);
	cout << "Enter the number of workshops: " << endl;
	getcorrectnumber(cs.workshop);
	cout << "Enter the number of workshops in operation: " << endl;
	getcorrectnumber(cs.workingwshop);
	while (cs.workshop < cs.workingwshop) {
		cout << "The number of operating compressor stations can't be more than the total number of stations!" << endl << "Try again!" << endl;
		getcorrectnumber(cs.workingwshop);
	}
	cs.efficiency = round(cs.workingwshop / cs.workshop * 100);
	cout << "Cstation effiency = " << cs.efficiency << "%. " << endl;
	return in;
}
ostream& operator << (ostream& out, cstation& cs) {
	out << "Compressor station name: " << cs.name << endl;
	out << "The number of workshops: " << cs.workshop << endl;
	out << "The number of working workshops: " << cs.workingwshop << endl;
	out << "Effiency: " << cs.efficiency << endl;
	return out;
}
ifstream& operator >> (ifstream& fin, cstation& cs) {
	fin >> cs.id;
	fin >> cs.name;
	fin >> cs.workshop;
	fin >> cs.workingwshop;
	fin >> cs.efficiency;
	return fin;
}
ofstream& operator << (ofstream& fout, cstation& cs) {
	fout << cs.id << endl << cs.name << endl << cs.workshop << endl << cs.workingwshop << endl << cs.efficiency << endl;
	return fout;
}
void cstation::changeworkshops(vector <cstation>& cstations, int index) {
	cout << "The number of workshops: " << cstations[index].workshop << endl;
	cout << "The number of working workshops: " << cstations[index].workingwshop << endl;
	cout << "Enter new number of working workshops: " << endl;
	getcorrectnumber(cstations[index].workingwshop);
	while (cstations[index].workshop < cstations[index].workingwshop) {
		cout << "The number of operating compressor stations can't be more than the total number of stations!" << endl << "Try again!" << endl;
		getcorrectnumber(cstations[index].workingwshop);
	}
}
vector <cstation> cstation::selectcs(vector <cstation> cstations) {
	int action;
	vector <cstation> selectcstations;
	cout << "1. Select cstation by name. " << endl
		<< "2. Select cstation by efficiency. " << endl
		<< "Chose action: ";
	getcorrectnumber(action);
	while (action < 0 || action > 2) {
		cout << "Try again!" << endl;
		getcorrectnumber(action);
	}
	if (action == 1) {
		string name;
		cout << "Enter cstation name: ";
		getline(cin, name);
		for (cstation cs : cstations) {
			if (cs.name.find(name) != string::npos) {
				selectcstations.push_back(cs);
				cout << "Success." << endl;
			}
		}
	}
	else {
		int efficiency;
		cout << "Enter efficiency percentage: ";
		getcorrectnumber(efficiency);
		while (efficiency > 100 || efficiency < 0) {
			cout << "Try again!";
			getcorrectnumber(efficiency);
		}
		for (cstation cs : cstations) {
			if (cs.efficiency == efficiency) {
				selectcstations.push_back(cs);
			}
		}
	}
	if (selectcstations.size() == 0) {
		cout << "Cstation wasn't found." << endl;
	}
	return selectcstations;
}
