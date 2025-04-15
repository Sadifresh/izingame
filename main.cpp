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

struct Done
{
      int x;
      int y;
      int w;
      int h;
      HDC image;
      HDC run_left;
      HDC run_right;
      HDC run_forward;
      HDC run_back;
      //HDC kill;
      int n_cadr;
      bool visible;

      void draw()
      {
        if(visible==true)
        txTransparentBlt(txDC(), x, y, w, h ,image, n_cadr*98, 0, TX_WHITE);
      }

    void animation()
    {
        n_cadr += 1;
        if (n_cadr >= 3)
        {
            n_cadr = 0;
        }
    }

};

struct Vag
{
    int x;
    int y;
    HDC image;
    int n_cadr;
    bool visible;

    void draw()
    {
        if(visible==true)
        txTransparentBlt(txDC(), x, y, 100, 113 ,image, n_cadr*100, 0, TX_WHITE);
    }

    void animation()
    {
        n_cadr += 1;
        if (n_cadr >= 3)
        {
            n_cadr = 0;
        }
    }

};

struct Knife
{
    int x;
    int y;
    HDC image;
    bool visible;
    int v;
    bool exists;

    void draw()
      {
        if(visible==true)
        txTransparentBlt(txDC(), x, y, 100, 20 ,image, 0, 0, TX_WHITE);
      }
};


struct Box
{
    int x;
    int y;
    int w;
    int h;
    HDC image;
    bool visible;

    void draw()
      {
        txTransparentBlt(txDC(), x, y, w, h ,image, 0, 0, TX_WHITE);
      }
};

int main()
{
txCreateWindow (1366, 768);
txTextCursor (false);

int n_cadr = 0;

Done done = {600,  768, 98, 172,
                txLoadImage("Images/run_forward_cadr.bmp"),
                txLoadImage("Images/run_left_cadr.bmp"),
                txLoadImage("Images/run_right_cadr.bmp"),
                txLoadImage("Images/run_forward_cadr.bmp"),
                txLoadImage("Images/run_back_cadr.bmp"), 0, true};


Vag vag = {1400, 650, txLoadImage("Images/vag.bmp"), 0, true};

Knife knife = {0, 0, txLoadImage("Images/knife.bmp"), false, 0};
int count_box = 12;
Box box[count_box];
box[0] = {700, 600, 148, 141,  txLoadImage("Images/box3.bmp")};
box[1] = {1400, 600, 143, 142,  txLoadImage("Images/box4.bmp")};
box[2] = {2100, 600+72, 75, 72,  txLoadImage("Images/box1.bmp")};
box[3] = {2800, 600, 73, 143, txLoadImage("Images/box2.bmp")};
box[4] = {3500, 600, 148, 141,  txLoadImage("Images/box3.bmp")};
box[5] = {4200, 600+72, 75, 72,  txLoadImage("Images/box1.bmp")};
box[6] = {4900, 600, 73, 143, txLoadImage("Images/box2.bmp")};
box[7] = {5600, 600, 143, 142,  txLoadImage("Images/box4.bmp")};
box[8] = {6300, 600, 73, 143, txLoadImage("Images/box2.bmp")};
box[9] = {7000, 600, 148, 141,  txLoadImage("Images/box3.bmp")};
box[10] = {7700, 600, 143, 142,  txLoadImage("Images/box4.bmp")};
box[11] = {8400, 600+72, 75, 72,  txLoadImage("Images/box1.bmp")};


string PAGE = "menu";

Button btn = {180, 110, 200, 100, "Старт", true};
Button btn1 = {180, 220, 200, 100, "Правила", true};
Button btn2 = {180, 330, 200, 100, "Об авторе", true};
Button btn3 = {180, 440, 200, 100, "Выход", true};

HDC Fon = txLoadImage("Images/Fone.bmp");
HDC Done = txLoadImage("Images/Done.bmp");
HDC Vag = txLoadImage("Images/vda.bmp");
int x_fon = 0;

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
            txBitBlt(txDC(), 0, 0, 1366, 768,Vag);
            txTextOut(100, 0, "Страница правил");
            txTextOut(750,250,"Правила:");
            txTextOut(430,280,"1.нельзя всё время стрелять в туннели если противники так и не вышли ");
            txTextOut(430,295,"2.нельзя поменять вид лица (игра идет от 1 лица)");
            txTextOut(430,310,"3.новое оружие будет падать с монстров иначе его заполучить нельзя");
            txTextOut(430,325,"4. нельзя использовать какие-либо баффы");
            txTextOut(415,340,"5. если ты погиб то тебе нельзя будет продолжить, только начать новую игру");

            if(GetAsyncKeyState(VK_ESCAPE))
            {
                PAGE = "menu";
            }
            txSetFillColor (TX_WHITE);
        }

//О программе

        if(PAGE == "about")
        {
            txBitBlt(txDC(), 0, 0, 1500, 750, Done);
            txSetColor (TX_BLACK);
            txTextOut(100, 0, "ОБ АВТОРЕ");
            txTextOut(315, 200, "Автор Александр, остальное тебе не надо");
            txTextOut(315, 215, "пароль 1654");
            txTextOut(315, 230, "что обо мне да обо мне");
            txTextOut(315,245,"говори свои данные");



            if(GetAsyncKeyState(VK_ESCAPE))
            {
                PAGE = "menu";
            }
            txSetFillColor (TX_WHITE);
        }

//Игра
        if(PAGE == "game")
        {
            txSetColor (TX_BLACK);
            if(GetAsyncKeyState(VK_ESCAPE))
            {
                PAGE = "menu";
            };

            txBitBlt(txDC(), x_fon, 0, 10852, 750, Fon);
            done.draw();
            knife.draw();
            for(int i=0; i<count_box; i++)
            {
                box[i].draw();
            }
            done.image = done.run_right;

            if(GetAsyncKeyState('D'))
            {
                 x_fon -= 10;
                 for(int i=0; i<count_box; i++)
                 {
                    box[i].x -= 10;
                 }
                 done.image = done.run_right;
                 done.animation();
                 txSleep(10);

            };

            if(GetAsyncKeyState('A'))

            {
                 x_fon +=10;
                 for(int i=0; i<count_box; i++)
                 {
                    box[i].x += 10;
                 }
                 done.image = done.run_left;
                 done.animation();
                 txSleep(10);
                 if(x_fon>0) x_fon=0;
            }

             if(GetAsyncKeyState('W'))

             {
                while(GetAsyncKeyState('W'))   txSleep(10);

                done.image = done.run_right;
                done.y -= 250;
             }

            if(done.y < 0)
            {
                done.y =  0;
            }

            done.y += 40;                                    //гравитация

            if(done.y > 600)                               //уровень земли
            {
                done.y =  600;
                //done.image = done.run_right;
            }


            vag.draw();
            vag.animation();
            vag.x -= 10;
            if(vag.x<0)
            {
                vag.x = 1200;
                vag.visible=true;
            }

            if(!done.visible)
            {
                txSleep(1000);
                PAGE = "menu";
            }

            if(vag.visible && vag.x<done.x+98 && vag.x+100>done.x && vag.y>done.y && vag.y+113<done.y+172)
            {
                done.visible=false;
            }

            knife.x+=knife.v;
            if(GetAsyncKeyState('S'))
            {
               knife.x = done.x+70;
               knife.y = done.y+70;
               knife.visible = true;
               knife.v = 50;
            }

            if(knife.visible && knife.x<vag.x+98 && knife.x+100>vag.x && knife.y>vag.y && knife.y+20<vag.y+113)
            {
                vag.visible=false;
                knife.visible=false;
                vag.x = -100;
            }
  //done.image == done.kill


            for(int i=0; i<count_box; i++)
            { /*
              if(done.x+done.w>box[i].x && done.x<box[i].x+box[i].w && done.y<box[i].y+box[i].h && done.y+done.h>box[i].y)
              {
                done.visible = false;
              } */
              if(done.x+done.w>box[i].x && done.x<box[i].x+box[i].w && done.y+done.h>box[i].y-5)
              {
                done.y=box[i].y-180;
              }
          }
        }











    txEnd();
    txSleep(50);
    }


txDeleteDC(Fon);


txDisableAutoPause();
return 0;
}
