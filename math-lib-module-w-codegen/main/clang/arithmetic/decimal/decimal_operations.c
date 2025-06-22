#include <stdint.h>
#include <arithmetic/decimal/decimal_operations.h>
#include <internal/internal_impl.h>

int32_t decimal_operations_add(int32_t op1, int32_t op2) {
    return internal_add(op1, op2);
}

int32_t decimal_operations_substract(int32_t op1, int32_t op2) {
    return internal_sub(op1, op2);
}

int32_t decimal_operations_multiply(int32_t op1, int32_t op2) {
    return internal_mul(op1, op2);
}

int32_t decimal_operations_divide(int32_t op1, int32_t op2) {
    return internal_div(op1, op2);
}

