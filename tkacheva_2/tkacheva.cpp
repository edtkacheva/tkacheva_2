#include <iostream>
#include <fstream>
#include <unordered_map>
#include <stdio.h>
#include "pipe.h"
#include "cstation.h"
#include "header.h"
using namespace std;
int main() {
	unordered_map <int, pipe> pipes;
	unordered_map <int, cstation> cstations;
	while (true) {
		printmenu();
		int choice;
		getcorrectnumber(choice);
		switch (choice) {
		case 1: {
			pipe p;
			cin >> p;
			pipes [pipes.size() + 1] = p;
			break;
		}
		case 2: {
			cstation cs;
			cin >> cs;
			cstations [cstations.size() + 1] = cs;
			break;
		}
		case 3: {
			if (pipes.size() == 0) {
				cout << "There is no data about pipes" << endl;
			}
			else {
				for (auto& p : pipes) {
					cout << p.second;
				}
			}
			break;
		}
		case 4: {
			if (cstations.size() == 0) {
				cout << "There is no data about cstations" << endl;
			}
			else {
				for (auto& cs : cstations) {
					cout << cs.second;
				}
			}
			break;
		}
		case 5: {
			ofstream fout;
			string filename;
			cout << "Enter file name: ";
			cin >> filename;
			fout.open(filename, ofstream::app, ofstream::trunc);
			if (fout.is_open()) {
				if (pipes.size() == 0 && cstations.size() == 0) {
					cout << "There is no data about pipes and cstations." << endl;
				}
				else if (pipes.size() == 0 && cstations.size() != 0) {
					fout << cstations.size() << endl;
					fout << "Cstations: " << endl;
					for (auto& cs : cstations) {
						fout << cs.second;
					}
					cout << "There is no data about pipes." << endl;
				}
				else if (pipes.size() != 0 && cstations.size() == 0) {
					fout << pipes.size() << endl;
					fout << "Pipes: " << endl;
					for (auto& p : pipes) {
						fout << p.second;
					}
					cout << "There is no data about cstations." << endl;
				}
				else {
					fout << pipes.size();
					fout << "Pipes: " << endl;
					for (auto& p : pipes) {
						fout << p.second;
					}
					fout << cstations.size();
					fout << "Cstations: " << endl;
					for (auto& cs : cstations) {
						fout << cs.second;
					}
				}
				cout << "Data was successfully saved." << endl;
				fout.close();
			}
			else {
				cout << "File couldn't be open." << endl;
			}
			break;
		}
		case 6: {
			ifstream fin;
			string filename;
			string line;
			cout << "Enter file name: ";
			cin >> filename;
			fin.open(filename, ifstream::app);
			if (fin.is_open()) {
				if (fin.peek() == ifstream::traits_type::eof()) {
					cout << "There is no data in file or the file name is incorrect." << endl;
				}
				else {
					do {
						int i;
						fin >> i;
						getline(fin, line);
						if (line == "Pipes: ") {
							for (int count{ 0 }; count < i; count++) {
								pipe p;
								fin >> p;
								pipes[pipes.size() + 1] = p;
							}
						}
						else {
							for (int count{ 0 }; count < i; count++) {
								cstation cs;
								fin >> cs;
								cstations[cstations.size() + 1] = cs;
							}
						}
					} while (!fin.eof());
				}
			}
			else {
				cout << "File couldn't be open." << endl;
			}
			break;
		}
		case 7: {
			pipe p;
			p.deletepipes(pipes);
			break;
		}
		case 8: {
			cstation cs;
			cs.deletecstations(cstations);
			break;
		}
		case 9: {
			pipe p;
			p.changeinrepair(pipes);
			break;
		}
		case 10: {
			cstation cs;
			cs.changeworkshops(cstations);
			break;
		}
		case 0: {
			return 0;
			break;
		}
		default:
			cout << "Wrong choice! Try again!" << endl;
			break;
		}
	}
	return 0;
}