#include "stdafx.h"
#include "TTable.h"
#include "string"
#include "stdlib.h"
#include "stdio.h"
#include "memory"

TTable::TTable()
{
	WordsInDictionary = 0;
}

char* TTable::FindWord(char* bulgarianWord) {
	for (int i = 0; i < WordsInDictionary; i++) {
		if (!strcmp(Row[i].BulgarianWord, bulgarianWord)) {
			return Row[i].EnglishWord;
		}
	}

	return "Dumata ne e namerena v re4nika";
}

void TTable::AddWord(char* bulgarianWord, char* englishWord) {
	Row[WordsInDictionary].BulgarianWord = bulgarianWord;
	Row[WordsInDictionary].EnglishWord = englishWord;
	WordsInDictionary++;
}

void TTable::RemoveWord(char* bulgarianWord) {
	bool wordExists = false;
	for (int i = 0; i < WordsInDictionary; i++) {
		if (!strcmp(Row[i].BulgarianWord, bulgarianWord)) {
			wordExists = true;
			for (int j = i; j < WordsInDictionary; j++) {
				Row[j] = Row[j + 1];
			}
		}
	}

	if (!wordExists) {
		printf("The word %s is not found in the dictionary! Cannot delete!", bulgarianWord);
	}
}

void TTable::PrintTable() {
	for (int i = 0; i < WordsInDictionary; i++) {
		printf("%s\t%s\n", Row[i].BulgarianWord, Row[i].EnglishWord);
	}
	printf("\n%d", WordsInDictionary);
}
