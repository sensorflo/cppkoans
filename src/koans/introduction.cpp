#include "cppkoans.h"

// We shall contemplate truth by testing reality, via asserts. Google test
// (slightly modified) provides the ground to do so.
TEST(introduction,assert_truth)
{
  // insert 'true' or 'false'
  EXPECT_TRUE(_________);
  EXPECT_FALSE(__);
}

// To understand reality, you must compare your expectations against actual
// reality.
TEST(introduction,assert_equality)
{
  EXPECT_EQ( __ /*your expected value*/, 1+1 /*actual value*/ );
}

// Most koans are amended with information on the topic, with references to
// further information and possibly with extracts from those sources. Often used
// references are referred to by aliases defined in the following list:
// 
// - TC++PL: The book 'The C++ Programming Language Fourth Edition' by Bjarne
//   Stroustrup
// 
// - TStd: The ISO C++ standard. In short just 'the standard'. Officially known
//   as 'ISO International Standard ISO/IEC 14882:2011(E) – Programming Language
//   C++'. http://isocpp.org/std/the-standard.
// 
// - C++FAQ: The web site http://www.parashift.com/c++-faq/. There is also a
//   book 'C++ FAQs' by Cline, Lomow, and Girou.
TEST(introduction,koans_are_amended_with_info_and_references)
{
  EXPECT_TRUE(__);
}

// Some things such as sizeof(int) are defined as being implementation defined
// by the C++ standard. The correct answer for such an expression is the
// identifier implementation_defined.
//
// TC++PL C.2 The Standard
// ... implementation-defined ... This means that each implementation must
// provide a specific, well-defined behavior for a construct and that behavior
// must be documented.
// 
// TStd 3.4.1 1 implementation-defined behavior
// unspecified behavior where each implementation documents how the choice is
// made
TEST(introduction,implementation_defined)
{
  EXPECT_EQ( __, sizeof(int) );
}
