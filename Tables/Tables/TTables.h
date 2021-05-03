#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef string TKey;
typedef int TValue;

struct TRecord {
	TKey key;
	TValue val;
};

class TTable {
protected:
	int DataCount; 
	int Eff; 
public:
	TTable() 
	{
		Eff = 0;
		DataCount = 0;
	}

	~TTable() {}

	int GetDataCount() 
	{
		return DataCount;
	}

	int GetEff() {
		return Eff;
	}

	void ClearEfficiency()
	{
		Eff = 0;
	}

	bool IsEmpty() {
		return DataCount == 0;
	}

	virtual TRecord GetCurr() const = 0;

	virtual bool IsFull() const = 0;

	virtual bool Find(TKey key) = 0;

	virtual void Insert(TRecord rec) = 0;

	virtual void Delete(TKey key) = 0;
	
	virtual void GoNext() = 0;
	
	virtual void Reset() = 0;
	
	virtual bool IsEnd() = 0;

	void Print() {
		for (Reset(); !IsEnd(); GoNext())
		{
			cout << GetCurr().key << " - " << GetCurr().val << endl;
		}
	}
	
	void Read(char* pFileName)
	{
		string str = "";
		ifstream TxtFile(pFileName);
		if (!TxtFile.fail())
		{
			while (!TxtFile.eof()) str += TxtFile.get();
			TxtFile.close();
		}
		else cout << "File does not exist " << endl;
		for (int i = 0; i < str.length(); i++)
		{
			char tmp = str[i];
			if (((int)tmp >= 65) && ((int)tmp <= 90))
			{
				tmp += 32;
			}
			str[i] = tmp;

		}
		string tmp = "";
		TRecord rec;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == ' ')
			{
				rec.key = tmp;
				rec.val = 1;
				Insert(rec);
				tmp = "";
			}
			else
			{
				tmp += str[i];
			}
		}
	}
};