//Rubik's cube
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
int a[6][3][3]={4,1,5,0,0,5,5,4,2,2,4,0,3,1,4,1,0,5,3,2,0,1,2,3,4,0,5,0,5,0,1,3,2,2,5,3,3,2,1,1,4,3,4,0,1,4,2,3,5,5,4,2,3,1};
int i,j,k,m,n,tmp,x,y,r,q=0;
char qq[250];
char c[6][10]={"White","Yellow","Blue","Green","Red","Orange"};
void rotate90minus(int z)                   //Rotation any face 90 degree anti-clockwise
{
    int b[1][3][3];
    for(i=z,j=0,m=2;j<3&&m>=0;m--,j++)
    {
        for(k=0,n=0;k<3&&n<3;n++,k++)
        {
            b[0][j][k]=a[i][n][m];
        }
    }
    for(i=z,j=0;j<3;j++)
    {
        for(k=0;k<3;k++)
        {
            a[i][j][k]=b[0][j][k];
        }
    }
}
void rotate90plus(int z)                    //Rotation any face 90 degree clockwise
{
    int b[1][3][3];
    for(i=z,j=0,m=0;j<3&&m<3;m++,j++)
    {
        for(k=0,n=2;k<3&&n>-1;n--,k++)
        {
            b[0][j][k]=a[i][n][m];
        }
    }
    for(i=z,j=0;j<3;j++)
    {
        for(k=0;k<3;k++)
        {
            a[i][j][k]=b[0][j][k];
        }
    }
}
void right(int repeat)                      //Rotate right layer 90 degree clockwise
{
    for(r=0;r<repeat;r++)
    {
           // cout<<"R\t";
            qq[q]='R';
            q++;

        int tmp[3],rot[4]={2,1,3,0};
        for(i=2,j=0,k=2;j<3;j++)
        {
                tmp[j]=a[i][j][k];
        }
        for(i=0;i<3;i++)
        {
            for(j=0,k=2;j<3;j++)
            {
                if(i==1)
                {
                    x=rot[i],y=rot[i+1];
                    a[x][j][2]=a[y][j][0];
                    ::tmp=a[x][0][2];
                    a[x][0][2]=a[x][2][2];
                    a[x][2][2]=::tmp;
                }
                else if(i==2)
                {
                    x=rot[i],y=rot[i+1];
                    a[x][j][0]=a[y][j][2];
                    ::tmp=a[x][0][0];
                    a[x][0][0]=a[x][2][0];
                    a[x][2][0]=::tmp;
                }
                else
                {
                    x=rot[i],y=rot[i+1];
                    a[x][j][k]=a[y][j][k];
                }
            }
        }
        for(i=0,j=0,k=2;j<3;j++)
        {
                a[i][j][k]=tmp[j];
        }
        rotate90plus(5);
    }
}
void right_prime(int repeat)                //Rotate right layer 90 degree anti-clockwise
{
for(r=0;r<repeat;r++)
{
        //cout<<"Rp\t";
        qq[q]='r';
        q++;

    int tmp[3],rot[4]={2,0,3,1};
    for(i=2,j=0,k=2;j<3;j++)
    {
            tmp[j]=a[i][j][k];
    }
    for(i=0;i<3;i++)
    {
        for(j=0,k=2;j<3;j++)
        {
            if(i==1)
            {
                x=rot[i],y=rot[i+1];
                a[x][j][2]=a[y][j][0];
                ::tmp=a[x][0][2];
                a[x][0][2]=a[x][2][2];
                a[x][2][2]=::tmp;
            }
            else if(i==2)
            {
                x=rot[i],y=rot[i+1];
                a[x][j][0]=a[y][j][2];
                ::tmp=a[x][0][0];
                a[x][0][0]=a[x][2][0];
                a[x][2][0]=::tmp;
            }
            else
            {
                x=rot[i],y=rot[i+1];
                a[x][j][k]=a[y][j][k];
            }
        }
    }
    for(i=1,j=0,k=2;j<3;j++)
    {
            a[i][j][k]=tmp[j];
    }
    rotate90minus(5);
}
}
void left(int repeat)                       //Rotate left layer 90 degree clockwise
{
for(r=0;r<repeat;r++)
{
       // cout<<"L\t";
        qq[q]='L';
        q++;

    int tmp[3],rot[4]={2,0,3,1};
    for(i=2,j=0,k=0;j<3;j++)
    {
            tmp[j]=a[i][j][k];
    }
    for(i=0;i<3;i++)
    {
        for(j=0,k=0;j<3;j++)
        {
            if(i==1)
            {
                x=rot[i],y=rot[i+1];
                a[x][j][0]=a[y][j][2];
                ::tmp=a[x][0][0];
                a[x][0][0]=a[x][2][0];
                a[x][2][0]=::tmp;
            }
            else if(i==2)
            {
                x=rot[i],y=rot[i+1];
                a[x][j][2]=a[y][j][0];
                ::tmp=a[x][0][2];
                a[x][0][2]=a[x][2][2];
                a[x][2][2]=::tmp;
            }
            else
            {
                x=rot[i],y=rot[i+1];
                a[x][j][k]=a[y][j][k];
            }
        }
    }
    for(i=1,j=0,k=0;j<3;j++)
    {
            a[i][j][k]=tmp[j];
    }
    rotate90plus(4);
}
}
void left_prime(int repeat)                 //Rotate left layer 90 degree anti-clockwise
{
for(r=0;r<repeat;r++)
{
        //cout<<"Lp\t";
        qq[q]='l';
        q++;

    int tmp[3],rot[4]={2,1,3,0};
    for(i=2,j=0,k=0;j<3;j++)
    {
            tmp[j]=a[i][j][k];
    }
    for(i=0;i<3;i++)
    {
        for(j=0,k=0;j<3;j++)
        {
            if(i==1)
            {
                x=rot[i],y=rot[i+1];
                a[x][j][0]=a[y][j][2];
                ::tmp=a[x][0][0];
                a[x][0][0]=a[x][2][0];
                a[x][2][0]=::tmp;
            }
            else if(i==2)
            {
                x=rot[i],y=rot[i+1];
                a[x][j][2]=a[y][j][0];
                ::tmp=a[x][0][2];
                a[x][0][2]=a[x][2][2];
                a[x][2][2]=::tmp;
            }
            else
            {
                x=rot[i],y=rot[i+1];
                a[x][j][k]=a[y][j][k];
            }
        }
    }
    for(i=0,j=0,k=0;j<3;j++)
    {
            a[i][j][k]=tmp[j];
    }
    rotate90minus(4);
}
}
void up(int repeat)                         //Rotate top layer 90 degree clockwise
{
for(r=0;r<repeat;r++)
{
        //cout<<"U\t";
        qq[q]='U';
        q++;

    int tmp[3],rot[4]={2,5,3,4};
    for(i=2,j=0,k=0;k<3;k++)
    {
            tmp[k]=a[i][j][k];
    }
    for(i=0;i<3;i++)
    {
        for(j=0,k=0;k<3;k++)
        {
            x=rot[i],y=rot[i+1];
            a[x][j][k]=a[y][j][k];
        }
    }
    for(i=4,j=0,k=0;k<3;k++)
    {
            a[i][j][k]=tmp[k];
    }
    rotate90plus(0);
}
}
void up_prime(int repeat)                   //Rotate top layer 90 degree anti-clockwise
{
for(r=0;r<repeat;r++)
{
        //cout<<"Up\t";
        qq[q]='u';
        q++;

    int tmp[3],rot[4]={2,4,3,5};
    for(i=2,j=0,k=0;k<3;k++)
    {
            tmp[k]=a[i][j][k];
    }
    for(i=0;i<3;i++)
    {
        for(j=0,k=0;k<3;k++)
        {
            x=rot[i],y=rot[i+1];
            a[x][j][k]=a[y][j][k];
        }
    }
    for(i=5,j=0,k=0;k<3;k++)
    {
            a[i][j][k]=tmp[k];
    }
    rotate90minus(0);
}
}
void down(int repeat)                       //Rotate bottom layer 90 degree clockwise
{
for(r=0;r<repeat;r++)
{
        //cout<<"D\t";
        qq[q]='D';
        q++;

    int tmp[3],rot[4]={2,4,3,5};
    for(i=2,j=2,k=0;k<3;k++)
    {
            tmp[k]=a[i][j][k];
    }
    for(i=0;i<3;i++)
    {
        for(j=2,k=0;k<3;k++)
        {
            x=rot[i],y=rot[i+1];
            a[x][j][k]=a[y][j][k];
        }
    }
    for(i=5,j=2,k=0;k<3;k++)
    {
            a[i][j][k]=tmp[k];
    }
    rotate90plus(1);
}
}
void down_prime(int repeat)                 //Rotate bottom layer 90 degree anti-clockwise
{
for(r=0;r<repeat;r++)
{
        //cout<<"Dp\t";
        qq[q]='d';
        q++;

    int tmp[3],rot[4]={2,5,3,4};
    for(i=2,j=2,k=0;k<3;k++)
    {
            tmp[k]=a[i][j][k];
    }
    for(i=0;i<3;i++)
    {
        for(j=2,k=0;k<3;k++)
        {
            x=rot[i],y=rot[i+1];
            a[x][j][k]=a[y][j][k];
        }
    }
    for(i=4,j=2,k=0;k<3;k++)
    {
            a[i][j][k]=tmp[k];
    }
    rotate90minus(1);
}
}
void front(int repeat)                      //Rotate front layer 90 degree clockwise
{
for(r=0;r<repeat;r++)
{
        //cout<<"F\t";
        qq[q]='F';
        q++;

    int tmp[3],rot[4]={4,1,5,0};
    for(i=4,j=0,k=2;j<3;j++)
    {
            tmp[j]=a[i][j][k];
    }
    for(i=0;i<3;i++)
    {
        for(j=0,k=2;j<3;j++)
        {
            if(i==1)
            {
                x=rot[i],y=rot[i+1];
                a[x][0][j]=a[y][j][0];
                ::tmp=a[x][0][0];
                a[x][0][0]=a[x][0][2];
                a[x][0][2]=::tmp;
            }
            else if(i==2)
            {
                x=rot[i],y=rot[i+1];
                a[x][j][0]=a[y][2][j];
            }
            else
            {
                x=rot[i],y=rot[i+1];
                a[x][j][2]=a[y][0][j];
            }
        }
    }
    for(i=0,j=2,m=0,k=2;k>=0;m++,k--)
    {
            a[i][j][m]=tmp[k];
    }
    rotate90plus(2);
}
}
void front_prime(int repeat)                //Rotate front layer 90 degree anti-clockwise
{
for(r=0;r<repeat;r++)
{
        //cout<<"Fp\t";
        qq[q]='f';
        q++;

    int tmp[3],rot[4]={4,0,5,1};
    for(i=4,j=0,k=2;j<3;j++)
    {
            tmp[j]=a[i][j][k];
    }
    for(i=0;i<3;i++)
    {
        for(j=0,k=2;j<3;j++)
        {
            if(i==1)
            {
                x=rot[i],y=rot[i+1];
                a[x][2][j]=a[y][j][0];
            }
            else if(i==2)
            {
                x=rot[i],y=rot[i+1];
                a[x][j][0]=a[y][0][j];
                ::tmp=a[x][0][0];
                a[x][0][0]=a[x][2][0];
                a[x][2][0]=::tmp;
            }
            else
            {
                x=rot[i],y=rot[i+1];
                a[x][j][2]=a[y][2][j];
                ::tmp=a[x][0][2];
                a[x][0][2]=a[x][2][2];
                a[x][2][2]=::tmp;
            }
        }
    }
    for(i=1,j=0,k=0;k<3;k++)
    {
            a[i][j][k]=tmp[k];
    }
    rotate90minus(2);
}
}
void back(int repeat)                       //Rotate back layer 90 degree clockwise
{
for(r=0;r<repeat;r++)
{
        //cout<<"B\t";
        qq[q]='B';
        q++;

    int tmp[3],rot[4]={4,0,5,1};
    for(i=4,j=0,k=0;j<3;j++)
    {
            tmp[j]=a[i][j][k];
    }
    for(i=0;i<3;i++)
    {
        for(j=0,k=2;j<3;j++)
        {
            if(i==1)
            {
                x=rot[i],y=rot[i+1];
                a[x][0][j]=a[y][j][2];
            }
            else if(i==2)
            {
                x=rot[i],y=rot[i+1];
                a[x][j][2]=a[y][2][j];
                ::tmp=a[x][0][2];
                a[x][0][2]=a[x][2][2];
                a[x][2][2]=::tmp;
            }
            else
            {
                x=rot[i],y=rot[i+1];
                a[x][j][0]=a[y][0][j];
                ::tmp=a[x][0][0];
                a[x][0][0]=a[x][2][0];
                a[x][2][0]=::tmp;
            }
        }
    }
    for(i=1,j=2,k=0;k<3;k++)
    {
            a[i][j][k]=tmp[k];
    }
    rotate90plus(3);
}
}
void back_prime(int repeat)                 //Rotate back layer 90 degree anti-clockwise
{
for(r=0;r<repeat;r++)
{
        //cout<<"Bp\t";
        qq[q]='b';
        q++;

    int tmp[3],rot[4]={4,1,5,0};
    for(i=4,j=0,k=0;j<3;j++)
    {
            tmp[j]=a[i][j][k];
    }
    for(i=0;i<3;i++)
    {
        for(j=0,k=2;j<3;j++)
        {
            if(i==1)
            {
                x=rot[i],y=rot[i+1];
                a[x][2][j]=a[y][j][2];
                ::tmp=a[x][2][0];
                a[x][2][0]=a[x][2][2];
                a[x][2][2]=::tmp;
            }
            else if(i==2)
            {
                x=rot[i],y=rot[i+1];
                a[x][j][2]=a[y][0][j];
            }
            else
            {
                x=rot[i],y=rot[i+1];
                a[x][j][0]=a[y][2][j];
            }
        }
    }
    for(i=0,j=0,m=0,k=2;k>=0;m++,k--)
    {
            a[i][j][m]=tmp[k];
    }
    rotate90minus(3);
}
}
void face3()                                //Positions the middle edges
{
    if(a[3][2][1]==4)
    {
        front_prime(1);
        down_prime(1);
        front(1);
        down(1);
        left(1);
        down(1);
        left_prime(1);
    }
    else
    {
        front(1);
        down(1);
        front_prime(1);
        down_prime(1);
        right_prime(1);
        down_prime(1);
        right(1);
    }
}
void face2()                                //Positions the middle edges
{
    if(a[2][2][1]==5)
    {
        back_prime(1);
        down_prime(1);
        back(1);
        down(1);
        right(1);
        down(1);
        right_prime(1);
    }
    else
    {
        back(1);
        down(1);
        back_prime(1);
        down_prime(1);
        left_prime(1);
        down_prime(1);
        left(1);
    }
}
void face5()                                //Positions the middle edges
{
    if(a[5][2][1]==2)
    {
        left(1);
        down(1);
        left_prime(1);
        down_prime(1);
        front_prime(1);
        down_prime(1);
        front(1);
    }
    else
    {
        left_prime(1);
        down_prime(1);
        left(1);
        down(1);
        back(1);
        down(1);
        back_prime(1);
    }
}
void face4()                                //Positions the middle edges
{
    if(a[4][2][1]==3)
    {
        right(1);
        down(1);
        right_prime(1);
        down_prime(1);
        back_prime(1);
        down_prime(1);
        back(1);
    }
    else
    {
        right_prime(1);
        down_prime(1);
        right(1);
        down(1);
        front(1);
        down(1);
        front_prime(1);
    }
}
void layer1_1()                             //Top face - plus formation
{
    int flag,count,brk=0;
    for(count=0,flag=1;brk<100&&count!=4;brk++)
    {
        while(flag!=0)                                                      //Check for white sticker in the top face
        {
            flag=0;
            if(a[0][0][1]==0&&(a[3][0][1]!=a[3][1][1]))
            {
                back(2);
            }
            if(a[0][1][0]==0&&(a[4][0][1]!=a[4][1][1]))
            {
                left(2);
            }
            if(a[0][1][2]==0&&(a[5][0][1]!=a[5][1][1]))
            {
                right(2);
            }
            if(a[0][2][1]==0&&(a[2][0][1]!=a[2][1][1]))
            {
                front(2);
            }
            if(a[1][0][1]==0)                                               //Check for white sticker in the bottom face
            {
                flag=1;
                count++;
                switch(a[2][2][1])
                {
                    case 2: front(2);
                            break;
                    case 3: down(2);
                            back(2);
                            break;
                    case 4: down_prime(1);
                            left(2);
                            break;
                    case 5: down(1);
                            right(2);
                            break;
                }
            }
            if(a[1][1][0]==0)
            {
                flag=1;
                count++;
                switch(a[4][2][1])
                {
                    case 2: down(1);
                            front(2);
                            break;
                    case 3: down_prime(1);
                            back(2);
                            break;
                    case 4: left(2);
                            break;
                    case 5: down_prime(2);
                            right(2);
                            break;
                }
            }
            if(a[1][1][2]==0)
            {
                flag=1;
                count++;
                switch(a[5][2][1])
                {
                    case 2: down_prime(1);
                            front(2);
                            break;
                    case 3: down(1);
                            back(2);
                            break;
                    case 4: down(2);
                            left(2);
                            break;
                    case 5: right(2);
                            break;
                }
            }
            if(a[1][2][1]==0)
            {
                flag=1;
                count++;
                switch(a[3][2][1])
                {
                    case 2: down(2);
                            front(2);
                            break;
                    case 3: back(2);
                            break;
                    case 4: down(1);
                            left(2);
                            break;
                    case 5: down_prime(1);
                            right(2);
                            break;
                }
            }
        }
        if(count!=4)                                             //Check for white sticker in the middle layer and send them to bottom face
        {
            if(a[2][1][2]==0)
            {
                flag=1;
                right_prime(1);
                down_prime(1);
                right(1);
            }
            else if(a[2][1][0]==0)
            {
                flag=1;
                left(1);
                down(1);
                left_prime(1);
            }
            else if(a[5][1][2]==0)
            {
                flag=1;
                back_prime(1);
                down_prime(1);
                back(1);
            }
            else if(a[5][1][0]==0)
            {
                flag=1;
                front(1);
                down(1);
                front_prime(1);
            }
            else if(a[3][1][2]==0)
            {
                flag=1;
                left_prime(1);
                down_prime(1);
                left(1);
            }
            else if(a[3][1][0]==0)
            {
                flag=1;
                right(1);
                down(1);
                right_prime(1);
            }
            else if(a[4][1][2]==0)
            {
                flag=1;
                front_prime(1);
                down_prime(1);
                front(1);
            }
            else if(a[4][1][0]==0)
            {
                flag=1;
                back(1);
                down_prime(1);
                back_prime(1);
            }
            else
            {
                flag=2;
            }
        }
        if(flag==2)                                                 //Check for white sticker in the top layer and send them to middle layer
        {
            if(a[2][0][1]==0)
            {
                front(1);
            }
            else if(a[5][0][1]==0)
            {
                right_prime(1);
            }
            else if(a[3][0][1]==0)
            {
                back(1);
            }
            else if(a[4][0][1]==0)
            {
                left(1);
            }
            else
            {
                flag=3;
            }
        }
        if(flag==3)                                                    //Check for white sticker in the bottom layer and send them to middle layer
        {
            if(a[2][2][1]==0)
            {
                if(a[2][0][1]!=a[2][1][1]||a[0][2][1]!=0)
                {
                    front(1);
                }
                else if(a[3][0][1]!=a[3][1][1]||a[0][0][1]!=0)
                {
                    down(2);
                    back(1);
                }
                else if(a[4][0][1]!=a[4][1][1]||a[0][1][0]!=0)
                {
                    down_prime(1);
                    left(1);
                }
                else if(a[5][0][1]!=a[5][1][1]||a[0][1][2]!=0)
                {
                    down(1);
                    right(1);
                }
            }
            else if(a[3][2][1]==0)
            {
                if(a[2][0][1]!=a[2][1][1]||a[0][2][1]!=0)
                {
                    down(2);
                    front(1);
                }
                else if(a[3][0][1]!=a[3][1][1]||a[0][0][1]!=0)
                {
                    back(1);
                }
                else if(a[4][0][1]!=a[4][1][1]||a[0][1][0]!=0)
                {
                    down(1);
                    left(1);
                }
                else if(a[5][0][1]!=a[5][1][1]||a[0][1][2]!=0)
                {
                    down_prime(1);
                    right(1);
                }
            }
            else if(a[4][2][1]==0)
            {
                if(a[2][0][1]!=a[2][1][1]||a[0][2][1]!=0)
                {
                    down(2);
                    front(1);
                }
                else if(a[3][0][1]!=a[3][1][1]||a[0][0][1]!=0)
                {
                    down_prime(2);
                    back(1);
                }
                else if(a[4][0][1]!=a[4][1][1]||a[0][1][0]!=0)
                {
                    left(1);
                }
                else if(a[5][0][1]!=a[5][1][1]||a[0][1][2]!=0)
                {
                    down_prime(2);
                    right(1);
                }
            }
            else if(a[5][2][1]==0)
            {
                if(a[2][0][1]!=a[2][1][1]||a[0][2][1]!=0)
                {
                    down_prime(1);
                    front(1);
                }
                else if(a[3][0][1]!=a[3][1][1]||a[0][0][1]!=0)
                {
                    down(1);
                    back(1);
                }
                else if(a[4][0][1]!=a[4][1][1]||a[0][1][0]!=0)
                {
                    down(2);
                    left(1);
                }
                else if(a[5][0][1]!=a[5][1][1]||a[0][1][2]!=0)
                {
                    right(1);
                }
            }
        }
    }
    //cout<<"\n\n\n";
}
void layer1_2()                             //Top Corners
{
    int count,flag,brk=0;
    for(count=0,flag=1;count!=4&&brk<10;brk++)
    {
        while(flag!=0)
        {
            flag=0;
            if(a[0][0][0]==0&&a[4][0][0]!=a[4][0][1])                   //Remove wrongly positioned white stickers in the top face to the bottom corners
            {
                back(1);
                down(1);
                back_prime(1);
            }
            if(a[0][0][2]==0&&a[5][0][1]!=a[5][0][2])
            {
                back_prime(1);
                down_prime(1);
                back(1);
            }
            if(a[0][2][0]==0&&a[2][0][0]!=a[2][0][1])
            {
                left(1);
                down(1);
                left_prime(1);
            }
            if(a[0][2][2]==0&&a[2][0][1]!=a[2][0][2])
            {
                right_prime(1);
                down_prime(1);
                right(1);
            }
            if(a[2][2][0]==0)                                   //Positioning the white stickers in the top face from the bottom corner
            {
                flag=1;
                count++;
                switch(a[1][0][0])
                {
                    case 2: down(1);
                            left(1);
                            down_prime(1);
                            left_prime(1);
                            break;
                    case 3: down_prime(1);
                            right(1);
                            down_prime(1);
                            right_prime(1);
                            break;
                    case 4: back(1);
                            down_prime(1);
                            back_prime(1);
                            break;
                    case 5: down(2);
                            front(1);
                            down_prime(1);
                            front_prime(1);
                            break;
                }
            }
            if(a[2][2][2]==0)
            {
                flag=1;
                count++;
                switch(a[1][0][2])
                {
                    case 2: down_prime(1);
                            right_prime(1);
                            down(1);
                            right(1);
                            break;
                    case 3: down(1);
                            left_prime(1);
                            down(1);
                            left(1);
                            break;
                    case 4: down_prime(2);
                            front_prime(1);
                            down(1);
                            front(1);
                            break;
                    case 5: back_prime(1);
                            down(1);
                            back(1);
                            break;
                }
            }
            if(a[5][2][0]==0)
            {
                flag=1;
                count++;
                switch(a[1][0][2])
                {
                    case 2: left(1);
                            down_prime(1);
                            left_prime(1);
                            break;
                    case 3: down(2);
                            right(1);
                            down_prime(1);
                            right_prime(1);
                            break;
                    case 4: down_prime(1);
                            back(1);
                            down_prime(1);
                            back_prime(1);
                            break;
                    case 5: down(1);
                            front(1);
                            down_prime(1);
                            front_prime(1);
                            break;
                }
            }
            if(a[5][2][2]==0)
            {
                flag=1;
                count++;
                switch(a[1][2][2])
                {
                    case 2: down_prime(2);
                            right_prime(1);
                            down(1);
                            right(1);
                            break;
                    case 3: left_prime(1);
                            down(1);
                            left(1);
                            break;
                    case 4: down(1);
                            front_prime(1);
                            down(1);
                            front(1);
                            break;
                    case 5: down_prime(1);
                            back_prime(1);
                            down(1);
                            back(1);
                            break;
                }
            }
            if(a[3][2][0]==0)
            {
                flag=1;
                count++;
                switch(a[1][2][2])
                {
                    case 2: down_prime(1);
                            left(1);
                            down_prime(1);
                            left_prime(1);
                            break;
                    case 3: down(1);
                            right(1);
                            down_prime(1);
                            right_prime(1);
                            break;
                    case 4: down(2);
                            back(1);
                            down_prime(1);
                            back_prime(1);
                            break;
                    case 5: front(1);
                            down_prime(1);
                            front_prime(1);
                            break;
                }
            }
            if(a[3][2][2]==0)
            {
                flag=1;
                count++;
                switch(a[1][2][0])
                {
                    case 2: down(1);
                            right_prime(1);
                            down(1);
                            right(1);
                            break;
                    case 3: down_prime(1);
                            left_prime(1);
                            down(1);
                            left(1);
                            break;
                    case 4: front(1);
                            down(1);
                            front_prime(1);
                            break;
                    case 5: down_prime(2);
                            back_prime(1);
                            down(1);
                            back(1);
                            break;
                }
            }
            if(a[4][2][0]==0)
            {
                flag=1;
                count++;
                switch(a[1][2][0])
                {
                    case 2: down(2);
                            left(1);
                            down_prime(1);
                            left_prime(1);
                            break;
                    case 3: right(1);
                            down_prime(1);
                            right_prime(1);
                            break;
                    case 4: down(1);
                            back(1);
                            down_prime(1);
                            back_prime(1);
                            break;
                    case 5: down_prime(1);
                            front(1);
                            down_prime(1);
                            front_prime(1);
                            break;
                }
            }
            if(a[4][2][2]==0)
            {
                flag=1;
                count++;
                switch(a[1][0][0])
                {
                    case 2: right_prime(1);
                            down(1);
                            right(1);
                            break;
                    case 3: down_prime(2);
                            left_prime(1);
                            down(1);
                            left(1);
                            break;
                    case 4: down_prime(1);
                            front_prime(1);
                            down(1);
                            front(1);
                            break;
                    case 5: down(2);
                            back_prime(1);
                            down(1);
                            back(1);
                            break;
                }
            }
        }
        if(count!=4)                                        //Positioning the white stickers in the bottom corners from the bottom face
        {
            if(a[1][0][0]==0)
            {
                flag=1;
                if(a[0][2][0]!=0||a[2][0][0]!=a[2][0][1])
                {
                    left(1);
                    down_prime(1);
                    left_prime(1);
                }
                else if(a[0][2][2]!=0||a[2][0][2]!=a[2][0][1])
                {
                    down(1);
                    right_prime(1);
                    down(1);
                    right(1);
                }
                else if(a[0][0][2]!=0||a[3][0][0]!=a[3][0][1])
                {
                    down(2);
                    right(1);
                    down_prime(1);
                    right_prime(1);
                }
                else if(a[0][0][0]!=0||a[3][0][2]!=a[3][0][1])
                {
                    down_prime(1);
                    left_prime(1);
                    down(1);
                    left(1);
                }
            }
            else if(a[1][0][2]==0)
            {
                flag=1;
                if(a[0][2][0]!=0||a[2][0][0]!=a[2][0][1])
                {
                    down_prime(1);
                    left(1);
                    down_prime(1);
                    left_prime(1);
                }
                else if(a[0][2][2]!=0||a[2][0][2]!=a[2][0][1])
                {
                    right_prime(1);
                    down(1);
                    right(1);
                }
                else if(a[0][0][2]!=0||a[3][0][0]!=a[3][0][1])
                {
                    down(1);
                    right(1);
                    down_prime(1);
                    right_prime(1);
                }
                else if(a[0][0][0]!=0||a[3][0][2]!=a[3][0][1])
                {
                    down_prime(2);
                    left_prime(1);
                    down(1);
                    left(1);
                }
            }
            else if(a[1][2][0]==0)
            {
                flag=1;
                if(a[0][2][0]!=0||a[2][0][0]!=a[2][0][1])
                {
                    down(1);
                    left(1);
                    down_prime(1);
                    left_prime(1);
                }
                else if(a[0][2][2]!=0||a[2][0][2]!=a[2][0][1])
                {
                    down(2);
                    right_prime(1);
                    down(1);
                    right(1);
                }
                else if(a[0][0][2]!=0||a[3][0][0]!=a[3][0][1])
                {
                    down_prime(1);
                    right(1);
                    down_prime(1);
                    right_prime(1);
                }
                else if(a[0][0][0]!=0||a[3][0][2]!=a[3][0][1])
                {
                    left_prime(1);
                    down(1);
                    left(1);
                }
            }
            else if(a[1][2][2]==0)
            {
                flag=1;
                if(a[0][2][0]!=0||a[2][0][0]!=a[2][0][1])
                {
                    down_prime(2);
                    left(1);
                    down_prime(1);
                    left_prime(1);
                }
                else if(a[0][2][2]!=0||a[2][0][2]!=a[2][0][1])
                {
                    down_prime(1);
                    right_prime(1);
                    down(1);
                    right(1);
                }
                else if(a[0][0][2]!=0||a[3][0][0]!=a[3][0][1])
                {
                    right(1);
                    down_prime(1);
                    right_prime(1);
                }
                else if(a[0][0][0]!=0||a[3][0][2]!=a[3][0][1])
                {
                    down(1);
                    left_prime(1);
                    down(1);
                    left(1);
                }
            }
            else
            {
                flag=2;
            }
        }
        if(flag==2)                                             //Positioning the white stickers in the top face from the top corner
        {
            if(a[2][0][0]==0)
            {
                left(1);
                down_prime(1);
                left_prime(1);
            }
            else if(a[2][0][2]==0)
            {
                right_prime(1);
                down(1);
                right(1);
            }
            else if(a[5][0][0]==0)
            {
                front(1);
                down_prime(1);
                front_prime(1);
            }
            else if(a[5][0][2]==0)
            {
                back_prime(1);
                down(1);
                back(1);
            }
            else if(a[3][0][0]==0)
            {
                right(1);
                down_prime(1);
                right_prime(1);
            }
            else if(a[3][0][2]==0)
            {
                left_prime(1);
                down(1);
                left(1);
            }
            else if(a[4][0][0]==0)
            {
                back(1);
                down_prime(1);
                back_prime(1);
            }
            else if(a[4][0][2]==0)
            {
                front_prime(1);
                down(1);
                front(1);
            }
        }
    }
    //cout<<"\n\n\n";
}
void layer2()                               //2nd layer edges
{
    int flag=1,count=0,brk=0;
    for(;count!=4&&brk<5;brk++)
    {
    while(flag!=0)
    {
        flag=0;
        if(a[2][2][1]!=1&&a[1][0][1]!=1)                            //Positions middle layer edges from bottom edges
        {
            count++;
            flag=1;
            switch(a[1][0][1])
            {
                case 2: down(2);
                        face3();
                        break;
                case 3: face2();
                        break;
                case 4: down(1);
                        face5();
                        break;
                case 5: down_prime(1);
                        face4();
                        break;
            }
        }
        else if(a[5][2][1]!=1&&a[1][1][2]!=1)
        {
            count++;
            flag=1;
            switch(a[1][1][2])
            {
                case 2: down(1);
                        face3();
                        break;
                case 3: down_prime(1);
                        face2();
                        break;
                case 4: face5();
                        break;
                case 5: down(2);
                        face4();
            }
        }
        else if(a[3][2][1]!=1&&a[1][2][1]!=1)
        {
            count++;
            flag=1;
            switch(a[1][2][1])
            {
                case 2: face3();
                        break;
                case 3: down(2);
                        face2();
                        break;
                case 4: down_prime(1);
                        face5();
                        break;
                case 5: down(1);
                        face4();
            }
        }
        else if(a[4][2][1]!=1&&a[1][1][0]!=1)
        {
            count++;
            flag=1;
            switch(a[1][1][0])
            {
                case 2: down_prime(1);
                        face3();
                        break;
                case 3: down(1);
                        face2();
                        break;
                case 4: down(2);
                        face5();
                        break;
                case 5: face4();
            }
        }
    }
    if(count!=4)                                                           //Removes wrongly positioned edges in the middle layer to bottom edges
    {
        if(a[2][1][0]!=a[2][1][1]||a[4][1][1]!=a[4][1][2])
        {
            flag=1;
            left(1);
            down(1);
            left_prime(1);
            down_prime(1);
            front_prime(1);
            down_prime(1);
            front(1);
        }
        else if(a[5][1][0]!=a[5][1][1]||a[2][1][1]!=a[2][1][2])
        {
            flag=1;
            front(1);
            down(1);
            front_prime(1);
            down_prime(1);
            right_prime(1);
            down_prime(1);
            right(1);
        }
        else if(a[3][1][0]!=a[3][1][1]||a[5][1][1]!=a[5][1][2])
        {
            flag=1;
            right(1);
            down(1);
            right_prime(1);
            down_prime(1);
            back_prime(1);
            down_prime(1);
            back(1);
        }
        else if(a[4][1][0]!=a[4][1][1]||a[3][1][1]!=a[3][1][2])
        {
            flag=1;
            back(1);
            down(1);
            back_prime(1);
            down_prime(1);
            left_prime(1);
            down_prime(1);
            left(1);
        }
    }
    }
    //cout<<"\n\n\n";
}
void bottom_face()                          //Bottom  face - plus formation
{
    int flag=1,count=0,brk;
    for(i=1,j=0;j<3;j++)
    {
        for(k=0;k<3;k++)
        {
            if(j+k==1||j+k==3)
            {
                if(a[i][j][k]==1)
                {
                    count++;
                }
            }
        }
    }
    for(brk=0;flag!=0&&count!=4;brk++)
    {
        if(a[1][1][0]==1&&a[1][1][2]==1)                            //BLU(LUB)'
        {
            flag=0;
            front(1);
            left(1);
            down(1);
            left_prime(1);
            down_prime(1);
            front_prime(1);
        }
        else if(a[1][1][2]==1&&a[1][2][1]==1)                       //BUL(ULB)'
        {
            flag=0;
            front(1);
            down(1);
            left(1);
            down_prime(1);
            left_prime(1);
            front_prime(1);
        }
        if(flag==1)
        {
            down(1);
        }
        if(brk==4)                                                 //If there is no line or 'L' formation do BLU(LUB)'
        {
            front(1);
            left(1);
            down(1);
            left_prime(1);
            down_prime(1);
            front_prime(1);
        }
    }
    //cout<<"\n\n\n";
}
void layer3_1()                             //3rd layer edges
{
    int count=0;
    while(a[2][2][1]!=a[2][1][1]||a[5][2][1]!=a[5][1][1]||a[3][2][1]!=a[3][1][1]||a[4][2][1]!=a[4][1][1])
    {
        count++;
        if(a[2][2][1]==a[2][1][1]&&a[5][2][1]!=a[5][1][1]&&a[3][2][1]!=a[3][1][1]&&a[4][2][1]!=a[4][1][1])
        {
            switch(a[4][2][1])
            {
                case 5: down(1);
                        right_prime(1);
                        down(2);
                        right(1);
                        down(1);
                        right_prime(1);
                        down(1);
                        right(1);
                        down(1);
                        break;
                case 3: down_prime(1);
                        left(1);
                        down_prime(2);
                        left_prime(1);
                        down_prime(1);
                        left(1);
                        down_prime(1);
                        left_prime(1);
                        down_prime(1);
                        break;
            }
        }
        else if(a[2][2][1]!=a[2][1][1]&&a[5][2][1]==a[5][1][1]&&a[3][2][1]!=a[3][1][1]&&a[4][2][1]!=a[4][1][1])
        {
            switch(a[2][2][1])
            {
                case 3: down(1);
                        back_prime(1);
                        down(2);
                        back(1);
                        down(1);
                        back_prime(1);
                        down(1);
                        back(1);
                        down(1);
                        break;

                case 4: down_prime(1);
                        front(1);
                        down_prime(2);
                        front_prime(1);
                        down_prime(1);
                        front(1);
                        down_prime(1);
                        front_prime(1);
                        down_prime(1);
                        break;
            }
        }
        else if(a[2][2][1]!=a[2][1][1]&&a[5][2][1]!=a[5][1][1]&&a[3][2][1]==a[3][1][1]&&a[4][2][1]!=a[4][1][1])
        {
            switch(a[5][2][1])
            {
                case 4: down(1);
                        left_prime(1);
                        down(2);
                        left(1);
                        down(1);
                        left_prime(1);
                        down(1);
                        left(1);
                        down(1);
                        break;

                case 2: down_prime(1);
                        right(1);
                        down_prime(2);
                        right_prime(1);
                        down_prime(1);
                        right(1);
                        down_prime(1);
                        right_prime(1);
                        down_prime(1);
                        break;
            }
        }
        else if(a[2][2][1]!=a[2][1][1]&&a[5][2][1]!=a[5][1][1]&&a[3][2][1]!=a[3][1][1]&&a[4][2][1]==a[4][1][1])
        {
            switch(a[3][2][1])
            {
                case 2: down(1);
                        front_prime(1);
                        down(2);
                        front(1);
                        down(1);
                        front_prime(1);
                        down(1);
                        front(1);
                        down(1);
                        break;

                case 5: down_prime(1);
                        back(1);
                        down_prime(2);
                        back_prime(1);
                        down_prime(1);
                        back(1);
                        down_prime(1);
                        back_prime(1);
                        down_prime(1);
                        break;
            }
        }
        else
        {
            if(count==5)                                                                //Special Case where nothing matches or more than one matches
            {
                down(1);
                right_prime(1);
                down(2);
                right(1);
                down(1);
                right_prime(1);
                down(1);
                right(1);
                down(1);
            }
            else                                                                        //If the blue color does not match
            {
                down(1);
            }
        }
    }
    //cout<<"\n\n\n";
}
void layer3_2()                             //3rd layer corners position
{
    if((((a[2][2][0]==1||a[2][2][0]==4||a[2][2][0]==2)&&(a[4][2][2]==4||a[4][2][2]==1||a[4][2][2]==2)&&(a[1][0][0]==1||a[1][0][0]==4||a[1][0][0]==2))&&((a[2][2][2]==1||a[2][2][2]==2||a[2][2][2]==5)&&(a[5][2][0]==1||a[5][2][0]==2||a[5][2][0]==5)&&(a[1][0][2]==1||a[1][0][2]==2||a[1][0][2]==5))&&((a[5][2][2]==1||a[5][2][2]==3||a[5][2][2]==5)&&(a[3][2][0]==1||a[3][2][0]==3||a[3][2][0]==5)&&(a[1][2][2]==1||a[1][2][2]==3||a[1][2][2]==5))&&((a[3][2][2]==1||a[3][2][2]==4||a[3][2][2]==3)&&(a[4][2][0]==1||a[4][2][0]==3||a[4][2][0]==4)&&(a[1][2][0]==1||a[1][2][0]==4||a[1][2][0]==3)))==0)
    {
    int flag=1;
    while(flag!=0)
    {
        if((a[2][2][0]==1||a[2][2][0]==4||a[2][2][0]==2)&&(a[4][2][2]==4||a[4][2][2]==1||a[4][2][2]==2)&&(a[1][0][0]==1||a[1][0][0]==4||a[1][0][0]==2))
        {
            flag=0;
            if((a[2][2][2]==1||a[2][2][2]==3||a[2][2][2]==5)&&(a[5][2][0]==1||a[5][2][0]==3||a[5][2][0]==5)&&(a[1][0][2]==1||a[1][0][2]==3||a[1][0][2]==5))
            {
                right_prime(1);
                down(1);
                left(1);
                down_prime(1);
                right(1);
                down(1);
                left_prime(1);
                down_prime(1);
            }
            else
            {
                down(1);
                left(1);
                down_prime(1);
                right_prime(1);
                down(1);
                left_prime(1);
                down_prime(1);
                right(1);
            }
        }
        else if((a[2][2][2]==1||a[2][2][2]==2||a[2][2][2]==5)&&(a[5][2][0]==1||a[5][2][0]==2||a[5][2][0]==5)&&(a[1][0][2]==1||a[1][0][2]==2||a[1][0][2]==5))
        {
            flag=0;
            if((a[5][2][2]==1||a[5][2][2]==4||a[5][2][2]==3)&&(a[3][2][0]==1||a[3][2][0]==3||a[3][2][0]==4)&&(a[1][2][2]==1||a[1][2][2]==4||a[1][2][2]==3))
            {
                back_prime(1);
                down(1);
                front(1);
                down_prime(1);
                back(1);
                down(1);
                front_prime(1);
                down_prime(1);
            }
            else
            {
                down(1);
                front(1);
                down_prime(1);
                back_prime(1);
                down(1);
                front_prime(1);
                down_prime(1);
                back(1);
            }
        }
        else if((a[5][2][2]==1||a[5][2][2]==3||a[5][2][2]==5)&&(a[3][2][0]==1||a[3][2][0]==3||a[3][2][0]==5)&&(a[1][2][2]==1||a[1][2][2]==3||a[1][2][2]==5))
        {
            flag=0;
            if((a[3][2][3]==1||a[3][2][2]==4||a[3][2][2]==2)&&(a[4][2][0]==4||a[4][2][0]==1||a[4][2][0]==2)&&(a[1][2][0]==1||a[1][2][0]==4||a[1][2][0]==2))
            {
                left_prime(1);
                down(1);
                right(1);
                down_prime(1);
                left(1);
                down(1);
                right_prime(1);
                down_prime(1);
            }
            else
            {
                down(1);
                right(1);
                down_prime(1);
                left_prime(1);
                down(1);
                right_prime(1);
                down_prime(1);
                left(1);
            }
        }
        else if((a[3][2][2]==1||a[3][2][2]==4||a[3][2][2]==3)&&(a[4][2][0]==1||a[4][2][0]==3||a[4][2][0]==4)&&(a[1][2][0]==1||a[1][2][0]==4||a[1][2][0]==3))
        {
            flag=0;
            if((a[2][2][0]==1||a[2][2][0]==5||a[2][2][0]==2)&&(a[4][2][2]==5||a[4][2][2]==1||a[4][2][2]==2)&&(a[1][0][0]==1||a[1][0][0]==5||a[1][0][0]==2))
            {
                front_prime(1);
                down(1);
                back(1);
                down_prime(1);
                front(1);
                down(1);
                back_prime(1);
                down_prime(1);
            }
            else
            {
                down(1);
                back(1);
                down_prime(1);
                front_prime(1);
                down(1);
                back_prime(1);
                down_prime(1);
                front(1);
            }
        }
        else
        {
            right_prime(1);
            down(1);
            left(1);
            down_prime(1);
            right(1);
            down(1);
            left_prime(1);
            down_prime(1);
        }
    }
    }
    //cout<<"\n\n\n";
}
void layer3_3()                             //3rd layer corners orientation
{
    for(int t=0;t<4;t++)
    {
        if(a[1][0][0]!=1)
        {
            if(a[2][2][0]==1)
            {
                for(int s=0;s<2;s++)
                {
                    front(1);
                    up(1);
                    front_prime(1);
                    up_prime(1);
                }
            }
            else
            {
                for(int s=0;s<2;s++)
                {
                    up(1);
                    front(1);
                    up_prime(1);
                    front_prime(1);
                }
            }
            down_prime(1);
        }
        else
        {
            down_prime(1);
        }
    }
    //cout<<"\n\n\n";
}
void shiftpos(char *str,int pos)
{
    for(int i=0;str[pos+i+2]!='\0';i++)
    {
        str[pos+i]=str[pos+i+2];
    }
}
int main()
{
    cout<<"Enter the colours with WHITE as TOP face and BLUE as FRONT Face\nW - White\nY - Yellow\nB - Blue\nG - Green\nR - Red\nO - Orange\n";
    char pos;
    for(i=0;i<6;i++)                                                            //Getting the face colours
    {
        cout<<"\nEnter "<<c[i]<<" face colours\n";
        for(j=0;j<3;j++)
        {
            for(k=0;k<3;k++)
            {
                cin>>pos;
                switch(pos)
                {
                    case 'W':
                    case 'w': a[i][j][k]=0;
                            break;
                    case 'Y':
                    case 'y': a[i][j][k]=1;
                            break;
                    case 'B':
                    case 'b': a[i][j][k]=2;
                            break;
                    case 'G':
                    case 'g': a[i][j][k]=3;
                            break;
                    case 'R':
                    case 'r': a[i][j][k]=4;
                            break;
                    case 'O':
                    case 'o': a[i][j][k]=5;
                            break;
                    default: cout<<"------------------Enter a valid position-------------------"<<endl;
                            k--;
                }
            }
        }
    }
    for(i=0;i<6;i++)                                                            //Printing the 6 face colours as numbers in matrix form
    {
        cout<<c[i]<<" face colours\n";
        for(j=0;j<3;j++)
        {
            for(k=0;k<3;k++)
            {
                switch(a[i][j][k])
                {
                    case 0: cout<<"W ";
                            break;
                    case 1: cout<<"Y ";
                            break;
                    case 2: cout<<"B ";
                            break;
                    case 3: cout<<"G ";
                            break;
                    case 4: cout<<"R ";
                            break;
                    case 5: cout<<"O ";
                }
            }
            cout<<'\n';
        }
        cout<<'\n';
    }
    qq[q]='@';
    q++;
    layer1_1();
    qq[q]='@';
    q++;
    layer1_2();
    qq[q]='@';
    q++;
    layer2();
    qq[q]='@';
    q++;
    bottom_face();
    qq[q]='@';
    q++;
    layer3_1();
    qq[q]='@';
    q++;
    layer3_2();
    qq[q]='@';
    q++;
    layer3_3();
    qq[q]='\0';
    cout<<"-------------------------------------------------------------------------------"<<endl;
    for(int t=0;t<3;t++)
    {
    for(i=3;qq[i]!='\0';i++)
    {
        if((qq[i-3]==qq[i-2])&&(qq[i-2]==qq[i-1])&&(qq[i-1]==qq[i]))
        {
            for(int j=0;qq[j]!='\0';j++)
            {
                qq[i-3+j]=qq[i+j+1];
            }
        }
    }
    qq[i]='\0';
    for(i=0;qq[i+1]!='\0';i++)
    {
        if((qq[i]=='R'&&qq[i+1]=='r')||(qq[i]=='L'&&qq[i+1]=='l')||(qq[i]=='U'&&qq[i+1]=='u')||(qq[i]=='D'&&qq[i+1]=='d')||(qq[i]=='F'&&qq[i+1]=='f')||(qq[i]=='B'&&qq[i+1]=='b')||(qq[i]=='r'&&qq[i+1]=='R')||(qq[i]=='l'&&qq[i+1]=='L')||(qq[i]=='u'&&qq[i+1]=='U')||(qq[i]=='d'&&qq[i+1]=='D')||(qq[i]=='f'&&qq[i+1]=='F')||(qq[i]=='b'&&qq[i+1]=='B'))
        {
            for(int j=0;qq[j]!='\0';j++)
            {
                qq[i+j]=qq[i+2+j];
            }
        }
    }
    qq[i+1]='\0';
    for(i=2;qq[i]!='\0';i++)
    {
        if((qq[i-2]==qq[i-1])&&(qq[i-1]==qq[i]))
        {
            switch(qq[i])
            {
                case 'R': qq[i-2]='r';
                        shiftpos(qq,i-1);
                        break;
                case 'r': qq[i-2]='R';
                        shiftpos(qq,i-1);
                        break;
                case 'L': qq[i-2]='l';
                        shiftpos(qq,i-1);
                        break;
                case 'l': qq[i-2]='L';
                        shiftpos(qq,i-1);
                        break;
                case 'U': qq[i-2]='u';
                        shiftpos(qq,i-1);
                        break;
                case 'u': qq[i-2]='U';
                        shiftpos(qq,i-1);
                        break;
                case 'D': qq[i-2]='d';
                        shiftpos(qq,i-1);
                        break;
                case 'd': qq[i-2]='D';
                        shiftpos(qq,i-1);
                        break;
            }
        }
    }
    }
    string def[7]={"Top face plus formation","Top Corners","2nd layer edges","Bottom face plus formation","3rd layer edges","3rd layer corners","3rd layer corners' orientation"};
    int k;
    for(i=0,k=0;qq[i]!='\0';i++)
    {
        switch(qq[i])
        {
            case '@': cout<<"\n\n\n";
                    cout<<def[k]<<"\n\n";
                    k++;
                    break;
            case 'r': cout<<"Rp\t";
                    break;
            case 'l': cout<<"Lp\t";
                    break;
            case 'u': cout<<"Up\t";
                    break;
            case 'd': cout<<"Dp\t";
                    break;
            case 'f': cout<<"Fp\t";
                    break;
            case 'b': cout<<"Bp\t";
                    break;
            default: cout<<qq[i]<<'\t';
        }
    }
    cout<<"\n\n";
    cout<<"Number of moves = "<<strlen(qq)-7<<endl;
    cout<<'\n';
    cout<<"-------------------------------------------------------------------------------"<<endl;
    for(i=0;i<6;i++)                                                            //Printing the 6 face colours as numbers in matrix form
    {
        cout<<'\n'<<c[i]<<" face colours\n";
        for(j=0;j<3;j++)
        {
            for(k=0;k<3;k++)
            {
                switch(a[i][j][k])
                {
                    case 0: cout<<"W ";
                            break;
                    case 1: cout<<"Y ";
                            break;
                    case 2: cout<<"B ";
                            break;
                    case 3: cout<<"G ";
                            break;
                    case 4: cout<<"R ";
                            break;
                    case 5: cout<<"O ";
                }
            }
            cout<<'\n';
        }
        cout<<'\n';
    }
    return 0;
}
