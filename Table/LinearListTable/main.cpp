#include <iostream>
#include <string>
#include "LinearListTableLib/LinListTable.h"
using namespace std;

int main() {
	LinearListTable<int, string> t;
	t.Insert(11, "0000");
	t.Insert(2, "xsds");
	t.Insert(4, "vsdvxs");
	t.Insert(32, "mmsds");
	t.Insert(21, "22s2dsds");
	cout << t << endl;
	t.Delete(4);
	cout << t;
}