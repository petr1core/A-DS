#include <iostream>
#include <string>
#include "TableMixLib/TableMix.h"
using namespace std;

const int MAX_SIZE = 26;
void menu()
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

string generate_rand_string() {
    srand(time(0));
    string str = "";
    for (inti = 0; i < n; i++)
        ran = ran + letters[rand() % MAX_SIZE];
    return str;
}

int main() {
    
    char letters[MAX_SIZE] = { 
        'a','b','c','d','e','f',
        'g','h','i','j','k','l',
        'm','n','o','p','q','r',
        's','t','u','v','w','x',
        'y','z' 
    };

    setlocale(LC_ALL, "Russian");
    TPolinom p;
    MixTable t;
    srand(time(NULL));

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
            t.Add(key, p);
            end = clock();
            cout << (end - start) / CLOCKS_PER_SEC << endl;
            break;
        case 9:
            int how;
            cout << "Хотите задать имя самостоятельно?\n1 - да\n2 - нет" << endl;
                cin >> how;
            start = clock();
            t.Delete(key);
            end = clock();
            cout << (end - start) / CLOCKS_PER_SEC << endl;
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
