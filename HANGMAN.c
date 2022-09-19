#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gfx.h"
#include <time.h>

void paper();
void main_menu();
void playchoice();
void helpmenu();
void exitchoice();
void pvp();
void pvc();
int keyboard(char a[],char b[],int num, int wrongs);
int level();

int main()
{
	int ysize = 800, xsize = 1400;
	int x1, y1; char c;

	gfx_open (xsize,ysize,"HANGMAN");	//opengfx
	
	
	while(1)
	{
		main_menu();		
		c = gfx_wait();
		if(c==0x01)
		{
			x1=gfx_xpos();
			y1=gfx_ypos();

			if(x1>=50 && x1<=200 && y1>=700 && y1<=750) 	//play
			{
				playchoice();
			}
			else if(x1>=625 && x1<=775 && y1>=700 && y1<=750) //help
			{
				helpmenu();
			}
			else if(x1>=1200 && x1<=1350 && y1>=700 && y1<=750) //exit
			{
				exitchoice();
			}
		}	
	}	
return(0);
}

void paper()
{
int i;
	gfx_clear();
	gfx_clear_color (245,245,245);
	gfx_clear();
		
	gfx_color (255,0,0);
	gfx_line (150,0,150,800);
	
	gfx_color (0,0,255);
	for (i=50; i<1400; i=i+50)
	{
		gfx_line(0,i,1400,i);
	}
}

void main_menu()
{	
	paper();	
	gfx_color (0,0,0);	  		//H
	gfx_fillrectangle (295,60,30,90);
	gfx_fillrectangle (325,90,30,30);
	gfx_fillrectangle (355,60,30,90);

	gfx_fillrectangle (415,60,30,90); 	//A1
	gfx_fillrectangle (445,60,30,60);
	gfx_fillrectangle (475,60,30,90);
	gfx_color (245,245,245);
	gfx_fillrectangle (450,80,20,20);

	gfx_color (0,0,0);	  		//N1
	gfx_fillrectangle (535,60,30,90);
	gfx_fillrectangle (565,60,15,30);
	gfx_fillrectangle (575,90,10,30);
	gfx_fillrectangle (580,120,15,30);
	gfx_fillrectangle (595,60,30,90);

	gfx_fillrectangle (655,60,90,90); 	//G
	gfx_color (245,245,245);
	gfx_fillrectangle (685,90,60,10);
	gfx_fillrectangle (685,100,15,10);
	gfx_fillrectangle (685,110,30,10);
	gfx_color (0,0,255);
	gfx_line (685,100,700,100);

	gfx_color (0,0,0);	  		//M
	gfx_fillrectangle (775,60,90,90);
	gfx_color (245,245,245);
	gfx_fillrectangle (815,60,10,30);
	gfx_fillrectangle (805,90,5,30);
	gfx_fillrectangle (830,90,5,30);
	gfx_fillrectangle (805,120,10,30);
	gfx_fillrectangle (825,120,10,30);
	gfx_color (0,0,255);
	gfx_line (805,100,809,100);
	gfx_line (830,100,834,100);

	gfx_color (0,0,0);	  		//A2
	gfx_fillrectangle (895,60,30,90);
	gfx_fillrectangle (925,60,30,60);
	gfx_fillrectangle (955,60,30,90);
	gfx_color (245,245,245);
	gfx_fillrectangle (930,80,20,20);

	gfx_color (0,0,0);	  		//N2
	gfx_fillrectangle (1015,60,30,90);
	gfx_fillrectangle (1045,60,15,30);
	gfx_fillrectangle (1055,90,10,30);
	gfx_fillrectangle (1060,120,15,30);
	gfx_fillrectangle (1075,60,30,90);
	
	gfx_fillrectangle (500,645,400,5);	//LOGO
	gfx_fillrectangle (550,200,5,450);
	gfx_fillrectangle (550,200,150,5);
	gfx_fillrectangle (700,200,5,300);
	gfx_fillrectangle (625,375,75,5);
	gfx_fillrectangle (705,375,75,5);
	
	gfx_line (625,600,700,500);
	gfx_line (626,600,701,500);
	gfx_line (627,600,702,500);
	gfx_line (628,600,703,500);
	gfx_line (629,600,704,500);
	gfx_line (630,600,705,500);
	
	gfx_line (705,500,780,600);
	gfx_line (704,500,779,600);
	gfx_line (703,500,778,600);
	gfx_line (702,500,777,600);
	gfx_line (701,500,776,600);
	gfx_line (700,500,775,600);

	gfx_fillcircle (703,300,100);
	gfx_color (245,245,245);
	gfx_fillcircle (703,300,90);
	gfx_color (0,0,255);
	gfx_line (613,300,883,300);
	
	gfx_color(0,0,0);	  		//playbox
	gfx_rectangle (50,700,150,50);
	gfx_text ("PLAY",100,715);
	  
	gfx_rectangle (625,700,150,50);		//helpbox
	gfx_text ("HELP",675,715);
		  
	gfx_rectangle (1200,700,150,50);	//exitbox
	gfx_text ("EXIT",1250,715);
}

void exitchoice()
{
	int c, x, y;

	gfx_color (0,0,0);
	gfx_rectangle (1000,700,150,50);
	gfx_rectangle (1200,600,150,50);
	gfx_line (1150,725,1200,725);
	gfx_line (1275,650,1275,700);
	gfx_text ("NO",1065,715);
	gfx_text ("YES",1260,615);
	
	while(1)
	{
		c = gfx_wait();
		if(c==0x01)
		{
			x=gfx_xpos(); y=gfx_ypos();
	
			if(x>=1000 && x<=1150 && y>=700 && y<=750)     //no
			{
				break;
			}
			else if(x>=1200 && x<=1350 && y>=600 && y<=650) //yes
				exit(1);
		}
	}
}

void helpmenu()
{
	int x,y;
	char c;
	
	paper();
	gfx_color (0,0,0);
	gfx_text ("PLAYER VS PLAYER:-",160,70);
	gfx_text ("1ST PLAYER WILL ENTER THE WORD AND THE 2ND PLAYER WILL GUESS IT.",160,120);
	gfx_text ("THE 2ND PLAYER HAVE DIFFERENT AMOUNT OF LIVES:-",160,170);
	gfx_text ("EASY   : 7 LIVES,",200,220);
	gfx_text ("MEDIUM : 5 LIVES,",200,270);
	gfx_text ("HARD   : 3 LIVES,",200,320);
	gfx_text ("THE GAME GOES ON UNTIL 2ND PLAYER LOSE.",160,370);
			
	gfx_text ("PLAYER VS COMPUTER:-",160,470);
	gfx_text ("COMPUTER WILL GIVE RANDOM WORDS AND PLAYER WILL HAVE TO GUESS IT.",160,520);
	gfx_text ("THE GAME GOES ON UNTIL PLAYER LOSE ACCORDING TO THE LEVEL TAKEN.",160,570);	  
	gfx_rectangle (1200,700,150,50);
	gfx_text ("NOTED",1250,715);

	while(1)
	{
		c = gfx_wait();
		if(c==0x01)
		{
			x=gfx_xpos(); y=gfx_ypos();

			if(x>=1200 && x<=1350 && y>=700 && y<=750) //noted
			{
				break;
			}
		}		
	}
}

void playchoice()
{
	int x,y;
	char c;
	
	gfx_color (0,0,0);
	gfx_rectangle (250,700,150,50);
	gfx_rectangle (50,600,150,50);
	gfx_line (200,725,250,725);
	gfx_line (125,650,125,700);			
	gfx_text ("VS PLAYER",273,715);
	gfx_text ("VS COMPUTER",58,615);

	while(1)
	{
		c = gfx_wait();
		if(c=0x01)
		{
			x=gfx_xpos(); y=gfx_ypos();
			
			if(x>=250 && x<=400 && y>=700 && y<=750) //pvp
			{
				pvp();
			}
			else if(x>=50 && x<=200 && y>=600 && y<=650) //pvc
			{
				pvc();
			}
		}
	}
}

void pvp()
{
	int x1,y1,x,y,a,i,totalchance,twrongu,repeat=0,score=0,played=0,won=0,perfect=0;
	char word[16]="",guess[16]="",inttostr[10]="",z;
		
	totalchance = level();
	do
	{
		memset(guess,0,15);
		memset(word,0,15);
		paper();
		gfx_color (0,0,0);
		gfx_text ("P1 ENTER A WORD <15 CHARACTER:-",160,120);
		gfx_text ("PRESS '/' TO VIEW.",160,170);
		gfx_rectangle (1200,700,150,50);
		gfx_text ("PROCEED",1235,713);
					
		a=0;
		do
		{
			z=gfx_wait();		//requestword	
			if((z>='a'&&z<='z')||(z>='A'&&z<='Z'))
			{
				word[a]=z;
				a++;
			} 
		}while(z != '/' && a<15);
		printf("\nword = %s\n",word);
							
		x = 160;
		y = 270;

		for (i=0; i<a; i++)		//printdash
		{
			gfx_color (0,0,0);
			gfx_text ("__",x,y);
			x = x + 50;				
		}		

		while(1)
		{
			z=gfx_wait();
			if(z==0x01)
			{
				x1=gfx_xpos(); y1=gfx_ypos();
				if(x1>=1200 && x1<=1350 && y1>=700 && y1<=750)
				{
					paper();
					gfx_color (0,0,0);
					gfx_text ("P2 GUESS THE WORD",160,120);
					x = 100;
					for (i=0; i<a; i++)		//printdash
					{
						guess[i]= '_';			
					}
					gfx_text(guess,160,220);
					twrongu = keyboard(word, guess, a, totalchance);
					printf("\nguess= %s",guess);
					if(strcasecmp(guess,word) == 0)
					{
						gfx_color (255,0,0);
						gfx_text("CONGRATS !",645,120);
						gfx_color (0,0,0);
						gfx_text ("CLICK ANYWHERE TO CONTINUE.",1000,770);
						gfx_color (0,0,0);
						score = score + 100 + ((7 - twrongu)*10);	//totalscore
						won++;					//total won
						played++;				//total played
						if (twrongu==0)				//total perfect
							perfect++;

						z=gfx_wait();
						if(z==0x01)
						{
							x1=gfx_xpos(); y1=gfx_ypos();
							if (x1>=0 && x1<=1400 && y1>=0 && y1<=800)
								break;
						}
						else
							break;
					}
					else
					{
						gfx_color (255,0,0);
						gfx_text("BETTER LUCK NEXT TIME ;)",565,120);
						gfx_color (0,0,0);
						played++;
						gfx_text("TOTAL SCORE :-",1000,170);
						sprintf (inttostr,"%d",score);
						gfx_text (inttostr,1000,220);
						gfx_text("TOTAL WON :-",1000,270);
						sprintf (inttostr,"%d",won);
						gfx_text (inttostr,1000,320);
						gfx_text("TOTAL GAME PLAYED :-",1000,370);
						sprintf (inttostr,"%d",played);
						gfx_text (inttostr,1000,420);
						gfx_text("TOTAL PERFECT GAME :-",1000,470);
						sprintf (inttostr,"%d",perfect);
						gfx_text (inttostr,1000,520);
						gfx_text ("THE ANSWER IS :-",1000,620);
						gfx_text (word,1000,670);
						gfx_text ("CLICK ANYWHERE TO EXIT.",1000,770);
						repeat = 1;
						z=gfx_wait();
						if(z==0x01)
							exit(1);
						else
							exit(1);
					}	
				}
			}
		}
	}while(repeat !=1);	
}

void pvc()
{
	int x1,y1,x,y,a,i,r,totalchance,twrongu,repeat=0,score=0,played=0,won=0,perfect=0;
	char guess[15]="",word[15]="",inttostr[10]="",z;
	char list[136][20]= {"cat", "dog", "rat", "fox", "ox", "ant", "bat", "hen", "owl", "boa", "bee", "fly", "cow", "yak", "wolf", "lynx", "bear", "crow", "lion", "deer", "bird", "fish", "swan", "duck", "seal", "crab", "frog", "hawk", "dove", "bull", "goat", "worm", "snake", "otter", "eagle", "skunk", "sheep", "bison", "goose", "whale", "sloth", "gecko", "crane", "stork", "shark", "tapir", "hyena", "camel", "cobra", "tiger", "mouse", "zebra", "koala", "viper", "moose", "llama", "lizard", "parrot", "alpaca", "beaver", "rodent", "turkey", "baboon", "monkey", "donkey", "ferret", "oyster", "caiman", "weaver", "iguana", "wombat", "jaguar", "spider", "turtle", "komodo", "meerkat", "parrot", "cougar", "python", "rabbit", "salmon", "shrimp", "squirrel", "buffalo", "elephant", "axolotl", "porcupine", "polecat", "alligator", "buffalo", "woodpecker", "antelope", "armadillo", "bandicoot", "kangaroo", "crocodile", "giraffe", "rhinoceros", "peacock", "pelican", "butterfly", "mosquito", "chameleon", "cheetah", "flamingo", "chimpanzee", "chipmunk", "cockatoo", "hamster", "raccoon", "cheetah", "panther", "porcupine", "tortoise", "dolphin", "dragonfly", "penguin", "pigeon",  "antelope", "hornbill", "leopard", "kingfisher", "manatee", "ostrich", "opossum", "lobster", "echidna", "sparrow", "tarantula", "warthog", "gorilla", "octopus", "starfish", "squid", "pufferfish", "clownfish"};
	
	srand(time(NULL));
	
	paper();	
	totalchance = level();
	do
	{
		r = rand() % 136;
		memset(guess,0,15);
		memset(word,0,15);
		
		strcpy(word,list[r]);
		a=0;
		a = strlen(word);
		
		printf ("%s",word);
		x=100;y=200;					
		for (i=0; i<a; i++)		//printdash
		{
			gfx_color (0,0,0);
			gfx_text ("__",x,y);
			x = x + 50;				
		}		

	
		while(1)
		{
			paper();
			gfx_color (0,0,0);
			gfx_text ("GUESS THE WORD",160,120);
			gfx_text ("HINT : ANIMAL",160,170);
			x = 100;
			for (i=0; i<a; i++)		//printdash
			{
				guess[i]= '_';			
			}
			gfx_text(guess,160,220);
			twrongu=keyboard(word, guess,a, totalchance);
			if(strcasecmp(guess,word) == 0)
			{
				gfx_color (255,0,0);
				gfx_text("CONGRATS !",645,120);
				gfx_color (0,0,0);
				gfx_text ("CLICK ANYWHERE TO CONTINUE.",1000,770);
				score = score + 100 + ((7 - twrongu)*10);	//totalscore
				won++;					//total won
				played++;				//total played
				if (twrongu==0)				//total perfect
					perfect++;
	
				z=gfx_wait();
				if(z==0x01)
				{
					x1=gfx_xpos(); y1=gfx_ypos();
					if (x1>=0 && x1<=1400 && y1>=0 && y1<=800)
						break;
				}
				else
					break;
			}
			else
			{
				gfx_color (255,0,0);
				gfx_text("BETTER LUCK NEXT TIME ;)",565,120);
				gfx_color (0,0,0);
				played++;
				gfx_text("TOTAL SCORE :-",1000,170);
				sprintf (inttostr,"%d",score);
				gfx_text (inttostr,1000,220);
				gfx_text("TOTAL WON :-",1000,270);
				sprintf (inttostr,"%d",won);
				gfx_text (inttostr,1000,320);
				gfx_text("TOTAL GAME PLAYED :-",1000,370);
				sprintf (inttostr,"%d",played);
				gfx_text (inttostr,1000,420);
				gfx_text("TOTAL PERFECT GAME :-",1000,470);
				sprintf (inttostr,"%d",perfect);
				gfx_text (inttostr,1000,520);
				gfx_text ("THE ANSWER IS :-",1000,620);
				gfx_text (word,1000,670);
				gfx_text ("CLICK ANYWHERE TO EXIT.",1000,770);
				repeat = 1;
				z=gfx_wait();
					if(z==0x01)
						exit(1);
					else
						exit(1);
			}
		}
	}while(repeat!=1);	
}

int level()
{
	int totalwrong,z,x1,y1;
	
	paper();
	gfx_color(0,0,0);
	gfx_text ("PLAYER CHOOSE LEVEL OF DIFFICULTY:-",160,120);
	
	gfx_rectangle (550,200,300,100);
	gfx_rectangle (550,350,300,100);
	gfx_rectangle (550,500,300,100);
	
	gfx_text ("EASY",680,238);
	gfx_text ("MEDIUM",668,390);
	gfx_text ("HARD",680,538);
	
	while(1)
	{
	z=gfx_wait();
		if(z==0x01)
		{
			x1=gfx_xpos(); y1=gfx_ypos();
			if (x1>=550 && x1<=850 && y1>=200 && y1<=300)	//EASY
			{
				totalwrong = 7;
				break;
			}
			
			if (x1>=550 && x1<=850 && y1>=350 && y1<=450)	//MEDIUM
			{
				totalwrong = 5;
				break;
			}
			
			if (x1>=550 && x1<=850 && y1>=500 && y1<=650)	//HARD
			{
				totalwrong = 3;
				break;
			}
		}
	}
	printf ("\n%d\n",totalwrong);
	return (totalwrong);
}

int keyboard(char a[],char b[], int num, int wrongs)
{
	int row, col, x, x1, y1, y, condition, i, wrong=0, alpha=0;
	int pushA=0,pushB=0,pushC=0,pushD=0,pushE=0,pushF=0,pushG=0,pushH=0,pushI=0,pushJ=0,pushK=0,pushL=0,pushM=0,pushN=0,pushO=0, pushP=0,pushQ=0,pushR=0,pushS=0,pushT=0,pushU=0,pushV=0,pushW=0,pushX=0,pushY=0,pushZ=0;
	char c,z[26] = "ABCDEFGHIJKLMNOPQRSTUVWX",hoi[10]="";
	char str[2];

	x=0;
	for(row=300;row<700;row=row+100) //y
	{
		for(col=185;col<760;col=col+100) //x
		{
			gfx_color(0,0,0);
			gfx_circle(col,row,50);
			sprintf(str,"%c",z[x]);
			gfx_text(str,col-5,row-10);
			x++;
		}
	}

	gfx_circle(185,700,50); //y
	gfx_text("Y",180,690);
	
	gfx_circle(285,700,50); //z
	gfx_text("Z",280,690);

	while(1)
	{
		c=gfx_wait();
		if (c==0x01)
		{
			x1=gfx_xpos();y1=gfx_ypos();
			if (x1>=160 && x1<=210 && y1>=275 && y1<=325 && pushA==0)	//A
			{
				condition = 1;
				gfx_color (0,0,0);
				gfx_fillcircle (185,300,50);
				for(y=0;y<num;y++)
				{
					if((a[y] == 'a') || (a[y] == 'A'))
					{
						b[y] = 'A';
						condition = 0;
						alpha++;
						gfx_text(b,160,220);
					}
				}
				if(condition == 1)
				{	
					wrong++;
				}
				pushA = 1;
			}
			
			if (x1>=260 && x1<=310 && y1>=275 && y1<=325 && pushB==0)	//B
			{
				gfx_color (0,0,0);
				gfx_fillcircle (285,300,50);
				condition = 1;
				for(y=0;y<num;y++)
				{
					if((a[y] == 'b') || (a[y] == 'B'))
					{
						b[y] = 'B';
						condition = 0;
						alpha++;
						gfx_text(b,160,220);
					}
				}
				if(condition == 1)
				{
					wrong++;
				}
				pushB = 1;
			}
			
			if (x1>=360 && x1<=410 && y1>=275 && y1<=325 && pushC==0)	//C
			{
				gfx_color (0,0,0);
				gfx_fillcircle (385,300,50);
				condition = 1;
				for(y=0;y<num;y++)
				{
					if((a[y] == 'c') || (a[y] == 'C'))
					{
						b[y] = 'C';
						condition = 0;
						alpha++;
						gfx_text(b,160,220);
					}
				}
				if(condition == 1)
				{
					wrong++;
				}
				pushC = 1;
			}
			
			if (x1>=460 && x1<=510 && y1>=275 && y1<=325 && pushD==0)	//D
			{
				gfx_color (0,0,0);
				gfx_fillcircle (485,300,50);
				condition = 1;
				for(y=0;y<num;y++)
				{
					if((a[y] == 'd') || (a[y] == 'D'))
					{
						b[y] = 'D';
						condition = 0;
						alpha++;
						gfx_text(b,160,220);
					}
				}
				if(condition == 1)
				{
					wrong++;
				}
				pushD = 1;
			}
			
			if (x1>=560 && x1<=610 && y1>=275 && y1<=325 && pushE==0)	//E
			{
				gfx_color (0,0,0);
				gfx_fillcircle (585,300,50);
				condition = 1;
				for(y=0;y<num;y++)
				{
					if((a[y] == 'e') || (a[y] == 'E'))
					{
						b[y] = 'E';
						condition = 0;
						alpha++;
						gfx_text(b,160,220);
					}
				}
				if(condition == 1)
				{
					wrong++;
				}
				pushE = 1;
			}
			
			if (x1>=660 && x1<=710 && y1>=275 && y1<=325 && pushF==0)	//F
			{
				gfx_color (0,0,0);
				gfx_fillcircle (685,300,50);
				condition = 1;
				for(y=0;y<num;y++)
				{
					if((a[y] == 'f') || (a[y] == 'F'))
					{
						b[y] = 'F';
						condition = 0;
						alpha++;
						gfx_text(b,160,220);
					}
				}
				if(condition == 1)
				{
					wrong++;
				}
				pushF = 1;
			}
			
			if (x1>=160 && x1<=210 && y1>=375 && y1<=425 && pushG==0)	//G
			{
				gfx_color (0,0,0);
				gfx_fillcircle (185,400,50);
				condition = 1;
				for(y=0;y<num;y++)
				{
					if((a[y] == 'g') || (a[y] == 'G'))
					{
						b[y] = 'G';
						condition = 0;
						alpha++;
						gfx_text(b,160,220);
					}
				}
				if(condition == 1)
				{
					wrong++;
				}
				pushG = 1;
			}
			
			if (x1>=260 && x1<=310 && y1>=375 && y1<=425 && pushH==0)	//H
			{
				gfx_color (0,0,0);
				gfx_fillcircle (285,400,50);
				condition = 1;
				for(y=0;y<num;y++)
				{
					if((a[y] == 'h') || (a[y] == 'H'))
					{
						b[y] = 'H';
						condition = 0;
						alpha++;
						gfx_text(b,160,220);
					}
				}
				if(condition == 1)
				{
					wrong++;
				}
				pushH = 1;
			}
			
			if (x1>=360 && x1<=410 && y1>=375 && y1<=425 && pushI==0)	//I
			{
				gfx_color (0,0,0);
				gfx_fillcircle (385,400,50);
				condition = 1;
				for(y=0;y<num;y++)
				{
					if((a[y] == 'i') || (a[y] == 'I'))
					{
						b[y] = 'I';
						condition = 0;
						alpha++;
						gfx_text(b,160,220);
					}
				}
				if(condition == 1)
				{
					wrong++;
				}
				pushI = 1;
			}
			
			if (x1>=460 && x1<=510 && y1>=375 && y1<=425 && pushJ==0)	//J
			{
				gfx_color (0,0,0);
				gfx_fillcircle (485,400,50);
				condition = 1;
				for(y=0;y<num;y++)
				{
					if((a[y] == 'j') || (a[y] == 'J'))
					{
						b[y] = 'J';
						condition = 0;
						alpha++;
						gfx_text(b,160,220);
					}
				}
				if(condition == 1)
				{
					wrong++;
				}
				pushJ = 1;
			}
			
			if (x1>=560 && x1<=610 && y1>=375 && y1<=425 && pushK==0)	//K
			{
				gfx_color (0,0,0);
				gfx_fillcircle (585,400,50);
				condition = 1;
				for(y=0;y<num;y++)
				{
					if((a[y] == 'k') || (a[y] == 'K'))
					{
						b[y] = 'K';
						condition = 0;
						alpha++;
						gfx_text(b,160,220);
					}
				}
				if(condition == 1)
				{
					wrong++;
				}
				pushK = 1;
			}
			
			if (x1>=660 && x1<=710 && y1>=375 && y1<=425 && pushL==0)	//L
			{
				gfx_color (0,0,0);
				gfx_fillcircle (685,400,50);
				condition = 1;
				for(y=0;y<num;y++)
				{
					if((a[y] == 'l') || (a[y] == 'L'))
					{
						b[y] = 'L';
						condition = 0;
						alpha++;
						gfx_text(b,160,220);
					}
				}
				if(condition == 1)
				{
					wrong++;
				}
				pushL = 1;
			}
			
			if (x1>=160 && x1<=210 && y1>=475 && y1<=525 && pushM==0)	//M
			{
				gfx_color (0,0,0);
				gfx_fillcircle (185,500,50);
				condition = 1;
				for(y=0;y<num;y++)
				{
					if((a[y] == 'm') || (a[y] == 'M'))
					{
						b[y] = 'M';
						condition = 0;
						alpha++;
						gfx_text(b,160,220);
					}
				}
				if(condition == 1)
				{
					wrong++;
				}
				pushM = 1;
			}
			
			if (x1>=260 && x1<=310 && y1>=475 && y1<=525 && pushN==0)	//N
			{
				gfx_color (0,0,0);
				gfx_fillcircle (285,500,50);
				condition = 1;
				for(y=0;y<num;y++)
				{
					if((a[y] == 'n') || (a[y] == 'N'))
					{
						b[y] = 'N';
						condition = 0;
						alpha++;
						gfx_text(b,160,220);
					}
				}
				if(condition == 1)
				{
					wrong++;
				}
				pushN = 1;
			}
			
			if (x1>=360 && x1<=410 && y1>=475 && y1<=525 && pushO==0)	//O
			{
				gfx_color (0,0,0);
				gfx_fillcircle (385,500,50);
				condition = 1;
				for(y=0;y<num;y++)
				{
					if((a[y] == 'o') || (a[y] == 'O'))
					{
						b[y] = 'O';
						condition = 0;
						alpha++;
						gfx_text(b,160,220);
					}
				}
				if(condition == 1)
				{
					wrong++;
				}
				pushO = 1;
			}
			
			if (x1>=460 && x1<=510 && y1>=475 && y1<=525 && pushP==0)	//P
			{
				gfx_color (0,0,0);
				gfx_fillcircle (485,500,50);
				condition = 1;
				for(y=0;y<num;y++)
				{
					if((a[y] == 'p') || (a[y] == 'P'))
					{
						b[y] = 'P';
						condition = 0;
						alpha++;
						gfx_text(b,160,220);
					}
				}
				if(condition == 1)
				{
					wrong++;
				}
				pushP = 1;
			}
			
			if (x1>=560 && x1<=610 && y1>=475 && y1<=525 && pushQ==0)	//Q
			{
				gfx_color (0,0,0);
				gfx_fillcircle (585,500,50);
				condition = 1;
				for(y=0;y<num;y++)
				{
					if((a[y] == 'q') || (a[y] == 'Q'))
					{
						b[y] = 'Q';
						condition = 0;
						alpha++;
						gfx_text(b,160,220);
					}
				}
				if(condition == 1)
				{
					wrong++;
				}
				pushQ = 1;
			}
			
			if (x1>=660 && x1<=710 && y1>=475 && y1<=525 && pushR==0)	//R
			{
				gfx_color (0,0,0);
				gfx_fillcircle (685,500,50);
				condition = 1;
				for(y=0;y<num;y++)
				{
					if((a[y] == 'r') || (a[y] == 'R'))
					{
						b[y] = 'R';
						condition = 0;
						alpha++;
						gfx_text(b,160,220);
					}
				}
				if(condition == 1)
				{
					wrong++;
				}
				pushR = 1;
			}
			
			if (x1>=160 && x1<=210 && y1>=575 && y1<=625 && pushS==0)	//S
			{
				gfx_color (0,0,0);
				gfx_fillcircle (185,600,50);
				condition = 1;
				for(y=0;y<num;y++)
				{
					if((a[y] == 's') || (a[y] == 'S'))
					{
						b[y] = 'S';
						condition = 0;
						alpha++;
						gfx_text(b,160,220);
					}
				}
				if(condition == 1)
				{
					wrong++;
				}
				pushS = 1;
			}
			
			if (x1>=260 && x1<=310 && y1>=575 && y1<=625 && pushT==0)	//T
			{
				gfx_color (0,0,0);
				gfx_fillcircle (285,600,50);
				condition = 1;
				for(y=0;y<num;y++)
				{
					if((a[y] == 't') || (a[y] == 'T'))
					{
						b[y] = 'T';
						condition = 0;
						alpha++;
						gfx_text(b,160,220);
					}
				}
				if(condition == 1)
				{
					wrong++;
				}
				pushT = 1;
			}
			
			if (x1>=360 && x1<=410 && y1>=575 && y1<=625 && pushU==0)	//U
			{
				gfx_color (0,0,0);
				gfx_fillcircle (385,600,50);
				condition = 1;
				for(y=0;y<num;y++)
				{
					if((a[y] == 'u') || (a[y] == 'U'))
					{
						b[y] = 'U';
						condition = 0;
						alpha++;
						gfx_text(b,160,220);
					}
				}
				if(condition == 1)
				{
					wrong++;
				}
				pushU = 1;
			}
			
			if (x1>=460 && x1<=510 && y1>=575 && y1<=625 && pushV==0)	//V
			{
				gfx_color (0,0,0);
				gfx_fillcircle (485,600,50);
				condition = 1;
				for(y=0;y<num;y++)
				{
					if((a[y] == 'v') || (a[y] == 'V'))
					{
						b[y] = 'V';
						condition = 0;
						alpha++;
						gfx_text(b,160,220);
					}
				}
				if(condition == 1)
				{
					wrong++;
				}
				pushV = 1;
			}
			
			if (x1>=560 && x1<=610 && y1>=575 && y1<=625 && pushW==0)	//W
			{
				gfx_color (0,0,0);
				gfx_fillcircle (585,600,50);
				condition = 1;
				for(y=0;y<num;y++)
				{
					if((a[y] == 'w') || (a[y] == 'W'))
					{
						b[y] = 'W';
						condition = 0;
						alpha++;
						gfx_text(b,160,220);
					}
				}
				if(condition == 1)
				{
					wrong++;
				}
				pushW = 1;
			}
			
			if (x1>=660 && x1<=710 && y1>=575 && y1<=625 && pushX==0)	//X
			{
				gfx_color (0,0,0);
				gfx_fillcircle (685,600,50);
				condition = 1;
				for(y=0;y<num;y++)
				{
					if((a[y] == 'x') || (a[y] == 'X'))
					{
						b[y] = 'X';
						condition = 0;
						alpha++;
						gfx_text(b,160,220);
					}
				}
				if(condition == 1)
				{
					wrong++;
				}
				pushX = 1;
			}
			
			if (x1>=160 && x1<=210 && y1>=675 && y1<=725 && pushY==0)	//Y
			{
				gfx_color (0,0,0);
				gfx_fillcircle (185,700,50);
				condition = 1;
				for(y=0;y<num;y++)
				{
					if((a[y] == 'y') || (a[y] == 'Y'))
					{
						b[y] = 'Y';
						condition = 0;
						alpha++;
						gfx_text(b,160,220);
					}
				}
				if(condition == 1)
				{
					wrong++;
				}
				pushY = 1;
			}
			
			if (x1>=260 && x1<=310 && y1>=675 && y1<=725 && pushZ==0)	//Z
			{
				gfx_color (0,0,0);
				gfx_fillcircle (285,700,50);
				condition = 1;
				for(y=0;y<num;y++)
				{
					if((a[y] == 'z') || (a[y] == 'Z'))
					{
						b[y] = 'Z';
						condition = 0;
						alpha++;
						gfx_text(b,160,220);
					}
				}
				if(condition == 1)
				{
					wrong++;
				}
				pushZ = 1;
			}
			
			
		}
		if(alpha==num)
			break;
		if(wrong==wrongs)
			break;
	}
	printf("\nb = %s",b);
	return (wrong);
}
