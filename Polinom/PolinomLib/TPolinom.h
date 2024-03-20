#pragma once

#include "List/ListLib/HeadList.h"
#include "PolinomLib/TMonom.h"

//#include "TMatrix.h" mb nuzhen vector
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

const int nonDisplayedZeros = 4;
const int precision = 4;

class TPolinom : public THeadList<TMonom>
{
public:
	TPolinom(); //
	TPolinom(TPolinom& other); //
	TPolinom(TDynamicVector<TMonom> vec);
	TPolinom(string str); // ---
	TPolinom& operator=(TPolinom& other); //
	TPolinom& operator+(TPolinom& q); //


	void AddMonom(TMonom newMonom); //
	TPolinom MultMonom(TMonom monom); // ---
	TPolinom AddPolinom(TPolinom& other); //
	TPolinom operator*(double coef); //
	TPolinom operator* (TPolinom& other);
	bool operator==(TPolinom& other); //
	bool operator!=(TPolinom& other); //
	string ToString(); //
};

TPolinom::TPolinom() : THeadList<TMonom>::THeadList() { length = 0; }

TPolinom::TPolinom(TPolinom& other)
{
	int size = other.GetLength();
	this->length = size;
	other.Reset();
	TMonom first = other.GetCurrentItem();
	this->InsertFirst(first);
	other.GoNext();
	for (size_t i = 1; i < size; i++) {
		TMonom newm = other.GetCurrentItem();
		this->InsertLast(newm);
		//this->GoNext();
		if (i != size - 1) other.GoNext();
	}
	pStop = nullptr;
}

TPolinom::TPolinom(TDynamicVector<TMonom> vec)
{
	int vector_size = vec.size();
	this->InsertFirst(vec[0]);
	SetCurrentAt(0);
	TMonom currm = GetCurrentItem();
	int prevPow, nextPow, counter = 1, poliSize = 1;
	if (vector_size > 1) {
		for (int i = 1; i < vector_size; i++) {
			nextPow = vec[i].GetIndex();
			prevPow = GetCurrentItem().GetIndex();
			if (nextPow > prevPow) {
				TMonom newM;
				newM.SetCoef(vec[i].GetCoef());
				newM.SetIndex(vec[i].GetIndex());
				InsertFirst(newM);
				poliSize++;
			}
			else
			{
				while (nextPow < prevPow) {
					if (counter < poliSize) {
						GoNext();
						counter++;
						currm = GetCurrentItem();
						prevPow = currm.GetIndex();
					}
					else {
						TMonom newM;
						newM.SetCoef(vec[i].GetCoef());
						newM.SetIndex(vec[i].GetIndex());
						InsertLast(newM);
						poliSize++;
						return;
					}
				}

				if (nextPow == prevPow) {
					if (counter == 1) {
						currm.SetCoef(currm.GetCoef() + vec[i].GetCoef());
						InsertFirst(currm);
						Reset();
						for (size_t i = 0; i < counter + 1; i++) GoNext();
						DeleteCurrent();
					}
					else
					{
						currm.SetCoef(currm.GetCoef() + vec[i].GetCoef());
						DeleteCurrent();
						InsertCurrent(currm);
					}
				}
				else
				{
					TMonom newM;
					newM.SetCoef(vec[i].GetCoef());
					newM.SetIndex(vec[i].GetIndex());
					InsertCurrent(newM);
					poliSize++;
				}
			}
			counter = 1;
		}
	}
	Reset();
	pStop = nullptr;
}

TPolinom::TPolinom(string str)
{
	return;
}

TPolinom& TPolinom::operator=(TPolinom& other)
{
	other.Reset();
	this->Reset();
	TMonom m;
	for (size_t i = 0; i < other.GetLength(); i++) {
		m = other.GetCurrentItem();
		this->InsertCurrent(m);
		this->GoNext();
		other.GoNext();
	}
	this->pStop = nullptr;
	this->Reset();
	other.Reset();
	return *this;
}

void TPolinom::AddMonom(TMonom otherMon)
{
	int	size = this->GetLength();
	this->Reset();
	int i, j;
	for (size_t ii = 0; ii < size; ii++) {
		TMonom thisMon = this->GetCurrentItem();
		i = thisMon.GetIndex();
		j = otherMon.GetIndex();
		if (i == j) {
			TMonom newm;
			newm.SetCoef(thisMon.GetCoef() + otherMon.GetCoef());
			newm.SetIndex(i);
			this->pCurrent->SetValue(newm);
			return;
		}
		if (ii != size - 1)
			GoNext();
	}
	this->InsertNextCurrent(otherMon);
	this->Reset();
}

TPolinom TPolinom::MultMonom(TMonom monom)
{
	return *this;
}

TPolinom& TPolinom::operator+(TPolinom& other)
{
	TPolinom res(*this);
	res.AddPolinom(other);
	return res;
}

TPolinom TPolinom::AddPolinom(TPolinom& other)
{
	TPolinom res(*this);
	other.Reset();
	this->Reset();
	for (size_t i = 0; i < other.GetLength(); i++) {
		TMonom m = other.GetCurrentItem();
		res.AddMonom(m);
		if (i != other.GetLength() - 1) other.GoNext();
	}
	return res;
}

TPolinom TPolinom::operator*(double _coef)
{
	TPolinom res(*this);
	this->Reset();
	res.Reset();
	int size = res.GetLength();
	for (size_t i = 0; i < size; i++) {
		TMonom newm;
		newm.SetCoef(this->GetCurrentItem().GetCoef() * _coef);
		newm.SetIndex(this->GetCurrentItem().GetIndex());
		res.SetCurrentItem(newm);
		if (i != size - 1)
		{
			res.GoNext();
			this->GoNext();
		}
	}
	return res;
}

TPolinom TPolinom::operator*(TPolinom& other)
{
	/*if (this->GetLength() != other.GetLength()) throw "Not equal polinomials length, can't mult them";
	TPolinom res;
	TNode<TMonom>* tm = pFirst;
	TNode<TMonom>* om = other.pFirst;
	while (tm != pHead) {
		while (om != pHead) {
			TMonom m = tm->value * om->value;

			res.AddMonom(m);
			om = om->GetPointer();
		}
		tm = tm->GetPointer();
		tm = tm->GetPointer();
	}*/
	return *this;
}

bool TPolinom::operator==(TPolinom& other)
{
	if (this->GetLength() != other.GetLength()) return false;
	this->Reset();
	other.Reset();
	for (int i = 0; i < this->GetLength(); i++) {
		TMonom f = this->GetCurrentItem();
		TMonom s = other.GetCurrentItem();
		if (f != s) return false;
		this->GoNext();
		other.GoNext();
	}
	return true;
}

bool TPolinom::operator!=(TPolinom& other)
{
	if (this->GetLength() != other.GetLength()) return true;
	this->Reset();
	other.Reset();
	for (int i = 0; i < this->GetLength(); i++) {
		TMonom f = this->GetCurrentItem();
		TMonom s = other.GetCurrentItem();
		if (f != s) return true;
		this->GoNext();
		other.GoNext();
	}
	return false;
}

string TPolinom::ToString()
{
	string res;
	this->Reset();
	int size = this->GetLength();
	for (size_t i = 0; i < size; i++)
	{
		TMonom m = this->GetCurrentItem();
		double d = m.GetCoef();
		int ind = m.GetIndex();
		std::ostringstream output;
		output << setprecision(precision) << d;
		res += output.str() + "x" + to_string((ind - ind % 100) / 100);
		res += "y" + to_string(((ind % 100) - (ind % 10)) / 10);
		res += "z" + to_string(ind % 10);
		if (i != size - 1) {
			res += " + ";
			this->GoNext();
		}
	}
	this->Reset();
	return res;
}