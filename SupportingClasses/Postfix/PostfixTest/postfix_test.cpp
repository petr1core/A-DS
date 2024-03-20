#include "gtest.h"
#include "PostfixLib/postfix.h"

TEST(TPostfixCalc, can_create_calc_with_positive_length)
{
	ASSERT_NO_THROW(TPostfixCalc c("12*5"));
}

TEST(TPostfixCalc, throws_when_create_calc_with_zero_length)
{
	ASSERT_ANY_THROW(TPostfixCalc c(""));
}

TEST(TPostfixCalc, can_copy_calc)
{
	TPostfixCalc c("(10 + 15) * 9");
	ASSERT_NO_THROW(TPostfixCalc c1(c));
}

TEST(TPostfixCalc, copied_calc_is_equal_to_source_one)
{
	TPostfixCalc c("(10 + 15) * 9");
	TPostfixCalc c1(c);
	ASSERT_EQ(true, c == c1);
}

TEST(TPostfixCalc, copied_calc_has_its_own_memory)
{
	TPostfixCalc c("(10 + 15) * 9");
	TPostfixCalc c1(c);
	c.ToPostfix();
	ASSERT_ANY_THROW(c1.CalcPostfix());
}