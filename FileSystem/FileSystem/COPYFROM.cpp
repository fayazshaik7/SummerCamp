#include "stdafx.h"


int getSeek(FILE *fp, int seek, char *fileName){
	fseek(fp, seek, SEEK_SET);
	char *ch;
	ch = (char *)malloc(16);
	if (fread(ch, 16, 1, fp) != 1) {
		printf("Error Reading\n");
		return -1;
	}
	//printf("%s\n", ch);
	int res = checkTxt(ch);
	if (res == 0)
		return seek;
	res = checkComparison(ch, fileName);
	if (res == 1){
		printf("File already exists !!!\n");
		return -1;
	}
	unsigned int start;
	if (fread(&start, 4, 1, fp) != 1){
		printf("Error writing\n");
		return -1;
	}
	//printf("%d\n", start);
	if (start == 0)
		return seek;
	unsigned int length;
	if (fread(&length, 4, 1, fp) != 1){
		printf("Error writing\n");
		return -1;
	}
	//printf("%d\n", length);
	return getSeek(fp, start + length, fileName);
}

void copyFrom(FILE *fp, int iter, char *cmd){
	char *fileName;
	fp = fopen("hardDisk.hdd", "rb+");
	if (fp == NULL){
		printf("Error file opening\n");
		return;
	}
	fileName = (char *)malloc(16);
	fileName[16] = '\0';
	int index = 0;
	for (int i = iter; cmd[i]; i++)
		fileName[index++] = cmd[i];
	fileName[index] = '\0';
	FILE *nf = fopen(fileName, "rb+");
	int len = 0;
	int v;
	while (fread(&v, 1, 1, nf) == 1)
		len++;
	char str;
	int seekpt = getSeek(fp, 0, fileName);
	if (seekpt == -1)
		return;
	fseek(fp, seekpt, SEEK_SET);
	printf("%d\n", fp);
	if (fwrite(fileName, 16, 1, fp) != 1){
		printf("Error writing\n");
		return;
	}
	unsigned int offset = seekpt + 24;
	if (fwrite(&offset, 4, 1, fp) != 1){
		printf("Error writing\n");
		return;
	}
	unsigned int length = len;
	fwrite(&length, 4, 1, fp);
	int i;
	fseek(nf, 0, SEEK_SET);
	for (i = 0; i < len; i++){
		if (fscanf(nf, "%c", &str) == EOF)
			break;
		if (fwrite(&str, 1, 1, fp) != 1){
			printf("Error writing\n");
			return;
		}
	}
	fclose(fp);

}