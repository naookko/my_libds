#include<stdlib.h>
#include<stdio.h>
#include"my_list.h"

Node* my_list(){ //Looks like it's better to initialize the list as a NULL pointer instead of reserving memory for an empty list
	Node* new_list = (Node*)malloc(sizeof(Node));

	if(new_list == NULL){
		printf("Error: couldn't create a new list.\n");
		return NULL;
	}

	new_list->data = NULL;
	new_list->next = NULL;

	return new_list;
}

void traverse_list(Node* list){
	if(list == NULL){
		printf("Error: the list is NULL\n");
		return;
	}

	Node* aux = list;	

	while(aux != NULL){
		printf("> %s\n", (char*)aux->data); //Currently just accept strings. But it can change to receive a callback and print different kind of data.
		aux = aux->next;
	}
}

void insert_list(Node** list, void* element){
	if(list == NULL){
		printf("Error: the list is NULL\n");
		return;
	}

	Node* newNode = (Node*)malloc(sizeof(Node));
	
	if(newNode == NULL){
		printf("Error: couldn't create a new node.\n");
		return;
	}
	
	newNode->data = element;

	newNode->next = NULL;


	if(*list == NULL){
		*list = newNode;
		return;
	}

	Node* aux = *list;
	while(aux->next != NULL){
		aux = aux->next;
	}

	aux->next = newNode;

	return;
}
