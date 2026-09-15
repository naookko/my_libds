#include<stdlib.h>
#include<stdio.h>
#include"vector.h"

#define INITIAL_CAPACITY = 4

Vector* my_vector(){
	Vector* newVector = malloc(sizeof(Vector));
	if(newVector == NULL){
		fprintf(stderr, "Error: couldn't initialize the vector\n");
		return NULL;
	}

	newVector->data = malloc(INITIAL_CAPACITY * sizeof(void*));
	if(newVector->data == NULL){
		free(newVector);
		fprintf(stderr, "Error: couldn't initialize the vector\n");
		return NULL;
	}

	newVector->capacity = INITIAL_CAPACITY;

	newVector->size = 0;

	return newVector;
}
