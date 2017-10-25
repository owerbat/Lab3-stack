#include "..\Stack-lab\Stack.h"

#include "gtest.h"

TEST(TStackcreate_bitfield_with_positive_length)
{
  ASSERT_NO_THROW(TStack<int> s(3));
}

