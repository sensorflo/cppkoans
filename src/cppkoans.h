#include "gtest/gtest.h"

static const int            __ = 123456; 
static const double         ___ = 123.456; 
static const char* const    ____ = "123456"; 
static const wchar_t* const _____ = L"123456"; 
static const char           ______ = '@'; 
static const wchar_t        _______ = L'@'; 

#define KOAN_AREA(area) TEST(area,DISABLED_dummy) {}
