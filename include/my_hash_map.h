#ifndef MY_HASH_MAP_H
#define MY_HASH_MAP_H

#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>

#define MAP_CAPACITY 101

typedef struct NodeHashMap{
	void* key;
	void* data;
	struct NodeHashMap* next;
} NodeHashMap;

typedef struct HashMap{
	size_t capacity;
	NodeHashMap** buckets;
} HashMap;

HashMap* my_hashmap();

#endif
