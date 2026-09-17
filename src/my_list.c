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

