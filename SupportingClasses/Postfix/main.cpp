// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include "PostfixLib/postfix.h"
#include "Stack/StackLib/Stack.h"
#include <cmath>
//---------------------------------------------------------------------------
void main()
{
	setlocale(LC_ALL, "Russian");
	/*int choice = 1;
	string eq;
	TPostfixCalc calc;
	cout << "|--------------------------------------------|" << endl;
	while (choice == 1) {
		cout << "Введите ваше выражение без пробелов, функции\n[cN -- cos(N); sN -- sin(N); LN -- log10(N)]" << endl;
		cin >> eq;
		calc.ChangeEquation(eq);
		calc.Build();
		cout << "Введённое выражение: " << calc.GetEquation() << endl
			<< "Его постфиксная форма: " << calc.GetPolish() << endl
			<< "Ответ: " << calc.GetSol() << endl;
		cout << "Хотите попробовать ещё раз?" << endl
			<< "1 - Да" << endl << "2 - Нет" << endl;
		cin >> choice;
		cout << "|--------------------------------------------|" << endl;
	}*/
	srand(time(0));
	int size = 250000000;
	TStack<int> st(size);
	
	for (size_t i = 0; i < size; i++)
	{
		st.Push(1);
	}
	clock_t start = clock();
	
	
	
	for (size_t i = 0; i < size; i++)
	{
		st.Pop();
	}
	clock_t end = clock();

	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("The time: %f seconds\n", seconds);
}
