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
      HDC image;
      HDC run_left;
      HDC run_right;
      HDC run_forward;
      HDC run_back;
      int n_cadr;

      void draw()
      {
        txTransparentBlt(txDC(), x, y, 98, 172 ,image, n_cadr*98, 0, TX_WHITE);
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

    void draw()
    {
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



int main()
{
txCreateWindow (1366, 768);
txTextCursor (false);

int n_cadr = 0;

Done done = {600,  768,
                txLoadImage("Images/run_forward_cadr.bmp"),
                txLoadImage("Images/run_left_cadr.bmp"),
                txLoadImage("Images/run_right_cadr.bmp"),
                txLoadImage("Images/run_forward_cadr.bmp"),
                txLoadImage("Images/run_back_cadr.bmp"), 0};


Vag vag = {1400, 650, txLoadImage("Images/vag.bmp"), 0};

string PAGE = "menu";

Button btn = {180, 110, 200, 100, "�����", true};
Button btn1 = {180, 220, 200, 100, "�������", true};
Button btn2 = {180, 330, 200, 100, "�� ������", true};
Button btn3 = {180, 440, 200, 100, "�����", true};

HDC Fon = txLoadImage("Images/Fone.bmp");
HDC Done = txLoadImage("Images/Done.bmp");
HDC Vag = txLoadImage("Images/vda.bmp");
int x_fon = 0;

    while(!btn3.click())
    {
        txClear();
        txBegin();
//����
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









//�������
        if(PAGE == "rules")
        {
            txSetColor (TX_BLACK);
            txBitBlt(txDC(), 0, 0, 1366, 768,Vag);
            txTextOut(100, 0, "�������� ������");
            txTextOut(750,250,"�������:");
            txTextOut(430,280,"1.������ �� ����� �������� � ������� ���� ���������� ��� � �� ����� ");
            txTextOut(430,295,"2.������ �������� ��� ���� (���� ���� �� 1 ����)");
            txTextOut(430,310,"3.����� ������ ����� ������ � �������� ����� ��� ���������� ������");
            txTextOut(430,325,"4. ������ ������������ �����-���� �����");
            txTextOut(415,340,"5. ���� �� ����� �� ���� ������ ����� ����������, ������ ������ ����� ����");

            if(GetAsyncKeyState(VK_ESCAPE))
            {
                PAGE = "menu";
            }
            txSetFillColor (TX_WHITE);
        }

//� ���������

        if(PAGE == "about")
        {
            txBitBlt(txDC(), 0, 0, 1500, 750, Done);
            txSetColor (TX_BLACK);
            txTextOut(100, 0, "�� ������");
            txTextOut(315, 200, "����� ���������, ��������� ���� �� ����");
            txTextOut(315, 215, "������ 1654");
            txTextOut(315, 230, "��� ��� ��� �� ��� ���");
            txTextOut(315,245,"������ ���� ������");



            if(GetAsyncKeyState(VK_ESCAPE))
            {
                PAGE = "menu";
            }
            txSetFillColor (TX_WHITE);
        }

//����
        if(PAGE == "game")
        {
            txSetColor (TX_BLACK);
            if(GetAsyncKeyState(VK_ESCAPE))
            {
                PAGE = "menu";
            };

            txBitBlt(txDC(), x_fon, 0, 10852, 750, Fon);
            done.draw();
            done.image = done.run_forward;

            if(GetAsyncKeyState('D'))
            {
                 x_fon -= 10;
                 done.image = done.run_right;
                 done.animation();
                 txSleep(10);

            }

            if(GetAsyncKeyState('A'))

            {
                 x_fon +=10;
                 done.image = done.run_left;
                 done.animation();
                 txSleep(10);
                 if(x_fon>0) x_fon=0;
            }

            done.y += 80;                                    //����������

            if(done.y > 600)                               //������� �����
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
            }





        }











    txEnd();
    txSleep(50);
    }


txDeleteDC(Fon);


txDisableAutoPause();
return 0;
}
