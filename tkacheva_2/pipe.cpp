#include "pipe.h"
#include "header.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
ostream& operator << (ostream& out, pipe& p) {
	out << "Pipe name: " << p.name << endl;
	out << "Pipe length: " << p.length << endl;
	out << "Pipe diameter: " << p.diameter << endl;
	out << "Condition 'under repair': " << p.inrepair << endl;
	return out;
}
istream& operator >> (istream& in, pipe& p) {
	cout << "Enter pipe name: " << endl;
	in.ignore();
	getline(in, p.name);
	cout << "Enter pipe length: " << endl;
	getcorrectnumber(p.length);
	cout << "Enter pipe diameter: " << endl;
	getcorrectnumber(p.diameter);
	cout << "Is the pipe being repaired? (1 - yes, 0 - no): " << endl;
	getcorrectnumber(p.inrepair);
	return in;
}
ofstream& operator <<(ofstream& fout, pipe& p) {
	fout << p.id << endl << p.name << endl << p.length << endl << p.diameter << endl << p.inrepair << endl;
	return fout;
}
ifstream& operator >> (ifstream& fin, pipe& p) {
	fin >> p.id;
	getline(fin, p.name);
	fin >> p.length;
	fin >> p.diameter;
	fin >> p.inrepair;
	return fin;
}
void pipe::changeinrepair(vector<pipe>& pipes, int index) {
	pipes[index].inrepair = !pipes[index].inrepair;
	cout << "The status 'under repair' has been changed" << endl;
}
void pipe::deletepipes(vector<pipe>& pipes, vector<pipe>& selectpipes) {
	int action;
	vector <int> id;
	cout << "1. Delete all pipes. " << endl
		<< "2. Select pipes to delete. " << endl
		<< "Chose action: ";
	getcorrectnumber(action);
	while (action < 0 || action > 2) {
		cout << "Try again!" << endl;
		getcorrectnumber(action);
	}
	if (action == 1) {
		pipes.clear();
		cout << "All pipes was deleted. " << endl;
	}
	else {
		for (pipe p : selectpipes) {
			id.push_back(p.id);
		}
		for (pipe p : pipes) {
			if (contains(id, p.id) {
				pipes.erase();
			}
		}
	}
}
vector<pipe> pipe::selectpipe(vector<pipe> pipes) {
	int action;
	vector <pipe> selectpipes;
	cout << "1. Select pipes by name. " << endl
		<< "2. Select pipe based on the characteristics in repair. " << endl
		<< "Chose action: ";
	getcorrectnumber(action);
	while (action < 0 || action > 2) {
		cout << "Try again!" << endl;
		getcorrectnumber(action);
	}
	if (action == 1) {
		string name;
		cout << "Enter pipe name: ";
		getline(cin, name);
		for (pipe p : pipes) {
			if (p.name.find(name) != string::npos) {
				selectpipes.push_back(p);
				cout << "Success." << endl;
			}
		}
	}
	else {
		bool characteristic;
		cout << "Enter characteristic in repair (0 or 1): ";
		getcorrectnumber(characteristic);
		for (pipe p : pipes) {
			if (p.inrepair == characteristic) {
				selectpipes.push_back(p);
			}
		}
	}
	if (selectpipes.size() == 0) {
		cout << "Pipe wasn't found." << endl;
	}
	return selectpipes;
}