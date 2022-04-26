#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <wex.h>
#include "cStarterGUI.h"

class cElements
{
public:
    int myCharacter;
    int myPlot;
    int mySetting;
    int myStyle;
    int myPOV;
    int myTheme;
    int myTone;

    cElements();

    std::string genre();

private:
    std::vector<std::vector<int>> myGenreSpecs;
};

cElements theElements;

class cGUI : public cStarterGUI
{
public:
    cGUI()
        : cStarterGUI(
              "Okungbowa's Elements of Fiction",
              {50, 50, 1000, 500}),
          slCharacter(wex::maker::make<wex::slider>(fm)),
          lbCharacter(wex::maker::make<wex::label>(fm)),
          slPlot(wex::maker::make<wex::slider>(fm)),
          lbPlot(wex::maker::make<wex::label>(fm)),
          slSetting(wex::maker::make<wex::slider>(fm)),
          lbSetting(wex::maker::make<wex::label>(fm)),
          slStyle(wex::maker::make<wex::slider>(fm)),
          lbStyle(wex::maker::make<wex::label>(fm)),
          slPOV(wex::maker::make<wex::slider>(fm)),
          lbPOV(wex::maker::make<wex::label>(fm)),
          slTheme(wex::maker::make<wex::slider>(fm)),
          lbTheme(wex::maker::make<wex::label>(fm)),
          slTone(wex::maker::make<wex::slider>(fm)),
          lbTone(wex::maker::make<wex::label>(fm)),
          lbLow(wex::maker::make<wex::label>(fm)),
          lbMid(wex::maker::make<wex::label>(fm)),
          lbHigh(wex::maker::make<wex::label>(fm)),
          lbGenre(wex::maker::make<wex::label>(fm))
    {
        int maxrange = 6;
        int x = 200;
        int y = 50;
        lbLow.move(200,0,200,30);
        lbMid.move(390,0,200,30);
        lbHigh.move(580,0,200,30);
        lbLow.text("Low");
        lbMid.text("Mid");
        lbHigh.text("High");
        slCharacter.move(x, y, 400, 30);
        slCharacter.range(0, maxrange);
        slCharacter.steps();
        lbCharacter.move(50, y + 5, 100, 30);
        lbCharacter.text("Character");
        slCharacter.events().slid(
            [&](int pos)
            {
                theElements.myCharacter = pos;
                slCharacter.position(pos);
                onSlide();
            });
        y += 60;
        slPlot.move(x, y, 400, 30);
        slPlot.range(0, maxrange);
        slPlot.steps();
        lbPlot.move(50, y + 5, 100, 30);
        lbPlot.text("Plot");
        slPlot.events().slid(
            [&](int pos)
            {
                theElements.myPlot = pos;
                onSlide();
            });
        y += 60;
        slSetting.move(x, y, 400, 30);
        slSetting.range(0, maxrange);
        slSetting.steps();
        lbSetting.move(50, y + 5, 100, 30);
        lbSetting.text("Setting");
        slSetting.events().slid(
            [&](int pos)
            {
                theElements.mySetting = pos;
                onSlide();
            });
        y += 60;
        slStyle.move(x, y, 400, 30);
        slStyle.range(0, maxrange);
        slStyle.steps();
        lbStyle.move(50, y + 5, 100, 30);
        lbStyle.text("Style");
        slStyle.events().slid(
            [&](int pos)
            {
                theElements.myStyle = pos;
                onSlide();
            });
        y += 60;
        slPOV.move(x, y, 400, 30);
        slPOV.range(0, maxrange);
        slPOV.steps();
        lbPOV.move(50, y + 5, 100, 30);
        lbPOV.text("POV");
        slPOV.events().slid(
            [&](int pos)
            {
                theElements.myPOV = pos;
                onSlide();
            });
        y += 60;
        slTheme.move(x, y, 400, 30);
        slTheme.range(0, maxrange);
        slTheme.steps();
        lbTheme.move(50, y + 5, 100, 30);
        lbTheme.text("Theme");
        slTheme.events().slid(
            [&](int pos)
            {
                theElements.myTheme = pos;
                onSlide();
            });
        y += 60;
        slTone.move(x, y, 400, 30);
        slTone.range(0, maxrange);
        slTone.steps();
        lbTone.move(50, y + 5, 100, 30);
        lbTone.text("Tone");
        slTone.events().slid(
            [&](int pos)
            {
                theElements.myTone = pos;
                onSlide();
            });

        lbGenre.move(700, 200, 200, 30);
        lbGenre.fontHeight(22);
        lbGenre.text("");

        fm.events().draw(
            [&](PAINTSTRUCT &ps)
            {
                int top = 20;
                int bot = 450;
                int x = 205;
                int xinc = 65;
                wex::shapes S(ps);
                for( int k = 0; k < 7; k++ ) {
                S.line({x, top, x, bot});
                x += xinc;
                }

            });

        show();
        run();
    }

private:
    wex::label &lbCharacter;
    wex::label &lbPlot;
    wex::label &lbSetting;
    wex::label &lbStyle;
    wex::label &lbPOV;
    wex::label &lbTheme;
    wex::label &lbTone;
    wex::label &lbLow;
    wex::label &lbMid;
    wex::label &lbHigh;
    wex::slider &slCharacter;
    wex::slider &slPlot;
    wex::slider &slSetting;
    wex::slider &slStyle;
    wex::slider &slPOV;
    wex::slider &slTheme;
    wex::slider &slTone;
    wex::label &lbGenre;

    void onSlide()
    {
        std::cout << theElements.genre() << "\n";
        lbGenre.text("Genre: " + theElements.genre());
        lbGenre.update();
    }
};

cElements::cElements()
{
    myCharacter = 2;
    myPlot = 2;
    mySetting = 2;
    myStyle = 2;
    myPOV = 2;
    myTheme = 2;
    myTone = 2;
    std::vector<int> vsf{5, 5, 6, 2, 2, 2, 2};
    myGenreSpecs.push_back(vsf);
    std::vector<int> vmy{6, 6, 3, 2, 1, 6, 2};
    myGenreSpecs.push_back(vmy);
}

std::string cElements::genre()
{
    std::cout << theElements.myCharacter
              << " " << theElements.myPlot
              << " " << theElements.mySetting
              << " " << theElements.myStyle
              << " " << theElements.myPOV
              << " " << theElements.myTheme
              << " " << theElements.myTone
              << " => ";

    if (fabs(myCharacter - myGenreSpecs[0][0]) <= 1 &&
        fabs(myPlot - myGenreSpecs[0][1]) <= 1 &&
        fabs(mySetting - myGenreSpecs[0][2]) <= 1 &&
        fabs(myStyle - myGenreSpecs[0][3]) <= 1 &&
        fabs(myPOV - myGenreSpecs[0][4]) <= 1 &&
        fabs(myTheme - myGenreSpecs[0][5]) <= 1 &&
        fabs(myTone - myGenreSpecs[0][6]) <= 1)
        return "Science Fiction";
    if (fabs(myCharacter - myGenreSpecs[1][0]) <= 1 &&
        fabs(myPlot - myGenreSpecs[1][1]) <= 1 &&
        fabs(mySetting - myGenreSpecs[1][2]) <= 1 &&
        fabs(myStyle - myGenreSpecs[1][3]) <= 1 &&
        fabs(myPOV - myGenreSpecs[1][4]) <= 1 &&
        fabs(myTheme - myGenreSpecs[1][5]) <= 1 &&
        fabs(myTone - myGenreSpecs[1][6]) <= 1)
        return "Science Fiction";
    return "unknown";
}

main()
{
    cGUI theGUI;
    return 0;
}
