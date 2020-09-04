// UVA11572.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>

using namespace::std;

int testCases;
map<int, int> snowflakePos;

static int uniques(int snowflakes) 
{
	int type;
	int maxLength = 0;
	int lastPos = 0;
	bool lastNew = true;
	for (int k = 0; k < snowflakes; k++) {
		cin >> type;
		if (snowflakePos.count(type) == 0) {
			snowflakePos.emplace(type,k);
			lastNew = true;
		}
		else {
			if (maxLength < (k - lastPos)) 
				maxLength = (k - lastPos);
			
			if (lastPos < snowflakePos[type] + 1) 
				lastPos = snowflakePos[type] + 1;
			lastNew = false;
			snowflakePos[type] = k;
		}	

	}

	if (lastNew && maxLength < (snowflakes - lastPos)) 
		maxLength = snowflakes - lastPos;

	return maxLength;
}

int main()
{
	int snowflakes;
	int length;
	cin >> testCases;
	for (int k = 0; k < testCases; k++) {
		cout << "\n \n new set \n \n";
		cin >> snowflakes;
		length = uniques(snowflakes);
		cout << "Max length is: " << length << "\n";
		snowflakePos.clear();
	}
}

