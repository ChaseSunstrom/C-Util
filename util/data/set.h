#ifndef CORE_SET_H
#define CORE_SET_H

#include "vector.h"

 typedef struct
{
	u64 size;
	u64 capacity;
	vector* data;
} set;

 set* set_new();
 void set_insert(set* set, u64 index, generic data);
 void set_push(set* set, generic data);
 void set_remove(set* set, u64 index);
 generic    set_get(set* set, u64 index);
 void set_free(set* set);


#endif // CORE_SET_H