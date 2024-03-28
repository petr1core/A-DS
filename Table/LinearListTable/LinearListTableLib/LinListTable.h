#include "Polinom/PolinomLib/HeadList.h"
#include "BaseTableLib/BTable.h"
#include <vector>
using namespace std;

template<class Key, class Value>
class LinearListTable : public Table<Key, Value>
{
protected:
	TList<Row> arr; 
	TList::TNode<Row>* curs;
public:
	LinearListTable();
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
LinearListTable<Key, Value>::LinearListTable()
{
	//curs = arr.begin();
}
template<class Key, class Value>
Value* LinearListTable<Key, Value>::Find(Key _key)
{
	/*if (this->IsEmpty()) return -1;
	for (arr.Reset(); arr.IsEnd(); arr.GoNext()) {
		if (arr.GetCurrentItemPtr().key == _key) {
			return &arr.GetCurrentItem().value;
		}
		arr.Reset();
		return 0;
	}
	return -1;*/
	TList<Row>::Iterator i;
	i = arr.begin();
	while (i != arr.end()) {
		if ((*i).key == _key)
			return &(*i).value;
		i++;
	}
	return nullptr;
}

template<class Key, class Value>
int LinearListTable<Key, Value>::Insert(Key _key, Value _val)
{
	/*arr.InsertLast({ _key, _val });
	this->size++;
	return 0;*/


	if (this->IsFull()) 
		return -1;
	if (Find(_key) != nullptr) 
		return -1;
	else {
		arr.InsertLast({ _key,_val });
		this->size++;
		return 0;
	}
}

template<class Key, class Value>
int LinearListTable<Key, Value>::Delete(Key _key)
{
	if (this->IsEmpty()) return -1;
	TList<Row>::Iterator i;
	for (i = arr.begin(); i != arr.end(); i++) {
		if ((*i).key == _key) {
			arr.;
			this->size--;
			return 0;
		}
	}
	return -1;
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
}

template<class Key, class Value>
void LinearListTable<Key, Value>::Reset(void) 
{
	this->curs = arr.begin();
}

template<class Key, class Value>
bool LinearListTable<Key, Value>::IsTabEnded(void) const
{
	return this->curs == arr.end();
}

template<class Key, class Value>
int LinearListTable<Key, Value>::GoNext(void)
{
	if (this->IsTabEnded())
		this->Reset();
	this->curs = this->curs->pNext;
	return 0;
}

template<class Key, class Value>
Key LinearListTable<Key, Value>::GetKey(void) const
{
	return (this->curs->value).key;
}

template<class Key, class Value>
Value* LinearListTable<Key, Value>::GetValuePtr(void)
{
	return &(this->curs->value).value;
}
