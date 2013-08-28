#include "cppkoans.h"

// We shall contemplate truth by testing reality, via asserts.
TEST(about_asserts,test_assert_truth)
{
  EXPECT_TRUE(false); // This should be true
  EXPECT_FALSE(true); // This should be false
}

// Enlightenment may be more easily achieved with appropriate messages.
TEST(about_asserts,test_assert_with_message)
{
  EXPECT_TRUE(false) << "This should be true -- Please fix this";
}

// To understand reality, you must compare your expectations against actual
// reality.
TEST(about_asserts,test_assert_equality)
{
  int your_expected_value = __;
  int actual_value = 1 + 1;
  EXPECT_TRUE( your_expected_value == actual_value);
}

// Some ways of asserting equality are better than others.
TEST(about_asserts,test_a_better_way_of_asserting_equality)
{
  int your_expected_value = __;
  int actual_value = 1 + 1;
  EXPECT_EQ( your_expected_value, actual_value);
}

// Sometimes we will ask you to fill in the values.
TEST(about_asserts,test_fill_in_values)
{
  EXPECT_EQ( __, 1+1);
}
