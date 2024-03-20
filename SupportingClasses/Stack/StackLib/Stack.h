
#pragma once
template <class T>
class TStack {
protected:
	int size;
	int top;
	T* mas;

public:
	TStack(int n = 0) {
		if (n < 0) throw std::runtime_error{"can't create stack with negative length"};
		top = -1;
		size = n;
		mas = new T[n];
	}
	TStack(const TStack<T>& st) {
		size = st.size;
		top = st.top;
		mas = new T[size];
		for (size_t i = 0; i < size; i++)
		{
			mas[i] = st.mas[i];
		}
	}
	~TStack() {
		delete[] mas;
	}

	void Clear() {
		for (size_t i = 0; i < size; i++) mas[i] = 0;
	}
	int GetSize() {
		return top + 1;
	}
	void Push(T x) {  // Втолкнуть x в стек
		if (IsFull()) throw std::runtime_error{"The stack is full"};
		mas[++top] = x;
	} 
    T GetTop() {  // Вытолкнуть последний элемент из стека
		if (IsEmpty()) throw std::runtime_error{"The stack is empty"};
		return mas[top];
	}
	T Pop()  // Вытолкнуть последний элемент из стека
	{
		if (IsEmpty()) throw std::runtime_error{"The stack is empty"};
		return mas[top--];
	}
	T TopView() {  // Подгядеть последний элемент
		if (IsEmpty()) throw std::runtime_error{"The stack is empty"};
		return mas[top];
	} 
	
	//операторы вводы и выводы

	bool IsFull() {
		return top == size - 1;
	}
	bool IsEmpty() {
		return top == -1;
	}

	TStack<T>& operator=(const TStack<T>& st){
		if (&st == this) return *this;
		delete[] mas;
		size = st.size;
		top = st.top;
		mas = new T[size];
		for (size_t i = 0; i < size; i++) mas[i] = st.mas[i];
		return *this;
	}
	
	bool operator==(const TStack<T>& stack) {
		if (size != stack.size) return false;
		for (size_t i = 0; i < stack.size; i++)
		{
			if (mas[i] != stack.mas[i]) return false;
		}
		return true;
	}
	bool operator!=(const TStack<T>& stack) {
		if (size != stack.size) return true;
		for (size_t i = 0; i < size; i++) {
			if (mas[i] != stack.mas[i]) return true;
		}
		return false;
	}
	};
