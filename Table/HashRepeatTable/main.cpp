#include <iostream>
#include "HashRepeatTableLib/HRTable.h"
#include "vector"

using namespace std;
int main() {
	HashRepeatTable<int, std::string> t;
	t.Insert(12, "(12 good table)");//
	t.Insert(32, "(32 good table)");//
	t.Insert(45, "(45 good table)");//
	t.Insert(12, "(12 good table)");
	t.Insert(2, "(2 good table)");//
	t.Insert(1, "(1 good table)");
	t.Insert(1, "(1 good table)");
	t.Insert(1, "(1 good table)");
	t.Insert(1, "(1 good table)");
	t.Insert(1, "(1 good table)");
	t.Insert(1, "(1 good table)");
	t.Insert(1, "(1 good table)");
	t.Insert(1, "(1 good table)");
	//12 el-s

	cout << t << "GetSize() = " << t.GetSize() <<
		" ; GetSize()/MaxSize = " << t.GetSize() / 10000.0 <<
		endl << "GetFullness() = " << t.Getfullness() << 
		" ; GetCount()/GetSize() = " <<
		t.GetCount() / (double)t.GetSize() <<
		endl;

	t.Delete(1);
	t.Delete(45);
	//10 el-s
	cout << t << endl;

	
	return 0;
}