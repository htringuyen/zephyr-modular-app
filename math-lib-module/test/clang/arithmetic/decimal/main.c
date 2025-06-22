/*
 * Unit tests for decimal_operations.h using ztest framework
 */

#include <zephyr/ztest.h>
#include <limits.h>
#include <arithmetic/decimal/decimal_operations.h>

/* Test suite for decimal_operations_add */
ZTEST_SUITE(decimal_add, NULL, NULL, NULL, NULL, NULL);

ZTEST(decimal_add, test_add_positive_numbers)
{
    zassert_equal(decimal_operations_add(5, 3), 8, "5 + 3 should equal 8");
    zassert_equal(decimal_operations_add(10, 20), 30, "10 + 20 should equal 30");
    zassert_equal(decimal_operations_add(100, 200), 300, "100 + 200 should equal 300");
    zassert_equal(decimal_operations_add(1, 1), 2, "1 + 1 should equal 2");
}

ZTEST(decimal_add, test_add_negative_numbers)
{
    zassert_equal(decimal_operations_add(-5, -3), -8, "-5 + (-3) should equal -8");
    zassert_equal(decimal_operations_add(-10, -20), -30, "-10 + (-20) should equal -30");
    zassert_equal(decimal_operations_add(-1, -1), -2, "-1 + (-1) should equal -2");
}

ZTEST(decimal_add, test_add_mixed_signs)
{
    zassert_equal(decimal_operations_add(-5, 10), 5, "-5 + 10 should equal 5");
    zassert_equal(decimal_operations_add(15, -10), 5, "15 + (-10) should equal 5");
    zassert_equal(decimal_operations_add(-20, 15), -5, "-20 + 15 should equal -5");
    zassert_equal(decimal_operations_add(20, -25), -5, "20 + (-25) should equal -5");
}

ZTEST(decimal_add, test_add_with_zero)
{
    zassert_equal(decimal_operations_add(0, 0), 0, "0 + 0 should equal 0");
    zassert_equal(decimal_operations_add(42, 0), 42, "42 + 0 should equal 42");
    zassert_equal(decimal_operations_add(0, -42), -42, "0 + (-42) should equal -42");
    zassert_equal(decimal_operations_add(-100, 0), -100, "-100 + 0 should equal -100");
}

ZTEST(decimal_add, test_add_boundary_values)
{
    zassert_equal(decimal_operations_add(INT32_MAX - 1, 1), INT32_MAX, "Should handle near-max values");
    zassert_equal(decimal_operations_add(INT32_MIN + 1, -1), INT32_MIN, "Should handle near-min values");
    zassert_equal(decimal_operations_add(0, INT32_MAX), INT32_MAX, "0 + INT32_MAX should work");
    zassert_equal(decimal_operations_add(INT32_MIN, 0), INT32_MIN, "INT32_MIN + 0 should work");
}

/* Test suite for decimal_operations_substract */
ZTEST_SUITE(decimal_subtract, NULL, NULL, NULL, NULL, NULL);

ZTEST(decimal_subtract, test_subtract_positive_numbers)
{
    zassert_equal(decimal_operations_substract(10, 3), 7, "10 - 3 should equal 7");
    zassert_equal(decimal_operations_substract(50, 20), 30, "50 - 20 should equal 30");
    zassert_equal(decimal_operations_substract(100, 25), 75, "100 - 25 should equal 75");
    zassert_equal(decimal_operations_substract(5, 5), 0, "5 - 5 should equal 0");
}

ZTEST(decimal_subtract, test_subtract_negative_numbers)
{
    zassert_equal(decimal_operations_substract(-10, -3), -7, "-10 - (-3) should equal -7");
    zassert_equal(decimal_operations_substract(-5, -10), 5, "-5 - (-10) should equal 5");
    zassert_equal(decimal_operations_substract(-20, -20), 0, "-20 - (-20) should equal 0");
}

ZTEST(decimal_subtract, test_subtract_mixed_signs)
{
    zassert_equal(decimal_operations_substract(10, -5), 15, "10 - (-5) should equal 15");
    zassert_equal(decimal_operations_substract(-10, 5), -15, "-10 - 5 should equal -15");
    zassert_equal(decimal_operations_substract(-10, -5), -5, "-10 - (-5) should equal -5");
    zassert_equal(decimal_operations_substract(0, -10), 10, "0 - (-10) should equal 10");
}

ZTEST(decimal_subtract, test_subtract_with_zero)
{
    zassert_equal(decimal_operations_substract(0, 0), 0, "0 - 0 should equal 0");
    zassert_equal(decimal_operations_substract(42, 0), 42, "42 - 0 should equal 42");
    zassert_equal(decimal_operations_substract(0, 42), -42, "0 - 42 should equal -42");
    zassert_equal(decimal_operations_substract(-100, 0), -100, "-100 - 0 should equal -100");
}

ZTEST(decimal_subtract, test_subtract_boundary_values)
{
    zassert_equal(decimal_operations_substract(INT32_MAX, 0), INT32_MAX, "INT32_MAX - 0 should work");
    zassert_equal(decimal_operations_substract(INT32_MIN, 0), INT32_MIN, "INT32_MIN - 0 should work");
    zassert_equal(decimal_operations_substract(0, INT32_MIN), -INT32_MIN, "0 - INT32_MIN should work");
    zassert_equal(decimal_operations_substract(INT32_MAX, INT32_MAX), 0, "MAX - MAX should equal 0");
}

/* Test suite for decimal_operations_multiply */
ZTEST_SUITE(decimal_multiply, NULL, NULL, NULL, NULL, NULL);

ZTEST(decimal_multiply, test_multiply_positive_numbers)
{
    zassert_equal(decimal_operations_multiply(5, 3), 15, "5 * 3 should equal 15");
    zassert_equal(decimal_operations_multiply(7, 8), 56, "7 * 8 should equal 56");
    zassert_equal(decimal_operations_multiply(10, 10), 100, "10 * 10 should equal 100");
    zassert_equal(decimal_operations_multiply(12, 12), 144, "12 * 12 should equal 144");
}

ZTEST(decimal_multiply, test_multiply_negative_numbers)
{
    zassert_equal(decimal_operations_multiply(-5, -3), 15, "-5 * (-3) should equal 15");
    zassert_equal(decimal_operations_multiply(-7, -8), 56, "-7 * (-8) should equal 56");
    zassert_equal(decimal_operations_multiply(-10, -10), 100, "-10 * (-10) should equal 100");
}

ZTEST(decimal_multiply, test_multiply_mixed_signs)
{
    zassert_equal(decimal_operations_multiply(-5, 3), -15, "-5 * 3 should equal -15");
    zassert_equal(decimal_operations_multiply(5, -3), -15, "5 * (-3) should equal -15");
    zassert_equal(decimal_operations_multiply(-7, 8), -56, "-7 * 8 should equal -56");
    zassert_equal(decimal_operations_multiply(7, -8), -56, "7 * (-8) should equal -56");
}

ZTEST(decimal_multiply, test_multiply_with_zero)
{
    zassert_equal(decimal_operations_multiply(0, 0), 0, "0 * 0 should equal 0");
    zassert_equal(decimal_operations_multiply(42, 0), 0, "42 * 0 should equal 0");
    zassert_equal(decimal_operations_multiply(0, 42), 0, "0 * 42 should equal 0");
    zassert_equal(decimal_operations_multiply(-100, 0), 0, "-100 * 0 should equal 0");
    zassert_equal(decimal_operations_multiply(0, -100), 0, "0 * (-100) should equal 0");
}

ZTEST(decimal_multiply, test_multiply_with_one)
{
    zassert_equal(decimal_operations_multiply(1, 1), 1, "1 * 1 should equal 1");
    zassert_equal(decimal_operations_multiply(42, 1), 42, "42 * 1 should equal 42");
    zassert_equal(decimal_operations_multiply(1, 42), 42, "1 * 42 should equal 42");
    zassert_equal(decimal_operations_multiply(-100, 1), -100, "-100 * 1 should equal -100");
    zassert_equal(decimal_operations_multiply(1, -100), -100, "1 * (-100) should equal -100");
}

ZTEST(decimal_multiply, test_multiply_powers_of_two)
{
    zassert_equal(decimal_operations_multiply(2, 2), 4, "2 * 2 should equal 4");
    zassert_equal(decimal_operations_multiply(4, 4), 16, "4 * 4 should equal 16");
    zassert_equal(decimal_operations_multiply(8, 8), 64, "8 * 8 should equal 64");
    zassert_equal(decimal_operations_multiply(16, 2), 32, "16 * 2 should equal 32");
}

/* Test suite for decimal_operations_divide */
ZTEST_SUITE(decimal_divide, NULL, NULL, NULL, NULL, NULL);

ZTEST(decimal_divide, test_divide_positive_numbers)
{
    zassert_equal(decimal_operations_divide(15, 3), 5, "15 / 3 should equal 5");
    zassert_equal(decimal_operations_divide(56, 8), 7, "56 / 8 should equal 7");
    zassert_equal(decimal_operations_divide(100, 10), 10, "100 / 10 should equal 10");
    zassert_equal(decimal_operations_divide(144, 12), 12, "144 / 12 should equal 12");
}

ZTEST(decimal_divide, test_divide_negative_numbers)
{
    zassert_equal(decimal_operations_divide(-15, -3), 5, "-15 / (-3) should equal 5");
    zassert_equal(decimal_operations_divide(-56, -8), 7, "-56 / (-8) should equal 7");
    zassert_equal(decimal_operations_divide(-100, -10), 10, "-100 / (-10) should equal 10");
}

ZTEST(decimal_divide, test_divide_mixed_signs)
{
    zassert_equal(decimal_operations_divide(-15, 3), -5, "-15 / 3 should equal -5");
    zassert_equal(decimal_operations_divide(15, -3), -5, "15 / (-3) should equal -5");
    zassert_equal(decimal_operations_divide(-56, 8), -7, "-56 / 8 should equal -7");
    zassert_equal(decimal_operations_divide(56, -8), -7, "56 / (-8) should equal -7");
}

ZTEST(decimal_divide, test_divide_by_one)
{
    zassert_equal(decimal_operations_divide(42, 1), 42, "42 / 1 should equal 42");
    zassert_equal(decimal_operations_divide(-42, 1), -42, "-42 / 1 should equal -42");
    zassert_equal(decimal_operations_divide(0, 1), 0, "0 / 1 should equal 0");
    zassert_equal(decimal_operations_divide(INT32_MAX, 1), INT32_MAX, "INT32_MAX / 1 should equal INT32_MAX");
}

ZTEST(decimal_divide, test_divide_zero_dividend)
{
    zassert_equal(decimal_operations_divide(0, 5), 0, "0 / 5 should equal 0");
    zassert_equal(decimal_operations_divide(0, -5), 0, "0 / (-5) should equal 0");
    zassert_equal(decimal_operations_divide(0, 100), 0, "0 / 100 should equal 0");
    zassert_equal(decimal_operations_divide(0, -100), 0, "0 / (-100) should equal 0");
}

ZTEST(decimal_divide, test_divide_truncation)
{
    zassert_equal(decimal_operations_divide(7, 3), 2, "7 / 3 should equal 2 (truncated)");
    zassert_equal(decimal_operations_divide(10, 3), 3, "10 / 3 should equal 3 (truncated)");
    zassert_equal(decimal_operations_divide(22, 7), 3, "22 / 7 should equal 3 (truncated)");
    zassert_equal(decimal_operations_divide(-7, 3), -2, "-7 / 3 should equal -2 (truncated)");
    zassert_equal(decimal_operations_divide(7, -3), -2, "7 / (-3) should equal -2 (truncated)");
}

ZTEST(decimal_divide, test_divide_boundary_values)
{
    zassert_equal(decimal_operations_divide(INT32_MAX, INT32_MAX), 1, "INT32_MAX / INT32_MAX should equal 1");
    zassert_equal(decimal_operations_divide(INT32_MIN, INT32_MIN), 1, "INT32_MIN / INT32_MIN should equal 1");
    zassert_equal(decimal_operations_divide(INT32_MAX, -1), -INT32_MAX, "INT32_MAX / (-1) should equal -INT32_MAX");
    zassert_equal(decimal_operations_divide(0, INT32_MAX), 0, "0 / INT32_MAX should equal 0");
}

/* Test suite for combined operations and edge cases */
ZTEST_SUITE(decimal_combined, NULL, NULL, NULL, NULL, NULL);

ZTEST(decimal_combined, test_combined_operations)
{
    /* Test combinations: (a + b) * c / d - e */
    int32_t step1 = decimal_operations_add(10, 5);     /* 15 */
    int32_t step2 = decimal_operations_multiply(step1, 4); /* 60 */
    int32_t step3 = decimal_operations_divide(step2, 3);   /* 20 */
    int32_t result = decimal_operations_substract(step3, 8); /* 12 */
    zassert_equal(result, 12, "((10+5)*4)/3-8 should equal 12");
}

ZTEST(decimal_combined, test_commutative_properties)
{
    /* Addition commutative: a + b = b + a */
    zassert_equal(decimal_operations_add(5, 7), decimal_operations_add(7, 5), 
                  "Addition should be commutative");
    
    /* Multiplication commutative: a * b = b * a */
    zassert_equal(decimal_operations_multiply(6, 9), decimal_operations_multiply(9, 6), 
                  "Multiplication should be commutative");
}

ZTEST(decimal_combined, test_associative_properties)
{
    /* Addition associative: (a + b) + c = a + (b + c) */
    int32_t left = decimal_operations_add(decimal_operations_add(3, 4), 5);
    int32_t right = decimal_operations_add(3, decimal_operations_add(4, 5));
    zassert_equal(left, right, "Addition should be associative");
    
    /* Multiplication associative: (a * b) * c = a * (b * c) */
    left = decimal_operations_multiply(decimal_operations_multiply(2, 3), 4);
    right = decimal_operations_multiply(2, decimal_operations_multiply(3, 4));
    zassert_equal(left, right, "Multiplication should be associative");
}

ZTEST(decimal_combined, test_identity_elements)
{
    /* Addition identity: a + 0 = a */
    zassert_equal(decimal_operations_add(42, 0), 42, "Addition identity test");
    
    /* Multiplication identity: a * 1 = a */
    zassert_equal(decimal_operations_multiply(42, 1), 42, "Multiplication identity test");
    
    /* Division identity: a / 1 = a */
    zassert_equal(decimal_operations_divide(42, 1), 42, "Division identity test");
}

ZTEST(decimal_combined, test_inverse_operations)
{
    /* Addition and subtraction are inverse: (a + b) - b = a */
    int32_t original = 42;
    int32_t added = decimal_operations_add(original, 17);
    int32_t result = decimal_operations_substract(added, 17);
    zassert_equal(result, original, "Addition and subtraction should be inverse");
    
    /* Multiplication and division are inverse: (a * b) / b = a */
    original = 15;
    int32_t multiplied = decimal_operations_multiply(original, 7);
    result = decimal_operations_divide(multiplied, 7);
    zassert_equal(result, original, "Multiplication and division should be inverse");
}

ZTEST(decimal_combined, test_distributive_property)
{
    /* Distributive: a * (b + c) = (a * b) + (a * c) */
    int32_t a = 5, b = 3, c = 7;
    int32_t left_side = decimal_operations_multiply(a, decimal_operations_add(b, c));
    int32_t right_side = decimal_operations_add(decimal_operations_multiply(a, b), 
                                                decimal_operations_multiply(a, c));
    zassert_equal(left_side, right_side, "Multiplication should distribute over addition");
}