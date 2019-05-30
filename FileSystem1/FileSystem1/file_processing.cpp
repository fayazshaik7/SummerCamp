#include "stdafx.h"

void INIT(struct MetaData *meta_data[],struct OtherData *other_data){
	char *src = (char *)malloc(BLOCK_SIZE);
	unsigned int val = 0x444E524D;
	memcpy(src, &val, 4);
	for (int index = 0; index < NO_OF_FILES; index++){
		meta_data[index]->blocks_occupied = 0;
		meta_data[index]->fileName[0] = '\0';
		meta_data[index]->file_length = 0;
		meta_data[index]->start_block = -1;
		memcpy(src + 4 + (index*sizeof(struct MetaData)), meta_data[index], sizeof(struct MetaData));
	}
	other_data->no_of_files = 0;
	other_data->no_of_free_blocks = NO_OF_DATA_BLOCKS;
	memcpy(src + sizeof(int) + (NO_OF_FILES * NO_OF_FILES), &other_data->no_of_files, 4);
	memcpy(src + sizeof(int) + (NO_OF_FILES * NO_OF_FILES) + sizeof(int), &other_data->no_of_free_blocks, 4);
	for (int i = 0; i < NO_OF_DATA_BLOCKS + 4; i++){
		other_data->bitVector[i] = '1';
	}
	memcpy(src + sizeof(int) + (NO_OF_FILES * NO_OF_FILES) + sizeof(int) + sizeof(int), other_data->bitVector, NO_OF_DATA_BLOCKS + 4);
	write_block(src, 0);
}

void list(FILE *fp, struct MetaData *meta_data[], struct OtherData *other_data){
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
	for (int i = 0; i < other_data->no_of_files; i++){
		if (!check_name(meta_data[i]->fileName))
			continue;
		printf("%s %u %u %u\n", meta_data[i]->fileName, meta_data[i]->start_block, meta_data[i]->blocks_occupied, meta_data[i]->file_length);
	}
	printf("No of Files = %u\n", other_data->no_of_files);
	printf("No of Free blocks = %u\n", other_data->no_of_free_blocks);
	
	return;

}

void Debugger(FILE *fp, struct MetaData *meta_data[], struct OtherData *other_data){
	list(fp,meta_data,other_data);
}

void Format(FILE *fp, struct MetaData *meta_data[], struct OtherData *other_data){
	INIT(meta_data, other_data);
}
