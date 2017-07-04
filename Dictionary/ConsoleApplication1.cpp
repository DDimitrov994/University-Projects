// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TTable.h"
#include "string"
#include "stdlib.h"
#include "stdio.h"
#include "memory"
#include "TTable.h"
#include "TDihotTable.h"
//#include "THashTable.h"

int _tmain(int argc, _TCHAR* argv[])
{
	TDihotTable dictionary;


	dictionary.AddWord("kola", "car");
	dictionary.AddWord("vrata", "door");
	dictionary.AddWord("kompiutar", "computer");
	dictionary.AddWord("mishka", "mouse");
	dictionary.AddWord("zapis", "record");

	FILE *source, *destination;

	source = fopen("bulgarianWords.txt", "r");
	destination = fopen("englishWords.txt", "w");

	const size_t line_size = 300;
	char* line = (char*)malloc(line_size);

	while (fgets(line, line_size, source) != NULL) {
		strtok(line, "\n");
		char* word =  dictionary.FindWord(line);
		fputs(word, destination);
		fputs("\n", destination);
	}
	dictionary.PrintTable();

	free(line);
	fclose(source);
	fclose(destination);
	system("pause");
	return 0;
}

