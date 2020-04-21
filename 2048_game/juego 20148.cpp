// i use headers from windows, so, this code only compile on windows c:
// enjoy c:, i believe :D
#include<time.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int mat[102][102];
bool vs[102][102];
int ax,ay;
bool bs=true;
void mapa()
{
    for(int c=1; c<=66; c++)
    {
        cout<<'-';
    }
    cout<<"\n";
    for(int c=1; c<=4; c++)
    {
        for(int d=1; d<=4;d++)
        {
            cout<<'|';
            if(mat[c][d]==0)
            {
                cout<<"\t \t";
            }
            else
            cout<<"\t"<<mat[c][d]<<"\t";
        }
     cout<<'|';
        cout<<"\n";
            for(int h=1; h<=66; h++)
                {
                    cout<<'-';
                }
                cout<<"\n";
    }
}
bool NotGame()
{
        int vx[]={-1,0,1,0};
        bool ban=false;
        for(int c=1; c<=4; c++)
        {
            for(int d=1; d<=4; d++)
            {
                for(int h=0; h<4; h++)
                {
                    pair<int,int>hijo;
                    hijo.first=(c+vx[h]);
                    hijo.second=(d+vx[(h+1)%4]);
                    if(hijo.first>=1 && hijo.first<=4 && hijo.second>=1 && hijo.second<=4)
                    {
                        if(mat[hijo.first][hijo.second]==mat[c][d] ||mat[hijo.first][hijo.second]==0)
                        {
                            ban=true;
                        }
                    }
                }
            }
        }
        if(!ban)
            return false;
        return true;
}
void random()
{
    srand(time(NULL));
    for(int c=1; c<=4; c++)
    {
        for(int d=1; d<=4; d++)
        {
            if(mat[c][d]==NULL)
            {
                    int n=rand()%5;
                    if(n==2 || n==4 && c==ax && d==ay)
                    {
                        mat[c][d]=n;
                        ax=c,ay=d;
                       // ban=true;
                        return;
                    }

            }
        }
    }
}
bool win()
{
    for(int c=1; c<=4; c++)
    {
        for(int d=1; d<=4; d++)
        {
            if(mat[c][d]==2048)
                return true;
        }
    }
    return false;
}
void up()
{
    for(int c=1; c<=4; c++)
    {
        for(int d=4; d>=2; d--)
        {
            if((mat[d][c]==mat[d-1][c] || mat[d-1][c]==0))//) && !vs[d-1][c])
            {
                mat[d-1][c]+=mat[d][c];
                vs[d-1][c]=true;
                mat[d][c]=0;

            }
        }
        for(int d=4; d>=2; d--)
        {
            if(mat[d][c]!=0 && mat[d-1][c]==0)
            {
                swap(mat[d][c],mat[d-1][c]);
            }
        }
    }
       /* for(int c=1; c=4; c++)
        {
            for(int d=1; d<=4; d++)
            {
                vs[c][d]=false;
            }
        }*/
}
void down()
{
    for(int c=1; c<=4; c++)
    {
        for(int d=1; d<4; d++)
        {
            if((mat[d][c]==mat[d+1][c] || mat[d+1][c]==0))// && !vs[d+1][c])
            {
                mat[d+1][c]+=mat[d][c];
                vs[d+1][c]=true;
                mat[d][c]=0;
            }
        }
        for(int d=1; d<4; d++)
        {
            if(mat[d][c]!=0 && mat[d+1][c]==0)
            {
                swap(mat[d][c],mat[d+1][c]);
            }
        }
    }
       /* for(int c=1; c=4; c++)
        {
            for(int d=1; d<=4; d++)
            {
                vs[c][d]=false;
            }
        }*/
}
void left()
{
    for(int c=1; c<=4; c++)
    {
        for(int d=4; d>=2; d--)
        {
            if((mat[c][d]==mat[c][d-1] || mat[c][d-1]==0 ))// && !vs[c][d-1])
            {
                mat[c][d-1]+=mat[c][d];
                vs[c][d-1]=true;
                mat[c][d]=0;
            }
        }
        for(int d=4; d>=2; d--)
        {
            if(mat[c][d]!=0 && mat[c][d-1]==0)
            {
                swap(mat[c][d],mat[c][d-1]);
            }
        }
    }
   /* for(int c=1; c=4; c++)
        {
            for(int d=1; d<=4; d++)
            {
                vs[c][d]=false;
            }
        }*/
}
void rigth()
{
    for(int c=1; c<=4; c++)
    {
        for(int d=1; d<4; d++)
        {
            if((mat[c][d]==mat[c][d+1] || mat[c][d+1]==0 ))// && !vs[c][d+1])
            {
                mat[c][d+1]+=mat[c][d];
                vs[c][d+1]=true;
                mat[c][d]=0;
            }
        }
        for(int d=1; d<4; d++)
        {
            if(mat[c][d]!=0 && mat[c][d+1]==0)
            {
                swap(mat[c][d],mat[c][d+1]);
            }
        }
    }
    /*for(int c=1; c=4; c++)
        {
            for(int d=1; d<=4; d++)
            {
                vs[c][d]=false;
            }
        }*/
}
main ()
{
    int key=NULL;
   while(NotGame())
   {
       if(bs)
       random();
       bool bs=true;
       mapa();
       int bas=getch();
       switch(getch())
       {
           case 72:
            up();
            break;
           case 77:
            rigth();
            break;
           case 80:
            down();
            break;
           case 75:
            left();
            break;
           default:

               bs=false;
            break;
       }
       if(win())
       {
           cout<<"Felicidades Fin del juego";
           system("pause");
           return 0;
       }
       system("cls");

   }
   cout<<"Perdiste zorro";
   system("pause");
   return 0;
}
