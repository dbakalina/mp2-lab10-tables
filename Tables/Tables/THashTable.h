#ifndef _T_HASH_TABLE_H_
#define _T_HASH_TABLE_H_

#include "TTable.h"

class THashTable :public TTable
{
protected:
	int HashFunc(TKey key);

	int maxSize, curr, step, free;
	TRecord *pRec;

public:
	THashTable(int _size = 0, int _step = 0);
	virtual ~THashTable() { delete[] pRec; pRec = NULL; };

	virtual bool IsFull() { return maxSize == DataCount; };
	virtual bool Find(TKey key);
	virtual void InsRec(TRecord rec);
	virtual void DelRec(TKey key);

	virtual void Reset();
	virtual void GoNext();
	virtual bool IsEnd() { return curr == maxSize; };
	virtual TRecord GetCurr() { return pRec[curr]; };
};


#endif
