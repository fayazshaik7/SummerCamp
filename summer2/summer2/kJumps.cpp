#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int climb(int n,int k,int x){
	if (n == x)
		return 1;
	int sum = 0;
	for (int i = 1; i <= k; i++){
		int p = x + i;
		if (p > n)
			break;

		sum += climb(n, k,p);
		
	}
	return sum;

}
/*
int main(){

	int n, k;
	cin >> n >> k;
	int res = climb(n, k,0);
	cout << res << endl;
}*/