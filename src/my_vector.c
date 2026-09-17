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

bool insert(Vector* vector, void* element, size_t index){
	if(vector == NULL){
		printf("The vector is NULL\n");
		return false;
	}

	if(index > vector->size){
		printf("Index out of bounds\n");
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

	for(size_t i = vector->size; i > index; i--){
		vector->data[i] = vector->data[i-1];
	}

	vector->data[index] = element;

	vector->size++;

	return true;
}

bool erase(Vector* vector, size_t index){
	if(vector == NULL){
		printf("The vector is NULL\n");
		return false;
	}

	if(index >= vector->size){
		printf("Index out of bounds\n");
		return false;
	}

	for(size_t i = index; i < vector->size-1; i++){
		vector->data[i] = vector->data[i+1];
	}

	vector->size--;
	
	vector->data[vector->size] = NULL;

	return true;
}

bool pop_back(Vector* vector){
	if(vector == NULL){
		printf("The vector is NULL\n");
		return false;
	}
	if(vector->size == 0){
		printf("The vector is empty");
		return false;
	}

	vector->data[--vector->size] = NULL;

	return true;
}
