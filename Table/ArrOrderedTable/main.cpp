#include <iostream>
#include "ArrOrderedTableLib/ArrOrderedTable.h"
using namespace std;

int main() {
	OrderedArrTable<int, double> t;
	t.Insert(1, 12 / 1.0);
	t.Insert(7, 12 / 7.0);
	t.Insert(2, 12 / 2.0);
	t.Insert(3, 12 / 3.0);
	t.Insert(4, 12 / 4.0);
	t.Insert(5, 12 / 5.0);
	cout << t;
	t.Delete(2);
	cout << t;
	cout << *t.Find(7);


	return 0;
}