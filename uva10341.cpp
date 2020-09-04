// uva10341.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>



using namespace::std;

int main()
{
	int p;
	int q;
	int r;
	int s;
	int t;
	int u;
	cout.precision(4);
	double high;
	double mid;
	double low;
	double guess;
	while (scanf_s("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) == 6) {
		if (p * exp(-1) + q * sin(1) + r * cos(1) + s * tan(1) + t + u > 1e-9 || p + r + u < 0) {
			printf("No solution\n");
			continue;
		}
		low = 0.0;
		high = 1.0;

		for (int k = 0; k < 30; k++) {
			mid = (low + high) / 2.0;

			guess = p * exp(-1 * mid) + q * sin(mid) + r * cos(mid) + s * tan(mid) + t * mid * mid + u;

			if (guess > 0)
				low = mid;
			else
				high = mid;
		}
		cout << low << "\n";
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
