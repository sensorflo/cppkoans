#include "cppkoans.h"
#include <type_traits>
#pragma GCC diagnostic ignored "-Wunused-variable"

// C++11 added rvalue references, so since then there are two types of
// references, the lvalue references already known to C++98 and the new rvalue
// references. The term reference applies to both.


// A reference declaration declares a named variable as a reference, that is,
// an alias to an already-existing object or function. E.g. the following
// declares a named variable 'ri' as a reference to the alrady-existing object
// named 'i':
//
//   int i = 0;
//   int& ri = i;
//
// What 'ri' really is depends upon in what context of the grammar it is used:
//
//   'ri' as an expression (grammar symbol) denotes the referenced object,
//   here 'i'. I.e. 'ri' really is just an alias to the referenced
//   object. Here, the type of 'ri' consequently is the type of the referenced
//   object, here int.
//
//   'ri' as an id-expression (grammar symbol) denotes the reference (aka
//   reference variable). Here the type of 'ri' is 'reference to int'.
//
// In nearly all cases where it is not obvious what 'ri' is, it is an
// expression, not an id-expression. The author of this koans knows only one
// single exception: the argument to the decltype operator, which is handled
// in a later koan within the reference area.
//
// TC++PL4 7.7 References
//   A reference is an alternative name for an object, an alias... In a type
//   name, the notation X& means "reference to X".
//
// TStd14 8.3.2 References [dcl.ref]
//   1 ... A reference can be thought of as a name of an object. ...
TEST(about_references,a_reference_is_an_alias_to_an_object)
{
  //
  int i = 1;
  int& ri = i;

  EXPECT_EQ( __, ri );

  ri = 2;
  EXPECT_EQ( __, i );
  EXPECT_EQ( __, ri );

  i = 3;
  EXPECT_EQ( __, ri );

  EXPECT_EQ( __ /*true or false*/, &i == &ri );
}

// Concerning the topic of references, loosly speaking, typeid(x) always
// refers to the std::type_info of the referenced type, opposed to the
// std::type_info of the reference.
//
// The typeid operator has two syntax variants:
// 1. typeid(type), i.e. the argument is a type: If type is a reference type,
//    the result refers to a std::type_info object representing the referenced
//    type.
// 2. typeid(expresssion), i.e. the argument is an expression: There's nothing
//    special regarding references. Just remember what you learned before:
//    Considering 'typeid(ri)', if the identifier 'ri' was declared as a
//    reference, then here 'ri' is an expression denoting the referenced
//    object, not the reference.
//
// cppref: http://en.cppreference.com/w/cpp/language/typeid
TEST(about_references,typeid_returns_type_info_of_referenced_type) {
  EXPECT_EQ( true/*true or false*/, typeid(int) == typeid(int&));

  int i = 0;
  int& ri = i;
  EXPECT_EQ( true/*true or false*/, typeid(i) == typeid(ri));
}

// Concerning the topic of references, loosly speaking, sizeof(x) always
// returns the size of the referenced type, opposed to size of the reference.
//
// TStd14: 5.3.3 Sizeof [expr.sizeof]
//   2 When applied to a reference or a reference type, the result is the size
//     of the referenced type.
//
// Putting that together with the fact that the sizeof operator has these two
// syntax variants (see TStd14 [expr.unary]), one sees that concerning
// references the result is always the size of the referenced type
// 1. sizeof(type):
//    - [expr.sizeof] directly says so (... or a reference type ...).
// 2. sizeof expression:
//    - [expr.sizeof] directly says so (... to a reference or ...).
//    - Despite [expr.sizeof] being explicit about this case, there's actually
//      nothing special regarding references. Just remember what you learned
//      before. Considering 'sizeof(ri)', if the identifier 'ri' was declared
//      as a reference, then here 'ri' is an expression denoting the
//      referenced object, not the reference.
//
// TStd14 5.3. Unary expressions [expr.unary]
//   1 [grammar fragment showing syntax variants of sizeof]
TEST(about_references,sizeof_returns_size_of_referenced_type) {

  // if you fail on this question, repeat koans in area 'characters'
  EXPECT_EQ( __, sizeof(char));

  EXPECT_EQ( __, sizeof(char&));

  char c;
  char& rc = c;
  EXPECT_EQ( __, sizeof c);
  EXPECT_EQ( __, sizeof rc);
}

// Concerning the topic of references, loosly speaking, decltype(e) is the
// only case where, given 'e' being declared as reference, 'e' denotes the
// reference, opposed to the referenced object.
//
// 7.1.6.2 simple type specifiers [dcl.type.simple]
//   1  [the grammar lists 'decltype(expression)' as only variant of decltype]
//   4  The type denoted by decltype(e) is defined as follows:
//      - if e is an _unparenthesized_ id-expression or ..., decltype(e)
//        is the type of the entity named by e.... [I.e. this is the one
//        single case where, given an identifier 'e' being declared as
//        reference, 'e' is an id-expression and not an expression, and thus
//        'e' denotes the reference, opposed to the referenced object.]
//      - otherwise, if e is an xvalue, decltype(e) is T&&, where T is the
//        type of e;
//      - otherwise, if e is an lvalue, decltype(e) is T&, where T is the type
//        of e;
//      - otherwise [i.e. e is an prvalue], decltype(e) is the type of e.
TEST(about_references,decltype) {

  // always answer with true or false

  // tiny intro to std::is_reference in case you don't know it yet
  EXPECT_EQ( __, std::is_reference<int>::value);
  EXPECT_EQ( __, std::is_reference<int&>::value);

  int i = 0;
  int& ri = i;
  int fi();
  int& fri();

  EXPECT_EQ( __, std::is_reference<decltype(i)>::value);
  EXPECT_EQ( __, std::is_reference<decltype(ri)>::value);

  EXPECT_EQ( __, std::is_reference<decltype((i))>::value);
  EXPECT_EQ( __, std::is_reference<decltype((ri))>::value);

  EXPECT_EQ( __, std::is_reference<decltype(42)>::value);
  EXPECT_EQ( __, std::is_reference<decltype(fi())>::value);
  EXPECT_EQ( __, std::is_reference<decltype(fri())>::value);
}

// References are not objects, and because of that, there are no references to
// references, no arrays of references and no pointers to references.
//
// TStd14 8.3.2/5 References [decl.ref]
TEST(about_references,a_reference_is_not_an_object)
{
  #if 0
  int&& ri;    // error - there are no references to references
  int&[2] ari; // error - there are no arrays of references
  int&* pri;   // error - there are no pointers to references
  #endif
  ACKNOWLEDGE(__);
}

// TC++PL4 7.7 References
//   A reference [unlike a pointer] always refers to the [same] object to
//   which it was initialized... Consequently, the value of a reference cannot
//   be changed after initialization; it always refers to the same object.
//
// Given an identifier 'r' being declared as a reference, the 'r' as an
// expression denotes the referenced object, opposed to the reference. Imagine
// a szenario where a reference is an object which can be modified to refer to
// another object. Then some special syntax would be needed to refer to the
// reference object (in order to modify it), opposed to the referenced object.
TEST(about_references,a_reference_always_refers_to_the_same_object)
{
  ACKNOWLEDGE(__);
}

// TC++PL4 7.7 References
//   To ensure that a reference is a name for something (that is, that is
//   bound to an object [opposed to being "null"]) we must initialize the
//   reference.
//   There is no "null reference", and we may assume that a reference refers
//   to an object.
//
// TStd14 8.3.2/5 References [decl.ref]
//   A reference shall be initialized to refer to a valid object or
//   function. ... Note: in particular, a null reference cannot exist in a
//   well-defined program, because the only way to create such a reference
//   would be to bind it to the 'Object' obtained by dereferencing a null
//   pointer, which causes undefined behavior. ...
TEST(about_references,a_reference_must_be_initialized_with_a_valid_object_and_cannot_be_null)
{
  #if 0
  int& ri; // error
  int* p = nullptr;
  int& ri = *p; // error, *p dereferences a nullptr which is undefined
                // behaviour
  #endif
  ACKNOWLEDGE(__);
}


// Normaly a temporary is destroyed at the end of the enclosing full
// expression. However when bound to a reference, the lifetime of the
// temporary is extended so it lives as long as the reference.
//
// TStd14 12.2 temporary objects [class.temporary]
//   3 ... Temporary objects are destroyed as the last step in evaluating the
//     full-expression (1.9) that (lexically) contains the point where it was
//     created.
//   4 There are two context in which temporaries are destroyed at a different
//     point than the end of the full-expression. ...
//   5 The second context is when a reference is bound to a temporary.  The
//     temporary to which the reference is bound or the temporary that is the
//     complete object of a subobject to which the reference is bound persists
//     for the lifetime of the reference except ...
static std::string events;
struct A { ~A() { events += ",~A"; } };
struct B { ~B() { events += ",~B"; } };
A makeA() { static A a; return a; }
B makeB() { static B b; return b; }
TEST(about_references,reference_extends_lifetime_of_temporary)
{
  // remember that calling a function which returns by value (opposed to
  // return by reference) creates a temporary.

  {
    makeA();
    events += ",foo";
    const B& rb = makeB();
    events += ",bar";
  }

  EXPECT_EQ( std::string(____), events);
}
