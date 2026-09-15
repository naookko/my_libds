#include<stdlib.h>
#include<stdio.h>
#include"my_vector.h"

#define INITIAL_CAPACITY 4

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

void* front(Vector* vector){
	if(vector == NULL || vector->size == 0){
		printf("The vector is NULL or is empty\n");
		return NULL;
	}

	return vector->data[0];
}

void* back(Vector* vector){
	if(vector == NULL || vector->size == 0){
		printf("The vector is NULL or is empty\n");
		return NULL;
	}

	return vector->data[vector->size-1];
}

bool push_back(Vector* vector, void* element){
	if(vector == NULL){
		printf("The vector is NULL\n");
		return false;
	}
	
	if(vector->size == vector->capacity){
		void** temp = realloc(vector->data, (vector->size * 2) * sizeof(void*));
		if(temp == NULL){
			printf("Looks like there's no more space to expand the vector\n");
			return false;		
		}
		vector->data = temp;
		vector->capacity *= 2;
	}

	vector->data[vector->size++] = element;
	return true;
}
