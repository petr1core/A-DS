#pragma once
#include "TreeAVLTableLib/SearchTreeTable.h"
using namespace std;

template<class Key, class Value>
int SearchTreeTable<Key, Value>::number = 0;
template<class Key, class Value>
class AVLTreeTable : public SearchTreeTable<Key, Value> {
public:
	struct Table {
		Key key;
		Value value;
	};
	struct Node
	{
		Table data;
		Node* left;
		Node* right;
		Node* parent;
		int balance;
		Node(Key key, Value value) {
			left = nullptr;
			right = nullptr;
			data.key = key;
			data.value = value;
			this->parent = nullptr;
			balance = 0;
		}
		Node(Node* l, Node* r, Key key, Value value) {
			left = l;
			right = r;
			data.key = key;
			data.value = value;
			l->parent = r->parent = this;
			balance = this.update_balance();
		}

		void update_balance2() {
			Node* n = this->parent;
			if (n == nullptr) {
				if (n->left == this) { this->balance--; }
				else { this->balance++; }
				return;
			}
			if (n->left == this) { this->balance--; }
			else { this->balance++; }
			this->update_balance2();
		}
		Node* update_balance() {
			if (this != nullptr) {
				this->balance = get_height(this->right) - get_height(this->left);
				if ((this->balance == 2) || (this->balance == -2)) { this->balancir(); }
				if (this->parent != nullptr) { this->parent->update_balance(); }
			}
			else return this;
		}
		int get_height(Node* node) {
			if (node == nullptr) return -1;
			return 1 + max(get_height(node->left), get_height(node->right));
		}
		Node* balancir() {
			if (this->balance == -2)
			{
				if (this->left->balance < 0)
				{
					cout << "1" << endl; this->singleUpLeft();  return this;
				}
				if (this->left->balance > 0)
				{
					cout << "2" << endl; this->doubleUpLeft();  return this;
				}
			}
			if (this->balance == 2) {
				if (this->right->balance < 0)
				{
					cout << "3" << endl; this->singleUpRight(); return this;
				}
				if (this->right->balance > 0)
				{
					cout << "4" << endl; this->doubleUpRight(); return this;
				}
			}
			return this;
		}
		Node* singleUpLeft() {
			Node* B = this->left;

			if (this->parent != nullptr) {
				if (this == ((this->parent)->left)) {
					B->parent = this->parent;
					(B->parent)->left = B;
				}
				else {
					(B->parent)->right = B;
					B->parent = this->parent;
				}
			}
			else { B->parent = this->parent; }

			this->left = B->right;
			B->right = this;
			this->parent = B;
			this->update_balance();
			B->update_balance();
			return B;
		}
		Node* singleUpRight() {
			Node* B = this->right;

			if (this->parent != nullptr) {
				if (this == ((this->parent)->right)) {
					B->parent = this->parent;
					(B->parent)->left = B;
				}
				else {
					(B->parent)->left = B;
					B->parent = this->parent;
				}
			}
			else { B->parent = this->parent; }

			this->right = B->left;
			B->left = this;
			this->parent = B;
			this->update_balance();
			B->update_balance();
			return B;
		}
		Node* doubleUpLeft() {
			Node* B = this->left;
			Node* C = B->right;

			if (this->parent != nullptr) {
				if (this == ((this->parent)->left)) {
					C->parent = this->parent;
					(C->parent)->left = C;
				}
				else {
					(C->parent)->right = C;
					C->parent = this->parent;
				}
			}
			else { C->parent = this->parent; }

			B->right = C->left;
			C->left = B;
			this->left = C->right;
			C->right = this;
			B->parent = C;
			this->parent = C;
			this->update_balance();
			B->update_balance();
			C->update_balance();
			return C;
		}
		Node* doubleUpRight() {
			Node* B = this->right;
			Node* C = B->left;

			if (this->parent != nullptr) {
				if (this == ((this->parent)->left)) {
					C->parent = this->parent;
					(C->parent)->left = C;
				}
				else {
					(C->parent)->right = C;
					C->parent = this->parent;
				}
			}
			else { C->parent = this->parent; }

			B->left = C->right;
			C->right = B;
			this->right = C->left;
			C->left = this;
			B->parent = C;
			this->parent = C;
			this->update_balance();
			B->update_balance();
			C->update_balance();
			return C;
		}
		void print() {
			if (this == nullptr) return;
			this->left->print();
			if (this->parent == nullptr)
				cout << "Parent: null, ";
			else
				cout << "Parent: " << this->parent->data.key << ", ";
			cout << "Key:" << this->data.key /* << ", Value: " << n->data.value */ << ", Balance: " << this->balance << ", Left potomok: ";
			if (this->left == nullptr)
				cout << "null " << ", ";
			else { cout << this->left->data.key << " ,"; }
			if (this->right == nullptr)
				cout << "Right potomok: null " << " )" << endl;
			else { cout << "Right potomok: " << this->right->data.key << " )" << endl; }
			this->right->print();
		}
	};
	Node* root;
public:
	AVLTreeTable() {
		TPolinom p; root = new Node(2, p);
		root->balance = 0;
	}
	AVLTreeTable(int key, int value) {
		root = new Node(key, value);
		root->balance = 0;
	}
	AVLTreeTable(AVLTreeTable p1, AVLTreeTable p2, int key, int value) {
		root = new Node(p1.root, p2.root, key, value);
		root->balance = p2.root->balance - p1.root->balance;
	}
	string toString() {
		string res;
		res += "(" + std::to_string(root->data.key) + ", " + std::to_string(root->data.value) + ", " + std::to_string(root->balance) + ")";
		return res;
	}
	void print2(Node* node) {
		Node* n = node;
		while (n->parent != nullptr) { n = node->parent; }
		print2(n);
	}

	Value* Find(Key key)
	{
		Node* node = findNode(key, root);
		if (node == nullptr) { return nullptr; }
		return &node->data.value;
	}
	Node* findNode(Key key, Node* node) {
		if (node == nullptr) {
			return nullptr;
		}
		if (key < node->data.key) {
			return findNode(key, node->left);
		}
		else if (key > node->data.key) {
			return findNode(key, node->right);
		}
		else {
			return node; // ���������� ����, ���� ���� ���������
		}
	}

	int Insert(Key _key, Value _val) {
		if (this->Find(_key) != nullptr) {
			// ���� � ����� ������ ��� ����������, ������� �� ���������
			return 0;
		}
		else {
			// ������� ����� ����
			Node* new_node = new Node(_key, _val);
			if (root == nullptr) {
				root = new_node; // ���� ������ ������, ����� ���� ���������� ������
				return 1; // �������� ������� ������ ����
			}
			Node* current = root;
			Node* parent = nullptr;
			// ������� ����� ��� ������� ����� �������
			while (current != nullptr) {
				parent = current;
				if (_key < current->data.key) {
					current = current->left;
				}
				else {
					current = current->right;
				}
			}
			// ��������� ����� ������� � ������������� ������ �� ��������
			if (_key < parent->data.key) {
				parent->left = new_node;
			}
			else {
				parent->right = new_node;
			}
			// �������������� �������� �� �������� �������
			if (parent->left == nullptr && parent->right == nullptr) {
				parent->update_balance(); // ��������� ������ � ��������� ������
			}
			new_node->parent = parent;
			if (root->parent != nullptr) {
				root = root->parent; // ���������� ����� ������
			}
			new_node->update_balance();
			if (root->parent != nullptr) {
				root = root->parent; // ���������� ����� ������
			}
			return 1; // �������� ������� ������ ����
		}
	}
	int Delete(Key _key) {
		if ((this->Find(_key) == nullptr) || (root == nullptr)) {
			// ���� � ����� ������ �� ����������, �������� �� ���������
			return 0;
		}
		else {
			this->root = deleteNode(root, _key);
			this->root->update_balance();
			return 1; // �������� �������� ����
		}
	}
	Node* deleteNode(Node* currentNode, Key _key) {
		if (currentNode == nullptr) return nullptr;

		if (_key < currentNode->data.key) {
			currentNode->left = deleteNode(currentNode->left, _key);
		}
		else if (_key > currentNode->data.key) {
			currentNode->right = deleteNode(currentNode->right, _key);
		}
		else {
			// ������ ��� 0 ��������
			if ((currentNode->left == nullptr) && (currentNode->right == nullptr)) {
				if ((currentNode->parent)->left == currentNode) { (currentNode->parent)->left = nullptr; }
				else { (currentNode->parent)->right = nullptr; }
				delete currentNode;
				return nullptr;
			}
			else if (currentNode->left != nullptr && currentNode->right != nullptr) {
				Node* temp = maxValueNode(currentNode->left);
				currentNode->data = temp->data;
				deleteNode(currentNode->left, temp->data.key);
				return currentNode;
			}
			else {
				Node* temp = (currentNode->left != nullptr) ? currentNode->left : currentNode->right;
				if (currentNode->parent == nullptr) {
					currentNode = temp;
					delete temp;
					return currentNode;
				}
				else {
					if (currentNode == currentNode->parent->left) {
						currentNode->parent->left = temp;
					}
					else {
						currentNode->parent->right = temp;
					}
					temp->parent = currentNode->parent;
					delete currentNode;
					return temp;
				}
			}
		}
		return currentNode;
	}
	Node* maxValueNode(Node* node) {
		Node* current = node;
		while (current->right != nullptr) {
			current = current->right;
		}
		return current;
	}
};