// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include "StackLib/Stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(TStack<int> s(10));
}


TEST(TStack, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> s(-10));
}

TEST(TStack, can_copy_stack)
{
	TStack<int> t1(12);
	t1.Push(222);
	ASSERT_NO_THROW(TStack<int> t2(t1));
}

TEST(TStack, copied_stack_is_equal_to_source_one)
{
	TStack<int> t1(12);
	t1.Push(222);
	TStack<int> t2(t1);
	ASSERT_EQ(true, t1 == t2);
}

TEST(TStack, copied_stack_has_its_own_memory)
{
	TStack<int> t1(5);
	TStack<int> t2(t1);
	t2.Push(10900);
	ASSERT_EQ(false, t1 == t2);
}



TEST(TStack, can_pop_element)
{
	TStack<int> t(10);
	t.Push(100);
	ASSERT_EQ(100, t.Pop());
}

TEST(TStack, can_push_element)
{
	TStack<int> t(10);
	t.Push(100);
	ASSERT_EQ(100, t.Pop());
}

TEST(TStack, can_get_size)
{
	TStack<int> t(10);
	for (size_t i = 0; i < 10; i++)
	{
		t.Push(i);
	}
	ASSERT_EQ(10, t.GetSize());
}

TEST(TStack, can_assign_stack_to_itself)
{
	TStack<int> t(10);
	ASSERT_NO_THROW(t = t);
}

TEST(TStack, can_assign_stacks_of_equal_size)
{
	TStack<int> t1(11);
	TStack<int> t2(11);
	ASSERT_NO_THROW(t1 = t2);
}

TEST(TStack, can_assign_different_stack_size)
{
	TStack<int> t1(5);
	TStack<int> t2(10);
	ASSERT_NO_THROW(t1 = t2);
}
