#include "cppkoans.h"

using namespace std;

TEST(about_strings,double_quotes_define_string_literals)
{
  string str = "hello world";
  EXPECT_EQ(____,str); 
}

TEST(about_strings,double_quotes_with_L_prefix_define_wide_character_string_literals)
{
  wstring wstr = L"hello world";
  EXPECT_EQ(_____,wstr);
}

// todo: c11's raw, u8, u16 etc prefixes

TEST(about_strings,simple_escape_sequences)
{
  // As most programming languages, C++ supports escape sequences. The following
  // koan teaches you only a subset of the existing simple escape sequences.
  // More wisdom and a complete list of available escape sequences you will find
  // at http://en.cppreference.com/w/cpp/language/escape

  string newline = "\n";
  EXPECT_EQ(__,static_cast<int>(newline[0]));

  string tab = "\t";
  EXPECT_EQ(__,static_cast<int>(tab[0]));

  string double_quote = "\"";
  EXPECT_EQ(__,static_cast<int>(double_quote[0]));
}

TEST(about_strings,more_escape_sequences)
{
  // define a character by its unicode code point with the \uxxxx escape
  // sequence. 
  wstring devanagari_om = L"\u0950";
  EXPECT_EQ(__,static_cast<int>(devanagari_om[0]));
}

TEST(about_strings,adjancted_string_literals_are_concatenated)
{
  // the adjancated string literalys can be separated by any number of any blank
  // characters.

  string str = "hello" " wor"
    "ld";
  EXPECT_EQ(____,str);

  // However that only works for literals, not for variables / objects:
  // 
  // string str1,str2;
  // string str3 = str1 str2;   ! compile error
  // string str3 = str1 "foo";  ! compile error
}

TEST(about_strings,adjancted_string_literals_are_concatenated_into_one_string_literal)
{
  string str = "4\
2";
  EXPECT_EQ(____,str);
}

TEST(about_strings,string_literals_are_implicitely_suffixed_with_the_null_char)
{
  char buf[] = "42";
  EXPECT_EQ(__,sizeof(buf));
  EXPECT_EQ(______,buf[0]);
  EXPECT_EQ(______,buf[1]);
  EXPECT_EQ(______,buf[2]);
}

TEST(about_strings,STL_string_assignment_makes_a_copy)
{
  string str1 = "hello";
  string str2 = str1;
  str1[0] = 'b';
  EXPECT_EQ(____,str2);
}
