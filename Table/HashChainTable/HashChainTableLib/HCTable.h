#pragma once
#include <iostream>
#include <vector>
#include "BaseTableLib/BTable.h"
using namespace std;

template<class Key, class Value>
class HashTable : public Table<Key, Value>
{
	int HashKey(string _key) const;

public:
	Value* Find(Key _key) override;
	int Insert(Key _key, Value _val) override;
	int Delete(Key _key) override;

	void Reset(void) override;
	bool IsTabEnded(void) const override;
	int GoNext(void) override;

	Key GetKey(void) const override;
	Value* GetValuePtr(void) override;	//	(=1 first el, if called on last cell of table)
	operator std::string() const {
		std::ostringstream ostring;
		ostring << (int)GetKey();
		return ostring;
	}
};



template<class Key, class Value>
int HashTable<Key, Value>::HashKey(string _key) const
{
	int res = 0;
	
	for (int i = 0; i < _key.length(); i++)
		res += _key[i];
	return res %= this->maxsize;
}


template<class Key, class Value>
Value* HashTable<Key, Value>::Find(Key _key)
{
	int t = this->HashKey(_key);
	return nullptr;
}

template<class Key, class Value>
int HashTable<Key, Value>::Insert(Key _key, Value _val)
{

	return 0;
}

template<class Key, class Value>
int HashTable<Key, Value>::Delete(Key _key)
{

	return 0;
}

template<class Key, class Value>
void HashTable<Key, Value>::Reset(void)
{

	return;
}

template<class Key, class Value>
bool HashTable<Key, Value>::IsTabEnded(void) const
{

	return true;
}

template<class Key, class Value>
int HashTable<Key, Value>::GoNext(void)
{

	return 0;
}

template<class Key, class Value>
Key HashTable<Key, Value>::GetKey(void) const
{

	return NULL;
}

template<class Key, class Value>
Value* HashTable<Key, Value>::GetValuePtr(void) 
{

	return nullptr;
}