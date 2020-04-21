#pragma once
#include"Header.h"

Stack::Stack()
{
	if (head != nullptr) {
		throw AnError();
	}
}
void Stack::ShellSort()
{

	try
	{
		if (head == nullptr)
			throw AnError();

		Node* temp = head;
		int count = 0;
		int size = 0;
		while (temp != NULL) {
			count++;
			temp = temp->Next;
		}
		temp = head;
		size = count;
		int* array = new int[size];
		count = 0;
		while (head != NULL) {
			array[count] = head->x;
			head = head->Next;
			count++;
		}

		int i, j, step;
		int tmp;
		for (step = size / 2; step > 0; step /= 2)
			for (i = step; i < size; i++)
			{
				tmp = array[i];
				for (j = i; j >= step; j -= step)
				{
					if (tmp > array[j - step])
						array[j] = array[j - step];
					else
						break;
				}
				array[j] = tmp;
			}

		for (int i = 0; i < count; i++)
		{
			Input(array[i]);
		}
		delete[]array;
	}

	catch (Stack::AnError)
	{
		cout << "Нечего сортировать. Заполните стек элементами" << endl;
	}
}
int Stack::Pop() {

	if (head == nullptr)
		throw AnError();
	int temp = head->x;
	Node* pv = head;
	head = head->Next;
	delete pv;
	return temp;

}
void Stack::Input(int x) {
	try
	{
		Node* pv = new Node;
		pv->x = x;
		pv->Next = head;
		head = pv;
	}
	catch (Stack::AnError)
	{
		cout << "Ошибка" << endl;
	}
}
bool Stack::Emptin() {

	try
	{
		if (head != nullptr)
			return true;
	}
	catch (Stack::AnError)
	{
		return false;
	}

	return head ? false : true;
}
void Stack::Print()
{

	if (head == nullptr)
		throw AnError();

	Node* h = head;
	cout.width(120);
	cout.setf(ios::right);
	cout << "Стек выровнен по правому краю: " << endl;
	cout.width(91);
	cout.setf(ios::right);

	while (h)
	{
		cout << h->x << ' ';
		h = h->Next;

	}
	cout.unsetf(ios::right);
	cout << endl;


	Node* pos = head;
	cout << endl;
	cout << "Показывает “+” перед положительными целыми числами:";
	cout << showpos;
	while (pos)
	{
		cout << pos->x << ' ';
		pos = pos->Next;
	}
	cout.unsetf(ios::showpos);
	cout << endl;

	Node* hex = head;
	cout << endl;
	cout << "Перевод в шестнадцатеричную форму:";
	cout.unsetf(ios::dec);
	cout.setf(ios::hex);
	//cout << hex << showbase;
	while (hex)
	{
		cout << hex->x << ' ';
		hex = hex->Next;
	}
	cout.unsetf(ios::hex);
	cout << endl;


	Node* oct = head;
	cout << endl;
	cout << "Перевод в восьмеричную форм:";
	cout.unsetf(ios::dec);
	cout.setf(ios::oct);
	//cout << oct << showbase;
	while (oct)
	{
		cout << oct->x << ' ';
		oct = oct->Next;
	}
	cout.unsetf(ios::oct);
	cout << endl;

	Node* dec = head;
	cout << endl;
	cout << "Перевод в десятичную форму:";
	cout.setf(ios::dec);
	//cout << dec;
	while (dec)
	{
		cout << dec->x << ' ';
		dec = dec->Next;
	}
	cout.unsetf(ios::dec);
	cout << endl << endl;
}


Stack::~Stack()
{
	while (head)
	{
		Node* pv = head;
		head = head->Next;
		delete pv;
	}
}

istream& operator >> (istream& input, Stack& variable) {
	variable += variable.unnumericInputProtection();
	return input;
}
Stack& Stack::operator += (int elem)
{
	this->Input(elem);
	return *this;
}
ostream& operator << (ostream& output, Stack& variable) {
	variable.Print();
	return output;
}
int Stack::unnumericInputProtection()
{
	int number;
	try
	{
		cout << "Ввод: " << endl;
		cin >> number;
		if (!cin.good())
			throw number;
		return number;
	}
	catch (int number)
	{

		while (true) {

			cout << "Некорректный ввод." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cin >> number;
			if (cin.good())
				return number;
		}
	}
}
