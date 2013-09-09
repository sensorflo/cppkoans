#include "gtest/gtest.h"

/** A GTest printer for cppkoans */
class KoanGTestPrinter :
  public ::testing::EmptyTestEventListener
{
public:
  KoanGTestPrinter();

private:
  virtual void OnTestProgramStart(const ::testing::UnitTest&);
  virtual void OnTestEnd(const ::testing::TestInfo&);
  virtual void OnTestProgramEnd(const ::testing::UnitTest&);

  /** Number of runned & passed tests aka koans.
  UnitTest::successful_test_count() apparently also counts tests that not yet*/
  int m_PassedKoansCount;
};
