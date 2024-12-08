
#include "gtest/gtest.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "../lib/skrzydlo.h"

using namespace testing;

TEST(SuiteName, CaseName)
{
    skrzydlo obj;

    auto result = obj.GetPoczatek();

    EXPECT_EQ(result.x, -1);
    EXPECT_EQ(result.y, -1);
    // EXPECT_EQ(1, 1);
}
