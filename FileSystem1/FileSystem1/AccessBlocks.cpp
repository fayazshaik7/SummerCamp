#include "stdafx.h"

void read_block(void *dest, unsigned int block){
	FILE *fp = fopen("HardDisk.hdd", "rb");
	if (fp == NULL){
		printf("Error loading the disk!!!\n");
		return;
	}
	fseek(fp, block * BLOCK_SIZE, SEEK_SET);
	if (fread(dest, BLOCK_SIZE, 1, fp) != 1){
		printf("Error\n");
	}
}


void write_block(void *src, unsigned int block){
	FILE *fp = fopen("HardDisk.hdd", "rb+");
	if (fp == NULL){
		printf("Error reading file!!\n");
		return;
	}
	fseek(fp, block * BLOCK_SIZE, SEEK_SET);
	if (fwrite(src, BLOCK_SIZE,1, fp) != 1){
		printf("Error writing file!!\n");
		return;
	}
	fclose(fp);
}