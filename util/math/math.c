#include "math.h"

inline f64 clamp(f64 val, f64 minval, f64 maxval)
{
	return min(max(val, minval), maxval);
}