// FileSystem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
int getOperation(char *token){
	if (strcmp(token, "copyFrom\0") == 0)
		return 0;
	if (strcmp(token, "ls\0") == 0)
		return 1;
	if (strcmp(token, "copyTo\0") == 0)
		return 2;
	return -1;
}
int checkTxt(char *ch){
	for (int i = 0; i < 13; i++){
		if (ch[i] == '.'){
			return 1;
		}
	}
	return 0;
}
int checkComparison(char *ch, char *fileName){
	for (int i = 0; fileName[i]; i++){
		if (ch[i] != fileName[i])
			return 0;
	}
	return 1;
}


void list(FILE *fp){
	fp = fopen("hardDisk.hdd", "rb");
	if (fp == NULL){
		printf("error!!\n");
		return;
	}
	while (1){
		char *ch;
		ch = (char *)malloc(16);
		if (fread(ch, 16, 1, fp) != 1) {
			printf("Error Reading\n");
			return;
		}
		int res = checkTxt(ch);
		if (res == 0)
			return;

		puts(ch);
		printf("\n");
		unsigned int start;
		if (fread(&start, 4, 1, fp) != 1){
			printf("Error writing\n");
			return;
		}
		unsigned int length;
		if (fread(&length, 4, 1, fp) != 1){
			printf("Error writing\n");
			return;
		}
		fseek(fp, start + length, SEEK_SET);


	}
}

void decodeInput(FILE *fp, char *cmd){
	char *token = (char *)malloc(7);
	int tokenIndex = 0;
	int operation = -1;
	int iter;
	for (iter = 0; cmd[iter]; iter++){
		if (cmd[iter] == ' '){
			break;
		}
		token[tokenIndex++] = cmd[iter];
	}
	token[tokenIndex] = '\0';
	operation = getOperation(token);
	if (operation == 0)
		copyFrom(fp, iter + 1, cmd);
	else if(operation == 1)
		list(fp);
	else if (operation == 2)
		copyTo(fp, iter + 1, cmd);
	else
		exit(0);

}

int _tmain(int argc, _TCHAR* argv[])
{
	FILE *fp;
	fp = (FILE *)malloc(sizeof(FILE));
	while (1){
		printf("> ");
		char *inp;
		inp = (char *)malloc(16);
		gets(inp);
		decodeInput(fp, inp);
	}
	return 0;
}

