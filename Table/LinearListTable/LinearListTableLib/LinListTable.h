#include "Polinom/PolinomLib/HeadList.h"
#include "BaseTableLib/BTable.h"
#include <vector>
using namespace std;

template<class Key, class Value>
class LinearListTable : public Table<Key, Value>
{
protected:
	TList<Row> arr;
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
Value* LinearListTable<Key, Value>::Find(Key _key)
{
	for (arr.Reset(); !arr.IsEnd(); arr.GoNext()) {
		if ((*arr.GetCurrentItemPtr()).key == _key) {
			return &(*arr.GetCurrentItemPtr()).value;
		}
	}
	return nullptr;
}

template<class Key, class Value>
int LinearListTable<Key, Value>::Insert(Key _key, Value _val)
{
	if (this->IsFull()) return -1;
	if (this->Find(_key) != nullptr) {
		arr.InsertLast({_key,_val});
	}
	this->size++;
	return 0;
}

template<class Key, class Value>
int LinearListTable<Key, Value>::Delete(Key _key)
{
	Value* f = Find(_key);
	if (f != nullptr) {
		arr.DeleteCurrent();
		return 0;
	}
<<<<<<< HEAD
	return -1;
	//for (arr.Reset(); arr.IsEnd(); arr.GoNext()) {
	//	if (arr.pCurrent.key == _key) {
	//		if (this->curs == arr.pCurrent)
	//			this->curs = arr.pCurrent;
	//		arr.DeleteCurrent();
	//		this->size--;
	//	}
	//	arr.Reset();
	//	return 0;
	//}
	//return -1;*/
=======
	else return -1;
>>>>>>> 90fba52c0182518f2aea7c1647d074853de9f5af
}

template<class Key, class Value>
void LinearListTable<Key, Value>::Reset(void) 
{
	arr.Reset();
}

template<class Key, class Value>
bool LinearListTable<Key, Value>::IsTabEnded(void) const
{
	return arr.IsEnd();
}

template<class Key, class Value>
int LinearListTable<Key, Value>::GoNext(void)
{
	arr.GoNext();
	return 0;
}

template<class Key, class Value>
Key LinearListTable<Key, Value>::GetKey(void) const
{
	return (*arr.GetCurrentItemPtr()).key;
}

template<class Key, class Value>
Value* LinearListTable<Key, Value>::GetValuePtr(void)
{
	//return &(this->curs->value).value;
	return &(*arr.GetCurrentItemPtr()).value;
}
