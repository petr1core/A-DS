#pragma once
#include <iostream>
#include <vector>
#include "BaseTableLib/BTable.h"
#include "Polinom/PolinomLib/List.h"
using namespace std; 

template<class Key, class Value>
class HashChainTable : public Table<Key, Value>
{
	vector<TList<Row>> vec;
	int curs = -1;
	int count = 0; // not empty els in vec
	int itemCurs = -1;
	int HashKey(Key _key) const;
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
	Value* GetValuePtr(void) override;	//	(=1 first el, if called on last cell of table)
	/*operator std::string() const {
		std::ostringstream ostring;
		ostring << (int)GetKey();
		return ostring;
	}*/
};

template<class Key, class Value>
double HashChainTable<Key, Value>::Getfullness(void) const
{
	return (double)count / size;
}

template<class Key, class Value>
int HashChainTable<Key, Value>::GetCount(void) const
{
	return this->count;
}

template<class Key, class Value>
int HashChainTable<Key, Value>::HashKey(Key _key) const
{
	int res = 0;
	string str = to_string(_key);
	for (int i = 0; i < _key.length(); i++)
		res += _key[i];
	return res % this->maxsize;
}


template<class Key, class Value>
Value* HashChainTable<Key, Value>::Find(Key _key)
{
	int t = this->HashKey(_key);
	if (this->IsEmpty()) return nullptr;
	vec[t].Reset();
	return &(vec[t].GetCurrentItemPtr()->value);
}

template<class Key, class Value>
int HashChainTable<Key, Value>::Insert(Key _key, Value _val)
{
	/*size_t index = this->GetHash(key, M);
	auto& list = this->data[index];

	for (list.Reset(); !list.IsListEnded(); list.GoNext()) {
		auto rec = list.GetDatValue();
		if (rec == nullptr)
			break;
		if (rec->key == key) {
			rec->value = value;
			return;
		}
	}
	auto rec = new Table<Key, Value>::template STableRec<Key, Value>(key, value);
	if (list.GetCurrentPos() != 0)
		list.SetCurrentPos(list.GetCurrentPos() - 1);
	list.InsCurrent(rec);

	if (this->actriveRec == nullptr) {
		this->actriveRec = rec;
	}

	this->length++;*/

	/*struct STableRec {
		Key key;
		Value value;
		STableRec(Key key, Value value) {
			this->key = key;
			this->value = value;
		}
		STableRec() : key(Key()), value(Value()) {}
	};*/

	if (this->IsFull()) return -1;
	int t = this->HashKey(_key);
	Row row(_key, _val );
	//auto row_done = new Table<Key, Value>::template TList::TNode<Row>{ row, nullptr };
	TList::TNode<Row> row_done( row, nullptr );

	if (t >= vec.size()) {		// if vec has no space to insert in that index
		if ((t + 1) <= this->maxsize) {
			TList<Row> newlist;
			newlist.InsertFirst(row_done);
			vec.resize(t);
			vec.push_back(newlist);
			count++;
			if (count == 1) { // if first el in whole vec, make cursor point to it
				this->Reset();
			}
			size = vec.size();
			return 0;
		}
		else return -1; // reached max
	}
	if (vec[t] == TList<Table::Row>()) {  // if cell[t] has no TList in
			TList<Row> newlist;
			newlist.InsertFirst(row_done);
			vec[t] = newlist;
			count++;
			size++;
	}
	else {   // if cell [t] already has TList in
		vec[t].InsertLast(row_done);
		size++;
	}
	return 0;
}

template<class Key, class Value>
int HashChainTable<Key, Value>::Delete(Key _key) //??
{
	if (this->IsEmpty()) return -1;
	int t = this->HashKey(_key);
	vec[t] = TList<Table::Row>();
	return 0;
}

template<class Key, class Value>
void HashChainTable<Key, Value>::Reset(void)
{
	this->curs = -1;
	this->itemCurs = 0;
	this->GoNext();
	vec[this->curs].Reset();
}
template<class Key, class Value>
int HashChainTable<Key, Value>::GoNext(void)
{
	if (!vec[curs + 1 % size].IsEnd())
		vec[curs + 1 % size].GoNext();
	else {
		do {
			curs = (curs + 1) % size;

		} while (vec[curs] == TList<Table::Row>());
	}
	if (count != 0 && vec[curs] != TList<Table::Row>())
		this->itemCurs++;
	return 0;
}

template<class Key, class Value>
bool HashChainTable<Key, Value>::IsTabEnded(void) const
{
	return this->itemCurs == count + 1;
}


template<class Key, class Value>
Key HashChainTable<Key, Value>::GetKey(void) const //??
{
	if (curs == -1) return NULL;
	return vec[this->curs].GetCurrentItemPtr().key;
}
template<class Key, class Value>
Value* HashChainTable<Key, Value>::GetValuePtr(void) //??
{
	if (curs == -1) return nullptr;
	return &(vec[this->curs].GetCurrentItem().value);
}