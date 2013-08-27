#include "gtest/gtest.h"

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
