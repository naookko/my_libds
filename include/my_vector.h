#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>

struct Vector{
	void **data;
	size_t capacity;
	size_t size;
} Vector;

Vector* my_vector();

#endif

