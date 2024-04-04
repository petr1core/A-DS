#include <iostream>
#include <string>
#include "TableMixLib/TableMix.h"
using namespace std;

const int MAX_SIZE = 26;
const int NAME_SIZE = 5;
const char letters[MAX_SIZE] = { 
        'a','b','c','d','e','f',
        'g','h','i','j','k','l',
        'm','n','o','p','q','r',
        's','t','u','v','w','x',
        'y','z' 
    };
void menu(void)
{
    printf("\n1. Выбрать элемент в линейной таблице на массиве\n");
    printf("2. Выбрать элемент в линейной таблице на списке\n");
    printf("3. Выбрать элемент в упорядоченной таблице на массиве\n");
    printf("4. Выбрать элемент в дереве поиска\n");
    printf("5. Выбрать элемент в дереве AVL\n");
    printf("6. Выбрать элемент в хэш-таблице с повторением\n");
    printf("7. Выбрать элемент в хэш-таблице цепочкой\n");
    printf("8. Добавить элемент\n");
    printf("9. Удалить элемент\n");
    printf("10. Выход\n");
}

void info(MixTable<string, TPolinom>& tab, const vector<string>& keys) {
    if (tab.GetSize() != 0)
        cout << "\nSize = " << tab.GetSize() << "\nKeys:";
    else 
        cout << "\nSize = 0"  << "\nKeys:";

    for (int i = 0; i < keys.size(); i++) {
        cout << "\n" << keys[i];
    }
}

string generate_rand_string() {
    srand(time(NULL));
    string str = "";
    for (int i = 0; i < NAME_SIZE; i++)
        str = str + letters[rand() % MAX_SIZE];
    return str;
}

int main() {
    

    setlocale(LC_ALL, "Russian");
    TPolinom p;
    TMonom newMonom;
    MixTable<string, TPolinom> t;
    vector<string> key_arr;
    srand(time(NULL));
    string key; 
    int s;
    double start, end;
    bool stop = false;
    while (!stop) {
        menu();
        cin >> s;
        switch (s)
        {
        case 1:
            start = clock();
            t.Find(1, key);
            end = clock();
            cout << (end - start) / CLOCKS_PER_SEC << endl;
            break;
        case 2:
            start = clock();
            t.Find(2, key);
            end = clock();
            cout << (end - start) / CLOCKS_PER_SEC << endl;
            break;
        case 3:
            start = clock();
            t.Find(3, key);
            end = clock();
            cout << (end - start) / CLOCKS_PER_SEC << endl;
            break;
        case 4:
            start = clock();
            t.Find(4, key);
            end = clock();
            cout << (end - start) / CLOCKS_PER_SEC << endl;
            break;
        case 5:
            start = clock();
            t.Find(5, key);
            end = clock();
            cout << (end - start) / CLOCKS_PER_SEC << endl;
            break;
        case 6:
            start = clock();
            t.Find(6, key);
            end = clock();
            cout << (end - start) / CLOCKS_PER_SEC << endl;
            break;
        case 7:
            start = clock();
            t.Find(7, key);
            end = clock();
            cout << (end - start) / CLOCKS_PER_SEC << endl;
            break;
        case 8:
            start = clock();
            key = generate_rand_string();
            key_arr.push_back(key);
            newMonom.SetMonom(
                rand() % (10 - 1 + 1) + 1,
                rand() % (10 - 1 + 1) + 1,
                rand() % (10 - 1 + 1) + 1,
                rand() % (10 - 1 + 1) + 1
            );
            p.AddMonom(newMonom);
            t.Add(key, p);
            info(t, key_arr);
            cout << endl;
            t.print();
            end = clock();
            cout << "\ntime: " << (end - start) / CLOCKS_PER_SEC << endl;
            break;
        case 9:
            info(t,key_arr);
            start = clock();
            t.Delete(key_arr[key_arr.size() - 1]);
            key_arr.pop_back();
            end = clock();
            cout << "\ntime: " << (end - start) / CLOCKS_PER_SEC << endl;
            break;
        case 10:
            stop = true;
            break;
        default:
            break;
        }
    }
    t.print();
}

