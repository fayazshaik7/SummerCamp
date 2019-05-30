#include "stdafx.h"

int comparestr(char *a, char *b){
	for (int i = 0; b[i]; i++)
		if (a[i] != b[i])
			return 0;
	return 1;
}

void copyFromDisk(FILE *fp, int iter, char *cmd,struct MetaData *meta_data[],struct OtherData *other_data){
	char *source, *destination;
	int sIndex = 0, dIndex = 0;
	source = (char *)malloc(20);
	destination = (char *)malloc(20);
	int i;
	for (i = iter; cmd[i] != ' '; i++){
		source[sIndex++] = cmd[i];
	}
	source[sIndex] = '\0';
	for (int j = i + 1; cmd[j]; j++)
		destination[dIndex++] = cmd[j];
	destination[dIndex] = '\0';

	char *dest = (char *)malloc(BLOCK_SIZE);
	read_block(dest, 0);
	memcpy(&other_data->magicNumber, dest, 4);
	dest = dest + 4;
	for (int i = 0; i < NO_OF_FILES; i++){
		memcpy(meta_data[i], dest, sizeof(struct MetaData));
		dest = dest + sizeof(struct MetaData);
	}
	memcpy(&other_data->no_of_files, dest, 4);
	dest = dest + 4;
	memcpy(&other_data->no_of_free_blocks, dest, 4);
	unsigned int startIndx = -1;
	unsigned int length = -1;
	unsigned int ReqBlocks = -1;
	for (int i = 0; i < NO_OF_FILES; i++){
		if (comparestr(meta_data[i]->fileName, source)){
			startIndx = meta_data[i]->start_block;
			length = meta_data[i]->file_length;
			ReqBlocks = meta_data[i]->blocks_occupied;
			break;
		}
	}
	if (startIndx == -1){
		printf("Source not found!!\n");
		return;
	}
	FILE *fp1 = fopen(destination, "wb");
	int startBlock = startIndx / BLOCK_SIZE;
	for (int i = 0; i < ReqBlocks; i++){
		if (i == ReqBlocks - 1){
			char *dest = (char *)malloc(BLOCK_SIZE);
			read_block(dest, startBlock + i);
			if (fwrite(dest, length%BLOCK_SIZE, 1, fp1) != 1){
				printf("Write error\n");
				return;
			}
		}
		else{
			char *dest = (char *)malloc(BLOCK_SIZE);
			read_block(dest, startBlock + i);
			if (fwrite(dest, BLOCK_SIZE, 1, fp1) != 1){
				printf("Write error\n");
				return;
			}

		}
	}
	fclose(fp1);
}