
#include "gtest/gtest.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "../lib/skrzydlo.h"

using namespace testing;

TEST(Skrzydlo, PozycjaCentralna)
{
    // arrange
    skrzydlo obj({123, 456});

    // act
    auto result = obj.srodek();

    // assert
    EXPECT_EQ(result.x, 123);
    EXPECT_EQ(result.y, 456);
}
