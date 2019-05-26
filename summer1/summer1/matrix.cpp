#include "stdafx.h"

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int **transpose(int **arr,int r,int c){
	int **res;
	res = (int **)malloc(sizeof(int *)*c);
	for (int i = 0; i < c; i++)
		res[i] = (int *)malloc(sizeof(int)*r);
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			res[j][i] = arr[i][j];
		}
	}
	return res;
}
int *spiral(int **arr, int r, int c){
	int *res;
	res = (int *)malloc(sizeof(int)*(r*c));
	int i = 0;
	int l = 0;
	int h = 0;
	while (l <= r&&h <= c){
		//printf("%d %d %d %d\n", l, r, h, c);
		for (int p = h; p <= c; p++)
			res[i++] = arr[l][p];
		l++;
		for (int p = l; p <= r; p++)
			res[i++] = arr[p][c];
		c--;
		for (int p = c; p >= h; p--)
			res[i++] = arr[r][p];
		r--;
		for (int p = r; p >= l; p--)
			res[i++] = arr[p][h];
		h++;
	}
	return res;
}
/*
int _tmain(int argc, _TCHAR* argv[])
{
	
	int r, c;
	cin >> r >> c;
	int **arr;
	arr = (int **)malloc(sizeof(int *)*r);
	for (int i = 0; i < r; i++)
		arr[i] = (int *)malloc(sizeof(int)*c);
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin>>arr[i][j];
	int **res=transpose(arr,r,c);
	printf("*************transpose***********\n");
	for (int i = 0; i < c; i++){
		for (int j = 0; j < r; j++){
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
	int *res1 = spiral(arr, r-1, c-1);
	printf("*******spiral********\n");
	for (int i = 0; i < r*c; i++)
		printf("%d ", res1[i]);
	printf("\n");
}*/