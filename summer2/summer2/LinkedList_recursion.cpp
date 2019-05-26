#include "stdafx.h"
#include "LL.h"
struct node *Reverse_recursion(struct node *head){
	if (head == NULL)
		return head;
	struct node *temp = head;
	struct node *res = Reverse_recursion(head->next);
	if (res == NULL)
		res = temp;
	else{
		struct node *iter = res;
		while (iter->next != NULL)
			iter = iter->next;
		iter->next = temp;
		temp->next = NULL;
	}
	return res;
}
/*
int main(){
	int size;
	cin >> size;
	int element;
	struct node *head=NULL,*last=NULL;
	for (int i = 0; i < size; i++){
		cin >> element;
		if (head == NULL){
			head = createNode(element);
			last = head;
		}
		else{
			last->next = createNode(element);
			last = last->next;
		}
	}
	struct node *res = Reverse_recursion(head);
	while (res != NULL){
		cout << res->data << " ";
		res = res->next;
	}
	cout << endl;
}*/
