#include <iostream>
#include <string>
#include "LinearListTableLib/LinListTable.h"
using namespace std;

int main() {
	LinearListTable<int, string> t;
	t.Insert(11, "eleven");
	t.Insert(2, "two");
	t.Insert(4, "four");
	t.Insert(32, "32");
	t.Insert(21, "21");
	cout << t << endl;
	cout << endl << "Delete key4, key21:" << endl << endl;
	t.Delete(4);
	t.Delete(21);
	cout << t;
}