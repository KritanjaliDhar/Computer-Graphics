#include<windows.h>
#include<GL\glut.h>
#include <GL/glu.h>
#include<math.h>
#include <stdlib.h>
#include<stdio.h>
#define PI 3.1416

GLint i, trainST=0,bridgeST=0;
GLfloat sun_spin=0, sun_x=0, sun_y=0;
GLfloat ax=0,bx=0,cx=0,dx=0,str=500.0,mn=500.0;
GLfloat tr11=100,tr12=-200,tr22=0,trn=550;
GLfloat spin = 0.0;

void init(void)
{
	glClearColor(.20, .110, 0.65, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1000.0, 0.0, 500.0);
}

///*** Circle_Model***///
void circle(GLdouble rad)
{
    GLint points = 50;
    GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
    GLdouble theta = 0.0;

    glBegin(GL_POLYGON);
    {
        for( i = 0; i <=50; i++, theta += delTheta )
        {
            glVertex2f(rad * cos(theta),rad * sin(theta));
        }
    }
    glEnd();
}
/// *** Sun_Model **///
void Sun_Model(){
    glPushMatrix();
    glTranslatef(800,150,0);
    circle(30);
    glPopMatrix();

}
void Moving_Sun_Model(){
    glPushMatrix();
    glRotatef(-sun_spin, 0,0,-.009);
    Sun_Model();
    glPopMatrix();

}
///*** Cloud_Model***///
void cloud_model_one(){

    glColor3f(1.25, 0.924, 0.930);

    ///Top_Left

    glPushMatrix();
    glTranslatef(320,210,0);
    circle(15);
    glPopMatrix();

    ///Top

    glPushMatrix();
    glTranslatef(340, 225, 0);
    circle(16);
    glPopMatrix();

    ///Right

    glPushMatrix();
    glTranslatef(360,210,0);
    circle(16);
    glPopMatrix();


    ///middle_Fill
    glPushMatrix();
    glTranslatef(355,210,0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(350,210,0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(345,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(340,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(335,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(330,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(325,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(320,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(315,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(310,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(305,204,0);
    circle(10);
    glPopMatrix();

    ///****Fill End****

}

void cloud_model_Two(){
    glColor3f(1.25, 0.924, 0.930);

    ///Left_Part
    glPushMatrix();
    glTranslatef(305,205,0);
    circle(10);
    glPopMatrix();

    ///Top

    glPushMatrix();
    glTranslatef(320,210,0);
    circle(15);
    glPopMatrix();

    ///Right_Part
    glPushMatrix();
    glTranslatef(334,207,0);
    circle(10);
    glPopMatrix();

    ///Bottom_Part
    glPushMatrix();
    glTranslatef(320,207,0);
    circle(10);
    glPopMatrix();

}

void cloud_model_Three(){
    glColor3f(1.25, 0.924, 0.930);

    ///Left_Part
    glPushMatrix();
    glTranslatef(300,200,0);
    circle(15);
    glPopMatrix();

    ///Top_Left

    glPushMatrix();
    glTranslatef(320,210,0);
    circle(15);
    glPopMatrix();

    ///Top
    glPushMatrix();
    glTranslatef(340,220,0);
    circle(16);
    glPopMatrix();

    ///Top_Right
    glPushMatrix();
    glTranslatef(360,210,0);
    circle(15);
    glPopMatrix();

    ///Right_Part
    glPushMatrix();
    glTranslatef(380,200,0);
    circle(15);
    glPopMatrix();

    ///Bottom_Right
    glPushMatrix();
    glTranslatef(360,190,0);
    circle(20);
    glPopMatrix();

    ///Bottom_Left
    glPushMatrix();
    glTranslatef(320,190,0);
    circle(20);
    glPopMatrix();

    ///Bottom
    glPushMatrix();
    glTranslatef(340,190,0);
    circle(20);
    glPopMatrix();




    ///****Fill End****

}

///*** Bus_Model ***///
void Bus_Model()
{
    glBegin(GL_POLYGON); //body
    glColor3ub(102, 102, 255);
    glVertex2i(915,27);
    glVertex2i(915,100);
    glVertex2i(1300,100);
    glVertex2i(1300,27);
    glEnd();
    //windows
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 102);
    glVertex2i(930,65);
    glVertex2i(930,95);
    glVertex2i(960,95);
    glVertex2i(960,65);
    glEnd();

    glBegin(GL_POLYGON); //body
    glColor3ub(0, 0, 102);
    glVertex2i(965,65);
    glVertex2i(965,95);
    glVertex2i(995,95);
    glVertex2i(995,65);
    glEnd();

    glBegin(GL_POLYGON); //body
    glColor3ub(0, 0, 102);
    glVertex2i(1045,65);
    glVertex2i(1045,95);
    glVertex2i(1075,95);
    glVertex2i(1075,65);
    glEnd();
    glBegin(GL_POLYGON); //body
    glColor3ub(0, 0, 102);
    glVertex2i(1080,65);
    glVertex2i(1080,95);
    glVertex2i(1110,95);
    glVertex2i(1110,65);
    glEnd();
    glBegin(GL_POLYGON); //body
    glColor3ub(0, 0, 102);
    glVertex2i(1115,65);
    glVertex2i(1115,95);
    glVertex2i(1145,95);
    glVertex2i(1145,65);
    glEnd();
    glBegin(GL_POLYGON); //body
    glColor3ub(0, 0, 102);
    glVertex2i(1150,65);
    glVertex2i(1150,95);
    glVertex2i(1180,95);
    glVertex2i(1180,65);
    glEnd();
    glBegin(GL_POLYGON); //body
    glColor3ub(0, 0, 102);
    glVertex2i(1185,65);
    glVertex2i(1185,95);
    glVertex2i(1215,95);
    glVertex2i(1215,65);
    glEnd();
    glBegin(GL_POLYGON); //body
    glColor3ub(0, 0, 102);
    glVertex2i(1220,65);
    glVertex2i(1220,95);
    glVertex2i(1250,95);
    glVertex2i(1250,65);
    glEnd();
    glBegin(GL_POLYGON); //body
    glColor3ub(0, 0, 102);
    glVertex2i(1255,65);
    glVertex2i(1255,95);
    glVertex2i(1285,95);
    glVertex2i(1285,65);
    glEnd();

    //bus door
    glBegin(GL_POLYGON); //door
    glColor3ub(0, 0, 102);
    glVertex2i(1010,27);
    glVertex2i(1010,80);
    glVertex2i(1040,80);
    glVertex2i(1040,27);
    glEnd();

    // back tire
    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(960,30,0);
    circle(10);
    glPopMatrix();

    glPushMatrix(); // front tire
    glColor3f(0.0,0.0,0.0);
    glTranslatef(1000,30,0);
    circle(10);
    glPopMatrix();

     glPushMatrix(); // back tire
    glColor3f(0.0,0.0,0.0);
    glTranslatef(1200,30,0);
    circle(10);
    glPopMatrix();

    glPushMatrix(); // front tire
    glColor3f(0.0,0.0,0.0);
    glTranslatef(1250,30,0);
    circle(10);
    glPopMatrix();

}

///*** Car_Model ***///
void Car_Model()
{
    glBegin(GL_POLYGON);
    glColor3ub(204, 102, 0);//body
    glVertex2i(145,17);
    glVertex2i(145,35);
    glVertex2i(160,35);
    glVertex2i(165,50);
    glVertex2i(200,50);
    glVertex2i(205,35);
    glVertex2i(220,35);
    glVertex2i(220,17);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(128, 0, 0);//front body
    glVertex2i(220,35);
    glVertex2i(220,17);
    glVertex2i(230,17);
    glVertex2i(230,35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(128, 0, 0);//back body
    glVertex2i(145,35);
    glVertex2i(145,17);
    glVertex2i(135,17);
    glVertex2i(135,35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(128, 0, 0);//car windows
    glVertex2i(162,35);
    glVertex2i(165,48);
    glVertex2i(181,48);
    glVertex2i(181,35);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(128, 0, 0);//car windows
    glVertex2i(203,35);
    glVertex2i(200,48);
    glVertex2i(184,48);
    glVertex2i(184,35);
    glEnd();

    glPushMatrix(); // back tire
    glColor3f(0.0,0.0,0.0);
    glTranslatef(165,20,0);
    circle(9);
    glPopMatrix();

    glPushMatrix(); // front tire
    glColor3f(0.0,0.0,0.0);
    glTranslatef(200,20,0);
    circle(9);
    glPopMatrix();
}

/// ***train model *** ///
void train_model()
{
glPushMatrix();

    glBegin(GL_POLYGON); //engine body
    glColor3ub (3, 71, 23);
	glVertex2i(480,122);
	glVertex2i(490,131);
	glVertex2i(600,131);
	glVertex2i(600,122);
    glEnd();
    glBegin(GL_POLYGON); // engine body
    glColor3ub (3, 71, 23);
	glVertex2i(560,122);
	glVertex2i(560,160);
	glVertex2i(600,160);
	glVertex2i(600,122);
    glEnd();
    glBegin(GL_POLYGON); // engine
    glColor3ub (71, 3, 23);
	glVertex2i(492,132);
	glVertex2i(515,150);
	glVertex2i(558,160);
	glVertex2i(558,132);
    glEnd();
    glColor3ub (21,67,96); // engine window
    glPointSize(4.0);
    glRectf(565,132,595,155);

    for(int i=0; i<401; i=i+100)
    {
        glBegin(GL_POLYGON); // car Body
        glColor3ub (3, 71, 23);
        glVertex2i(602+i,122);
        glVertex2i(602+i,160);
        glVertex2i(700+i,160);
        glVertex2i(700+i,122);
        glEnd();

        glBegin(GL_POLYGON); // car Door
        glColor3ub (21,67,96);
        glVertex2i(608+i,124);
        glVertex2i(608+i,155);
        glVertex2i(628+i,155);
        glVertex2i(628+i,124);
        glEnd();

        glColor3ub (21,67,96); // car1 window
        glPointSize(4.0);
        glRectf(631+i,132,651+i,155);

        glColor3ub (21,67,96); // car1 window
        glPointSize(4.0);
        glRectf(653+i,132,673+i,155);

        glColor3ub (21,67,96); // car1 window
        glPointSize(4.0);
        glRectf(675+i,132,695+i,155);
    }

glPopMatrix();
//glFlush();
}

/// *** train model *** ///
void bridge_model()
{
    int clrCnt =0;
	for(int i=0; i<1400; i=i+90)
    {
        glBegin(GL_POLYGON); // bridge slab
        glColor3ub (158, clrCnt, clrCnt+30);
        glVertex2i(0+i, 230);
        glVertex2i(0+i, 245);
        glVertex2i(90+i, 245);
        glVertex2i(90+i, 230);
        glEnd();
        clrCnt=clrCnt+10;

        glBegin(GL_POLYGON); // bridge pile base
        glColor3ub(28,90,188);
        glVertex2i(10+i, 120);
        glVertex2i(20+i, 145);
        glVertex2i(40+i, 145);
        glVertex2i(50+i, 120);
        glEnd();

        glBegin(GL_POLYGON); // bridge pile body
        glColor3ub(28,190,188);
        glVertex2i(22+i, 145);
        glVertex2i(25+i, 230);
        glVertex2i(35+i, 230);
        glVertex2i(38+i, 145);
        glEnd();

    }
}
///*** Buildings ***///
void buidling(){

    glBegin(GL_QUADS);
	glColor3ub(102, 102, 153);
	glVertex2i(0+i,70);
	glVertex2i(0+i,400);
	glVertex2i(40+i,400);
	glVertex2i(40+i,70);
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 51, 51);
	glVertex2i(43+i,70);
	glVertex2i(43+i,350);
	glVertex2i(85+i,350);
	glVertex2i(85+i,70);
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 102, 153);
	glVertex2i(88+i,70);
	glVertex2i(88+i,430);
	glVertex2i(130+i,430);
	glVertex2i(130+i,70);
	glEnd();


	//building1 windows
	glBegin(GL_POLYGON);
    glColor3ub(255, 255, 153);
	glVertex2i(60, 120);
	glVertex2i(60, 150);
	glVertex2i(80, 150);
	glVertex2i(80, 120);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(255, 255, 153);
	glVertex2i(60,155);
	glVertex2i(60,165);
	glVertex2i(80,165);
	glVertex2i(80,155);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 153);
	glVertex2i(60,170);
	glVertex2i(60,180);
	glVertex2i(80,180);
	glVertex2i(80,170);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 153);
	glVertex2i(60,185);
	glVertex2i(60,195);
	glVertex2i(80,195);
	glVertex2i(80,185);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 153);
	glVertex2i(60,200);
	glVertex2i(60,210);
	glVertex2i(80,210);
	glVertex2i(80,200);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 153);
	glVertex2i(60,215);
	glVertex2i(60,220);
	glVertex2i(80,220);
	glVertex2i(80,215);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 153);
	glVertex2i(60,225);
	glVertex2i(60,235);
	glVertex2i(80,235);
	glVertex2i(80,225);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 153);
	glVertex2i(60,240);
	glVertex2i(60,250);
	glVertex2i(80,250);
	glVertex2i(80,240);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 153);
	glVertex2i(60,255);
	glVertex2i(60,265);
	glVertex2i(80,265);
	glVertex2i(80,255);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 153);
	glVertex2i(60,270);
	glVertex2i(60,280);
	glVertex2i(80,280);
	glVertex2i(80,270);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(255, 255, 153);
	glVertex2i(60,285);
	glVertex2i(60,295);
	glVertex2i(80,295);
	glVertex2i(80,285);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 153);
	glVertex2i(60,300);
	glVertex2i(60,310);
	glVertex2i(80,310);
	glVertex2i(80,300);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 153);
	glVertex2i(60,315);
	glVertex2i(60,325);
	glVertex2i(80,325);
	glVertex2i(80,315);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 153);
	glVertex2i(60,330);
	glVertex2i(60,340);
	glVertex2i(80,340);
	glVertex2i(80,330);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 153);
	glVertex2i(60,345);
	glVertex2i(60,355);
	glVertex2i(80,355);
	glVertex2i(80,345);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 153);
	glVertex2i(60,360);
	glVertex2i(60,370);
	glVertex2i(80,370);
	glVertex2i(80,360);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 153);
	glVertex2i(60,375);
	glVertex2i(60,385);
	glVertex2i(80,385);
	glVertex2i(80,375);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 153);
	glVertex2i(60,390);
	glVertex2i(60,400);
	glVertex2i(80,400);
	glVertex2i(80,390);
	glEnd();

    //building2 windows
	glBegin(GL_POLYGON);
    glColor3ub(255, 255, 153);
	glVertex2i(105, 120);
	glVertex2i(105, 140);
	glVertex2i(125, 140);
	glVertex2i(125, 120);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255, 255, 153);
	glVertex2i(105, 145);
	glVertex2i(105, 155);
	glVertex2i(125, 155);
	glVertex2i(125, 145);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255, 255, 153);
	glVertex2i(105, 160);
	glVertex2i(105, 170);
	glVertex2i(125, 170);
	glVertex2i(125, 160);
	glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 153);
	glVertex2i(105, 175);
	glVertex2i(105, 185);
	glVertex2i(125, 185);
	glVertex2i(125, 175);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255, 255, 153);
	glVertex2i(105, 190);
	glVertex2i(105, 200);
	glVertex2i(125, 200);
	glVertex2i(125, 190);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255, 255, 153);
	glVertex2i(105, 205);
	glVertex2i(105, 215);
	glVertex2i(125, 215);
	glVertex2i(125, 205);
	glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 153);
	glVertex2i(105, 220);
	glVertex2i(105, 230);
	glVertex2i(125, 230);
	glVertex2i(125, 220);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255, 255, 153);
	glVertex2i(105, 235);
	glVertex2i(105, 245);
	glVertex2i(125, 245);
	glVertex2i(125, 235);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255, 255, 153);
	glVertex2i(105, 250);
	glVertex2i(105, 260);
	glVertex2i(125, 260);
	glVertex2i(125, 250);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255, 255, 153);
	glVertex2i(105, 265);
	glVertex2i(105, 275);
	glVertex2i(125, 275);
	glVertex2i(125, 265);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255, 255, 153);
	glVertex2i(105, 270);
	glVertex2i(105, 280);
	glVertex2i(125, 280);
	glVertex2i(125, 270);
	glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 153);
	glVertex2i(105, 285);
	glVertex2i(105, 295);
	glVertex2i(125, 295);
	glVertex2i(125, 285);
	glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 153);
	glVertex2i(105, 300);
	glVertex2i(105, 310);
	glVertex2i(125, 310);
	glVertex2i(125, 300);
	glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 153);
	glVertex2i(105, 315);
	glVertex2i(105, 325);
	glVertex2i(125, 325);
	glVertex2i(125, 315);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255, 255, 153);
	glVertex2i(105, 330);
	glVertex2i(105, 340);
	glVertex2i(125, 340);
	glVertex2i(125, 330);
	glEnd();

	//building3 windows
	glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(145, 120);
	glVertex2i(145, 140);
	glVertex2i(175, 140);
	glVertex2i(175, 120);
	glEnd();
	//left side window
	glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(141, 145);
	glVertex2i(141, 155);
	glVertex2i(158, 155);
	glVertex2i(158, 145);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(141, 160);
	glVertex2i(141, 170);
	glVertex2i(158, 170);
	glVertex2i(158, 160);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(141, 175);
	glVertex2i(141, 185);
	glVertex2i(158, 185);
	glVertex2i(158, 175);
	glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(141, 190);
	glVertex2i(141, 200);
	glVertex2i(158, 200);
	glVertex2i(158, 190);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(141, 205);
	glVertex2i(141, 215);
	glVertex2i(158, 215);
	glVertex2i(158, 205);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(141, 220);
	glVertex2i(141, 230);
	glVertex2i(158, 230);
	glVertex2i(158, 220);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(141, 235);
	glVertex2i(141, 245);
	glVertex2i(158, 245);
	glVertex2i(158, 235);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(141, 250);
	glVertex2i(141, 260);
	glVertex2i(158, 260);
	glVertex2i(158, 250);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(141, 265);
	glVertex2i(141, 275);
	glVertex2i(158, 275);
	glVertex2i(158, 265);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(141, 280);
	glVertex2i(141, 290);
	glVertex2i(158, 290);
	glVertex2i(158, 280);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(141, 295);
	glVertex2i(141, 305);
	glVertex2i(158, 305);
	glVertex2i(158, 295);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(141, 310);
	glVertex2i(141, 320);
	glVertex2i(158, 320);
	glVertex2i(158, 310);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(141, 325);
	glVertex2i(141, 335);
	glVertex2i(158, 335);
	glVertex2i(158, 325);
	glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(141, 340);
	glVertex2i(141, 350);
	glVertex2i(158, 350);
	glVertex2i(158, 340);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(141, 355);
	glVertex2i(141, 365);
	glVertex2i(158, 365);
	glVertex2i(158, 355);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(141, 370);
	glVertex2i(141, 380);
	glVertex2i(158, 380);
	glVertex2i(158, 370);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(141, 385);
	glVertex2i(141, 395);
	glVertex2i(158, 395);
	glVertex2i(158, 385);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(141, 400);
	glVertex2i(141, 410);
	glVertex2i(158, 410);
	glVertex2i(158, 400);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(141, 415);
	glVertex2i(141, 425);
	glVertex2i(158, 425);
	glVertex2i(158, 415);
	glEnd();
	//right side window
	glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(160, 145);
	glVertex2i(160, 155);
	glVertex2i(177, 155);
	glVertex2i(177, 145);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(160, 160);
	glVertex2i(160, 170);
	glVertex2i(177, 170);
	glVertex2i(177, 160);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(160, 175);
	glVertex2i(160, 185);
	glVertex2i(177, 185);
	glVertex2i(177, 175);
	glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(160, 190);
	glVertex2i(160, 200);
	glVertex2i(177, 200);
	glVertex2i(177, 190);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(160, 205);
	glVertex2i(160, 215);
	glVertex2i(177, 215);
	glVertex2i(177, 205);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(160, 220);
	glVertex2i(160, 230);
	glVertex2i(177, 230);
	glVertex2i(177, 220);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(160, 235);
	glVertex2i(160, 245);
	glVertex2i(177, 245);
	glVertex2i(177, 235);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(160, 250);
	glVertex2i(160, 260);
	glVertex2i(177, 260);
	glVertex2i(177, 250);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(141, 265);
	glVertex2i(141, 275);
	glVertex2i(177, 275);
	glVertex2i(177, 265);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(160, 280);
	glVertex2i(160, 290);
	glVertex2i(177, 290);
	glVertex2i(177, 280);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(160, 295);
	glVertex2i(160, 305);
	glVertex2i(177, 305);
	glVertex2i(177, 295);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(160, 310);
	glVertex2i(160, 320);
	glVertex2i(177, 320);
	glVertex2i(177, 310);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(160, 325);
	glVertex2i(160, 335);
	glVertex2i(177, 335);
	glVertex2i(177, 325);
	glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(160, 340);
	glVertex2i(160, 350);
	glVertex2i(177, 350);
	glVertex2i(177, 340);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(160, 355);
	glVertex2i(160, 365);
	glVertex2i(158, 365);
	glVertex2i(158, 355);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(160, 370);
	glVertex2i(160, 380);
	glVertex2i(177, 380);
	glVertex2i(177, 370);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(160, 385);
	glVertex2i(160, 395);
	glVertex2i(177, 395);
	glVertex2i(177, 385);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(160, 400);
	glVertex2i(160, 410);
	glVertex2i(177, 410);
	glVertex2i(177, 400);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(160, 415);
	glVertex2i(160, 425);
	glVertex2i(177, 425);
	glVertex2i(177, 415);
	glEnd();









	glBegin(GL_POLYGON);
    glColor3ub(153, 51, 51);
	glVertex2i(160, 340);
	glVertex2i(160, 350);
	glVertex2i(177, 350);
	glVertex2i(177, 340);
	glEnd();



}

///** Footpath_Model ***///
void footpath(){
    ///Footpath
	glBegin(GL_POLYGON);
    glColor3ub(128, 96, 0);
	glVertex2i(0, 70);
	glVertex2i(0, 120);
	glVertex2i(1000, 120);
	glVertex2i(1000, 70);

	glEnd();


    ///footpath_Shadow
	glBegin(GL_POLYGON);
	glColor3ub(128, 96, 0);
	//glColor3ub(122,132,123);
	glVertex2i(0, 0);
	glVertex2i(0, 70);
	glVertex2i(1000, 70);
	glVertex2i(1000, 0);

	glEnd();
    //Trafic Signal
    //Trafic Pole
glBegin(GL_POLYGON);
glColor3ub(173, 173, 133);
glVertex2i(60,70);
glVertex2i(60,110);
glVertex2i(70,110);
glVertex2i(70,70);
glEnd();

//light box
glBegin(GL_POLYGON);
glColor3ub(0, 0, 0);
glVertex2i(60,95);
glVertex2i(60,110);
glVertex2i(110,110);
glVertex2i(110,95);
glEnd();


//1:red light
glLineWidth(7.5);
glBegin(GL_POLYGON);
for(int i=0;i<200;i++)
{
glColor3ub(255, 0, 0);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=5;
float x = r * cos(A);
float y = r * sin(A);
glVertex2i(75+x,103+y);
}
glEnd();

//yellow light
glLineWidth(7.5);
glBegin(GL_POLYGON);
for(int i=0;i<200;i++)
{
glColor3ub(255, 255, 0);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=5;
float x = r * cos(A);
float y = r * sin(A);
glVertex2i(88+x,103+y);
}
glEnd();

//green light
glLineWidth(7.5);
glBegin(GL_POLYGON);
for(int i=0;i<200;i++)
{
glColor3ub(0, 179, 60);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=5;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(101+x,103+y);
}
glEnd();

}
void Road()
{

    for(int i=0; i<1000; i=i+50)
    {
        glBegin(GL_POLYGON); // ROad Skirt up
        if(i==0 || i%100==0)
        {
            glColor3ub(382,115,123);
        }
        else
        {
            glColor3ub(0,0,0);
        }
        glVertex2i(0+i,65);
        glVertex2i(0+i,70);
        glVertex2i(50+i,70);
        glVertex2i(50+i,65);
        glEnd();

        glBegin(GL_POLYGON); // Road Mid
        glColor3ub(153, 153, 102);
        glVertex2i(0+i,5);
        glVertex2i(0+i,65);
        glVertex2i(50+i,65);
        glVertex2i(50+i,5);
        glEnd();


        glBegin(GL_POLYGON); // ROad Skirt down
        if(i==0 || i%100==0)
        {
            glColor3ub(382,115,123);
        }
        else
        {
            glColor3ub(0,0,0);
        }
        glVertex2i(0+i,0);
        glVertex2i(0+i,5);
        glVertex2i(50+i,5);
        glVertex2i(50+i,0);
        glEnd();
    }
}

void RoadMidSkirt()
{
    for(int i=0; i<1000; i=i+20)
    {
        glBegin(GL_POLYGON); // ROad Skirt up
        if(i==0 || i%100==0)
        {
            glColor3ub(158,182,133);
        }
        else
        {
            glColor3ub(0,0,0);
        }
        glVertex2i(0+i,30);
        glVertex2i(0+i,35);
        glVertex2i(20+i,35);
        glVertex2i(20+i,30);
        glEnd();
    }
}
///*** Tree_Model ***///
void Tree_Model_One(){


    glPushMatrix();
    glTranslatef(110,112,0);
    circle(25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(110,90,0);
    circle(10);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2f(109, 70);
	glVertex2f(109, 90);
	glVertex2f(111, 90);
	glVertex2f(111, 70);

    glEnd();

}
void Tree_Model_Two(){

    glPushMatrix();
    glTranslatef(130,90,0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(125,86,0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(135,86,0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(130,85,0);
    circle(5);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2f(129, 70);
	glVertex2f(129, 84);
	glVertex2f(131, 84);
	glVertex2f(131, 70);

    glEnd();
}

void Tree_Model_Three(){


    glBegin(GL_POLYGON);
	glVertex2f(125, 90);
	glVertex2f(133, 105);
	glVertex2f(141, 90);
	glEnd();

    glBegin(GL_POLYGON);
	glVertex2f(125, 83);
	glVertex2f(133, 115);
	glVertex2f(141, 83);
	glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2f(132, 70);
	glVertex2f(132, 84);
	glVertex2f(134, 84);
	glVertex2f(134, 70);
    glEnd();
}

/// *** Windmill_Stand_Model ***///
void Windmill_Stand_Model(){

    glColor3ub(153, 51, 51);
    glBegin(GL_POLYGON);
    glVertex2i(375, 120);
    glVertex2i(380, 320);
    glVertex2i(384, 320);
    glVertex2i(390, 120);
    glEnd();
}

///*** Windmill_Blades_Model ***///

void Windmill_Blade(){
///Blade_One
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(-5, 0);
    glVertex2i(-85, -36);
    glVertex2i(-83, -37);
    glVertex2i(-3, -8);
    glEnd();
    glPopMatrix();

    ///Blade_Two
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(0, 5);
    glVertex2i(45, 70);
    glVertex2i(50, 73);
    glVertex2i(5, 0);
    glEnd();
    glPopMatrix();

    ///Blade_Three
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(68, -78);
    glVertex2i(0,0);
    glVertex2i(5, 5);
    glVertex2i(70, -77);
    glEnd();
    glPopMatrix();

}
///*** Windmill_Final_Model ***///
void Windmill(){



    ///Windmill_Stand
    glColor3ub(153, 51, 51);
    glPushMatrix();
    Windmill_Stand_Model();
    glPopMatrix();

    ///Windmill_Motor
    glColor3ub(204, 153, 0);
    glPushMatrix();
    glTranslatef(380,330,0);
    circle(10);
    glPopMatrix();

    ///Windmill_Rotary_Blades
    glColor3ub(204, 153, 0);
    glPushMatrix();
    glTranslatef(380,330,0);
    Windmill_Blade();
    glPopMatrix();




}


///Model_End
///=======================================================================================================///


///=================///
///***   Object  ***///
///=================///

///*** Sun ***///
void Sun(){
    glColor3f(1, 1, 0);
    glPushMatrix();
    Moving_Sun_Model();
    glPopMatrix();
}

///*** Cloud_One_Model_One ***///

void cloud_one(){
    glPushMatrix();
    glTranslatef(cx,240,0);
    cloud_model_one();
    glPopMatrix();

}


///*** Cloud_Two_Model_one ***///

void cloud_two(){
    glPushMatrix();
    glTranslatef(bx+150,250,0);
    cloud_model_one();
    glPopMatrix();

}

///*** Cloud_Three_Model_Two ***///

void cloud_three(){
    glPushMatrix();
    glTranslatef(ax-80,245,0);
    cloud_model_Two();
    glPopMatrix();

}
///*** Cloud_Four_Model_Two ***///

void cloud_four(){
    glPushMatrix();
    glTranslatef(dx+300,230,0);
    cloud_model_Two();
    glPopMatrix();

}

///*** Bridge ***///
void bridge(){
    glPushMatrix();
    glTranslatef(0,0,0);
    bridge_model();
    glPopMatrix();
}
///*** Tree_1 ***///
void Tree_One(){
    glColor3ub(3,90,30);
    glPushMatrix();
    glTranslatef(700,0,0);
    Tree_Model_One();
    glPopMatrix();
}

///*** Tree_2 ***///
void Tree_Two(){
    glColor3ub(3,90,30);
    glPushMatrix();
    glTranslatef(760,0,0);
    Tree_Model_One();
    glPopMatrix();
}

///*** Tree_3 ***///
void Tree_Three(){
    glColor3ub(40,180,99);
    glPushMatrix();
    glTranslatef(810,0,0);
    Tree_Model_One();
    glPopMatrix();
}
///*** Tree_4 ***///
void Tree_Four(){
    glColor3ub(40,180,99);
    glPushMatrix();
    glTranslatef(650,0,0);
    Tree_Model_One();
    glPopMatrix();
}

///*** Tree_5 ***///
void Tree_Five(){
    glColor3ub(40,180,90);
    glPushMatrix();
    glTranslatef(580,30,0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_6 ***///
void Tree_Six(){
    glColor3ub(3,71,23);
    glPushMatrix();
    glTranslatef(760,30,0);
    Tree_Model_Two();
    glPopMatrix();
}
///*** Tree_7 ***///
void Tree_Seven(){
    glColor3ub(3,71,23);
    glPushMatrix();
    glTranslatef(700,15,0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_8 ***///
void Tree_Eight(){
    glColor3ub(40,180,99);
    glPushMatrix();
    glTranslatef(630,30,0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_9 ***///
void Tree_Nine(){
    glColor3ub(3,90,30);
    glPushMatrix();
    glTranslatef(680,20,0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_10 ***///
void Tree_Ten(){
    glColor3ub(40,180,90);
    glPushMatrix();
    glTranslatef(800,20,0);
    Tree_Model_Three();
    glPopMatrix();
}

///*** Tree_11 ***///
void Tree_Eleven(){
    glColor3ub(3,71,23);
    glPushMatrix();
    glTranslatef(820,20,0);
    Tree_Model_Three();
    glPopMatrix();
}

///*** Tree_12 ***///
void Tree_Twelve(){
    glColor3ub(3,90,30);
    glPushMatrix();
    glTranslatef(850,20,0);
    Tree_Model_Three();
    glPopMatrix();
}

///*** Tree_13 ***///
void Tree_Thirteen(){
    glColor3ub(3,71,23);
    glPushMatrix();
    glTranslatef(860,0,0);
    Tree_Model_Three();
    glPopMatrix();
}

///*** Tree_14 ***///
void Tree_fourteen(){
    glColor3ub(40,180,90);
    glPushMatrix();
    glTranslatef(840,0,0);
    Tree_Model_Three();
    glPopMatrix();
}

/// *** Car Model ***///
void Car_one()
{
    glPushMatrix();
    glTranslatef(tr12,0,0);
    Car_Model();
    glPopMatrix();
}

/// *** Bus Model ***///
void Bus_one()
{
    glPushMatrix();
    glTranslatef(tr22,20,0);
    Bus_Model();
    glPopMatrix();
}


/// *** Train ***///
void train()
{
    glPushMatrix();
    glTranslatef(trn,125,0);
    train_model();
    glPopMatrix();
}

/// *** Windmill ***///

    void windmill(){
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(508,0,0);
    Windmill();
    glPopMatrix();

}

void keyboard(unsigned char key, int x, int y){

	 if (key == 't'){		//train start
		trainST = 1;
		bridgeST = 1;
	}
	else if (key == 's'){		//train start
		trainST = 0;
		bridgeST = 0;
	}
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);

    ///*** Object_Layer ***///
    Sun();
    buidling();

    windmill();

    cloud_three();
    cloud_four();


    if(bridgeST==1)
    {
        bridge();
    }


    cloud_two();
    cloud_one();



    footpath();
    Road();
    RoadMidSkirt();

    Tree_Five();
    Tree_Six();
    Tree_Seven();
    Tree_Eight();
    Tree_Nine();
    Tree_Ten();
    Tree_Eleven();
    Tree_Twelve();

    if(bridgeST==1)
    {
        train();
    }

    Tree_One();
    Tree_Two();
    Tree_Three();
    Tree_Four();
    Tree_Thirteen();
    Tree_fourteen();


    Bus_one();
    Car_one();




	glFlush();
}
///========================///
///*** Speed & Movement ***///
///========================///
///*** Sun_Move ***///
void sun_move(){

    sun_spin = sun_spin + 0.008;
    if(sun_spin>15){
            sun_spin = 15;
    }
}
void move_right(){

    sun_move();

    spin=spin+0.1;
    ax = ax + .05;
    bx = bx + .08;
    cx = cx + .40;
    dx = dx + .15;
    tr11 = tr11 - .10;
    tr12 = tr12 + .10;
    tr22 = tr22 - .15;



    if(cx>1000){
        cx = -300;
    }
    if(bx>1000){
            bx= -400;

    }
    if(cx>1000){
            cx= -400;

    }
    if(dx>1000){
            dx= -500;

    }

    if(tr11<-1000){
            tr11= 100;

    }

    if(tr12>1000){
            tr12= -200;

    }
    if(tr22<-1000){
            tr22= 200;
    }

        if(trainST==1)
    {
        trn = trn - .20;
        if(trn<-1100)
        {
            trn=500;
        }
    }
    glutPostRedisplay();
}

void mouse(int key, int state, int x, int y){
    switch (key)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(move_right);
        }
        break;
    case GLUT_MIDDLE_BUTTON:
    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(NULL);
        }
        break;
    default:
        break;
    }
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 50);
	glutInitWindowSize(1900, 1900);
	glutCreateWindow("City life scenario");

	glutKeyboardFunc(keyboard);
	init();
	glutDisplayFunc(display);

    glutMouseFunc(mouse);


    //glutFullScreen();
	glutMainLoop();
}
