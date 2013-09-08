#include "koangtestprinter.h"
using namespace testing;
using namespace testing::internal;

// kludge to get access to gtest internal stuff which cppkoans finds usefull but
// which gtest did not intend to put on their public interface.
namespace testing {
  namespace internal {  
    enum GTestColor {
      COLOR_DEFAULT,
      COLOR_RED,
      COLOR_GREEN,
      COLOR_YELLOW
    };
    void ColoredPrintf(GTestColor color, const char* fmt, ...);
  }
}

KoanGTestPrinter::KoanGTestPrinter() :
  m_PassedKoansCount(0)
{
}

void KoanGTestPrinter::OnTestEnd(const TestInfo& test_info)
{
  const TestResult& test_result = *test_info.result();

  if (test_result.Passed()) {
    ColoredPrintf(COLOR_GREEN,
      "Koan %s in area %s has expanded your awareness.\n",
      test_info.name(), test_info.test_case_name() );
    m_PassedKoansCount++;

  } else { 
    bool all_unanswered = true;
    for (int i=0; i<test_result.total_part_count(); i++) {
      const TestPartResult& part_result = test_result.GetTestPartResult(i);
      if ( part_result.failed() ) {
        bool answered = strcmp(part_result.summary(),"_")!=0;
        all_unanswered &= !answered;
      } else {
        all_unanswered = false;
        break;
      }
    }

    if (all_unanswered) {
      ColoredPrintf(COLOR_RED,
        "Koan %s in area %s shall be your next step on your path to enlightenment.\n",
        test_info.name(), test_info.test_case_name());
      const TestPartResult& part_result = test_result.GetTestPartResult(0);
      printf("Meditate on the following code:\n");
      printf("%s(%d):\n", part_result.file_name(), part_result.line_number());
    }

    else {
      ColoredPrintf(COLOR_RED,
        "Your answer to koan %s in area %s has damaged your karma.\n",
        test_info.name(), test_info.test_case_name());

      for (int i=0; i<test_result.total_part_count(); i++) {
        const TestPartResult& part_result =
          test_result.GetTestPartResult(i);
      
        if ( part_result.failed() ) {
          const char* summary = part_result.summary();

          if (strcmp(summary,"__schelte__")==0) {
            printf("\nDon't try to cheat me - you will succeed eventually.\n");
            printf("However mind that you will not reach enlightenment by going this path.\n");
            printf("Continue to faithfully meditate on the following code:\n");
            printf("%s(%d):\n", part_result.file_name(), part_result.line_number());
            
          }

          else if (strcmp(summary,"_")==0) {
            printf("\nYou did not yet answer the following question, continue to meditate on it:\n");
            printf("%s(%d):\n", part_result.file_name(), part_result.line_number());
          }

          else {
            printf("\nYour expectation did not match actual reality:\n%s\n",
              summary);
            // the file_name(line_number) format is currently only optimized for
            // msvc, so one can easily jump to the file/line in the IDE by double
            // clicking on that line in the output
            printf("You must continue to meditate on the following code:\n");
            printf("%s(%d):\n", part_result.file_name(), part_result.line_number());
          }
        }
      }
    }

    // Hat's tip to Ara T. Howard for the zen statements from his metakoans
    // Ruby Quiz (http://rubyquiz.com/quiz67.html)
    const char* statement = NULL;
    switch ((m_PassedKoansCount/3) % 6) {
    case 0: statement = "Mountains are merely mountains"; break;
    case 1: statement = "Learn the rules so you know how to break them properly"; break;
    case 2: statement = "Remember that silence is sometimes the best answer"; break;
    case 3: statement = "Sleep is the best meditation"; break;
    case 4: statement = "When you lose, don't lose the lesson"; break;
    default: statement = "Things are not what they appear to be: nor are they otherwise"; 
    }
    printf("\n%s\n",statement);

    printf("Your path to enlightenment thus far: %d of %d koans\n",
      m_PassedKoansCount, UnitTest::GetInstance()->test_to_run_count());
  }
}

void KoanGTestPrinter::OnTestProgramEnd(const UnitTest& unit_test) {
  if ( unit_test.Passed() ) {
    printf("\nYou reached enlightenment! You are now a master yourself and shall guide\n"
      "others on their paths.\n");
  }

  // in case of failure, OnTestEnd already printed all the info and
  // StopOnFirstFailureListener aborted running the koans, i.e. in case of
  // failure we never reach this point
}
