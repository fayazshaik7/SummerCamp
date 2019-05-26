#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;


void checkAvailability(char **inp, char *str, int x, int y, int str_position, int r, int c,int direction,int ix,int iy){
	//cout << x << " " << y << " " << " " << str_position << endl;

	if (str_position == (strlen(str))){
		cout << ix << " " << iy << ":" << x << " " << y << endl;
		return;
	}

	if ((direction == 0||direction==1) && x>0 && y>0 &&inp[x - 1][y - 1] == str[str_position])
		checkAvailability(inp, str, x - 1, y - 1, str_position + 1, r, c,1,ix,iy);
	if ((direction == 0 || direction == 2) && x>0 && inp[x - 1][y] == str[str_position])
		checkAvailability(inp, str, x - 1, y, str_position + 1, r, c, 2, ix, iy);
	if ((direction == 0 || direction == 3) && x>0 && y<c - 1 && inp[x - 1][y + 1] == str[str_position])
		checkAvailability(inp, str, x - 1, y + 1, str_position + 1, r, c, 3, ix, iy);
	if ((direction == 0 || direction == 4) && y>0 && inp[x][y - 1] == str[str_position])
		checkAvailability(inp, str, x, y - 1, str_position + 1, r, c, 4, ix, iy);
	if ((direction == 0 || direction == 5) && y<c - 1 && inp[x][y + 1] == str[str_position])
		checkAvailability(inp, str, x, y + 1, str_position + 1, r, c, 5, ix, iy);
	if ((direction == 0 || direction == 6) && x<r - 1 && y>0 && inp[x + 1][y - 1] == str[str_position])
		checkAvailability(inp, str, x + 1, y - 1, str_position + 1, r, c, 6, ix, iy);
	if ((direction == 0 || direction == 7) && x>r - 1 && inp[x + 1][y] == str[str_position])
		checkAvailability(inp, str, x + 1, y, str_position + 1, r, c, 7, ix, iy);
	if ((direction == 0 || direction == 8) && x<r - 1 && y<c - 1 && inp[x + 1][y + 1] == str[str_position])
		checkAvailability(inp, str, x + 1, y + 1, str_position + 1, r, c, 8, ix, iy);
}

void find_word(char **inp, char *str, int r, int c){
	int count = 0;
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			if (inp[i][j] == str[0]){
				checkAvailability(inp, str, i, j, 1,r,c,0,i,j);
			}
		}
	}
}

/*
int main(){
	int row, col;
	cin >> row >> col;
	char **inp;
	inp = (char **)malloc(sizeof(char *)*row);
	for (int i = 0; i < row; i++)
		inp[i] = (char *)malloc(sizeof(char)*col);
	for (int i = 0; i < row; i++)
		cin >> inp[i];
	char *str;
	str = (char *)malloc(sizeof(char)*10);
	cin >> str;
	scanf_s("%s", str);
	find_word(inp, str, row, col);

}*/