#include <iostream>
#include <string>
#include <xkeycheck.h>
#include "HashChainTableLib/HashChainTable.h"
#include "HashRepeatTableLib/HashRepeatTable.h"
#include "TreeAVLTableLib/SearchTreeTable.h"
#include "TreeAVLTableLib/TreeAVL_Table.h"
#include "ListLinearTableLib/ListLinearTable.h"
#include "ArrOrderedTableLib/ArrOrderedTable.h"
#include "ArrLinearTableLib/ArrLinearTable.h"
using namespace std;

class MixTable {
private:
    SearchTreeTable <string, TPolinom> sTree;
    AVLTreeTable <string, TPolinom> AVLTree;
public:
    void Add(string key, TPolinom p) {
        sTree.Insert(key, p);
        AVLTree.Insert(key, p);
    }

    void Delete(string key) {
        sTree.Delete(key);
        AVLTree.Delete(key);
    }
    void print() {
        sTree.print(sTree.root);
        AVLTree.root->print();
    }
    void Find(int id, string key) {
        switch (id) {
        case 1: //поиск в линейной на массиве
            break;
        case 2: //поиск в линейной на списке
            break;
        case 3:  //поиск в упорядоченной на массиве
            break;
        case 4: sTree.Find(key);
            break;
        case 5: AVLTree.Find(key);
            break;
        case 6: //поиск в хеше1
            break;
        case 7: //поиск в хеше2 
            break;
        default: break;
        }
    }
};