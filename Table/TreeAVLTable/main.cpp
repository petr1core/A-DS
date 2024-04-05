#include <iostream>
#include "TreeAVLTableLib/TreeAVL_Table.h"
#include <string>
using namespace std;
int main() {
	AVLTreeTable<int, string> t;
	t.Insert(0, "aaa");
	t.Insert(-1, "bbb");
	t.Insert(-2, "ccc");

	//t.Delete(0);
	t.Delete(-1);

	t.Insert(0, "aaa");
	t.Insert(70, "aaa");
	t.Insert(-25, "aaa");
	cout << "done!";
}