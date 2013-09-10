#include "cppkoans.h"

// TC++PL 7.2 Pointers
//   For a type T, T* is the type "pointer to T"
//
// I.e. T and T* are two distinct types
TEST(about_pointers,a_type_amended_with_star_is_a_new_distinct_type)
{
  EXPECT_EQ(__,typeid(int)==typeid(int*));
  EXPECT_EQ(__,typeid(double*)==typeid(double));
  EXPECT_EQ(__,typeid(double*)==typeid(int*));
}

// & reference (aka address-of) operator (unary prefix)
// * dereferencing (aka indirection) operator (unary prefix) 
// 
// TC++PL 7.2 Pointers
//   ... a variable of type T* can hold the address of an object of type T.
TEST(about_pointers,ampersand_references_and_star_dereferences)
{
  int i = 42;
  int* p = &i;
  EXPECT_EQ(__,*p);
  EXPECT_EQ(__________,p);
  i = 31415;
  EXPECT_EQ(__,*p);
  int j = 666;
  p = &j;
  EXPECT_EQ(__,*p);
  EXPECT_EQ(__________,p);
  *p = 0;
  EXPECT_EQ(__,*p);
  EXPECT_EQ(__,i);
  EXPECT_EQ(__,j);
}
