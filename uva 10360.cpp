#include <cstdio>
#include <iostream>

using namespace std;

int main() {
	int scenarios;
	int strength;
	int n;
	int x;
	int y;
	int pop;
	int* killed[1024];
	int maxk;
	scanf("%d", &scenarios);
	
	while (scenarios--) 
	{
		scanf("%d", &strength);

		for (int k = 0; k < 1024; k++) {
			killed[k] = new int[1024]{ 0 };
		}

		scanf("%d", &n);
		for (int k = 0; k < n; k++) {
			scanf("%d %d %d", &x, &y, &pop);
			for (int i = x - strength; i < x + strength; i++) {
				for (int j = y - strength; j < j + strength; j++) {
					if (i >= 0 && j >= 0 && i < 1024 && j < 1024)
						killed[i][j] += pop;
				}
			}
		}

		maxk = 0;
		for (int k = 0; k < 1024; k++) {
			for (int i = 0; i < 1024; i++) {
				if (killed[k][i] > maxk){
					maxk = killed[k][i];
					x = k;
					j = i;
				]
			}
		}
			printf("%d %d %d", x, y, maxk);
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
