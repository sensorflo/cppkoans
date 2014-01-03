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
//   The elements are indexed from 0 to size-1.... You can access an array using
//   the subscript operator []
TEST(about_arrays,arrays_elements_are_indexed_from_0_to_size_minus_1)
{
  int a[] = {3,5,8};
  EXPECT_EQ( a[_________], 3);  
  EXPECT_EQ( a[_________], 5); 
  EXPECT_EQ( a[_________], 8); 
}

// TC++PL4 7.3 Arrays
//   The number of elements of the array, the array bound, must be a constant
//   expression ($10.4).
TEST(about_arrays,array_bound_must_be_a_const_expr)
{
  EXPECT_COMPILEABLE(__);
  #if 0
  int n;
  int a[n];
  #endif

  EXPECT_COMPILEABLE(__);
  #if 0
  const int n = 3;
  int a[n];
  #endif
}

// TStd 8.3.4 Arrays / 1
//   ... the constant-expression (5.19) [defining the array's size] ... and its
//   value shall be greater than zero
//
// However zero-sized arrays are supported by some implementations, e.g. GCC.
// They are very useful as the last element of a structure that is really a
// header for a variable-length object.
// http://gcc.gnu.org/onlinedocs/gcc/Zero-Length.html
TEST(about_arrays,array_bound_must_be_greater_than_zero)
{
#if 0
  int a[0];   // compile error
#endif 
  EXPECT_TRUE(_________);//	acknowledge you understood this koan
}

// TC++PL4 7.3.1 Array Initializers
//   An array can be initialized by a list of values.... When an array is
//   declared without a specific size, but with an initializer list, the size is
//   calculated by counting the elements of the initializer list.
//
//   If the initializer supplies too few elements for an array, 0 is used for
//   the rest.
TEST(about_arrays,)
{
  EXPECT_EQ( __, sizeof(char) ); // quick refresher from about_characters koans

  char a1[] = {'a','b','c'};
  EXPECT_EQ( __, sizeof(a1) );

  int a2[4] = {42,31};
  EXPECT_EQ( __, a2[0] );
  EXPECT_EQ( __, a2[1] );
  EXPECT_EQ( __, a2[2] );
  EXPECT_EQ( __, a2[3] );
}

// TC++PL4 7.3.1 Array Initializers
//   If a size is explicitly specified, it is an error to give surplus elements
//   in an initializer list.
TEST(about_arrays,)
{
#if 0
  char a2[2] = {'a','b','c'}; // compile error: to many elements in initializer

  char a3[]; // compile error: array size neither given explicitely nor
  // implicitely through an initializer list
#endif 
}

size 0??

what happens with values if not initialized? where is the _exact_ answer in TC++PL4; undefined behaviour? 


// TC++PL4 7.3 Arrays
//   Access out of range of an array is undefined...
// 
// TC++PL4 7.??? Pointers into Arrays
//   Taking a pointer to the element one beyond the end of an array is
//   guaranteed to work. ... it may not be used for reading or writing.
//
// TC++PL4 7.???? Pointers into Arrays
//   The result of taking the address of the element before the initial element
//   or beyond one-past-the-last element is undefined ...


// TC++PL4 7.3.1 Array Initializers
//  There is no built-in copy operation for arrays. You cannot initialize one
//  array with another (not even of exactly the same type), and there is no
//  array assignment:
TEST(about_arrays,there_is_no_copy_operation_for_arrays)
{
#if 0
  int a1[2];
  int a2[2] = a1; // compile error: cannot initialize an array with another
  a2 = a1; // compile error: there is no array assignment 
#endif
  EXPECT_TRUE(_________);//	acknowledge you understood this koan
}


// TC++PL4 7.3 Arrays
//  If you allocate an array on the free store, be sure to delete[] [opposed to
//  delete without brackets] its pointer once only and only after its last use
//  (§11.2.2).


TEST(about_arrays,out_of_range_access)
{
  
}

 

// TC++PL4 7.3.1 Array Initializers
//
// array decay: T[size] (i.e. array of size elements of type T) is converted to
// T* unless most of the cases. For exceptions see next koan
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

//
// Also, due to array decay rules, the array decays, and thus you get an
// assignment to an Rvalue pointer 
//
