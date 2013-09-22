#include "cppkoans.h"

// TC++PL chapter 6.2.2 Booleans
TEST(about_booleans,when_convertet_to_an_integer_true_is_one_and_false_is_zero)
{
  EXPECT_EQ(__,int(true));
  EXPECT_EQ(__,int(false));
}

#ifdef _MSC_VER
# pragma warning(push)
# pragma warning(disable:4800)
#endif
// TC++PL chapter 10.5.2.5 Boolean conversions
// Pointer, integral and floating-point values can be implicitly converted to
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
#ifdef _MSC_VER
# pragma warning(pop)
#endif

// TC++PL 6.2.8 Sizes
//   1 <= sizeof(bool) <= sizeof(long)
//
// TStd 5.3.3/1
//   sizeof(char), sizeof(signed char) and sizeof(unsigned char) are 1; the
//   result of sizeof applied to any other fundamental type is
//   implementation-defined. In particular, sizeof(bool) and ... are
//   implementation-defined
TEST(about_booleans,sizeof_bool_is_implementation_defined)
{
  EXPECT_EQ(__,sizeof(bool));
  EXPECT_EQ(__,sizeof(bool)==sizeof(int));
}
