#include "stdafx.h"

#include<iostream>
using namespace std;

/*
struct node *findLoopStarting(struct node *head){
	struct node *slow;
	struct node *fast;
	slow = head;
	fast = head;
	while (slow != fast || head == fast ){
		if (head->next == head)
			break;
		slow = slow->next;
		fast = fast->next->next;
	}
	slow = head;
	while (slow != fast){
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}


/*
int main(){
	int size;
	cin >> size;
	int *arr;
	arr = (int *)malloc(sizeof(int)*size);
	for (int iterator = 0; iterator < size; iterator++)
		cin >> arr[iterator];
	struct node *head = create_list(arr, size);
	struct node *temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = head;
	struct node *res = findLoopStarting(head);
	cout << "start of the loop : " << res->data << endl;
}*/