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
HDC fon = txLoadImage("Безымянный.bmp")

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
            txTextOut(200, 50, "Пожалуйста подождите...");
            if(GetAsyncKeyState(VK_ESCAPE))
            {
                PAGE = "menu";
            }
            txSetFillColor (TX_YELLOW);
        }




    txEnd();
    txSleep(10);
    }





    txDisableAutoPause();

    return 0;
}
