#include "gtest/gtest.h"
#include <iostream>
#include <typeinfo>

struct dummytype {};

// don't use only a single underscore since that is used already by gmock. They
// put it into the testing namespace, but cppkoans makes 'using namespace
// testing'.
const int            __ = 123456; 
const double         ___ = 123.456; 
const char* const    ____ = "123456"; 
const wchar_t* const _____ = L"123456"; 
const char           ______ = '@'; 
const wchar_t        _______ = L'@'; 
typedef dummytype    ________;
const void* const    _________ = "123456";
#define              __________

/** Pass variables which otherwise would make the compiler output warnings about
unreferenced variables.*/ 
inline void DontWarnAboutUnreferencedVars(...) {}

::std::ostream& operator<<(::std::ostream& os, const std::type_info& ti);

#define KOAN_AREA(area) TEST(area,DISABLED_dummy) {}

// http://sourceforge.net/p/predef/wiki/Compilers 

// GCC
// ===
// http://gcc.gnu.org/projects/cxx0x.html. assuming to compile with -std=c++11
#if defined(__GNUC__)
  // ! only works for C++11 features !
  #define __VERSION_LARGER_THAN(version,minor)    \
    ((__GNUC__*100 + __GNUC_MINOR__ >= version*100 + minor) && \
     (__cplusplus>201103L))

  #define __HAS_TYPE_LONG_LONG  __VERSION_LARGER_THAN(4,3) 

// Clang
// =====
// http://clang.llvm.org/cxx_status.html
#elif defined(__clang__)
  // ! only works for C++11 features !
  #define __VERSION_LARGER_THAN(version,minor)    \
    ((__clang_major__*100+__clang_minor__ >= version*100 + minor) && \
     (__cplusplus>201103L))

  #define __HAS_TYPE_LONG_LONG  __VERSION_LARGER_THAN(2,9)

// MSVC
// ====
// msvc 2012: http://msdn.microsoft.com/en-us/library/b0084kay(v=vs.110).aspx
// 
// product        _MSC_VER
// 9.0  (2008)	  1500	
// 10.0 (2010)	  1600	
// 11.0 (2012)	  1700	
// 12.0 (2013)	  1800
#elif defined(_MSC_VER)
  #define __YEAR_TO_MSC_VER(year)                                     \
    (year==2013 ? 1800 : (year==2012 ? 1700 : (year==2010 ? 1600 : 1500)))
  #define __VERSION_LARGER_THAN(year)                                 \
    (_MSC_VER>=__YEAR_TO_MSC_VER(year))

  #define __HAS_TYPE_LONG_LONG __VERSION_LARGER_THAN(2010)

// assume C++11 or C++98 standard conforming
// http://sourceforge.net/p/predef/wiki/Standards/
// 
// name   __cplusplus      standard
// C++98	199711L	         ISO/IEC 14882:1998
// C++11	201103L	         ISO/IEC 14882:2011
#else
  #define __YEAR_TO_CPLUSPLUS(year) (year==98 ? 199711L : 201103L)
  #define __VERSION_LARGER_THAN(year) (_cplusplus>=__YEAR_TO_CPLUSPLUS(year))

  #define __HAS_TYPE_LONG_LONG __VERSION_LARGER_THAN(11) // N1811

#endif
