#include "cppkoans.h"

// The point is to have a cheat sheet. You most probably don't need to remember
// the exact members of groupings like 'integral types' or 'arithmetic types'.
// But you should know all the available concrete types (i.e. not a grouping)
// like int, double, array etc. Having this cheat sheet is handy since TStd11,
// TC++PL4 and thus also cppkoans often refer to these groupings.
// 
// Legend
// - @foo reads 'foo types', it means that foo is a grouping of types
// - column headers: @b=@builtin, @s=@scalar
// - cells of b/s columns: X=is member of, -=is _not_ member of, ?=only some of
//   sub-nodes are member of, "=see parent node
// - {...}C++11: enclosed types added in C++11
// 
//                           @b @s keywords / pseudo code
// @fundamental              X  ?  
//   @arithmetic             "  X
//     @integral             "  "
//       @integer            "  "
//         @signed integer   "  "  signed (char, short, int, long {, long long}C++11)
//         @unsigned integer "  "  unsigned (char, short, int, long {, long long}C++11)
//       @character          "  "  char {, char16_t, char32_t, wchar_t}C++11
//       bool                "  "  bool
//     @floating point       "  "  float, double {, long double}C++11
//   void                    "  -  void
//   std::nullptr_t          "  X  {std::nullptr_t}C++11
// @compound                 ?  ?  
//   array                   X  -  T[size]
//   (ordinary) pointer      X  X  T*
//   pointer to member       X  X  T classname::*
//   @reference              X  -  
//     lvalue reference      "  "  T&
//     rvalue reference      "  "  T&&
//   function                X  -  
//   union                   X  -  union name {...}
//   @user-defined           -  ?  
//     class                 "  -  class name {...}, struct name {...}
//     enumeration           "  X  enum name {...}, enum class name {...}
//
//  Notes
//  - the keywords typedef and using define type aliases, not distinct new types
TEST(about_types,cheat_sheet_for_all_available_types_and_often_used_groupings_of_types)
{
  ACKNOWLEDGE( __ );
}

// to be written - TStd11 3.9.3
TEST(about_types,cv_qualifiers)
{
  ACKNOWLEDGE( __ );
}


// The following is only a scratch pad for koan authors
// 
// Types = {fundamental types, compound types} (TStd11 3.9/1)
//
// fundamental types = (TStd11 3.9.1)
//   standard (signed|unsigned) integer types: (unsigned|) (char, short [int],
//     int, long [int], long long [int]) (TStd11 3.9.1/2 3.9.1/3)
//     !!! however excluding char (i.e. only signed|unsigned char is in the list)
//     !!! TC++PL4 does _not_ list any character type here !!!!
//     !!! Thus technically, having a standard, signed/unsigned char is clearly
//     of integer type, but in practice its diffuse whether it is integer or
//     character q!!!!
//   integral types: signed/unsigned integer types, bool, char, char16_t,
//     char32_t, wchar_t (TStd11 3.9.1/7)
//   floating point types: float, double, long double (TStd11 3.9.1/8)
//   void: (TStd11 3.9.1/9)
//   std::nullptr_t: (TStd11 3.9.1/10)
//
//   arithmetic types: integral types, floating types (TStd11 3.9.1/8)
//   extended (signed|unsigned) integer types: implementation defined (TStd11 3.9.1/2 3.9.1/3)
//   (signed|unsigned) integer types: standard (signed|unsigned) integer types,
//     extended (signed|unsigned) integer types (TStd11 3.9.1/2 3.9.1/3)
//
// compound types = (TStd11 3.9.2)
//   arrays
//   functions
//   pointers to void, objects or functions
//   references
//   classes ...
//   unions
//   enumerations
//   pointers to non-static class members
//
// further type groupings, defined in TStd11 3.9
//   scalar types: Arithmetic types (3.9.1), enumeration types, pointer types,
//     pointer to member types (3.9.2), std::nullptr_t, and cv-qualified versions
//     of these types (3.9.3) (TStd11 3.9/9)
//   Incomplete types: incompletely-defined object type, void types (TStd11 3.9/5)
//   POD types: scalar types, POD classes, arrays of such types, and cv-qualified
//     versions of these types (TStd11 3.9/9)
//   trivially copyable types: Scalar types, trivially copyable class types
//     (Clause 9), arrays of such types, and cv-qualified versions of these types
//     (3.9.3)
//   trivial types: Scalar types, trivial class types (Clause 9), arrays of such
//     types and cv-qualified versions of these types (3.9.3).
//   standard-layout types: Scalar types, standard-layout class types (Clause 9),
//     arrays of such types and cv-qualified versions of these types (3.9.3)
//   Aggregate: An aggregate is an array or a class (Clause 9) with no
//     user-provided constructors (12.1), no brace-or-equal-initializers for
//     non-static data members (9.2), no private or protected non-static data
//     members (Clause 11), no base classes (Clause 10), and no virtual functions
//     (10.3). (TStd 8.5.1/1)
//
// Type groupings defined in TC++PL4 6.2.1 but not in TStd11
//   user-defined types: enumerations, classes
//   Built-in types: fundamental types, pointers, references
//     !!! most certainly also the other compound types not being user-defined types
//     are meant to be built-in types !!!!!!
//   character types: char, signed char, unsigned char, wchar_t, char16_t, char32_t
// 
// which of the type groups have a corresponding type trait predicate?
