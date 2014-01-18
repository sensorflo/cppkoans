#include "cppkoans.h"
#include <climits>

// Like char, each integer type comes in three forms: "plain", signed, and
// unsigned. Unlike plain char s, plain integers s are always signed and are
// just aliases for their signed form, i.e. no distinct type. In addition,
// orthogonally, integers come in four sizes: short, int, long and long long.
// long long was added in C++11.
//
// TC++PL4 6.2.4 Integer Types
TEST(about_integer_types,available_types)
{
  EXPECT_EQ( __, std::numeric_limits<short>::is_signed );
  EXPECT_EQ( __, typeid(short) == typeid(signed short) );
  EXPECT_EQ( __, typeid(short) == typeid(unsigned short) );

  EXPECT_EQ( __, std::numeric_limits<int>::is_signed );
  EXPECT_EQ( __, typeid(int) == typeid(signed int) );
  EXPECT_EQ( __, typeid(int) == typeid(unsigned int) );

  EXPECT_EQ( __, std::numeric_limits<long>::is_signed );
  EXPECT_EQ( __, typeid(long) == typeid(signed long) );
  EXPECT_EQ( __, typeid(long) == typeid(unsigned long) );

  #if __HAS_TYPE_LONG_LONG
  EXPECT_EQ( __, std::numeric_limits<long long>::is_signed );
  EXPECT_EQ( __, typeid(long long) == typeid(signed long long) );
  EXPECT_EQ( __, typeid(long long) == typeid(unsigned long long) );
  #endif

  // recapitulation
  EXPECT_EQ( __, std::numeric_limits<char>::is_signed );
}

// TC++PL4 6.2.4.1 Integer Literals
// Integer literals come in three guises: decimal, octal, and hexadecimal. ...
// Decimal literals ... look as you would expect them to. ... A literal starting
// with zero followed by x or X (0x or 0X) is a hexadecimal (base 16) number. A
// literal starting with zero but not followed by x or X is an octal (base 8)
// number.
TEST(about_integer_types,literals_and_available_prefixes)
{
  // answer with the decimal literal equivalent
  EXPECT_EQ( __, 0xa );
  EXPECT_EQ( __, 0xb );
  EXPECT_EQ( __, 0xA );
  EXPECT_EQ( __, 0xfF );
  EXPECT_EQ( __, 011 );
}

// TC++PL4 6.2.4.1 Integer Literals
// The suffix U [or u] can be used to write explicitly unsigned literals.
// Similarly, the suffix L [or l] can be used to write explicitly long literals.
// [Similarly, the suffix LL [or ll], added in C++11, can be used to write
// explicit long long literals] ... Combination of suffixes are allowed. [So are
// combinations with a prefix. ]
TEST(about_integer_types,literals_and_available_suffixes)
{
  EXPECT_EQ( typeid(________), typeid(42U) );
  EXPECT_EQ( typeid(________), typeid(42l) );
  EXPECT_EQ( typeid(42 __________), typeid(unsigned long) );
  #if __HAS_TYPE_LONG_LONG
  EXPECT_EQ( typeid(31415 __________), typeid(long long) );
  #endif 
  EXPECT_EQ( __, 0xF0UL );
  EXPECT_EQ( typeid(________), typeid(0xF0UL) );
}

// TC++PL4 6.2.4.1 Integer Literals
//
// regarding size:
//   no suffix: starts at int (i.e. skip short)
//   l: starts at long
//   ll: is long long
// regarding sign:
//   suffix u: only unsigned forms
//   no suffix u:
//     decimal: only signed forms
//     hex/octal: signed before unsigned, treated as bit pattern
// TEST(about_integer_types,)
// {
// }

// still assuming this is an implementation which implements negative integers
// with two's complement.
// 0xFFFF is -1, not 65...
TEST(about_integer_types,hex_and_oct_literals_define_bit_patterns)
{
  #if UINT_MAX == 0xFFFF
  EXPECT_EQ( __, 0xFFFF );
  EXPECT_EQ( typeid(________), typeid(0xFFFF) );
  #elif UINT_MAX == 0xFFFFFFFF
  EXPECT_EQ( -2, 0xFFFFFFFF );
  EXPECT_EQ( typeid(int), typeid(0xFFFFFFFF) );
  EXPECT_EQ( typeid(unsigned), typeid(0xFFFFFFFF) );
  EXPECT_EQ( typeid(long), typeid(0xFFFFFFFF) );
  EXPECT_EQ( typeid(unsigned long), typeid(0xFFFFFFFF) );
  #endif
}

// There are aliases for types in <cstdint> which you might find useful.
// (u|)int(|least|fast)(8|16|32|64)_t. Exactly given bit width, no other integer
// type exists with lesser size and at least the specified width, at least as
// fast as any other integer type with at least the specified width.
//
// - TC++PL4 43.7 Etc.
// - http://www.cplusplus.com/reference/cstdint/
