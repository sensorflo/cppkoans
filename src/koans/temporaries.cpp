#include "cppkoans.h"
#include <iostream>
using namespace std;

// Resources on references: 
// - TC++PL4 10.3.4 Temporary Objects
// - "More Effective C++", Scott Meyers. Item 19: "Understand the origin of
//   temporary Objects"

// TC++PL4 10.3.4 Temporary Objects
//   Often, the compiler must introduce an object to hold an intermediate result
//   of an expression. For example, for v=x+y*z the result of y*z has to be put
//   somewhere before it is added to x... Unless bound to a reference ... a
//   temporary object is destroyed at the end of the full expression in which it
//   was created.
//
//   A temporary can be used as an initializer for a const reference ... The
//   temporary is destroyed when "its" reference ... goes out of scope.
// 
//   Same for named object.
//   !!! test !!!! with ctor signature a) by value b) by lvalue ref c) by const ref
//   1) another type than temporary 2) same type as temporary
// 
//   Remember that a returning a reference to a local variable is an error
//   ($12.1.4) and that a temporary object cannot be bound to a non-const lvalue
//   reference ($7.7).
//
//   A temporary object can also be created explicitely in an expression by
//   invoking a constructor ($11.5.1).
//
//
//  When a temporary is used to init an object 'C c = 1 + 2', the
//  temporary and the object are actually the same object; there is no actual
//  copy ctor call. If the object is a variable, then look at it as giving the
//  temporary a name. Note that in C(C(C())) only one object, the temporary
//  created by the innermost C() is created. All other 'objects' are actually
//  the same object we started with in the beginning. Or has that todo with
//  return value optimization? Note that I implicitely compile with -O0.
//  http://stackoverflow.com/questions/1758142/why-copy-constructor-is-not-called-in-this-case
//  --> When certain criteria are met, an implementation is allowed to omit the
//  copy/move construction of a class object, even if the copy/move constructor
//  and/or destructor for the object have side effects.
//  --> This elision of copy/move operations, called copy elision (http://en.wikipedia.org/wiki/Copy_elision)
//  --> direct-initialization 
//  Also happens when signature is foo(C) and I call with foo(C())? I.e. no copy
//  ctor call?
//
//  - Function call (that naturally includes operators) return value 
//  - Explicit ctor call (somewhat the same as the previous point??, merge it???)
//  - Ctor or conversion operator can be called implicitely for implicit type
//    conversion, which takes place e.g.
//      - To initialize a const ref, e.g. args to a function
//
// A temporary object is often refered to as just a temporary.

// typedef void callback_t();

// struct C {
//   C(callback_t& callback) : _callback(callback) {};
//   ~C() {callback();}
//   callback_t& _callback;
// };

struct E {
  E() : id(cnt++) { cout << "E <" << id << "> " << this << "\n"; }
  E(const E&) : id(cnt++) { cout << "E(const E&) <" << id << "> " << this << "\n"; }
  ~E() { cout << "~E <" << id << "> " << this << "\n"; }
  int id;
  static int cnt;
};  
int E::cnt;

struct D {
  D() : id(cnt++),geil(33) { cout << "D <" << id << ">\n"; }
  D(int i) : id(cnt++),geil(i) { cout << "D(int) <" << id << ">\n"; }
  // D(E e) : m_e(e), id(cnt++) { cout << "D(E) <" << id << ">\n"; }
  // D(const E& e) : m_e(e), id(cnt++) { cout << "D(const E&) <" << id << ">\n"; }
  D(const D& d) : /*m_e(d.m_e),*/ id(cnt++),geil(d.geil) { cout << "D(const DE&) <" << id << ">\n"; }
  ~D() { cout << "~D <" << id << ">\n"; }
  void foo() { cout << "D::foo() <" << id << ">\n"; }
  D operator+(const D& rhs) { return D(geil+rhs.geil); }
  // const E m_e;
  int id;
  int geil;
  static int cnt;
};  
int D::cnt;

D foo() { return D(11); }

TEST(about_temporaries,geilgeil)
{
  cout << "line " << __LINE__ << "\n";
  // D d1 = ;
  // cout << "line " << __LINE__ << "\n";
  D(D(D(D())));
  cout << "line " << __LINE__ << "\n";
  cout << "E::cnt " << E::cnt << "\n";
  cout << "D::cnt " << D::cnt << "\n";
}


// example when a method returns an object (not a reference), e.g. 'C foo()'.
// One can the write 'foo() = ...'; Question to disciple: What is that supposed
// to mean, what happens?

// implicit type conversin happens for const reference but not for lvalue
// reference. Thus
// foo("hello") or foo(s1+s2)
// works for foo(const string&) but not for foo(string&)
//
//
