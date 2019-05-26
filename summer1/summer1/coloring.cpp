#include "stdafx.h"

#include<iostream>
#include<stdlib.h>
using namespace std;

int *counting_ones(int *arr, int size){
		
	int iterator;
	int sum = 0;//finds no of ones
	for (iterator = 0; iterator < size; iterator++){
		sum += arr[iterator];
	}
	for (iterator = 0; iterator < size - sum; iterator++)
		arr[iterator] = 0;
	for (iterator = size - sum; iterator < size; iterator++)
		arr[iterator] = 1;
	return arr;
}

int *sorting(int *arr, int size){
	for (int iterator1 = 0; iterator1 < size; iterator1++){
		for (int iterator2 = 0; iterator2 < size - iterator1 - 1; iterator2++){
			if (arr[iterator2]>arr[iterator2 + 1]){
				int temp = arr[iterator2];
				arr[iterator2] = arr[iterator2 + 1];
				arr[iterator2 + 1] = temp;
			}
		}
	}
	return arr;
}

int *swapping(int *arr, int size){
	int front_ptr = 0;
	int back_ptr = size - 1;
	while (front_ptr < back_ptr){
		while (arr[front_ptr] == 0)
			front_ptr++;
		while (arr[back_ptr])
			back_ptr--;
		if (front_ptr >= back_ptr)
			break;
		int temp = arr[front_ptr];
		arr[front_ptr] = arr[back_ptr];
		arr[back_ptr] = temp;
		front_ptr++ ;
		back_ptr--;
		
	}
	return arr;
}

int *ThreeColorarrangement(int *arr, int size){
	int front_ptr = 0;
	int back_ptr = size - 1;
	for (int iterator = 0; iterator <= back_ptr;){
		if (arr[iterator] == 0){
			int temp = arr[iterator];
			arr[iterator] = arr[front_ptr];
			arr[front_ptr] = temp;
			front_ptr++;
		}
		else if (arr[iterator] == 2){
			int temp = arr[iterator];
			arr[iterator] = arr[back_ptr];
			arr[back_ptr] = temp;
			back_ptr--;
		}
		else
			iterator++;
	}
	return arr;
}
/*
int _tmain(int argc, _TCHAR* argv[])
{
	int size;
	cin >> size;
	int *arr;
	arr = (int *)malloc(sizeof(int)*size);
	for (int iterator = 0; iterator < size; iterator++)
		cin >> arr[iterator];
	/*int *res = counting_ones(arr, size);
	cout << "Counting ones : ";
	for (int iterator = 0; iterator < size; iterator++)
		cout << arr[iterator]<<" ";
	cout << endl;*/
	/*int *res = sorting(arr, size);
	cout << "Sorting : ";
	for (int iterator = 0; iterator < size; iterator++)
		cout << arr[iterator] << " ";
	cout << endl;*/
	/*int *res = swapping(arr, size);
	cout << "Swapping : ";
	for (int iterator = 0; iterator < size; iterator++)
		cout << arr[iterator] << " ";
	cout << endl;

	int *res = ThreeColorarrangement(arr, size);
	for (int iterator = 0; iterator < size; iterator++)
		cout << arr[iterator] << " ";
	cout << endl; 
}*/
