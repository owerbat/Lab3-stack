#include "..\Stack-lab\TCalculator.h"

#include "gtest.h"

TEST(TCalculator, can_create_object) {
	ASSERT_NO_THROW(TCalculator a("2+2"));
}