#include "stdafx.h"


int findText(FILE *fp, char *fileName){
	while (1){
		char *ch;
		ch = (char *)malloc(16);
		if (fread(ch, 16, 1, fp) != 1) {
			printf("Error Reading\n");
			return -1;
		}
		int res = checkComparison(ch, fileName);
		if (res == 1){
			unsigned int start;
			if (fread(&start, 4, 1, fp) != 1){
				printf("Error writing\n");
				return -1;
			}
			unsigned int length;
			if (fread(&length, 4, 1, fp) != 1){
				printf("Error writing\n");
				return -1;
			}
			return 1;
		}
		res = checkTxt(ch);
		if (res == 0){
			printf("File Not Found!!!\n");
			return -1;
		}

		unsigned int start;
		if (fread(&start, 4, 1, fp) != 1){
			printf("Error writing\n");
			return -1;
		}
		unsigned int length;
		if (fread(&length, 4, 1, fp) != 1){
			printf("Error writing\n");
			return -1;
		}
		fseek(fp, start + length, SEEK_SET);


	}
	return 1;

}

void copyTo(FILE *fp, int iter, char *cmd){
	fp = fopen("hardDisk.hdd", "rb");
	if (fp == NULL){
		printf("error!!\n");
		return;
	}
	char *fileName;
	fileName = (char *)malloc(16);
	int index = 0;
	int i;
	for (i = iter; cmd[i] != ' '; i++)
		fileName[index++] = cmd[i];
	fileName[index] = '\0';

	char *fileName1;
	fileName1 = (char *)malloc(16);
	index = 0;
	for (int j = i + 1; cmd[j]; j++)
		fileName1[index++] = cmd[j];
	fileName1[index] = '\0';

	FILE *wf = fopen(fileName1, "wb");
	if (wf == NULL){
		printf("Error!!\n");
		return;
	}
	int res = findText(fp, fileName);
	if (res == -1)
		return;
	while(1){
		char ch;
		if (fread(&ch, 1, 1, fp) != 1)
			break;
		fwrite(&ch, 1, 1, wf);
	}
	fclose(wf);
}
