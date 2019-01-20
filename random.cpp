#include<graphics.h>
#include<bits/stdc++.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<windows.h>
#include<mmsystem.h>
using namespace std;

void exit();
void game();
void level();
void high();
void help();
void check();
void border();
void speed();
void type();
void short_border();
void full_border();

int snake_size=3,snake_x[500],snake_y[500],score,highscore,spd=100;
bool high_chk=true,BONUS=false,checkdied=false,easy=false,medium=false,hard=false;
int page=0;
bool pblm=false;

int main()
{
    int gd=DETECT;
    int gm;
    initgraph(&gd,&gm,"");

    setcolor(3);
    settextstyle(10,0,5);
    outtextxy(80,2," Project-1: Snake");
    settextstyle(10,0,3);
    setcolor(7);
    outtextxy(00,80," Submitted by:");
    outtextxy(30,120,"Md.Mehedi Hasan");
    outtextxy(30,145,"Registration No: 2017831023");
    outtextxy(30,170,"UChaiAye Marma");
    outtextxy(30,195,"Registration No: 2017831053");
    outtextxy(00,260," Submitted to: ");
    outtextxy(30,300,"Asif Mohammed Samir Sir ");
    outtextxy(30,320,"Assistant Professor");
    outtextxy(30,340,"IICT,SUST");
    setcolor(YELLOW);
    settextstyle(8,HORIZ_DIR,3);
    outtextxy(160,400,"Press any key to continue");
    getch();
    cleardevice();

    char ch;
    int cursor_y=140;
    while(1)
    {
        setcolor(3);
        settextstyle(10,HORIZ_DIR,6);
        outtextxy(200,50,"Snake");

        setcolor(GREEN);
        settextstyle(6,HORIZ_DIR,2);
        outtextxy(200,140,"New game");
        outtextxy(200,180,"Level");
        outtextxy(200,220,"Help");
        outtextxy(200,260,"High Score");
        outtextxy(200,300,"Exit");

        setcolor(BLUE);
        settextstyle(3,0,3);
        outtextxy(170,cursor_y,">");

        if(kbhit)
        {
            ch=getch();
            setcolor(BLACK);
            settextstyle(3,0,3);
            outtextxy(170,cursor_y,">");


            if(ch==13)
            {
                PlaySound("rumi.wav",NULL,SND_FILENAME | SND_SYNC);
                if(cursor_y==300)
                    exit(0);
                else if(cursor_y==140)
                    game();
                else if(cursor_y==180)
                    level();
                else if(cursor_y==220)
                    help();
                else if(cursor_y==260)
                    high();
            }

        }

        if(ch==80)
        {
            PlaySound("rumi.wav",NULL,SND_FILENAME | SND_SYNC);
            cursor_y+=40;
            if(cursor_y>300)
                cursor_y=140;
        }
        if(ch==72)
        {
            PlaySound("rumi.wav",NULL,SND_FILENAME | SND_SYNC);
            cursor_y-=40;
            if(cursor_y<140)
                cursor_y=300;
        }
        settextstyle(3,0,3);
        outtextxy(170,cursor_y,">");
    }
    return 0;
}


void game()
{
    clearviewport();
    freopen("game.dat","r",stdin);
    cin>>highscore;

    char ch;
    string key="right";
    int x=200,y=220;
    int maxx=getmaxx()-12;
    int maxy=getmaxy()-52;
    int food_x=rand()%maxx;
    int food_y=rand()%maxy;
    int temp;
    temp=food_x%10;
    food_x-=temp;
    temp=food_y%10;
    food_y-=temp;

    int w=0;
    int bonus=500;

    while(true)
    {
        if(pblm)
        {
            setactivepage(1-page);
            setvisualpage(page);
            pblm=false;
        }
        else
        {
            setactivepage(page);
            setvisualpage(1-page);
        }
        clearviewport();

        //left
        if(hard)
        {
            setcolor(RED);
            line(2,0,2,maxy);
            line(12,0,12,maxy);
            for(int k=0; k<=maxy; k=k+10)
                line(2,k,12,k);
            //up border
            line(0,2,maxx,2);
            line(0,12,maxx,12);
            for(int k=0; k<maxx; k=k+10)
                line(k,2,k,12);
            //down border
            line(12,maxy-12,maxx,maxy-12);
            line(2,maxy-2,maxx,maxy-2);
            for(int k=12; k<maxx; k=k+10)
                line(k,maxy-12,k,maxy-2);
            //right border
            line(maxx-1,0,maxx-1,maxy);
            line(maxx-14,0,maxx-14,maxy);
            for(int k=0; k<maxy-10; k=k+10)
                line(maxx-14,k,maxx-1,k);

            rectangle(190,130,200,200);
            for(int k=140; k<200; k=k+10)
            {
                line(190,k,200,k);
            }
            rectangle(190,228,200,310);
            for(int k=238; k<310; k=k+10)
            {
                line(190,k,200,k);
            }

            rectangle(400,130,410,200);
            for(int k=140; k<200; k=k+10)
            {
                line(400,k,410,k);
            }
            rectangle(400,228,410,310);
            for(int k=238; k<310; k=k+10)
            {
                line(400,k,410,k);
            }

        }

        //up
        if(medium || hard)
        {
            setcolor(RED);
            line(200,130,400,130);
            line(200,140,400,140);
            for(int k=200; k<=400; k=k+10)
                line(k,130,k,140);

            //down
            line(200,300,400,300);
            line(200,310,400,310);
            for(int k=200; k<=400; k=k+10)
                line(k,300,k,310);
        }
        if(medium)
        {
            setcolor(RED);
            line(2,0,2,150);
            line(12,0,12,150);
            for(int k=0; k<=150; k=k+10)
                line(2,k,12,k);

            line(2,maxy-150,2,maxy);
            line(12,maxy-150,12,maxy);
            for(int k=maxy-150; k<maxy; k=k+10)
            {
                line(2,k,12,k);
            }
            //up border
            setcolor(RED);
            line(0,2,150,2);
            line(0,12,150,12);
            for(int k=0; k<=150; k=k+10)
                line(k,2,k,12);

            line(maxx-150,2,maxx,2);
            line(maxx-150,12,maxx,12);
            for(int k=maxx-150; k<maxx; k=k+10)
                line(k,2,k,12);
            //down border
            line(0,maxy-12,150,maxy-12);
            line(0,maxy-2,150,maxy-2);
            for(int k=0; k<=150; k=k+10)
                line(k,maxy-12,k,maxy-2);

            line(maxx-150,maxy-12,maxx,maxy-12);
            line(maxx-150,maxy-2,maxx,maxy-2);
            for(int k=maxx-150; k<maxx; k=k+10)
                line(k,maxy-12,k,maxy-2);

            //right border
            line(maxx-1,0,maxx-1,150);
            line(maxx-14,0,maxx-14,150);
            for(int k=0; k<=150; k=k+10)
                line(maxx-14,k,maxx-1,k);

            line(maxx-1,maxy-150,maxx-1,maxy);
            line(maxx-14,maxy-150,maxx-14,maxy);
            for(int k=maxy-150; k<maxy; k=k+10)
                line(maxx-14,k,maxx-1,k);

        }

        while(food_x%10!=0 || food_y%10!=0 || food_x<12 || food_y<20 || ((food_x>=200 && food_x<=400) && ((food_y>=130 && food_y<=140)|| (food_y>=300 && food_y<=310))) || (((food_x>=190 && food_x<=200) || (food_x>=400 && food_x<=410)) && (food_y>=130 && food_y<=310)))
        {
            food_x=rand()%(maxx-12);
            food_y=rand()%(maxy-52);
            temp;
            temp=food_x%10;
            food_x-=temp;
            temp=food_y%10;
            food_y-=temp;
        }

        if(w%5!=0 || w==0 || bonus==0)
        {
            setcolor(WHITE);
            setfillstyle(SOLID_FILL,WHITE);
            circle(food_x,food_y,5);
            floodfill(food_x,food_y,WHITE);
        }
        else
        {
            BONUS=true;
            setcolor(RED);
           // setfillstyle(SOLID_FILL,RED);
            circle(food_x,food_y,8);
            floodfill(food_x,food_y,RED);
        }

        if(kbhit())
        {
            ch=getch();
            if(ch==0 )
                ch=getch();
            if(ch==72 && key!="down")
                key="up";
            if(ch==80 && key!="up")
                key="down";
            if(ch==75 && key!="right")
                key="left";
            if(ch==77 && key!="left")
                key="right";
            if(ch==27)
            {
                if(!pblm)
                    pblm=true;
                else
                    pblm=false;
                cleardevice();
                for(int k=0; k<snake_size; k++)
                {
                    snake_x[k]=0;
                    snake_y[k]=0;
                }
                setvisualpage(page);
                return;
            }
        }

        for(int posi = snake_size; posi >= 0; posi--)
        {
            snake_x[posi+1] = snake_x[posi];
            snake_y[posi+1] = snake_y[posi];
        }

        snake_x[0] = x;
        snake_y[0] = y;

        setcolor(WHITE);
        circle(snake_x[0],snake_y[0],6);
        setfillstyle(SOLID_FILL,WHITE);                   //head
        floodfill(snake_x[0],snake_y[0],WHITE);

        setcolor(3);
        for(int posi = 1; posi <= snake_size; posi++)
        {
            //lez
            circle(snake_x[posi],snake_y[posi],5);
            setfillstyle(SOLID_FILL,3);
            floodfill(snake_x[posi],snake_y[posi],3);
        }

        maxx=getmaxx();
        maxy=getmaxy()-40;
        setcolor(WHITE);
        line(0,maxy+5,maxx,maxy+5);

        if(food_x==x && food_y==y)
        {
            score++;
            w++;
            if(BONUS)
            {
                score+=bonus;
                BONUS=false;
                bonus=500;
            }
            else
                snake_size++;

            food_x=rand()%maxx-12;
            food_y=rand()%maxy-52;
            temp=food_x%10;
            food_x-=temp;
            temp=food_y%10;
            food_y-=temp;
        }

        char arr[100];
        settextstyle(8,HORIZ_DIR,2);
        sprintf(arr,"Score : %d",score);
        outtextxy(5,maxy+10,arr);

        sprintf(arr,"Highscore : %d",highscore);
        outtextxy(maxx-210,maxy+10,arr);

        if(key == "right")
            x = x+10;
        if(x > maxx)
            x =0;
        if(key == "left")
            x = x-10;
        if(x < 0)
            x = maxx-(maxx%10);
        if(key == "up")
            y = y-10;
        if(y < 0)
            y = maxy-(maxy%10);
        if(key == "down")
            y = y+10;
        if(y > maxy)
            y = 0;

        check();
        if(hard)
            full_border();
        if(medium || hard)
            border();
        if(medium)
            short_border();
        if(checkdied)
        {
            score=0;
            snake_size=3;
            checkdied=false;
            BONUS=false;
            if(!pblm)
                pblm=true;
            else
                pblm=false;
            clearviewport();
            for(int k=0; k<5; k++)
            {
                snake_x[k]=1000;
                snake_x[k]=1000;
            }
            return;
        }

        if(BONUS)
        {
            if(bonus>0)
            {
                bonus-=5;
                setcolor(YELLOW);
                settextstyle(8,0,4);
                sprintf(arr,"Hurry !!! %d",bonus);
                outtextxy(152,maxy+8,arr);
            }
        }

        page=1-page;
        delay(spd);
    }

}

void check()
{
    freopen("game.dat","w",stdout);
    if(highscore<score)
    {
        cout<<score<<endl;
        if(high_chk)
        {
            setcolor(RED);
            outtextxy(200,200,"Snake master!!!");
            delay(500);
            high_chk=false;
        }
    }
    else
        cout<<highscore<<endl;

    freopen("game.dat","r",stdin);
    cin>>highscore;


    for(int i=1; i<snake_size; i++)
    {
        if(snake_x[0]==snake_x[i] && snake_y[0]==snake_y[i])
        {
            setvisualpage(page);
            setcolor(RED);
            circle(snake_x[0],snake_y[0],7);
            setfillstyle(SOLID_FILL,RED);
            floodfill(snake_x[0],snake_y[0],RED);
            setcolor(2);
            settextstyle(10,HORIZ_DIR,8);
            outtextxy(100,180,"GAME OVER");
            setcolor(YELLOW);
            settextstyle(8,HORIZ_DIR,3);
            outtextxy(160,350,"Press Enter to continue");

            while(1)
            {
                if(kbhit())
                {
                    char ch=getch();
                    if(ch==13)
                    {
                        checkdied=true;
                        return;
                    }
                }
            }
        }
    }
}


void help()
{
    clearviewport();
    setcolor(WHITE);
    outtextxy(150,150,"Use  ->  to move the snake to the right.");
    outtextxy(150,180,"Use  <-  to move the snake to the left.");
    outtextxy(150,210,"Press  'Alt' button to push the game.");
    char ch=getch();
    clearviewport();
    return;
}


void high()
{
    clearviewport();
    freopen("game.dat","r",stdin);
    cin>>highscore;
    char arr[100];
    sprintf(arr,"Highscore = %d",highscore);
    setcolor(WHITE);
    outtextxy(150,200,arr);
    char ch=getch();
    clearviewport();
    return;
}

void level()
{
    clearviewport();
    int pointer=200;
    char ch;
    while(1)
    {
        setcolor(3);
        outtextxy(200,300,"Press  <-  key to back");
        setcolor(GREEN);
        outtextxy(200,200,"Type");
        outtextxy(200,230,"Speed");

        setcolor(BLUE);
        settextstyle(3,0,3);
        outtextxy(170,pointer,">");

        if(kbhit)
        {
            ch=getch();
            setcolor(BLACK);
            settextstyle(3,0,3);
            outtextxy(170,pointer,">");
            if(ch==13)
            {
                PlaySound("rumi.wav",NULL,SND_FILENAME | SND_SYNC);
                if(pointer==200)
                    type();
                else if(pointer==230)
                    speed();
            }
        }
        if(ch==80)
        {
            PlaySound("rumi.wav",NULL,SND_FILENAME | SND_SYNC);
            pointer+=30;
            if(pointer>230)
                pointer=200;
        }
        if(ch==72)
        {
            PlaySound("rumi.wav",NULL,SND_FILENAME | SND_SYNC);
            pointer-=30;
            if(pointer<200)
                pointer=230;
        }
        if(ch==75)
        {
            PlaySound("rumi.wav",NULL,SND_FILENAME | SND_SYNC);
            clearviewport();
            return;
        }
        settextstyle(3,0,3);
        outtextxy(170,pointer,">");
    }
    return;
}


void speed()
{
    clearviewport();
    char ch;
    char arr[100];
    while(1)
    {
        setcolor(3);
        outtextxy(150,300,"Press  <-  key to back");

        int i=abs(spd/10-11);
        sprintf(arr,"SELECT LEVEL : %d",i);
        setcolor(GREEN);
        outtextxy(150,200,arr);

        if(kbhit())
        {
            ch=getch();
            if(ch==80)
            {
                PlaySound("rumi.wav",NULL,SND_FILENAME | SND_SYNC);
                spd-=10;
                if(spd<10)
                    spd=100;
            }
            else if(ch==72)
            {
                PlaySound("rumi.wav",NULL,SND_FILENAME | SND_SYNC);
                spd+=10;
                if(spd>100)
                    spd=10;
            }
            else if(ch==13)
            {
                PlaySound("rumi.wav",NULL,SND_FILENAME | SND_SYNC);
                break;
            }
            if(ch==75)
            {
                PlaySound("rumi.wav",NULL,SND_FILENAME | SND_SYNC);
                clearviewport();
                return;
            }
            sprintf(arr,"SELECT LEVEL : %d",i);
            setcolor(BLACK);
            outtextxy(150,200,arr);
        }
    }
    clearviewport();
}


void type()
{
    clearviewport();
    int pointer=200;
    char ch;
    while(1)
    {
        setcolor(3);
        outtextxy(200,320,"Press  <-  key to back");
        setcolor(GREEN);
        outtextxy(200,200,"Easy");
        outtextxy(200,230,"Medium");
        outtextxy(200,260,"Hard");
        setcolor(BLUE);
        settextstyle(3,0,3);
        outtextxy(170,pointer,">");
        if(kbhit)
        {
            ch=getch();
            setcolor(BLACK);
            settextstyle(3,0,3);
            outtextxy(170,pointer,">");
            if(ch==13)
            {
                PlaySound("rumi.wav",NULL,SND_FILENAME | SND_SYNC);
                if(pointer==200)
                {
                    easy=true;
                    medium=false;
                    hard=false;
                }
                else if(pointer==230)
                {
                    medium=true;
                    easy=false;
                    hard=false;
                }
                else if(pointer==260)
                {
                    hard=true;
                    easy=false;
                    medium=false;
                }
                clearviewport();
                break;
            }
        }
        if(ch==80)
        {
            PlaySound("rumi.wav",NULL,SND_FILENAME | SND_SYNC);
            pointer+=30;
            if(pointer>260)
                pointer=200;
        }
        if(ch==72)
        {
            PlaySound("rumi.wav",NULL,SND_FILENAME | SND_SYNC);
            pointer-=30;
            if(pointer<200)
                pointer=260;
        }
        if(ch==75)
        {
            PlaySound("rumi.wav",NULL,SND_FILENAME | SND_SYNC);
            clearviewport();
            return;
        }
        settextstyle(3,0,3);
        outtextxy(170,pointer,">");
    }
    return;
}

void full_border()
{
    int maxx=getmaxx()-12;
    int maxy=getmaxy()-52;
    if(snake_x[0]<=12 || snake_x[0]>=maxx || snake_y[0]<=12 || snake_y[0]>=maxy)
    {
        setvisualpage(page);
        setcolor(RED);
        setfillstyle(SOLID_FILL,RED);
        circle(snake_x[0],snake_y[0],5);
        floodfill(snake_x[0],snake_y[0],RED);
        setcolor(2);
        settextstyle(10,HORIZ_DIR,8);
        outtextxy(100,180,"GAME OVER");
        setcolor(YELLOW);
        settextstyle(8,HORIZ_DIR,3);
        outtextxy(160,350,"Press Enter to continue");
        while(1)
        {
            char ch=getch();
            if(ch==13)
            {
                checkdied=true;
                return;
            }
        }
    }

    //last added obstracal
    if((snake_x[0]>=190 && snake_x[0]<=200) || (snake_x[0]>=400 && snake_x[0]<=410))
    {
        if((snake_y[0]>=130 && snake_y[0]<=200) ||(snake_y[0]>=228 && snake_y[0]<=310) )
        {
            setvisualpage(page);
            setcolor(RED);
            setfillstyle(SOLID_FILL,RED);
            circle(snake_x[0],snake_y[0],6);
            floodfill(snake_x[0],snake_y[0],RED);
            setcolor(2);
            settextstyle(10,HORIZ_DIR,8);
            outtextxy(100,180,"GAME OVER");
            setcolor(YELLOW);
            settextstyle(8,HORIZ_DIR,3);
            outtextxy(160,350,"Press Enter to continue");

            while(1)
            {
                if(kbhit())
                {
                    char ch=getch();
                    if(ch==13)
                    {

                        checkdied=true;
                        return;

                    }
                }
            }

        }
    }

}

void short_border()
{
    int maxx=getmaxx()-12;
    int maxy=getmaxy()-52;
    if((snake_y[0]<12 || snake_y[0]>maxy) &&(snake_x[0]<=150 || snake_x[0]>maxx-149))
    {
        setvisualpage(page);
        setcolor(RED);
        setfillstyle(SOLID_FILL,RED);
        circle(snake_x[0],snake_y[0],5);
        floodfill(snake_x[0],snake_y[0],RED);
        setcolor(2);
        settextstyle(10,HORIZ_DIR,8);
        outtextxy(100,180,"GAME OVER");
        setcolor(YELLOW);
        settextstyle(8,HORIZ_DIR,3);
        outtextxy(160,350,"Press Enter to continue");
        while(1)
        {
            char ch=getch();
            if(ch==13)
            {
                checkdied=true;
                return;
            }
        }
    }
    if((snake_x[0]<12 || snake_x[0]>maxx) &&(snake_y[0]<=150 || snake_y[0]>maxy-145))
    {
        setvisualpage(page);
        setcolor(RED);
        setfillstyle(SOLID_FILL,RED);
        circle(snake_x[0],snake_y[0],5);
        floodfill(snake_x[0],snake_y[0],RED);
        setcolor(2);
        settextstyle(10,HORIZ_DIR,8);
        outtextxy(100,180,"GAME OVER");
        setcolor(YELLOW);
        settextstyle(8,HORIZ_DIR,3);
        outtextxy(160,350,"Press Enter to continue");
        while(1)
        {
            char ch=getch();
            if(ch==13)
            {
                checkdied=true;
                return;
            }
        }
    }
}

void border()
{
    if(snake_x[0]>=200 && snake_x[0]<=400)
    {
        if((snake_y[0]>=130 && snake_y[0]<=140) || (snake_y[0]>=300 && snake_y[0]<=310))
        {
            setvisualpage(page);
            setcolor(RED);
            setfillstyle(SOLID_FILL,RED);
            circle(snake_x[0],snake_y[0],5);
            floodfill(snake_x[0],snake_y[0],RED);
            setcolor(2);
            settextstyle(10,HORIZ_DIR,8);
            outtextxy(100,180,"GAME OVER");
            setcolor(YELLOW);
            settextstyle(8,HORIZ_DIR,3);
            outtextxy(160,350,"Press Enter to continue");

            while(1)
            {
                if(kbhit())
                {
                    char ch=getch();
                    if(ch==13)
                    {
                        checkdied=true;
                        return;
                    }
                }
            }
        }
    }
}


