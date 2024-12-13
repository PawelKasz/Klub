
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

TEST(Skrzydlo, PoczatekPoziomegoPlataWMinus300)
{
    // arrange
    skrzydlo punkt({0, 0}, 300, 0);
    // act
    auto result = punkt.GetPoczatek();
    // assert
    EXPECT_EQ(result.x, -300);
    EXPECT_EQ(result.y, 0);
}

TEST(Skrzydlo, PoczatekPoziomegoPlataPrzesunietegoMinus50)
{
    // arrange
    skrzydlo punkt({-50, 50}, 300, 0);
    // act
    auto result = punkt.GetPoczatek();
    // assert
    EXPECT_EQ(result.x, -350);
    EXPECT_EQ(result.y, 0);
}

TEST(Skrzydlo,PoczPozPlat10dgr)
{
    // arrange
    skrzydlo punkt({0, 0}, 300, 10);
    // act
    auto result = punkt.GetPoczatek();
    // assert
    EXPECT_EQ(result.x, 52);
    EXPECT_EQ(result.y, 295);
}

TEST(Skrzydlo,PoczPozPlat10dgrV2)
{
    // arrange
    skrzydlo punkt({0, 0}, 300, 10);
    // act
    auto result = punkt.GetPoczatek2Ver();
    // assert
    EXPECT_EQ(result.x, 52);
    EXPECT_EQ(result.y, 295);
}

TEST(Skrzydlo,PoczPozPlat45dgrV2)
{
    // arrange
    skrzydlo punkt({0, 0}, 300, 45);
    // act
    auto result = punkt.GetPoczatek2Ver();
    // assert
    EXPECT_EQ(result.x, 212);
    EXPECT_EQ(result.y, 212);
}

TEST(Skrzydlo,PoczPozPlat80dgrV2)
{
    // arrange
    skrzydlo punkt({0, 0}, 300, 80);
    // act
    auto result = punkt.GetPoczatek2Ver();
    // assert
    EXPECT_EQ(result.x, 295);
    EXPECT_EQ(result.y, 52);
}

TEST(Skrzydlo,PoczPozPlat100dgrV2)
{
    // arrange
    skrzydlo punkt({0, 0}, 300, 100);
    // act
    auto result = punkt.GetPoczatek2Ver();
    // assert
    EXPECT_EQ(result.x, 295);
    EXPECT_EQ(result.y, -52);
}

TEST(Skrzydlo,PoczPozPlat135dgrV2)
{
    // arrange
    skrzydlo punkt({0, 0}, 300, 135);
    // act
    auto result = punkt.GetPoczatek2Ver();
    // assert
    EXPECT_EQ(result.x, 212);
    EXPECT_EQ(result.y, -212);
}

TEST(Skrzydlo,PoczPozPlat170dgrV2)
{
    // arrange
    skrzydlo punkt({0, 0}, 300, 170);
    // act
    auto result = punkt.GetPoczatek2Ver();
    // assert
    EXPECT_EQ(result.x, 52);
    EXPECT_EQ(result.y, -295);
}

TEST(Skrzydlo,PoczPozPlat190dgrV2)
{
    // arrange
    skrzydlo punkt({0, 0}, 300, 190);
    // act
    auto result = punkt.GetPoczatek2Ver();
    // assert
    EXPECT_EQ(result.x, -52);
    EXPECT_EQ(result.y, -295);
}

TEST(Skrzydlo,PoczPozPlat225dgrV2)
{
    // arrange
    skrzydlo punkt({0, 0}, 300, 225);
    // act
    auto result = punkt.GetPoczatek2Ver();
    // assert
    EXPECT_EQ(result.x, -212);
    EXPECT_EQ(result.y, -212);
}

TEST(Skrzydlo,PoczPozPlat315dgrV2)
{
    // arrange
    skrzydlo punkt({0, 0}, 300, 315);
    // act
    auto result = punkt.GetPoczatek2Ver();
    // assert
    EXPECT_EQ(result.x, -212);
    EXPECT_EQ(result.y, 212);
}

TEST(Skrzydlo,PoczPozPlat225dgr)
{
    // arrange
    skrzydlo punkt1({0, 0}, 300, 225);
    // act
    auto result = punkt1.GetPoczatek();
    // assert
    EXPECT_EQ(result.x, 212);

}

TEST(Skrzydlo, PoczatekObruconegoKat45DegMinus212)
{
    // arrange
    skrzydlo punkt({0, 0}, 300, 45);
    // act
    auto result = punkt.GetPoczatek();

    // assert
    EXPECT_EQ(result.x, 212);
    EXPECT_EQ(result.y, 212);
}

TEST(Skrzydlo, PoczatekKont90Deg)
{
    // arrange
    skrzydlo punkt({0, 0}, 300, 175);
    // act
    auto result = punkt.GetPoczatek();
    // assert
    EXPECT_EQ(result.x, 26);
    EXPECT_EQ(result.y, -298);
}


