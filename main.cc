#include <iostream>
#include <stdexcept>
#include <stdlib.h>
//#include <stdio.h>
//#define DEBUG 10
//#include "debug.h"
#include "matrix1.h"

using namespace std;

int main()
{
  try {
	Matrix <int> matr1(3);
	int ar[9] = { 
		1, 2, 3, 
		4, 5, 4, 
		3, 2, 1 
			};
	matr1.set(ar, 9);
	cout << matr1 << endl;

	Matrix <int> matr2(3);
	int ar2[9] = { 
		5, 4, 3, 
		2, 1, 2, 
		3, 4, 5 
			};
	matr2.set(ar2, 9);
	cout << matr2 << endl;

	Matrix <int> matr3(3);

	matr3 = matr1 + matr2;
	cout << matr3 << endl;

	matr3 = matr1 - matr2;
	cout << matr3 << endl;

	matr3 = matr1 * matr2;
	cout << matr3 << endl;
  }
  catch (exception &e) {
	//PDEBUG(1, "exept. %s", e.what());
  }
  catch (const char*) {
	//PDEBUG(1, "exept. %s", s);
  }
  catch (int) { 
	/*PDEBUG(1, "exept. negative size %d", k)*/
  }
}
