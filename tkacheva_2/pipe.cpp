#include "pipe.h"
#include "header.h"
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>
int ID = 0;
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
pipe::pipe()
{
	id = ID ++;
	name = "no name";
	length = 0;
	diameter = 0;
	inrepair = 0;
}
void pipe::changeinrepair(unordered_map<int, pipe>& pipes) {
	int action;
	vector <int> id;
	cout << "1. Edit all pipes. " << endl
		<< "2. Select pipes to edit. " << endl
		<< "Chose action: ";
	getcorrectnumber(action);
	while (action < 0 || action > 2) {
		cout << "Try again!" << endl;
		getcorrectnumber(action);
	}
	if (action == 1) {
		for (auto p : pipes) {
			p.second.inrepair = !p.second.inrepair;
		}
		cout << "All pipes have been edited.";
	}
	else {
		unordered_map <int, int> selectpipes = selectpipe(pipes);
		if (selectpipes.size() == 0) {
			cout << "No items selected. " << endl;
		}
		else {
			for (auto p : pipes) {
				if (contains(selectpipes, p.second.id)) {
					p.second.inrepair = !p.second.inrepair;
				}
			}
			cout << "Selected pipes have been deleted. " << endl;
		}
	}
}
void pipe::deletepipes(unordered_map<int, pipe>& pipes) {
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
		cout << "All pipes have been deleted. " << endl;
	}
	else {
		unordered_map <int, int> selectpipes = selectpipe(pipes);
		if (selectpipes.size() == 0) {
			cout << "No items selected. " << endl;
		}
		else {
			int i;
			for (auto p : pipes) {
				if (contains(selectpipes, p.second.id)) {
					pipes.erase(i);
				}
				i ++;
			}
			cout << "Selected pipes have been deleted. " << endl;
		}
	}
}
unordered_map<int, int> pipe::selectpipe(unordered_map<int, pipe> pipes) {
	int action;
	unordered_map<int, int> selectpipes;
	while (true) {
		cout << "1. Select pipes by name. " << endl
			<< "2. Select pipe based on the characteristics in repair. " << endl
			<< "0. Exit. " << endl
			<< "Chose action: ";
		getcorrectnumber(action);
		switch (action) {
		case 1: {
			string name;
			cout << "Enter pipe name: ";
			getline(cin, name);
			for (auto p : pipes) {
				if (p.second.name.find(name) != string::npos) {
					selectpipes[selectpipes.size() + 1] = p.second.id;
					cout << "Success." << endl;
				}
			}
			break;
		}
		case 2: {
			bool characteristic;
			cout << "Enter characteristic in repair (0 or 1): ";
			getcorrectnumber(characteristic);
			for (auto p : pipes) {
				if (p.second.inrepair == characteristic) {
					selectpipes[selectpipes.size() + 1] = p.second.id;
					cout << "Success." << endl;
				}
			}
			break;
		}
		case 0: {
			return selectpipes;
			break;
		}
		}
		if (selectpipes.size() == 0) {
			cout << "Pipe wasn't found." << endl;
		}
	}
	return selectpipes;
}