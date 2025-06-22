// internal_impl.c
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

// Decimal operations
int32_t internal_add(int32_t op1, int32_t op2) {
    return op1 + op2;
}

int32_t internal_sub(int32_t op1, int32_t op2) {
    return op1 - op2;
}

int32_t internal_mul(int32_t op1, int32_t op2) {
    return op1 * op2;
}

int32_t internal_div(int32_t op1, int32_t op2) {
    assert(op2 != 0); // runtime safety check
    return op1 / op2;
}

// Boolean bit operations
bool internal_and(bool op1, bool op2) {
    return op1 & op2;
}

bool internal_or(bool op1, bool op2) {
    return op1 | op2;
}

bool internal_xor(bool op1, bool op2) {
    return op1 ^ op2;
}

bool internal_not(bool op) {
    return !op;
}

// Bit shift operations
int32_t internal_lshift(int32_t op) {
    return op << 1;
}

int32_t internal_rshift(int32_t op) {
    return op >> 1;
}
