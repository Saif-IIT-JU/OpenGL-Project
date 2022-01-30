#include<stdio.h>
#include<math.h>
#include<bits/stdc++.h>
#include<windows.h>
#include<GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <mmsystem.h>

#define SPEED 30.0
const double PI = 3.141592654;

int frameNumber = 0;

float i=0.0,m=0.0,n=0.0,o=0.0,c=0.0,b=0.0,xm=900, th=0.0;
float p=0.75,q=0.47,r=0.14, xp, yp, sk=0.0;
float e=0.90,f=0.91,g=0.98;
int day;

void draw_pixel(GLint cx, GLint cy)
{

	glBegin(GL_POINTS);
		glVertex2i(cx,cy);
	glEnd();
}

void plotpixels(GLint h,GLint k, GLint x,GLint y)
{
	draw_pixel(x+h,y+k);
	draw_pixel(-x+h,y+k);
	draw_pixel(x+h,-y+k);
	draw_pixel(-x+h,-y+k);
	draw_pixel(y+h,x+k);
	draw_pixel(-y+h,x+k);
	draw_pixel(y+h,-x+k);
	draw_pixel(-y+h,-x+k);
}

void draw_circle(GLint h, GLint k, GLint r)
{
	GLint d=1-r, x=0, y=r;
	while(y>x)
	{
		plotpixels(h,k,x,y);
		if(d<0) d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels(h,k,x,y);
}

void rotation(double x1, double y1, double tx, double ty)
{
    double bh = th;

    th = th*PI/180;
    x1-=tx, y1-=ty;
    xp = x1*cos(th)-y1*sin(th);
    yp = x1*sin(th)+y1*cos(th);
    xp+=tx; yp+=ty;

    th = bh;
}


void draw_object()
{
int l;
glColor3f(0.0,0.9,0.9);
glBegin(GL_POLYGON);
glVertex2f(0,380);
glVertex2f(0,700);
glVertex2f(1100,700);
glVertex2f(1100,380);
glEnd();

//sun


	for(l=0;l<=35;l++)
{
		glColor3f(1.0,0.9,0.0);
		draw_circle(1000,650,l);
}

//cloud1


	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(160+i,625,l);

	}


	for(l=0;l<=35;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(200+i,625,l);
		draw_circle(225+i,625,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(265+i,625,l);
	}


//cloud2


	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(370+i,615,l);
}




	for(l=0;l<=35;l++)
	{

		glColor3f(1.0,1.0,1.0);
		draw_circle(410+i,615,l);
		draw_circle(435+i,615,l);
		draw_circle(470+i,615,l);
	}

for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(500+i,615,l);
}






//grass
glColor3f(0.6,0.8,0.196078);
glBegin(GL_POLYGON);
glVertex2f(0,160);
glVertex2f(0,380);
glVertex2f(1100,380);
glVertex2f(1100,160);
glEnd();

//windmill
glColor3f(0.6,0.8,0.196078);
glBegin(GL_POLYGON);
glVertex2f(600,380);
glVertex2f(605,380);
glVertex2f(605,480);
glVertex2f(600,480);
glEnd();

glColor3f(2.0f, 0.5f, 1.0f);
glBegin(GL_POLYGON);
glVertex2f(605,480);
rotation(670,470,605,480);
glVertex2f(xp,yp);
rotation(670,480,605,480);
glVertex2f(xp,yp);
glEnd();

glColor3f(2.0f, 0.5f, 1.0f);
glBegin(GL_POLYGON);
rotation(535,465,605,480);
glVertex2f(xp,yp);
glVertex2f(605,480);
rotation(535,445,605,480);
glVertex2f(xp,yp);
glEnd();
glColor3f(2.0f, 0.5f, 1.0f);
glBegin(GL_POLYGON);
rotation(605,535,605,480);
glVertex2f(xp,yp);
glVertex2f(605,480);
rotation(585,525,605,480);
glVertex2f(xp,yp);

glEnd();


glColor3f(0.6,0.8,0.196078);
glBegin(GL_POLYGON);
glVertex2f(440,380);
glVertex2f(445,380);
glVertex2f(445,480);
glVertex2f(440,480);
glEnd();
glColor3f(2.0f, 0.5f, 1.0f);
glBegin(GL_POLYGON);
rotation(510,490,445,480);
glVertex2f(xp,yp);
glVertex2f(445,480);
rotation(510,470,445,480);
glVertex2f(xp,yp);
glEnd();
glColor3f(2.0f, 0.5f, 1.0f);
glBegin(GL_POLYGON);
rotation(375,465,445,480);
glVertex2f(xp,yp);
glVertex2f(445,480);
rotation(375,445,445,480);
glVertex2f(xp,yp);
glEnd();
glColor3f(2.0f, 0.5f, 1.0f);
glBegin(GL_POLYGON);
rotation(425,525,445,480);
glVertex2f(xp,yp);
glVertex2f(445,480);
rotation(445,535,445,480);
glVertex2f(xp,yp);
glEnd();




glColor3f(0.6,0.8,0.196078);
glBegin(GL_POLYGON);
glVertex2f(280,380);
glVertex2f(285,380);
glVertex2f(285,480);
glVertex2f(280,480);
glEnd();
glColor3f(2.0f, 0.5f, 1.0f);
glBegin(GL_POLYGON);
rotation(350,490,285,480);
glVertex2f(xp,yp);
glVertex2f(285,480);
rotation(350,470,285,480);
glVertex2f(xp,yp);
glEnd();
glColor3f(2.0f, 0.5f, 1.0f);
glBegin(GL_POLYGON);
rotation(215,465,285,480);
glVertex2f(xp,yp);
glVertex2f(285,480);
rotation(215,445,285,480);
glVertex2f(xp,yp);
glEnd();
glColor3f(2.0f, 0.5f, 1.0f);
glBegin(GL_POLYGON);
rotation(265,525,285,480);
glVertex2f(xp,yp);
glVertex2f(285,480);
rotation(285,535,285,480);
glVertex2f(xp,yp);
glEnd();





//Ground
	glColor3f(0.0,0.3,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(-600,0);
		glVertex2f(-600,185);
		glVertex2f(1100,185);
		glVertex2f(1100,0);
	glEnd();

	//new road
 glColor3ub(69,69,69);
	glBegin(GL_POLYGON);
		glVertex2f(-600,185);
		glVertex2f(-600,300);
		glVertex2f(1100,300);
		glVertex2f(1100,185);
	glEnd();
//road divider
    glColor3ub(138,138,138);
    glBegin(GL_POLYGON);
		glVertex2f(-600,240);
		glVertex2f(-600,245);
		glVertex2f(1100,245);
		glVertex2f(1100,240);
	glEnd();

//tree2 smal
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(45,5);
glVertex2f(45,75);
glVertex2f(75,75);
glVertex2f(75,5);
glEnd();

	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(35,70,l);
		draw_circle(75,70,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(45,110,l);
		draw_circle(65,110,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(55,135,l);
	}


//tree 1 big
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(100,380);
glVertex2f(100,530);
glVertex2f(140,530);
glVertex2f(140,380);
glEnd();


	for(l=0;l<=40;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(40,530,l);
		draw_circle(90,530,l);
		draw_circle(150,530,l);
		draw_circle(210,530,l);
		draw_circle(65,590,l);
		draw_circle(115,590,l);
		draw_circle(175,590,l);

	}

	for(l=0;l<=55;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(115,620,l);


	}

		//lake


	/*for(l=0;l<=20;l++)
	{
		glColor3ub(127,255,212);
		draw_circle(370,615,l);
}*/
//lake outside
glColor3f(0.0,0.5,0.1);
glBegin(GL_POLYGON);
glVertex2f(150,5);
glVertex2f(385,5);
glVertex2f(385,175);
glVertex2f(150,175);
glEnd();
glColor3f(0.0,0.5,0.1);
glBegin(GL_POLYGON);
glVertex2f(145,10);
glVertex2f(380,10);
glVertex2f(380,180);
glVertex2f(145,180);
glEnd();
/*glColor3f(0.0,0.5,0.0);
glBegin(GL_POLYGON);
glVertex2f(390,375);
glVertex2f(625,375);
glVertex2f(625,205);
glVertex2f(390,205);
glEnd();
glColor3f(0.0,0.5,0.0);
glBegin(GL_POLYGON);
glVertex2f(385,365);
glVertex2f(620,365);
glVertex2f(620,190);
glVertex2f(385,190);
glEnd();*/
//lake inside
	for(l=0;l<=80;l++)
	{

		glColor3ub(175, 238 ,223);
		draw_circle(235,95,l);
		draw_circle(240,95,l);
		draw_circle(245,95,l);
		draw_circle(250,95,l);
		draw_circle(255,95,l);
		draw_circle(260,95,l);
		draw_circle(265,95,l);
		draw_circle(270,95,l);
		draw_circle(275,95,l);
		draw_circle(280,95,l);
		draw_circle(285,95,l);
		draw_circle(290,95,l);
		draw_circle(295,95,l);
		draw_circle(300,95,l);
	}
	for(l=0;l<=70;l++)
	{

		glColor3ub(0 ,245 ,255);
		draw_circle(235,95,l);
		draw_circle(240,95,l);
		draw_circle(245,95,l);
		draw_circle(250,95,l);
		draw_circle(255,95,l);
		draw_circle(260,95,l);
		draw_circle(265,95,l);
		draw_circle(270,95,l);
		draw_circle(275,95,l);
		draw_circle(280,95,l);
		draw_circle(285,95,l);
		draw_circle(290,95,l);
		draw_circle(295,95,l);
		draw_circle(300,95,l);
	}

//lake side tree2 small
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(500,5);
glVertex2f(500,75);
glVertex2f(485,75);
glVertex2f(485,5);
glEnd();

	for(l=0;l<=40;l++)
	{
		glColor3f(0.0,0.5,0.3);
		draw_circle(475,70,l);
		draw_circle(515,70,l);
	}

	for(l=0;l<=35;l++)
	{
		glColor3f(0.0,0.5,0.3);
		draw_circle(485,110,l);
		draw_circle(505,110,l);
	}

	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.3);
		draw_circle(495,135,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.3);
		draw_circle(495,145,l);
	}
	//car
glColor3f(1.0f, 0.5f, 0.0f);
glBegin(GL_POLYGON);
glVertex2f(400+m,246);
glVertex2f(590+m,246);
glVertex2f(590+m,276);
glVertex2f(400+m,276);
glEnd();

glColor3f(1.0f, 0.5f, 0.0f);
glBegin(GL_POLYGON);
glVertex2f(455+m,276);
glVertex2f(535+m,276);
glVertex2f(520+m,295);
glVertex2f(470+m,295);
glEnd();

glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
glBegin(GL_POLYGON);
glVertex2f(470+m,270);
glVertex2f(490+m,270);
glVertex2f(490+m,290);
glVertex2f(470+m,290);
glEnd();

glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
glBegin(GL_POLYGON);
glVertex2f(500+m,270);
glVertex2f(520+m,270);
glVertex2f(520+m,290);
glVertex2f(500+m,290);
glEnd();

glColor3ub(69,69,69);
glBegin(GL_POLYGON);
glVertex2f(560+m,276);
glVertex2f(590+m,246);
glVertex2f(590+m,276);
glEnd();

//glColor3ub(139,105 ,105);
glColor3ub(69,69,69);
glBegin(GL_POLYGON);
glVertex2f(400+m,276);
glVertex2f(400+m,246);
glVertex2f(430+m,276);

glEnd();

for(l=0;l<=14;l++)
	{
		glColor3f(0.0,0.0,0.0);
		draw_circle(550+m,250,l);
	}
for(l=0;l<=14;l++)
	{
		glColor3f(0.0,0.0,0.0);
		draw_circle(450+m,250,l);
	}
 	//roof

	glColor3f(0.35,0.0,0.0);
	glBegin(GL_POLYGON);

		glVertex2f(680,500);
		glVertex2f(720,600);
		glVertex2f(1030,600);
		glVertex2f(990,500);

	glEnd();
	glColor3ub(26, 26 ,26);
	glBegin(GL_POLYGON);

		glVertex2f(720,515);
		glVertex2f(720,590);
		glVertex2f(780,590);
		glVertex2f(780,515);

	glEnd();

	glColor3ub(26, 26 ,26);
	glBegin(GL_POLYGON);

		glVertex2f(790,515);
		glVertex2f(790,590);
		glVertex2f(850,590);
		glVertex2f(850,515);

	glEnd();

	glColor3ub(26, 26 ,26);
	glBegin(GL_POLYGON);

		glVertex2f(860,515);
		glVertex2f(860,590);
		glVertex2f(920,590);
		glVertex2f(920,515);

	glEnd();

	glColor3ub(26, 26 ,26);
	glBegin(GL_POLYGON);

		glVertex2f(930,515);
		glVertex2f(930,590);
		glVertex2f(990,590);
		glVertex2f(990,515);

	glEnd();
	glColor3ub(160 ,32 ,240);
	glBegin(GL_POLYGON);

		glVertex2f(930,530);
		glVertex2f(930,540);
		glVertex2f(990,540);
		glVertex2f(990,530);

	glEnd();

	glColor3ub(160 ,32 ,240);
	glBegin(GL_POLYGON);

		glVertex2f(930,560);
		glVertex2f(930,570);
		glVertex2f(990,570);
		glVertex2f(990,560);

	glEnd();

	glColor3ub(160 ,32 ,240);
	glBegin(GL_POLYGON);

		glVertex2f(940,515);
		glVertex2f(940,590);
		glVertex2f(950,590);
		glVertex2f(950,515);

	glEnd();

	glColor3ub(160 ,32 ,240);
	glBegin(GL_POLYGON);

		glVertex2f(970,515);
		glVertex2f(970,590);
		glVertex2f(980,590);
		glVertex2f(980,515);

	glEnd();

	glColor3ub(160 ,32 ,240);
	glBegin(GL_POLYGON);

		glVertex2f(860,530);
		glVertex2f(860,540);
		glVertex2f(920,540);
		glVertex2f(920,530);

	glEnd();

	glColor3ub(160 ,32 ,240);
	glBegin(GL_POLYGON);

		glVertex2f(860,560);
		glVertex2f(860,570);
		glVertex2f(920,570);
		glVertex2f(920,560);

	glEnd();

	glColor3ub(160 ,32 ,240);
	glBegin(GL_POLYGON);

		glVertex2f(870,515);
		glVertex2f(870,590);
		glVertex2f(880,590);
		glVertex2f(880,515);

	glEnd();

	glColor3ub(160 ,32 ,240);
	glBegin(GL_POLYGON);

		glVertex2f(720,530);
		glVertex2f(720,540);
		glVertex2f(780,540);
		glVertex2f(780,530);

	glEnd();


glColor3ub(160 ,32 ,240);
	glBegin(GL_POLYGON);

		glVertex2f(790,530);
		glVertex2f(790,540);
		glVertex2f(850,540);
		glVertex2f(850,530);

	glEnd();

	glColor3ub(160 ,32 ,240);
	glBegin(GL_POLYGON);

		glVertex2f(720,560);
		glVertex2f(720,570);
		glVertex2f(780,570);
		glVertex2f(780,560);

	glEnd();

	glColor3ub(160 ,32 ,240);
	glBegin(GL_POLYGON);

		glVertex2f(730,515);
		glVertex2f(730,590);
		glVertex2f(740,590);
		glVertex2f(740,515);

	glEnd();

	glColor3ub(160 ,32 ,240);
	glBegin(GL_POLYGON);

		glVertex2f(760,515);
		glVertex2f(760,590);
		glVertex2f(770,590);
		glVertex2f(770,515);

	glEnd();

	glColor3ub(160 ,32 ,240);
	glBegin(GL_POLYGON);

		glVertex2f(860,530);
		glVertex2f(860,540);
		glVertex2f(920,540);
		glVertex2f(920,530);

	glEnd();

	glColor3ub(160 ,32 ,240);
	glBegin(GL_POLYGON);

		glVertex2f(790,560);
		glVertex2f(790,570);
		glVertex2f(850,570);
		glVertex2f(850,560);

	glEnd();

	glColor3ub(160 ,32 ,240);
	glBegin(GL_POLYGON);

		glVertex2f(800,515);
		glVertex2f(800,590);
		glVertex2f(810,590);
		glVertex2f(810,515);

	glEnd();

	glColor3ub(160 ,32 ,240);
	glBegin(GL_POLYGON);

		glVertex2f(830,515);
		glVertex2f(830,590);
		glVertex2f(840,590);
		glVertex2f(840,515);

	glEnd();

glColor3ub(160 ,32 ,240);
	glBegin(GL_POLYGON);

		glVertex2f(900,515);
		glVertex2f(900,590);
		glVertex2f(910,590);
		glVertex2f(910,515);

	glEnd();


	//home

	//glColor3f(p,q,r);
	glColor3ub(189 ,183 ,107);
	glBegin(GL_POLYGON);

		glVertex2f(680,500);
		glVertex2f(680,300);
		glVertex2f(990,300);
		glVertex2f(990,500);
		glEnd();

glColor3f(0.1f, 0.1f, 0.1f);
	glBegin(GL_POLYGON);

		glVertex2f(990,500);
		glVertex2f(1070,500);
		glVertex2f(1030,600);

	glEnd();

	glColor3f(0.1f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);

		glVertex2f(990,500);
		glVertex2f(990,300);
		glVertex2f(1070,300);
		glVertex2f(1070,500);
		glEnd();

	//window border

	/*glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);

		glVertex2f(720,410);
		glVertex2f(720,480);
		glVertex2f(775,480);
		glVertex2f(775,410);

	glEnd();

	glBegin(GL_POLYGON);

		glVertex2f(825,205);
		glVertex2f(825,285);
		glVertex2f(905,285);
		glVertex2f(905,205);

	glEnd();*/




	//door
	glColor3f(e,f,g);
	glBegin(GL_POLYGON);

		glVertex2f(900,300);
		glVertex2f(900,400);
		glVertex2f(800,400);
		glVertex2f(800,300);

	glEnd();
	//inside_door
    glColor3f(0.35,0.0,0.0);
	glBegin(GL_POLYGON);

		glVertex2f(800,400);
		glVertex2f(800,300);
		glVertex2f(870,310);
		glVertex2f(870,390);

	glEnd();




	//window

	glColor3f(e,f,g);
   glColor3f(0.5f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);

		glVertex2f(710,480);
		glVertex2f(710,410);
		glVertex2f(780,410);
		glVertex2f(780,480);

	glEnd();
		glColor3f(0.1f, 0.1f, 0.0f);
	glBegin(GL_POLYGON);

		glVertex2f(730,480);
		glVertex2f(730,410);
		glVertex2f(735,410);
		glVertex2f(735,480);

	glEnd();
glColor3f(0.1f, 0.1f, 0.0f);
	glBegin(GL_POLYGON);

		glVertex2f(760,480);
		glVertex2f(760,410);
		glVertex2f(765,410);
		glVertex2f(765,480);

	glEnd();

	glColor3f(0.5f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);

		glVertex2f(910,480);
		glVertex2f(910,410);
		glVertex2f(980,410);
		glVertex2f(980,480);

	glEnd();

glColor3f(0.1f, 0.1f, 0.0f);
	glBegin(GL_POLYGON);

		glVertex2f(930,480);
		glVertex2f(930,410);
		glVertex2f(935,410);
		glVertex2f(935,480);

	glEnd();
	glColor3f(0.1f, 0.1f, 0.0f);
	glBegin(GL_POLYGON);

		glVertex2f(960,480);
		glVertex2f(960,410);
		glVertex2f(965,410);
		glVertex2f(965,480);

	glEnd();






glColor3f(0.73,0.16,0.96 );

	glBegin(GL_POLYGON);

		glVertex2f(250+i-xm,295+b);
		glVertex2f(280+i-xm,295+b);
		glVertex2f(280+i-xm,280+b);

	glEnd();

	glBegin(GL_POLYGON);

		glVertex2f(280+i-xm,305+b);
		glVertex2f(290+i-xm,305+b);
		glVertex2f(280+i-xm,295+b);


	glEnd();

	glBegin(GL_POLYGON);

		glVertex2f(200+i-xm,285+b);
		glVertex2f(230+i-xm,285+b);
		glVertex2f(230+i-xm,270+b);

	glEnd();

	glBegin(GL_POLYGON);

		glVertex2f(230+i-xm,295+b);
		glVertex2f(240+i-xm,295+b);
		glVertex2f(230+i-xm,285+b);


	glEnd();




	glBegin(GL_POLYGON);

		glVertex2f(150+i-xm,285+b);
		glVertex2f(180+i-xm,285+b);
		glVertex2f(180+i-xm,270+b);

	glEnd();

	glBegin(GL_POLYGON);

		glVertex2f(180+i-xm,295+b);
		glVertex2f(190+i-xm,295+b);
		glVertex2f(180+i-xm,285+b);


	glEnd();

//way

/*glBegin(GL_QUADS);
    //glColor3ub(153, 153, 102);
    //glColor3f(0.0, 0.0, 0.0)
    glColor3ub(69,69,69);
    glVertex2f(500,0);
    glVertex2f(700,300);
    glVertex2f(1000,300);
    glVertex2f(900,0);
    glEnd();


glBegin(GL_QUADS);
    glColor3ub(138,138,138);
    //glColor3f(0.0, 0.0, 0.0)

    glVertex2f(670,0);
    glVertex2f(850,300);
    glVertex2f(880,300);
    glVertex2f(700,0);
    glEnd();

glFlush();*/

//new road
 /*glColor3ub(69,69,69);
	glBegin(GL_POLYGON);
		glVertex2f(-600,185);
		glVertex2f(-600,300);
		glVertex2f(1100,300);
		glVertex2f(1100,185);
	glEnd();
//road divider
    glColor3ub(138,138,138);
    glBegin(GL_POLYGON);
		glVertex2f(-600,240);
		glVertex2f(-600,245);
		glVertex2f(1100,245);
		glVertex2f(1100,240);
	glEnd();*/

}





void idle()
{

bool flag = true;
if(i>=0 && i<=1150)
 {

i+=SPEED/50;
if(m<=500 && flag)
m+=SPEED/25;
else{ b-=SPEED/25; m=-b; flag=false; }

b+=SPEED/150;
th+=SPEED/10;

 }

glutPostRedisplay(); //glutPostRedisplay marks the current window as needing to be
                    //redisplayed.

}




void myinit()
{
glClearColor(1.0,1.0,1.0,0.0);
glColor3f(0.0,1.0,0.0);
glPointSize(2.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,1100.0,0.0,700.0);
}



void display()
{

glClear(GL_COLOR_BUFFER_BIT);
draw_object();
glFlush();
}


int main(int argc,char** argv)
{

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1100.0,700.0);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Simple Village");
	glutDisplayFunc(display);
    glutIdleFunc(idle);  //glutIdleFunc sets the global idle callback
                        //to be func so a GLUT program can perform background processing
                        // tasks or continuous animation when window system events are not
                        // being received.
	myinit();
    //adding sound

	sndPlaySound("breakout.wav",SND_ASYNC);

	//glutFullScreen();
	//PlaySound(TEXT("breakout.wav"),NULL,SND_SYNC);

	glutMainLoop();

	return 0;
}
