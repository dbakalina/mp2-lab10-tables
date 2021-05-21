#include "TRecord.h"
#include "TScanTable.h"
#include "TSortTable.h"
#include "THashTable.h"
#include "TTreeTable.h"
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;


int main()
{
	setlocale(LC_CTYPE, "Russian");
	int maxSize, step;
	cout << "Введите максимальный размер таблиц:" << endl;
	cin >> maxSize;
	cout << "Введите величину шага для хэш-таблицы:" << endl;
	cin >> step;
	TScanTable* scan = new TScanTable(maxSize);
	TSortTable* sort = new TSortTable(maxSize);
	THashTable* hash = new THashTable(maxSize, step);
	TTreeTable* tree = new TTreeTable;
	TTable* tab = scan;
	TRecord rec;
	TKey key;
	TValue val;
	int op = 1;
	int tab_num = 1;
	int size;

	do
	{
		switch (op)
		{
		case 1: scan = new TScanTable(maxSize);
			sort = new TSortTable(maxSize);
			hash = new THashTable(maxSize, step);
			tree = new TTreeTable;
			tab = scan;
			cout << "Введите число элементов в таблице:" << endl;
			cin >> size;
			for (int i = 0; i < size; i++)
			{
				key = "";
				val = "";
				int j = 0;
				while (j < 3)
				{
					key += (rand() % 10 + '0');
					val += (rand() % 10 + '0');
					j++;
				}
				rec.SetKey(key);
				rec.SetValue(val);
				scan->InsRec(rec);
				sort->InsRec(rec);
				hash->InsRec(rec);
				tree->InsRec(rec);
			}
			break;

		case 2: cout << "Выберите вид таблицы" << endl;
			cout << "1. Таблица для просмотра" << endl;
			cout << "2. Отсортированная таблица" << endl;
			cout << "3. Хэш-таблица" << endl;
			cout << "4. Древовидная таблица" << endl;
			cin >> tab_num;
			switch (tab_num)
			{
			case 1: tab = scan;
				break;
			case 2: tab = sort;
				break;
			case 3: tab = hash;
				break;
			case 4: tab = tree;
				break;
			default: cout << "Некорректный ввод!" << endl;
			}
			break;

		case 3: switch (tab_num)
		{
		case 1: cout << "Таблица для просмотра:" << endl;
			scan->Print();
			break;

		case 2: cout << "Отсортированная таблица:" << endl;
			sort->Print();
			break;

		case 3: cout << "Хэш-таблица:" << endl;
			hash->Print();
			break;

		case 4: cout << "Древовидная таблица:" << endl;
			tree->Print();
			break;
		}
			  break;

		case 4: cout << "Введите ключ элемента поиска:" << endl;
			cin >> key;
			tab->ResetEff();
			if (tab->Find(key))
				cout << "Элемент найден - " << tab->GetCurr() << endl;
			else
				cout << "Элемент не найден" << endl;
			cout << "Эффективность - " << tab->GetEff() << endl;
			break;

		case 5: cout << "Заполните поля элемента, который хотите вставить:" << endl;
			cin >> rec;
			tab->ResetEff();
			tab->InsRec(rec);
			cout << "Эффективность - " << tab->GetEff() << endl;
			break;

		case 6: cout << "Введите ключ элемента, который хотите удалить:" << endl;
			cin >> key;
			tab->ResetEff();
			tab->DelRec(key);
			cout << "Эффективность - " << tab->GetEff() << endl;
			break;

		case 7: sort = new TSortTable(*scan);
			tab_num = 2;
			cout << "Таблица отсортирована" << endl;
			break;

		case 8: break;

		default: cout << "Некорректный ввод! Введите значение заново" << endl;
		}
		cout << "Выберите операцию:" << endl;
		cout << "1. Заполнить таблицы" << endl;
		cout << "2. Выбрать вид таблицы (по умолчанию - таблица для просмотра)" << endl;
		cout << "3. Вывод таблицы на экран" << endl;
		cout << "4. Поиск элемента" << endl;
		cout << "5. Вставить элемент" << endl;
		cout << "6. Удалить элемент" << endl;
		cout << "7. Отсортировать таблицу для просмотра" << endl;
		cout << "8. Завершение работы" << endl;
		cin >> op;
	} while (op != 8);

	return 0;
}
