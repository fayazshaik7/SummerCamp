// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <string.h>
#define BLOCK_SIZE (16*1024)
#define NO_OF_FILES 32
#define NAME_SIZE 20
#define NO_OF_DATA_BLOCKS 6395

struct MetaData{
	char fileName[NAME_SIZE];
	unsigned int start_block;
	unsigned int blocks_occupied;
	unsigned int file_length;
};
struct OtherData{
	unsigned int magicNumber = 0x444E524D;
	unsigned int no_of_files;
	unsigned int no_of_free_blocks;
	char bitVector[NO_OF_DATA_BLOCKS];
};
void INIT(struct MetaData *meta_data[], struct OtherData *other_data);
void decodeInput(FILE *fp, char *cmd, struct MetaData *meta_data[], struct OtherData *other_data);
void copyFromDisk(FILE *fp, int iter, char *cmd, struct MetaData *meta_data[], struct OtherData *other_data);
void copy_to_disk(FILE *fp, int iter, char *cmd, struct MetaData *meta_data[], struct OtherData *other_data);
void list(FILE *fp, struct MetaData *meta_data[], struct OtherData *other_data);
int check_name(char ch[]);
unsigned int getFileSize(char *fileName);
void read_block(void *dest, unsigned int block);
void write_block(void *src, unsigned int block);
int comparestr(char *a, char *b);
void delete_file(FILE *fp, int iter, char *cmd, struct MetaData *meta_data[], struct OtherData *other_data);
void Debugger(FILE *fp, struct MetaData *meta_data[], struct OtherData *other_data);
void Format(FILE *fp, struct MetaData *meta_data[], struct OtherData *other_data);



// TODO: reference additional headers your program requires here
