#include "cppkoans.h"

// TC++PL chapter 6.2.2 Booleans
TEST(about_booleans,true_has_the_value_one_when_convertet_to_an_integer)
{
  EXPECT_EQ(__,int(true)); 
}

TEST(about_booleans,false_has_the_value_zero_when_convertet_to_an_integer)
{
  EXPECT_EQ(__,int(false)); 
}

// TC++PL chapter 10.5.2.5 Boolean conversions
// Pointer, integral and floating-point values can be implicitely converted to
// bool ($6.2.2). A nonzero value converts to true; a zero value converts to
// false.
TEST(about_booleans,non_zero_is_true__zero_is_false)
{
  EXPECT_EQ(__,bool(1)); 
  EXPECT_EQ(__,bool(-42)); 
  EXPECT_EQ(__,bool(0)); 
  EXPECT_EQ(__,bool(1.0)); 
  EXPECT_EQ(__,bool(0.0)); 
  EXPECT_EQ(__,bool(42)); 
  EXPECT_EQ(__,bool(3.1415)); 
  EXPECT_EQ(__,bool(NULL)); 
  int i = 0;
  int* p = &i;
  EXPECT_EQ(__,bool(p));
}

