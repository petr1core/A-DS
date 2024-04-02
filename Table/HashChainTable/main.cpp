#include <iostream>
#include "HashChainTableLib/HCTable.h"
using namespace std;
int main() {
	HashChainTable<int, std::string> t;
	t.Insert(1, "sas");
	std::cout << t << std::endl;
	t.Delete(1);
	std::cout << t << std::endl;
}