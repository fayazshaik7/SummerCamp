#include "stdafx.h"
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *create_node(int val){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = val;
	temp->next = NULL;
	return temp;
}

struct node *create_list(int arr[], int n){
	struct node *head, *lastnode = NULL;
	head = NULL;
	for (int i = 0; i < n; i++){
		if (head == NULL){
			head = create_node(arr[i]);
			lastnode = head;
		}
		else{
			lastnode->next = create_node(arr[i]);
			lastnode = lastnode->next;
		}
	}
	return head;
}