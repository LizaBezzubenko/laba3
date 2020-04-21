#pragma once
#include"Header.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	Stack newStack;
	int choice, x, N;
	bool flag = true;
	while (flag) {
		cout << "1.Создать стек множества элементов" << endl;
		cout << "2.Просмотреть стек" << endl;
		cout << "3.Ввести элемент стека" << endl;
		cout << "4.Удалить элемент" << endl;
		cout << "5.Стереть данные" << endl;
		cout << "6.Cортировка Шелла" << endl;
		cout << "0.Выход" << endl;
		switch (newStack.unnumericInputProtection())
		{
		case 1:
			cout << " Введите максимальное число элементов необходиммое для заполнения стека" << endl;
			cin >> N;
			for (int i = 0; i < N; i++)
			{
				cin >> newStack;
			}
			break;
		case 2:
			try
			{
				cout << newStack;
			}
			catch (Stack::AnError)
			{
				cout << "А стек пуст!" << endl << endl;
			}
			break;
		case 3:
			cin >> newStack;
			break;
		case 4:
			try
			{
				newStack.Pop();
			}
			catch (Stack::AnError)
			{
				cout << "А стек пуст!" << endl;
			}
			break;
		case 5: newStack.~Stack(); break;
		case 6:
			newStack.ShellSort();
			break;
		case 0:flag = false;
			break;
		default:cout << "Неккоректный ввод" << endl;
			break;
		}
	}
	return 0;
}
