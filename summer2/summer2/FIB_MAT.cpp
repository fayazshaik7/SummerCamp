#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int **multiply(int **a, int **b){
	int x = a[0][0] * b[0][0] + a[0][1] * b[1][0];
	int y = a[0][0] * b[0][1] + a[0][1] * b[1][1];
	int p = a[1][0] * b[0][0] + a[1][1] * b[1][0];
	int q = a[1][0] * b[0][1] + a[1][1] * b[1][1];
	a[0][0] = x;
	a[0][1] = y;
	a[1][0] = p;
	a[1][1] = q;
	return a;
}


int **fib(int n){

	int **a = (int **)malloc(sizeof(int *)*2);
	a[0] = (int *)malloc(sizeof(int) * 2);
	a[1] = (int *)malloc(sizeof(int) * 2);
	a[0][0] = 0;
	a[0][1] = a[1][0] = a[1][1] = 1;
	if (n == 1)
		return a;
	int **res;
	
	res = fib(n / 2);
	res = multiply(res, res);
	if (n % 2 != 0){
		res = multiply(res, a);
	}
	return res;
}

int main(){
	int n;
	cin >> n;
	int **res = fib(n);
	cout << res[0][1] << endl;;
}