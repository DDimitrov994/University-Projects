#include "stdafx.h"
#include "TDihotTable.h"
#include "string"
#include "stdlib.h"
#include "stdio.h"
#include "memory"

TDihotTable::TDihotTable()
{
	WordsInDictionary = 0;
}

char* TDihotTable::FindWord(char* bulgarianWord) {
	int first = 0,
		last = WordsInDictionary - 1,
		middle,
		position = -1;
	bool found = false;

	while (!found && first <= last) {
		middle = (first + last) / 2;
		if (!strcmp(Row[middle].BulgarianWord, bulgarianWord)) {
			found = true;
			position = middle;
		}
		else if (strcmp(Row[middle].BulgarianWord, bulgarianWord) > 0) {
			last = middle - 1;
		}
		else {
			first = middle + 1;
		}
	}

	if (position != -1) {
		return Row[position].EnglishWord;
	}
	else {
		return "Dumata ne e namerena v re4nika";
	}

}

void TDihotTable::AddWord(char* bulgarianWord, char* englishWord) {
	if (WordsInDictionary == 0) {
		Row[WordsInDictionary].BulgarianWord = bulgarianWord;
		Row[WordsInDictionary].EnglishWord = englishWord;
		WordsInDictionary++;
		return;
	}

	int indexToInsertAt = WordsInDictionary;
	for (int i = 0; i < WordsInDictionary; i++) {
		if (strcmp(Row[i].BulgarianWord, bulgarianWord) > 0) {
			indexToInsertAt = i;
			break;
		}
	}

	if (indexToInsertAt == WordsInDictionary) {
		Row[WordsInDictionary].BulgarianWord = bulgarianWord;
		Row[WordsInDictionary].EnglishWord = englishWord;
		WordsInDictionary++;
		return;
	}

	WordsInDictionary++;

	for (int i = 0; i < WordsInDictionary; i++) {
		if (i > indexToInsertAt) {
			Row[i] = Row[i - 1];
		}
	}
	Row[indexToInsertAt].BulgarianWord = bulgarianWord;
	Row[indexToInsertAt].EnglishWord = englishWord;
}

void TDihotTable::RemoveWord(char* bulgarianWord) {
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

void TDihotTable::PrintTable() {
	for (int i = 0; i < WordsInDictionary; i++) {
		printf("%s\t%s\n", Row[i].BulgarianWord, Row[i].EnglishWord);
	}
	printf("\nwords in dictionary: %d\n", WordsInDictionary);
}
