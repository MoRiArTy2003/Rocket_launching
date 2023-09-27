/*Rocket Launching Project By IOTE28 Ameya Mhatre
			      IOTE23 Anisha Koratala
			      IOTE12 Sandeep Gurram */
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#include<iostream.h>

char *fname[] = {
"GO!!!",
"Mission Accomplished!!",
"SMALL font",
"SANS SERIF font",
"Gothic!"
};
//******************FLOODFILL ALGORITHM*************************************
void floodfill(int x,int y,int old,int fill)
{
 int current;
 current = getpixel(x,y);
 if(current==old)
 {
  putpixel(x,y,fill);
  floodfill(x+1,y,old,fill);
  floodfill(x-1,y,old,fill);
  floodfill(x,y+1,old,fill);
  floodfill(x,y-1,old,fill);


 }
																																																																						}
//******************BRESENHAM'S LINE DRAWING ALGORITHM************************
int sign(int x)
{
 if(x<0) return -1;
 if(x>0) return 1;
 else return 0;
}
void line(int x1, int y1, int x2, int y2 ,int c)
{
 int x,y,dx,dy,s1,s2,e;
 dx=abs(x2-x1);
 dy=abs(y2-y1);
 s1=sign(x2-x1);
 s2=sign(y2-y1);
 x=x1;
 y=y1;
 int temp, flag = 0;
 if(dy>dx)
 {
  temp=dx;
  dx=dy;
  dy=temp;
  flag=1;
 }
 e=(2*dy)-dx;
 int i;
 for(i=1;i<=dx;i++)
 {
  putpixel(x,y,c);
  while(e>=0)
  {
   if(flag==1)
   {
    x=x+s1;
   }
   else
   {
    y=y+s2;
   }
   e=e-2*dx;
  }
  if(flag==1)
  y=y+s2;
  else
  x=x+s1;
  e=e+2*dy;
 }
}
//************************MIDPOINT CIRCLE ALGORITHM**************************
void circle(int a, int b, int r, int c)
{
 int x,y,e;
 x=0;
 y=r;
 e=1-r;
 do
 {
  if(e<0)
  {
   x=x+1;
   e=e+(2*x)+1;
  }
  else
  {
   x=x+1;
   y=y-1;
   e=e+2*x-2*y+1;
  }
  putpixel(a+x,b+y,c);
  putpixel(a+x,b-y,c);
  putpixel(a-x,b+y,c);
  putpixel(a-x,b-y,c);
  putpixel(a+y,b+x,c);
  putpixel(a-y,b+x,c);
  putpixel(a+y,b-x,c);
  putpixel(a-y,b-x,c);
 }
 while(x<y);
}

void bot(int i,int y, int c)
{
 setcolor(c);
 rectangle(90+i,380+y,116+i,395+y);
 circle(96+i,386+y,2);
 circle(110+i,386+y,2);
 line(100+i,386+y,100+i,405+y);
 line(106+i,395+y,106+i,405+y);
 setfillstyle(SOLID_FILL,RED);
 int p[]={86+i,400+y,86+i,440+y,120+i,440+y,120+i,400+y};
 fillpoly(4,p);

 setfillstyle(SOLID_FILL,BLUE);
 setcolor(DARKGRAY);
 int h[]={97+i,430+y,97+i,445+y,101+i,445+y,101+i,430+y};
 fillpoly(4,h);
 setcolor(c);
 line(90+i,445+y,110+i,445+y);
 setfillstyle(SOLID_FILL,BLACK);
 setcolor(BLACK);
 circle(100+i,410+y,3);
 circle(100+i,415+y,3);
 circle(100+i,420+y,3);
 circle(111+i,410+y,3);
 circle(111+i,415+y,3);
 circle(111+i,420+y,3);
 setfillstyle(SOLID_FILL,BLACK);
 setcolor(BLACK);
 circle(86+i,448+y,8);
 circle(120+i,448+y,8);
 floodfill(89+i,448+y,0);
 floodfill(119+i,448+y,0);
 line(86+i,456+y,120+i,456+y);
}
//*************************FRACTAL*******************************************
double angle=30*(3.14/180);

void fractal(int l,double a,int x,int y)
{
 if(l!=0)
 {
  double a1=a+angle;
  double a2=a-angle;
  int x1=x+l*cos(a1);
  int y1=y-l*sin(a1);
  line(x,y,x1,y1);
  fractal(l/2,a1,x1,y1);
  x1=x+l*cos(a2);
  y1=y+l*sin(a2);
  line(x,y,x1,y1);
  fractal(l/2,a2,x1,y1);
  a1=a1+angle;
  a2=a2-angle;
  x1=x+l*cos(a1);
  y1=y-l*sin(a1);
  line(x,y,x1,y1);
  fractal(l/2,a1,x1,y1);
  x1=x+l*cos(a2);
  y1=y-l*sin(a2);
  line(x,y,x1,y1);
  fractal(l/2,a2,x1,y1);
 }
}

void main()
{
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 int i,x,y,style,midx,midy;
 float a;

 midx = getmaxx() /2;
 midy = getmaxy() /2;

 cout << "\n\n\n\n\n";
 cout << "W"; delay(50);
 cout << "E"; delay(50);
 cout << "L"; delay(50);
 cout << "C"; delay(50);
 cout << "O"; delay(50);
 cout << "M"; delay(50);
 cout << "E\t"; delay(50);

 cout << "T"; delay(50);
 cout << "O\t"; delay(50);

 cout << "I"; delay(50);
 cout << "S"; delay(50);
 cout << "R"; delay(50);
 cout << "O\t"; delay(50);

 cout << "I"; delay(50);
 cout << "N"; delay(50);
 cout << "T"; delay(50);
 cout << "E"; delay(50);
 cout << "R"; delay(50);
 cout << "N"; delay(50);
 cout << "A"; delay(50);
 cout << "T"; delay(50);
 cout << "I"; delay(50);
 cout << "O"; delay(50);
 cout << "N"; delay(50);
 cout << "A"; delay(50);
 cout << "L\t"; delay(50);

 cout << "\tS"; delay(50);
 cout << "P"; delay(50);
 cout << "A"; delay(50);
 cout << "C"; delay(50);
 cout << "E"; delay(50);

 cout << "\tS"; delay(50);
 cout << "T"; delay(50);
 cout << "A"; delay(50);
 cout << "T"; delay(50);
 cout << "I"; delay(50);
 cout << "O"; delay(50);
 cout << "N"; delay(50);
 cout << "."; delay(50);
 cout << "\n\n";

 delay(2000);

 cout << "\tT"; delay(50);
 cout << "H"; delay(50);
 cout << "I"; delay(50);
 cout << "S"; delay(50);

 cout << "\tI"; delay(50);
 cout << "S"; delay(50);

 cout << "\tM"; delay(50);
 cout << "O"; delay(50);
 cout << "R"; delay(50);
 cout << "I"; delay(50);
 cout << "A"; delay(50);
 cout << "R"; delay(50);
 cout << "T"; delay(50);
 cout << "Y"; delay(50);

/* cout << "\t&"; delay(50);


 cout << "\tT"; delay(50);
 cout << "E"; delay(50);
 cout << "A"; delay(50);
 cout << "M"; delay(50);*/

 cout << "\tR"; delay(50);
 cout << "E"; delay(50);
 cout << "P"; delay(50);
 cout << "O"; delay(50);
 cout << "R"; delay(50);
 cout << "T"; delay(50);
 cout << "I"; delay(50);
 cout << "N"; delay(50);
 cout << "G"; delay(50);
 cout << "."; delay(50);
 cout << "\n\n";

 delay(2000);

 cout << "\tI"; delay(50);
 cout << "S"; delay(50);
 cout << "R"; delay(50);
 cout << "O"; delay(50);

 cout << "\tI"; delay(50);
 cout << "S"; delay(50);

 cout << "\tR"; delay(50);
 cout << "E"; delay(50);
 cout << "A"; delay(50);
 cout << "D"; delay(50);
 cout << "Y"; delay(50);

 cout << "\tT"; delay(50);
 cout << "O"; delay(50);

 cout << "\tT"; delay(50);
 cout << "A"; delay(50);
 cout << "K"; delay(50);
 cout << "E\t"; delay(50);

 cout << "O"; delay(50);
 cout << "F"; delay(50);
 cout << "F"; delay(50);

 cout << "\tG"; delay(50);
 cout << "S"; delay(50);
 cout << "A"; delay(50);
 cout << "T"; delay(50);
 cout << "-"; delay(50);
 cout << "1"; delay(50);

 cout << "\t2"; delay(50);
 cout << "0"; delay(50);
 cout << "2"; delay(50);
 cout << "2"; delay(50);

 cout << "\tI"; delay(50);
 cout << "N"; delay(50);

 cout << "\tA\t"; delay(50);

 cout << "F"; delay(50);
 cout << "E"; delay(50);
 cout << "W"; delay(50);

 cout << "\tS"; delay(50);
 cout << "E"; delay(50);
 cout << "C"; delay(50);
 cout << "O"; delay(50);
 cout << "N"; delay(50);
 cout << "D"; delay(50);
 cout << "S"; delay(50);
 cout << "."; delay(50);

 cout << "\n\n";

 delay(2000);

 cout << "\tP"; delay(50);
 cout << "L"; delay(50);
 cout << "E"; delay(50);
 cout << "A"; delay(50);
 cout << "S"; delay(50);
 cout << "E"; delay(50);

 cout << "\tT"; delay(50);
 cout << "I"; delay(50);
 cout << "G"; delay(50);
 cout << "H"; delay(50);
 cout << "T"; delay(50);
 cout << "E"; delay(50);
 cout << "N"; delay(50);

 cout << "\tY"; delay(50);
 cout << "O"; delay(50);
 cout << "U"; delay(50);
 cout << "R"; delay(50);

 cout << "\tB"; delay(50);
 cout << "E"; delay(50);
 cout << "L"; delay(50);
 cout << "T"; delay(50);
 cout << "S"; delay(50);

 cout << "\t!"; delay(50);
 cout << "\n\n";

 delay(2000);
 cout << "\tP"; delay(50);
 cout << "L"; delay(50);
 cout << "E"; delay(50);
 cout << "A"; delay(50);
 cout << "S"; delay(50);
 cout << "E"; delay(50);

 cout << "\tE"; delay(50);
 cout << "N"; delay(50);
 cout << "T"; delay(50);
 cout << "E"; delay(50);
 cout << "R"; delay(50);

 cout <<"\n\n";

 delay(2000);
//For Bot Animation
 for(int b=1;b<300;b++)
 {
  bot(b,1,2);
  bot(50+b,1,14);
  setcolor(RED);
  line(100,450,400,450);
  setcolor(BLUE);
  rectangle(400,350,500,450);
  delay(10);
  cleardevice();
 }

 cout << "\tO"; delay(50);
 cout << "V"; delay(50);
 cout << "E"; delay(50);
 cout << "R"; delay(50);
 cout << "."; delay(50);
 delay(1000);
 cout << "\n\n";

 cout << "\tL"; delay(50);
 cout << "A"; delay(50);
 cout << "U"; delay(50);
 cout << "N"; delay(50);
 cout << "C"; delay(50);
 cout << "H"; delay(50);
 cout << "I"; delay(50);
 cout << "N"; delay(50);
 cout << "G"; delay(50);
 cout << "."; delay(50);
 cout << "."; delay(50);
 cout << "."; delay(50);

 delay(1000);

 cout << "[3]..."; delay(400);
 cout << "[2].."; delay(400);
 cout << "[1]."; delay(400);

 cleardevice();
 setcolor(LIGHTGREEN);
 settextjustify(CENTER_TEXT, CENTER_TEXT);

 style = DEFAULT_FONT;

 settextstyle(style,HORIZ_DIR,8);
 outtextxy(midx,midy,fname[style]);
 delay(1800);

 cleardevice();

 for(i=0;i<=100;i++)
 {
  if(i<20)
  setbkcolor(9);
  else
  setbkcolor(0);
  if(i<=45)
  {
   a=3.142*i/100;
   delay(30);
    //Rocket
   line(300*(cos(a))+300*(sin(a)),300*(cos(a))-300*(sin(a)),350*(cos(a))+300*(sin(a)),300*(cos(a))-350*(sin(a)));
   line(350*(cos(a))+300*(sin(a)),300*(cos(a))-350*(sin(a)),350*(cos(a))+400*(sin(a)),400*(cos(a))-350*(sin(a)));
   line(300*(cos(a))+300*(sin(a)),300*(cos(a))-300*(sin(a)),300*(cos(a))+400*(sin(a)),400*(cos(a))-300*(sin(a)));
   line(270*(cos(a))+400*(sin(a)),400*(cos(a))-270*(sin(a)),380*(cos(a))+400*(sin(a)),400*(cos(a))-380*(sin(a)));
   line(300*(cos(a))+350*(sin(a)),350*(cos(a))-300*(sin(a)),270*(cos(a))+400*(sin(a)),400*(cos(a))-270*(sin(a)));
   line(350*(cos(a))+350*(sin(a)),350*(cos(a))-350*(sin(a)),380*(cos(a))+400*(sin(a)),400*(cos(a))-380*(sin(a)));
   line(300*(cos(a))+300*(sin(a)),300*(cos(a))-300*(sin(a)),325*(cos(a))+260*(sin(a)),260*(cos(a))-325*(sin(a)));
   line(325*(cos(a))+260*(sin(a)),260*(cos(a))-325*(sin(a)),350*(cos(a))+300*(sin(a)),300*(cos(a))-350*(sin(a)));
   //Letter G
   line(318*(cos(a))+320*(sin(a)),320*(cos(a))-318*(sin(a)),335*(cos(a))+320*(sin(a)),320*(cos(a))-335*(sin(a)));
   line(318*(cos(a))+320*(sin(a)),320*(cos(a))-318*(sin(a)),318*(cos(a))+340*(sin(a)),340*(cos(a))-318*(sin(a)));
   line(318*(cos(a))+340*(sin(a)),340*(cos(a))-318*(sin(a)),335*(cos(a))+340*(sin(a)),340*(cos(a))-335*(sin(a)));
   line(335*(cos(a))+340*(sin(a)),340*(cos(a))-335*(sin(a)),335*(cos(a))+330*(sin(a)),330*(cos(a))-335*(sin(a)));
   line(325*(cos(a))+330*(sin(a)),330*(cos(a))-335*(sin(a)),335*(cos(a))+330*(sin(a)),330*(cos(a))-335*(sin(a)));

   //Launching Smoke
   if(i==0)
   {
    delay(1400);
    for(int k=0; k<70; k++)
    {
     delay(100);
     circle(250,400,k,8);
     circle(270,400,k,8);
     circle(285,400,k+10,7);
     circle(318,400,k+30,7);
     circle(335,400,k+10,7);
     circle(370,400,k+10,7);
     circle(390,400,k,8);
     circle(410,400,k,8);
    }
   }
   if(i%2==0)
   {
   for(int v=10; v>=0; v--)
   {
    circle(318*(cos(a))+400*(sin(a)),400*(cos(a))-318*(sin(a)),v,14);
    circle(335*(cos(a))+400*(sin(a)),400*(cos(a))-335*(sin(a)),v,14);
   }
    circle(325*(cos(a))+260*(sin(a)),260*(cos(a))-325*(sin(a)),5,12);
    circle(325*(cos(a))+260*(sin(a)),260*(cos(a))-325*(sin(a)),4,12);
    circle(325*(cos(a))+260*(sin(a)),260*(cos(a))-325*(sin(a)),3,12);
    circle(325*(cos(a))+260*(sin(a)),260*(cos(a))-325*(sin(a)),2,12);
    circle(325*(cos(a))+260*(sin(a)),260*(cos(a))-325*(sin(a)),1,12);
   }
   else
   {
    for(int w=10; w>=10; w--)
    {
     circle(335*(cos(a))+400*(sin(a)),400*(cos(a))-33*(sin(a)),w,14);
     circle(325*(cos(a))+400*(sin(a)),400*(cos(a))-335*(sin(a)),w,14);
     circle(350*(cos(a))+400*(sin(a)),400*(cos(a))-335*(sin(a)),w,14);
    }
   }
  }
  circle(250,300+i,400-i,1);
  circle(250,300+i,399-i,1);
  circle(250,300+i,398-i,1);
  circle(250,300+i,397-i,1);
  circle(250,300+i,396-i,1);
  circle(250,300+i,395-i,1);
  circle(250,300+i,394-i,1);
  circle(250,300+i,393-i,1);
  circle(250,300+i,392-i,1);
  circle(250,300+i,391-i,1);
  circle(250,300+i,390-i,1);
  circle(250,300+i,389-i,1);
  circle(250,300+i,388-i,1);

  cleardevice();

}
for(i=0;i<320;i++)
{
 if(i<=300)
 {
  cleardevice();
  line(300,50+i,350,50+i,15);   //Upper Horizon
  line(300,50+i,300,150+i,15);   //Left Vertical

  line(270,150+i,380,150+i,15); //Bottom Horizon
  line(350,50+i,350,150+i,15);  //Right Vertical

  line(300,100+i,270,150+i,15); //Left Slant
  line(350,100+i,380,150+i,15); //Right Slant

  line(300,50+i,325,10+i,15);   //Top Left Slant
  line(325,10+i,350,50+i,15);   //Top Right Slant

  //Letter G
  line(318,70+i,335,70+i,2);
  line(318,70+i,318,90+i,2);
  line(318,90+i,335,90+i,2);
  line(335,90+i,335,80+i,2);
  line(325,80+i,335,80+i,2);

  setcolor(2);
  if(i>=180)
  {
   rectangle(0,450,getmaxx(),getmaxy());
   delay(10);
  }
 }
 else
 {
  bot(330,1,2);
  bot(100,1,14);
  delay(10);
 }
 if(i>=250)
 {
  setcolor(RED);
  fractal(40,45*(3.14/180),100,380);
  line(100,380,100,450,1);
  setcolor(BLUE);
  fractal(40,45*(3.14/180),550,380);
  line(550,380,550,450,6);
 }
}
 setcolor(LIGHTGREEN);
 settextjustify(CENTER_TEXT,CENTER_TEXT);
 style=TRIPLEX_FONT;
 cleardevice();
 settextstyle(style,HORIZ_DIR,6);
 outtextxy(midx,midy,fname[style]);
 getch();
 closegraph();
}