#include "stdafx.h"

struct node{
	int data;
	struct node *next;
};

struct node *reverse(struct node *head){

	struct node *head1, *p, *q;
	head1 = NULL;
	p = head;
	while (p != NULL){
		q = p;
		p = p->next;
		q->next = NULL;
		if (head1 == NULL)
			head1 = q;
		else{
			q->next = head1;
			head1 = q;
		}
	}
	return head1;
}

struct node *foo(int k, struct node *head){
	if (head == NULL || k <= 1)
		return head;
	struct node *temp, *br, *thead,*head1;
	temp = head;
	head1 = NULL;
	thead = head;
	int c = 0;
	while (temp != NULL){
		c++;
		if (c == k){
			br = temp;
			temp = temp->next;
			br->next = NULL;//br = break point 

			//reversing
			struct node *res = reverse(thead);

			//connecting
			thead = temp;//thead = head after break point
			if (head1 == NULL)
				head1 = res;
			else{
				struct node *t;
				t = head1;
				while (t->next != NULL)
					t = t->next;
				t->next = res;
			}
			c = 0;
			continue;
		}

		temp = temp->next;
	}
	if (head1 == NULL){
		head1 = thead;
		return head1;
	}
	if (thead != NULL){
		struct node *t;
		t = head1;
		while (t->next != NULL)
			t = t->next;
		t->next = thead;
	}

	return head1;


}