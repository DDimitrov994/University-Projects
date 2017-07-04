#ifndef TDIHOTTABLE_H
#define TDIHOTTABLE_H

struct TableRow2 {
	char *EnglishWord;
	char *BulgarianWord;
};

class TDihotTable
{
	TableRow2 Row[50];
	int WordsInDictionary;

public:
	TDihotTable();
	char* FindWord(char* bulgarianWord);
	void AddWord(char* bulgarianWord, char* englishWord);
	void RemoveWord(char* bulgarianWord);
	void PrintTable();
};

#endif // TDIHOTTABLE_H
