// internal_impl.h
#ifndef INTERNAL_IMPL_H
#define INTERNAL_IMPL_H

#include <stdint.h>
#include <stdbool.h>

// Decimal
int32_t internal_add(int32_t op1, int32_t op2);
int32_t internal_sub(int32_t op1, int32_t op2);
int32_t internal_mul(int32_t op1, int32_t op2);
int32_t internal_div(int32_t op1, int32_t op2);

// Bit logic
bool internal_and(bool op1, bool op2);
bool internal_or(bool op1, bool op2);
bool internal_xor(bool op1, bool op2);
bool internal_not(bool op);

// Bit shift
int32_t internal_lshift(int32_t op);
int32_t internal_rshift(int32_t op);

#endif
