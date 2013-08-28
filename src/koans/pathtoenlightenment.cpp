#include "cppkoans.h"

// You walk the path to enlightenment by meditating on the following koan areas
// in the given order. Note that not listing a koan area (aka test case) here
// still runs the koan area, it's just that then the order is undefined.

KOAN_AREA(about_asserts)
KOAN_AREA(about_strings)
KOAN_AREA(about_arrays)

// Implementation notice: In the build step of the build process, the
// pathtoenlightenment object file must be linked before all the koan object
// files. In the end it's about trying to define the order in which global
// static variables are initialized. Behind gtest's TEST macro is a global
// static variable initialization, and the order of those initializations
// defines the order of the test cases and the order of the tests within a test
// case. Actually C++ standard defines that order of global static variable
// initialization is undefined. However in practice with most compiler & linkers
// it's the order in which the compiler sees the statements and the order in
// which the linker sees the object files. For msvc, I don't know how to define
// the order in which the linker sees the object files, but so for by sheer luck
// it's the intended one.
//
// Unfortunately gtest does not allow to explicitly define the order in which
// test cases are executed, because in the automated testing world it is
// considered a bad idea to rely on the order in which tests are executed.

