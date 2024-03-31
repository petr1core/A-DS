#pragma once
#include "BaseTableLib/BTable.h"
#include <vector>
#include <string>
#include "Polinom/PolinomLib/List.h"

using namespace std;

template<class Key, class Value>
class HashRepeatTable : public Table<Key, Value>
{
private:
	vector<Row> vec;
protected:
	int HashKey(Key _key) const;
	int Rehash(Key _key, int seed) const;
	std::string keyToString(const Key& k);
	int keyToInt(const Key& k);
	int simpleHash(Key k);
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


template<class Key, class Value>
int HashRepeatTable<Key, Value>::HashKey(Key _key) const
{
	int sum = 0;
	string str = to_string(_key);
	for (int i = 0; i < str.length(); i++)
		sum += str[i];
	return sum;
}

template<class Key, class Value>
int HashRepeatTable<Key, Value>::Rehash(Key _key, int seed) const
{
	int sum = seed;
	string str = to_string(_key);
	for (int i = 0; i < str.length(); i++)
		res += str[i];
	return res %= this->maxsize;

}

template<class Key, class Value>
Value* HashRepeatTable<Key, Value>::Find(Key _key)
{
	if (this->IsEmpty()) return nullptr;
	int hk = this->HashKey(_key);
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i].key == hk)
			return &(vec[i].value);
	}
	return nullptr;
}


template<class Key, class Value>
int HashRepeatTable<Key, Value>::Insert(Key _key, Value _val)
{
	if (this->IsFull()) return -1;
	int hk = this->HashKey(_key);
	if (this->Find(hk) != nullptr) {
		hk = this->Rehash(_key, 11);
	}
	vec.push_back({ hk ,_val });
	size++;
	return 0;
}

template<class Key, class Value>
int HashRepeatTable<Key, Value>::Delete(Key _key)
{
	
	return 0;

}

template<class Key, class Value>
void HashRepeatTable<Key, Value>::Reset(void)
{
	return;

}

template<class Key, class Value>
bool HashRepeatTable<Key, Value>::IsTabEnded(void) const
{
	return true;

}

template<class Key, class Value>
int HashRepeatTable<Key, Value>::GoNext(void)
{
	return 1;

}

template<class Key, class Value>
Key HashRepeatTable<Key, Value>::GetKey(void) const
{
	int hk = this->HashKey(0);
	return NULL;

}

template<class Key, class Value>
Value* HashRepeatTable<Key, Value>::GetValuePtr(void)
{
	int hk = this->HashKey(0);
	return nullptr;

}