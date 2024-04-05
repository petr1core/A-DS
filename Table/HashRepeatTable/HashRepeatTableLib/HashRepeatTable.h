#pragma once
#include <vector>
#include <string>
#include "Polinom/PolinomLib/List.h"
#include "TableBaseLib/TableBase.h"

using namespace std;

template<class Key, class Value>
class HashRepeatTable : public Table<Key, Value>
{
private:
	vector<Row> vec;
	int curs = -1;  // current item
	int count = 0; // not empty elems counter
	int steps = -1;
protected:
	int HashKey(Key _key) const;
	int Rehash(Key _key, int seed) const;
public:
	double Getfullness(void) const;
	int GetCount(void) const;

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
double HashRepeatTable<Key, Value>::Getfullness(void) const 
{
	return (double)count / size;
}

template<class Key, class Value>
int HashRepeatTable<Key, Value>::GetCount(void) const 
{
	return this->count;
}
template<class Key, class Value>
int HashRepeatTable<Key, Value>::HashKey(Key _key) const 
{
	int sum = 0;
	string str = _key;
	for (int i = 0; i < str.length(); i++)
		sum += str[i];
	return sum % this->maxsize;
}

template<class Key, class Value>
int HashRepeatTable<Key, Value>::Rehash(Key _key, int seed) const 
{
	int sum = seed;
	string str = to_string(_key);
	for (int i = 0; i < str.length(); i++)
		sum += str[i];
	return sum % this->maxsize;

}

template<class Key, class Value>
Value* HashRepeatTable<Key, Value>::Find(Key _key) 
{
	if (this->IsEmpty()) return nullptr;
	int id = this->HashKey(_key);
	while (vec[id].key != _key && vec[id].key != Key())
		id = (id + 1) % this->maxsize;

	if (vec.size() <= id || vec[id].key == Key()) return nullptr;
	return &vec[id].value;
}


template<class Key, class Value>
int HashRepeatTable<Key, Value>::Insert(Key _key, Value _val) 
{
	if (this->IsFull()) return -1;

	int id = this->HashKey(_key);
	int repeat_id = -1;
	
	if (vec.size() <= id){
		if ((id + 1) <= this->maxsize) {
			vec.resize(id);
			Row row(_key, _val);
			vec.push_back(row);
			count++;
			size = vec.size();
			if (count == 1) {
				//curs++;
				this->Reset();
			}
			return 0;
		}
		else return -1; // reached maxSize
		
	}
	while (vec[id].key != Key()) {
		id = (id + 1) % this->maxsize;
	}
	if (vec[id].key == Key()) {
		repeat_id = id;
	}
	if (repeat_id != -1) {
		vec[repeat_id] = Row{ _key, _val };
	}
	else {
		vec[id].value = _val;
	}
	count++; // plus one new elem
	return 0;
}

template<class Key, class Value>
int HashRepeatTable<Key, Value>::Delete(Key _key) 
{
	if (this->IsEmpty()) return - 1;
	if (this->Find(_key) == nullptr) return -1;
	int id = this->HashKey(_key);
	Row empty{};
	vec[id] = empty;
	return 0;
}

template<class Key, class Value>
void HashRepeatTable<Key, Value>::Reset(void) 
{
	steps = 0;
	curs = -1;
	this->GoNext();
}

template<class Key, class Value>
bool HashRepeatTable<Key, Value>::IsTabEnded(void) const 
{
	return steps == count + 1;
}

template<class Key, class Value>
int HashRepeatTable<Key, Value>::GoNext(void) 
{
	do { curs = (curs + 1) % size; }
	while (vec[curs].key == Key());

	if (count != 0 && vec[curs].key != Key())
		steps++;
	return 0;
}

template<class Key, class Value>
Key HashRepeatTable<Key, Value>::GetKey(void) const 
{
	return (curs != -1) ? vec[curs].key : NULL;
}

template<class Key, class Value>
Value* HashRepeatTable<Key, Value>::GetValuePtr(void) 
{ 
	return (curs != -1) ? &vec[curs].value : nullptr;

}