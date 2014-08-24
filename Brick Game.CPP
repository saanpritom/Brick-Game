#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<string.h>

union REGS in,out;
struct brick{
int x11,x22,y11,y22,p;
}br[100];
struct high_scor{
char name[100];
int num;
}take[5],temp;
int x1,x2,y1,y2,xx,yy,tx,ty,scor,totalb,life;
char ch[100],chh[100];
void menu();

void helpmenu() ;

void take_score();

void High();

void load_mouse_driver() ;

void unload_mouse_driver();

void controls();

int yes_no();

void cover_page() ;

void second_page();

void erase(int i);

void cheack();

void game1();

void game2();

void restor();


void win_lose();

void intgra()
 {
  int gd=DETECT,gm;

  initgraph(&gd,&gm,"c:\\turboc3\\bgi"); //initialization  graph
  cleardevice();
  int error=graphresult();

  if(error!=0)  //error chacking of graph  initialization
   {
    printf("error graph initialization\n");
    printf("Press any key.....\n");
    getch();
    exit(1);
   }
 }

void main()     //main function start
 {

   intgra();
  cover_page();
  second_page();


  while(1)
    {


       setcolor(15);
       settextstyle(0,0,1);

       load_mouse_driver();
       menu();
       int x,y,cl,a;


       in.x.ax=3;
       int86(0x33,&in,&out);

       x=out.x.cx;      // To get x coordinate
       y=out.x.dx;      // To get y coordinate
       cl=out.x.bx;     // 1/0 ; 1 for mouse click

       if(x>=250 && x<=314 && y>=100 && y<=108 && cl==1) //checking if the mouse inside the new game and the user click on it..
	{
	   unload_mouse_driver();
	   game1();
	}
       else if(x>=250 && x<=314 && y>=150 && y<=158 && cl==1)    //checking if the mouse inside the control and the user click on it..
	{
	  unload_mouse_driver();
	  controls();
	}

	else if(x>=250 && x<=314 && y>=200 && y<=208 && cl==1)    //checking if the mouse inside the control and the user click on it..
	{
		 unload_mouse_driver();
		cleardevice();
		helpmenu() ;
		cleardevice();
	}
       else if(x>=250 && x<=330 && y>=250 && y<=258 && cl==1)    //checking if the mouse inside the control and the user click on it..
	{
	 unload_mouse_driver();
	 cleardevice();
	  High();

	}

	else if(x>=250&&x<=356&&y>=300&&y<=308&&cl==1)
	     {
	      unload_mouse_driver();
	      cleardevice();
	      restor();
	      }

       else if(x>=250&&x<=282&&y>=350&&y<=358&&cl==1)          //checking if the mouse inside the exit and the user click on it..
	{
		int t=yes_no();     //checking gamer sure to exit
		if(t==0)        //0 for clicking no
		 {
		  unload_mouse_driver();
		  cleardevice();
		  continue;
		 }
		unload_mouse_driver();
		break;
	}
    }

    closegraph();
 }

void load_mouse_driver()
	{

	 out.x.cx=0;out.x.bx=0;     //lodeing mouse drive
	 in.x.ax=1;
	 int86(0x33,&in,&out);

	 /*display mouse drive*/

	 in.x.ax=7;
	 in.x.cx=0;
	 in.x.dx=639;
	 int86(0x33,&in,&out);
	 in.x.ax=8;
	 in.x.cx=0;
	 in.x.dx=479;
	 int86(0x33,&in,&out);


	}



void unload_mouse_driver()      //unloading mouse derive
	{
	 in.x.ax=2;
	 int86(0x33,&in,&out);

	}

void cover_page()         //show the cover page
 {
   setcolor(BROWN);
   settextstyle(4,0,6);
   outtextxy(80,80,"BRICK BREAKING");
   outtextxy(80,130,"     GAME");
   settextstyle(5,0,6);
   outtextxy(80,350,"LOADING.....");

   int i;
   for( i=0;i<=640;i++)
    {
	setcolor(BLUE);
	line(i,0,i,50);
	setcolor(BLACK);
	settextstyle(1,0,6);
	outtextxy(140,1,"NUJHAT");
	delay(1);
    }

    for( i=0;i<=480;i++)
     {
	setcolor(YELLOW);
	line(590,i,640,i);
	setcolor(BLACK);
	settextstyle(1,1,6);
	outtextxy(588,140,"SAYED");
	delay(1);
     }

    for(i=640;i>=0;i--)
     {
	setcolor(GREEN);
	line(i,430,i,480);
	setcolor(BLACK);
	settextstyle(1,0,6);
	outtextxy(200,420,"SANIM");
	delay(1);
     }
    for( i=480;i>=0;i--)
    {
	setcolor(RED);
	line(0,i,50,i);
	setcolor(BLACK);
	settextstyle(1,1,6);
	outtextxy(0,116,"PRITOM");
	delay(1);
    }


   settextstyle(5,0,6);
   outtextxy(80,350,"LOADING.....");

   setcolor(15);
   settextstyle(0,0,0);
   outtextxy(80,350,"press any key to continue");
   while(1)              //take any key input
    {
     if(!kbhit())
       {
	i++;
	setcolor(15);
	outtextxy(288+(i*8),350,".");
	delay(200);
       }
     else
      break;
     if(i==5)
      {
       setcolor(0);
       outtextxy(288,350,"......");
       i=-1;
      }
      sound(2000);                 //sound for giving click
      delay(1);
      nosound();

     }

    cleardevice();
 }


void second_page() //animation for second page
{
setcolor(WHITE);
setfillstyle(1,WHITE);
floodfill(10,20,WHITE);
setcolor(YELLOW);
rectangle(230,380,380,400);//bar
setfillstyle(1,BLUE);
floodfill(231,385,YELLOW);//bar
int i;
for(i=10;i<=600;i=i+20)
{
setcolor(YELLOW);
rectangle(i,10,i+20,30);
setfillstyle(1,CYAN);
floodfill(i+2,12,YELLOW);
}
for(i=10;i<=600;i=i+20)
{
setcolor(YELLOW);
rectangle(i,30,i+20,50);
setfillstyle(1,BLUE);
floodfill(i+2,32,YELLOW);
}
for(i=10;i<=600;i=i+20)
{
setcolor(YELLOW);
rectangle(i,50,i+20,70);
setfillstyle(1,GREEN);
floodfill(i+2,52,YELLOW);
}
for(i=10;i<=300;i++)
{
sound(100);
setcolor(RED);
circle(i,320,35);
circle(i,320,49);
setfillstyle(1,BLACK);
floodfill(i,283,RED);
delay(5);
if(i==300)
{
break;
}
setcolor(WHITE);
circle(i,320,35);
circle(i,320,49);
setfillstyle(1,WHITE);
floodfill(i,283,RED);
}
nosound();
delay(40);
setcolor(WHITE);
rectangle(230,380,380,400);//INVISIBLAE RECTANGLE
setfillstyle(1,WHITE);
floodfill(231,385,YELLOW);
setcolor(YELLOW);
line(230,400,380,400);
line(230,380,230,400);
line(380,380,380,400);
line(230,380,305,390);
line(380,380,305,390);
setfillstyle(1,BLUE);
floodfill(240,382,YELLOW);
delay(40);
setcolor(WHITE);
line(230,380,305,390);
line(380,380,305,390);
setcolor(YELLOW);
line(230,400,380,400);
line(230,380,230,400);
line(380,380,380,400);
line(230,380,305,380);
line(380,380,305,380);
setfillstyle(1,BLUE);
floodfill(240,382,YELLOW);
setcolor(WHITE);
line(230,380,305,380);
line(380,380,305,380);
setcolor(YELLOW);
line(230,400,380,400);
line(230,380,230,400);
line(380,380,380,400);
line(230,380,305,370);
line(380,380,305,370);
setfillstyle(1,BLUE);
floodfill(305,372,YELLOW);
for(i=320;i>=70;i--)
{
setcolor(RED);
circle(300,i,35);
circle(300,i,49);
setfillstyle(1,BLACK);
floodfill(301,i,RED);
delay(5);
setcolor(WHITE);
if(i==70)
break;
circle(300,i,35);
circle(300,i,49);
setfillstyle(1,WHITE);
floodfill(301,i,WHITE);
}
for(i=10;i<=600;i=i+20)
{
setcolor(WHITE);
rectangle(i,10,i+20,30);
rectangle(i,30,i+20,50);
rectangle(i,50,i+20,70);
setfillstyle(1,WHITE);
floodfill(i+2,12,WHITE);
floodfill(i+2,32,WHITE);
floodfill(i+2,52,WHITE);
}
for(i=70;i<=200;i++)
{
setcolor(RED);
circle(300,i,35);
circle(300,i,49);
i=i-80;
rectangle(30,i,50,i+20);
rectangle(70,i,90,i+20);
rectangle(110,i,130,i+20);
rectangle(150,i,170,i+20);
rectangle(190,i,210,i+20);
rectangle(580,i,560,i-20);
rectangle(540,i,520,i-20);
rectangle(500,i,480,i-20);
rectangle(460,i,440,i-20);
i=i+80;
i=i+40;
rectangle(30,i,50,i+20);
rectangle(70,i,90,i+20);
rectangle(110,i,130,i+20);
rectangle(150,i,170,i+20);
rectangle(190,i,210,i+20);
rectangle(580,i,560,i-20);
rectangle(540,i,520,i-20);
rectangle(500,i,480,i-20);
rectangle(460,i,440,i-20);
i=i-40;
rectangle(20,i,40,i+20);
rectangle(80,i,100,i+20);
rectangle(140,i,160,i+20);
rectangle(200,i,220,i+20);
rectangle(570,i,550,i-20);
rectangle(510,i,490,i-20);
rectangle(450,i,430,i-20);
rectangle(390,i,370,i-20);
setfillstyle(1,BLACK);
floodfill(301,i,RED);
delay(3);
setcolor(WHITE);
i=i-80;
rectangle(30,i,50,i+20);
rectangle(70,i,90,i+20);
rectangle(110,i,130,i+20);
rectangle(150,i,170,i+20);
rectangle(190,i,210,i+20);
rectangle(580,i,560,i-20);
rectangle(540,i,520,i-20);
rectangle(500,i,480,i-20);
rectangle(460,i,440,i-20);
i=i+80;
i=i+40;
rectangle(30,i,50,i+20);
rectangle(70,i,90,i+20);
rectangle(110,i,130,i+20);
rectangle(150,i,170,i+20);
rectangle(190,i,210,i+20);
rectangle(580,i,560,i-20);
rectangle(540,i,520,i-20);
rectangle(500,i,480,i-20);
rectangle(460,i,440,i-20);
i=i-40;
rectangle(20,i,40,i+20);
rectangle(80,i,100,i+20);
rectangle(140,i,160,i+20);
rectangle(200,i,220,i+20);
rectangle(570,i,550,i-20);
rectangle(510,i,490,i-20);
rectangle(450,i,430,i-20);
rectangle(390,i,370,i-20);
if(i==200)
break;
setfillstyle(1,WHITE);
floodfill(301,i,WHITE);
}
for(i=300;i>=180;i--)
{
setcolor(RED);
circle(i,200,35);
circle(i,200,49);
setfillstyle(1,BLACK);
floodfill(i,202,RED);
delay(3);
if(i==180)
break;
setcolor(WHITE);
circle(i,200,35);
circle(i,200,49);
setfillstyle(1,WHITE);
floodfill(i,202,RED);
}
setcolor(WHITE);
settextstyle(4,0,6);
outtextxy(170,172,"D");
setcolor(BLUE);
outtextxy(235,172,"X-BALL");
cleardevice();
}

void erase(int i)     //take input for those brick who is touched by the ball & erease them
 {
   sound(2000);
   setfillstyle(1,BLACK);
   floodfill(br[i].x11+1,br[i].y11+1,RED);
   setcolor(BLACK);
   rectangle(br[i].x11,br[i].y11,br[i].x22,br[i].y22);

   nosound();
    for( i=0;i<totalb;i++)    //print only those ball who r not touched
	  {
	   if(br[i].p)
	    {
	      setcolor(RED);
	      rectangle(br[i].x11,br[i].y11,br[i].x22,br[i].y22);
	      setfillstyle(2,BROWN);
	      floodfill(br[i].x11+1,br[i].y11+1,RED);
	    }
	    else if(br[i].p==2)
	    {
	      setcolor(RED);
	      rectangle(br[i].x11,br[i].y11,br[i].x22,br[i].y22);
	      setfillstyle(1,BROWN);
	      floodfill(br[i].x11+1,br[i].y11+1,RED);
	    }
	    else scor++;

	     }
 }


void cheack()   //cheack if a brick touched by the ball
 {
    int i,l=1;
    for(i=0;i<totalb;i++)
     {
      if(xx+5>=br[i].x11&&xx+5<=br[i].x22&&yy>=br[i].y11&&yy<=br[i].y22&&br[i].p)
	{
	  br[i].p--;
	  erase(i);
	  if(l)
	  {
	   tx*=-1;
	   l=0;
	   }

	}
     else if(xx-5>=br[i].x11&&xx-5<=br[i].x22&&yy>=br[i].y11&&yy<=br[i].y22&&br[i].p)
	{
	  br[i].p--;
	  erase(i);
	  if(l)
	  {
	   tx*=-1;
	   l=0;
	   }

	}
     else if(xx>=br[i].x11&&xx<=br[i].x22&&yy-5>=br[i].y11&&yy-5<=br[i].y22&&br[i].p)
	{
	  br[i].p--;
	  erase(i);
	  if(l)
	  {
	   ty*=-1;
	   l=0;
	   }

	}
     else if(xx>=br[i].x11&&xx<=br[i].x22&&yy+5>=br[i].y11&&yy+5<=br[i].y22&&br[i].p)
	{
	  br[i].p--;
	  erase(i);
	  if(l)
	  {
	   ty*=-1;
	   l=0;
	   }

	}
     }

 }

void game1()     //game room
 {

	cleardevice();
       unload_mouse_driver();

       int i,j,k;

       scor=0;
       life=3;
       setcolor(RED);
       outtextxy(500,20,"SCORE:");
       outtextxy(100,20,"LIFE:");
       itoa(scor,ch,10);
       outtextxy(556,20,ch);
       itoa(life,chh,10);
       outtextxy(148,20,chh);
	  for(k=0,i=20,j=50;k<100;k++,i+=30)
	   {
	      br[k].x11=i;
	      br[k].x22=i+30;
	      br[k].y11=j;
	      br[k].y22=j+10;
	      br[k].p=1;
	      if((k+1)%20==0)
	       {
		i=-10;
		j+=10;
	       }
	   }

	  totalb=100;
	  x1=297;
	  x2=343;
	  y1=468;
	  y2=478;
	  xx=320;
	  yy=462;
	  tx=0;
	  ty=0;
	 setcolor(15);
	 rectangle(1,40,629,479);  //out line for game
	 circle(xx,yy,5);           //ball
	 rectangle(x1,y1,x2,y2);   //bar

	while(1)    //bar  & ball controlling loop
	 {

	     setcolor(BLACK);
	      outtextxy(556,20,ch);
	     setcolor(RED);
	     itoa(scor,ch,10);
	    outtextxy(556,20,ch);
	      setcolor(0);
	      circle(xx,yy,5);
	  cheack();        //call for ckeack touched ball
	  setcolor(15);
	 rectangle(1,40,629,479);

	  scor=0;
	  for(int i=0;i<totalb;i++)    //print only those ball who r not touched
	  {
	   if(br[i].p)
	    {
	      setcolor(RED);
	      rectangle(br[i].x11,br[i].y11,br[i].x22,br[i].y22);
	      setfillstyle(2,BROWN);
	      floodfill(br[i].x11+1,br[i].y11+1,RED);
	    }
	    else scor++;

	     }

	   if(scor==100)
	    game2();
	  if(kbhit())   //take input for bar where direction he has to go
	  {
	    char ch=getch();

	    if(ch==77&&x2<=623)   //go right
	     {
	       setcolor(0);
		rectangle(x1,y1,x2,y2);
		x1+=10;
		x2+=10;

	     }

	    else if(ch==75&&x1>=6)     //go left
	     {
	      setcolor(0);
	       rectangle(x1,y1,x2,y2);
	       x1-=10;
	       x2-=10;


	     }
	    else if(ch==27)   //close the game
	     {
		 break;
	     }
	  }

	  setcolor(15);
	  rectangle(x1,y1,x2,y2);

	 if(yy+5==467)  //when ball is in the line of bar
	  {
	     if(xx>=x1&&xx<=x2)
	       {
		 if(xx>=((x1+x2)/2-1)-3&&xx<=((x1+x2)/2+1)+3)
		      {
		       tx=0;
		       ty=-5;
		      }
		 else if(xx>=((x1+x2)/2)-23&&xx<=((x1+x2)/2))
		       {
			 tx=-3;
			 ty=-5;
		       }
		 else if(xx<=((x1+x2)/2)+23&&xx>=((x1+x2)/2))
			{
			 tx=3;
			 ty=-5;
			}
		  else if(xx>=((x1+x2)/2)-53&&xx<=((x1+x2)/2))
		       {
			 tx=-6;
			 ty=-5;
		       }
		 else if(xx<=((x1+x2)/2)+53&&xx>=((x1+x2)/2))
			{
			 tx=6;
			 ty=-5;
			}

	       }

	     else
	      {
	      // cleardevice();
	      setcolor(BLACK);
	      outtextxy(148,20,chh);
	      rectangle(x1,y1,x2,y2);
	      life--;
	      setcolor(RED);
	      itoa(life,chh,10);
	      outtextxy(148,20,chh);
	       if(life==0)
		{
		 getch();
		 break;
		 }

		 x1=297;
	  x2=343;
	  y1=468;
	  y2=478;
	  xx=320;
	  yy=462;
	  tx=0;
	  ty=0;
	      }

	  }

	 else if(xx-5<3||xx+5>627)    //side line
	  {
	   tx=-tx;
	  }

	 else if(yy-5<40)        //upper line
	  {
	   ty*=-1;
	  }

	  xx+=tx;
	  yy+=ty;

	 setcolor(WHITE);
	  circle(xx,yy,5);
	  delay(20);


	 }
	 cleardevice();
	 take_score();


}

void game2()                //level 2
 {
     cleardevice();
    int a[]={2,2,2,2,2,2,2,       //how to show the brick
	     2,0,0,0,0,0,2,
	     2,0,0,0,1,0,2,
	     2,0,0,1,0,0,2,
	     2,0,1,0,0,0,2,
	     2,0,1,0,0,0,2,
	     2,0,0,1,0,0,2,
	     2,0,0,0,1,0,2,
	     2,0,0,0,1,0,2,
	     2,0,0,1,0,0,2,
	     2,0,1,0,0,0,2,
	     2,0,0,0,0,0,2,
	     2,2,2,2,2,2,2};
    int i,j,k;
     scor=100;
       setcolor(RED);
       outtextxy(500,20,"SCORE:");
       itoa(scor,ch,10);
       outtextxy(556,20,ch);

     for(k=0,i=200,j=50;k<91;k++,i+=30)
	   {
	      br[k].x11=i;
	      br[k].x22=i+30;
	      br[k].y11=j;
	      br[k].y22=j+10;
	      br[k].p=a[k];
	      if((k+1)%7==0)
	       {
		i=170;
		j+=10;
	       }
	   }
	  totalb=91;
	  x1=297;
	  x2=343;
	  y1=468;
	  y2=478;
	  xx=320;
	  yy=462;
	  tx=0;
	  ty=0;
	 setcolor(15);
	 rectangle(1,40,629,479);  //out line for game
	 circle(xx,yy,5);           //ball
	 rectangle(x1,y1,x2,y2);   //bar


     while(1)    //bar  & ball controlling loop
	 {

	     setcolor(BLACK);
	      outtextxy(556,20,ch);
	     setcolor(RED);
	     itoa(scor,ch,10);
	    outtextxy(556,20,ch);
	      setcolor(0);
	      circle(xx,yy,5);
	    cheack();        //call for ckeack touched ball
	  setcolor(15);
	 rectangle(1,40,629,479);

	  scor=100;
	  for(int i=0;i<totalb;i++)    //print only those ball who r not touched
	  {
	   if(br[i].p==1)
	    {
	      setcolor(WHITE);
	      rectangle(br[i].x11,br[i].y11,br[i].x22,br[i].y22);
	      setfillstyle(2,GREEN);
	      floodfill(br[i].x11+1,br[i].y11+1,WHITE);
	    }
	   else if(br[i].p==2)
	    {
	      setcolor(RED);
	      rectangle(br[i].x11,br[i].y11,br[i].x22,br[i].y22);
	      setfillstyle(1,BROWN);
	      floodfill(br[i].x11+1,br[i].y11+1,RED);
	    }


	    else scor++;

	     }

	   if(scor==237)
	    break;
	  if(kbhit())   //take input for bar where direction he has to go
	  {
	    char ch=getch();

	    if(ch==77&&x2<=623)   //go right
	     {
	       setcolor(0);
		rectangle(x1,y1,x2,y2);
		x1+=10;
		x2+=10;

	     }

	    else if(ch==75&&x1>=6)     //go left
	     {
	      setcolor(0);
	       rectangle(x1,y1,x2,y2);
	       x1-=10;
	       x2-=10;


	     }
	    else if(ch==27)   //close the game
	     {
		 break;
	     }
	  }

	  setcolor(15);
	  rectangle(x1,y1,x2,y2);

	 if(yy+5==467)  //when ball is in the line of bar
	  {
	     if(xx>=x1&&xx<=x2)
	       {
		 if(xx>=((x1+x2)/2-1)-3&&xx<=((x1+x2)/2+1)+3)
		      {
		       tx=0;
		       ty=-5;
		      }
		 else if(xx>=((x1+x2)/2)-23&&xx<=((x1+x2)/2))
		       {
			 tx=-3;
			 ty=-5;
		       }
		 else if(xx<=((x1+x2)/2)+23&&xx>=((x1+x2)/2))
			{
			 tx=3;
			 ty=-5;
			}
		  else if(xx>=((x1+x2)/2)-53&&xx<=((x1+x2)/2))
		       {
			 tx=-6;
			 ty=-5;
		       }
		 else if(xx<=((x1+x2)/2)+53&&xx>=((x1+x2)/2))
			{
			 tx=6;
			 ty=-5;
			}

	       }

	     else
	      {
	      // cleardevice();
	      setcolor(BLACK);
	      outtextxy(148,20,chh);
	      rectangle(x1,y1,x2,y2);
	      life--;
	      setcolor(RED);
	      itoa(life,chh,10);
	      outtextxy(148,20,chh);


	       if(life==0)
		{
		 getch();
		 break;
		 }
		x1=297;
	       x2=343;
	      y1=468;
	     y2=478;
	    xx=320;
	   yy=462;
	  tx=0;
	 ty=0;
	      }

	  }

	 else if(xx-5<3||xx+5>627)    //side line
	  {
	   tx=-tx;
	  }

	 else if(yy-5<40)        //upper line
	  {
	   ty*=-1;
	  }

	  xx+=tx;
	  yy+=ty;

	 setcolor(WHITE);
	  circle(xx,yy,5);
	  delay(20);


	 }
      cleardevice();
      take_score();
 }


void controls()       //how to control game
 {
  cleardevice();
  load_mouse_driver() ;
  outtextxy(100,100,"Left                       ->");
  outtextxy(100,130,"Right                      <-");
  outtextxy(10,400,"Back");
  while(1)
   {
	   int x,y,cl;

	   in.x.ax=3;
	   int86(0x33,&in,&out);

	   x=out.x.cx;      // To get x coordinate
	   y=out.x.dx;      // To get y coordinate
	   cl=out.x.bx;

	   if(x>=10&&x<=42&&y>=400&&y<=408&&cl==1) //back to manu from controls
		     {
		      cleardevice();
		      break;
		     }
   }
 }

int yes_no()  //exit or not
 {
  rectangle(200,185,370,200);
  setfillstyle(1,BLUE);
  setcolor(15);
  outtextxy(201,189,"ARE YOU WANT TO EXIT?");
  floodfill(201,186,15);
  rectangle(200,200,370,300);
  setfillstyle(1,15);
  floodfill(201,201,15);
  setcolor(BLACK);
  outtextxy(220,246,"YES");
  outtextxy(334,246,"NO");

  while(1)
   {
     int x,y,cl,a;


       in.x.ax=3;
       int86(0x33,&in,&out);

       x=out.x.cx;      // To get x coordinate
       y=out.x.dx;      // To get y coordinate
       cl=out.x.bx;     // 1/0 ; 1 for mouse click

      if(x>=220&&x<=244&&y>=246&&y<=254&&cl==1)
       return 1;
      if(x>=334&&x<=350&&y>=246&&y<=254&&cl==1)
       return 0;

   }

 }



 void menu()                  //game manu
	{
	 setcolor(BROWN);
	 settextstyle(7,0,5);
	 outtextxy(50,5,"BRICK BREAKING GAME");


	 setcolor(15);
	 settextstyle(0,0,1);
	 outtextxy(250,100,"New Game");
	 outtextxy(250,150,"Controls");
	 outtextxy(250,200,"Help");
	 outtextxy(250,250,"High score");
	 outtextxy(250,300,"Restore");
	 outtextxy(250,350,"Exit");
	}
void take_score()     //take input for making highscore
 {
  FILE *fp;
  int i,j;
  fp=fopen("c:\\tc\\High_score.txt","r");
  fread(&take,sizeof(take[0]),3,fp);
  fclose(fp);
  if(scor<take[2].num);

  else
   {
   int i=0;


    printf("Your name:");
    gets(take[2].name);
    take[2].num = scor;
    for(i=0;i<2;i++)
     {
      for(j=i+1;j<3;j++)
       {
	if(take[i].num<take[j].num)
	 {
	  temp=take[i];
	  take[i]=take[j];
	  take[j]=temp;
	 }
       }
     }
   fp= fopen("c:\\tc\\High_score.txt","w");
   fwrite(&take,sizeof(take[0]),3,fp);
   fclose(fp);
   }
      cleardevice();
    High();

   }
void High()         //show highscore
{
 FILE *fp;
 fp=fopen("c;\\tc\\High_score.txt","r") ;
  fread(&take,sizeof(take[0]),3,fp);
  fclose(fp);
int i;
  for(i=0;i<=650;i++)
  {
  setcolor(BLUE);
  rectangle(i,58,i,64);
  delay(2);
  setcolor(YELLOW);
  rectangle(i,404,i,410);
  delay(2);
  }
  for(i=410;i>=58;i--)
  {
  setcolor(GREEN);
  rectangle(640,i,634,i);
  delay(2);
  setcolor(LIGHTRED);
  rectangle(0,i,6,i);
  delay(2);
  }
  for(i=150;i<=210;i++)
	{
	   setcolor(BLUE);
	   line(i,120,i,140);
	   setcolor(BLACK);

	   outtextxy(170,125,"Name");
	   delay(20);
	  }

     for(i=350;i<=410;i++)
	 {
	   setcolor(RED);
	   line(i,120,i,140);
	   setcolor(BLACK);
	   outtextxy(360,125,"Score");
	   delay(20);


	  }
       if(take[0].num)
       for(i=50;i<=150;i++)
       {
	  setcolor(YELLOW);
	 outtextxy(i,160,take[0].name);
	 setcolor(BLACK);
	 delay(20);
	 if(i!=150)
	  {
	 outtextxy(i,160,take[0].name);
	  }


	  delay(10);
	  }

	if(take[1].num)
       for(i=50;i<=150;i++)
       {
	  setcolor(LIGHTGREEN);
	 outtextxy(i,190,take[1].name);
	 setcolor(BLACK);
	 delay(20);
	 if(i!=150)
	  {
	 outtextxy(i,190,take[1].name);
	  }


	  delay(10);
       }

	if(take[2].num)
       for(i=50;i<=150;i++)
       {
	  setcolor(LIGHTRED);
	 outtextxy(i,220,take[2].name);
	 setcolor(BLACK);
	 delay(20);
	 if(i!=150)
	  {
	 outtextxy(i,220,take[2].name);
	  }


	  delay(10);
	  }
	int j=160;
	setcolor(RED);
       for(i=0,j;i<3;j+=30,i++)
	{
	  char t[100];

	  itoa(take[i].num,t,10);
	  if(take[i].num)
	  outtextxy(360,j,t);
	}

   getch();
    cleardevice();
   }
void helpmenu()        //help player to play game
{
int i;
for(i=0;i<=650;i++)
{
setcolor(BLUE);
rectangle(i,58,i,64);
delay(2);
setcolor(YELLOW);
rectangle(i,404,i,410);
delay(2);
}
for(i=410;i>=58;i--)
{
setcolor(GREEN);
rectangle(640,i,634,i);
delay(2);
setcolor(LIGHTRED);
rectangle(0,i,6,i);
delay(2);
}
for(i=7;i<=633;i++)
{
setcolor(LIGHTGRAY);
rectangle(i,64,i,130);
delay(2);
}
for(i=10;i<=235;i++) //HELP design
{
setcolor(RED);
settextstyle(4,0,5);
outtextxy(i,60,"HELP");
delay(20);
if(i!=235)
{
setcolor(LIGHTGRAY);
outtextxy(i,60,"HELP");
}
}
setcolor(LIGHTCYAN);
rectangle(56,135,584,350);
setcolor(LIGHTGREEN);
rectangle(7,355,633,403);
setfillstyle(1,LIGHTGREEN);
floodfill(10,360,LIGHTGREEN);
setcolor(LIGHTCYAN);
rectangle(7,131,633,354);
setfillstyle(1,LIGHTCYAN);
floodfill(9,133,LIGHTCYAN);
int k;
for(i=300;i>=150;i--)
{
setcolor(BLUE);
settextstyle(4,0,4);
outtextxy(i,360,"ENJOY THE GAME");
delay(40);
if(i!=150)
{
setcolor(LIGHTGREEN);
outtextxy(i,360,"ENJOY THE GAME");
}
}
for(k=290;k>=160;k--)
{
setcolor(RED);
settextstyle(2,0,5);
outtextxy(150,k,"You have to break the bricks with the ball");
outtextxy(150,k+10,"Use the arrow key for moving the bar.");
outtextxy(150,k+20,"If you break one brick you get 1 point.");
outtextxy(150,k+30,"If you complete one level you get bonus prizes.");
outtextxy(150,k+40,"But if you fail to catch the ball you lose your life.");
setcolor(BLUE);
delay(40);
setcolor(BLACK);
settextstyle(2,0,5);
outtextxy(150,k,"You have to break the bricks with the ball");
outtextxy(150,k+10,"Use the arrow key for moving the bar.");
outtextxy(150,k+20,"If you break one brick you get 1 point.");
outtextxy(150,k+30,"If you complete one level you get bonus prizes.");
outtextxy(150,k+40,"But if you fail to catch the ball you lose your life.");
delay(20);
}


   getch();

}

void restor()
 {
   FILE *fp;
  fp=fopen("c:\\tc\\High_score.txt","w");

     take[0].num=0;
     take[1].num=0;
     take[2].num=0;
   fwrite(&take,sizeof(take[0]),3,fp);
   fclose(fp);
 }

