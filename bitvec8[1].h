#include "stdint.h"
#include "stdbool.h"

typedef uint8_t bitvec8;

bitvec8 bitvec8_add(bitvec8 x, bitvec8 y);
struct bitvec8 bitvec8_negate(struct bitvec8 x);
bitvec8 bitvec8_mul(bitvec8 x, bitvec8 y);