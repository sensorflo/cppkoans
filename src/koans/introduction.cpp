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

// In a few cases it is not possible for me to provide you with a proper
// question which you can meditate upon and then try to answer it. I will then
// teach you by written wisdom only. In such cases you only have to acknowledge
// that you have read and hopefully understood the wisdom I gave you.
TEST(introduction,acknowledge)
{
  ACKNOWLEDGE( __ ); // answer with 'true'
}

// Most koans are amended with information on the topic, with references to
// further information and possibly with extracts from those sources. The 2nd
// argument of the TEST macro is the test (aka koan) name which really is a
// brief sentence stating the essence of what the koans tries to teach you. So
// you're adviced to always first read that sentence, and after that read the
// information in the comment preceding the koan.
//
// Often used references are referred to by aliases defined in the following
// list:
//
// - TC++PL4: The book 'The C++ Programming Language Fourth Edition' by Bjarne
//   Stroustrup.
//
// - TStd: The ISO C++ standard. In short just 'the standard'. Officially known
//   as 'ISO International Standard ISO/IEC 14882:2011(E) – Programming Language
//   C++'. http://isocpp.org/std/the-standard.
//
// - C++FAQ: The web site http://www.parashift.com/c++-faq/. There is also a
//   book 'C++ FAQs' by Cline, Lomow, and Girou.
TEST(introduction,koans_are_amended_with_info_and_references)
{
  ACKNOWLEDGE(__);
}

// Some things such as sizeof(int) are defined as being implementation defined
// by the C++ standard. The correct answer for such an expression is the
// identifier implementation_defined.
//
// TC++PL4 C.2 The Standard
//   ... implementation-defined ... This means that each implementation must
//   provide a specific, well-defined behavior for a construct and that behavior
//   must be documented.
//
// TStd 3.4.1 1 implementation-defined behavior
//   unspecified behavior where each implementation documents how the choice is
//   made.
TEST(introduction,implementation_defined)
{
  EXPECT_EQ( __, sizeof(int) );
}

// cppkoans are based upon the C++11 standart.
//
// Some implementations do not support all of the features which the C++11
// standart defines. In order that cppkoans is still usefull on multiple
// implementations, features potentially not supported are only conditionally
// compiled using preprocessor conditionals (e.g. #if) and are thus inexistent
// on some implementations. In such a case you sadly can't learn from practical
// experience since as said the respective code fragment is technically
// inexistent, but at least you can read the concepts.
//
// Note that the directives used, e.g. __HAS_LONG_LONG, are non-standard; they
// are defined internally by cppkoans.
TEST(introduction,potentially_unsupported_features_are_conditionally_compiled)
{
  #if __HAS_TYPE_LONG_LONG
  long long l = 42;
  EXPECT_EQ( __, l );
  #endif

  ACKNOWLEDGE( __ );
}

// typeid(...)'s return type is std::type_info (from #include <typeinfo>), which
// has a member method 'const char* name() const'. What it returns is
// implementation defined. Many koans make use of typeid to teach you type
// related knowledge. In case you give a wrong answer, you get printed what
// std::type_info::name() returns. Thus it makes sense that you have a sense of
// how name() behaves in your implementation.
//
// http://www.cplusplus.com/reference/typeinfo/type_info/name/
//   Returns a null-terminated character sequence that may identify the type.
//
//   The particular representation pointed by the returned value is
//   implementation-defined, and may or may not be different for different
//   types.
TEST(introduction,know_your_implementations_type_info_name_scheme)
{
  // the point is to get a feeling, a sense of how the scheme works in your
  // implementation. It's not the point to actually remember the exact answers.

  // fundamental types
  EXPECT_STREQ( ____, typeid(char).name() );
  EXPECT_STREQ( ____, typeid(signed char).name() );
  EXPECT_STREQ( ____, typeid(unsigned char).name() );
  EXPECT_STREQ( ____, typeid(wchar_t).name() );

  EXPECT_STREQ( ____, typeid(bool).name() );

  EXPECT_STREQ( ____, typeid(short).name() );
  EXPECT_STREQ( ____, typeid(unsigned short).name() );
  EXPECT_STREQ( ____, typeid(int).name() );
  EXPECT_STREQ( ____, typeid(unsigned int).name() );
  EXPECT_STREQ( ____, typeid(long).name() );
  EXPECT_STREQ( ____, typeid(unsigned long).name() );

  EXPECT_STREQ( ____, typeid(float).name() );
  EXPECT_STREQ( ____, typeid(double).name() );

  // compound
  EXPECT_STREQ( ____, typeid(int*).name() );
  EXPECT_STREQ( ____, typeid(char*).name() );
  EXPECT_STREQ( ____, typeid(int[]).name() );
  EXPECT_STREQ( ____, typeid(int[3]).name() );
}
