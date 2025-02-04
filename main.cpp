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
    txTransparentBlt(txDC(), x, y, w, h , 0, 0, TX_WHITE);
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
      HDC image_run1;
      HDC image_run2;
      HDC image_walk1;
      HDC image_walk2;

      void draw()
      {
        txTransparentBlt(txDC(), x, y, w, h ,image, 0, 0, TX_WHITE);
      }

};




int main()
{
txCreateWindow (1500, 750);
txTextCursor (false);

Done done = {0, 164, 100, 100, txLoadImage("Done_run1.bmp"), txLoadImage("Done_run1.bmp"), txLoadImage("Done_run2.bmp"), txLoadImage("Done_walk1.bmp"), txLoadImage("Done_walk2.bmp")};

string PAGE = "menu";

Button btn = {180, 110, 200, 100, "�����", true};
Button btn1 = {180, 220, 200, 100, "�������", true};
Button btn2 = {180, 330, 200, 100, "�� ������", true};
Button btn3 = {180, 440, 200, 100, "�����", true};

HDC Fon = txLoadImage("Pictures/Fon.bmp");
HDC Done = txLoadImage("Pictures/Done.bmp");

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
            txLine(0,475,410,370);
            txLine(0,620,630,370);
            txLine(365,645,860,370);
            txLine(800,645,1080,370);
            txLine(1160,645,1310,370);
            txLine(1445,645,1500,475);
            txRectangle(165,370,280,280);
            txRectangle(565,370,680,280);
            txRectangle(565+400,370,680+400,280);
            txRectangle(565+700,370,680+700,280);
            */

            txBitBlt(txDC(), 0, 0, 1500, 750, Fon);


        }





    txEnd();
    txSleep(10);
    }


    txDeleteDC(Fon);


    txDisableAutoPause();

    return 0;
}
