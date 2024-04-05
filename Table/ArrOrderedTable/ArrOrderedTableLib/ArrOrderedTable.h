#include "TableBaseLib/TableBase.h"
#include <iostream>
#include <vector>

using namespace std;

template<class Key, class Value>
class OrderedArrTable : public Table<Key, Value>
{
private:
	vector<Row> vec;
	int curs = -1;

	int BinSearch(Key _key) const;
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
int OrderedArrTable<Key,Value>::BinSearch(Key _key) const
{
	int i = 0;
	int k = this->size-1;
	while (i <= k) {
		int j = i + (k-i) / 2;
		if (vec[j].key == _key) {
			return j;
		}
		if (vec[j].key < _key) {
			i = j + 1;
		}
		else {
			k = j - 1;
		}
	}
	return -1;
} 

template<class Key, class Value>
Value* OrderedArrTable<Key, Value>::Find(Key _key) 
{
	int i = BinSearch(_key);
	if (i > -1) 
		return &vec[i].value;
	else 
		return nullptr;
}

template<class Key, class Value>
int OrderedArrTable<Key, Value>::Insert(Key _key, Value _val) 
{
	if (this->IsEmpty()) {
		vec.push_back({ _key, _val });
		curs++;
		size++;
		return 0;
	}
	if (!this->IsFull()) {
		if (BinSearch(_key) != -1) return -1;    // elem. with this key is already exists in table
		vec.push_back({ _key, _val });
		size++;
		int i = size - 1;
		while (vec[i].key < vec[i - 1].key && i > 1) {
			std::swap(vec[i], vec[i - 1]);
			i--;
		}
		return 0;
	}
	else {
		return -1;
	}
}

template<class Key, class Value>
int OrderedArrTable<Key, Value>::Delete(Key _key)
{
	int i = BinSearch(_key);
	if (i == -1) return -1;
	while (i < size - 1 && vec[i].key < vec[i + 1].key) {
		std::swap(vec[i], vec[i + 1]);
		i++;
	}
	vec.pop_back();
	curs = (curs == size-1) ? size-2 : curs; // if curs was pointing to last el, make it point to NEW last one (ex. ()()(.) ->> ()(.) ),
	size--;  								// otherwise do nothing with it 
	return 0;
}

template<class Key, class Value>
bool OrderedArrTable<Key, Value>::IsTabEnded(void) const
{
	return this->curs == this->size;
}

template<class Key, class Value>
int OrderedArrTable<Key, Value>::GoNext(void)
{
	if (!this->IsEmpty()) {
		(this->IsTabEnded()) ? this->Reset() : this->curs++;
		return 0;
	}
	else {
		return -1;
	}
}

template<class Key, class Value>
void OrderedArrTable<Key, Value>::Reset(void)
{
	curs = (curs != -1) ? 0 : -1;
}

template<class Key, class Value>
Key OrderedArrTable<Key, Value>::GetKey(void) const
{
	return (!IsEmpty()) ? vec[this->curs].key : NULL;
}

template<class Key, class Value>
Value* OrderedArrTable<Key, Value>::GetValuePtr(void)
{
	return (!IsEmpty()) ? &vec[this->curs].value : nullptr;
}