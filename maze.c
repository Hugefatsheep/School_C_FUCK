//maze.c
#include <stdio.h>
//'2'is the starting point,'4'is the terminal point.
                //   1 2 3 4 5 6 7 8
int maze[10][10]={{1,1,1,1,1,1,1,1,1,1},
        /*1*/     {1,2,0,1,0,0,0,1,0,1},
        /*2*/     {1,0,0,0,0,0,0,1,0,1},
        /*3*/     {1,0,1,1,1,1,1,0,0,1},
        /*4*/     {1,0,0,0,1,0,0,1,0,1},
        /*5*/     {1,0,1,0,1,1,0,0,0,1},
        /*6*/     {1,0,0,1,0,0,0,1,0,1},
        /*7*/     {1,1,0,0,0,1,0,1,1,1},
        /*8*/     {1,0,0,1,0,1,0,0,4,1},
                  {1,1,1,1,1,1,1,1,1,1}};
int qmaze[100][10][10];
int tracex[100];
int tracey[100];
int node=0;

void input(int x,int y,int dp);    //记录当前迷宫状况
void input(int x,int y,int dp)
{
        for(int t=0;t<10;t++)
            for(int z=0;z<10;z++)
                qmaze[dp][t][z]=maze[t][z];
        tracex[dp]=x;
        tracey[dp]=y;

       /* for(int t=0;t<10;t++)
        {
            for(int z=0;z<10;z++)
                printf("%d ",qmaze[dp][t][z]);      //测试用
            printf("\n");
        }*/
}

void judge(int,int);
void judge(int x,int y)
{
    if(maze[x-1][y] == 4 || maze[x][y+1] == 4 || maze[x+1][y] == 4 || maze[x][y-1] == 4)
        printf("Congratulation!Maze done!\n\nThe '8' consist the path!\n");
    else
    {
        if(maze[x-1][y] == 0)
        {
            if(maze[x][y+1] == 0 || maze[x+1][y] ==0 || maze[x][y-1] == 0)
            {
                maze[x-1][y]=9;
                input(x,y,node++);
            }
            maze[x-1][y]=8;
            judge(x-1,y);
        }
        else if(maze[x][y+1] == 0)
        {
            if(maze[x-1][y] == 0 || maze[x+1][y] ==0 || maze[x][y-1] == 0)
            {
                maze[x][y+1]=9;
                input(x,y,node++);
            }
            maze[x][y+1]=8;
            judge(x,y+1);
        }
        else if(maze[x+1][y] == 0)
        {
            if(maze[x][y+1] == 0 || maze[x-1][y] ==0 || maze[x][y-1] == 0)
            {
                maze[x+1][y]=9;
                input(x,y,node++);
            }
            maze[x+1][y]=8;
            judge(x+1,y);
        }
        else if(maze[x][y-1] == 0)
        {
            if(maze[x][y+1] == 0 || maze[x+1][y] ==0 || maze[x-1][y] == 0)
            {
                maze[x][y-1]=9;
                input(x,y,node++);
            }
            maze[x][y-1]=8;
            judge(x,y-1);
        }
        else   //be trapped
        {
            for(int t=0;t<10;t++)
                for(int z=0;z<10;z++)
                    maze[t][z]=qmaze[node-1][t][z];
            node--;
           // printf("%d,%d,%d",tracex[node],tracey[node],node);
            judge(tracex[node],tracey[node]);
        }
    }
}
int main(void)
{
    judge(1,1);

    for(int i=0;i<10;i++)
    {
        for(int t=0;t<10;t++)
        {
            if(maze[i][t] == 9)
                maze[i][t] = 0;
        }
    }

    for(int i=0;i<10;i++)
    {
        for(int t=0;t<10;t++)
            printf("%d ",maze[i][t]);
        printf("\n");
    }
    return 0;
}
