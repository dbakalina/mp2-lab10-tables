#pragma once
#include <iostream>
#include "TArrayTables.h"
using namespace std;

class TScanTable :public TArrayTable {
public:
	
	TScanTable(int _MaxSize = 1000) :TArrayTable(_MaxSize) {}
	
	~TScanTable() {}

	int GetMaxSize() {
		return MaxSize;
	}
	
	TRecord GetMas(int i) {
		if ((i >= 0) && (i < MaxSize)) {
			return mas[i];
		}
	}

	virtual bool Find(TKey _key) {
		for (int i = 0; i < DataCount; i++) {
			Eff++;
			if (mas[i].key == _key) {
				Curr = i;
				return true;
			}
		}
		Curr = DataCount;
		return false;
	}
	
	virtual void Delete(TKey _key) {
		if (Find(_key)) {
			DataCount--;
			Eff++;
			mas[Curr] = mas[DataCount];
		}
	}
	
	virtual void Insert(TRecord rec) {
		//if (IsFull()) return;
		if (!Find(rec.key)) {
			for (int i = (DataCount - 1); i >= Curr; i--)
			{
				mas[i+1] = mas[i];
				Eff++;
			}
			mas[Curr] = rec;
			//mas[Curr].key = rec.key;
			//mas[Curr].val = rec.val;
			DataCount++;
			//Eff++;
		}
		else
		{
			mas[Curr].val++;
		}
	}
};
