#include<stdlib.h>
#include<stdio.h>
#include<string.h>
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

void put(HashMap* map, void* key, void* data){
	if(map == NULL || key == NULL || data == NULL){
		printf("Couldn't save the data");
		return;
	}
	
	size_t index = my_hash_function(key);

	NodeHashMap* aux = map->buckets[index];
	
	while(aux != NULL){
		if(strcmp((const char*) aux->key, (const char*)key) == 0){
			aux->data = data;
			return;
		}
		aux = aux->next;
	}

	NodeHashMap* newNode = (NodeHashMap*)malloc(sizeof(NodeHashMap));

	if(newNode == NULL){
		printf("Couldn't create the new entry on the map");
		return;
	}

	newNode->key = key;
	newNode->data = data;

	newNode->next = map->buckets[index];
	map->buckets[index] = newNode;
}
