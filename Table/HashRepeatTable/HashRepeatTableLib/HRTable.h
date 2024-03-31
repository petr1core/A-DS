#pragma once
#include "BaseTableLib/BTable.h"
#include <vector>

template<class Key, class Value>
class HashRepeatTable : public Table<Key, Value>
{
private:
	vector<Row> vec;
protected:
	
	int HashKey(string _key) const;
	int Rehash(string _key, int seed) const;
	std::string keyToString(const Key& k);
	
public:
	Value* Find(Key _key) override;
	int Insert(Key _key, Value _val) override;
	int Delete(Key _key) override;
	void Reset(void) override;
	bool IsTabEnded(void) const override;
	int GoNext(void) override;

	Key GetKey(void) const override;
	Value* GetValuePtr(void) override;
};
template<typename Key>
std::string keyToString(const Key& k)
{
	std::ostringstream ostring;
	ostring << k;
	return ostring.str();
}

template<class Key, class Value>
int HashRepeatTable<Key, Value>::HashKey(string _key) const
{
	int res = 0;
	for (int i = 0; i < _key.length(); i++)
		res += _key[i];
	return res %= this->maxsize;
}

template<class Key, class Value>
int HashRepeatTable<Key, Value>::Rehash(string _key, int seed) const
{
	int res = seed;
	for (int i = 0; i < _key.length(); i++)
		res += _key[i];
	return res %= this->maxsize;
}

template<class Key, class Value>
Value* HashRepeatTable<Key, Value>::Find(Key _key)
{
	if (this->IsEmpty()) return nullptr;
	int hk = this->HashKey(keyToString(_key));
	for (int i = 0; i < this->vec.size(); i++) {
		if (vec[i].key == hk) {
			return &(vec[i].value);
		}
	}
	return nullptr;
}


template<class Key, class Value>
int HashRepeatTable<Key, Value>::Insert(Key _key, Value _val)
{
	if (this->IsFull()) return -1;
	int hk = this->HashKey(keyToString(_key));
	if (this->Find(_key) != nullptr) {
		int seed = rand() % (this->maxsize + 1);
		hk = this->Rehash(keyToString(_key), seed);
	}
	//вставка
	vec.push_back({ hk, _val });
	this->size++;
}
