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