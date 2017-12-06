#include "..\Stack-lab\TCalculator.h"

#include "gtest.h"

TEST(TCalculator, can_create_object) {
	ASSERT_NO_THROW(TCalculator a("2+2"));
}

TEST(TCalculator, false_check_when_opening_brackets_more_then_closing_breackets) {
	TCalculator a("((2+2*3)");

	EXPECT_EQ(0, a.check());
}

TEST(TCalculator, false_check_when_closing_brackets_more_then_opening_breackets) {
	TCalculator a("(2+2)*3)");

	EXPECT_EQ(0, a.check());
}

TEST(TCalculator, false_check_when_the_first_symbol_is_closing_breacket) {
	TCalculator a(")((2+2*3)");

	EXPECT_EQ(0, a.check());
}

TEST(TCalculator, false_check_when_the_last_symbol_is_opening_breacket) {
	TCalculator a("(2+2*3))(");

	EXPECT_EQ(0, a.check());
}

TEST(TCalculator, throw_when_try_topostfix_incorrect_string) {
	TCalculator a(")2+3)(");

	ASSERT_ANY_THROW(a.topostfix());
}

TEST(TCalculator, throw_when_try_to_calculate_incorrect_string) {
	TCalculator a(")2+3)(");

	ASSERT_ANY_THROW(a.calc());
}

TEST(TCalculator, can_get_infix) {
	TCalculator a("2+2");

	EXPECT_EQ("2+2", a.getinfix());
}

TEST(TCalculator, can_set_infix) {
	TCalculator a("");

	a.setinfix("2+2");

	EXPECT_EQ("2+2", a.getinfix());
}

TEST(TCalculator, can_get_postfix) {
	TCalculator a("(2+3)*4");

	a.topostfix();

	EXPECT_EQ("2 3+ 4*", a.getpostfix());
}

TEST(TCalculator, can_add_numbers) {
	TCalculator a("2+2");

	EXPECT_EQ(4, a.calc());
}

TEST(TCalculator, can_substract_numbers) {
	TCalculator a("5-2");

	EXPECT_EQ(3, a.calc());
}

TEST(TCalculator, can_multiply_numbers) {
	TCalculator a("2*7");

	EXPECT_EQ(14, a.calc());
}

TEST(TCalculator, can_divide_numbers) {
	TCalculator a("15/3");

	EXPECT_EQ(5, a.calc());
}

TEST(TCalculator, can_pow_numbers) {
	TCalculator a("3^3");

	EXPECT_EQ(27, a.calc());
}

TEST(TCalculator, can_work_with_double_numbers) {
	TCalculator a("((2.6+7.8)^0.3-4.5/8.7)*5.55");

	EXPECT_EQ((pow(2.6 + 7.8, 0.3) - 4.5 / 8.7)*5.55, a.calc());
}

TEST(TCalculator, can_calculate_a_large_string) {
	TCalculator a("9+(5*45-(7+7^4)*5/(7*2+21/254)+4*9^6)*(7+34+9*(9+3+4^7/8-6+562-5)*6)/10^7");

	double result = 9 + (5 * 45 - (7 + pow(7, 4)) * 5 / (7 * 2 + 21.0 / 254) + 4 * pow(9, 6))*(7 + 34 + 9 * (9 + 3 + pow(4, 7) / 8 - 6 + 562 - 5) * 6) / pow(10, 7);
	cout.precision(100);
	cout << a.calc() << endl << result << endl;

	EXPECT_EQ(result, a.calc());
	//EXPECT_EQ(201.064, a.calc());
}