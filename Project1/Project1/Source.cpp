#include <cstddef>
#include "stdio.h"
struct doubly_linked_list_node
{
	doubly_linked_list_node* next = NULL;
	doubly_linked_list_node* prev = NULL;
	int value = 0;
};

struct doubly_linked_list
{
	doubly_linked_list_node* front = NULL;
	doubly_linked_list_node* back = NULL;

	void addFront(int value)
	{
		doubly_linked_list_node* a = new doubly_linked_list_node;
		 a->value = value;
		 if (front == NULL){

			 front = a;
			 back = a;
		
		 } else {
			 a->prev = front;
			 front->next = a;
			 front = a;				 
		 }
	}

	void addBack(int value)
	{
		doubly_linked_list_node* a = new doubly_linked_list_node;
		a->value = value;
		if (back == NULL) {

			front = a;
			back = a;

		}
		else {
			a->next = back;
			front->prev = a;
			back = a;
		}
	}

	void delFront()
	{
		if (back) {
			if (front->prev != NULL)
			{
				if (front != NULL) {
					doubly_linked_list_node* tmp = front->prev;
					tmp->next = NULL;

					delete front;
					front = tmp;

				}
			}
			else {
				delete back;
				front = NULL;
				back = NULL;
			}
		}		
	}

	void delBack()
	{
		if (back) {
			if (front->prev != NULL)
			{
				if (back != NULL) {
					doubly_linked_list_node* tmp = back->next;
					tmp->prev = NULL;

					delete back;
					back = tmp;
				}
			}
			else {
				delete back;
				front = NULL;
				back = NULL;
			}
		}
	}
};


struct singly_linked_list_node
{
	singly_linked_list_node* next = NULL;
	int value = 0;
};

struct singly_linked_list
{
	singly_linked_list_node* front = NULL;
	singly_linked_list_node* back = NULL;

	void addFront(int value)
	{
		singly_linked_list_node* a = new singly_linked_list_node;
		a->value = value;
		if (front == NULL) {

			front = a;
			back = a;

		}
		else {
			front->next = a;
			front = a;
		}
	}

	void addBack(int value)
	{
		singly_linked_list_node* a = new singly_linked_list_node;

		a->value = value;
		if (back == NULL) {

			front = a;
			back = a;

		}
		else {
			a->next = back;
			back = a;
		}
	}

	void delFront()
	{
		if (front) {
			
			singly_linked_list_node* tmp = back;

			while (tmp->next != front)
			{
				tmp = tmp->next;
			}

			delete front;
			front = tmp;
			front->next = NULL;
			
		}
	}

	void delBack()
	{
		if (back) {

			singly_linked_list_node* a = back->next;
			
			delete back;

			back = a;

		}
	}
};

int main()
{
	singly_linked_list a;

	singly_linked_list_node* tmp;
	
	a.addFront(1);
	a.addFront(2);
	a.addFront(3);
	a.addBack(4);
		
	a.delFront();

	tmp = a.back;

	while (tmp != NULL)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	} 

	return 0;
}