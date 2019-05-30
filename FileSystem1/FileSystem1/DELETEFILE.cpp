#include "stdafx.h"

void delete_file(FILE *fp, int iter, char *cmd, struct MetaData *meta_data[], struct OtherData *other_data){
	char *FileName;
	FileName = (char *)malloc(NAME_SIZE);
	int index = 0;
	for (int i = iter; cmd[i]; i++)
		FileName[index++] = cmd[i];
	FileName[index] = '\0';

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
	dest = dest + 4;
	memcpy(other_data->bitVector, dest, NO_OF_DATA_BLOCKS + 4);

	for (int i = 0; i<other_data->no_of_files; i++){
		if (comparestr(meta_data[i]->fileName, FileName)){

			int srtInd = meta_data[i]->start_block;
			int ReqBlocks = meta_data[i]->blocks_occupied;
			int strBlk = srtInd / BLOCK_SIZE;
			for (int j = strBlk; j <= ReqBlocks; j++)
				other_data->bitVector[j] = '1';
			other_data->no_of_free_blocks += ReqBlocks;
			meta_data[i]->blocks_occupied = 0;
			meta_data[i]->fileName[0] = '\0';
			meta_data[i]->file_length = 0;
			meta_data[i]->start_block = -1;
			other_data->no_of_files -=1;
			if (i == (other_data->no_of_files)){
				break;
			}
			strcpy(meta_data[i]->fileName, meta_data[other_data->no_of_files]->fileName);
			meta_data[i]->start_block = meta_data[other_data->no_of_files]->start_block;
			meta_data[i]->blocks_occupied = meta_data[other_data->no_of_files]->blocks_occupied;
			meta_data[i]->file_length = meta_data[other_data->no_of_files]->file_length;
			break;
		}
	}
	char *src = (char *)malloc(BLOCK_SIZE);
	unsigned int val = 0x444E524D;
	memcpy(src, &val, 4);
	for (int index = 0; index < NO_OF_FILES; index++){
		memcpy(src + 4 + (index*sizeof(struct MetaData)), meta_data[index], sizeof(struct MetaData));
	}
	memcpy(src + sizeof(int) + (NO_OF_FILES * NO_OF_FILES), &other_data->no_of_files, sizeof(int));
	memcpy(src + sizeof(int) + (NO_OF_FILES * NO_OF_FILES) + sizeof(int), &other_data->no_of_free_blocks, sizeof(int));
	memcpy(src + sizeof(int) + (NO_OF_FILES * NO_OF_FILES) + sizeof(int) + sizeof(int), other_data->bitVector, NO_OF_DATA_BLOCKS + 4);
	write_block(src, 0);

}