#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
#include<iostream.h>
#include<string.h>
#include<fstream.h>
#include<ctype.h>
int flag=0,yz,status=0,stat=0;
int pl=1,izy,ch=0,flat=0,jmn,kol=0;
char c;
class sticky
{public:char sticky[200];
}s;
void ip()
{ofstream f("sticky.dat",ios::binary|ios::in|ios::out|ios::app);
{clrscr();
cout<<"                               STICKY NOTES";
cout<<"\n--------------------------------------------------------------------------------";
do
{
cout<<"   ";
gets(s.sticky);
}while(strcmpi(s.sticky,"close"));
cout<<"\n________________________________________________________________________________";
}f.write((char *)&s,sizeof(s));
f.close();
}
void op()
{ifstream f1("sticky.dat",ios::binary|ios::in|ios::out|ios::app);
{clrscr();
while(!f1.eof())
{f1.read((char *)&s,sizeof(s));
{cout<<"    "<<s.sticky;
}
}f1.close();
getch();
}
}

void title();
void instructions1();
struct total
{
	char one[20];
	char two[20];
	char hun[30];
	char tho[30];
	char thu[30];
	char lak[30];
	char tlk[30];
	int o,tl,tu,tw,h,th,l;
};
struct acc
{
	char accname[30];
	char password[30];
	char imp[40];
}A;
class file
{
	total t;
	acc a;
	char exp[30];
	char product[17][30];
	int q[17];
	float r[17];
	double amt[17];
	long tot;
	int invoice;
	int login();
	int reg();
	int incheck(int);
	public:
		file();
		void make();
		void cacc();
		void setting();
		void open();
		void delacc();
		void del();
		void tinw(long n);
		void cpass();
		int use();
		void cimp();
};
int n;
file::file()
{
	strcpy(t.one,"\0");
	strcpy(t.two,"\0");
	strcpy(t.hun,"\0");
	strcpy(t.tho,"\0");
	strcpy(t.tho,"\0");
	strcpy(t.lak,"\0");
	strcpy(t.tlk,"\0");
}
int file::login()
{
	int c=0;
	cleardevice();
	gotoxy(3,2);
	cout<<"<-Back(ESC)";
	gotoxy(30,12);
	cout<<"Account name:";
	int ex=0;
	int x;
	a.accname[0]='\0';
	do
	{
		x=0;
		while(1)
		{
			char s=getch();
			if(s==13)
				break;
			if(s==27)
				return 10;
			if(s=='\b')
			{
				cout<<'\b'<<' '<<'\b';
				a.accname[--ex]='\0';
				continue;
			}
			cout<<s;
			a.accname[ex++]=s;
		}
		a.accname[ex]='\0';
		if(strcmp(a.accname,"\0")==0)
			x++;
	}while(x!=0);
	gotoxy(30,13);
	cout<<"Password:";
	char m,n[20];
	ex=0;
	do
	{
		int x=0;
		for(int i=0;i<20;i++)
		{
			m=getch();
			if(m==27)
				return 10;
			if(isalnum(m))
			{
				n[x++]=m;
				cout<<'*';
			}
			else if(m=='\b')
			{
				if(x>0)
				{
					cout<<'\b'<<" "<<'\b';
					n[x--]='\0';
				}
			}
			else
				break;
		}
		n[x]='\0';
		if(strcmp(n,"\0")==0)
			ex++;
	}while(ex!=0);
	strcpy(a.password,n);
	fstream f;
	f.open("os.dat",ios::in|ios::out|ios::binary|ios::app);
	acc ac;
	while(f.read((char*)&ac,sizeof(ac)))
	{
		if(strcmp(a.accname,ac.accname)==0)
			c++;
		if(strcmp(a.password,ac.password)==0)
			c++;
		if(c==2)
		{
			A=ac;
			break;
		}
		else
			c=0;
	}
	f.close();
	return c;
}
int file::reg()

{
	int c=0;
	fstream f;
	f.open("os.dat",ios::in|ios::out|ios::app|ios::binary);
	acc ac;
	cleardevice();
	X:
	gotoxy(3,2);
	cout<<"<-Back(ESC)";
	gotoxy(30,12);
	cout<<"Enter account name:";
	int ex=0;
	int x;
	do
	{
		x=0;
		while(1)
		{
			char s=getch();
			if(s==13)
				break;
			if(s==27)
				return 10;
			if(s=='\b')
			{
				cout<<'\b'<<' '<<'\b';
				a.accname[--ex]='\0';
				continue;
			}
			cout<<s;
			a.accname[ex++]=s;
		}
		a.accname[ex]='\0';
		if(strcmp(a.accname,"\0")==0)
			x++;
	}while(x!=0);
	gotoxy(30,13);
	cout<<"Enter password:";
	char m,n[20];
	ex=0;
	do
	{
		ex=0;
		int x=0;
		for(int i=0;i<20;i++)
		{
			m=getch();
			if(m==27)
				return 10;
			if(isalnum(m))
			{
				n[x++]=m;
				cout<<'*';
			}
			else if(m=='\b')
			{
				if(x>0)
				{
					cout<<'\b'<<' '<<'\b';
					n[--x]='\0';
				}
			}
			else
				break;
		}
		n[x]='\0';
		if(strcmpi(n,"\0")==0)
			ex++;
	}while(ex!=0);
	strcpy(a.password,n);
	gotoxy(30,14);
	cout<<"Enter company name:";
	do
	{
		x=0;
		while(1)
		{
			char s=getch();
			if(s==13)
				break;
			if(s==27)
				return 10;
			if(s=='\b')
			{
				cout<<'\b'<<' '<<'\b';
				a.imp[--ex]='\0';
				continue;
			}
			cout<<s;
			a.imp[ex++]=s;
		}
		a.imp[ex]='\0';
		if(strcmp(a.imp,"\0")==0)
			x++;
	}while(x!=0);
	int q=0;
	do
	{
		q=0;
		while(f.read((char*)&ac,sizeof(ac)))
		{
			if(strcmpi(ac.accname,a.accname)==0)
			{
				q++;
				break;
			}
		}
		if(q==1)
		{
			cleardevice();
			gotoxy(30,11);
			cout<<"Account name already exists!!";
			f.close();
			f.open("os.dat",ios::in|ios::out|ios::app|ios::binary);
			goto X;
		}
	}while(q!=0);
	f.close();
	f.open("os.dat",ios::in|ios::out|ios::app|ios::binary);
	f.write((char*)&a,sizeof(a));
	A=a;
	cleardevice();
	char fn[100];
	strcpy(fn,a.imp);
	strcat(fn,".dat");
	fstream file(fn,ios::binary|ios::nocreate|ios::noreplace);
	file.close();
	char ifn[100];
	strcpy(ifn,"Invoice");
	strcat(ifn,a.imp);
	strcat(ifn,".txt");
	fstream file1(ifn,ios::out);
	file1<<0;
	file1.close();
	gotoxy(30,12);
	cout<<"Account created";
	getch();
	c=3;
	f.close();
	return c;
}
int file::use()
{
	acc ac;
	int x;
	int c=5;
	int f1=0;
	do
	{
		cleardevice();
		int i=0;
		while(1)
		{
			for(int x=0;x<3;x++)
			{
				gotoxy(31,12+x);
				cout<<"  ";
			}
			gotoxy(31,12+i);
			cout<<"=>";
			gotoxy(33,10);
			cout<<"\n                          FIRE SECURITY SYSTEMS";
			gotoxy(33,12);
			cout<<"1.Login";
			gotoxy(33,13);
			cout<<"2.Register";
			gotoxy(33,14);
			cout<<"3.Exit";
			if(kbhit())
			{
			char a=getch();
				if(a==80)
					if(i<2)
						i++;
				if(a==72)
					if(i>0)
						i--;
				if(a==13)
					break;
			}
			delay(80);
			delay(80);
		}
		switch(i)
		{
			case 0:
				x=1;
				break;
			case 1:
				x=2;
				break;
			case 2:
				exit(0);
		}
		switch(x)
		{
			case 1:
				c=login();
				f1++;
				if(c==10)
					f1=0;
				break;
			case 2:
				c=reg();
				f1++;
				if(c==10)
					f1=0;
				break;
			default:
				cleardevice();
				gotoxy(23,12);
				cout<<"Invalid choice!!! Please try again!!";
				delay(1000);
		}
	}while(f1==0);
	cleardevice();

	return c;
}
class tym
{
int hh,mm,ss,ms;
public:
void show()
{
if(ms>9)
{
ms=0;
ss++;
}
else if(ss>59)
{
ss=0;
mm++;
}
else if(mm>59)
{
mm=0;
hh++;
}
cout<<hh<<":"<<mm<<":"<<ss<<":"<<ms;
}

void inc()
{
ms++;
}

void cancel()
{
hh=mm=ss=ms=0;
}

tym()
{
hh=mm=ss=ms=0;
}
};

void title()
{
cout<<"\n press s for start ";
cout<<"\n press p for pause ";
cout<<"\n press t for stop ";
cout<<"\n press r for resume ";
cout<<"\n press c for cancel ";
}


struct bmpfileheader
{
   char type[2];					// Here are the letters { 'B' , 'M '}
   long int size;					//Size of the entire file
   char reserved[4];
   long int offbits;				//Offset of the bitmap in the file
};
struct bmpinfoheader
 {
	long int size;					//Size of bmpinfoheader
									//12 - OS/2 1.x format
									//40 - Windows 3.x format
																	//64 - OS/2 2.x format
   long int width;				//Horizontal width of bitmap in pixels
   long int height;				//Vertical height of bitmap in pixels
   int planes;						//Number of planes
   int bitcount;					//bits per pixel: 1, 4, 8, 24
										//This then indicates the number of colors
   long int compression;		                                        //0 - none
										//1 - RLE - 8 bit/pixel
										//2 - RLE - 4 bit/pixel
   long int sizeimage;  		//Size of the image in bytes
   long int xpm;           	//Horizontal Resolution: x pixels per meter
   long int ypm;					//Vertical Resolution: y pixels per meter
   long int colused;				//Number of colors used
   long int colimp;				//Number of important colors
};
struct RGBquad
{
	unsigned char blue,green,red;
	unsigned char resv;					//reserved
};

//void bmp_save(int x1,int y1,int x2,int y2,char *filename);
RGBquad *bmp_load(int x1,int y1,char *filename);
int init_graph();

void bmp_save(int x1,int y1,int x2,int y2,char *filename);
int init_graph()
{
	int gdriver =DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode,"C:\\TC\\BGI");
   errorcode = graphresult();
   if (errorcode != grOk)    /* an error occurred */
	{
		cout << "Error in graphical mode:\n" << grapherrormsg(errorcode) << endl;
      system ("pause");
      exit(1);               /* return with error code */
   }
   return grOk;
}
char* currentWallpaper = "os.bmp";
RGBquad *bmp_load(int x1, int y1, char *filename)
   {
	   filename=currentWallpaper;
	register int i,j;
	int x2, y2;
	unsigned char c;
	bmpfileheader bmph;
	bmpinfoheader bmpi;
	RGBquad *rgb;

	ifstream img(filename,ios::in|ios::binary);
   if (!img) {
	cout << "The file " << filename << " does not exist." << endl;
		exit(EXIT_FAILURE);
   }

	img.read((char *)&bmph,sizeof(bmph));
	img.read((char *)&bmpi,sizeof(bmpi));

	if((bmph.type[0]!='B') || (bmph.type[1]!='M')) {
	cout << "BMP file does not have a header BM." << endl;
		img.close();
		exit(EXIT_FAILURE);
	};

	if((bmph.reserved[0] != '\0') ||
	   (bmph.reserved[1] != '\0') ||
	   (bmph.reserved[2] != '\0') ||
	   (bmph.reserved[3] != '\0'))
	 {
	   cout << "BMP file does not have the field bmph.reserved free." << endl;
		img.close();
		exit(EXIT_FAILURE);
	};

   if (bmpi.planes != 1)
    {
	cout << "BMP file has bmpi.planes != 1" << endl;
		img.close();
		exit(EXIT_FAILURE);
    }

   if (bmpi.compression!=0) {
	cout << "Compressed BMP File" << endl;
		cout << "Compressed BMP Files can't be read " << endl;
		img.close();
		exit(EXIT_FAILURE);
   }

   switch (bmpi.bitcount)
{
   case 1:    {
		cout << "Color format monochrome still not supported" << endl;
		img.close();
		exit(EXIT_FAILURE);
		break;
	      }
   case 4:
		if (getmaxcolor() < 15)
      {
	cout << "The current configuration does not allow 16 colors." << endl;
		exit(EXIT_FAILURE);
		}

		rgb = new RGBquad[1<<bmpi.bitcount];
		img.read((char *)rgb,sizeof(*rgb)*(1<<bmpi.bitcount));

	      for (i=0; i<=15 ; i++)
		{
			setrgbpalette(i,rgb[i].red>>2,rgb[i].green>>2,rgb[i].blue>>2);
			setpalette(i,i);
		}

		x2 = x1 + (int)bmpi.width;
		y2 = y1 + (int)bmpi.height;

		for(j=y2-1; j>=y1; j--) {			//Fix Photo j=y2
			for(i=x1; i<x2; i++) {        //Fix Photo i<=x2
				img.read((char *)&c,sizeof(c));
				putpixel(i,j,c>>4);
				i++;
				putpixel(i,j,(c & 15)); //c<<4)>>4);
			}
		}
		break;
	case 8:
		cout << "256 Color Format not supported." << endl;
		img.close();
		exit(EXIT_FAILURE);
		break;
   case 24:
		cout << "24 Color Format not supported." << endl;
		img.close();
		exit(EXIT_FAILURE);
		break;
   default:
	cout << "BMP file invalid" << endl;
		img.close();
		exit(EXIT_FAILURE);
   };       //	img.close();
	return rgb;
};
int checkmove();
int checkwin();
void board();
void dot();
void feedback();
char sq[9]={'1','2','3','4','5','6','7','8','9'};
void call();
int xyz;
void applock();
void case1();
void case3();
void case4();
void case6();
void case8();
union REGS i,o;
initmouse();
showmouse();
hidemouse();
void restrictmouse(int x1,int y1,int x2,int y2);
void getmousestatus( int *button,int *x,int *y);
void findday();
void menu();
void cal();
void loading();
void main()
{while(!kbhit())
{
pk:int gdriver=DETECT,gmode,errorcode;
initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
   int bkcol, maxcolor, x, y;
   char msg[80];
   maxcolor = getmaxcolor();

   /* for centering text messages */
  settextjustify(CENTER_TEXT, CENTER_TEXT);
   x = getmaxx() / 2;
   y = getmaxy() / 2;

 for (bkcol=0; bkcol<=maxcolor; bkcol++)
   { int xx,yy,b;
      cleardevice();
      setbkcolor(bkcol);
if (bkcol == WHITE||bkcol==YELLOW)
	 setcolor(EGA_RED);
      settextstyle(TRIPLEX_FONT,HORIZ_DIR,8);
      sprintf(msg, " -FIRE OS- ", bkcol);
      outtextxy(x, y, msg);
      delay(500);
}closegraph();
{clrscr();
int i;
union REGS l,o;
l.x.ax=1;
int86(0x33,&l,&o);
cout<<"\n\n\n\n\n\n\n\n\n\n\n                             FIRE OPERATINGSYSTEMS";
cout<<"\n                                                  - Light The Fire In You";
delay(3000);
clrscr();
lk:clrscr();
	int gdriver = DETECT,gdmode;
	initgraph(&gdriver, &gdmode,"C://TC//BGI");
	X:int f=1;
	int x;
	file b;
	x=b.use();
	while(x<2)
	{
		gotoxy(30,12);
		cout<<"Invalid account name or password";
		getch();
		x=b.use();
	}closegraph();
{
{
{
clrscr();
cout<<"\n\n\n\n\n\n\n\n\n";
}
loading();
delay(2000);
z:init_graph();
{bmp_load(0,0,"os.bmp");}
{
struct  time t;
   gettime(&t);
   {cout<<"  TIME:"<<(t.ti_hour-0);cout<<":"<<"0"<<(t.ti_min-0);
    struct date d;
getdate(&d);
cout<<"\n  DATE:"<<(d.da_day-0);cout<<":"<<(d.da_mon-0);cout<<":"<<d.da_year;
}
}
int ch;
int xx,yy,b;
  initmouse();
  restrictmouse(0,0,getmaxx(),getmaxy());
	    settextstyle(SMALL_FONT,HORIZ_DIR,6);
	     setcolor(EGA_GREEN);
  outtextxy(30,50,"1)SETTINGS");
  outtextxy(260,52,"2)STOPWATCH");
  outtextxy(510,52,"3)BINGO");
  outtextxy(30,190,"4)TIC TAC TOE");
  outtextxy(260,190,"5)STICKY NOTES");
  outtextxy(510,190,"6)CALCULATOR");
  outtextxy(30,325,"7)WALLPAPER");
  outtextxy(260,325,"8)CALENDER");
  outtextxy(510,325,"9)POWER");
	 showmouse();
  while(!kbhit())
  {
{if(xx>=250&&yy>=316&&xx<=385&&yy<=347)//fn8
     {
	getmousestatus(&b,&xx,&yy);
	if(b&1==1)
	{
	   hidemouse();
	   cleardevice();
	   menu();
	   goto z;
	}
     }
}
getmousestatus(&b,&xx,&yy);
     if(xx>=20&&yy>=50&&xx<=150&&yy<=73)//fn1
     {
	getmousestatus(&b,&xx,&yy);
	    if(b&1==1)
{ hidemouse();
	      cleardevice();
if (stat==1)
{y:int pass;
cout<<"\n                                APPLOCK";
 cout<<"\n ENTER PASSWORD:";
 cin>>pass;
 if(pass==1234)
 goto code;
 else
 goto y;
}
else
{code:
int a;
clrscr();
closegraph();
cout<<"\n 1.USER MANUAL\n 2.CHANGE PASSWORD";
cout<<"\n ENTER CHOICE:";
cin>>a;
switch (a)
{case 1:
cout<<"\n                                 USER MANUAL\n";
cout<<"\n * 1.THIS IS A VERY USERFRIENDLY OPERATING SYSTEM\n.";
cout<<"\n * 2.IN THIS OS WE HAVE KEPT EXIT BUTTON WHEREEVER NECESSARY....\n";
cout<<"\n * 3.STICKY NOTES IS THE PLACE WHERE YOU CAN TYPE WHAT EVER YOU WANT BUT YOU         CANT SAVE IT.\n";
cout<<"\n * 4.TO EXIT STICKY NOTES TYPE CLOSE IN A SEPERATE LINE.\n";
cout<<"\n * 5.JUST TYPE THE NAME OF THE FUNCTION YOU WANT TO OPEN....AND THE REST WILL        HAPPEN AUTOMATICALLY.\n";
cout<<"\n * 6.SELECT OPTION NO 9 TO SHUTDOWN THE OS.............";
getch();
clrscr();
cout<<"\n                                OS INFORMATION\n";
cout<<"\n                                FIRE OS V.2.0";
cout<<"\n FIRE operating system is created on c++ base to creat a userlink interface." ;
cout<<"\n\n We have created  an userlink interface with the knowledge what we have on c++.";
cout<<"\n\n This operating system	is created by\n VISHAL.S.V\n JAYASURYA\n AKSHAY PRASSANNA.";
cout<<"\n\n We hope that we have given an os which can full fill the need's of a basic  user or learner.";
cout<<"\n\n We are pretty sure that there shall be more improvements in our next version of our OS.";
cout<<"\n                                THANKYOU";
cout<<"\n\n\n                                                               Yours faithful";
cout<<"\n                                                               TEAM FIRE OS.";
break;
case 2:
{
//app lock
if (stat==1)
{go:int pass;
cout<<"\n                                APPLOCK";
 cout<<"\n ENTER PASSWORD:";
 cin>>pass;
 if(pass==1234)
 goto ok;
 else
 goto go;
}
else
ok:case8();
}
}
}
getch();
goto z;
}
}
else if(xx>=260&&yy>=52&&xx<=360&&yy<=73)//fn2
     {
getmousestatus(&b,&xx,&yy);
	      if(b&1==1){
	      hidemouse();
	      cleardevice();

if (stat==1)
{
w:int pass;
cout<<"\n                                APPLOCK";
cout<<"\n ENTER PASSWORD:";
 cin>>pass;
 if(pass==1234)
 goto cod;
 else
 goto w;
}
cod:int gdriver = DETECT, gmode, errorcode;
   int midx, midy;
   int radius = 100;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode,"C:\\TC\\BGI");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }

   midx = getmaxx() / 2;
   midy = getmaxy() / 2;
   setcolor(getmaxcolor());

   /* draw the circle */
   circle(midx, midy-50,radius+10);
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,3) ;
   outtextxy(midx-62,midy-65,"STOPWATCH");

   /* clean up */
   delay(3000);
   closegraph();
clrscr();
tym t;
char opt;
clrscr();

title();
cout<<"\n\n stopwatch :- ";

opt=getch();
if((opt=='s')||(opt=='S'))
e: {
while(!kbhit())
{
clrscr();
title();
cout<<"\n\n stopwatch :- ";
t.show();
delay(100);
t.inc();
}
opt=getch();
if((opt=='p')||(opt=='P'))
{
while(!kbhit())
{
clrscr();
title();
cout<<"\n\n stopwatch :- ";
t.show();
delay(100);
}
opt=getch();
if((opt=='s')||(opt=='S'))
goto e;
else if((opt=='t')||(opt=='T'))
{
clrscr();
title();
cout<<"\n\n stopwatch :- ";
t.show();
delay(5000);
}
else if((opt=='c')||(opt=='C'))
{
while(!kbhit())
{
clrscr();
title();
cout<<"\n\n stopwatch :- ";
t.cancel();
t.show();
delay(100);
}

opt=getch();
if((opt=='s')||(opt=='S')||(opt=='r')||(opt=='R'))
goto e;
}
else if((opt=='r')||(opt=='R'))
goto e;
}
else if((opt=='t')||(opt=='T'))
{
clrscr();
title();
cout<<"\n\n stopwatch :- ";
t.show();
delay(5000);
goto e;
}
else if((opt=='c')||(opt=='C'))
{
while(!kbhit())
{
clrscr();
title();
cout<<"\n\n stopwatch :- ";
t.cancel();
t.show();
goto z;
}
opt=getch();
if((opt=='s')||(opt=='S')||(opt=='r')||(opt=='R'))
goto e;
}
else
goto cod;
}
else
getch();
goto z;
     }
}
else if(xx>=510&&yy>=52&&xx<=(286*2)&&yy<=73)//fn3
     {   getmousestatus(&b,&xx,&yy);
	      if(b&1==1){ hidemouse();
	      cleardevice();
	      {
if (stat==1)
{o:int pass;
cout<<"\n                                APPLOCK";
 cout<<"\n ENTER PASSWORD:";
 cin>>pass;
 if(pass==1234)
 goto co;
 else
 goto o;
}
else
{co:clrscr();randomize();
int i,j,count=0,count1=0,b[5][5],a[5][5],fd;
char ch,p[30],p1[30];
cout<<"\t\t\t Welcome to Bingo Game !!!\n";
cout<<"\t\t\t\t How to Play :\n";
cout<<"\n * There are 2 players.\n";
cout<<"\n * There are 2 tables, filled with random numbers, provided to each player.\n";
cout<<"\n * The computer calls a random number. \n";
cout<<"\n * If the number matches with a number in the table,the number is replaced by 0.";
cout<<"\n * The no. of zereos is counted for each player, when it is replaced.\n ";
cout<<"\n * This continues till any one of the player has 25 zeroes.\n ";
cout<<"\n * The player with 25 zeroes is declared the winner.\n";
cout<<"\n\t\t Shall we play ( Y/N ) : ";cin>>ch;
delay(1000);
if(ch=='Y' || ch=='y')
{ clrscr();
  cout<< "\n\t\t\tPlayer 1 Name : ";gets(p);
  cout<< "\n\t\t\t"<<p<< "'s Table :\n";
  for(i=0;i<5;i++)             // Randomize the numbers
  { for(j=0;j<5;j++)
    { a[i][j]=random(25)+10;
      b[i][j]=random(25)+10;
    }
  }
  for(i=0;i<5;i++)           // Inputting Player 1 Table
  { cout<<"                         ";
    for(j=0;j<5;j++)
    cout<<a[i][j]<< "  ";
    cout<<endl;
  } delay(1000);
   cout<< "\n\t\t\tPlayer 2 Name : ";gets(p1);
   cout<< "\n\t\t\t"<<p1<< "'s Table :\n";
   for(i=0;i<5;i++)
   { cout<<"                        ";
      for(j=0;j<5;j++)        // Inputting Player 2 table
     cout<<b[i][j]<< "  ";
     cout<<endl;
   }delay(1000);
    clrscr();
   loop:                    // The main logic of the game starts here
   call();                  // Function call
   cout<< "\n\t\t\t The no. called is : "<<xyz; cout<<endl;
   delay(1000);
   for(i=0;i<5;i++)
   { for(j=0;j<5;j++)
     { if(a[i][j]==xyz)
       {  a[i][j]=0;       // Makes the number 0 when encountered with z
	  count++;
       }
       if(b[i][j]==xyz)
       { b[i][j]=0;        // Makes the number 0 when encountered with z
	 count1++;
       }
     }
   }
   cout<< "\n\t\t\t After replacement :\n";
   cout<<"\n\t\t\t"<<p<< "'s table :\n";
   for(i=0;i<5;i++)        // Display the table after replacement
   { cout<<"                        ";
     for(j=0;j<5;j++)
     cout<<a[i][j]<< "  ";
     cout<<endl;
   } cout<< "\n\n\n";
   cout<<"\n\t\t\t"<<p1<< "'s table :\n";
   for(i=0;i<5;i++)       // Displays the table after replacement
   { cout<<"                        ";
     for(j=0;j<5;j++)
     cout<<b[i][j]<< "  ";
     cout<<endl;
   } cout<< "\n\t\t The no. of zero(es) for "<<p<< " and "<<p1<<" : "<<count<<"  "<<count1<<"\n";
   delay(2000);
   clrscr();
   if(count<25 && count1<25)  // Checks the count for continuity of game
   goto loop;
   else if(count==25 && count1==25)   // Check for tie
   cout<< "\n\t\t\t It is a tie ";
   else if(count==25)                 // Checks for winner
   cout<<"\n\t\t\t"<<p<< " wins ";
   else if(count1==25)                // Checks for winner
   cout<<"\n\t\t\t"<<p1<< " wins " ;
   cout<< "\n\t\t\t Thank You for playing \n\n";
   cout<< "\n\t\t\t How was the game ?? ";    // Feedback
   cout<< "\n\t\t\t 1 - Bad \n\t\t\t 2 - Poor \n\t\t\t 3 - Good \n\t\t\t 4 - Very Good \n";
   cout<< "\t\t\t 5 - Outstanding ";cout<<"\n\t\t\t Enter your rating : ";
   cin>>fd;
   if(fd==1 || fd==2 || fd==3 || fd==4)
   cout<< "\n\t\t Thanks for your feedback. We will improve our game " ;
   else
   cout<< "\n\t\t Thanks for your feedback. We will keep it up. " ;
}
else
goto co;
}
getch();
goto z;
}
}
}
else if(xx>=496&&yy>=304&&xx<=597&&yy<=349)//fn9
     {  getmousestatus(&b,&xx,&yy);
	      if(b&1==1)
	     { hidemouse();
	      cleardevice();
	      {int choice;
k:cout<<"\n 1.SHUTDOWN               2.RESTART              3.LOCK";
cout<<"\n ENTER CHOICE:";
cin>>choice ;
switch(choice)
{case 1:
clrscr();
closegraph();
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n                              SHUTTING DOWN FIRE.............";
delay(2000);
clrscr();
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n                              POWER OFF...........";
delay(750);
clrscr();
delay(1000);
exit(0);
break;
case 2:
{clrscr();
delay(2000);
goto pk;
}
case 3:
{clrscr();
goto lk;
}

default:
cout<<"\n INVALID......";
clrscr();
goto k;
}
}
}
}


    else if(xx>=12&&yy>=160&&xx<=167&&yy<=235) //fn4
     {  getmousestatus(&b,&xx,&yy);
	     if(b&1==1) { hidemouse();
	      cleardevice();
	  if (stat==1)
{b:clrscr();
int pass;
cout<<"\n                                APPLOCK";
 cout<<"\n ENTER PASSWORD:";
 cin>>pass;
 if(pass==1234)
 goto odd;
 else
 goto b;
}
else
{
odd:clrscr();
char mark;
instructions1();
if(c=='Y' || c=='y')
{ clrscr();
  do
  { board();
    abcd:pl=(pl%2)?1:2;
    cout<< "\n\t\t\t\t Player "<<pl<< "\n\t\t\t Enter a number (1-9) : ";
    cin>>ch;delay(1000);
    jmn=checkmove();
    if(jmn==1)
    goto abcd;
    else
    { mark=(pl==1)?'X':'O';
      switch(ch)
      { case 1 :sq[0]=mark;break;
	case 2 :sq[1]=mark;break;
	case 3 :sq[2]=mark;break;
	case 4 :sq[3]=mark;break;
	case 5 :sq[4]=mark;break;
	case 6 :sq[5]=mark;break;
	case 7 :sq[6]=mark;break;
	case 8 :sq[7]=mark;break;
	case 9 :sq[8]=mark;break;
	default: cout<< "\n\t\t\t\t Invalid number \n";
	pl--;
	getch();
      }
    kol++;
    izy=checkwin(); //0 - Over and draw, 1-Over and win, -1 - game in progress
    pl++;
   }
 clrscr();
 }while(izy==-1);
board();
cout<<endl<<endl;
if(izy==1)
cout<< "\t\t\t    ==>\a Player "<<--pl<< " win ";
else
cout<< "\t\t\t       ==>\a Game draw ";
delay(2000);
clrscr();flat=1;
if(flat==1)
{ sq[0]='1';
  sq[1]='2';
  sq[2]='3';
  sq[3]='4';
  sq[4]='5';
  sq[5]='6';
  sq[6]='7';
  sq[7]='8';
  sq[8]='9';
}
}
else
 exit(0);
getch();
}goto z;
}
}
else if(xx>=16&&yy>=310&&xx<=146&&yy<=345)//fn7
     {
	getmousestatus(&b,&xx,&yy);
	if(b&1==1)
	{  init_graph();
	   hidemouse();
	   cleardevice();
	      int n;
Q:clrscr();
cout<<"\n CHANGE WALLPAPER TO........................";
cout<<"\n 1.APPLE INC \n 2.STEVE JOBS \n 3.CAR \n 4.APPLE 2 \n 5.FIRE \n 6.FIRE 2";
cout<<"\n ENTER CHOICE:";
cin>>n;
 switch(n)
 { case 1:init_graph(); currentWallpaper="logo.bmp";goto z;//break;
  case 2:init_graph();currentWallpaper="steve.bmp";goto z;//break;
  case 3:init_graph();currentWallpaper="car.bmp";goto z;//break;
  case 4:init_graph();currentWallpaper="sym.bmp";goto z;//break;
  case 5:init_graph();currentWallpaper="fire.bmp";goto z;//break;
  case 6:init_graph();currentWallpaper="os.bmp";goto z;//break;
  default:cout<<"\n CHECK CHOICE..........";
  clrscr();
  goto Q;
 //break;
 }
}
}
else if(xx>=485&&yy>=170&&xx<=610&&yy<=225) //fn6
     { int stat=0;
	{
	    getmousestatus(&b,&xx,&yy);
	     if(b&1==1){
	     hidemouse();
	      cleardevice();

	      {if (stat==1)
{f:int pass;
cout<<"\n                                APPLOCK";
 cout<<"\n ENTER PASSWORD:";
 cin>>pass;
 if(pass==1234)
 goto eve;
 else
 goto f;
}
else
{
eve:
clrscr();
int gdriver=DETECT,gmode,errorcode;
initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
outtextxy(20,160,"   SCIENTIFIC  CALCULATOR");
delay(4000);
closegraph();
x:clrscr();
long int a[30],no,no1,f=1,d;
long float r,t;
int s=0,i,n,choice,p=1;
cout<<"  ENTER NUMBER OF NUMBERS YOU ARE GOING TO OPERATE WITH(in case of multiple number's):";
cin>>n;
cout<<"\n MENU:\n PLEASE CHOOSE FROM THE FOLLOWING:\n 1.ADDITION\n 2.SUBTRACTION\n 3.MULTIPLICATION\n 4.DIVISION\n 5.SQUARE\n 6.power of one no. over the other\n 7.SINE function\n 8.COSINE function\n 9.TAN function\n 10.ROOT\n 11.LOG(base 10)\n 12.FACTORIAL\n 13.SINE inverse\n 14.COSINE inverse\n 15.TAN inverse\n ENTER CHOICE:";
cin>>choice;
switch(choice)
{
case 1:
cout<<" please enter the no.s:\n";
for(i=0;i<n;i++)
{
cin>>d;
cout<<"+";
s+=d;
}
cout<<" sum is:"<<s;
break;
case 2:
cout<<" please enter the no.s:";
for(i=0;i<n;i++)
{
cin>>a[i];}
for(i=0;i<n;i++)
cout<<a[i]<<"-";
for(i=1;i<n;i++)
{
a[0]-=a[i];//subtracting one no. by all others finally getting difference
}
cout<<" difference is:"<<a[0];
break;
case 3:
cout<<" please enter no.s";
for(i=0;i<n;i++)
{
cin>>a[i];
cout<<"*";
}cout<<'\b';
for(i=0;i<n;i++)
{
p*=a[i];
}
cout<<" product is:"<<p;
break;
case 4:
cout<<" enter the no.s:";
for(i=0;i<n;i++)
{cin>>a[i];
}
for(i=1;i<n;i++){
a[0]/=a[i];
}
cout<<" quotient is:"<<a[0];
break;
case 5:
cout<<" enter no.:";
cin>>no;
t=pow(no,2);
cout<<" square is:"<<t;
break;
case 6:
cout<<"  enter no.1:";cin>>no;
cout<<"  enter no.2:";cin>>no1;
t=pow(no,no1);
cout<<" the power is :"<<t;
break;
case 7:
cout<<" please enter no.:";cin>>no;
t=sin(no);
cout<<" sin value is:"<<t;
break;
case 8:
cout<<" please enter no.:";cin>>no;
t=cos(no);
cout<<" cos value is:"<<t;
break;
case 9:
cout<<" please enter no.:" ;cin>>no;
t=tan(no);
cout<<" tan value is:"<<t;
break;
case 10:
cout<<" please enter no.:";cin>>no;
r=sqrt(no);
cout<<" the square root is:"<<r;
break;
case 11:
cout<<" please enter no.:";cin>>no;
r=log(no);
cout<<" log (base 10) is:"<<r;
break;
case 12:
cout<<" please enter no.:";
cin>>no;
for(i=no;i>=1;i--){
f*=i;
}
cout<<" factorial is:"<<f;
break;
case 13:
cout<<" please enter no.:";cin>>no;
t=asin(no);
cout<<" sin inverse is:"<<t;
break;
case 14:
cout<<" please enter no.:";cin>>no;
t=acos(no);
cout<<" cos inverse is:"<<t;
break;
case 15:
cout<<" please enter no.:";cin>>no;
t=atan(no);
cout<<" tan inverse is:"<<t;
break;
}
}
goto z;
}
}
}
}
else if(xx>=239&&yy>=168&&xx<=420&&yy<=231) //fn5
if(b&1==1)
{getmousestatus(&b,&xx,&yy);
       {
	      hidemouse();
	      cleardevice();
if(stat==1)
{sq:int pass;
cout<<"\n                                APPLOCK";
 cout<<"\n ENTER PASSWORD:";
 cin>>pass;
 if(pass==1234)
 goto c;
 else
 goto sq;
}
int n;
c:q:clrscr();
int sch;
closegraph();
cout<<"\n WELCOME TO STICKY NOTES............";
cout<<"\n\n MENU.";
cout<<"\n 1.NEW STICKY NOTES.";
cout<<"\n 2.VIEW OLD ONE.";
cout<<"\n 3.EXIT.";
cin>>sch;
switch(sch)
{case 1:ip();
goto q;
break;
case 2:op();
goto q;
break;
case 3:goto z;
break;
default:cout<<"\n CHECK CHOICE........................";
goto q;
}
}
goto c;
}
}
}
}
}
}
closegraph();
}
void dot()
{ cout<<"                          ";
  for(int i=0;i<24;i++)
  cout<< "-";
  cout<<endl;
}
void board()
{ cout<< "\n\n\t\t\t\t Tic Tac Toe \n\n";
cout<< "\t\t\t Player 1 (X) - Player 2 (O) "<<endl<<endl;
cout<<"                                 |       |       "<<endl;
cout<<"                             "<<sq[0]<<"   |   "<<sq[1]<<"   |   "<<sq[2]<<endl;
cout<<"                                 |       |       "<<endl;dot();
cout<<"                                 |       |       "<<endl;
cout<<"                             "<<sq[3]<<"   |   "<<sq[4]<<"   |   "<<sq[5]<<endl;
cout<<"                                 |       |       "<<endl;dot();
cout<<"                                 |       |       "<<endl;
cout<<"                             "<<sq[6]<<"   |   "<<sq[7]<<"   |   "<<sq[8]<<endl;
cout<<"                                 |       |       "<<endl;
}
int checkmove()
{ if(sq[ch-1]=='X' || sq[ch-1]=='O')
  {  cout<<" \n\t\t   Invalid Entry !! Re-Enter a new one ";
      return 1;
  }
  else
  return 0;
}
int checkwin()
{ if(sq[0]==sq[1] && sq[1]==sq[2])
    return 1;
  else if(sq[3]==sq[4] && sq[4]==sq[5])
    return 1;
  else if(sq[6]==sq[7] && sq[7]==sq[8])
    return 1;
  else if(sq[0]==sq[3] && sq[3]==sq[6])
   return 1;
  else if(sq[1]==sq[4] && sq[4]==sq[7])
   return 1;
  else if(sq[2]==sq[5] && sq[5]==sq[8])
    return 1;
  else if(sq[0]==sq[4] && sq[4]==sq[8])
    return 1;
  else if(sq[2]==sq[4] && sq[4]==sq[6])
    return 1;
  else if(sq[0]!='1' && sq[1]!='2' && sq[2]!='3' && sq[3]!='4' &&
	  sq[4]!='5' && sq[5]!='6' && sq[6]!='7' && sq[7]!='8' && sq[8]!='9')
    return 0;
  else
  return -1;
}
void instructions1()
{ cout<< "\n\t\t\t\t Tic Tac Toe \n\n";
  cout<< "\n -> This game contains a grid which has 9 cells in it ";
  cout<< "\n -> Only 2 Players can play at a time ";
  cout<< "\n -> Player 1 (X) has 5 chances to fill the cells ";
  cout<< "\n -> Player 2 (O) has 4 chances to fill the cells ";
  cout<< "\n -> Player 1(X) starts and next Player 2 (O) starts ";
  cout<< "\n -> The player can fill the cells in any order but one cannot overwrite ";
  cout<< "\n    the other ";
  cout<< "\n -> The player is declared as the winner when the player arranges 3 consecutive";
  cout<< "\n    X's or O's along a row or a column or along the diagonals ";
  cout<< "\n\n Are you ready to play ?? (Y/N) : ";
  cin>>c;
}
void feedback()
{ int c;
  cout<< "\n\n\t\t\t How was the game ?? ";
  cout<< "\n\t\t\t 1-Bad \n\t\t\t 2-Poor \n\t\t\t 3-Good \n\t\t\t 4-Excellent \n\t\t\t 5-Outstanding ";
  cout<< "\n\t\t\t Enter your ratings : ";cin>>c;
  if(c==5)
   cout<< "\n\t\t\t Thanks for your appreciation !! ";
  else
  cout<< "\n\t\t\t Thank You!! We will try to improve our game ";
}
void call()
{ for(int i=0;i<25;i++)
  xyz=random(25)+10;
}
void case1()
{
int a;
code:clrscr();
cout<<"\n 1.USER MANUAL\n 2.CHANGE PASSWORD";
cout<<"\n ENTER CHOICE:";
cin>>a;
switch (a)
{case 1:
cout<<"\n                                 USER MANUAL\n";
cout<<"\n * 1.THIS IS A VERY USERFRIENDLY OPERATING SYSTEM\n.";
cout<<"\n * 2.IN THIS OS WE HAVE KEPT EXIT BUTTON WHEREEVER NECESSARY....\n";
cout<<"\n * 3.STICKY NOTES IS THE PLACE WHERE YOU CAN TYPE WHAT EVER YOU WANT BUT YOU         CANT SAVE IT.\n";
cout<<"\n * 4.TO EXIT STICKY NOTES TYPE CLOSE IN A SEPERATE LINE.\n";
cout<<"\n * 5.FRIDAY (type control) WHICH HELPS YOU TO OPEN THE APP YOU WANT....\n";
cout<<"\n * 6.JUST TYPE THE NAME OF THE FUNCTION YOU WANT TO OPEN....AND THE REST WILL        HAPPEN AUTOMATICALLY.\n";
cout<<"\n * 7.SELECT OPTION NO 9 TO SHUTDOWN THE OS.............";
getch();
clrscr();
cout<<"\n                                OS INFORMATION\n";
cout<<"\n                                FIRE OS V.2.0";
cout<<"\n FIRE operating system is created on c++ base to creat a userlink interface." ;
cout<<"\n\n We have created  an userlink interface with the knowledge what we have on c++.";
cout<<"\n\n This operating system	is created by\n VISHAL.S.V\n JAYASURYA\n AKSHAY PRASSANNA.";
cout<<"\n\n We hope that we have given a os which can full fill the need's of a basic  user or learner.";
cout<<"\n\n We are pretty sure that there shall be more improvements in our next version of our OS.";
cout<<"\n                                THANKYOU";
cout<<"\n\n\n                                                               Yours faithful";
cout<<"\n                                                               TEAM FIRE OS.";
break;
case 2:
{
//app lock
if (stat==1)
{go:int pass;
cout<<"\n                                APPLOCK";
 cout<<"\n ENTER PASSWORD:";
 cin>>pass;
 if(pass==1234)
 goto ok;
 else
 goto go;
}
else
ok:case8();
}
getch();
}
}
void case3()
{
{co:clrscr();randomize();
int i,j,count=0,count1=0,b[5][5],a[5][5],fd;
char ch,p[30],p1[30];
cout<<"\t\t\t Welcome to Bingo Game !!!\n";
cout<<"\t\t\t\t How to Play :\n";
cout<<"\n * There are 2 players.\n";
cout<<"\n * There are 2 tables, filled with random numbers, provided to each player.\n";
cout<<"\n * The computer calls a random number. \n";
cout<<"\n * If the number matches with a number in the table,the number is replaced by 0.";
cout<<"\n * The no. of zereos is counted for each player, when it is replaced.\n ";
cout<<"\n * This continues till any one of the player has 25 zeroes.\n ";
cout<<"\n * The player with 25 zeroes is declared the winner.\n";
cout<<"\n\t\t Shall we play ( Y/N ) : ";cin>>ch;
delay(1000);
if(ch=='Y' || ch=='y')
{ clrscr();
  cout<< "\n\t\t\tPlayer 1 Name : ";gets(p);
  cout<< "\n\t\t\t"<<p<< "'s Table :\n";
  for(i=0;i<5;i++)             // Randomize the numbers
  { for(j=0;j<5;j++)
    { a[i][j]=random(25)+10;
      b[i][j]=random(25)+10;
    }
  }
  for(i=0;i<5;i++)           // Inputting Player 1 Table
  { cout<<"                         ";
    for(j=0;j<5;j++)
    cout<<a[i][j]<< "  ";
    cout<<endl;
  } delay(1000);
   cout<< "\n\t\t\tPlayer 2 Name : ";gets(p1);
   cout<< "\n\t\t\t"<<p1<< "'s Table :\n";
   for(i=0;i<5;i++)
   { cout<<"                        ";
      for(j=0;j<5;j++)        // Inputting Player 2 table
     cout<<b[i][j]<< "  ";
     cout<<endl;
   }delay(1000);
    clrscr();
   loop:                    // The main logic of the game starts here
   call();                  // Function call
   cout<< "\n\t\t\t The no. called is : "<<xyz; cout<<endl;
   delay(1000);
   for(i=0;i<5;i++)
   { for(j=0;j<5;j++)
     { if(a[i][j]==xyz)
       {  a[i][j]=0;       // Makes the number 0 when encountered with z
	  count++;
       }
       if(b[i][j]==xyz)
       { b[i][j]=0;        // Makes the number 0 when encountered with z
	 count1++;
       }
     }
   }
   cout<< "\n\t\t\t After replacement :\n";
   cout<<"\n\t\t\t"<<p<< "'s table :\n";
   for(i=0;i<5;i++)        // Display the table after replacement
   { cout<<"                        ";
     for(j=0;j<5;j++)
     cout<<a[i][j]<< "  ";
     cout<<endl;
   } cout<< "\n\n\n";
   cout<<"\n\t\t\t"<<p1<< "'s table :\n";
   for(i=0;i<5;i++)       // Displays the table after replacement
   { cout<<"                        ";
     for(j=0;j<5;j++)
     cout<<b[i][j]<< "  ";
     cout<<endl;
   } cout<< "\n\t\t The no. of zero(es) for "<<p<< " and "<<p1<<" : "<<count<<"  "<<count1<<"\n";
   delay(2000);
   clrscr();
   if(count<25 && count1<25)  // Checks the count for continuity of game
   goto loop;
   else if(count==25 && count1==25)   // Check for tie
   cout<< "\n\t\t\t It is a tie ";
   else if(count==25)                 // Checks for winner
   cout<<"\n\t\t\t"<<p<< " wins ";
   else if(count1==25)                // Checks for winner
   cout<<"\n\t\t\t"<<p1<< " wins " ;
   cout<< "\n\t\t\t Thank You for playing \n\n";
   cout<< "\n\t\t\t How was the game ?? ";    // Feedback
   cout<< "\n\t\t\t 1 - Bad \n\t\t\t 2 - Poor \n\t\t\t 3 - Good \n\t\t\t 4 - Very Good \n";
   cout<< "\t\t\t 5 - Outstanding ";cout<<"\n\t\t\t Enter your rating : ";
   cin>>fd;
   if(fd==1 || fd==2 || fd==3 || fd==4)
   cout<< "\n\t\t Thanks for your feedback. We will improve our game " ;
   else
   cout<< "\n\t\t Thanks for your feedback. We will keep it up. " ;
}
else
goto co;
}
getch();
}
void case4()
{odd:clrscr();
int pl=1,i,ch;
char mark;
do
{ board();
pl=(pl%2)?1:2;
cout<< "\t\t\t\t Player "<<pl<< "\n\t\t\t Enter a number (1-9) : ";
cin>>ch;delay(1000);
mark=(pl==1)?'X':'O';
switch(ch)
{ case 1 :sq[0]=mark;break;
  case 2 :sq[1]=mark;break;
  case 3 :sq[2]=mark;break;
  case 4 :sq[3]=mark;break;
  case 5 :sq[4]=mark;break;
  case 6 :sq[5]=mark;break;
  case 7 :sq[6]=mark;break;
  case 8 :sq[7]=mark;break;
  case 9 :sq[8]=mark;break;
  default: cout<< "\n\t\t\t\t Invalid number : ";
	   pl--;getch();
}
 i=checkwin(); //0 - Over and draw, 1-Over and win, -1 - game in progress
 pl++;
clrscr();
}
while(i==-1);
board();
cout<<endl<<endl;
if(i==1)
cout<< "\t\t\t\t==>\a Player "<<--pl<< " win ";
else
cout<< "\t\t\t\t==>\a Game draw ";
delay(2000);
clrscr();flag=1;
if(flag==1)
{sq[0]='1';
sq[1]='2';
sq[2]='3';
sq[3]='4';
sq[4]='5';
sq[5]='6';
sq[6]='7';
sq[7]='8';
sq[8]='9';
feedback();
}
else
goto odd;
getch();
}
void case6()
{{eve:clrscr();
int gdriver=DETECT,gmode,errorcode;
initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
outtextxy(20,160,"   SCIENTIFIC  CALCULATOR");
delay(4000);
closegraph();
x:clrscr();
long int a[30],no,no1,f=1,d;
long float r,t;
int s=0,i,n,choice,p=1;
cout<<"  ENTER NUMBER OF NUMBERS YOU ARE GOING TO OPERATE WITH(in case of multiple number's):";
cin>>n;
cout<<"\n MENU:\n PLEASE CHOOSE FROM THE FOLLOWING:\n 1.ADDITION\n 2.SUBTRACTION\n 3.MULTIPLICATION\n 4.DIVISION\n 5.SQUARE\n 6.power of one no. over the other\n 7.SINE function\n 8.COSINE function\n 9.TAN function\n 10.ROOT\n 11.LOG(base 10)\n 12.FACTORIAL\n 13.SINE inverse\n 14.COSINE inverse\n 15.TAN inverse\n ENTER CHOICE:";
cin>>choice;
switch(choice)
{
case 1:
cout<<" please enter the no.s:\n";
for(i=0;i<n;i++)
{
cin>>d;
cout<<"+";
s+=d;
}
cout<<" sum is:"<<s;
break;
case 2:
cout<<" please enter the no.s:";
for(i=0;i<n;i++)
{
cin>>a[i];}
for(i=0;i<n;i++)
cout<<a[i]<<"-";
for(i=1;i<n;i++)
{
a[0]-=a[i];//subtracting one no. by all others finally getting difference
}
cout<<" difference is:"<<a[0];
break;
case 3:
cout<<" please enter no.s";
for(i=0;i<n;i++)
{
cin>>a[i];
cout<<"*";
}cout<<'\b';
for(i=0;i<n;i++)
{
p*=a[i];
}
cout<<" product is:"<<p;
break;
case 4:
cout<<" enter the no.s:";
for(i=0;i<n;i++)
{cin>>a[i];
}
for(i=1;i<n;i++){
a[0]/=a[i];
}
cout<<" quotient is:"<<a[0];
break;
case 5:
cout<<" enter no.:";
cin>>no;
t=pow(no,2);
cout<<" square is:"<<t;
break;
case 6:
cout<<"  enter no.1:";cin>>no;
cout<<"  enter no.2:";cin>>no1;
t=pow(no,no1);
cout<<" the power is :"<<t;
break;
case 7:
cout<<" please enter no.:";cin>>no;
t=sin(no);
cout<<" sin value is:"<<t;
break;
case 8:
cout<<" please enter no.:";cin>>no;
t=cos(no);
cout<<" cos value is:"<<t;
break;
case 9:
cout<<" please enter no.:" ;cin>>no;
t=tan(no);
cout<<" tan value is:"<<t;
break;
case 10:
cout<<" please enter no.:";cin>>no;
r=sqrt(no);
cout<<" the square root is:"<<r;
break;
case 11:
cout<<" please enter no.:";cin>>no;
r=log(no);
cout<<" log (base 10) is:"<<r;
break;
case 12:
cout<<" please enter no.:";
cin>>no;
for(i=no;i>=1;i--){
f*=i;
}
cout<<" factorial is:"<<f;
break;
case 13:
cout<<" please enter no.:";cin>>no;
t=asin(no);
cout<<" sin inverse is:"<<t;
break;
case 14:
cout<<" please enter no.:";cin>>no;
t=acos(no);
cout<<" cos inverse is:"<<t;
break;
case 15:
cout<<" please enter no.:";cin>>no;
t=atan(no);
cout<<" tan inverse is:"<<t;
break;
}
}
getch();
}
void case8()
{int n;
cout<<"\n 1.ON  2.OFF";
cout<<"\n ENTER CHOICE:";
cin>>n;
if(n==1)
stat=1;
else
stat=0;
}

void menu()
{
  cleardevice();
  int b,xx,yy;
  initmouse();
  restrictmouse(0,0,getmaxx(),getmaxy());
  setbkcolor(6);
  settextstyle(10,0,2);
  outtextxy(100,70,"***********MENU***********");
  outtextxy(100,150,"--FIRE CALENDAR--");
  outtextxy(100,200,"--EXIT--");
  settextstyle(8,0,1);
  showmouse();
  while(!kbhit())
  {
     getmousestatus(&b,&xx,&yy);
     if(xx>=100&&yy>=150&&xx<=500&&yy<=200)
     {
	getmousestatus(&b,&xx,&yy);
	if(b&1==1)
	{
	   hidemouse();
	   cleardevice();
	   {
  int k=1,m=11,mon,D,C,f,i,y,total=0,t,I,d,x1=115,y1=160,q,r,v;
  static int s=0;
  char st2[3],st3[9],st4[5];
  int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
  char*month[]={"JANUARY","FEBRUARY","MARCH","APRIL","MAY","JUNE","JULY","AUGUST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMEBER"};
  restorecrtmode();
  cout<<"Enter year : ";
  cin>>y;
  cout<<"Enter month : ";
  cin>>mon;
  if(mon>12)
  {
     cout<<" Invalid entry !.....";
     delay(1000);
     setgraphmode(getgraphmode());
     menu();
  }
  y-=1;
  C=y/100;
  D=y%100;
  f=(k+((13*m-1)/5)+D+(D/4)+(C/4)-(2*C));
  i=f%7;
  if(i<0)
     i+=7;
  y++;
  if(y%4==0)
  days[1]=29;
  for(t=0;t<mon-1;t++)
  {
     total+=days[t];
  }
  I=total%7;
  d=I+i;
  if(d>=7)
     d=d%7;
  setgraphmode(getgraphmode());
  cal();
  v=mon-1;
  strcpy(st3,month[v]);
  itoa(y,st4,10);
  settextstyle(2,0,8);
  outtextxy(100,90,st3);
  outtextxy(250,90,st4);
  q=days[mon-1];
  settextstyle(1,0,2);
  setcolor(15);
  for(r=1;r<=d;r++)
  {
     x1+=62;
     s++;
  }
  for(r=1;r<=q;r++)
  {
     itoa(r,st2,10);
     if(s>=6)
     {
	outtextxy(x1,y1,st2);
	y1+=30;
	x1=112;
	s=0;
	continue;
     }
     outtextxy(x1,y1,st2);
     x1+=60;
     s++;
  }
  s=0;
  getch();
  menu();
}
	}
     }
     if(xx>=100&&yy>=200&&xx<=300&&yy<=260)
     {
	getmousestatus(&b,&xx,&yy);
	if(b&1==1)
	{
	   hidemouse();
	   cleardevice();
	   setbkcolor(0);
	   setcolor(15);
	   settextstyle(10,0,5);
	   outtextxy(100,200,"EXITING");
	   int o=0;
	   for(int n=0;n<10;n++)
	   {
	      outtextxy(380+o,200,".");
	      o+=20;
	      delay(200);
	   }

	}
     }
  }
}
void cal()
{
  cleardevice();
  int l=100,t=125,r=155,b=185,g,x=110,y=127;
  char *day[]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
  char st1[4];
  setbkcolor(0);
  settextstyle(10,0,7);
  setcolor(15);
  outtextxy(100,-40,"C");
  settextstyle(10,0,6);
  outtextxy(160,-20,"ALENDAR");
  setfillstyle(1,BLUE);
  bar(85,115,530,345);
  setfillstyle(1,0);
  bar3d(l,t,r,b,0,0);
  bar3d(l,t+30,r,b+30,0,0);
  bar3d(l,t+60,r,b+60,0,0);
  bar3d(l,t+90,r,b+90,0,0);
  bar3d(l,t+120,r,b+120,0,0);
  bar3d(l,t+150,r,b+150,0,0);
  bar3d(l,t+180,r,b+150,0,0);
  bar3d(l+60,t,r+60,b,0,0);
  bar3d(l+60,t+30,r+60,b+30,0,0);
  bar3d(l+60,t+60,r+60,b+60,0,0);
  bar3d(l+60,t+90,r+60,b+90,0,0);
  bar3d(l+60,t+120,r+60,b+120,0,0);
  bar3d(l+60,t+150,r+60,b+150,0,0);
  bar3d(l+60,t+180,r+60,b+150,0,0);
  bar3d(l+120,t,r+120,b,0,0);
  bar3d(l+120,t+30,r+120,b+30,0,0);
  bar3d(l+120,t+60,r+120,b+60,0,0);
  bar3d(l+120,t+90,r+120,b+90,0,0);
  bar3d(l+120,t+120,r+120,b+120,0,0);
  bar3d(l+120,t+150,r+120,b+150,0,0);
  bar3d(l+120,t+180,r+120,b+150,0,0);
  bar3d(l+180,t,r+180,b,0,0);
  bar3d(l+180,t+30,r+180,b+30,0,0);
  bar3d(l+180,t+60,r+180,b+60,0,0);
  bar3d(l+180,t+90,r+180,b+90,0,0);
  bar3d(l+180,t+120,r+180,b+120,0,0);
  bar3d(l+180,t+150,r+180,b+150,0,0);
  bar3d(l+180,t+180,r+180,b+150,0,0);
  bar3d(l+240,t,r+240,b,0,0);
  bar3d(l+240,t+30,r+240,b+30,0,0);
  bar3d(l+240,t+60,r+240,b+60,0,0);
  bar3d(l+240,t+90,r+240,b+90,0,0);
  bar3d(l+240,t+120,r+240,b+120,0,0);
  bar3d(l+240,t+150,r+240,b+150,0,0);
  bar3d(l+240,t+180,r+240,b+150,0,0);
  bar3d(l+300,t,r+300,b,0,0);
  bar3d(l+300,t+30,r+300,b+30,0,0);
  bar3d(l+300,t+60,r+300,b+60,0,0);
  bar3d(l+300,t+90,r+300,b+90,0,0);
  bar3d(l+300,t+120,r+300,b+120,0,0);
  bar3d(l+300,t+150,r+300,b+150,0,0);
  bar3d(l+300,t+180,r+300,b+150,0,0);
  bar3d(l+360,t,r+360,b,0,0);
  bar3d(l+360,t+30,r+360,b+30,0,0);
  bar3d(l+360,t+60,r+360,b+60,0,0);
  bar3d(l+360,t+90,r+360,b+90,0,0);
  bar3d(l+360,t+120,r+360,b+120,0,0);
  bar3d(l+360,t+150,r+360,b+150,0,0);
  bar3d(l+360,t+180,r+360,b+150,0,0);
  settextstyle(1,0,2);
  setcolor(15);
  for(g=0;g<7;g++)
  {
     strcpy(st1,day[g]);
     outtextxy(x,y,st1);
     x+=60;
  }
}
initmouse()
{
  i.x.ax=0;
  int86(0x33,&i,&o);
  return(o.x.ax);
}
showmouse()
{
  i.x.ax=1;
  int86(0x33,&i,&o);
  return(o.x.ax);
}
hidemouse()
{
  i.x.ax=2;
  int86(0x33,&i,&o);
  return(o.x.ax);
}
void restrictmouse(int x1,int y1,int x2,int y2)
{
  i.x.ax=7;
  i.x.cx=x1;
  i.x.dx=x2;
  int86(0x33,&i,&o);
  i.x.ax=8;
  i.x.cx=y1;
  i.x.dx=y2;
  int86(0x33,&i,&o);
}
void getmousestatus(int *button,int *x,int *y)
{
  i.x.ax=3;
  int86(0x33,&i,&o);
  *button=o.x.bx;
  *x=o.x.cx;
  *y=o.x.dx;
}
void loading()
{  int x,y,i;
 int g=DETECT, d;
 initgraph(&g, &d,"C:\\TC\\BGI");
 cleardevice();
 x=getmaxx()/2;
 y=getmaxy()/2;
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
 setbkcolor(rand());
 setcolor(4);
 int c=150;
for(int e=0;e<25;e++) //Change 15 to your desired value
 {
  for(int i=50;i<100;i++)
  {
    setcolor(3);
    circle(x,y,i);
    circle(x,y,c);
    c--;
    cleardevice();
  }
  }
  setcolor(6);
  settextstyle(TRIPLEX_FONT, HORIZ_DIR,6);
  settextjustify(x,y);
  outtextxy(x-170,y-80,"WELCOME");
  delay(500);
  outtextxy(x+90,y-80,"TO");
  delay(500);
  outtextxy(x-110,y-10,"FIRE");
  delay(500);
  outtextxy(x+60,y-10,"OS");
  delay(1000);
 closegraph();
}


