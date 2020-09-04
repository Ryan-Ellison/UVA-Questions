// uva11935.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define pos first
#define type second[0]
#define fuel second[1]

const double eps = 10E-6;
vector<pair<int, string> > road;

double journeySuccess(double v) {
	double g = v, c = 0, l = 0, prevPos = 0;
	for (size_t i = 0; i < road.size(); ++i) {
		g -= (road[i].pos - prevPos) * (l + c / 100.0);
		if (i < road.size() - 1)
			switch (road[i].type) {
			case 'F': c = road[i].fuel; break;
			case 'L': ++l; break;
			case 'G': g = (g >= 0 ? v : g); break;
			case 'M': l = 0; break;
			default: break;
			}
		prevPos = road[i].pos;
	}
	return g;
}

int main() {
	int p, t = 1, nLeak, maxT;
	string s;
	ostringstream e;
	cout.precision(3);
	while (true) {
		// input
		road.clear();
		maxT = nLeak = 0;
		do {
			cin >> p >> s, e.str(""), e << s[0];
			if (s[0] == 'L')
				++nLeak;
			if (s[0] == 'G' && s[1] == 'a')
				cin >> s;
			if (s[0] == 'F' && cin >> s >> t)
				e << (char)t, maxT = max(maxT, t);
			if (!t && !road.size())
				return 0;
			road.push_back(make_pair(p, string(e.str())));
		} while (s[0] != 'G' || s[1] != 'o');
		// solve
		double lV = 0, mV, hV = p * (maxT / 100.0 + nLeak), j;
		do {
			mV = (hV + lV) / 2;
			if ((j = journeySuccess(mV)) > 0)
				hV = mV;
			else
				lV = mV;
		} while (hV - lV > eps || j < 0);
		cout << fixed << ((hV + lV) / 2) << endl;
	}
	return 0;
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
