#include<stdlib.h>
#include<stdio.h>
#include"my_list.h"

Node* my_list(){
	Node* new_list = (Node*)malloc(sizeof(Node));

	if(new_list == NULL){
		printf("Error: couldn't create a new list.\n");
		return NULL;
	}

	new_list->data = NULL;
	new_list->next = NULL;

	return new_list;
}

void traverse(Node* list){
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
