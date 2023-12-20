#ifndef CORE_MAP_H
#define CORE_MAP_H
#include "vector.h"

typedef struct
{
	generic key;
	generic value;
} pair;

typedef struct
{
	u64 size;
	u64 capacity;
	struct_vec pairs;
} map;

bool pair_compare(pair* a, generic key);

map* map_new();
void    map_insert(map* map, generic key, generic value);
void    map_remove(map* map, generic key);
generic map_get(map* map, generic key);


#endif