#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <windows.h>
using namespace std;


struct STATE
{
	char name[32];
	char Capital[32];
	char Language[32];
	unsigned int Population;
	unsigned int Area;
	char MonetaryUnit[32];
	char PoliticalSystem[32];
	char HeadOfState[32];
	int count;
};

void memory(STATE*& state, int& size)
{
	STATE* new_state = new STATE[size + 1];

	for (int i = 0; i < size; i++)
	{
		new_state[i] = state[i];
	}

	size++;

	delete[] state;

	state = new_state;
}

void sort(STATE *state, int size)
{
	int N;
	cout << "Хотите отсортировать массив? Возможна сортировка по колличеству населения или площади\n" << endl;
	cout << "По колличеству населения нажмите 1, по площади - 2, не сортировать - любое другое число:";
	cin >> N;

	if (N == 1)
	{
		for (int i = 0; i < size; i++)
		{
			for (int i = 0; i < size - 1; i++)
			{
				if (state[i].Population > state[i + 1].Population)
				{
					STATE temp = state[i];
					state[i] = state[i + 1];
					state[i + 1] = temp;
				}
			}
		}

		cout << "Сортировка по колличеству населения прошла успешно!" << endl;

	}

	else if (N == 2)
	{
		for (int i = 0; i < size; i++)
		{
			for (int i = 0; i < size - 1; i++)
			{
				if (state[i].Area > state[i + 1].Area)
				{
					STATE temp = state[i];
					state[i] = state[i + 1];
					state[i + 1] = temp;
				}
			}
		}

		cout << "Сортировка по площади прошла успешно!" << endl;

	}

	else
	{
		cout << "Вы решили не сортировать." << endl;
	}
}

void search(STATE* state, int size)
{
	int s, m, count = 0;
	string Name, number;

	cout << "Вы можете найти нужную вам страну по его названию(1) или столице(2)\n";
	cout << "Введите соответствующий номер для поиска либо другое число для пропуска: ";
	cin >> s;
	cout << endl;

	if (s == 1)
	{
		cout << "Введите название: ";
		cin >> Name;
		cout << endl;

		for (int i = 0; i < size; i++)
		{
			if (Name == state[i].name)
			{
				cout << "Название страны: " << state[i].name << endl;;
				cout << "Столица: " << state[i].Capital << endl;
				cout << "Язык: " << state[i].Language << endl;
				cout << "Население: " << state[i].Population << endl;
				cout << "Площадь территории: " << state[i].Area << endl;
				cout << "Денежная единица: " << state[i].MonetaryUnit << endl;
				cout << "Государственный строй: " << state[i].PoliticalSystem << endl;
				cout << "Глава государства: " << state[i].HeadOfState << endl;
				count++;
			}
		}

		if (count == 0)
		{
			cout << "Таких стран в базе не найдено" << endl;
		}

		cout << endl;
		cout << "Продолжить поиск? Да - 1, Нет - другое число: ";
		cin >> m;
		cout << endl;

		if (m == 1)
		{
			search(state, size);
			count = 0;
		}

		else
		{
			count = 0;
		}

		cout << endl;
	}

	if (s == 2)
	{
		cout << "Введите название столицы: ";
		cin >> number;
		cout << endl;
		for (int i = 0; i < size; i++)
		{
			if (number == state[i].Capital)
			{
				cout << "Название страны: " << state[i].name << endl;;
				cout << "Столица: " << state[i].Capital << endl;
				cout << "Язык: " << state[i].Language << endl;
				cout << "Население: " << state[i].Population << endl;
				cout << "Площадь территории: " << state[i].Area << endl;
				cout << "Денежная единица: " << state[i].MonetaryUnit << endl;
				cout << "Государственный строй: " << state[i].PoliticalSystem << endl;
				cout << "Глава государства: " << state[i].HeadOfState << endl;
				count++;
			}
		}

		if (count == 0)
		{
			cout << "Страны с данным городом не найдено" << endl;
		}

		cout << endl;
		cout << "Продолжить поиск? Да - 1, Нет - другое число: ";
		cin >> m;
		cout << endl;

		if (m == 1)
		{
			search(state, size);
			count = 0;
		}

		else
		{
			count = 0;
		}

		cout << endl;
	}
}void massiv(STATE* state, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Название страны: " << state[i].name << endl;;
		cout << "Столица: " << state[i].Capital << endl;
		cout << "Язык: " << state[i].Language << endl;
		cout << "Население: " << state[i].Population << endl;
		cout << "Площадь территории: " << state[i].Area << endl;
		cout << "Денежная единица: " << state[i].MonetaryUnit << endl;
		cout << "Государственный строй: " << state[i].PoliticalSystem << endl;
		cout << "Глава государства: " << state[i].HeadOfState << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	STATE* state;
	int size;

	do
	{
		cout << "Введите количество стран, данные которых вы будете вводить: ";
		cin >> size;
	} while (size < 1);

	state = new STATE[size];

	for (int i = 0; i < size; i++)
	{
		cout << "Введите название страны под номером " << i + 1 << ": ";
		cin >> state[i].name;

		cout << "Введите столицу: ";
		cin >> state[i].Capital;

		cout << "Введите государственный язык: ";
		cin >> state[i].Language;

		cout << "Введите колличество населения: ";
		cin >> state[i].Population;

		cout << "Введите площадь территории: ";
		cin >> state[i].Area;

		cout << "Введите денежную единицу: ";
		cin >> state[i].MonetaryUnit;

		cout << "Введите государственный строй: ";
		cin >> state[i].PoliticalSystem;

		cout << "Введите главу государства: ";
		cin >> state[i].HeadOfState;
		cout << endl;
		system("cls");
		if (i == size - 1)
		{
			state[i].count = 0;

			cout << "Хотите добавить страну?(Если Да - введите 1, Нет - любое другое число)" << endl;
			cin >> state[i].count;
			cout << endl;

			if (state[i].count == 1)
			{
				//функция для выделения памяти если пользователь продолжит ввод;
				memory(state, size);
			}
		}

	}

	if (size > 1)
	{
		//функция сортировки массива;
		sort(state, size);

		//функция поиска нужной структуры по заданному значению;
		search(state, size);
	}

	else
	{
		cout << "Так как вы ввели информацию только об 1 стране функции сортировки и поиска недоступны" << endl << endl;
	}

	cout << "Вывод информации о введенных странах: " << endl;
	//функция вывода массива;
	massiv(state, size);
}