#ifndef TTABLE_H
#define TTABLE_H

struct TableRow {
	char *EnglishWord;
	char *BulgarianWord;
};

class TTable
{
	TableRow Row[50];
	int WordsInDictionary;

public:
	TTable();
	char* FindWord(char* bulgarianWord);
	void AddWord(char* bulgarianWord, char* englishWord);
	void RemoveWord(char* bulgarianWord);
	void PrintTable();
};

#endif // TTABLE_H
