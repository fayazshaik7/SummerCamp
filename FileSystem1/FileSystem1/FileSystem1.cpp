// FileSystem1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int getOperation(char *token){
	if (strcmp(token, "INIT\0") == 0)
		return 0;
	if (strcmp(token, "LS\0") == 0)
		return 1;
	if (strcmp(token, "COPYTODISK\0") == 0)
		return 2;
	if (strcmp(token, "COPYFROMDISK\0") == 0)
		return 3;
	if (strcmp(token, "DELETE\0") == 0)
		return 4;
	if (strcmp(token, "DEBUGGER\0") == 0)
		return 5;
	if (strcmp(token, "FORMAT\0") == 0)
		return 6;
	return -1;
}

int check_name(char ch[]){
	for (int i = 0; i < NAME_SIZE; i++)
		if (ch[i] == '.')
			return 1;
	return 0;
}


void decodeInput(FILE *fp, char *cmd,struct MetaData *meta_data[],struct OtherData *other_data){
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
		INIT(meta_data,other_data);
	else if (operation == 1)
		list(fp,meta_data,other_data);
	else if (operation == 2)
		copy_to_disk(fp, iter + 1, cmd,meta_data,other_data);
	else if (operation == 3)
		copyFromDisk(fp, iter + 1, cmd, meta_data, other_data);
	else if (operation == 4)
		delete_file(fp, iter + 1, cmd, meta_data, other_data);
	else if (operation == 5)
		Debugger(fp, meta_data, other_data);
	else if (operation == 6)
		Format(fp, meta_data, other_data);
	else
		exit(0);

}

int _tmain(int argc, _TCHAR* argv[])
{
	FILE *fp;
	fp = (FILE *)malloc(sizeof(FILE));
	fp = fopen("HardDisk.hdd", "rb");
	if (fp == NULL){
		printf("Error opening the disk !!!\n");
		return 0;
	}
	struct MetaData *meta_data[NO_OF_FILES];
	for (int i = 0; i < NO_OF_FILES; i++){
		meta_data[i] = (struct MetaData *)malloc(sizeof(struct MetaData));
	}
	struct OtherData *other_data;
	other_data = (struct OtherData *)malloc(sizeof(struct OtherData));
	unsigned int val = 0x444E524D;
	unsigned int check;
	fread(&check, 4, 1, fp);
	fclose(fp);
	if (val != check){
		printf("Formatting disk is required!!!\n");
		printf("Formatting the disk.....\n");
		INIT(meta_data, other_data);
		printf("Disk Formatted Successfully!!\n");
	}
	while (1){
		printf("> ");
		char *inp;
		inp = (char *)malloc(16);
		gets(inp);
		decodeInput(fp, inp,meta_data,other_data);
	}
	return 0;
}