#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
class Stack {
public:
	Stack();
	~Stack();
	void Input(int x);
	int Pop();
	bool Emptin();
	void Print();
	int unnumericInputProtection();
	void ShellSort();
	friend istream& operator >> (istream& input, Stack& variable);
	Stack& operator += (int elem);
	friend ostream& operator << (ostream& output, Stack& variable);
	class AnError
	{

	};
private:
	struct Node {
		int x;
		Node* Next;
	}*head = nullptr;
};
