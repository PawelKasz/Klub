
#include "gtest/gtest.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "../lib/skrzydlo.h"
#include "../lib/dialog.h"
#include "qapplication.h"
#include "qdebug.h"

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
    auto result = punkt.GetPoczatek2Ver();

    // assert
    EXPECT_EQ(result.x, 0);
    EXPECT_EQ(result.y, 300);
}

TEST(Skrzydlo, PoczatekPionowegoPlataPrzesunietegoMinus50)
{
    // arrange
    skrzydlo punkt({-50, 50}, 300, 0);
    // act
    auto result = punkt.GetPoczatek2Ver();
    // assert
    EXPECT_EQ(result.x, -50);
    EXPECT_EQ(result.y, 350);
}

TEST(Skrzydlo,PoczPozPlat10dgr)
{
    // arrange
    skrzydlo punkt({0, 0}, 300, 10);
    // act
    auto result = punkt.GetPoczatek2Ver();
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
    skrzydlo punkt({0, 0}, 300, 225);
    // act
    auto result = punkt.GetPoczatek2Ver();
    // assert
    EXPECT_EQ(result.x, -212);
}

TEST(Skrzydlo, PoczatekObruconegoKat45DegMinus212)
{
    // arrange
    skrzydlo punkt({0, 0}, 300, 45);
    // act
    auto result = punkt.GetPoczatek2Ver();

    // assert
    EXPECT_EQ(result.x, 212);
    EXPECT_EQ(result.y, 212);
}


TEST(Skrzydlo, DISABLED_WypiszWartosciCalegoZakresuKatow)
{

    // arrange
    skrzydlo punkt({0, 0}, 300, 0);

    // act
    for(int i{0}; i<360; ++i)
    {
        punkt.setKat(i);
        auto result = punkt.GetPoczatek2Ver();
        // qDebug() << "[kat, x,y] = " << i << ", " << result.x << ", " << result.y;
        std::cout << "[kat, x,y] = " << i << ", " << result.x << ", " << result.y << std::endl << std::flush;
    }

    // assert
    // EXPECT_EQ(result.x, 212);
    // EXPECT_EQ(result.y, 212);
}

TEST(Skrzydlo, PoczatekKat0Dlugosc300)
{
    // arrange
    skrzydlo punkt({0, 0}, 300, 0);

    // act
    punkt.setKat(0);
    auto result = punkt.GetPoczatek2Ver();

    // assert
    EXPECT_EQ(result.x, 0);
    EXPECT_EQ(result.y, 300);
}

TEST(Skrzydlo, PoczatekKat0Dlugosc200)
{
    // arrange
    skrzydlo punkt({0, 0}, 200, 0);

    // act
    punkt.setKat(0);
    auto result = punkt.GetPoczatek2Ver();

    // assert
    EXPECT_EQ(result.x, 0);
    EXPECT_EQ(result.y, 200);
}

TEST(Skrzydlo, KoniecKat0Dlugosc300)
{
    int const dlugosc_poczatku = 300;
    int const dlugosc_konca = dlugosc_poczatku * 1.6;

    // arrange
    skrzydlo punkt({0, 0}, dlugosc_poczatku, 0);

    // act
    punkt.setKat(0);
    auto result = punkt.GetKoniec();

    // assert
    EXPECT_EQ(result.x, 0);
    EXPECT_EQ(result.y, -dlugosc_konca);
}

TEST(Skrzydlo, KoniecKat0Dlugosc200)
{
    int const dlugosc_poczatku = 200;
    int const dlugosc_konca = dlugosc_poczatku * 1.6;

    // arrange
    skrzydlo punkt({0, 0}, dlugosc_poczatku, 0);

    // act
    punkt.setKat(0);
    auto result = punkt.GetKoniec();

    // assert
    EXPECT_EQ(result.x, 0);
    EXPECT_EQ(result.y, -dlugosc_konca);
}


TEST(Skrzydlo, KoniecKat45Dlugosc300)
{
    int const dlugosc_poczatku{ 300};
    int const dlugosc_konca = dlugosc_poczatku * 1.6;
    int const kat_obrotu{45};


    int poz_x = dlugosc_konca * sin(qDegreesToRadians(kat_obrotu + 180));
    int poz_y = dlugosc_konca * cos(qDegreesToRadians(kat_obrotu + 180));

    // arrange
    skrzydlo punkt({0, 0}, dlugosc_poczatku, kat_obrotu);

    // act
    auto result = punkt.GetKoniec();

    // assert
    EXPECT_EQ(result.x, poz_x);
    EXPECT_EQ(result.y, poz_y);

    EXPECT_LT(result.x, 0); // LT Mniejsze niz.
    EXPECT_LT(result.y, 0); //
}

TEST(Skrzydlo, KoniecKat135Dlugosc300)
{
    int const dlugosc_poczatku{ 300};
    int const dlugosc_konca = dlugosc_poczatku * 1.6;
    int const kat_obrotu{135};


    int poz_x = dlugosc_konca * sin(qDegreesToRadians(kat_obrotu + 180));
    int poz_y = dlugosc_konca * cos(qDegreesToRadians(kat_obrotu + 180));

    // arrange
    skrzydlo punkt({0, 0}, dlugosc_poczatku, kat_obrotu);

    // act
    auto result = punkt.GetKoniec();

    // assert
    EXPECT_EQ(result.x, poz_x);
    EXPECT_EQ(result.y, poz_y);

    EXPECT_LT(result.x, 0); // LT Mniejsze niz.
    EXPECT_GT(result.y, 0); //
}

TEST(Skrzydlo, KoniecKat225Dlugosc300)
{
    int const dlugosc_poczatku{ 300};
    int const dlugosc_konca = dlugosc_poczatku * 1.6;
    int const kat_obrotu{225};


    int poz_x = dlugosc_konca * sin(qDegreesToRadians(kat_obrotu + 180));
    int poz_y = dlugosc_konca * cos(qDegreesToRadians(kat_obrotu + 180));

    // arrange
    skrzydlo punkt({0, 0}, dlugosc_poczatku, kat_obrotu);

    // act
    auto result = punkt.GetKoniec();

    // assert
    EXPECT_EQ(result.x, poz_x);
    EXPECT_EQ(result.y, poz_y);

    EXPECT_GT(result.x, 0); // LT Mniejsze niz.
    EXPECT_GT(result.y, 0); //
}

TEST(Skrzydlo, WspolrzedneKat0Dlugosc300)
{
    int const dlugosc_poczatku{ 300};
    int const dlugosc_konca = dlugosc_poczatku * 1.6;
    int const kat_obrotu{0};

    int poz_x = dlugosc_konca * sin(qDegreesToRadians(kat_obrotu + 180));
    int poz_y = dlugosc_konca * cos(qDegreesToRadians(kat_obrotu + 180));

    // arrange
    skrzydlo punkt({0, 0}, dlugosc_poczatku, kat_obrotu);

    // act
    auto resultPoczatek = punkt.GetPoczatek2Ver();
    auto resultKoniec = punkt.GetKoniec();

    // assert
    EXPECT_EQ(resultPoczatek.x, 0);
    EXPECT_EQ(resultPoczatek.y, 300);

    EXPECT_EQ(resultKoniec.x, poz_x);
    EXPECT_EQ(resultKoniec.y, poz_y);


    EXPECT_EQ(resultPoczatek.x, 0);
    EXPECT_EQ(resultKoniec.x, 0);

    EXPECT_GT(resultPoczatek.y, 0);
    EXPECT_LT(resultKoniec.y, 0);
}

TEST(Skrzydlo, WspolrzedneKat90Dlugosc300)
{
    int const dlugosc_poczatku{ 300};
    int const dlugosc_konca = dlugosc_poczatku * 1.6;
    int const kat_obrotu{90};

    int poz_x = dlugosc_konca * sin(qDegreesToRadians(kat_obrotu + 180));
    int poz_y = dlugosc_konca * cos(qDegreesToRadians(kat_obrotu + 180));

    // arrange
    skrzydlo punkt({0, 0}, dlugosc_poczatku, kat_obrotu);

    // act
    auto resultPoczatek = punkt.GetPoczatek2Ver();
    auto resultKoniec = punkt.GetKoniec();

    // assert
    EXPECT_EQ(resultPoczatek.x, 300);
    EXPECT_EQ(resultPoczatek.y, 0);

    EXPECT_EQ(resultKoniec.x, poz_x);
    EXPECT_EQ(resultKoniec.y, poz_y);

    EXPECT_EQ(resultPoczatek.y, 0);
    EXPECT_EQ(resultKoniec.y, 0);

    EXPECT_GT(resultPoczatek.x, 0);
    EXPECT_LT(resultKoniec.x, 0);
}
TEST(Skrzydlo, WspolrzedneKat400Dlugosc300)
{
    int const dlugosc_poczatku{ 300};
    int const dlugosc_konca = dlugosc_poczatku * 1.6;
    int const kat_obrotu{400};

    int poz_x = dlugosc_konca * sin(qDegreesToRadians(kat_obrotu + 180));
    int poz_y = dlugosc_konca * cos(qDegreesToRadians(kat_obrotu + 180));

    // arrange
    skrzydlo punkt({0, 0}, dlugosc_poczatku, kat_obrotu);

    // act
    auto resultPoczatek = punkt.GetPoczatek2Ver();
    auto resultKoniec = punkt.GetKoniec();

    // assert
    EXPECT_GT(resultPoczatek.y, 0);
    EXPECT_LT(resultKoniec.y, 0);

    EXPECT_GT(resultPoczatek.x, 0);
    EXPECT_LT(resultKoniec.x, 0);
}

TEST(Skrzydlo, WspolrzedneKatMinus10Dlugosc300)
{
    int const dlugosc_poczatku{ 300};
    int const dlugosc_konca = dlugosc_poczatku * 1.6;
    int const kat_obrotu{-10};

    int poz_x = dlugosc_konca * sin(qDegreesToRadians(kat_obrotu + 180));
    int poz_y = dlugosc_konca * cos(qDegreesToRadians(kat_obrotu + 180));

    // arrange
    skrzydlo punkt({0, 0}, dlugosc_poczatku, kat_obrotu);

    // act
    auto resultPoczatek = punkt.GetPoczatek2Ver();
    auto resultKoniec = punkt.GetKoniec();

    // assert
    EXPECT_GT(resultPoczatek.y, 0);
    EXPECT_LT(resultKoniec.y, 0);

    EXPECT_LT(resultPoczatek.x, 0);
    EXPECT_GT(resultKoniec.x, 0);
}

TEST(dialog, Przeliczenie_x_y){

    // arrange
    int argc{1};
    char **argv{nullptr};
    QApplication program(argc, argv);

    skrzydlo punkt({0, 0}, 300, 45);
    Wiatr wia;
    Dialog ob(&punkt, &wia);

    // act
    auto cieciwa = punkt.GetCieciwa();
    auto result = ob.ConvertToQtCoords(cieciwa);

    //assert

    EXPECT_EQ(cieciwa.poczatek.x, result.poczatek.x);
    EXPECT_EQ(cieciwa.koniec.x, result.koniec.x);

    EXPECT_EQ(cieciwa.poczatek.y, -result.poczatek.y);
    EXPECT_EQ(cieciwa.koniec.y, -result.koniec.y);

}


TEST(strzalka, ramka_poz){

    // arrange

    // act

    // assert
}

std::vector<int> Kopiuj(std::vector<int> const  &in)
{
    // int pierwszy = in.at(1);

    std::vector<int> rezultat{in};
    for(auto &i: in)
    {
        rezultat.push_back(i);
    }

    return rezultat;
}


TEST(KopiowanieTablicy, Test01)
{
    const std::vector<int> wejsciowy {1};

    const std::vector<int> oczekiwany {1,1};

    auto resultat = Kopiuj(wejsciowy);

    EXPECT_EQ(resultat, oczekiwany);
}


TEST(KopiowanieTablicy, Test02)
{
    const std::vector<int> wejsciowy {1,2};

    const std::vector<int> oczekiwany {1,2,1, 2};

    auto resultat = Kopiuj(wejsciowy);

    EXPECT_EQ(resultat, oczekiwany);
}

TEST(KopiowanieTablicy, Test03)
{
    const std::vector<int> wejsciowy {1,2, 3, 4};

    const std::vector<int> oczekiwany {1,2,3, 4, 1, 2, 3, 4};

    auto resultat = Kopiuj(wejsciowy);

    EXPECT_EQ(resultat, oczekiwany);
}

