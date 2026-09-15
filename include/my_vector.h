#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct Vector{
	void **data;
	size_t capacity;
	size_t size;
} Vector;

Vector* my_vector();
void* front(Vector* vector);
void* back(Vector* vector);

#endif

