/*
---------MINIPROJECT ON-------------------------
---------GRAPHICAL VISUALIZATION OF-------------
---------BIRTH OF PLANET EARTH------------------

---------CREATED BY-----------------------------
---------Mohammed Afzel & Derrick Abreo---------
*/


#include <gl/glut.h>
#include <stdio.h>
#include<string.h>
#include<math.h>
float a1x,z,a[1000],b[1000],x,temp,z,ex,ax2=0,earth_exp=0,ax3=0,ax4=0;
int NumberOfPoints = 600,a1flag1=0,tx,a1flag2=0,a1flag3=0,a1flag4=0,tflag=0,i,j=0,a2flag1=0,a2flag2=0,a2flag3=0,a2flag4=0,cr,cg;
int wflag=0,cflag=0;
float tm,rainx[1000],rainy[1000],xw,xc=0;
float xtimer1,xtimer2,xtimer3,xtimer4,x_grass[1000],y_grass[1000];
int flag1=0,flag2=0,flag3=0,flag4=0;
int ct=150; //to set the position in x axis
int xvt,flagvb1=0,flagvb2=0,flagvb3=0,sflag;
float xvb;

//for layers of earth
void timer1(int v)
{
     xtimer1=xtimer1+2;
     if(xtimer1==560)
     	flag1=1;
     glutPostRedisplay();
     glutTimerFunc(500,timer1,0);
}

void timer2(int v)
{
     xtimer2=xtimer2+2;
     if(xtimer2==784)
     	flag2=1;
     glutPostRedisplay();
     glutTimerFunc(500,timer2,0);
}
void timer3(int v)
{
     xtimer3=xtimer3+2;
     if(xtimer3==760)
     	flag3=1;
     glutPostRedisplay();
     glutTimerFunc(500,timer3,0);
}
void timer4(int v)
{
     xtimer4=xtimer4+2;
     if(xtimer4==760)
     	flag4=1;
     glutPostRedisplay();
     glutTimerFunc(500,timer4,0);
}

void timer_volc(int w)
{
     tm=tm+0.5;

     glutPostRedisplay();
     glutTimerFunc(5000,timer_volc,0);

}

//for water filling
void timer_water(int v)
{
      xw=xw+0.5;
     if(xw==250)
	  wflag=1;
	 glutPostRedisplay();
     glutTimerFunc(100,timer_water,0);
 }

 //for clouds
void timer_cloud(int v)
{
      xc=xc+0.5;
     if(xc==1250)
     cflag=1;

	 glutPostRedisplay();
     glutTimerFunc(100,timer_cloud,0);
 }

//asteroid timer
void timer_asteroids1(int v)
{
     a1x=a1x+0.5;

       if(a1x==199)
         a1flag3=1;
       if(a1x==120)
     	 a1flag1=1;
       if(a1x==125)
    	 a1flag2=1;
       if(a1x==390)
       	 a1flag4=1;

	 glutPostRedisplay();
     glutTimerFunc(1000,timer_asteroids1,0);
 }
void timer_asteroid2(int v)
{
     ax2=ax2+0.5;

       if(ax2==199)
       {
         a2flag3=1;
  		earth_exp +=5;
  		cr +=5;
  		cg +=5;
	   }
	   if(ax2==120)
	   {
     	 a2flag1=1;
   	earth_exp +=5;
   	cr +=5;
  		cg +=5;
   }
	   if(ax2==125){
    	 a2flag2=1;
    	 earth_exp +=5;
    	 cr +=5;
  		cg +=5;
    }
       if(ax2==390)
       {
       	 a2flag4=1;
       	 earth_exp +=5;
       	 cr +=5;
  		cg +=5;
   	}
	 glutPostRedisplay();
     glutTimerFunc(1000,timer_asteroid2,0);
 }
void timer_asteroids_extras1(int v)
{
     ax3=ax3+0.3;
     glutPostRedisplay();
     glutTimerFunc(2000,timer_asteroids_extras1,0);
}
void timer_asteroids_extras2(int v)
{
     ax4=ax4+0.3;
     glutPostRedisplay();
     glutTimerFunc(2000,timer_asteroids_extras2,0);
}
//color to the stars
void timer_twinkle(int v)
{
	int temp,temp1,temp2;
	tx=tx+1;
	temp=tx%7;
	temp1=tx%13;
	if(temp==0)
	tflag=1;
	if(temp1==0)
	tflag=10;
	else tflag=0;
	//for smoke
	temp2=tx%20;
	if(temp2==0)
	sflag=1;
	glutPostRedisplay();
	glutTimerFunc(100,timer_twinkle,0);
}
void timer_volcano_events(int v)
{
      xvt=xvt+1;
      if(xvt==100)
	 	flagvb1=1;
	 if(xvt==300)
	 	flagvb1=2;
	if(xvt==1000)
		flagvb1=3;
	 glutPostRedisplay();
     glutTimerFunc(1000,timer_volcano_events,0);
 }
void timer_volcano_break(int v)
{
     xvb=xvb+0.5;
      if(xvb==150)
	   flagvb2=1;
	 glutPostRedisplay();
     glutTimerFunc(500,timer_volcano_break,0);
 }

//intro stuff
void printstring(float x,float y,char *string,void *font)
{
int length,s;
glRasterPos2f(x,y);
length=(int)strlen(string);
for(s=0;s<length;s++)
{
glutBitmapCharacter(font,string[s]);
}

//glFlush();
}
void intro()
{
glColor3ub(191,191,191);
glPushMatrix();
printstring(450,700,"SRINIVAS SCHOOL OF ENGINEERING",GLUT_BITMAP_TIMES_ROMAN_24);
printstring(450,620,"COMPUTER SCIENCE DEPARTMENT",GLUT_BITMAP_TIMES_ROMAN_24);
printstring(420,540,"A MINI PROJECT ON GRAPHICAL VISUALIZATION OF",GLUT_BITMAP_HELVETICA_18);
printstring(500,460,"BIRTH OF PLANET EARTH",GLUT_BITMAP_TIMES_ROMAN_24);
printstring(635,380,"BY",GLUT_BITMAP_HELVETICA_18);
printstring(350,280,"MOHAMMED AFZEL",GLUT_BITMAP_HELVETICA_18);
printstring(780,280,"DERRICK ABREO",GLUT_BITMAP_HELVETICA_18);
printstring(375,250,"4ES13CS026",GLUT_BITMAP_HELVETICA_18);
printstring(800,250,"4ES13CS078",GLUT_BITMAP_HELVETICA_18);
glColor3ub(255,201,14);
printstring(525,200,"[Press 'd' or 'D' to Continue...!]",GLUT_BITMAP_HELVETICA_18);
printstring(530,170,"[Press 'q' or 'Q' to Quit...!]",GLUT_BITMAP_HELVETICA_18);
glPopMatrix();
glFlush();
}


//common function
void print(char s[])
{
     int i,it;
     for(i=0;i<strlen(s);i++)
     {
	     glutStrokeCharacter(GLUT_STROKE_ROMAN,s[i]);

	}
}
void temp_table()
{

		//glPushMatrix();
		//glTranslatef(900,100,0)

		glPushMatrix();
		glTranslatef(900,300,0);
		glScalef(0.15,0.15,0.15);
		print("TEMPERATURE OF  DIFFERENT LAYERS");
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1050,220,0);
		glScalef(0.1,0.1,0.1);
		print("INNER CORE-7200 deg C");
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1050,180,0);
		glScalef(0.1,0.1,0.1);
		print("OUTER CORE-4300 deg C");
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1050,140,0);
		glScalef(0.1,0.1,0.1);
		print("MANTLE-3700 deg C");
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1050,100,0);
		glScalef(0.1,0.1,0.1);
		print("CRUST-870 deg C");
		glPopMatrix();

	//glPopMatrix();
}

void crust()
{
	float theta;
		glPushMatrix();
		glTranslatef(500,250,0);
		glScalef(0.2,0.2,0.2);
		print("CRUST");
		glPopMatrix();

		//outer semicircle
	float PI = 3.14,angle,xrad=105,yrad=111.5,xc,yc;
	float step=5.0;
	glPushMatrix();
	glColor3ub(52,148,190);
 	glTranslatef(1115-ct,800,0);
	glRotatef(180,0,0,1);
	glBegin(GL_POLYGON);
 	for(angle=0.0f;angle<=180; angle+=step)
 	{
    	float rad  = PI*angle/180;
    	xc  = 400+xrad*sin(rad);
    	yc  = 400+yrad*cos(rad);
    	glVertex2f(xc,yc);

	}
	glEnd();
	glPopMatrix();

  //outer circle
	int radiusy2=112,radiusx2=44,xc2=720-ct,yc2=400;
	glColor3ub(126,76,68);
	glBegin(GL_POLYGON);
	for(theta=0;theta<360;theta++)
	{

		glVertex2f(xc2+(radiusx2*cos(theta)),yc2+(radiusy2*sin(theta)));
	}
	glEnd();

	//inner circle
	int radiusy1=108,radiusx1=40,xc1=720-ct,yc1=400;

	glColor3ub(81,24,30);
	glBegin(GL_POLYGON);
	for(theta=0;theta<360;theta++)
	{

		glVertex2f(xc1+(radiusx1*cos(theta)),yc1+(radiusy1*sin(theta)));
	}
	glEnd();


}

void mantle()
{
	float theta;
		glPushMatrix();
		glColor3ub(255,128,0);
		glTranslatef(580,550,0);
		glScalef(0.2,0.2,0.2);
		print("MANTLE");
		glPopMatrix();

	//outer semicircle
	float PI = 3.14,angle,xrad=105,yrad=108,xc,yc;
	float step=5.0;
	glPushMatrix();
	glColor3ub(180,49,41);
 	glTranslatef(1205-ct,800,0);
	glRotatef(180,0,0,1);
	glBegin(GL_POLYGON);
 	for(angle=0.0f;angle<=180; angle+=step)
 	{
    	float rad  = PI*angle/180;
    	xc  = 400+xrad*sin(rad);
    	yc  = 400+yrad*cos(rad);
    	glVertex2f(xc,yc);

	}
	glEnd();
	glPopMatrix();

	//outer circle
	int radiusy2=108,radiusx2=70,xc2=810-ct,yc2=400;

  glColor3ub(237,116,59);
	glBegin(GL_POLYGON);
	for(theta=0;theta<360;theta++)
	{
		glVertex2f(xc2+(radiusx2*cos(theta)),yc2+(radiusy2*sin(theta)));
	}
	glEnd();

	//inner circle
	int radiusy1=75,radiusx1=50,xc1=810-ct,yc1=400;

  glColor3ub(134,53,50);
	glBegin(GL_POLYGON);
	for(theta=0;theta<360;theta++)
	{
		glVertex2f(xc1+(radiusx1*cos(theta)),yc1+(radiusy1*sin(theta)));
	}
	glEnd();

}

void outercore()
{	float theta;

		glPushMatrix();
		glTranslatef(700,250,0);
		glScalef(0.2,0.2,0.2);
		print("Outer Core");
		glPopMatrix();

	//outer semicircle
	float PI = 3.14,angle,xrad=75,yrad=75,xc,yc;
	float step=5.0;
	glPushMatrix();
	glColor3ub(237,174,107);
 	glTranslatef(1286-ct,800,0);
	glRotatef(180,0,0,1);
	glBegin(GL_POLYGON);
 	for(angle=0.0f;angle<=180; angle+=step)
 	{
    	float rad  = PI*angle/180;
    	xc  = 400+xrad*sin(rad);
    	yc  = 400+yrad*cos(rad);
    	glVertex2f(xc,yc);

	}
	glEnd();
	glPopMatrix();

	//outer circle
	int radiusy2=75,radiusx2=42,xc2=890-ct,yc2=400;
	glColor3ub(255,222,156);
	glBegin(GL_POLYGON);
	for(theta=0;theta<360;theta++)
	{
	  glVertex2f(xc2+(radiusx2*cos(theta)),yc2+(radiusy2*sin(theta)));
	}
	glEnd();

	//inner circle
	int radiusy1=50,radiusx1=30,xc1=890-ct,yc1=400;

	glColor3ub(250,190,127);
	glBegin(GL_POLYGON);
	for(theta=0;theta<360;theta++)
	{
		glVertex2f(xc1+(radiusx1*cos(theta)),yc1+(radiusy1*sin(theta)));
	}
	glEnd();


}

void innercore()
{

		glPushMatrix();
		glTranslatef(800,500,0);
		glScalef(0.2,0.2,0.2);
		print("Inner Core");
		glPopMatrix();


	glColor3ub(253,248,184);
	glTranslatef(960-ct,400,0);
	glutSolidSphere(50,30,30);

}

void sick()
 {
 	glPushMatrix();
 	glColor3f(1,1,0);
 	glTranslatef(300,550,0);

 	glutSolidSphere(50,30,30);
 	glPopMatrix();
 	glPushMatrix();
 	glTranslatef(50,0,0);
 	glBegin(GL_POLYGON);
 	glVertex2f(210,520);
 	glVertex2f(180,490);
 	glVertex2f(230,520);
 	glEnd();
 	glPopMatrix();

 }

 void thermometer()
 {
 	glPushMatrix();
 	glColor3f(1,1,1);
 	glBegin(GL_POLYGON);

 	glVertex2f(180,410);
 	glVertex2f(300,450);
 	glVertex2f(300,430);

 	glEnd();
 	glBegin(GL_LINES);
 	glLineWidth(5);
 	glColor3f(1,0,0);
 	glVertex2f(180,410);
 	glVertex2f(300,440);
 	glVertex2f(180,410);
 	glVertex2f(300,441);
 		glVertex2f(180,410);
 	glVertex2f(300,442);
 	glEnd();
 	glPopMatrix();
 	glPushMatrix();
 	glTranslatef(305,440,0);
 	glutSolidSphere(10,30,30);
 	glPopMatrix();
 	glPushMatrix();
 	glColor3f(0,0,0);
 	glTranslatef(180,410,0);
 	glutSolidSphere(10,30,30);
 	glPopMatrix();
 	//eyes
 	glPushMatrix();

	glColor3f(0,0,0);
glTranslatef(20,335,0);
	{
		glBegin(GL_POLYGON);
	glVertex2f(100,100);
	glVertex2f(100,110);
	glVertex2f(110,110);
	glVertex2f(110,100);
 	glEnd();
 }
 	glPopMatrix();


 		glPushMatrix();

	glColor3f(0,0,0);
glTranslatef(80,353,0);
	{
		glBegin(GL_POLYGON);
	glVertex2f(100,100);
	glVertex2f(100,110);
	glVertex2f(110,110);
	glVertex2f(110,100);
 	glEnd();
 }
 	glPopMatrix();
 }
void interact()
{
	glPushMatrix();
	glTranslatef(300,280,0);
	glColor3ub(222,222,222);
	glutSolidSphere(70,30,30);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(222,222,222);
	glBegin(GL_POLYGON);
	glVertex2f(270,290);
	glVertex2f(300,320);
	glVertex2f(230,340);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glColor3ub(139,63,139);
	glTranslatef(265,310,0.0);
    glScalef(0.12,0.12,0.12);
    print("Press 'D'");
	glPopMatrix();

	glPushMatrix();
    glColor3ub(139,63,139);
	glTranslatef(245,281,0.0);
    glScalef(0.12,0.12,0.12);
    print("or 'd' to know");
	glPopMatrix();
	glPushMatrix();
    glColor3ub(139,63,139);
	glTranslatef(275,254,0.0);
    glScalef(0.12,0.12,0.12);
    print("more ");
	glPopMatrix();

	glPushMatrix();
    glColor3ub(139,63,139);
	glTranslatef(250,254-19,0.0);
    glScalef(0.12,0.12,0.12);
    print("about EARTH ");
	glPopMatrix();

}

void tree()
{
	glColor3ub(185,122,87);
	glBegin(GL_POLYGON);
	glVertex2f(400,200);
	glVertex2f(410,400);
	glVertex2f(440,400);
	glVertex2f(460,200);
	glEnd();
	//leaf
	glColor3f(0,1,0);
	glPushMatrix();
	glTranslatef(390,430,0);
	glutSolidSphere(50,30,30);
	glTranslatef(10,50,0);
	glutSolidSphere(50,30,30);
	glTranslatef(50,10,0);
	glutSolidSphere(50,30,30);
	glTranslatef(10,-50,0);
	glutSolidSphere(50,30,30);
	glPopMatrix();
	//branch1
	glColor3ub(185,122,87);
	glBegin(GL_POLYGON);
	glVertex2f(410,380);
	glVertex2f(390,420);
	glVertex2f(400,420);
	glVertex2f(430,380);
	glEnd();

	//tree2
	glPushMatrix();
	glTranslatef(770,180,0);
	glScalef(0.2,0.2,0.2);

	{
	glColor3ub(185,122,87);
	glBegin(GL_POLYGON);
	glVertex2f(400,200);
	glVertex2f(410,400);
	glVertex2f(440,400);
	glVertex2f(460,200);
	glEnd();
	//leaf
	glColor3f(0,1,0);
	glPushMatrix();
	glTranslatef(390,430,0);
	glutSolidSphere(50,30,30);
	glTranslatef(10,50,0);
	glutSolidSphere(50,30,30);
	glTranslatef(50,10,0);
	glutSolidSphere(50,30,30);
	glTranslatef(10,-50,0);
	glutSolidSphere(50,30,30);
	glPopMatrix();
	//branch1
	glColor3ub(185,122,87);
	glBegin(GL_POLYGON);
	glVertex2f(410,380);
	glVertex2f(390,420);
	glVertex2f(400,420);
	glVertex2f(430,380);
	glEnd();
    }
    glPopMatrix();

	//tree3
	glPushMatrix();
	glTranslatef(350,350,0);
	glScalef(0.5,0.5,0.5);

	{
	glColor3ub(185,122,87);
	glBegin(GL_POLYGON);
	glVertex2f(400,200);
	glVertex2f(410,400);
	glVertex2f(440,400);
	glVertex2f(460,200);
	glEnd();
	//leaf
	glColor3f(0,1,0);
	glPushMatrix();
	glTranslatef(390,430,0);
	glutSolidSphere(50,30,30);
	glTranslatef(10,50,0);
	glutSolidSphere(50,30,30);
	glTranslatef(50,10,0);
	glutSolidSphere(50,30,30);
	glTranslatef(10,-50,0);
	glutSolidSphere(50,30,30);
	glPopMatrix();
	//branch1
	glColor3ub(185,122,87);
	glBegin(GL_POLYGON);
	glVertex2f(410,380);
	glVertex2f(390,420);
	glVertex2f(400,420);
	glVertex2f(430,380);
	glEnd();
    }
    glPopMatrix();

	//tree4_chrismtas
	glPushMatrix();
	glTranslatef(778,100,0);
	glScalef(0.5,0.5,0.5);
	{
	glColor3ub(135,84,56);
	glBegin(GL_POLYGON);
	glVertex2f(400,200);
	glVertex2f(410,400);
	glVertex2f(440,400);
	glVertex2f(460,200);
	glEnd();
	}
    glPopMatrix();
	//leaf
	glPushMatrix();
	glTranslatef(950,350,0);
	glColor3f(0,0.7,0);
	{
	glScalef(8,8,8);
	glBegin(GL_POLYGON);
	glVertex3f(0,0,0);
	glVertex3f(5,10,0);
	glVertex3f(10,0,0);
	glEnd();
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(950,320,0);
	{
	glScalef(8,8,8);
	glBegin(GL_POLYGON);
	glVertex3f(0,0,0);
	glVertex3f(5,10,0);
	glVertex3f(10,0,0);
	glEnd();
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(950,290,0);
	{
	glScalef(8,8,8);
	glBegin(GL_POLYGON);
	glVertex3f(0,0,0);
	glVertex3f(5,10,0);
	glVertex3f(10,0,0);
	glEnd();
	}
	glPopMatrix();


	//tree5_chrismtas_repeat
	for(i=0;i<200;i+=50)
	{
	glPushMatrix();
	glTranslatef(-40+i,-140+i,0);
	glPushMatrix();
	glTranslatef(-900,250,0);
	glPushMatrix();
	glTranslatef(778,100,0);
	glScalef(0.5,0.5,0.5);
	glColor3ub(135,84,56);
	glBegin(GL_POLYGON);
	glVertex2f(400,200);
	glVertex2f(410,400);
	glVertex2f(440,400);
	glVertex2f(460,200);
	glEnd();
    glPopMatrix();
	//leaf
	glPushMatrix();
	glTranslatef(950,350,0);
	glColor3ub(0,120,0);
	glScalef(8,8,8);
	glBegin(GL_POLYGON);
	glVertex3f(0,0,0);
	glVertex3f(5,10,0);
	glVertex3f(10,0,0);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(950,320,0);
	glScalef(8,8,8);
	glBegin(GL_POLYGON);
	glVertex3f(0,0,0);
	glVertex3f(5,10,0);
	glVertex3f(10,0,0);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(950,290,0);
	glScalef(8,8,8);
	glBegin(GL_POLYGON);
	glVertex3f(0,0,0);
	glVertex3f(5,10,0);
	glVertex3f(10,0,0);
	glEnd();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	}

	//christmas_tree repeat
	for(i=0;i<200;i+=50)
	{
	glPushMatrix();
	glTranslatef(80+i,-130+i,0);
	glPushMatrix();
	glTranslatef(-900,250,0);
	glPushMatrix();
	glTranslatef(778,100,0);
	glScalef(0.5,0.5,0.5);
	glColor3ub(135,84,56);
	glBegin(GL_POLYGON);
	glVertex2f(400,200);
	glVertex2f(410,400);
	glVertex2f(440,400);
	glVertex2f(460,200);
	glEnd();
    glPopMatrix();
	//leaf
	glPushMatrix();
	glTranslatef(950,350,0);
	glColor3f(0,0.7,0);
	glScalef(8,8,8);
	glBegin(GL_POLYGON);
	glVertex3f(0,0,0);
	glVertex3f(5,10,0);
	glVertex3f(10,0,0);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(950,320,0);
	glScalef(8,8,8);
	glBegin(GL_POLYGON);
	glVertex3f(0,0,0);
	glVertex3f(5,10,0);
	glVertex3f(10,0,0);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(950,290,0);
	glScalef(8,8,8);
	glBegin(GL_POLYGON);
	glVertex3f(0,0,0);
	glVertex3f(5,10,0);
	glVertex3f(10,0,0);
	glEnd();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

	for(i=0;i<500;i+=130)
	{
		//tree2 repeat
	glPushMatrix();
	glScalef(0.6,0.6,0.6);
	glTranslatef(1730-i,500,0);

	{
	glColor3ub(185,122,87);
	glBegin(GL_POLYGON);
	glVertex2f(400,200);
	glVertex2f(410,400);
	glVertex2f(440,400);
	glVertex2f(460,200);
	glEnd();
	//leaf
	glColor3f(0,1,0);
	glPushMatrix();
	glTranslatef(390,430,0);
	glutSolidSphere(50,30,30);
	glTranslatef(10,50,0);
	glutSolidSphere(50,30,30);
	glTranslatef(50,10,0);
	glutSolidSphere(50,30,30);
	glTranslatef(10,-50,0);
	glutSolidSphere(50,30,30);
	glPopMatrix();
	//branch1
	glColor3ub(185,122,87);
	glBegin(GL_POLYGON);
	glVertex2f(410,380);
	glVertex2f(390,420);
	glVertex2f(400,420);
	glVertex2f(430,380);
	glEnd();
    }
    glPopMatrix();

	}
}
void grass_display()
{

	glColor3f(0,1,0);
	glTranslatef(x_grass[i],y_grass[i],0);
	glBegin(GL_POLYGON);
	glVertex2f(200,200);
	glVertex2f(180,250);
	glVertex2f(220,200);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(220,200);
	glVertex2f(260,250);
	glVertex2f(240,200);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(210,200);
	glVertex2f(220,258);
	glVertex2f(230,200);
	glEnd();

	glPushMatrix();
    glTranslatef(400,200,0);
    {
    glBegin(GL_POLYGON);
	glVertex2f(200,200);
	glVertex2f(180,250);
	glVertex2f(220,200);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(220,200);
	glVertex2f(260,250);
	glVertex2f(240,200);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(210,200);
	glVertex2f(220,258);
	glVertex2f(230,200);
	glEnd();
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(600,150,0);
    {
    glBegin(GL_POLYGON);
	glVertex2f(200,200);
	glVertex2f(180,250);
	glVertex2f(220,200);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(220,200);
	glVertex2f(260,250);
	glVertex2f(240,200);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(210,200);
	glVertex2f(220,258);
	glVertex2f(230,200);
	glEnd();
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(600,100,0);
    {
    	glBegin(GL_POLYGON);
	glVertex2f(200,200);
	glVertex2f(180,250);
	glVertex2f(220,200);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(220,200);
	glVertex2f(260,250);
	glVertex2f(240,200);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(210,200);
	glVertex2f(220,258);
	glVertex2f(230,200);
	glEnd();
    }
    glPopMatrix();

	glPushMatrix();
    glTranslatef(150,100,0);
    {
    	glBegin(GL_POLYGON);
	glVertex2f(200,200);
	glVertex2f(180,250);
	glVertex2f(220,200);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(220,200);
	glVertex2f(260,250);
	glVertex2f(240,200);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(210,200);
	glVertex2f(220,258);
	glVertex2f(230,200);
	glEnd();
    }
    glPopMatrix();

	glPushMatrix();
    glTranslatef(150,100,0);
    {
    	glBegin(GL_POLYGON);
	glVertex2f(200,200);
	glVertex2f(180,250);
	glVertex2f(220,200);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(220,200);
	glVertex2f(260,250);
	glVertex2f(240,200);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(210,200);
	glVertex2f(220,258);
	glVertex2f(230,200);
	glEnd();
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(100,40,0);
    {
    	glBegin(GL_POLYGON);
	glVertex2f(200,200);
	glVertex2f(180,250);
	glVertex2f(220,200);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(220,200);
	glVertex2f(260,250);
	glVertex2f(240,200);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(210,200);
	glVertex2f(220,258);
	glVertex2f(230,200);
	glEnd();
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(650,100,0);
    {
    	glBegin(GL_POLYGON);
	glVertex2f(200,200);
	glVertex2f(180,250);
	glVertex2f(220,200);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(220,200);
	glVertex2f(260,250);
	glVertex2f(240,200);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(210,200);
	glVertex2f(220,258);
	glVertex2f(230,200);
	glEnd();
    }
    glPopMatrix();
  glPushMatrix();
        glTranslatef(700,80,0);
    {
    	glBegin(GL_POLYGON);
	glVertex2f(200,200);
	glVertex2f(180,250);
	glVertex2f(220,200);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(220,200);
	glVertex2f(260,250);
	glVertex2f(240,200);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(210,200);
	glVertex2f(220,258);
	glVertex2f(230,200);
	glEnd();
    }
    glPopMatrix();
  glPushMatrix();
    glTranslatef(80,50,0);
    {
    	glBegin(GL_POLYGON);
	glVertex2f(200,200);
	glVertex2f(180,250);
	glVertex2f(220,200);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(220,200);
	glVertex2f(260,250);
	glVertex2f(240,200);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(210,200);
	glVertex2f(220,258);
	glVertex2f(230,200);
	glEnd();
    }
    glPopMatrix();
{
    glPushMatrix();
    glTranslatef(50,70,0);
    {
    	glBegin(GL_POLYGON);
	glVertex2f(200,200);
	glVertex2f(180,250);
	glVertex2f(220,200);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(220,200);
	glVertex2f(260,250);
	glVertex2f(240,200);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(210,200);
	glVertex2f(220,258);
	glVertex2f(230,200);
	glEnd();
    }
    glPopMatrix();

	glPushMatrix();
    glTranslatef(300,80,0);
    {
    	glBegin(GL_POLYGON);
	glVertex2f(200,200);
	glVertex2f(180,250);
	glVertex2f(220,200);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(220,200);
	glVertex2f(260,250);
	glVertex2f(240,200);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(210,200);
	glVertex2f(220,258);
	glVertex2f(230,200);
	glEnd();
    }
    glPopMatrix();

	glPushMatrix();
    glTranslatef(600,200,0);
    {
    	glBegin(GL_POLYGON);
	glVertex2f(200,200);
	glVertex2f(180,250);
	glVertex2f(220,200);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(220,200);
	glVertex2f(260,250);
	glVertex2f(240,200);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(210,200);
	glVertex2f(220,258);
	glVertex2f(230,200);
	glEnd();
    }
    glPopMatrix();

	glPushMatrix();
    glTranslatef(700,250,0);
    {
    	glBegin(GL_POLYGON);
	glVertex2f(200,200);
	glVertex2f(180,250);
	glVertex2f(220,200);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(220,200);
	glVertex2f(260,250);
	glVertex2f(240,200);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(210,200);
	glVertex2f(220,258);
	glVertex2f(230,200);
	glEnd();
    }
    glPopMatrix();

	glPushMatrix();
    glTranslatef(100,150,0);
    {
    	glBegin(GL_POLYGON);
	glVertex2f(200,200);
	glVertex2f(180,250);
	glVertex2f(220,200);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(220,200);
	glVertex2f(260,250);
	glVertex2f(240,200);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(210,200);
	glVertex2f(220,258);
	glVertex2f(230,200);
	glEnd();
    }
    glPopMatrix();
	//grass on border
	for(i=0;i<1080;i+=15)
    {
    glPushMatrix();
    glTranslatef(160+i,-100,0);
    {
    glScalef(0.5,0.5,0.5);
	glBegin(GL_POLYGON);
	glVertex2f(200,200);
	glVertex2f(180,250);
	glVertex2f(220,200);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(220,200);
	glVertex2f(260,250);
	glVertex2f(240,200);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(210,200);
	glVertex2f(220,258);
	glVertex2f(230,200);
	glEnd();
    }
    glPopMatrix();
	}
}
}
void lava()
{
float x_axis[100],y_axis[100];
	int i,ht=10,pt_size=3,tm=0;

	//layer1
	for(i=0;i<100;i++){
		//(rand()%(MAX-MIX))+MIN)
		x_axis[i]=(rand()%(1160-1120))+1120;
		y_axis[i]=(rand()%(270+ht-250))+250;
	}
	glColor3f(1,0,0);
    glPointSize(pt_size);
	glBegin(GL_POINTS);

    for(i=0;i<50;i++)
    {
     	glVertex2f(x_axis[i],y_axis[i]);
    }
    glEnd();
	glPopMatrix();

	//layer2
	for(i=0;i<100;i++){
		//(rand()%(MAX-MIX))+MIN)
		x_axis[i]=(rand()%(1180-1100))+1100;
		y_axis[i]=(rand()%(300+ht-270+ht))+270;
	}
	glColor3f(1,0,0);
    glPointSize(pt_size);
	glBegin(GL_POINTS);

    for(i=0;i<40;i++)
    {
     	glVertex2f(x_axis[i],y_axis[i]);
    }
    glEnd();

	//layer3
		for(i=0;i<100;i++){
		//(rand()%(MAX-MIX))+MIN)
		x_axis[i]=(rand()%(1200-1080))+1080;
		y_axis[i]=(rand()%(320+ht-300+ht))+300;
	}
	glColor3f(1,0,0);
    glPointSize(pt_size);
	glBegin(GL_POINTS);

    for(i=0;i<30;i++)
    {
     	glVertex2f(x_axis[i],y_axis[i]);
    }
    glEnd();

	//layer4
		for(i=0;i<100;i++){
		//(rand()%(MAX-MIX))+MIN)
		x_axis[i]=(rand()%(1220-1060))+1060;
		y_axis[i]=(rand()%(340+ht-320+ht))+300;
	}
	glColor3f(1,0,0);
    glPointSize(pt_size);
	glBegin(GL_POINTS);

    for(i=0;i<20;i++)
    {
     	glVertex2f(x_axis[i],y_axis[i]);
    }
    glEnd();
    for(i=0;i<100000000;i++);
}
//gray background
void clouds1()
{
 if(cflag==1)
	{
		glColor3ub(205,205,205);
	glPushMatrix();
	glBegin(GL_POLYGON);
	glVertex2f(0,500);
	glVertex2f(0,768);
	glVertex2f(1350,768);
	glVertex2f(1350,500);
	glEnd();
	glPopMatrix();
	}
}

void cloud3()
{
	glColor3ub(247,247,247);
		glPushMatrix();
	glTranslatef(50,700,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(85,720,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(130,720,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(85,680,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(130,680,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(160,700,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();


	glColor3ub(247,247,247);
		glPushMatrix();
	glTranslatef(50+400,700,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(85+400,720,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(130+400,720,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(85+400,680,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(130+400,680,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(160+400,700,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();

	glColor3ub(247,247,247);
		glPushMatrix();
	glTranslatef(50+900,700-20,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(85+900,720-20,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(130+900,720-20,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(85+900,680-20,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(130+900,680-20,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(160+900,700-20,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
}
void clouds2()
{
	int i,x0=0,y0=130;
	if(cflag==0)
	{
	glPushMatrix();
	glTranslatef(1320-xc,00,0);
	for(i=0;i<7;i++)
	{
	glColor3ub(180,180,180);
		glPushMatrix();
	glTranslatef(50+x0,700,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(85+x0,720,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(130+x0,720,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(85+x0,680,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(130+x0,680,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(160+x0,700,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
	x0=x0+190;
	}
	x0=0;
	for(i=0;i<7;i++)
	{
	glColor3ub(180,180,180);
		glPushMatrix();
	glTranslatef(50+x0,700-y0,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(85+x0,720-y0,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(130+x0,720-y0,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(85+x0,680-y0,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(130+x0,680-y0,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(160+x0,700-y0,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
	x0=x0+190;
	}
	glPopMatrix();
	}
	else if(cflag==1)
	{

	for(i=0;i<7;i++)
	{
	glColor3ub(180,180,180);
		glPushMatrix();
	glTranslatef(50+x0,700,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(85+x0,720,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(130+x0,720,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(85+x0,680,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(130+x0,680,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(160+x0,700,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
	x0=x0+190;
	}
	x0=0;
	for(i=0;i<7;i++)
	{
	glColor3ub(180,180,180);
		glPushMatrix();
	glTranslatef(50+x0,700-y0,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(85+x0,720-y0,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(130+x0,720-y0,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(85+x0,680-y0,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(130+x0,680-y0,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(160+x0,700-y0,0);
	glutSolidSphere(40,30,30);
	glPopMatrix();
	x0=x0+190;
	}
	}
}
void rain()
{
 	int i;
    float xpos;
	for(i=0;i<1000;i++)
	{
	rainx[i]=rand()%1350;
	rainy[i]=rand()%700;
	}


	glBegin(GL_LINES);
	glColor3ub(128,255,255);
	for(i=0;i<100;i++)
	{
		xpos=rainx[i];
		glVertex2f(rainx[i],rainy[i]);
		glVertex2f(rainx[i],rainy[i]+10);
   }
	glEnd();
	for(i=0;i<100000000;i++);

}
 void background_mountains()
{
		//background_mountains
	glColor3ub(97,97,97);
	glBegin(GL_POLYGON);
	glVertex2i(40,500);
	glVertex2i(160,500);
	glVertex2i(100,650);
	glEnd();



	glColor3ub(97,97,97);
	glBegin(GL_POLYGON);
	glVertex2i(180,500);
	glVertex2i(280,500);
	glVertex2i(230,650);
	glEnd();

	glColor3ub(97,97,97);
	glBegin(GL_POLYGON);
	glVertex2i(280,500);
	glVertex2i(380,500);
	glVertex2i(330,600);
	glEnd();

	glColor3ub(97,97,97);
	glBegin(GL_POLYGON);
	glVertex2i(380,500);
	glVertex2i(400,500);
	glVertex2i(390,600);
	glEnd();


	glColor3ub(139, 76,57);
	glBegin(GL_POLYGON);
	glVertex2i(-10,500);
	glVertex2i(90,500);
	glVertex2i(40,600);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(110,500);
	glVertex2i(210,500);
	glVertex2i(160,590);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(200,500);
	glVertex2i(300,500);
	glVertex2i(250,560);
	glEnd();
}
void volcano_bg()
{

	glPushMatrix();
	glColor3ub(98,91,85);
	glTranslatef(0-60,0+30,0);
	glBegin(GL_POLYGON);
	glVertex2i(1050,100);
	glVertex2i(1250,100);
	glVertex2i(1160,250);
	glVertex2i(1120,250);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(1160,250);
	glVertex2i(1120,250);
	glColor3ub(153,67,38);
	glVertex2i(1140,280);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glColor3ub(100,91,85);
	glTranslatef(00,0+80,0);
	glBegin(GL_POLYGON);
	glVertex2i(1050,100);
	glVertex2i(1250,100);
	glVertex2i(1160,250);
	glVertex2i(1120,250);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(1160,250);
	glVertex2i(1120,250);
	glColor3ub(153,67,38);
	glVertex2i(1140,280);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glColor3ub(98,91,85);
	glTranslatef(0+60,0+30,0);
	glBegin(GL_POLYGON);
	glVertex2i(1050,100);
	glVertex2i(1250,100);
	glVertex2i(1160,250);
	glVertex2i(1120,250);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(1160,250);
	glVertex2i(1120,250);
	glColor3ub(153,67,38);
	glVertex2i(1140,280);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3ub(87,53,45);
	glTranslatef(0+110,0+25,0);
	glBegin(GL_POLYGON);
	glVertex2i(1050,100);
	glVertex2i(1250,100);
	glVertex2i(1160,250);
	glVertex2i(1120,250);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(1160,250);
	glVertex2i(1120,250);
	glColor3ub(153,67,38);
	glVertex2i(1140,280);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3ub(138,88,62);
	glTranslatef(0+150,0+15,0);
	glBegin(GL_POLYGON);
	glVertex2i(1050,100);
	glVertex2i(1250,100);
	glVertex2i(1160,250);
	glVertex2i(1120,250);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(1160,250);
	glVertex2i(1120,250);
	glColor3ub(153,67,38);
	glVertex2i(1140,280);
	glEnd();
	glPopMatrix();
}
void volcano()
{
	//mountain
	//glColor3ub(139,115,85);
	glColor3ub(136,128,119);
	glBegin(GL_POLYGON);
	glVertex2i(1050,100);
	glVertex2i(1250,100);
	glVertex2i(1160,250);
	glVertex2i(1120,250);
	glEnd();
}
void vlocano_break1()
{

	glPushMatrix();
	glBegin(GL_POLYGON);
	//glColor3ub(242,219,45);
	glVertex2i(1160,250);
	glVertex2i(1120,250);
	glColor3ub(153,67,38);
	glVertex2i(1140,280);
	glEnd();
	glPopMatrix();

}
void volcano_break2()
{

	glPushMatrix();
	glBegin(GL_POLYGON);
	glVertex2i(1160,250);
	glVertex2i(1120,250);
	glColor3ub(153,67,38);
	glVertex2i(1140,280);
	glEnd();
	//crack in the volcano
	glBegin(GL_LINES);
	glColor3f(1,1,0);
	glVertex2i(1140,280);
	glVertex2i(1135,250);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1,1,0);
	glVertex2i(1135,250);
	glVertex2i(1145,240);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1,1,0);
	glVertex2i(1145,240);
	glVertex2i(1135,220);
	glEnd();
	glPopMatrix();
}
void volcano_break3()
{
	if(flagvb2==0)
	{
	glPushMatrix();
	glTranslatef(0-xvb,0-xvb,0);
	glBegin(GL_POLYGON);
	glVertex2i(1120,250);
	glVertex2i(1100,290);
	glColor3ub(153,67,38);
	glVertex2i(1050,250);
	glEnd();
	glPopMatrix();
	}
	if(flagvb2==1)
	{
	glPushMatrix();
	glTranslatef(-150,-150,0);
	glBegin(GL_POLYGON);
	//glColor3ub(242,219,45);
	glVertex2i(1120,250);
	glVertex2i(1100,290);
	glColor3ub(153,67,38);
	glVertex2i(1050,250);
	glEnd();
	glPopMatrix();
	}
}
void volcano_break4()
{
	glColor3ub(136,128,119);
	glBegin(GL_POLYGON);
	glVertex2i(1050,100);
	glVertex2i(1250,100);
	glColor3ub(182,13,14);
	glVertex2i(1160,250);
	glVertex2i(1120,250);
	glEnd();
}
void volcanic_cloud()
{
	int rad;
	if(sflag==1)
	rad=10;
	if(sflag==0)
	rad=0;
	glColor3ub(119,136,153);
	glPushMatrix();
	glTranslatef(1150,290,0);
	glutSolidSphere(40-rad,30,30);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1137,290,0);
	glutSolidSphere(40-rad,30,30);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1137,290,0);
	glutSolidSphere(40-rad,30,30);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1160,300,0);
	glutSolidSphere(40-rad,30,30);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1135,330,0);
	glutSolidSphere(50-rad,30,30);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1157,340,0);
	glutSolidSphere(50-rad,30,30);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1130,374,0);
	glutSolidSphere(58-rad,30,30);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1160,387,0);
	glutSolidSphere(58-rad,30,30);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1123,420,0);
	glutSolidSphere(55-rad,30,30);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1168,427,0);
	glutSolidSphere(55-rad,30,30);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1120,440,0);
	glutSolidSphere(65-rad,30,30);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1173,478,0);
	glutSolidSphere(65-rad,30,30);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1110,495,0);
	glutSolidSphere(67-rad,30,30);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1185,525,0);
	glutSolidSphere(65-rad,30,30);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1095,540,0);
	glutSolidSphere(65-rad,30,30);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1196,565,0);
	glutSolidSphere(65-rad,30,30);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1150,570,0);
	glutSolidSphere(65-rad,30,30);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1095,571,0);
	glutSolidSphere(65-rad,30,30);
	glPopMatrix();

}
void water_filling()
{
	float radius=0.0,xc=0.1,yc=0.2,theta;
	if(wflag==0)
	{
	radius=radius+xw;
	glColor3ub(0,128,255);
	glBegin(GL_POLYGON);
	for(theta=0;theta<360;theta++)
	{

		glVertex2f(xc+(radius*cos(theta)),yc+(radius*sin(theta)));
	}
	glEnd();
	}
	else if(wflag==1)
	{
	radius=250;
	glColor3ub(0,128,255);
	glBegin(GL_POLYGON);
	for(theta=0;theta<360;theta++)
	{

		glVertex2f(xc+(radius*cos(theta)),yc+(radius*sin(theta)));
	}
	glEnd();
	}
}

void change_bgcolor()
{
	glPopMatrix();
	glColor3ub(174,215,255);
	glBegin(GL_POLYGON);
	glVertex2f(0,500);
	glVertex2f(0,768);
	glColor3ub(231,245,250);
	glVertex2f(1350,768);
	glVertex2f(1350,500);
	glEnd();
	//sun

	glPushMatrix();
	glColor3ub(255,255,128);
	glTranslatef(1200,700,0);
	glutSolidSphere(50,30,30);
	glPopMatrix();

}
//dialouge box
void an_asteroid()
{
	glPushMatrix();
	glScalef(3.5,3.5,3.5);
	glTranslatef(0,50,0);
	glBegin(GL_POLYGON);
	glColor3f(0.717,0.517,0.321);
	glVertex3f(40,50,0);
	glVertex3f(70,54,0);
	glVertex3f(73,58,0);
	glVertex3f(52,85,0);
	glVertex3f(41,75,0);
	glVertex3f(38,72,0);
	glVertex3f(30,68,0);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(35,305,0);
	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex2f(100,100);
	glVertex2f(100,110);
	glVertex2f(110,110);
	glVertex2f(110,100);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(105,315,0);
	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex2f(100,100);
	glVertex2f(100,110);
	glVertex2f(110,110);
	glVertex2f(110,100);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0,0,0);
	glTranslatef(179,380,0);
	glutSolidSphere(10,30,30);
	glPopMatrix();

	//dialoug box
	glColor3ub(222,222,222);
	glPushMatrix();
	//glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	glVertex2f(300,400);
	glVertex2f(300,600);
	glVertex2f(630,600);
	glVertex2f(630,400);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(300,400);
	glVertex2f(280,400);
	glVertex2f(300,420);
	glEnd();
	glPopMatrix();
}
void an_asteroid1()
{
			glPushMatrix();
	glTranslatef(300,-200,0);
		glPushMatrix();
	glScalef(3.5,3.5,3.5);
	glTranslatef(0,50,0);
	glBegin(GL_POLYGON);
	glColor3f(0.717,0.517,0.321);
	glVertex3f(40,50,0);
	glVertex3f(70,54,0);
	glVertex3f(73,58,0);
	glVertex3f(52,85,0);
	glVertex3f(41,75,0);
	glVertex3f(38,72,0);
	glVertex3f(30,68,0);
	glEnd();
		glPopMatrix();
		glPushMatrix();
	glTranslatef(35,305,0);
	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex2f(100,100);
	glVertex2f(100,110);
	glVertex2f(110,110);
	glVertex2f(110,100);
	glEnd();
		glPopMatrix();
		glPushMatrix();
	glTranslatef(105,315,0);
	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex2f(100,100);
	glVertex2f(100,110);
	glVertex2f(110,110);
	glVertex2f(110,100);
	glEnd();
		glPopMatrix();


		glPushMatrix();
	glColor3f(0.0,0,0);
	glTranslatef(179,380,0);
	glutSolidSphere(10,30,30);
		glPopMatrix();
				glPopMatrix();
	//dialoug box
	glColor3ub(222,222,222);
		glPushMatrix();
	glTranslatef(300,-200,0);
	//glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	glVertex2f(300,400);
	glVertex2f(300,600);
	glVertex2f(600,600);
	glVertex2f(600,400);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(300,400);
	glVertex2f(280,400);
	glVertex2f(300,420);
	glEnd();
		glPopMatrix();

}

void an_asteroid2()
{	glPushMatrix();
	glTranslatef(300,-200,0);
	glPushMatrix();
	glScalef(3.5,3.5,3.5);
	glTranslatef(0,50,0);
	glBegin(GL_POLYGON);
	glColor3f(0.717,0.517,0.321);
	glVertex3f(40,50,0);
	glVertex3f(70,54,0);
	glVertex3f(73,58,0);
	glVertex3f(52,85,0);
	glVertex3f(41,75,0);
	glVertex3f(38,72,0);
	glVertex3f(30,68,0);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(35,305,0);
	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex2f(100,100);
	glVertex2f(100,110);
	glVertex2f(110,110);
	glVertex2f(110,100);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(105,315,0);
	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex2f(100,100);
	glVertex2f(100,110);
	glVertex2f(110,110);
	glVertex2f(110,100);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0,0,0);
	glTranslatef(179,380,0);
	glutSolidSphere(10,30,30);
	glPopMatrix();

	//dialoug box
	glColor3ub(222,222,222);
	glPushMatrix();
	//glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	glVertex2f(300,400);
	glVertex2f(300,600);
	glVertex2f(600,600);
	glVertex2f(600,400);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(300,400);
	glVertex2f(280,400);
	glVertex2f(300,420);
	glEnd();
	glPopMatrix();
	glPopMatrix();
}
//text
void s1text1()
{	int post=20;//change the y value
		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,588-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("Hey There!!!");
        glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,570-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("I'm an Asteroid...");
        glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,553-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("There are millions of me out there ");
		glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,534-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("in the solar system...");
        glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,515-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("We collide with each other to form");
        glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,496-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("bigger and better asteroids...");
        glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,477-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("This chain of collision leads to the");
        glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,458-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("formation of PLANETS or other ");
        glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,439-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("celestial object...");
        glPopMatrix();
}
void s1text2()
{	int post=30;//change the y value

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,586-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("The celestial body, at the right");
        glPopMatrix();
        glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,567-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("Is the SUN...");
        glPopMatrix();

        glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,548-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("The CENTRAL STAR or");
        glPopMatrix();

        glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,529-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("the Centre of our SOLAR SYSTEM...");
        glPopMatrix();
        glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,510-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("Every Celestial obect in our solar");
        glPopMatrix();

        glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,491-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("system revolve around the sun");
        glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,472-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("because of its huge mass and its");
        glPopMatrix();

        glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,453-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("gravitational pull...");
        glPopMatrix();
}
void s1text3()
{	int post=30;//change the y value
		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,586-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("Your Home planet-PLANET EARTH");
        glPopMatrix();

        glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,567-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("came into existence because of us...");
        glPopMatrix();

        glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,548-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("We collided with each other to form");
        glPopMatrix();

         glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,529-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("a bigger asteroid...");
        glPopMatrix();

         glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,510-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("We did this for millions of years");
        glPopMatrix();

         glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,491-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("until an asteroid large enough was");
        glPopMatrix();

         glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,472-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("formed..");
        glPopMatrix();

         glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,453-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("Lets see How..");
        glPopMatrix();
}
 void s2text3()
 {
 	int post=40;//change the y value

		glPushMatrix();
    	glColor3f(0,0,0);
	    glTranslatef(255,550,0.0);
    	glScalef(0.12,0.12,0.12);
        print("I am Sick!!");
        glPopMatrix();
 }
 void s2text1()
{	int post=40;//change the y value

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(605,388-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("This is EARTH million years after");
        glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(605,369-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("But the asteroids did'nt stop");
        glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(605,350-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("colliding the newly formed earth...");
		glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(605,331-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("It grew bigger in size..");
        glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(605,312-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("Lets see how it happened!");
        glPopMatrix();

		glPushMatrix();
    	glColor3ub(65,202,182);
	    glTranslatef(150,550,0.0);
    	glScalef(0.15,0.15,0.15);
        print("EARTH million years after!!!");
        glPopMatrix();



}
void s2text2()
{	int post=30;//change the y value

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(605,388-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("This is Earth...");
        glPopMatrix();

        glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(605,372-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("It grew to a size that we know");
        glPopMatrix();

        glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(605,353-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("today...");
        glPopMatrix();
        glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(605,334-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("But its temperature was soaring");
        glPopMatrix();

        glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(605,315-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("high...");
        glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(605,296-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("It started to cool while revolving");
        glPopMatrix();

        glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(605,277-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("around the SUN...");
        glPopMatrix();
}

void s3text1()
{	int post=10;//change the y value
		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,588-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("Hey There!!!");
        glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,570-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("I'm Back...");
        glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,553-post,0.0);
	    glScalef(0.12,0.12,0.12);
	    print("It's soo HOT In here");
    	glScalef(0.12,0.12,0.12);

		glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,534-post,0.0);
    	glScalef(0.12,0.12,0.12);
    	print("Earth in its early stages had very");

        glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,515-post,0.0);
    	glScalef(0.12,0.12,0.12);
    	print("active volcanos..");

        glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,496-post,0.0);
    	glScalef(0.12,0.12,0.12);
    	print("They played a major role in the ");

        glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,477-post,0.0);
    	glScalef(0.12,0.12,0.12);
    	print("formation of the atmosphere...");

        glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,458-post,0.0);
    	glScalef(0.12,0.12,0.12);
    	print("Poisonous gases from erruption ");

        glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,439-post,0.0);
    	glScalef(0.12,0.12,0.12);
    	print("formed the initial atmospheric layer");

        glPopMatrix();
        glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,439-post-19,0.0);
    	glScalef(0.12,0.12,0.12);

        print("of Earth");
        glPopMatrix();
}

void s3text2()
{	int post=60;//change the y value
		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,588-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("The gases like Hydrogen,Helium");
        glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,570-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("and others helped in the ");
        glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,553-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("formation of clouds!!!");
		glPopMatrix();

			glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,534-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("I just hope the chemical reactions ");
        glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,515-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("go right and it rains.. ");
        glPopMatrix();

}

void s3text3()
{	int post=30;//change the y value
		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,588-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("Look! Its raining!!");
        glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,570-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("The reactions went right");
        glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,553-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("Thanks to the clouds...");
        glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,534-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("Finally the earth can become cool,");
		glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,515-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("and the temperature can come down.");
        glPopMatrix();

        glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,496-post,0.0);
    	glScalef(0.12,0.12,0.12);
    	print("Oh Look there's water getting collected ");

        glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,477-post,0.0);
    	glScalef(0.12,0.12,0.12);
    	print("Finally i can arrange a Pool party!!!");

        glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,458-post,0.0);
    	glScalef(0.12,0.12,0.12);
    	print("YAY!!! ");

        glPopMatrix();



}

void s3text4()
{	int post=50;//change the y value
		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,588-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("Oh!Look the stars are gone");
        glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,570-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("and why has the color changed to blue?");
        glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,553-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("OH! It must be because of water..");
        glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,534-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("Lets call it as SKY!");
		glPopMatrix();



}

void s3text5()
{	int post=50;//change the y value
		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,588-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("Now there is water and ");
        glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,570-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("enough oxygen for life to survive");
        glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,553-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("on earth!");
        glPopMatrix();

		glPushMatrix();
    	glColor3f(1,0,0);
	    glTranslatef(305,534-post,0.0);
    	glScalef(0.12,0.12,0.12);
        print("Let there be plants");
		glPopMatrix();



}

void background1()
{
	//stars
	if(tflag==0)
	glColor3f(1.0,1.0,1.0);
	if(tflag==1)
	glColor3f(1.0,1.0,0.0);
	if(tflag==10)
	glColor3f(1,0,0);
	glBegin( GL_POINTS );

	for (i = 0; i < NumberOfPoints; i ++)
	{
    	glVertex3f( a[i], b[i],0 );

	}
	glEnd();
	//sun
	glPushMatrix();
	glColor3ub(255,132,9);
	glTranslatef(1050,460,10);
	glutSolidSphere(100,30,30);
	glPopMatrix();
}

void background2()
{
	//stars
	glBegin( GL_POINTS );
	if(tflag==0)
	glColor3f(1.0,1.0,1.0);
	if(tflag==1)
	glColor3f(1.0,1.0,0.0);
	if(tflag==10)
	glColor3f(1,0,0);
	for (i = 0; i < NumberOfPoints; i ++)
	{
	    	glVertex3f( a[i], b[i],0 );

	}
	glEnd();
	//sun
	int theta;
	int radius=130,xc2=1150,yc2=470;
	glColor3ub(255,132,9);
	glBegin(GL_POLYGON);
	for(theta=0;theta<360;theta++)
	{

		glVertex2f(xc2+(radius*cos(theta)),yc2+(radius*sin(theta)));
	}
	glEnd();


}
void background3()
{
	//background with stars
	glBegin(GL_POINTS );
	if(tflag==0)
	glColor3f(1.0,1.0,1.0);
	if(tflag==1)
	glColor3f(1.0,1.0,0.0);
	if(tflag==10)
	glColor3f(1,0,0);
	for (i = 0; i < NumberOfPoints; i ++)
	{
    	glVertex3f( a[i], b[i],0 );

	}
	glEnd();
	//ground
/*	glColor3f(0.85490196,0.64705882,0.1254902);
	glBegin(GL_POLYGON);
	glVertex2i(0,0);
	glVertex2i(0,500);
	glVertex2i(1350,500);
	glVertex2i(1350,0);
	glEnd();
	*/

	glColor3ub(116,71,48);
	glBegin(GL_POLYGON);
	glVertex2i(0,0);
	glVertex2i(0,500);
	glVertex2i(1350,500);
	glVertex2i(1350,0);
	glEnd();


	//sun
	glColor3f(1,0.6470588235,0);
	glPushMatrix();
	glTranslatef(510,710,0);
	glutSolidSphere(50,30,30);
	glPopMatrix();
	int wt=0,wr=280;
	for(wt=0;wt<=9;wt++)
	{
		wr=wr-20;
	glPushMatrix();
	glColor3ub(64,0,0);
	glTranslatef(0,0,0);
	glutSolidSphere(wr,30,30);
	glPopMatrix();
	}
}

void background4()
{
	//background with stars
	glBegin(GL_POINTS );
	if(tflag==0)
	glColor3f(1.0,1.0,1.0);
	if(tflag==1)
	glColor3f(1.0,1.0,0.0);
	if(tflag==10)
	glColor3f(1,0,0);
	for (i = 0; i < NumberOfPoints; i ++)
	{
    	glVertex3f( a[i], b[i],0 );

	}
	glEnd();
	//ground
/*	glColor3f(0.85490196,0.64705882,0.1254902);
	glBegin(GL_POLYGON);
	glVertex2i(0,0);
	glVertex2i(0,500);
	glVertex2i(1350,500);
	glVertex2i(1350,0);
	glEnd();
	*/

	glColor3ub(0,213,53);
	glBegin(GL_POLYGON);
	glVertex2i(0,0);
	glColor3ub(0,149,37);
	glVertex2i(0,500);
	glVertex2i(1350,500);
	glColor3ub(0,149,37);
	glVertex2i(1350,0);
	glEnd();


	//sun
	glColor3f(1,0.6470588235,0);
	glPushMatrix();
	glTranslatef(510,710,0);
	glutSolidSphere(50,30,30);
	glPopMatrix();
	int wt=0,wr=280;
	for(wt=0;wt<=9;wt++)
	{
		wr=wr-20;
	glPushMatrix();
	glColor3ub(64,0,0);
	glTranslatef(0,0,0);
	glutSolidSphere(wr,30,30);
	glPopMatrix();
	}
}
void asteroids1()
{
	//asteroids
glColor3ub(106,53,0);
if(a1flag1==0){
	glPushMatrix();
	glTranslatef(0+a1x,250+a1x,0);
	glBegin(GL_POLYGON);
//	glColor3f(0.717,0.517,0.321);
	glVertex3f(20,30,0);
	glVertex3f(25,62,0);
	glVertex3f(30,70,0);
	glVertex3f(50,60,0);
	glVertex3f(50,30,0);
	glVertex3f(28,20,0);
	glEnd();
	glPopMatrix();
}

else{
	glPushMatrix();
	glTranslatef(0+120,250+120,0);
	glBegin(GL_POLYGON);
//	glColor3f(0.717,0.517,0.321);
	glVertex3f(20,30,0);
	glVertex3f(25,62,0);
	glVertex3f(30,70,0);
	glVertex3f(50,60,0);
	glVertex3f(50,30,0);
	glVertex3f(28,20,0);
	glEnd();
	glPopMatrix();

}

if(a1flag2==0){
	glPushMatrix();
	glTranslatef(120,525-a1x,0);
	glBegin(GL_POLYGON);
//	glColor3f(0.717,0.517,0.321);
	glVertex3f(20,30,0);
	glVertex3f(50,34,0);
	glVertex3f(53,38,0);
	glVertex3f(32,65,0);
	glVertex3f(21,55,0);
	glVertex3f(18,52,0);
	glVertex3f(10,48,0);
	glEnd();
	glPopMatrix();
}
else{
	glPushMatrix();
	glTranslatef(120,530-150,0);
	glBegin(GL_POLYGON);
//	glColor3f(0.717,0.517,0.321);
	glVertex3f(20,10,0);
	glVertex3f(13,46,0);
	glVertex3f(46,70,0);
	glVertex3f(65,50,0);
	glVertex3f(65,14,0);
	glEnd();
	glPopMatrix();

}



if(a1flag3==0){
	glPushMatrix();
	glTranslatef(-120+a1x,381,0);
	glBegin(GL_POLYGON);
//	glColor3f(0.717,0.517,0.321);
	glVertex3f(20,30,0);
	glVertex3f(25,62,0);
	glVertex3f(50,60,0);
	glVertex3f(60,30,0);
	glVertex3f(55,20,0);
	glEnd();
	glPopMatrix();
}

else{
	glPushMatrix();
	glTranslatef(100,381,0);
	glBegin(GL_POLYGON);
//	glColor3f(0.717,0.517,0.321);
	glVertex3f(20,30,0);
	glVertex3f(25,62,0);
	glVertex3f(50,60,0);
	glVertex3f(60,30,0);
	glVertex3f(55,20,0);
	glEnd();
	glPopMatrix();
}
if(a1flag4==0){
	glPushMatrix();
	glTranslatef(541-a1x,381,0);
	glBegin(GL_POLYGON);
//	glColor3f(0.717,0.517,0.321);
	glVertex3f(20,30,0);
	glVertex3f(25,62,0);
	glVertex3f(50,60,0);
	glVertex3f(50,30,0);
	glVertex3f(28,20,0);
	glEnd();
	glPopMatrix();
}
else{
	glPushMatrix();
	glTranslatef(127,385,10);
	glBegin(GL_POLYGON);
//	glColor3f(0.717,0.517,0.321);
	glVertex3f(20,30,0);
	glVertex3f(4,23,0);
	glVertex3f(7,78,0);
	glVertex3f(43,69,0);
	glVertex3f(72,48,0);
	glVertex3f(60,18,0);
	glVertex3f(30,8,0);
	glEnd();
	glPopMatrix();
}

	//extra asteroids
	glPushMatrix();
	glTranslatef(1270-ax3,768-ax3,0);
	glBegin(GL_POLYGON);
	glColor3f(0.717,0.517,0.321);
	glVertex3f(20,30,0);
	glVertex3f(4,23,0);
	glVertex3f(7,78,0);
	glVertex3f(43,69,0);
	glVertex3f(72,48,0);
	glVertex3f(60,18,0);
	glVertex3f(30,8,0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0+ax3,671,0);
	glBegin(GL_POLYGON);
	glColor3f(0.717,0.517,0.321);
	glVertex3f(20,30,0);
	glVertex3f(25,62,0);
	glVertex3f(50,60,0);
	glVertex3f(60,30,0);
	glVertex3f(55,20,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(500+ax3,768-ax3,0);
	glBegin(GL_POLYGON);
	glColor3f(0.717,0.517,0.321);
	glVertex3f(20,10,0);
	glVertex3f(13,46,0);
	glVertex3f(46,70,0);
	glVertex3f(65,50,0);
	glVertex3f(65,14,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glScalef(1.5,1.5,1.5);
	glTranslatef(500-ax3,350+ax3,0);
	glBegin(GL_POLYGON);
	glColor3f(0.717,0.517,0.321);
	glVertex3f(25,25,0);
	glVertex3f(45,40,0);
	glVertex3f(35,52,0);
	glVertex3f(20,50,0);
	glVertex3f(15,30,0);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glScalef(3.5,3.5,3.5);
	glTranslatef(500+ax3,350-ax3,0);
	glBegin(GL_POLYGON);
	glColor3f(0.717,0.517,0.321);
	glVertex3f(25,25,0);
	glVertex3f(45,40,0);
	glVertex3f(35,52,0);
	glVertex3f(20,50,0);
	glVertex3f(15,30,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glScalef(4.0,4.0,4.0);
	glTranslatef(800+ax3,768+ax3,0);
	glBegin(GL_POLYGON);
	glColor3f(0.717,0.517,0.321);
	glVertex3f(20,10,0);
	glVertex3f(13,46,0);
	glVertex3f(46,70,0);
	glVertex3f(65,50,0);
	glVertex3f(65,14,0);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glScalef(1.5,1.5,1.5);
	glTranslatef(100,381-ax3,0);
	glBegin(GL_POLYGON);
	glColor3f(0.717,0.517,0.321);
	glVertex3f(20,30,0);
	glVertex3f(25,62,0);
	glVertex3f(50,60,0);
	glVertex3f(60,30,0);
	glVertex3f(55,20,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glScalef(1.5,1.5,1.5);
	glTranslatef(100-ax3,381-ax3,0);
	glBegin(GL_POLYGON);
	glColor3f(0.717,0.517,0.321);
	glVertex3f(25,10,0);
	glVertex3f(30,30,0);
	glVertex3f(40,20,0);
	glVertex3f(45,30,0);
	glVertex3f(40,40,0);
	glVertex3f(45,50,0);
	glVertex3f(30,50,0);
	glVertex3f(10,40,0);
	glVertex3f(25,30,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glScalef(2.5,2.5,2.5);
	glTranslatef(1050+ax3,150+ax3,0);
	glBegin(GL_POLYGON);
	glColor3f(0.717,0.517,0.321);
	glVertex3f(25,10,0);
	glVertex3f(30,30,0);
	glVertex3f(40,20,0);
	glVertex3f(45,30,0);
	glVertex3f(40,40,0);
	glVertex3f(45,50,0);
	glVertex3f(30,50,0);
	glVertex3f(10,40,0);
	glVertex3f(25,30,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glScalef(3,3,3);
	glTranslatef(700,350-ax3,0);
	glBegin(GL_POLYGON);
	glColor3f(0.717,0.517,0.321);
	glVertex3f(25,10,0);
	glVertex3f(30,30,0);
	glVertex3f(40,20,0);
	glVertex3f(45,30,0);
	glVertex3f(40,40,0);
	glVertex3f(45,50,0);
	glVertex3f(30,50,0);
	glVertex3f(10,40,0);
	glVertex3f(25,30,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glScalef(2.0,2.0,2.0);
	glTranslatef(500+ax3,250-ax3,0);
	glBegin(GL_POLYGON);
	glColor3f(0.717,0.517,0.321);
	glVertex3f(20,30,0);
	glVertex3f(25,62,0);
	glVertex3f(30,70,0);
	glVertex3f(50,60,0);
	glVertex3f(50,30,0);
	glVertex3f(28,20,0);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glScalef(2.5,2.5,2.5);
	glTranslatef(200+ax3,250+ax3,0);
	glBegin(GL_POLYGON);
	glColor3f(0.717,0.517,0.321);
	glVertex3f(20,30,0);
	glVertex3f(25,62,0);
	glVertex3f(30,70,0);
	glVertex3f(50,60,0);
	glVertex3f(50,30,0);
	glVertex3f(28,20,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.5,0.5,0.5);
	glTranslatef(500+ax3,381-ax3,0);
	glBegin(GL_POLYGON);
	glColor3f(0.717,0.517,0.321);
	glVertex3f(25,10,0);
	glVertex3f(30,30,0);
	glVertex3f(40,20,0);
	glVertex3f(45,30,0);
	glVertex3f(40,40,0);
	glVertex3f(45,50,0);
	glVertex3f(30,50,0);
	glVertex3f(10,40,0);
	glVertex3f(25,30,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.5,0.5,0.5);
	glTranslatef(1300-ax3,181+ax3,0);
	glBegin(GL_POLYGON);
	glColor3f(0.717,0.517,0.321);
	glVertex3f(25,10,0);
	glVertex3f(30,30,0);
	glVertex3f(40,20,0);
	glVertex3f(45,30,0);
	glVertex3f(40,40,0);
	glVertex3f(45,50,0);
	glVertex3f(30,50,0);
	glVertex3f(10,40,0);
	glVertex3f(25,30,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glScalef(1,1,1);
	glTranslatef(700,0+ax3,0);
	glBegin(GL_POLYGON);
	glColor3f(0.717,0.517,0.321);
	glVertex3f(25,10,0);
	glVertex3f(30,30,0);
	glVertex3f(40,20,0);
	glVertex3f(45,30,0);
	glVertex3f(40,40,0);
	glVertex3f(45,50,0);
	glVertex3f(30,50,0);
	glVertex3f(10,40,0);
	glVertex3f(25,30,0);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glScalef(0.8,0.8,0.8);
	glTranslatef(0+ax3,80+ax3,0);
	glBegin(GL_POLYGON);
	glColor3f(0.717,0.517,0.321);
	glVertex3f(20,30,0);
	glVertex3f(25,62,0);
	glVertex3f(50,60,0);
	glVertex3f(60,30,0);
	glVertex3f(55,20,0);
	glEnd();
	glPopMatrix();


}

void asteroids2()
{
//asteroids
glColor3ub(106,53,0);
if(a2flag1==0){
	glPushMatrix();
	glTranslatef(0+ax2,250+ax2,0);
	glBegin(GL_POLYGON);
	glVertex3f(20,30,0);
	glVertex3f(25,62,0);
	glVertex3f(30,70,0);
	glVertex3f(50,60,0);
	glVertex3f(50,30,0);
	glVertex3f(28,20,0);
	glEnd();
	glPopMatrix();
}
if(a2flag2==0){
	glPushMatrix();
	glTranslatef(120,525-ax2,0);
	glBegin(GL_POLYGON);
	glVertex3f(20,30,0);
	glVertex3f(50,34,0);
	glVertex3f(53,38,0);
	glVertex3f(32,65,0);
	glVertex3f(21,55,0);
	glVertex3f(18,52,0);
	glVertex3f(10,48,0);
	glEnd();
	glPopMatrix();
}
if(a2flag3==0){
	glPushMatrix();
	glTranslatef(-120+ax2,381,0);
	glBegin(GL_POLYGON);
	glVertex3f(20,30,0);
	glVertex3f(25,62,0);
	glVertex3f(50,60,0);
	glVertex3f(60,30,0);
	glVertex3f(55,20,0);
	glEnd();
	glPopMatrix();
}
if(a2flag4==0){
	glPushMatrix();
	glTranslatef(541-ax2,381,0);
	glBegin(GL_POLYGON);
	glVertex3f(20,30,0);
	glVertex3f(25,62,0);
	glVertex3f(50,60,0);
	glVertex3f(50,30,0);
	glVertex3f(28,20,0);
	glEnd();
	glPopMatrix();
}
	glPushMatrix();
	glTranslatef(500-ax2,250-ax2,50);
	glBegin(GL_POLYGON);
	glVertex3f(20,30,0);
	glVertex3f(25,62,0);
	glVertex3f(50,60,0);
	glVertex3f(50,30,0);
	glVertex3f(28,20,0);
	glEnd();
	glPopMatrix();
	//extras
	//extra asteroids
	glPushMatrix();
	glTranslatef(1270-ax4,768-ax4,0);
	glBegin(GL_POLYGON);
	glColor3f(0.717,0.517,0.321);
	glVertex3f(20,30,0);
	glVertex3f(4,23,0);
	glVertex3f(7,78,0);
	glVertex3f(43,69,0);
	glVertex3f(72,48,0);
	glVertex3f(60,18,0);
	glVertex3f(30,8,0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0+ax4,671,0);
	glBegin(GL_POLYGON);
	glColor3f(0.717,0.517,0.321);
	glVertex3f(20,30,0);
	glVertex3f(25,62,0);
	glVertex3f(50,60,0);
	glVertex3f(60,30,0);
	glVertex3f(55,20,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(500+ax4,768-ax4,0);
	glBegin(GL_POLYGON);
	glColor3f(0.717,0.517,0.321);
	glVertex3f(20,10,0);
	glVertex3f(13,46,0);
	glVertex3f(46,70,0);
	glVertex3f(65,50,0);
	glVertex3f(65,14,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glScalef(1.5,1.5,1.5);
	glTranslatef(500-ax4,350+ax4,0);
	glBegin(GL_POLYGON);
	glColor3f(0.717,0.517,0.321);
	glVertex3f(25,25,0);
	glVertex3f(45,40,0);
	glVertex3f(35,52,0);
	glVertex3f(20,50,0);
	glVertex3f(15,30,0);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glScalef(3.5,3.5,3.5);
	glTranslatef(500+ax4,350-ax4,0);
	glBegin(GL_POLYGON);
	glColor3f(0.717,0.517,0.321);
	glVertex3f(25,25,0);
	glVertex3f(45,40,0);
	glVertex3f(35,52,0);
	glVertex3f(20,50,0);
	glVertex3f(15,30,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glScalef(4.0,4.0,4.0);
	glTranslatef(800+ax4,768+ax4,0);
	glBegin(GL_POLYGON);
	glColor3f(0.717,0.517,0.321);
	glVertex3f(20,10,0);
	glVertex3f(13,46,0);
	glVertex3f(46,70,0);
	glVertex3f(65,50,0);
	glVertex3f(65,14,0);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glScalef(1.5,1.5,1.5);
	glTranslatef(100,381-ax4,0);
	glBegin(GL_POLYGON);
	glColor3f(0.717,0.517,0.321);
	glVertex3f(20,30,0);
	glVertex3f(25,62,0);
	glVertex3f(50,60,0);
	glVertex3f(60,30,0);
	glVertex3f(55,20,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glScalef(1.5,1.5,1.5);
	glTranslatef(100-ax4,381-ax4,0);
	glBegin(GL_POLYGON);
	glColor3f(0.717,0.517,0.321);
	glVertex3f(25,10,0);
	glVertex3f(30,30,0);
	glVertex3f(40,20,0);
	glVertex3f(45,30,0);
	glVertex3f(40,40,0);
	glVertex3f(45,50,0);
	glVertex3f(30,50,0);
	glVertex3f(10,40,0);
	glVertex3f(25,30,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glScalef(2.5,2.5,2.5);
	glTranslatef(1050+ax4,150+ax4,0);
	glBegin(GL_POLYGON);
	glColor3f(0.717,0.517,0.321);
	glVertex3f(25,10,0);
	glVertex3f(30,30,0);
	glVertex3f(40,20,0);
	glVertex3f(45,30,0);
	glVertex3f(40,40,0);
	glVertex3f(45,50,0);
	glVertex3f(30,50,0);
	glVertex3f(10,40,0);
	glVertex3f(25,30,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glScalef(3,3,3);
	glTranslatef(700,350-ax4,0);
	glBegin(GL_POLYGON);
	glColor3f(0.717,0.517,0.321);
	glVertex3f(25,10,0);
	glVertex3f(30,30,0);
	glVertex3f(40,20,0);
	glVertex3f(45,30,0);
	glVertex3f(40,40,0);
	glVertex3f(45,50,0);
	glVertex3f(30,50,0);
	glVertex3f(10,40,0);
	glVertex3f(25,30,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glScalef(2.0,2.0,2.0);
	glTranslatef(500+ax4,250-ax4,0);
	glBegin(GL_POLYGON);
	glColor3f(0.717,0.517,0.321);
	glVertex3f(20,30,0);
	glVertex3f(25,62,0);
	glVertex3f(30,70,0);
	glVertex3f(50,60,0);
	glVertex3f(50,30,0);
	glVertex3f(28,20,0);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glScalef(2.5,2.5,2.5);
	glTranslatef(200+ax4,250+ax4,0);
	glBegin(GL_POLYGON);
	glColor3f(0.717,0.517,0.321);
	glVertex3f(20,30,0);
	glVertex3f(25,62,0);
	glVertex3f(30,70,0);
	glVertex3f(50,60,0);
	glVertex3f(50,30,0);
	glVertex3f(28,20,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.5,0.5,0.5);
	glTranslatef(500+ax4,381-ax4,0);
	glBegin(GL_POLYGON);
	glColor3f(0.717,0.517,0.321);
	glVertex3f(25,10,0);
	glVertex3f(30,30,0);
	glVertex3f(40,20,0);
	glVertex3f(45,30,0);
	glVertex3f(40,40,0);
	glVertex3f(45,50,0);
	glVertex3f(30,50,0);
	glVertex3f(10,40,0);
	glVertex3f(25,30,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.5,0.5,0.5);
	glTranslatef(1300-ax4,181+ax4,0);
	glBegin(GL_POLYGON);
	glColor3f(0.717,0.517,0.321);
	glVertex3f(25,10,0);
	glVertex3f(30,30,0);
	glVertex3f(40,20,0);
	glVertex3f(45,30,0);
	glVertex3f(40,40,0);
	glVertex3f(45,50,0);
	glVertex3f(30,50,0);
	glVertex3f(10,40,0);
	glVertex3f(25,30,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glScalef(1,1,1);
	glTranslatef(700,0+ax4,0);
	glBegin(GL_POLYGON);
	glColor3f(0.717,0.517,0.321);
	glVertex3f(25,10,0);
	glVertex3f(30,30,0);
	glVertex3f(40,20,0);
	glVertex3f(45,30,0);
	glVertex3f(40,40,0);
	glVertex3f(45,50,0);
	glVertex3f(30,50,0);
	glVertex3f(10,40,0);
	glVertex3f(25,30,0);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glScalef(0.8,0.8,0.8);
	glTranslatef(0+ax4,80+ax4,0);
	glBegin(GL_POLYGON);
	glColor3f(0.717,0.517,0.321);
	glVertex3f(20,30,0);
	glVertex3f(25,62,0);
	glVertex3f(50,60,0);
	glVertex3f(60,30,0);
	glVertex3f(55,20,0);
	glEnd();
	glPopMatrix();


}
void earth()
{
	//earth
	glPushMatrix();
	glColor3ub(172+cr,86+cg,0);
	glTranslatef(160,430,10);
	glutSolidSphere(60+earth_exp,30,30);
	glPopMatrix();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	if(j==0)
	{
		glPushMatrix();
		intro();
		glPopMatrix();
	}

	if(j==1)
	{
	background1();
	an_asteroid();
	s1text1();
	interact();
	}
	if(j==2)
	{
	background1();
	an_asteroid();
	s1text2();
	}
	if(j==3)
	{
	background1();
	an_asteroid();
	s1text3();
	}
	if(j==4)
	{
	background1();
	asteroids1();
	timer_asteroids_extras1(0);//for extra asteroids
	timer_asteroids1(0);
	}
	if(j==5)
	{
	background2();
	an_asteroid1();
	s2text1();
	earth();
	}
	//earth();
	if(j==6)
	{
	background2();
	timer_asteroid2(0);
	timer_asteroids_extras2(0);//for extra asteroids
	asteroids2();
	earth();
	}
	if(j==7)
	{
		background2();
		an_asteroid1();
		s2text2();
		earth();
		thermometer();
		sick();
		s2text3();
	}
	if(j==8)
	{
		background3();
		background_mountains();
		timer_volcano_events(0);
		volcano_bg();
		volcano();
		if(flagvb1==0)
			vlocano_break1();
		if(flagvb1==1)
			 volcano_break2();
		if(flagvb1==2)
		{
			timer_volcano_break(0);
			volcano_break3();
		}
		if(flagvb1==3)
		{
		lava();
		volcano_break4();
		}
		an_asteroid();
		s3text1();
	}

	if(j==9)
	{
		background3();
		background_mountains();
		volcano_bg();
		volcano_break4();
		volcanic_cloud();
		an_asteroid();
		s3text1();
	}

	if(j==10)
	{
		background3();
		background_mountains();
		clouds1();
	 	clouds2();
	 	timer_cloud(0);
	 	volcano_bg();
	 	volcano_break4();
		timer_volc(0);
		volcanic_cloud();
		background_mountains();
		an_asteroid();
		s3text2();
	}
	if(j==11)
	{
		background3();
		clouds1();
	 	clouds2();
		rain();
		background_mountains();
		volcano_bg();
		volcano_break4();
		volcanic_cloud();
		water_filling();
		timer_water(0);
		an_asteroid();
		s3text3();

	}
	if(j==12)
	{
		background3();
		change_bgcolor();
		cloud3();
		volcano_bg();
		volcano();
		background_mountains();
		water_filling();
		an_asteroid();
		s3text4();
	}
	if(j==13)
	{
		background4();
		change_bgcolor();
		volcano_bg();
		volcano();
		cloud3();
		background_mountains();
		water_filling();
		an_asteroid();
		s3text5();
	}
	else
	if(j==14)
	{
		background4();
		change_bgcolor();
		cloud3();
		background_mountains();
		water_filling();
		volcano_bg();
		volcano();
		grass_display();
		tree();
	}
	if(j>=15)
	{
	glPushMatrix();
	glColor3ub(255,201,14);
	glScalef(0.4,0.4,0.4);
	glTranslatef(1050,1650,0);
	print("LAYERS OF EARTH");
	glPopMatrix();
	}
	//crust
	glPushMatrix();
	if(j>=19)
	{
	timer4(0);
		if(flag4==0)
		{
			glTranslatef(-800+xtimer4,0,0);
			crust();
		}
		else if(flag4==1)
		{
			glTranslatef(-20,0,0);
			crust();
		}
	}
	glPopMatrix();

	//mantle
	glPushMatrix();
	if(j>=18)
	{
	timer3(0);
	if(flag3==0)
	{
		glTranslatef(-800+xtimer3,0,0);
		mantle();
	}
	else if(flag3==1)
	{
		glTranslatef(-15,0,0);
		mantle();
	}
	}
	glPopMatrix();

	//outer core
	glPushMatrix();
	if(j>=17)
	{
	timer2(0);
	if(flag2==0)
	{
		glTranslatef(-800+xtimer2,0,0);
		outercore();
	}
	if(flag2==1)
	{
		glTranslatef(-10,0,0);
		outercore();
	}
	}
	glPopMatrix();

	//inner core
	glPushMatrix();
	if(j>=16)
	{
	timer1(0);
	if(flag1==0)
	{
		glTranslatef(550-xtimer1,0,0);
		innercore();
	}
	else
	{
		glTranslatef(-8,0,0);
		innercore();


	}
	}
	glPopMatrix();
	if(j>=20)
	temp_table();

	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();

}

void mykey(unsigned char key,int x,int y)
{
	if(key=='d'||key=='D')
	j=++j;
	if(key=='a'||key=='A')
	j=--j;
	if(key=='q'||key=='Q')
	exit(0);
}

void main(int argc,char **argv)
{
 		 glutInit(&argc,argv);
         glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
         glutInitWindowSize(1920,1080);
         glutCreateWindow("EARTH");
         glutInitWindowPosition(0,0);
         glPointSize(2.0);
	for(i=0;i<100;i++){
		//(rand()%(MAX-MIX))+MIN)
		x_grass[i]=(rand()%(1350-0))+0;
		y_grass[i]=(rand()%(450-250))+250;
	}
    for(i = 0; i < NumberOfPoints; i++)
	{
   	a[i]=rand()%1350;
    b[i]=rand()%768;
	}      glOrtho(0.0,1350.0,0.0,768.0,-100,100);
         glClearColor(0.0,0.0,0.0,0.0);
         glutDisplayFunc(display);
         glutKeyboardFunc(mykey);
         timer_twinkle(0);
         glutMainLoop();
}
