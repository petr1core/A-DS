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

template<class Key, class Value>
class MixTable {
private: 
    LinearArrTable<Key, Value> LATable;
    LinearListTable<Key, Value> ListTable;
    OrderedArrTable<Key, Value> OATable;
    SearchTreeTable <Key, Value> sTree;
    AVLTreeTable <Key, Value> AVLTree;
    HashChainTable<Key, Value> HashChain;
    HashRepeatTable<Key, Value> HashRepeat;
    int size = 0;
public:
    void Add(Key key, Value p) {
        LATable.Insert(key, p);
        ListTable.Insert(key, p);
        OATable.Insert(key, p);
        HashChain.Insert(key, p);
        HashRepeat.Insert(key, p);
        sTree.Insert(key, p);
        AVLTree.Insert(key, p);
       
      
       
        size++;
    }

    void Delete(Key key) {
        LATable.Delete(key);
        ListTable.Delete(key);
        OATable.Delete(key);
        HashChain.Delete(key);
        HashRepeat.Delete(key);
        sTree.Delete(key);
        AVLTree.Delete(key);
       
       
       
        size--;
    }
    void print() {
        cout << "///////////////////////////////////////////////////////" << endl;
        cout << LATable << endl << "||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << OATable << endl << "||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << HashChain << endl << "||||||||||||||||||||||||||||||||||||||||||" << endl;;
        cout << HashRepeat << endl << "||||||||||||||||||||||||||||||||||||||||||" << endl;;
        cout << ListTable << endl << "||||||||||||||||||||||||||||||||||||||||||" << endl;;
        sTree.print(sTree.root);
        cout << endl << "||||||||||||||||||||||||||||||||||||||||||" << endl;;
        AVLTree.root->print();
        cout << endl << "///////////////////////////////////////////////////////" << endl;;
        // остальные выводы //
    }
    int GetSize(void) {
        return this->size;
    }

    void Find(int id, Key key) {
        switch (id) {
        case 1: 
           cout << (LATable.Find(key) != nullptr) 
                ? 
                "\nSuccessfully finded in Linear Array Table\n" 
                : 
                "\nThere is no item like that in Linear Array Table\n";
            break;
        case 2: 
            cout << (ListTable.Find(key) != nullptr)
                ?
                "\nSuccessfully finded in Linear List Table\n"
                :
                "\nThere is no item like that in Linear List Table\n";
            break;
        case 3:  
            cout << (OATable.Find(key) != nullptr)
                ?
                "\nSuccessfully finded in Ordered Array Table\n"
                :
                "\nThere is no item like that in Ordered Array Table\n";
            break;
        case 4: 
            cout << (sTree.Find(key) != nullptr)
                ?
                "\nSuccessfully finded in Search Tree Table\n"
                :
                "\nThere is no item like that in Search Tree Table\n";
            break;
        case 5: 
            cout << (AVLTree.Find(key) != nullptr)
                ?
                "\nSuccessfully finded in AVL Tree Table\n"
                :
                "\nThere is no item like that in AVL Tree Table\n";
            break;
        case 6: 
            cout << (HashRepeat.Find(key) != nullptr)
            ?
                "\nSuccessfully finded in Hash Open-bufferred Table\n"
                :
                "\nThere is no item like that in Hash Open-bufferred Table\n";
            break;
        case 7: 
            cout << (HashChain.Find(key) != nullptr)
            ?
                "\nSuccessfully finded in Hash Chain Table\n"
                :
                "\nThere is no item like that in Hash Chain Table\n";
            break;
        default: break;
        }
    }
};