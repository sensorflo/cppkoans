#include "gtest/gtest.h"
#include <iostream>
#include <typeinfo>

struct dummytype {};

const int            __ = 123456; 
const double         ___ = 123.456; 
const char* const    ____ = "123456"; 
const wchar_t* const _____ = L"123456"; 
const char           ______ = '@'; 
const wchar_t        _______ = L'@'; 
typedef dummytype    ________;
const int            _________ = 0;
const void* const    __________ = "123456";

/** Pass variables which otherwise would make the compiler output warnings about
unreferenced variables.*/ 
inline void DontWarnAboutUnreferencedVars(...) {};

::std::ostream& operator<<(::std::ostream& os, const std::type_info& ti);

#define KOAN_AREA(area) TEST(area,DISABLED_dummy) {}
