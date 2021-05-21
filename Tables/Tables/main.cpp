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
	cout << "������� ������������ ������ ������:" << endl;
	cin >> maxSize;
	cout << "������� �������� ���� ��� ���-�������:" << endl;
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
			cout << "������� ����� ��������� � �������:" << endl;
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

		case 2: cout << "�������� ��� �������" << endl;
			cout << "1. ������� ��� ���������" << endl;
			cout << "2. ��������������� �������" << endl;
			cout << "3. ���-�������" << endl;
			cout << "4. ����������� �������" << endl;
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
			default: cout << "������������ ����!" << endl;
			}
			break;

		case 3: switch (tab_num)
		{
		case 1: cout << "������� ��� ���������:" << endl;
			scan->Print();
			break;

		case 2: cout << "��������������� �������:" << endl;
			sort->Print();
			break;

		case 3: cout << "���-�������:" << endl;
			hash->Print();
			break;

		case 4: cout << "����������� �������:" << endl;
			tree->Print();
			break;
		}
			  break;

		case 4: cout << "������� ���� �������� ������:" << endl;
			cin >> key;
			tab->ResetEff();
			if (tab->Find(key))
				cout << "������� ������ - " << tab->GetCurr() << endl;
			else
				cout << "������� �� ������" << endl;
			cout << "������������� - " << tab->GetEff() << endl;
			break;

		case 5: cout << "��������� ���� ��������, ������� ������ ��������:" << endl;
			cin >> rec;
			tab->ResetEff();
			tab->InsRec(rec);
			cout << "������������� - " << tab->GetEff() << endl;
			break;

		case 6: cout << "������� ���� ��������, ������� ������ �������:" << endl;
			cin >> key;
			tab->ResetEff();
			tab->DelRec(key);
			cout << "������������� - " << tab->GetEff() << endl;
			break;

		case 7: sort = new TSortTable(*scan);
			tab_num = 2;
			cout << "������� �������������" << endl;
			break;

		case 8: break;

		default: cout << "������������ ����! ������� �������� ������" << endl;
		}
		cout << "�������� ��������:" << endl;
		cout << "1. ��������� �������" << endl;
		cout << "2. ������� ��� ������� (�� ��������� - ������� ��� ���������)" << endl;
		cout << "3. ����� ������� �� �����" << endl;
		cout << "4. ����� ��������" << endl;
		cout << "5. �������� �������" << endl;
		cout << "6. ������� �������" << endl;
		cout << "7. ������������� ������� ��� ���������" << endl;
		cout << "8. ���������� ������" << endl;
		cin >> op;
	} while (op != 8);

	return 0;
}
