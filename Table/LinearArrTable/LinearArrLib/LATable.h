#include "BaseTableLib/BTable.h"
#include <vector>
using namespace std;


template <class Key, class Value>
class LinearArrTable : public Table<Key, Value> {
private:
	int curs = -1;
	vector<Row> vec;
public:
	Value* Find(Key _key) override;
	int Insert(Key _key, Value _val) override;

	int Delete(Key _key) override;

	void Reset(void) override;
	bool IsTabEnded(void) const override;
	int GoNext(void) override;			//	(=1 first el, if called on last cell of table)
	

	 Key GetKey(void) const override;
	 Value* GetValuePtr(void) override;
};

template<class Key, class Value>
Value* LinearArrTable<Key, Value>::Find(Key key)
{
	for (int i = 0; i < this->size; i++) {
		if (vec[i].key == key) {
			return &vec[i].value;
		}
	}
	return nullptr;
}

template<class Key, class Value>
int LinearArrTable<Key, Value>::Insert(Key _key, Value _val)
{
	if (!this->IsFull()) {
		this->curs++;
		this->vec.push_back(
			{ _key, _val }
		);
		this->size++;
		return 0;
	}
	else return -1;
}

template<class Key, class Value>
int LinearArrTable<Key, Value>::Delete(Key _key) 
{
	if (!this->IsEmpty()) {
		int whereFounded = -1;
		for (int i = 0; i < this->size; i++) {
			if (this->vec[i].key == _key) {
				whereFounded = i;
				break;
			}
		}
		if (whereFounded != -1) {
			for (int i = whereFounded; i < size-1; i++) {
				vec[i] = vec[i + 1];
			}
			size--;
			return 0;
		}
		else {
			return -1;
		}
	}
	else {
		return -1;
	}
}

template<class Key, class Value>
void LinearArrTable<Key,Value>::Reset(void)
{
	this->curs = 0;
}

template<class Key, class Value>
bool LinearArrTable<Key, Value>::IsTabEnded(void) const
{
	return this->curs == this->size;
}

template<class Key, class Value>
int LinearArrTable<Key, Value>::GoNext(void)
{
	if (!this->IsEmpty()) {
		(this->IsTabEnded()) ? this->Reset() : this->curs++;
		return 0;
	}
	else{
		return -1;
	}
}

template<class Key, class Value>
Key LinearArrTable<Key, Value>::GetKey(void) const
{
	return (curs > -1) ? vec[this->curs].key : nullptr;
}

template<class Key, class Value>
Value* LinearArrTable<Key, Value>::GetValuePtr(void)
{
	return (curs > -1) ? &vec[this->curs].value : nullptr;
}