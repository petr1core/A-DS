#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "BaseTableLib/BTable.h"
#include "Polinom/PolinomLib/List.h"
using namespace std;

template<class Key, class Value>
class HashTable : public Table<Key, Value>
{
protected:
	TList<Row> list;
	int HashKey(string _key) const;
public:
	Value* Find(Key _key) override;
	virtual int Insert(Key _key, Value _val) = 0;
	virtual int Delete(Key _key) = 0;

	virtual void Reset(void) = 0;
	virtual bool IsTabEnded(void) const = 0;
	virtual int GoNext(void) = 0;

	virtual Key GetKey(void) const = 0;
	virtual Value* GetValuePtr(void) = 0;	//	(=1 first el, if called on last cell of table)
	//operator std::string() const {
	//	std::ostringstream ostring;
	//	ostring << (int)GetKey();
	//	return ostring;
	//}

};
template<typename Key>
std::string keyToString(const Key& k)
{
	std::ostringstream ostring;
	ostring << k;
	return ostring.str();
}

template<class Key, class Value>
int HashTable<Key, Value>::HashKey(string _key) const
{
	int res = 0;
	for (int i = 0; i < _key.length(); i++)
		res += _key[i];
	return res %= this->maxsize;
}