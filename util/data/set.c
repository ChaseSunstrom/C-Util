#include "set.h"

 set* set_new()
{
	set* _set = ALLOC(set);
	_set->data = vector_new();
	_set->capacity = _set->data->capacity;
	_set->size = _set->data->size;
	return _set;
}

 void set_insert(set* _set, u64 index, generic data)
{
	for (u64 i = 0; i < _set->data->size; i++)
	{
		if (vector_get(_set->data, i) == data)
		{
			return;
		}
	}

	vector_insert(_set->data, index, data);
}

 void set_push(set* _set, generic data)
{
	for (u64 i = 0; i < _set->data->size; i++)
	{
		if (vector_get(_set->data, i) == data)
		{
			return;
		}
	}

	vector_push(_set->data, data);
}

 generic set_get(set* _set, u64 index)
{
	return vector_get(_set->data, index);
}

 void set_remove(set* _set, u64 index)
{
	vector_remove(_set->data, index);
}

 void set_free(set* _set)
{
	vector_free(_set->data);
	FREE(_set);
}