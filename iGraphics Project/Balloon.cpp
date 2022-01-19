# include "iGraphics.h"
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int redspd=13,greenspd=9,over=0;
int red,green,blust;
int redx=150 , greenx=50;
int redy=400,greeny=400;
int vice=1,blast=1,count=0;
int mousex=0 , mousey=0;
int blax,blay,go=1,score=0;
char sco[100];
char name[100] = "SOWPNIL ------> ";
char final[100];
char temp[100]= "SOWPNIL ------> ";

void iDraw()
{
	iClear();
	
	if(go%2!=0)
	{
		iShowBMP(redx,redy,"redBalloon3.bmp");
	}
	if(go%2==0)
	{
		iShowBMP(greenx,greeny,"greenBalloon3.bmp"); 
	}
	iShowBMP2((mousex-20), (mousey-20) , "aimLogos.bmp",0);
    
	iSetColor(0,255,0);
	iText(240, 370, "Player Name ->" "score");
	//printf("score : %d\n",score);

	iSetColor(255, 19, 21);
	if(score==0)
	{
		iText(250, 350, "SOWPNIL ------> 00" );
	}
	
	iText(250, 350, final );

	if(redy <= 0 || greeny <= 0)
	{
		iSetColor(255,0 , 0);
		iText(150,200,"GAME OVER !!!!!");
	}
	if(blast==count)
	{
		iShowBMP(blax,blay,"blow.bmp");
		
		go++;
		blast++;
	}
}


void iMouseMove(int mx, int my)
{
	//place your codes here
}


void iPassiveMouse(int mx, int my)
{
	mousex = mx;
	mousey = my;
	//printf("%d, %d\n",mousex,mousey);
}


void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		int i,j;
		for(i=redx ; i<=(redx+80); i++)
		{
			for(j=redy ; j<=(redy+80) ; j++)
			{
				if((mx==i) && (my==j))
				{
					count++;
					blax=redx;
					blay=redy;
					redx=150 , greenx=50;
					score=score+20;
					itoa(score,sco,10);//int to string
					strcat(name , sco);
					strcpy(final,name);
					strcpy(name,temp);
				}
			}
		}
		for(i=greenx ; i<=(greenx+80); i++)
		{
			for(j=greeny ; j<=(greeny+80) ; j++)
			{
				if((mx==i) && (my==j))
				{
					count++;
					blax=greenx;
					blay=greeny;
					redy=400,greeny=400;
					score=score+10;
					itoa(score,sco,10);
					strcat(name , sco);
					strcpy(final,name);
					strcpy(name,temp);
				}
			}
		}
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}


void iKeyboard(unsigned char key)
{
	if(key == 'p')
	{
		iPauseTimer(0);
	}
	if(key == 'r')
	{
		iResumeTimer(0);
	}
}


void iSpecialKeyboard(unsigned char key)
{
	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
}


void balloon(){

	if(go%2!=0)
	{
		redy -=redspd;
	}
	if(go%2==0)
	{
		greeny -=greenspd;
	}

	/*printf("%s\n",sco);
	printf("score : %d\n",score);*/
}


int main()
{
	iSetTimer(50, balloon);
	iInitialize(400,400, "Balloon Game");
	iStart();
	
	return 0;
}