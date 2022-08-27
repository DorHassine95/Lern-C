#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
////////one item//////////
typedef struct item {
	int data;
	struct item* next;
}Item;
typedef Item* list;

void Print_List(Item*);
Item* build_int_list_from_arr(int*,int);
Item* insert(int,Item*,list *);
void Delete(Item*,list*);
void FreeList(Item*);

void main() {
	int arr[7] = {23,4,7,11,29,45,3};
//,1,2,3,4,5 };
//	Item s,n,t;
//	s.data = 5;
//	s.next = &n;
//	n.data = 3;
//	n.next = &t;
//	t.data = 7;
//	t.next = NULL;
	Print_List(build_int_list_from_arr(&arr,7));

}
//////////////////Print list////////////////////
void Print_List(Item* lst) {
	Item* curr_point;
	curr_point = lst;
	printf("%d--->", lst->data);
	while (curr_point->next != NULL) {
		printf("%d--->", curr_point->next->data);
		curr_point = curr_point->next;
	}
	printf("NULL");
}

///////////////////////Build list form arr value/////////////////////
Item* build_int_list_from_arr(int* arr,int size) {
	Item* head, * curr_point;
	int i=1;
	if (!size) {
		return NULL;
	}
	head = (Item*)malloc(sizeof(Item));
	curr_point = head;
	head->data = arr[0];
	while (i<size) {
		curr_point->next = (Item*)malloc(sizeof(Item));
		curr_point = curr_point->next;
	    curr_point->data = arr[i];
		i++;
	}
	curr_point->next = NULL;
	return head;
}

////////////////add item after pos item//////////////
Item* insert(int x, Item* pos, list* lst) {
	Item* temp = (Item*)malloc(sizeof(Item));
	if (!temp) {
		return NULL;
	}
	temp->data = x;
	if (!(*lst) || !pos) {
		temp->next = *lst;
		*lst = temp;
	}
	else {
		temp->next = pos->next;
		pos->next = temp;
	}
	return lst;
}

/////////////////Delete item///////////////////
void Delete(Item* pos, list* slt) {
	Item* temp;
	if (!(*slt)) {
		return;
	}
	if (!pos) {
		temp = *slt;
		*slt = temp->next;
		free(temp);
	}
	else {
		if (pos->next) {
			temp = pos->next;
			pos->next = temp->next;
			free(temp);
		}
	}
}

/////////////////free list////////////
void FreeList(Item* head) {
	Item* to_free = head;
	while (to_free!= NULL) {
		head = head->next;
		free(to_free);
		to_free = head;
	}
}