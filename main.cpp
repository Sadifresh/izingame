#include "TXLib.h"


struct Button
{
    int x;
    int y;
    int w;
    int h;
    const char* text;
    bool visible;

    void draw()
    {
    txSetColor (TX_WHITE, 2);
    txSetFillColor (TX_RED);
    Win32::RoundRect (txDC(), x, y, x+w, y+h, 30, 30);
    txSelectFont("Courier", 20);
    txDrawText(x, y, x+w, y+h, text);
    }

    bool click()
    {
        return (txMouseX()>x && txMouseX()<x+w &&
                txMouseY()>y && txMouseY()<y+h &&
                txMouseButtons() == 1 && visible);


    }

};


int main()
{
txCreateWindow (1500, 750);
txTextCursor (false);

string PAGE = "menu";

Button btn = {180, 110, 200, 100, "Старт", true};
Button btn1 = {180, 220, 200, 100, "Правила", true};
Button btn2 = {180, 330, 200, 100, "Об авторе", true};
Button btn3 = {180, 440, 200, 100, "Выход", true};


    while(!btn3.click())
    {
        txClear();
        txBegin();
//меню
        if(PAGE == "menu")
        {
            btn.draw();
            btn1.draw();
            btn2.draw();
            btn3.draw();


            btn.visible=true;
            btn1.visible=true;
            btn2.visible=true;
            btn3.visible=true;




            if(btn.click())
            {
                while(btn.click()) txSleep(50);
                PAGE = "game";
                btn.visible=false;
                btn1.visible=false;
                btn2.visible=false;
                btn3.visible=false;


            }




            if(btn1.click())
            {
                while(btn1.click()) txSleep(50);
                PAGE = "rules";
                btn.visible=false;
                btn1.visible=false;
                btn2.visible=false;
                btn3.visible=false;

            }

            if(btn2.click())
            {
                while(btn2.click()) txSleep(50);
                PAGE = "about";
                btn.visible=false;
                btn1.visible=false;
                btn2.visible=false;
                btn3.visible=false;

            }

        txSetFillColor (TX_BLACK);

       }








//Правила
        if(PAGE == "rules")
        {
            txSetColor (TX_BLACK);
            txTextOut(0, 0, "Страница правил");
            if(GetAsyncKeyState(VK_ESCAPE))
            {
                PAGE = "menu";
            }
            txSetFillColor (TX_WHITE);
        }

//О программе

        if(PAGE == "about")
        {
            txSetColor (TX_BLACK);
            txTextOut(0, 0, "ОБ АВТОРЕ");
            if(GetAsyncKeyState(VK_ESCAPE))
            {
                PAGE = "menu";
            }
            txSetFillColor (TX_GREEN);
        }

//Игра
        if(PAGE == "game")
        {
            txSetColor (TX_BLACK);
            if(GetAsyncKeyState(VK_ESCAPE))
            {
                PAGE = "menu";
            }
            txSetFillColor (TX_WHITE);
            txLine(1,645,1500,645);
            txLine(13,645,120,750);
            txLine(120,750,285,645);
            txLine(285,645,395,750);
            txLine(395,750,555,645);
            txLine(555,645,665,750);
            txLine(665,750,820,645);
            txLine(820,645,935,750);
            txLine(935,750,1085,645);
            txLine(1085,645,1205,750);
            txLine(1205,750,1360,645);
            txLine(1360,645,1470,750);
            txLine(1470,750,1500,718);
            txLine(1,370,1500,370);
            txRectangle(165,370,280,280);
            txRectangle(565,370,680,280);
            txRectangle(565+400,370,680+400,280);
            txRectangle(565+700,370,680+700,280);

        }




    txEnd();
    txSleep(10);
    }





    txDisableAutoPause();

    return 0;
}
