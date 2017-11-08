#include "..\Stack-lab\Stack.h"

#include "gtest.h"

TEST(TStack, TStackcreate_stack_with_positive_length){
  ASSERT_NO_THROW(TStack<int> st(3));
}

TEST(TStack, throws_when_create_stack_with_negative_length){
	ASSERT_ANY_THROW(TStack<int> st(-3));
}

TEST(TStack, can_create_copied_stack)
{
	TStack<int> st(5);

	ASSERT_NO_THROW(TStack<int> st1(st));
}

TEST(TStack, copied_stack_is_equal_to_source_one)
{
	int i;
	TStack<int> a(3), b;
	for (i = 0; i < 3; i++) {
		a.push(i);
	}
	b = a;
	for (i = 0; i < 3; i++) {
		EXPECT_EQ(i, b[i]);
	}
}

TEST(TStack, copied_stack_has_its_own_memory)
{
	TStack<int> a(3), b;
	for (int i = 0; i < a.getmaxsize(); i++) {
		a.push(i);
	}
	b = a;
	int tmp = b.pop();
	b.push(5);
	EXPECT_NE(a.top(), b.top());
}

TEST(TStack, can_get_size){
	TStack<int> st(5);
	for (int i = 0; i < 3; i++) {
		st.push(i);
	}
	EXPECT_EQ(3, st.getsize());
}

TEST(TStack, can_get_maxsize){
	TStack<int> st(5);
	EXPECT_EQ(5, st.getmaxsize());
}

TEST(TStack, throws_when_get_top_in_empty_stack){
	TStack<int> st(3);
	ASSERT_ANY_THROW(st.top());
}

TEST(TStack, throws_when_get_pop_in_empty_stack){
	TStack<int> st(3);
	ASSERT_ANY_THROW(st.pop());
}

TEST(TStack, throws_when_push_an_element_in_full_stack) {
	TStack<int> st(3);
	for (int i = 0; i < 3; i++) {
		st.push(i);
	}
	ASSERT_ANY_THROW(st.push(3));
}

TEST(TStack, can_assign_stack_to_itself)
{
	TStack<int> st(3);
	ASSERT_NO_THROW(st = st);
}

TEST(TStack, can_assign_stacks_of_equal_maxsize)
{
	TStack<int> a(3), b(3);
	b = a;
	EXPECT_EQ(a, b);
}

TEST(TStack, assign_operator_changes_stack_maxsize)
{
	TStack<int> a(3), b(5);
	b = a;
	EXPECT_EQ(3, b.getmaxsize());
}

