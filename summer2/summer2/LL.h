#include <string.h>
#include <iostream>
using namespace std;
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *createNode(int data){
	struct node *cur;
	cur = (struct node *)malloc(sizeof(struct node));
	cur->data = data;
	cur->next = NULL;
	return cur;
}