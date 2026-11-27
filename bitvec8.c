#include "stdio.h"
#include "bitvec8.h"

bitvec8 bitvec8_from_int(unsigned int x) {
  return 0xFF & x;
}

unsigned int bitvec8_to_int(bitvec8 v) {
  return v;
}

void bitvec8_print(bitvec8 v) {
  putchar('0' + ((v>>7) & 1));
  putchar('0' + ((v>>6) & 1));
  putchar('0' + ((v>>5) & 1));
  putchar('0' + ((v>>4) & 1));
  putchar('0' + ((v>>3) & 1));
  putchar('0' + ((v>>2) & 1));
  putchar('0' + ((v>>1) & 1));
  putchar('0' + (v & 1));
}

struct add_result {
    bitvec8 s;
    bitvec8 c;
};

struct add_result sum_and_carry(bitvec8 x, bitvec8 y) {
  struct add_result result;
  result.s = x ^ y;
  result.c = (x & y) << 1;
  return result;
}

// Add, and possibly truncate, two bitvec8 values
// into a bitvec8 value.
bitvec8 bitvec8_add(bitvec8 x, bitvec8 y) {
  struct add_result r = sum_and_carry(x, y);
  r = sum_and_carry(r.s, r.c);
  r = sum_and_carry(r.s, r.c);
  r = sum_and_carry(r.s, r.c);
  r = sum_and_carry(r.s, r.c);
  r = sum_and_carry(r.s, r.c);
  r = sum_and_carry(r.s, r.c);
  r = sum_and_carry(r.s, r.c);
  return r.s;
}

// Return the negation of a bitvec8, as a bitvec8.
bitvec8 bitvec8_negate(bitvec8 x) {
  return bitvec8_add(~x,1);
}


bool bitvec8_get(bitvec8 v, int i) {
  return ((v>>i) & 1);
}

// Multiply, and possibly truncate, two bitvec8 values
// into a bitvec8 value. 

bitvec8 bitvec8_mul(bitvec8 x, bitvec8 y) {
    bitvec8 z = x & bitvec8_negate(bitvec8_get(y, 0));
    z = bitvec8_add(
        (x << 1) & bitvec8_negate(bitvec8_get(y, 1)), z);
    z = bitvec8_add(
        (x << 2) & bitvec8_negate(bitvec8_get(y, 2)), z);
    z = bitvec8_add(
        (x << 3) & bitvec8_negate(bitvec8_get(y, 3)), z);
    z = bitvec8_add(
        (x << 4) & bitvec8_negate(bitvec8_get(y, 4)), z);
    z = bitvec8_add(
        (x << 5) & bitvec8_negate(bitvec8_get(y, 5)), z);
    z = bitvec8_add(
        (x << 6) & bitvec8_negate(bitvec8_get(y, 6)), z);
    z = bitvec8_add(
        (x << 7) & bitvec8_negate(bitvec8_get(y, 7)), z);
    return z;
}
