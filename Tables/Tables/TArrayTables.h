#pragma once
#include <iostream>
#include "TTables.h"
using namespace std;

class TArrayTable :public TTable {
protected:
	TRecord* mas;	
	int MaxSize;	
	int Curr;
public:
	TArrayTable(int _MaxSize = 1000) {
		MaxSize = _MaxSize;
		Curr = -1;
		mas = new TRecord[MaxSize];
	}

	~TArrayTable() {
		delete[] mas;
	}

	virtual bool IsFull() const {
		return DataCount == MaxSize;
	}

	virtual TRecord GetCurr() const {
		if (Curr >= 0 && Curr < MaxSize)
			return mas[Curr];
	}

	virtual void Reset() {
		Curr = 0;
	}
	
	virtual bool IsEnd() {
		return DataCount == Curr;
	}
	
	virtual void GoNext() {
		Curr++;
	}
};
