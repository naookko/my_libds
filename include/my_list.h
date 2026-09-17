#ifndef MY_LIST_H
#define MY_LIST_H

#include<stdlib.h>
#include<stddef.h>

typedef struct Node{
	void* data;
	struct Node* next;	
} Node;

Node* my_list();
void traverse(Node* list);

#endif
