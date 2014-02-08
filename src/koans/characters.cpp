#include "cppkoans.h"
#include <limits>
#include "limits.h"

// C++ provides a variety of distinct character types that reflect the variety
// of the many character sets and character set encodings in use:
// - char
// - unsigned char
// - signed char
// - wchar_t  (there is no 'unsigned wchar_t' or 'signed wchar_t')
//
// TC++PL4 chapter 6.2.3 Character Types
TEST(about_characters,char_and_signed_char_and_unsigned_char_are_distinct_types)
{
  EXPECT_EQ(__,typeid(char)==typeid(unsigned char));
  EXPECT_EQ(__,typeid(char)==typeid(signed char));
}

// TC++PL4 6.2.3.1 Signed and Unsigned Characters
// ... A char must behave identically to either a signed char or an unsigned
// char.
TEST(about_characters,whether_char_is_signed_or_unsigned_is_implementation_defined)
{
  EXPECT_EQ(__,std::numeric_limits<char>::is_signed);
  EXPECT_EQ(__,int(char(std::numeric_limits<unsigned char>::max())));
}

// TC++PL4 6.2.3.2 Character Literals
//   A character literal is a single character enclosed in single quotes. The
//   type of a character literal is char.
TEST(about_characters,type_of_single_quote_literal_is_char)
{
  EXPECT_EQ(typeid(________),typeid('x'));
}

// TC++PL4 6.2.3.2 Character Literals
//   Wide character literals are of the form L'ab' and are of type wchar_t.
TEST(about_characters,type_of_single_quote_literal_prefixed_by_L_is_wchar_t)
{
  EXPECT_EQ(typeid(________),typeid(L'x'));
  EXPECT_EQ(typeid(__________'y'),typeid(wchar_t));
}

// TC++PL4 6.2.3 Character Types
//   Each character has an integer value in the character set used by the
//   implementation. For example, the value of 'b' is 98 in the ASCII character
//   set.
//
// http://en.wikipedia.org/wiki/Code_point
TEST(about_characters,the_integer_value_of_a_char_is_its_code_point)
{
  // To be precise, the answers are implementation defined, but that is not the
  // point here. Almost certainly for the characters below your implementation
  // will use a superset of the ASCII encoding, which you can find here:
  // http://en.wikipedia.org/wiki/Ascii#ASCII_printable_characters
  EXPECT_EQ(__,int('a'));
  EXPECT_EQ(__,int('0'));
}

// TC++PL4 6.2.3.2 Character Literals
//   ... A few characters have standard names that use the backslash, \, as an
//   escape character:
//   Newline             NL (LF)  \n
//   Horizontal tab      HT       \t
//   Vertical tab        VT       \v
//   Backspace           BS       \b
//   Carriage return     CR       \r
//   Form feed           FF       \f
//   Alert               BEL      \a
//   Backslash           \        \\                  .
//   Question mark       ?        \?
//   Single quote        '        \'
//   Double quote        "        \"
//   Octal number                 \ooo
//   Hexadecimal number           \xhhh...
//
// http://en.wikipedia.org/wiki/Ascii#ASCII_control_code_chart
TEST(about_characters,escape_sequences)
{
  // This koan assumes your C++ implementation's character set is a superset of
  // the ASCII character set, and it assumes that the ASCII characters use the
  // same character encoding.
  EXPECT_EQ(__,'\n'=='\x0a');
  EXPECT_EQ(__,'\t'=='\011');
}

// TC++PL4 6.2.3 Character Types
//   ... the character types are integral types ($6.2.1) so that arithemtic and
//   bitwise logical operations ($10.3) apply.
TEST(about_characters,character_types_are_integral_types)
{
  // To be precise, the answer is implementation defined, but that is not the
  // point here. Almost certainly for the characters below your implementation
  // will use a superset of the ASCII encoding, which you can find here:
  // http://en.wikipedia.org/wiki/Ascii#ASCII_printable_characters
  EXPECT_EQ(__,'c' - 'a');
}

// TC++PL4 6.2.8 Sizes
//   Sizes of C++ objects are expressed in terms of multiples of the size of a
//   char, so by definition the size of a char is 1.
//
// TStd 5.3.3/1
//   sizeof(char), sizeof(signed char) and sizeof(unsigned char) are 1; the
//   result of sizeof applied to any other fundamental type is
//   implementation-defined.
//
// C++FAQ 26.1:
//   sizeof(char) is always 1. Always. It is never 2. Never, never, never.
TEST(about_characters,size_of_char_is_always_one)
{
  EXPECT_EQ(__,sizeof(char));
}

// TC++PL4 40.2.1 Limit Macros
//   CHAR_BIT: Number of bits in a char (usually 8).
//
// C++FAQ 26.2
// - Each of these things that the C++ language calls a byte has at least 8
//   bits, but might have more than 8 bits.
// - The C++ language gives you a way to find out how many bits are in a byte in
//   your particular implementation: include the header <climits>, then the
//   actual number of bits per byte will be given by the CHAR_BIT macro.
//
// http://www.cplusplus.com/reference/limits/numeric_limits/
//   numeric_limits<>::digits: For integer types: number of non-sign bits (radix
//   base digits) in the representation.
TEST(about_characters,a_char_has_at_least_8_bits)
{
  // two ways how to retrieve the number of bits in a char in the current
  // implementation.
  EXPECT_EQ(__,CHAR_BIT == std::numeric_limits<unsigned char>::digits);

  EXPECT_EQ(__,std::numeric_limits<unsigned char>::digits);
  EXPECT_EQ(__,std::numeric_limits<unsigned char>::digits>=8);
}
