#include "stdafx.h"
#include "CppUnitTest.h"
#include "../summer1/linkedlist_reverse.cpp"
#include<stdlib.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(reverse_k_test)
	{
	public:

		struct node *create_node(int val){
			struct node *temp;
			temp = (struct node *)malloc(sizeof(struct node));
			temp->data = val;
			temp->next = NULL;
			return temp;
		}

		struct node *create_list(int arr[], int n){
			struct node *head,*lastnode;
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

		int compare(struct node *res, int exp[], int n){
			int i = 0;
			while (res != NULL&&i<n){
				if (res->data != exp[i])
					return 0;
				res = res->next;
				i++;
			}
			if (res == NULL&&i == n)
				return 1;
			return 0;
		}
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
			int arr[10] = { 1, 2, 3, 4, 5 };
			struct node *head = create_list(arr, 5);
			int k = 2;
			struct node *res = foo(k, head);
			int exp[100] = { 2, 1, 4, 3, 5 };
			Assert::AreEqual(compare(res, exp, 5), 1);
		}

		TEST_METHOD(TestMethod2)
		{
			// TODO: Your test code here
			int arr[10] = { 1, 2, 3, 4, 5 };
			struct node *head = create_list(arr, 5);
			int k = 3;
			struct node *res = foo(k, head);
			int exp[100] = {3,2,1,4,5 };
			Assert::AreEqual(compare(res, exp, 5), 1);
		}

		TEST_METHOD(TestMethod3)
		{
			// TODO: Your test code here
			int arr[10] = { 1, 2, 3, 4, 5 };
			struct node *head = create_list(arr, 5);
			int k = 6;
			struct node *res = foo(k, head);
			int exp[100] = { 1,2,3,4,5};
			Assert::AreEqual(compare(res, exp, 5), 1);
		}
		TEST_METHOD(TestMethod4)
		{
			// TODO: Your test code here
			int arr[10] = { 1, 2, 3, 4, 5,6,7,8,9 };
			struct node *head = create_list(arr, 9);
			int k = 4;
			struct node *res = foo(k, head);
			int exp[100] = { 4,3,2,1,8,7,6,5,9 };
			Assert::AreEqual(compare(res, exp, 9), 1);
		}

		TEST_METHOD(TestMethod5)
		{
			// TODO: Your test code here
			int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			struct node *head = create_list(arr, 9);
			int k = 3;
			struct node *res = foo(k, head);
			int exp[100] = { 3,2,1,6,5,4,9,8,7 };
			Assert::AreEqual(compare(res, exp, 9), 1);
		}

		TEST_METHOD(TestMethod6)
		{
			// TODO: Your test code here
			struct node *res = foo(0, NULL);
			int exp[10] = {};
			Assert::AreEqual(compare(res,exp,0),1);
		}

		TEST_METHOD(TestMethod7)
		{
			// TODO: Your test code here
			int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			struct node *head = create_list(arr, 9);
			int k = 1;
			struct node *res = foo(k, head);
			int exp[100] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			Assert::AreEqual(compare(res, exp, 9), 1);
		}

		TEST_METHOD(TestMethod8)
		{
			// TODO: Your test code here
			int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			struct node *head = create_list(arr, 9);
			int k = 9;
			struct node *res = foo(k, head);
			int exp[100] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
			Assert::AreEqual(compare(res, exp, 9), 1);
		}

	};
}