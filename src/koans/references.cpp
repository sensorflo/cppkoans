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
TEST(about_references, a_reference_is_an_alias_to_an_object)
{
  //
  int i = 1;
  int& ri = i;

  EXPECT_EQ(__, ri);

  ri = 2;
  EXPECT_EQ(__, i);
  EXPECT_EQ(__, ri);

  i = 3;
  EXPECT_EQ(__, ri);

  EXPECT_EQ(__ /*true or false*/, &i == &ri);
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
TEST(about_references, typeid_returns_type_info_of_referenced_type) {
  EXPECT_EQ(true/*true or false*/, typeid(int) == typeid(int&));

  int i = 0;
  int& ri = i;
  EXPECT_EQ(true/*true or false*/, typeid(i) == typeid(ri));
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
TEST(about_references, sizeof_returns_size_of_referenced_type) {

  // if you fail on this question, repeat koans in area 'characters'
  EXPECT_EQ(__, sizeof(char));

  EXPECT_EQ(__, sizeof(char&));

  char c;
  char& rc = c;
  EXPECT_EQ(__, sizeof c);
  EXPECT_EQ(__, sizeof rc);
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
TEST(about_references, decltype) {

  // always answer with true or false

  // tiny intro to std::is_reference in case you don't know it yet
  EXPECT_EQ(__, std::is_reference<int>::value);
  EXPECT_EQ(__, std::is_reference<int&>::value);

  int i = 0;
  int& ri = i;
  int fi();
  int& fri();

  EXPECT_EQ(__, std::is_reference<decltype(i)>::value);
  EXPECT_EQ(__, std::is_reference<decltype(ri)>::value);

  EXPECT_EQ(__, std::is_reference<decltype((i))>::value);
  EXPECT_EQ(__, std::is_reference<decltype((ri))>::value);

  EXPECT_EQ(__, std::is_reference<decltype(42)>::value);
  EXPECT_EQ(__, std::is_reference<decltype(fi())>::value);
  EXPECT_EQ(__, std::is_reference<decltype(fri())>::value);
}

// References are not objects, and because of that, there are no references to
// references, no arrays of references and no pointers to references.
//
// TStd14 8.3.2/5 References [decl.ref]
TEST(about_references, a_reference_is_not_an_object)
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
TEST(about_references, a_reference_always_refers_to_the_same_object)
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
TEST(about_references, a_reference_must_be_initialized_with_a_valid_object_and_cannot_be_null)
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
namespace dummy1 {
static std::string events;
struct A { ~A() { events += ",~A"; } };
struct B { ~B() { events += ",~B"; } };
A makeA() { static A a; return a; }
B makeB() { static B b; return b; }
TEST(about_references, reference_extends_lifetime_of_temporary)
{
  // remember that calling a function which returns by value (opposed to
  // return by reference) creates a temporary.

  {
    makeA();
    events += ",foo";
    const B& rb = makeB();
    events += ",bar";
  }

  EXPECT_EQ(std::string(____), events);
}
}

// cppref http://en.cppreference.com/w/cpp/language/reference_initialization
//   ... if the reference is either rvalue reference or lvalue reference to
//   const:
//   - ...
//   - If object is a class type expression (that is not reference-related to
//     T and (since C++17)) that can be implicitly converted to an xvalue, a
//     class prvalue, or a function value of type that is either T or derived
//     from T, equally or less cv-qualified, then the reference is bound to
//     the result of the conversion or to its base subobject. (User-defined
//     conversions are not considered (since C++17))
//   - Otherwise, a temporary of type T is constructed and copy-initialized
//     from object. The reference is then bound to this temporary.
//     Copy-initialization rules apply (explicit constructors are not
//     considered).
namespace dummy2 {
static std::string events;
struct A {
  ~A() { events += ",~A"; }
};
struct B {
  B(const A&) { }
  ~B() { events += ",~B"; }
};
TEST(about_references, reference_initialized_with_object_needing_implicit_conversion)
{
  // using explicit type for reference
  {
    A a;
    events += ",foo";
    const B& r = a;
    events += ",bar";
    EXPECT_EQ(__,
      reinterpret_cast<const void*>(&a) == reinterpret_cast<const void*>(&r));
  }
  EXPECT_EQ(std::string(____), events);

  // exactly the same but for using auto for reference type
  events.clear();
  {
    A a;
    events += ",foo";
    const auto& r = a;
    events += ",bar";
    EXPECT_EQ(__, &a == &r);
  }
  EXPECT_EQ(std::string(____), events);
}
}

#if 0

// There are actually two kinds of references (three in C++11): lvalue ("plain")
// references and const references. This koan is about lvalue references.
//
// TC++PL4 7.7.1 Lvalue References
//   The initializer for a "plain" T& [opposed to const T&] must be an lvalue of
//   type T.
TEST(about_references,the_initializer_for_an_lvalue_reference_must_be_an_lvalue)
{
#if 0
  int i1 = 2;
  int& ri1 = i1; // ok

  const int ci2 = 3;
  // int& ri2 = ci; // compile error, ci is not an lvalue

  // int& ri3 = 42; // compile error, 42 is not an lvalue

  // int& ri4 = 2 * i2; // compile error, the expression '2 * i2' is not an lvalue

  float f = 3.1415;
  // double& rd = f; // compile error, f is not of type double

  // contrast this koan with the next
#endif
  EXPECT_TRUE(_________);//	acknowledge you understood this koan
}

// About initializing const references
//
// TC++PL4 7.7.1 Lvalue References
//   The initializer for a const T& need not to be an lvalue [of type T] or even
//   of type T. In such cases
//   1) First, implicit type conversion to T is applied if neccessairy
//   2) Then, the resulting value is placed in a temporary variable of type T
//   3) Finally, this temporary is used as the value [i.e. the object] of the
//      initializer
TEST(about_references,initializing_const_references)
{
  // contrast this koan with the previous

  int i1 = 3;
  const int& cri1 = i1; //ok

  const int ci2 = 3;
  const int& cri2 = ci2; // ok

  const int& cri3 = 42; // ok. 42 is put into a temporary object, and the
                        // reference is then initialized to refer to that
                        // temporary object

  const int& cri4 = 2 * i1; // ok. The result of the expression '2 * i1' is put
                            // into a temporary object, and the reference is
                            // then initialized to refer to that temporary
                            // object

  float f = 3.1415;
  const double& crd = f; // ok. f is implicitely converted to double. The result
                         // is put into a temporary object, and the reference is
                         // then initialized to refer to that temporary object.
                         // Note that crd refers to the temporary, _not_ to f!

  EXPECT_TRUE(_________);//	acknowledge you understood this koan
}

// Regarding write access, the difference between 'T&' (lvalue refence) and
// 'const T&' (const reference) is the same as between 'T*' and 'const T*'. 'T&'
// allows to change the refered object whereas 'const T&' does not.
TEST(about_references,object_refered_to_by_const_reference_cannot_be_modified)
{
}


// Where to place const qualifier?
//
// ISO/IEC 14882-2003 8.3.2 References
//   Cv-qualified references are ill-formed except when the cv-qualifiers are
//   introduced through the use of a typedef (7.1.3) or of a template type
//   argument (14.3), in which case the cv-qualifiers are ignored.
typedef int& intref;
TEST(about_references,where_to_place_const_qualifier)
{
#if 0
  int i = 0;
  const int& ri1 = i;
  ri1 = 1; // compile eror
  int const & ri2 = i; // same thing as const int &
  ri2 = 2; // compile error

  int& const ri3 = i; // compile error
#endif
  int i4 = 0;
  intref const ri4 = i4; // ok, contrary to the above example, since int& having
                         // to be const was introduced through the use of a
                         // typedef. The const is ignored.
  ri4 = 4;               // ok, since the const was ignored

  EXPECT_TRUE(_________);//	acknowledge you understood this koan
}

// A temporary created to hold a reference initializer persists until the end
// of its reference's scope. [I.e. a const reference that is destructed, when
// it refers to a temporary object, also destructs that temporary object].

// References to invalid objects. E.g. function returning a reference to a local
// object. Or a collection returning a reference to internal data, and the
// refernce is used after the object has been deleted (the Umweg via collection
// is not needed, its just a typical case). The same is true for pointers, so
// put it into a separate koan? Or simply have the topic at multiple places?
// Humans learn by repetition...

// Difference pointer ref
// - ref cannot be NULL, i.e. use ptr when null is a possible value. This can be
//   an advantage (no nullptr checks necessairy) or an disadvantage (sometimes
//   you want to allow the scenario that there is no object)
// - ref allow for natural expressions like foo(a) or a + b (opposed to foo(&a)
//   or &a + &b respectively )
// - pointer must not neccessairly be initialized
// -

#endif
