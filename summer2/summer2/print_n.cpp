#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

void pr(int *arr,int n){
	int search_0 = 1;
	for (int i = 0; i < n-1; i++){
		int k = arr[i];
		if (k == 0 && search_0 == 1&&i!=n-1)
			continue;
		if (k == 0 || k == 1 || k == 8 || k == 5 || k == 2)
			cout << k;
		else if (k == 3)
			cout << "E";
		else if (k == 4)
			cout << "h";
		else if (k == 6)
			cout << k + 3;
		else if (k == 9)
			cout << k - 3;
		else
			cout << "L";
		search_0 = 0;
	}
	if (search_0 == 1)
		cout << "0";
}

void pr_n(int n,int *arr,int x){
	if (x == n-1){
		pr(arr,n);
		cout << endl;
		return;
	}
	for (int i = 0; i < 10; i++){
		arr[x] = i;
		pr_n(n, arr, x + 1);
	}
}
/*
int main(){
	int n;
	cin >> n;
	int *arr = (int *)malloc(sizeof(int)*n - 1);
	pr_n(n,arr,0);

}*/