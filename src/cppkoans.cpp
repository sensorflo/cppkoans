/*
cppkoans: learn C++ by little exercises
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

#include "gtest/gtest.h"
using namespace testing;

class StopOnFirstFailureListener : public EmptyTestEventListener {
  virtual void OnTestEnd(const TestInfo& test_info) {
    if (test_info.result()->Failed()) {
      exit(1);
    }
  }
};

int main(int argc, char* argv[])
{
  InitGoogleTest(&argc, argv);

  TestEventListeners& listeners =
      ::UnitTest::GetInstance()->listeners();
  listeners.Append(new StopOnFirstFailureListener);
  
  return RUN_ALL_TESTS();
}

