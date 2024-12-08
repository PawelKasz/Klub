
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "../skrzydlo.h"

using namespace testing;

TEST(SuiteName, CaseName)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}
