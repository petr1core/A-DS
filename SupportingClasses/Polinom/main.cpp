#include <iostream>

//template <typename T>
//class LinkedList {
//private:
//    struct Node {
//        T data;
//        Node* next;
//
//        Node(const T& value) : data(value), next(nullptr) {}
//    };
//
//    Node* first;
//    Node* last;
//    Node* current;
//    Node* previous;
//    int count;
//
//public:
//    LinkedList() : first(nullptr), last(nullptr), current(nullptr), previous(nullptr), count(0) {}
//
//    ~LinkedList() {
//        Node* temp = first;
//        while (temp != nullptr) {
//            Node* next = temp->next;
//            delete temp;
//            temp = next;
//        }
//    }
//
//    void Add(const T& value) {
//        Node* newNode = new Node(value);
//
//        if (first == nullptr) {
//            first = newNode;
//            last = newNode;
//        }
//        else {
//            last->next = newNode;
//            last = newNode;
//        }
//
//        count++;
//    }
//
//    void Remove(const T& value) {
//        if (first == nullptr) {
//            return;
//        }
//
//        current = first;
//        previous = nullptr;
//
//        while (current != nullptr && current->data != value) {
//            previous = current;
//            current = current->next;
//        }
//
//        if (current == nullptr) {
//            return;
//        }
//
//        if (previous != nullptr) {
//            previous->next = current->next;
//        }
//
//        if (current == first) {
//            first = first->next;
//        }
//
//        if (current == last) {
//            last = previous;
//        }
//
//        delete current;
//        current = nullptr;
//
//        count--;
//    }
//
//    int Count() const {
//        return count;
//    }
//
//    void Print() const {
//        Node* temp = first;
//        while (temp != nullptr) {
//            std::cout << temp->data << " ";
//            temp = temp->next;
//        }
//        std::cout << std::endl;
//    }
//};

#include "List/ListLib/List.h"
#include "PolinomLib/TPolinom.h"
//mb nuzhen vector
#include <iostream>

int main() {
	/*TDynamicVector<TMonom> vec(2);
	TMonom a(1, 2, 3, 4), b(2, 6, 7, 8), c(3, 2, 3, 4), t(5, 1, 2, 1);

	vec[0] = a;
	vec[1] = b;


	TPolinom polinom(vec);
	cout << "The initial polinomial: " << polinom.ToString() << endl;
	polinom.AddMonom(c);
	cout << "Add monom 3x^2y^3z^4 : " << polinom.ToString() << endl;
	polinom.AddMonom(t);
	cout << "Add monom 5x^1y^2z^1 : " << polinom.ToString() << endl;*/
	//TPolinom p2, result; 
	//string str1, str2;
	//cout << "Enter the first polynom\n";
	//cin >> str1;
	//TPolinom p1(str1);
	//cout << "Enter the second polynom\n";
	//cin >> str2;
	//TPolinom p2(str2);
	//result = p1 + p2;
	//cout << "First Polynom: " << p1.ToString() << endl;
	//cout << "First Polynom: " << p2.ToString() << endl; 
	//cout << "First Polynom: " << result.ToString() << endl;
	return 0;
}