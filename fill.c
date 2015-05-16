#include<graphics.h>
#include<stdio.h>
void drawbox();

void fill(int a[10][10],int b[10][10],int clr)
{
    drawbox();
    setbkcolor(WHITE);
    setcolor(clr);
    char c[2],i,j;
    settextstyle(4,0,4);
    int x,y;
        for(i=0,y=45;i<9;++i,y+=60)
        {

            for(j=0,x=45;j<9;++j,x+=60)
            {

                if(a[i][j])
                {
                    setcolor(BLACK);
                    c[0]=a[i][j]+48;
                    c[1]='\0';
                    outtextxy(x,y,c);printf("");
                }
                else if(clr==LIGHTGRAY)
                {
                    setcolor(LIGHTGRAY);
                    c[0]=b[i][j]+48;
                    c[1]='\0';
                    outtextxy(x,y,c);printf("");
                }
            }
        }
    getch();

}

