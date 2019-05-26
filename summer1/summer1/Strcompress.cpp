#include "stdafx.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *find_count_string(int count){
	char *ch;
	ch = (char *)malloc(100);
	int i = 0;
	while (count != 0){
		int r = count % 10;
		ch[i++] = r + 48;
		count = count / 10;
	}
	ch[i] = '\0';
	_strrev(ch);
	return ch;
}

char *compress(char ch[]){
	int count = 1;
	int j = 0, i;
	char *countstring;
	for (i = 0; ch[i + 1]; i++){
		if (ch[i] != ch[i + 1]){
			if (count > 1){
				countstring = find_count_string(count);
				count = 1;
				ch[j++] = ch[i];
				for (int k = 0; countstring[k]; k++)
					ch[j++] = countstring[k];
				continue;
			}
			else{
				ch[j++] = ch[i];
				count = 1;
				continue;
			}

		}
		count++;
	}
	if (count > 1){
		countstring = find_count_string(count);
		count = 1;
		ch[j++] = ch[i];
		for (int k = 0; countstring[k]; k++)
			ch[j++] = countstring[k];
	}
	else{
		ch[j++] = ch[i];
	}
	ch[j] = '\0';

	return ch;

}