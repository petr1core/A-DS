#pragma once
#include "BaseTableLib/BTable.h"
#include <vector>
using namespace std;

template<class Key, class Value>
class HashTable : public Table<Key,Value>
{
protected:
	vector<Row> vec;
public:
	Value* Find(Key _key) override;
	int Insert(Key _key, Value _val) override;
	int Delete(Key _key) override;

	void Reset(void) override;
	bool IsTabEnded(void) const override;
	int GoNext(void) override;

	Key GetKey(void) const override;
	Value* GetValuePtr(void) override;	//	(=1 first el, if called on last cell of table)				
};

template<class Key, class Value>
Value* HashTable<Key, Value>::Find(Key _key)
{
	int t = this->HashKey(this->keyToString(_key));
	for (int i = 0; i < this->size; i++) {
		if (vec[i].key == t) {
			return &(vec[i].key);
		}
	}
	return nullptr;
}

template<class Key, class Value>
int HashTable<Key, Value>::Insert(Key _key, Value _val)
{
	if (this->IsFull()) return -1;
	if (this->Find(this.))
	return nullptr;
}