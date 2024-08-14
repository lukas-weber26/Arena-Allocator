#include <stdio.h>
#include <stdlib.h>

typedef struct arena {
	void * data;
	int total_size; 
	int current_size; 
	void * current_loc;	
} arena;

void * arena_malloc(arena * arena, int size);
void arena_free(arena * arena);
arena * arena_create(int size);

void * arena_malloc(arena * arena, int size) {
	
	while (arena->current_size + size > arena->total_size) {
		arena->total_size *= 2;
		arena->data = realloc(arena->data,sizeof(char) * arena->total_size);
		arena->current_loc = arena->data + arena->current_size;
	} 

	void * return_pointer = arena->current_loc;
	arena ->current_size += size;
	arena ->current_loc += size;
	return return_pointer;
}

void arena_free(arena * arena) {
	free(arena->data);
	free(arena);
}

arena * arena_create(int size) {
	arena * new_arena = calloc(1,sizeof(arena));
	new_arena -> total_size = size;
	new_arena -> current_size = 0;
	new_arena -> data = calloc(size,sizeof(char));
	new_arena -> current_loc = new_arena -> data;
	return new_arena;
}

int main() {

}
