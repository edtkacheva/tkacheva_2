#include "header.h"
#include "cstation.h"
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
int ID = 0;
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
	getline(fin, cs.name);
	fin >> cs.workshop;
	fin >> cs.workingwshop;
	fin >> cs.efficiency;
	return fin;
}
ofstream& operator << (ofstream& fout, cstation& cs) {
	fout << cs.id << endl << cs.name << endl << cs.workshop << endl << cs.workingwshop << endl << cs.efficiency << endl;
	return fout;
}
cstation::cstation(){
	id = ID++;
	name = "no name";
	workshop = 0;
	workingwshop = 0;
	efficiency = 0;
}
void cstation::changeworkshops(unordered_map <int, cstation>& cstations) {
	int action;
	vector <int> id;
	cout << "1. Edit all cstations. " << endl
		<< "2. Select cstations to edit. " << endl
		<< "Chose action: ";
	getcorrectnumber(action);
	while (action < 0 || action > 2) {
		cout << "Try again!" << endl;
		getcorrectnumber(action);
	}
	if (action == 1) {
		for (auto cs : cstations) {
			cout << "The number of workshops: " << cs.second.workshop << endl;
			cout << "The number of working workshops: " << cs.second.workingwshop << endl;
			cout << "Enter new number of working workshops: " << endl;
			getcorrectnumber(cs.second.workingwshop);
			while (cs.second.workshop < cs.second.workingwshop) {
				cout << "The number of operating compressor stations can't be more than the total number of stations!" << endl << "Try again!" << endl;
				getcorrectnumber(cs.second.workingwshop);
			}
		}
		cout << "All cs have been changed. " << endl;
	}
	else {
		unordered_map <int, int> selectcstations = selectcs(cstations);
		if (selectcstations.size() == 0) {
			cout << "No items selected. " << endl;
		}
		else {
			for (auto cs : cstations) {
				if (contains(selectcstations, cs.second.id)) {
					cout << "The number of workshops: " << cs.second.workshop << endl;
					cout << "The number of working workshops: " << cs.second.workingwshop << endl;
					cout << "Enter new number of working workshops: " << endl;
					getcorrectnumber(cs.second.workingwshop);
					while (cs.second.workshop < cs.second.workingwshop) {
						cout << "The number of operating compressor stations can't be more than the total number of stations!" << endl << "Try again!" << endl;
						getcorrectnumber(cs.second.workingwshop);
					}
				}
			}
		}
		cout << "Selected cs have been changed. " << endl;
	}
	
}
void cstation::deletecstations(unordered_map<int, cstation>& cstations) {
	int action;
	vector <int> id;
	cout << "1. Delete all cstations. " << endl
		<< "2. Select cstations to delete. " << endl
		<< "Chose action: ";
	getcorrectnumber(action);
	while (action < 0 || action > 2) {
		cout << "Try again!" << endl;
		getcorrectnumber(action);
	}
	if (action == 1) {
		cstations.clear();
		cout << "All pipes have been deleted. " << endl;
	}
	else {
		unordered_map <int, int> selectcstations = selectcs(cstations);
		if (selectcstations.size() == 0) {
			cout << "No items selected. " << endl;
		}
		else {
			int i;
			for (auto cs : cstations) {
				if (contains(selectcstations, cs.second.id)) {
					cstations.erase(i);
				}
				i++;
			}
			cout << "Selected pipes have been deleted. " << endl;
		}
	}
}
unordered_map <int, int> cstation::selectcs(unordered_map <int, cstation> cstations) {
	int action;
	unordered_map <int, int> selectcstations;
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
		for (auto cs : cstations) {
			if (cs.second.name.find(name) != string::npos) {
				selectcstations [selectcstations.size() + 1] = cs.second.id;
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
		for (auto cs : cstations) {
			if (cs.second.efficiency == efficiency) {
				selectcstations [selectcstations.size() + 1] = cs.second.id;
			}
		}
	}
	if (selectcstations.size() == 0) {
		cout << "Cstation wasn't found." << endl;
	}
	return selectcstations;
}