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
// - TC++PL4: The book 'The C++ Programming Language Fourth Edition' by Bjarne
//   Stroustrup
//
// - TStd: The ISO C++ standard. In short just 'the standard'. Officially known
//   as 'ISO International Standard ISO/IEC 14882:2011(E) – Programming Language
//   C++'. http://isocpp.org/std/the-standard. You have to pay for the document,
//   however a draft, which is said to be the same appart from minor editorial
//   changes, is freely available at
//   http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3337.pdf
//
// - C++FAQ: The web site http://www.parashift.com/c++-faq/. There is also a
//   book 'C++ FAQs' by Cline, Lomow, and Girou.
TEST(introduction,koans_are_amended_with_info_and_references)
{
  EXPECT_TRUE(_________);
}

// Some things such as sizeof(int) are defined as being implementation-defined
// by the C++ standard. The correct answer for such an expression is the
// identifier implementation_defined.
//
// TC++PL4 C.2 The Standard
//   ... implementation-defined ... This means that each implementation must
//   provide a specific, well-defined behavior for a construct and that behavior
//   must be documented.
//
// TStd 1.3.10 implementation-defined behavior
//   behavior, for a well-formed program construct and correct data, that
//   depends on the implementation and that each implementation documents
TEST(introduction,implementation_defined)
{
  EXPECT_EQ( __, sizeof(int) );
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

// Sometimes a koan may querry your wisdom on whether a code fragment is
// compileable or not. Note that the question is about compiling only, i.e.
// excluding linking.
TEST(introduction,expectations_on_compileability)
{
  // The code fragment in question is enclosed by the #if / #endif lines

  EXPECT_COMPILEABLE(__); // true (=compileable) or false (= _not_ compileable)? 
  #if 0
  bla bla % ^ & foo bar ??;
  #endif  

  EXPECT_COMPILEABLE(__); // true (=compileable) or false (= _not_ compileable)? 
  #if 0
  int i;
  #endif  
}
