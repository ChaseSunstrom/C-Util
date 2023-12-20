#include "iterator.h"
#include "collection.h"

#include "vector.h"


// ===============================================================================
// ITERATOR FUNCTIONS

 iterator* iterator_new(generic* collection)
{
	iterator* it = ALLOC(iterator);
	it->index = 0;
	it->state = ITERATOR_NONE;
	it->collection = collection;
	it->collection_size = COLLECTION_SIZE(collection);
	it->collection_data = COLLECTION_DATA(collection);
	return it;
}

 iterator_state iterator_iterate(iterator* it)
{
	it->state = iterator_next(it);
	it->state = iterator_end(it);

	return it->state;
}

// Used to iterate backwards from the end
 iterator_state iterator_b_iterate(iterator* it)
{
	if (it->index == 0)
		it->index = it->collection_size + 1;

	it->state = iterator_prev(it);
	it->state = iterator_begin(it);

	return it->state;
}

 iterator_state iterator_begin(iterator* it)
{
	if (it->index == 0)
		return ITERATOR_BEGIN;

	return ITERATOR_ITERATING;
}

 iterator_state iterator_next(iterator* it)
{
	if (iterator_end(it) == ITERATOR_END)
		return ITERATOR_END;

	it->index += 1;

	return ITERATOR_ITERATING;
}

 iterator_state iterator_prev(iterator* it)
{
	if (iterator_begin(it) == ITERATOR_BEGIN)
		return ITERATOR_BEGIN;

	it->index -= 1;

	return ITERATOR_ITERATING;
}

 iterator_state iterator_end(iterator* it)
{
	if (it->index > it->collection_size)
	{
		it->state = ITERATOR_END;
		return it->state;
	}

	return ITERATOR_ITERATING;
}

 generic iterator_get_prev(iterator* it)
{
	if (iterator_prev(it) == ITERATOR_ITERATING)
		return it->collection_data[it->index - 2];

	return NULL;
}

 generic iterator_get_next(iterator* it)
{
	if (iterator_next(it) == ITERATOR_ITERATING)
		return it->collection_data[it->index];

	return NULL;
}

 generic iterator_get_current_data(iterator* it)
{
	if (iterator_end(it) == ITERATOR_END)
		return NULL;
	
	return it->collection_data[it->index - 1];
}

 void iterator_update(iterator* it, void** collection)
{
	it->collection = collection;
	it->collection_size = COLLECTION_SIZE(collection);
	it->collection_data = COLLECTION_DATA(collection);
}

 void iterator_reset(iterator* it)
{
	it->index = 0;
}

 void iterator_free(iterator* it)
{
	FREE(it);
}

// ===============================================================================