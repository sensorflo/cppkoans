#include "cppkoans.h"

// Operator precedence, together with operator associativity, determines in
// which order the operators of an expression are executed. The web page
// http://en.cppreference.com/w/cpp/language/operator_precedence lists all
// operators after their precedence. As an extract, the following operators are
// listed in order of their precedence, highest first: * + ==. Thus e.g.:
//
// 3+4*5==35  is equivalent to  ((3+(4*5))==35)
// 
// Or put differently:
// (remaining) expression   executed operator
// 3+4*5==35                *
// 3+20==35                 +
// 23==35                   ==
// false 
// 
// TC++PL 10.3 Operator summary
// 
// http://en.wikipedia.org/wiki/Operator_precedence
TEST(about_expressions,operator_precedence_define_which_operator_among_operators_with_different_precedence_is_performed_first)
{

}

// Operator associativity determines in which order operators of the same
// precedence are executed. 
// 
// Left associative: 3+1+4+1 is equivalent to (((3+1)+4)+1)
// 
// Right associative: a=b=c=d is equivalent to (a=(b=(c=d)))
// 
// TC++PL 10.3 Operator summary
// 
// http://en.wikipedia.org/wiki/Operator_associativity
TEST(about_expressions,foo)
{
  
}

// overwrite (or clarify) with parenthesis

// TC++PL 10.3.2 order of evaluation
//   The order of evaluation of subexpressions within an expression is
//   undefined. In particular, you cannot assume that the expression is
//   evaluated left-to-right.
TEST(about_expressions,foo3)
{

}

