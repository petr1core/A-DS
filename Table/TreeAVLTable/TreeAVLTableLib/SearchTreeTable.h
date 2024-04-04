#pragma once
#include "Polinom/PolinomLib/TPolinom.h"
#include "TableBaseLib/TableBase.h"

using namespace std;

template<class Key, class Value>
class SearchTreeTable : public Table<Key, Value> {
protected:
	/*struct Table {
		Key key;
		Value value;
	};*/
	struct Node
	{
		Row data;
		Node* left;
		Node* right;
		Node* parent;
		Node(Key key, Value value) {
			left = nullptr;
			right = nullptr;
			data.key = key;
			data.value = value;
			this->parent = nullptr;
		}
		Node(Node* l, Node* r, Key key, Value value) {
			left = l;    
			right = r;
			data.key = key;
			data.value = value;
			l->parent = r->parent = this;
		}
		void operator=(const Node& other) {
			parent = other.parent;
			left = other.left;
			right = other.right;
			data.key = other.data.key;
			data.value = other.data.value;
		}
	};
public:
	Node* root;

	SearchTreeTable() 
	{ 
		//TPolinom p; 
		//root = new Node(Key(), Value());
		root = nullptr;
		//root->parent = nullptr;
	}
	SearchTreeTable(int key, TPolinom value) 
	{ 
		root = new Node(key, value);
	}
	SearchTreeTable(SearchTreeTable p1, SearchTreeTable p2, int key, TPolinom value) 
	{
		root = new Node(p1.root, p2.root, key, value); 
		root->parent = nullptr; 
	}
	string toString() {
		string res;
		res += "(" + std::to_string(root->data.key) + ", " + std::to_string(root->data.value) + ")";
		return res;
	}
	Node* findNode(Key _key, Node* node)
	{
		if (node == nullptr) {
			return nullptr;
		}
		if (_key < node->data.key) {
			return findNode(_key, node->left);
		}
		else if (_key > node->data.key) {
			return findNode(_key, node->right);
		}
		else {
			return node; // Возвращаем узел, если ключ совпадает
		}
	}
	Node* deleteNode(Node* currentNode, Key _key)
	{
		if (currentNode == nullptr) return nullptr;

		if (_key < currentNode->data.key) {
			currentNode->left = deleteNode(currentNode->left, _key);
		}
		else if (_key > currentNode->data.key) {
			currentNode->right = deleteNode(currentNode->right, _key);
		}
		else {
			// случай для 0 потомков
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
	Node* maxValueNode(Node* node)
	{
		Node* current = node;
		while (current->right != nullptr) {

			current = current->right;
		}
		return current;
	}

	int Insert(Key _key, Value _val) override;
	int Delete(Key _key) override;
	Value* Find(Key _key) override;
	
	void Reset(void) override;
	int GoNext(void) override;
	bool IsTabEnded(void) const override;
	
	Key GetKey(void) const override;
	Value* GetValuePtr(void) override;
	
	void print(Node* node);
};
template<class Key, class Value>
Value* SearchTreeTable<Key,Value>::GetValuePtr(void) 
{
	//return this->GetValuePtr();
	return &Value();
}

template<class Key, class Value>
Key SearchTreeTable<Key, Value>::GetKey(void) const {
	//return this->GetKey(); 
	return Key();
}

template<class Key, class Value>
int SearchTreeTable<Key, Value>::GoNext(void)
{ 
	return 0;
}

template<class Key, class Value>
bool SearchTreeTable<Key, Value>::IsTabEnded(void) const 
{ 
	return false;
}

template<class Key, class Value>
void SearchTreeTable<Key, Value>::Reset(void) 
{ 
	int i = 0;
}


template<class Key, class Value>
int SearchTreeTable<Key, Value>::Delete(Key _key) 
{
	if ((this->Find(_key) == nullptr) || (root == nullptr)) {
		// Узел с таким ключом не существует, удаление не требуется
		return 0;
	}
	else {
		root = deleteNode(root, _key);
		return 1; // Успешное удаление узла
	}
}

template<class Key, class Value>
int SearchTreeTable<Key, Value>::Insert(Key _key, Value _val) 
{
	if (this->Find(_key) != nullptr) {
		// Узел с таким ключом уже существует, вставка не требуется
		return 0;
	}
	else {
		// Создаем новый узел
		Node* new_node = new Node(_key, _val);
		if (root == nullptr) {
			root = new_node; // Если дерево пустое, новый узел становится корнем
			root->parent = nullptr;
			return 1; // Успешная вставка нового узла
		}
		Node* current = root;
		Node* parent = nullptr;
		// Находим место для вставки новой вершины
		while (current != nullptr) {
			parent = current;
			if (_key < current->data.key) {
				current = current->left;
			}
			else {
				current = current->right;
			}
		}
		// Вставляем новую вершину и устанавливаем ссылку на родителя
		if (_key < parent->data.key) {
			parent->left = new_node;
		}
		else {
			parent->right = new_node;
		}
		new_node->parent = parent;
		return 1; // Успешная вставка нового узла
	}
}

template<class Key, class Value>
Value* SearchTreeTable<Key, Value>::Find(Key _key) 
{
	Node* node = findNode(_key, root);
	if (node == nullptr) { return nullptr; }
	return &node->data.value;
}

template<class Key, class Value>
void SearchTreeTable<Key, Value>::print(Node* node) 
{
	if (node == nullptr) return;
	print(node->left);
	//cout << "(Left potomok: ";
	if (node->parent == nullptr)
		cout << "Parent: null, ";
	else
		cout << "Parent: " << node->parent->data.key << ", ";
	cout << "Key:" << node->data.key << ", Value: " << node->data.value.ToString() << ", Left potomok: ";
	if (node->left == nullptr)
		cout << "null, Right potomok: ";
	else { cout << node->left->data.key << " Right Potomok: "; }
	if (node->right == nullptr)
		cout << "null " << ")" << endl;
	else { cout << node->right->data.key << " )" << endl; }
	print(node->right);
}
