#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<conio.h>
#include<graphics.h>

int a[10][10],ans[10][10];

void drawbox();
void fill(int [10][10],int [10][10],int);
void readsudoku()
{
    int i,j,k;
    char line[25];
    FILE *fin=fopen("input6.txt","r");
    for(i=0;i<9;++i)
    {
        fgets(line,25,fin);
        for(j=0,k=0;j<9;++j)
            ans[i][j]=a[i][j]=line[k++]-48;
    }
}

int place(int n,int p,int q)
{
    int i,j,x,y;
    for(i=0;i<9;++i)
    {
        if(ans[p][i]==n)
            return 0;
    }
    for(i=0;i<9;++i)
    {
        if(ans[i][q]==n)
            return 0;
    }
    x=(p/3)*3; y=(q/3)*3;
    for(i=x;i<x+3;++i)
        for(j=y;j<y+3;++j)
            if(ans[i][j]==n)
                return 0;
    return 1;
}

void print_ans()
{
    int i,j;
    for(i=0;i<9;++i)
    {
        printf("\n");
        for(j=0;j<9;++j)
            printf("%d ",ans[i][j]);
    }
    printf("\n\n");
}

void solve_sudoku(int n)
{
    int p,q,i;
    if(n==81)
    {
        print_ans();
        fill(a,ans,LIGHTGRAY);
        exit(0);
    }
    p=n/9; q=n%9;
    if(ans[p][q]==0)
    {
        for(i=1;i<=9;++i)
        {
            if(place(i,p,q))
            {
                ans[p][q]=i;
                solve_sudoku(n+1);
                ans[p][q]=0;
            }
        }
    }
    else
        solve_sudoku(n+1);
}

int main()
{
    initwindow(600,600,"SU-DO-KU");
    readsudoku();
    print_ans();
    fill(a,ans,BLACK);
    printf("\nThe Solved Su-do-ku:\n");
    solve_sudoku(0);
    getch();
}
