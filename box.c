#include<graphics.h>
#include<stdio.h>

void drawbox()
{
    int i,inc;

    floodfill(0,0,WHITE);

    setcolor(GREEN);

    rectangle(30,30,570,570);
    rectangle(29,29,571,571);
    rectangle(28,28,572,572);
    rectangle(27,27,573,573);


    line(30,210,570,210);
    line(30,210+1,570,210+1);


    line(30,210+180,570,210+180);
    line(30,211+180,570,211+180);


    line(210,30,210,570);
    line(211,30,211,570);

    line(210+180,30,210+180,570);
    line(211+180,30,211+180,570);

    setlinestyle(DOTTED_LINE,1,1);
    for(i=0,inc=90;i<8;++i,inc+=60)
        line(30,inc,570,inc);

    for(i=0,inc=90;i<8;++i,inc+=60)
        line(inc,30,inc,570);
}


/*int main()
{
    drawbox();
    getch();
}*/
