#pragma once
#include <string>
#include <cmath>
#include <stdexcept>
#include <iostream>
#include "Stack/StackLib/Stack.h"
using namespace std;

#pragma once
class TPostfixCalc
{
private:
	string inf;
	string postf;
	TStack<char> opstack;
	TStack<double> dstack;
	double sol;

protected:
	int Priority(char ch) {
		switch (ch)
		{
		case '(':
		case ')':
			return 1;
		case '+':
		case '-':
			return 2;
		case '*':
		case '/':
		case 's':
		case 'c':
		case 'L':
			return 3;
		default: throw - 1;
		}
	}
public:

	TPostfixCalc() {
		postf = "";
		inf = "";
		opstack = TStack<char>(0);
		dstack = TStack<double>(0);
		sol = 0;
	}

	TPostfixCalc(string eq) {
		if (eq.length() <= 0) throw std::runtime_error{"empty string given"};
		postf = "";
		inf = eq;
		opstack = TStack<char>(eq.length());
		dstack = TStack<double>(eq.length());
		sol = 0;
	}

	TPostfixCalc(const TPostfixCalc& c) {
		if (&c == this) throw std::runtime_error{"Can't assign element to itself"};
		postf = c.postf;
		inf = c.inf;
		opstack = c.opstack;
		dstack = c.dstack;
		sol = c.sol;
	}

	~TPostfixCalc() {}

	void ChangeEquation(string s) { 
		inf = s;
		opstack = TStack<char>(s.length());
		dstack = TStack<double>(s.length());
	}
	string GetEquation() { return inf; }
	string GetPolish() { return postf; }
	double GetSol() { return sol; }
	void ToPostfix() {
		//opstack.Clear();
		char el = '!';
		postf = "";
		string s = "(" + inf + ")";
		for (size_t i = 0; i < s.size(); i++)
		{
			if (s[i] <= '9' && s[i] >= '0') postf += s[i];
			if (s[i] == '/' || s[i] == '*' || s[i] == '+' || s[i] == '-') {
				postf += " ";
				el = opstack.Pop();
				while (Priority(s[i]) <= Priority(el)) {
					postf += el;
					postf += " ";
					el = opstack.Pop();
				}
				opstack.Push(el);
				opstack.Push(s[i]);
			}
			if (s[i] == 's' || s[i] == 'c' || s[i] == 'L') {
				opstack.Push(s[i]);
			}
			if (s[i] == '(') opstack.Push(s[i]);
			if (s[i] == ')') {
				el = opstack.Pop();
				
				while (el != '(') {
					postf += el;
					el = opstack.Pop();
				}
			}
		}
	}
	void CalcIteration(){

	}
	void CalcPostfix() {
		for (size_t i = 0; i < postf.size(); i++)
		{
			if (postf[i] == '+' || postf[i] == '-' || postf[i] == '*' || postf[i] == '/' || postf[i] == 's' || postf[i] == 'c' || postf[i] == 'L') {
				double d1, d2;
				switch (postf[i]) {
					case '+': 
						d1 = dstack.Pop();
						d2 = dstack.Pop();
						dstack.Push(d1 + d2);
						break;
					case '-':
						d2 = dstack.Pop();
						d1 = dstack.Pop();
						dstack.Push(d1 - d2);
						break;
					case '*':
						d1 = dstack.Pop();
						d2 = dstack.Pop();
						dstack.Push(d1 * d2);
						break;
					case '/':
						d1 = dstack.Pop();
						d2 = dstack.Pop();
						dstack.Push(d1 / d2);
						break;
					case 's':
						d1 = dstack.Pop();
						dstack.Push(sin(d1));
						break;
					case 'c':
						d1 = dstack.Pop();
						dstack.Push(cos(d1));
						break;
					case 'L':
						d1 = dstack.Pop();
						dstack.Push(log10(d1));
						break;
					default: throw - 1;
				}
			}
			if (postf[i] <= '9' && postf[i] >= '0') {
				size_t count;
				double t = std::stod(&postf[i], &count);
				dstack.Push(t);
				i += count - 1;
			}
		}
		sol = dstack.TopView();
	}
	void Build() {
		ToPostfix();
		CalcPostfix();
	}

	TPostfixCalc& operator=(const TPostfixCalc& c) {
		if (&c == this) return *this;
		postf = c.postf;
		inf = c.inf;
		opstack = c.opstack;
		dstack = c.dstack;
		return *this;
	}

	bool operator==(const TPostfixCalc& c) {
		if (inf != c.inf || postf != c.postf|| dstack != c.dstack|| opstack != c.opstack)
			return false;
		return true;
	}
	bool operator!=(const TPostfixCalc& c) {
		if (inf != c.inf || postf != c.postf || dstack != c.dstack || opstack != c.opstack)
			return true;
		return false;
	}

	friend istream& operator>>(istream& istr, TPostfixCalc& c)
	{
		cout << "Enter your expression:";
		string exp;
		istr >> exp;
		c.ChangeEquation(exp);
	}
	friend ostream& operator<<(ostream& ostr, const TPostfixCalc& c)
	{
		ostr << "Initial expr: " << c.inf << endl;
		if (c.postf.size() == 0) ostr << "Result expr: empty or not calculated yet" << endl; 
		else { ostr << "Result expr: " << c.postf << endl; }
		ostr << "The solution: " << c.sol << endl;
		
		return ostr;
	}
};
