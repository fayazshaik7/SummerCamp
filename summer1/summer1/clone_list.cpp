#include "stdafx.h"
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<unordered_map>
using namespace std;
struct node{
	int data;
	struct node *next;
	struct node *random;
};

struct node *create_node1(int val){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = val;
	temp->next = NULL;
	temp->random = NULL;
	return temp;
}
struct node *clone_hashing(struct node *head){
	unordered_map<struct node *, struct node *> umap;
	struct node *temp;
	temp = head;
	struct node *head1, *last;
	last = NULL;
	head1 = NULL;
	while (temp != NULL){
		if (head1 == NULL){
			head1 = create_node1(temp->data);
			last = head1;
		}
		else{
			last->next = create_node1(temp->data);
			last = last->next;
		}
		umap[temp] = last;
		temp = temp->next;
	}
	temp = head1;
	struct node *temp1;
	temp1 = head;
	while (temp1 != NULL){
		temp->random = umap[temp1->random];
		temp = temp->next;
		temp1 = temp1->next;
	}

	return head1;

}

struct node *clone_break_reframe(struct node *head){
	struct node *temp = head;
	while (temp->next != NULL){
		struct node *cur = create_node1(temp->data);
		cur->next = temp->next;
		temp->next = cur;
		temp = cur->next;
	}
	struct node *cur = create_node1(temp->data);
	temp->next = cur;
	temp = head;
	struct node *rand = NULL;
	while (temp != NULL){
		if (rand == NULL && temp->random!=NULL){
			rand = temp->random->next;
		}
		else if (rand != NULL){
			temp->random = rand;
			rand = NULL;
		}
		temp = temp->next;
	}

	struct node *head1;
	head1 = head->next;
	struct node *last1 = head;
	struct node *last2 = head1;
	temp = head->next;
	while (temp != NULL){
		temp = temp->next;
		last1->next = temp;
		last1 = temp;
		if (temp == NULL)
			break;
		temp = temp->next;
		last2->next = temp;
		last2 = temp;
	}
	return head1;
}
/*
int _tmain(int argc, _TCHAR* argv[])
{
	struct node *head;
	head = create_node1(1);
	struct node *last;
	last = head;
	for (int i = 2; i <= 6; i++){
		last->next = create_node1(i);
		last = last->next;
	}
	struct node *temp;
	temp = head;
	temp->random = temp->next->next;
	temp->next->random = temp->next->next->next->next;
	temp->next->next->next->random = temp->next->next->next->next;
	temp->next->next->next->next->next->random = temp->next->next->next;
	struct node *res = clone_hashing(head);

	temp = res;
	while (temp != NULL){
		if (temp->random != NULL)
			printf("%d %d\n", temp->data, temp->random->data);
		else
			printf("%d\n", temp->data);
		temp = temp->next;
	}
	printf("*********************************\n");
	res = clone_break_reframe(head);
	temp = res;
	while (temp != NULL){
		if (temp->random != NULL)
			printf("%d %d\n", temp->data, temp->random->data);
		else
			printf("%d\n", temp->data);
		temp = temp->next;
	}

}
*/
