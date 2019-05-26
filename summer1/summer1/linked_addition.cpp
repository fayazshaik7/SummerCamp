#include "stdafx.h"
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

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

struct node *add_recursively(struct node *temp1, struct node *temp2){
	if (temp1 == NULL || temp2 == NULL)
		return create_node(0);
	struct node *res=add_recursively(temp1->next, temp2->next);
	int ad = temp1->data + temp2->data+res->data;
	int b = 0;
	if (ad >= 10){
		ad = ad - 10;
		b = 1;
	}
	res->data = ad;
	struct node *cur = create_node(b);
	cur->next = res;
	res = cur;
	return res;

}
struct node *add_remaining(struct node *res, struct node *head1, int t){
	if (t==0||head1==NULL)
		return res;
	struct node *res1 = add_remaining(res, head1->next, --t);
	int ad = head1->data + res1->data;
	int b = 0;
	if (ad >= 10){
		ad = ad - 10;
		b = 1;
	}
	res1->data = ad;
	struct node *cur = create_node(b);
	cur->next = res1;
	res1 = cur;
	return res1;
}
struct node *addition(struct node *head1, struct node *head2, int n1, int n2){
	struct node *temp1, *temp2;
	struct node *res;
	temp1 = head1;
	temp2 = head2;
	if (n1 > n2){
		n1 = n1 - n2;
		int t = n1;
		while (n1--)
			temp1 = temp1->next;
		res = add_recursively(temp1, temp2);
		res = add_remaining(res, head1, t);
	}
	else{
		n2 = n2 - n1;
		int t = n2;
		while (n2--)
			temp2 = temp2->next;
		res = add_recursively(temp1, temp2);
		res = add_remaining(res, head2, t);
	}
	if (res->data == 0)
		res = res->next;
	return res;
}
int main(){
	int n1;
	int *arr1;
	cin >> n1;
	arr1 = (int *)malloc(sizeof(int)*n1);
	for (int i = 0; i < n1; i++){
		cin >> arr1[i];
	}
	int n2;
	int *arr2;
	cin >> n2;
	arr2 = (int *)malloc(sizeof(int)*n2);
	for (int i = 0; i < n2; i++){
		cin >> arr2[i];
	}
	struct node *head1, *head2;
	head1 = create_list(arr1, n1);
	head2 = create_list(arr2, n2);
	struct node *res = addition(head1, head2, n1, n2);
	while (res != NULL){
		cout << res->data << " ";
		res = res->next;
	}
}