//============================================================================
// Name        : Eclipse.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int mcd(int dias1, int dias2) {

	int mcd;

	while (dias1 != dias2) {
		if (dias1 > dias2)
			dias1 = dias1 - dias2;
		else
			dias2 = dias2 - dias1;
	}

	mcd = dias1;
	return mcd;
}

int main() {

	int cases;
	int casesIt;
	int resIterator = 0;
	cin >> cases;

	casesIt = cases;

	int results[cases];

	while (casesIt > 0) {

		int planet1 = 0;
		int planet2 = 0;

		cin >> planet1;
		cin >> planet2;

		int m = mcd(planet1, planet2);

		int mult = planet1 * planet2;

		int result = mult / m;

		results[resIterator] = result;

		resIterator++;

		casesIt--;

	}

	for (int print = 0; print < cases; print++) {

		cout << results[print] << endl;

	}

}
