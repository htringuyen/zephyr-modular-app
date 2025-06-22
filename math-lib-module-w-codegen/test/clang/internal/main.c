/*
 * Unit tests for internal_impl.h using ztest framework
 */

#include <zephyr/ztest.h>
#include <internal/internal_impl.h>

/* Test suite for decimal arithmetic operations */
ZTEST_SUITE(decimal_ops, NULL, NULL, NULL, NULL, NULL);

ZTEST(decimal_ops, test_internal_add_positive)
{
    zassert_equal(internal_add(5, 3), 8, "5 + 3 should equal 8");
    zassert_equal(internal_add(100, 200), 300, "100 + 200 should equal 300");
    zassert_equal(internal_add(0, 42), 42, "0 + 42 should equal 42");
}

ZTEST(decimal_ops, test_internal_add_negative)
{
    zassert_equal(internal_add(-5, -3), -8, "-5 + (-3) should equal -8");
    zassert_equal(internal_add(-10, 15), 5, "-10 + 15 should equal 5");
    zassert_equal(internal_add(10, -15), -5, "10 + (-15) should equal -5");
}

ZTEST(decimal_ops, test_internal_add_overflow)
{
    /* Test near INT32_MAX boundary */
    zassert_equal(internal_add(INT32_MAX - 1, 1), INT32_MAX, "Should handle near-max values");
    zassert_equal(internal_add(0, INT32_MAX), INT32_MAX, "Adding zero to max should work");
}

ZTEST(decimal_ops, test_internal_sub_positive)
{
    zassert_equal(internal_sub(10, 3), 7, "10 - 3 should equal 7");
    zassert_equal(internal_sub(100, 50), 50, "100 - 50 should equal 50");
    zassert_equal(internal_sub(42, 0), 42, "42 - 0 should equal 42");
}

ZTEST(decimal_ops, test_internal_sub_negative)
{
    zassert_equal(internal_sub(-5, -3), -2, "-5 - (-3) should equal -2");
    zassert_equal(internal_sub(-10, 5), -15, "-10 - 5 should equal -15");
    zassert_equal(internal_sub(5, 10), -5, "5 - 10 should equal -5");
}

ZTEST(decimal_ops, test_internal_sub_underflow)
{
    /* Test near INT32_MIN boundary */
    zassert_equal(internal_sub(INT32_MIN + 1, 1), INT32_MIN, "Should handle near-min values");
    zassert_equal(internal_sub(0, -INT32_MAX), INT32_MAX, "0 - (-INT32_MAX) should work");
}

ZTEST(decimal_ops, test_internal_mul_positive)
{
    zassert_equal(internal_mul(5, 3), 15, "5 * 3 should equal 15");
    zassert_equal(internal_mul(7, 8), 56, "7 * 8 should equal 56");
    zassert_equal(internal_mul(1, 42), 42, "1 * 42 should equal 42");
}

ZTEST(decimal_ops, test_internal_mul_with_zero)
{
    zassert_equal(internal_mul(0, 100), 0, "0 * 100 should equal 0");
    zassert_equal(internal_mul(100, 0), 0, "100 * 0 should equal 0");
    zassert_equal(internal_mul(0, 0), 0, "0 * 0 should equal 0");
}

ZTEST(decimal_ops, test_internal_mul_negative)
{
    zassert_equal(internal_mul(-5, 3), -15, "-5 * 3 should equal -15");
    zassert_equal(internal_mul(5, -3), -15, "5 * (-3) should equal -15");
    zassert_equal(internal_mul(-5, -3), 15, "-5 * (-3) should equal 15");
}

ZTEST(decimal_ops, test_internal_div_positive)
{
    zassert_equal(internal_div(15, 3), 5, "15 / 3 should equal 5");
    zassert_equal(internal_div(100, 10), 10, "100 / 10 should equal 10");
    zassert_equal(internal_div(42, 1), 42, "42 / 1 should equal 42");
}

ZTEST(decimal_ops, test_internal_div_negative)
{
    zassert_equal(internal_div(-15, 3), -5, "-15 / 3 should equal -5");
    zassert_equal(internal_div(15, -3), -5, "15 / (-3) should equal -5");
    zassert_equal(internal_div(-15, -3), 5, "-15 / (-3) should equal 5");
}

ZTEST(decimal_ops, test_internal_div_truncation)
{
    zassert_equal(internal_div(7, 3), 2, "7 / 3 should equal 2 (truncated)");
    zassert_equal(internal_div(-7, 3), -2, "-7 / 3 should equal -2 (truncated)");
    zassert_equal(internal_div(10, 3), 3, "10 / 3 should equal 3 (truncated)");
}

/* Test suite for boolean bit operations */
ZTEST_SUITE(boolean_ops, NULL, NULL, NULL, NULL, NULL);

ZTEST(boolean_ops, test_internal_and_true_cases)
{
    zassert_true(internal_and(true, true), "true AND true should be true");
    zassert_false(internal_and(true, false), "true AND false should be false");
    zassert_false(internal_and(false, true), "false AND true should be false");
    zassert_false(internal_and(false, false), "false AND false should be false");
}

ZTEST(boolean_ops, test_internal_or_cases)
{
    zassert_true(internal_or(true, true), "true OR true should be true");
    zassert_true(internal_or(true, false), "true OR false should be true");
    zassert_true(internal_or(false, true), "false OR true should be true");
    zassert_false(internal_or(false, false), "false OR false should be false");
}

ZTEST(boolean_ops, test_internal_xor_cases)
{
    zassert_false(internal_xor(true, true), "true XOR true should be false");
    zassert_true(internal_xor(true, false), "true XOR false should be true");
    zassert_true(internal_xor(false, true), "false XOR true should be true");
    zassert_false(internal_xor(false, false), "false XOR false should be false");
}

ZTEST(boolean_ops, test_internal_not_cases)
{
    zassert_false(internal_not(true), "NOT true should be false");
    zassert_true(internal_not(false), "NOT false should be true");
}

/* Test suite for bit shift operations */
ZTEST_SUITE(bitshift_ops, NULL, NULL, NULL, NULL, NULL);

ZTEST(bitshift_ops, test_internal_lshift_positive)
{
    zassert_equal(internal_lshift(1), 2, "1 << 1 should equal 2");
    zassert_equal(internal_lshift(5), 10, "5 << 1 should equal 10");
    zassert_equal(internal_lshift(100), 200, "100 << 1 should equal 200");
    zassert_equal(internal_lshift(0), 0, "0 << 1 should equal 0");
}

ZTEST(bitshift_ops, test_internal_lshift_negative)
{
    zassert_equal(internal_lshift(-1), -2, "-1 << 1 should equal -2");
    zassert_equal(internal_lshift(-5), -10, "-5 << 1 should equal -10");
    zassert_equal(internal_lshift(-100), -200, "-100 << 1 should equal -200");
}

ZTEST(bitshift_ops, test_internal_lshift_powers_of_two)
{
    zassert_equal(internal_lshift(2), 4, "2 << 1 should equal 4");
    zassert_equal(internal_lshift(4), 8, "4 << 1 should equal 8");
    zassert_equal(internal_lshift(8), 16, "8 << 1 should equal 16");
    zassert_equal(internal_lshift(16), 32, "16 << 1 should equal 32");
}

ZTEST(bitshift_ops, test_internal_rshift_positive)
{
    zassert_equal(internal_rshift(2), 1, "2 >> 1 should equal 1");
    zassert_equal(internal_rshift(10), 5, "10 >> 1 should equal 5");
    zassert_equal(internal_rshift(200), 100, "200 >> 1 should equal 100");
    zassert_equal(internal_rshift(0), 0, "0 >> 1 should equal 0");
}

ZTEST(bitshift_ops, test_internal_rshift_negative)
{
    /* Note: Right shift of negative numbers is implementation-defined */
    zassert_equal(internal_rshift(-2), -1, "-2 >> 1 should equal -1");
    zassert_equal(internal_rshift(-10), -5, "-10 >> 1 should equal -5");
    zassert_equal(internal_rshift(-200), -100, "-200 >> 1 should equal -100");
}

ZTEST(bitshift_ops, test_internal_rshift_odd_numbers)
{
    zassert_equal(internal_rshift(1), 0, "1 >> 1 should equal 0");
    zassert_equal(internal_rshift(3), 1, "3 >> 1 should equal 1");
    zassert_equal(internal_rshift(7), 3, "7 >> 1 should equal 3");
    zassert_equal(internal_rshift(15), 7, "15 >> 1 should equal 7");
}

ZTEST(bitshift_ops, test_internal_rshift_powers_of_two)
{
    zassert_equal(internal_rshift(32), 16, "32 >> 1 should equal 16");
    zassert_equal(internal_rshift(16), 8, "16 >> 1 should equal 8");
    zassert_equal(internal_rshift(8), 4, "8 >> 1 should equal 4");
    zassert_equal(internal_rshift(4), 2, "4 >> 1 should equal 2");
}

/* Test suite for edge cases and combinations */
ZTEST_SUITE(edge_cases, NULL, NULL, NULL, NULL, NULL);

ZTEST(edge_cases, test_max_min_values)
{
    zassert_equal(internal_add(INT32_MAX, 0), INT32_MAX, "MAX + 0 should equal MAX");
    zassert_equal(internal_sub(INT32_MIN, 0), INT32_MIN, "MIN - 0 should equal MIN");
    zassert_equal(internal_mul(INT32_MAX, 1), INT32_MAX, "MAX * 1 should equal MAX");
    zassert_equal(internal_div(INT32_MAX, 1), INT32_MAX, "MAX / 1 should equal MAX");
}

ZTEST(edge_cases, test_shift_boundary_values)
{
    /* Test shifting at boundaries */
    zassert_equal(internal_lshift(INT32_MAX >> 1), INT32_MAX - 1, "Left shift near max");
    zassert_equal(internal_rshift(1), 0, "Right shift of 1 should be 0");
    zassert_equal(internal_lshift(0x40000000), INT32_MIN, "0x40000000 << 1 should equal INT32_MIN");
}

ZTEST(edge_cases, test_combined_operations)
{
    /* Test combinations of operations */
    int32_t result = internal_add(internal_mul(5, 6), internal_div(20, 4));
    zassert_equal(result, 35, "(5*6) + (20/4) should equal 35");
    
    result = internal_sub(internal_lshift(8), internal_rshift(10));
    zassert_equal(result, 11, "(8<<1) - (10>>1) should equal 11");
    
    bool bool_result = internal_and(internal_or(true, false), internal_not(false));
    zassert_true(bool_result, "(true OR false) AND (NOT false) should be true");
}