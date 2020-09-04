// UVA599.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <regex>

using namespace::std;

vector <string> fInput;

void readFile() {

	ifstream fileIn;
	string line;

	fileIn.open("Input.txt");

	while (getline(fileIn, line)) {

		fInput.push_back(line);
	}
}

bool contains(string line) {
	for (int k = 0; k < line.size(); k++) {
		if (line.at(k) == fInput.at(0).at(1) || line.at(k) == fInput.at(0).at(3)) 
			return true;
	}
	return false;
}

string removeDuplicates(string tree) {
	for (int k = 0; k < tree.size(); k++) {
		for (int j = k + 1; j < tree.size(); j++) {
			if (tree[k] == tree[j]) {
				tree.erase(tree.begin() + j);
				j--;
			}
		}
	}
	return tree;
}

bool findMatch(string one, string two) {
	for (int i = 0; i < one.size(); i++) {
		for (int j = 0; j < two.size(); j++) {
			if (one[i] == two[j]) {
				return true;
			}
		}
	}
	return false;
}

vector<string> combine(vector<string> trees) {
	for (int k = 0; k < trees.size()-1; k++) {
		for (int j = k+1; j < trees.size(); j++) {
			if (findMatch(trees[k], trees[j])) {
				trees[k] += trees[j];
				trees.erase(trees.begin() + j);
				j--;
			}
		}
	}
	return trees;
}


void execute()
{
	vector<string> trees;
	string input;
	bool newS;
	while (fInput.at(0).at(0) != '*'){
		newS = true;
		for (int k = 0; k < trees.size(); k++) {
			if (contains(trees.at(k))) {
				newS = false;
				trees.at(k) += string(1, fInput.at(0).at(1));
				trees.at(k) += string(1, fInput.at(0).at(3));
			}
		}
		if (newS) {
			trees.emplace_back(string(1, fInput.at(0).at(1)));
			trees[trees.size()-1] += string(1, fInput.at(0).at(3));
		}	
		fInput.erase(fInput.begin());
	}
	for (int k = 0; k < trees.size(); k++) {
		trees.at(k) = removeDuplicates(trees.at(k));
	}
	for (int i = 0; i < trees.size(); i++) {
		cout << trees[i] << "\n";
	}
	trees = combine(trees);
	fInput.erase(fInput.begin());
	string list = fInput.at(0);
	for (int k = 0; k < list.size(); k++) {
		if (list[k] == ',') {
			list.erase(list.begin() + k);
			k--;
		}
	}
	fInput.erase(fInput.begin());
	int acorns = list.size();
	for (int k = 0; k < list.size(); k++) {
		for (int i = 0; i < trees.size(); i++) {
			if (trees.at(i).find(list[k]) != trees.at(i).npos) {
				acorns--;
			}
		}
	}
	cout << "\nThere are " << trees.size() << " trees \nThere are " << acorns << " acorns \n";
}

int main()
{
	readFile();
	int runs = stoi(fInput.at(0));
	fInput.erase(fInput.begin());
	for (int i = 0; i < runs; i++) 
	{
		execute();
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
