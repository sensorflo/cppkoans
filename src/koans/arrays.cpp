#include "cppkoans.h"

// TC++PL4 7.3 Arrays
//   For a type T, T[size] is the type "array of size elements of type T."
TEST(about_arrays,arrays_are_distinct_types)
{
  int a[3];
  EXPECT_EQ( __, typeid(a) == typeid(int[3]));
  EXPECT_EQ( __, typeid(a) == typeid(int));
  EXPECT_EQ( __, typeid(a) == typeid(int*));
  EXPECT_EQ( __, typeid(a) == typeid(int[]));
  EXPECT_EQ( __, typeid(a) == typeid(int[4]));

  int a2[2];
  EXPECT_EQ( typeid(__________), typeid(a2));

  int* a3[4];
  EXPECT_EQ( typeid(__________), typeid(a3));

  DontWarnAboutUnreferencedVars(a,a2,a3);
}

// TC++PL4 7.3 Arrays
//   The elements are indexed from 0 to size-1...
TEST(about_arrays,arrays_elements_are_indexed_from_0_to_size_minus_1)
{
}

// TC++PL4 7.3 Arrays
//   The number of elements of the array, the array bound, must be a constant
//   expression ($10.4).
TEST(about_arrays,array_bound_must_be_a_const_expr)
{
}

// TC++PL4 7.3 Arrays
//   Access out of range of an array is undefined...
//
// TC++PL4 7.4 Pointers into Arrays
//   Taking a pointer to the element one beyond the end of an array is
//   guaranteed to work. ... it may not be used for reading or writing.
//
// TC++PL4 7.4 Pointers into Arrays
//   The result of taking the address of the element before the initial element
//   or beyond one-past-the-last element is undefined ...
TEST(about_arrays,out_of_range_access)
{
}

// TC++PL4 7.3 Arrays
//   There is no array assignment.
//
// Also, due to array decay rules, the array decays, and thus you get an
// assignment to an Rvalue pointer 
//
// TC++PL4 7.3.1 Array Initializers
//
// array decay: T[size] (i.e. array of size elements of type T) is converted to
// T* unless most of the cases. For exceptions see next koan.
TEST(about_arrays,array_decay)
{
  int* p = NULL;
  EXPECT_EQ( __, typeid(p) == typeid(int[]));
  DontWarnAboutUnreferencedVars(p);
}

// array decay: T[size] (i.e. array of size elements of type T) is converted to
// T* unless
// - when using as argument to sizeof
// - when using as argument to (unary prefix) & (referencing (aka address-of)
//   operator)
// - when being a string literal used to initialize an array
//
// C99 6.3.2.1/3 - Other operands - Lvalues, arrays, and function designators
//   Except when it is
//   - the operand of the sizeof operator
//   - or the unary & operator
//   - or is a string literal used to initialize an array
//   an expression that has type ‘‘array of type’’ is converted to an expression
//   with type ‘‘pointer to type’’ that points to the initial element of the
//   array object and is not an Lvalue.
TEST(about_arrays,array_decay_exceptions)
{
  char a[3] = "om";

  EXPECT_EQ( __, sizeof(a) );

  EXPECT_EQ( __, typeid(a) == typeid(char*) );
  EXPECT_EQ( __, typeid(a) == typeid(char[3]) );
  EXPECT_EQ( __, typeid(&a) == typeid(char*) );
  EXPECT_EQ( __, typeid(&a) == typeid(char(*)[3]) );
  EXPECT_EQ( typeid(__________), typeid(a[0]));

  char a2[] = "hello";
  EXPECT_EQ( typeid(__________), typeid(a2));
  EXPECT_EQ( typeid(__________), typeid("hello"));
  EXPECT_EQ( __, sizeof(a2));
  EXPECT_EQ( __, sizeof("hello"));

  DontWarnAboutUnreferencedVars(a,a2);
}

// passing arrays
void foo1(char a[])    { EXPECT_EQ( typeid(__________), typeid(a)); DontWarnAboutUnreferencedVars(a); }
void foo2(char a[3])   { EXPECT_EQ( typeid(__________), typeid(a)); DontWarnAboutUnreferencedVars(a); }
void foo3(char* a)     { EXPECT_EQ( typeid(__________), typeid(a)); DontWarnAboutUnreferencedVars(a); }
void foo4(char(&a)[3]) { EXPECT_EQ( typeid(__________), typeid(a)); DontWarnAboutUnreferencedVars(a); }
void foo5(char(*a)[3]) { EXPECT_EQ( typeid(__________), typeid(a)); DontWarnAboutUnreferencedVars(a); }
TEST(about_arrays,passing_arrays)
{
  char a[] = "om";
  foo1(a);
  foo2(a);
  foo3(a);
  foo4(a);
  foo5(&a);
}

// void foo(char*);
// // const char* foo(char[]);  identical to the one above
// // const char* foo(char[10]);  identical to the one above
// void bar(char(&)[3]) {  };
// template<int N>
// void fred(char(&)[N]) {  };

