/*
cppkoans: improve your C++ by little exercises
Copyright (C) 2013 Kaufmann Florian

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program. If not, see <http://www.gnu.org/licenses/>.*/

#include "koangtestprinter.h"
#include "gtest/gtest.h"
#include <list>
using namespace testing;
using namespace std;

extern const char* path_to_enligthenment[];

int main(int argc, char* argv[])
{
  InitGoogleTest(&argc, argv);

  TestEventListeners& listeners =
      ::UnitTest::GetInstance()->listeners();
  delete listeners.Release(listeners.default_result_printer());
  listeners.Append(new KoanGTestPrinter);


  UnitTest::GetInstance()->SetTestCaseOrder(path_to_enligthenment);

  list<string> impl_def_expressions;
  impl_def_expressions.push_back("sizeof(int)");
  impl_def_expressions.push_back("sizeof(bool)");
  impl_def_expressions.push_back("sizeof(bool)==sizeof(int)");
  impl_def_expressions.push_back("int(char(uchar_max))");
  impl_def_expressions.push_back("int(char(std::numeric_limits<unsigned char>::max()))");
  impl_def_expressions.push_back("std::numeric_limits<char>::is_signed");
  impl_def_expressions.push_back("std::numeric_limits<unsigned char>::digits");
  SetImplementationDefinedExpressions(impl_def_expressions);

  return RUN_ALL_TESTS();
}

::std::ostream& operator<<(::std::ostream& os, const std::type_info& ti)
{
  return os << ti.name() << " [the name printed is implementation specific, see std::type_info::name()]";
}
