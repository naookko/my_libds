#ifndef MY_LIST_H
#define MY_LIST_H

#include<stdlib.h>
#include<stddef.h>

typedef struct Node{
	void* data;
	struct Node* next;	
} Node;

Node* my_list();
void traverse_list(Node* list);
void insert_list(Node** list, void* element);
void delete_list(Node** list, void* element);

#endif
