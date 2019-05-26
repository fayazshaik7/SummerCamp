#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

bool shouldSwap(int arr[], int start, int curr)
{
	for (int i = start; i < curr; i++)
		if (arr[i] == arr[curr])
			return 0;
	return 1;
}
void permutationsRepetetions(int *arr, int n,int x){
	if (x == n){
		for (int j = 0; j < n; j++)
			cout << arr[j] << " ";
		cout << endl;
		return;
	}
	for (int i = x; i < n; i++){
		if (shouldSwap(arr,x,i)){
			int temp = arr[x];
			arr[x] = arr[i];
			arr[i] = temp;
			permutationsRepetetions(arr, n, x + 1);
			temp = arr[x];
			arr[x] = arr[i];
			arr[i] = temp;
		}
	}

}

void permutate(int *arr, int n, int x){
	if (x == n){
		for (int j = 0; j < n; j++)
			cout << arr[j] << " ";
		cout << endl;
		return;
	}

	for (int i = x; i < n; i++){
		int temp = arr[x];
		arr[x] = arr[i];
		arr[i] = temp;
		permutate(arr, n, x + 1);
		temp = arr[x];
		arr[x] = arr[i];
		arr[i] = temp;
	}


}
/*
int main(){
	int n;
	cin >> n;
	int *arr = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << "--------------------" << endl;
	permutate(arr, n,0);
	cout << "--------------------" << endl;
	permutationsRepetetions(arr, n, 0);

}*/