#include "cppkoans.h"
#if 0
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
  int a[3] = {3,5,8};
  EXPECT_EQ( a[_________], 5);  
  EXPECT_EQ( a[_________], 3); 
  EXPECT_EQ( a[_________], 8); 
}

// Given an array a and an integer i, a[i] is identical to *((a)+(i)).
// Suprisingly this is identical to i[a] (via *((i)+(a))), i.e. the subscript
// operator [] is commutative.
// 
// TStd 8.3.4 Arrays / 6
//   Except where it has been declared for a class (13.5.5), the subscript
//   operator [] is interpreted in such a way that E1[E2] is identical to
//   *((E1)+(E2)). Because of the conversion rules that apply to +, if E1 is an
//   array and E2 an integer, then E1[E2] refers to the E2-th member of E1.
//   Therefore, despite its asymmetric appearance, subscripting is a commutative
//   operation.
TEST(about_arrays,subscript_operator_is_defined_via_plus_and_dereferening_and_is_commutative)
{
  int a[3] = {3,5,8};
  int i = 1;
  EXPECT_EQ( __, a[i] == *(a+i) );  
  EXPECT_EQ( __, i[a] == *(i+a) );  
  EXPECT_EQ( __, i[a] == a[i] );  
  EXPECT_EQ( __, 0[a] );  
  EXPECT_EQ( __, 2[a] );  
}
#endif

// TC++PL4 7.3 Arrays
//   The number of elements of the array, the array bound, must be a constant
//   expression ($10.4).
// 
// Note that varaiable-length automatic arrays are allowed in ISO C99 (that is
// C, not C++). The following is a link to a usenet discussion why they are not
// available in C++:
// https://groups.google.com/forum/#!topic/comp.std.c++/K_4lgA1JYeg
//
// Varaiable-length arrays are also supported by some C++ implementations. E.g
// GCC 4.8.1 by default uses it's own dialact of C++98 which supports
// variable-length arrays; use -std=c++11 or -std=c++98 to be standard
// conforming.
however what is typeid(new(T[n]))?
how to define a ppointer to an array, e.g. (int[3])* a = new int[3]? Does that work for variable size?  
how to properly parentise arbitray types array of ptr to array of some memberfunc for example
TEST(about_arrays,array_bound_must_be_a_const_expr)
{
  EXPECT_COMPILEABLE(true);
  #if 0
  int n;
  int a[n];
  #endif

  EXPECT_COMPILEABLE(false);
  #if 0
  const int n = 3;
  int a[n];
  #endif
}

// TStd 8.3.4 Arrays / 1
//   ... the constant-expression (5.19) [defining the array's size] ... value
//   shall be greater than zero
//
// Zero-sized arrays are supported by some implementations. E.g GCC 4.8.1 by
// default uses it's own dialact of C++98 which supports zero-sized arrays; use
// -std=c++11 or -std=c++98 to be standard conforming.
//
// Zero-sized arrays are very useful as the last element of a structure that is
// really a header for a variable-length object.
// http://gcc.gnu.org/onlinedocs/gcc/Zero-Length.html
TEST(about_arrays,array_bound_must_be_greater_than_zero)
{
  EXPECT_COMPILEABLE(__);
  #if 0
  int a[0];
  #endif 
}

// TC++PL4 7.3.1 Array Initializers
//   An array can be initialized by a list of values.... When an array is
//   declared without a specific size, but with an initializer list, the size is
//   calculated by counting the elements of the initializer list.
TEST(about_arrays,array_initializers)
{
  EXPECT_EQ( __, sizeof(char) ); // quick refresher from about_characters koans

  char a[] = {'a','b','c'};
  EXPECT_EQ( __, sizeof(a) );
}

// TC++PL4 7.3.1 Array Initializers
//   If the initializer supplies too few elements for an array, 0 is used for
//   the rest.
TEST(about_arrays,surplus_array_elements_are_initialized_with_zero)
{
  int a[4] = {42,31};
  EXPECT_EQ( __, a[0] );
  EXPECT_EQ( __, a[1] );
  EXPECT_EQ( __, a[2] );
  EXPECT_EQ( __, a[3] );
}

// TC++PL4 7.3.1 Array Initializers
//   If a size is explicitly specified, it is an error to give surplus elements
//   in an initializer list.
TEST(about_arrays,surplus_array_initializers_are_an_error)
{
  EXPECT_COMPILEABLE(__);
  #if 0
  char a[2] = {'a','b','c'}; 
  #endif

  EXPECT_COMPILEABLE(__);
  #if 0
  char a[2] = {'a','b'}; 
  #endif
}

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
  EXPECT_COMPILEABLE(__);
  #if 0
  void foo() {
    int a1[2];
    int a2[2] = a1;
  }
  #endif

  EXPECT_COMPILEABLE(__);
  #if 0
  void foo() {
    int a1[2];
    int a2[2];
    a2 = a1;
  }
  #endif
}

// TC++PL4 7.3 Arrays
//  If you allocate an array on the free store, be sure to delete[] [opposed to
//  delete without brackets] its pointer once only and only after its last use
//  (§11.2.2).
 

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
// what happens with values if not initialized? where is the _exact_ answer in TC++PL4; undefined behaviour? 



