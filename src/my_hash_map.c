#include<stdlib.h>
#include<stdio.h>
#include"my_hash_map.h"

#define MAP_CAPACITY 101

HashMap* my_hashmap(){
	HashMap* newHashMap = malloc(sizeof(HashMap));
	
	if(newHashMap == NULL){
		printf("Couldn't allocate memory for the HashMap\n");
		return NULL;
	}

	newHashMap->capacity = MAP_CAPACITY;
	newHashMap->buckets = calloc(MAP_CAPACITY, sizeof(HashMap*));

	if(newHashMap->buckets == NULL){
		free(newHashMap);
		printf("Couldnt't allocate memory for the HashMap's bucckets\n");
		return NULL;
	}

	printf("New HashMap created successfully\n");

	return newHashMap;
}

size_t my_hash_function(const void* data){
	const char* str = (const char*)data;
	size_t hash = 5381;
	int c;
	while((c = *str++)){
		hash = ((hash << 5) + hash) + c;
	}
	return hash % MAP_CAPACITY;
}
