#include <iostream>
#include "HashRepeatTableLib/HRTable.h"
#include "vector"

using namespace std;
int main() {
	HashRepeatTable<int, std::string> t;
	t.Insert(12, "stupid table");
	t.Insert(1, "good table");
	return 0;
}