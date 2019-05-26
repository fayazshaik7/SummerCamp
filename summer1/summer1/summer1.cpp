// summer1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unordered_map>
using namespace std;
struct node{
	int data;
	struct node *next;
	struct node *random;
};

struct node *create_node(int val){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = val;
	temp->next = NULL;
	temp->random = NULL;
	return temp;
}
struct node *clone(struct node *head){
	unordered_map<struct node *, struct node *> umap;
	struct node *temp;
	temp = head;
	struct node *head1,*last;
	last = NULL;
	head1 = NULL;
	while (temp != NULL){
		printf(">_>\n");
		if (head1 == NULL){
			head1 = create_node(temp->data);
			last = head1;
		}
		else{
			printf(">_>\n");
			last->next = create_node(temp->data);
		}
		printf(">_>\n");
		umap[temp] = last;
		printf(">_>\n");
		last = last->next;
		temp = temp->next;
		printf(">_>\n");
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
/*
int _tmain(int argc, _TCHAR* argv[])
{
	struct node *head;
	head = create_node(1);
	struct node *last;
	last = head;
	for (int i = 2; i <= 6; i++){
		last->next = create_node(i);
		last = last->next;
	}
	struct node *temp;
	temp = head;
	temp->random = temp->next->next;
	temp->next->random = temp->next->next->next->next;
	temp->next->next->next->random = temp->next->next->next->next;
	temp->next->next->next->next->next->random = temp->next->next->next;
	struct node *res = clone(head);

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