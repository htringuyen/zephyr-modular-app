#include <stdint.h>

#include <bitmath/bit_operations.h>
#include <internal/internal_impl.h>

int32_t bit_operations_lshift(int32_t op) {
    return internal_lshift(op) != 0;
}

int32_t bit_operations_rshift(int32_t op) {
    return internal_rshift(op) != 0;
}