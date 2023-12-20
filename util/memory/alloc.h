#ifndef CORE_ALLOC_H
#define CORE_ALLOC_H

#include "stdlib.h"

#define ALLOC(_type) (_type*)malloc(sizeof(_type))
#define REALLOC(_ptr, _type, _size) (_type*)realloc(_ptr, sizeof(_type) * (_size))
#define FREE(_ptr) free(_ptr)

#endif // CORE_ALLOC_H