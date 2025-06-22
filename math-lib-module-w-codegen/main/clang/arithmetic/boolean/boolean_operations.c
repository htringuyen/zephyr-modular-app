#include <stdbool.h>
#include <arithmetic/boolean/boolean_operations.h>

bool boolean_operations_and(bool op1, bool op2) {
    return op1 & op2;
}

bool boolean_operations_or(bool op1, bool op2) {
    return op1 | op2;
}

bool boolean_operations_xor(bool op1, bool op2) {
    return op1 ^ op2;
}

bool boolean_operations_not(bool op) {
    return !op;
}
