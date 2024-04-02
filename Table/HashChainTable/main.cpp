#include <iostream>
#include "HashChainTableLib/HCTable.h"
using namespace std;
int main() {
	HashChainTable<int, std::string> t;
	t.Insert(1, "sas");
	t.Insert(2, "saaas");
	t.Insert(3, "xczxczxc");
	t.Insert(4, "saadsadsacas");
	t.Insert(6, "saaasdasds");
	t.Insert(1212, "s vcxvaas");


	std::cout << t << std::endl;
	//t.Delete(1);
	//std::cout << t << std::endl;
}