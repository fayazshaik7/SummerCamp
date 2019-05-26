#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

struct node{
	int data;
	struct node *prev;
	struct node *next;
};

struct node *create_node(int data){
	struct node *_new;
	_new = (struct node *)malloc(sizeof(struct node));
	_new->data = data;
	_new->next = NULL;
	_new->prev = NULL;
	return _new;
}

struct node *merge(struct node *half1, struct node *half2){
	struct node *res = NULL,*last = NULL;
	while (half1 != NULL && half2 != NULL){
		if (half1->data > half2->data){
			if (res == NULL){
				res = half2;
				last = res;
				half2 = half2->next;
				if (half2!=NULL)
					half2->prev = NULL;
			}
			else{
				last->next = half2;
				half2->prev = last;
				last = half2;
				half2 = half2->next;
				if (half2 != NULL)
					half2->prev = NULL;
			}
		}
		else{
			if (res == NULL){
				res = half1;
				last = res;
				half1 = half1->next;
				if (half1 != NULL)
					half1->prev = NULL;
			}
			else{
				last->next = half1;
				half1->prev = last;
				last = half1;
				half1 = half1->next;
				if (half1 != NULL)
					half1->prev = NULL;
			}
		}


	}
	while (half1 != NULL){
		if (res == NULL){
			res = half1;
			last = res;
			half1 = half1->next;
			if (half1 != NULL)
				half1->prev = NULL;
		}
		else{
			last->next = half1;
			half1->prev = last;
			last = half1;
			half1 = half1->next;
			if (half1 != NULL)
				half1->prev = NULL;
		}
	}
	while (half2 != NULL){
		if (res == NULL){
			res = half2;
			last = res;
			half2 = half2->next;
			if (half2 != NULL)
				half2->prev = NULL;
		}
		else{
			last->next = half2;
			half2->prev = last;
			last = half2;
			half2 = half2->next;
			if (half2 != NULL)
				half2->prev = NULL;
		}
	}
	return res;

}

struct node *mergeSort(struct node *head){

	if (head->next == NULL)
		return head;
	//finding mid point
	struct node *mid, *temp;
	mid = head;
	temp = head;
	while (temp!= NULL){
		mid = mid->next;
		temp = temp->next;
		if (temp != NULL)
			temp = temp->next;
	}

	
	struct node *half_1 = head;
	mid->prev->next = NULL;;
	mid->prev = NULL;
	struct node *half_2 = mid;
	half_1 = mergeSort(half_1);
	half_2 = mergeSort(half_2);
	return merge(half_1, half_2);

}
/*
int main(){
	int size,element;
	cin >> size;
	struct node *head,*last;
	head = NULL;
	last = NULL;
	for (int iter = 0; iter < size; iter++){
		cin >> element;
		if (head == NULL){
			head = create_node(element);
			last = head;
		}
		else{
			last->next = create_node(element);
			last->next->prev = last;
			last = last->next;
		}
	}
	struct node *res = mergeSort(head);
	struct node *temp;
	temp = res;
	while (temp->next != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << temp->data << endl;
	

}





/*

struct node *temp;
temp = head;
while (temp->next != NULL){
cout << temp->data << " ";
temp = temp->next;
}
cout << temp->data << endl;

while (temp != NULL){
cout << temp->data << " ";
temp = temp->prev;
}
cout << endl;
*/