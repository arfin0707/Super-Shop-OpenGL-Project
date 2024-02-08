// Base Code For Assignment - 3
#include <windows.h>

#define GL_SILENCE_DEPRECATION
//#include <OpenGL/gl3.h>
#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <GL/gl.h>
#include<math.h>
#include <iostream>
#include <cmath>  // Include the header for math functions

#include "BmpLoader.h"
void sphere(double x, double y, double z){
 glutSolidSphere(x,y,z);
}

//stbi_set_flip_vertically_on_load(true);


using namespace std;
const int width = 700;
const int height = 700;

GLfloat eyeX = 31;
GLfloat eyeY = 5;
GLfloat eyeZ = -27;

GLfloat centerX = 7;
GLfloat centerY = 5;
GLfloat centerZ = 28;
double angle = 0 ;
bool l_on1 = true;
bool l_on2 = true;
bool l_on3 = true;
bool l_on4 = false;
float rot = 0;
int stop=1;
float door_angle=.5;
float l_height =.5;
float spt_cutoff = 30;
unsigned int ID;
//vector<int>v;


#include<GL/glut.h>
#include<math.h>
#define pi 3.142857
#include<iostream>
using namespace std;




void myInit ()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 700, 0, 800, -10.0, 10.0);
}

void circle(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy)///radius_x,radius_y,centre_position_x,centre_position_y///
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);
    for(int i=0; i<=360; i++)
    {
        float angle = 3.1416f * i/180;
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);
        glVertex2f((x+cx),(y+cy));
    }
    glEnd();


}

float p = -10;
int i= -700;
float j= -250;
float k= -100;



static void getNormal3p(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2, GLfloat x3, GLfloat y3, GLfloat z3)
{
    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

    Ux = x2-x1;
    Uy = y2-y1;
    Uz = z2-z1;

    Vx = x3-x1;
    Vy = y3-y1;
    Vz = z3-z1;

    Nx = Uy*Vz - Uz*Vy;
    Ny = Uz*Vx - Ux*Vz;
    Nz = Ux*Vy - Uy*Vx;

    glNormal3f(Nx,Ny,Nz);
}


static GLfloat v_cube[8][3] =
{
    {0,0,0},
    {0,0,1},
    {0,1,0},
    {0,1,1},

    {1,0,0},
    {1,0,1},
    {1,1,0},
    {1,1,1}
};

static GLubyte c_ind[6][4] =
{
    {3,1,5,7},  //front
    {6,4,0,2},  //back
    {2,3,7,6},  //top
    {1,0,4,5},  //bottom
    {7,5,4,6},  //right
    {2,0,1,3}   //left
};

void cubeT(float R=0.5, float G=0.5, float B=0.5, float a=1, int type=0, float val=1)
{

    GLfloat m_no[] = {0, 0, 0, 1.0};
    GLfloat m_amb[] = {R,G,B,a};
    GLfloat m_diff[] = {R,G,B,a};
    GLfloat m_spec[] = {1,1,1,1};
    GLfloat m_sh[] = {30};

    GLfloat m_em[] = {1,1,1,1};

    glMaterialfv(GL_FRONT, GL_AMBIENT, m_amb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, m_spec);
    glMaterialfv(GL_FRONT, GL_SHININESS, m_sh);
    if(type==1)
    {

        if(l_on1)
            glMaterialfv(GL_FRONT, GL_EMISSION, m_em);
        else
            glMaterialfv(GL_FRONT, GL_EMISSION, m_no);

    }
    else if(type==2)
    {
        if(l_on3)
            glMaterialfv(GL_FRONT, GL_EMISSION, m_em);
        else
            glMaterialfv(GL_FRONT, GL_EMISSION, m_no);
    }
    else
        glMaterialfv(GL_FRONT, GL_EMISSION, m_no);


    glBegin(GL_QUADS);
    for (GLint i = 0; i <6; i++)
    {
        getNormal3p(v_cube[c_ind[i][0]][0], v_cube[c_ind[i][0]][1], v_cube[c_ind[i][0]][2],
                    v_cube[c_ind[i][1]][0], v_cube[c_ind[i][1]][1], v_cube[c_ind[i][1]][2],
                    v_cube[c_ind[i][2]][0], v_cube[c_ind[i][2]][1], v_cube[c_ind[i][2]][2]);
        glTexCoord2f(0,val);
        glVertex3fv(&v_cube[c_ind[i][0]][0]);
        glTexCoord2f(0,0);
        glVertex3fv(&v_cube[c_ind[i][1]][0]);
        glTexCoord2f(val,0);
        glVertex3fv(&v_cube[c_ind[i][2]][0]);
        glTexCoord2f(val,val);
        glVertex3fv(&v_cube[c_ind[i][3]][0]);
    }
    glEnd();
}



void cube(float R=0.5, float G=0.5, float B=0.5, int type=0, float val=1)
{

    GLfloat m_no[] = {0, 0, 0, 1.0};
    GLfloat m_amb[] = {R,G,B,1};
    GLfloat m_diff[] = {R,G,B,1};
    GLfloat m_spec[] = {1,1,1,1};
    GLfloat m_sh[] = {30};

    GLfloat m_em[] = {1,1,1,1};

    glMaterialfv(GL_FRONT, GL_AMBIENT, m_amb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, m_spec);
    glMaterialfv(GL_FRONT, GL_SHININESS, m_sh);
    if(type==1)
    {

        if(l_on1)
            glMaterialfv(GL_FRONT, GL_EMISSION, m_em);
        else
            glMaterialfv(GL_FRONT, GL_EMISSION, m_no);

    }
    else if(type==2)
    {
        if(l_on3)
            glMaterialfv(GL_FRONT, GL_EMISSION, m_em);
        else
            glMaterialfv(GL_FRONT, GL_EMISSION, m_no);
    }
    else
        glMaterialfv(GL_FRONT, GL_EMISSION, m_no);


    glBegin(GL_QUADS);
    for (GLint i = 0; i <6; i++)
    {
        getNormal3p(v_cube[c_ind[i][0]][0], v_cube[c_ind[i][0]][1], v_cube[c_ind[i][0]][2],
                    v_cube[c_ind[i][1]][0], v_cube[c_ind[i][1]][1], v_cube[c_ind[i][1]][2],
                    v_cube[c_ind[i][2]][0], v_cube[c_ind[i][2]][1], v_cube[c_ind[i][2]][2]);
        glTexCoord2f(0,val);
        glVertex3fv(&v_cube[c_ind[i][0]][0]);
        glTexCoord2f(0,0);
        glVertex3fv(&v_cube[c_ind[i][1]][0]);
        glTexCoord2f(val,0);
        glVertex3fv(&v_cube[c_ind[i][2]][0]);
        glTexCoord2f(val,val);
        glVertex3fv(&v_cube[c_ind[i][3]][0]);
    }
    glEnd();
}


void cube2(float R = 0.5, float G = 0.5, float B = 0.5, float alpha = 0.2, int type = 0, float val = 1)
{

    GLfloat m_no[] = {0, 0, 0, 0.2};
    GLfloat m_amb[] = {R, G, B, alpha};  // Set alpha for ambient, diffuse, and specular
    GLfloat m_diff[] = {R, G, B, alpha};
    GLfloat m_spec[] = {1, 1, 1, alpha};
    GLfloat m_sh[] = {30};

    GLfloat m_em[] = {1,1,1,1};

    glMaterialfv(GL_FRONT, GL_AMBIENT, m_amb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, m_spec);
    glMaterialfv(GL_FRONT, GL_SHININESS, m_sh);
    if(type==1)
    {

        if(l_on1)
            glMaterialfv(GL_FRONT, GL_EMISSION, m_em);
        else
            glMaterialfv(GL_FRONT, GL_EMISSION, m_no);

    }
    else if(type==2)
    {
        if(l_on3)
            glMaterialfv(GL_FRONT, GL_EMISSION, m_em);
        else
            glMaterialfv(GL_FRONT, GL_EMISSION, m_no);
    }
    else
        glMaterialfv(GL_FRONT, GL_EMISSION, m_no);


    glBegin(GL_QUADS);
    for (GLint i = 0; i <6; i++)
    {
        getNormal3p(v_cube[c_ind[i][0]][0], v_cube[c_ind[i][0]][1], v_cube[c_ind[i][0]][2],
                    v_cube[c_ind[i][1]][0], v_cube[c_ind[i][1]][1], v_cube[c_ind[i][1]][2],
                    v_cube[c_ind[i][2]][0], v_cube[c_ind[i][2]][1], v_cube[c_ind[i][2]][2]);
        glTexCoord2f(0,val);
        glVertex3fv(&v_cube[c_ind[i][0]][0]);
        glTexCoord2f(0,0);
        glVertex3fv(&v_cube[c_ind[i][1]][0]);
        glTexCoord2f(val,0);
        glVertex3fv(&v_cube[c_ind[i][2]][0]);
        glTexCoord2f(val,val);
        glVertex3fv(&v_cube[c_ind[i][3]][0]);
    }
    glEnd();
}

void Cube()
{

    glBegin(GL_QUADS);
    for (GLint i = 0; i <6; i++)
    {
        getNormal3p(v_cube[c_ind[i][0]][0], v_cube[c_ind[i][0]][1], v_cube[c_ind[i][0]][2],
                    v_cube[c_ind[i][1]][0], v_cube[c_ind[i][1]][1], v_cube[c_ind[i][1]][2],
                    v_cube[c_ind[i][2]][0], v_cube[c_ind[i][2]][1], v_cube[c_ind[i][2]][2]);

        for (GLint j=0; j<4; j++)
        {
            glVertex3fv(&v_cube[c_ind[i][0]][0]);glTexCoord2f(1,1);
            glVertex3fv(&v_cube[c_ind[i][1]][0]);glTexCoord2f(1,0);
            glVertex3fv(&v_cube[c_ind[i][2]][0]);glTexCoord2f(0,0);
            glVertex3fv(&v_cube[c_ind[i][3]][0]);glTexCoord2f(0,1);
        }
    }
    glEnd();
}




void axes()
{
    float length = 10;
    float width = 0.3;

    // X-axis
    glPushMatrix();
    glTranslatef(length/2,0,0);
    glScalef(length,width,width);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.8,0.1,0.1);
    glPopMatrix();

    // Y-axis
    glPushMatrix();
    glTranslatef(0,length/2,0);
    glScalef(width,length,width);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.1,0.8,0.1);
    glPopMatrix();

    // Z-axis
    glPushMatrix();
    glTranslatef(0,0,length/2);
    glScalef(width,width,length);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.1,0.1,0.8);
    glPopMatrix();
}


void cse()
{

    glPushMatrix();
    glScalef(.3,.5,1);
    glTranslatef(45,15,1);
    glPushMatrix();

    //C
    glScalef(.4,1.5,2.9);


    glTranslatef(45,3,2);
    float length=3.4;
    float width=.4;
    //ground
    float a=1,b=0,c=.5;
    glPushMatrix();
    glTranslatef(length/2,1,1);;
    glScalef(3*length,width,width);
    glTranslatef(-.75,-0.5,-0.5);
    cube(a,b,c);
    glPopMatrix();

//right

    glPushMatrix();
    glPushMatrix();
    glTranslatef(1,length/2,1);;
    glScalef(width+3,length+.5,width);
    glTranslatef(0,-0.2,-0.5);
    cube(a,b,c);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(length/2,1,1);;
    glScalef(length*3,width,width);
    glTranslatef(-.75,8.7,-0.5);
    cube(a,b,c);
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();

//E


    glPushMatrix();

    glScalef(.4,1.5,2.9);

    glTranslatef(15,3,2);

    //ground
    glPushMatrix();
    glTranslatef(length/2,1,1);;
    glScalef(3*length,width,width);
    glTranslatef(-.75,-0.5,-0.5);
    cube(a,b,c);
    glPopMatrix();

//right

    glPushMatrix();
    glPushMatrix();
    glTranslatef(1,length/2+.1,1);;
    glScalef(width+3,length,width);
    glTranslatef(0,-0.2,-0.5);
    cube(a,b,c);
    glPopMatrix();

    //top
    glPushMatrix();
    glTranslatef(length/2,1,1);;
    glScalef(length*3,width,width);
    glTranslatef(-.75,8.7,-0.5);
    cube(a,b,c);
    glPopMatrix();
    //right
    /*
    */
    //rack4
    glPushMatrix();
    glTranslatef(length,1,1);;
    glScalef(3*length,width,width);
    glTranslatef(-.94,4,-0.5);
    cube(a,b,c);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();



//s


    glPushMatrix();

    glScalef(.4,1.5,2.9);
    glTranslatef(30,3,2);

    //ground
    glPushMatrix();
    glTranslatef(length/2,1,1);;
    glScalef(3*length,width,width);
    glTranslatef(-.75,-0.5,-0.5);
    cube(a,b,c);
    glPopMatrix();

//right

    glPushMatrix();
    glPushMatrix();
    glTranslatef(1,length/2,1);;
    glScalef(width+3,length/2,width);
    glTranslatef(0,0.7,-0.5);
    cube(a,b,c);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1,length/2,1);;
    glScalef(width+3,length/2+.1,width);
    glTranslatef(-2,-0.5,-0.5);
    cube(a,b,c);
    glPopMatrix();


    //top
    glPushMatrix();
    glTranslatef(length/2,1,1);;
    glScalef(length*3,width,width);
    glTranslatef(-.75,8.7,-0.5);
    cube(a,b,c);
    glPopMatrix();

    //rack4
    glPushMatrix();
    glTranslatef(length,1,1);;
    glScalef(3*length,width,width);
    glTranslatef(-.9,4,-0.5);
    cube(a,b,c);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

}

void road(){
    //bottom

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,6);
    glScalef(500,0.7,25);
    glTranslatef(-0.5,0.5,-5.5);
    //glRotatef(-90,1,0,0);
    //cube(0.8, 0.8, 0.8);
    Cube();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void floorWallsCeiling(float scale)
{



    //bottom

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,5);
    glScalef(700,1,900);
    glTranslatef(-0.5,-1,-0.5);
    //cube(0.8, 0.8, 0.8);
    Cube();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    //behind
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,4);
    glTranslatef(0,scale/4,scale/2);
    glScalef(1000,1000/2,1);
    glTranslatef(-0.5,-0.5,-31);
   // cube(1.000, 0.855, 0.725);
    Cube();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


/*

    //left
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,4);
    glTranslatef(scale/2,scale/4,0);
    glScalef(1,scale/2,scale);
    glTranslatef(-1,-0.5,-0.5);
   // cube(0.871, 0.722, 0.529);
    Cube();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    //right
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,4);
    glTranslatef(-scale/2+1,scale/4,0);
    glScalef(1,scale/2,scale);
    glTranslatef(-1,-0.5,-0.5);
   // cube(0.871, 0.722, 0.529);
    Cube();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);



   glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,1);
    glTranslatef(0,scale/4,scale/2);
    glScalef(scale,scale/2,1);
    glTranslatef(-0.5,-0.5,-1);
   //cube(1.000, 0.855, 0.725);
    Cube();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);    */





}


void flr()
{



    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,1);
//    glTranslatef(0,-0.5,0);
    glScalef(60,1,60);
    glTranslatef(-0.5,19,-0.5);
    //cube(0.690, 0.769, 0.871,0,4);
    Cube();
    glPopMatrix();
  glDisable(GL_TEXTURE_2D);



    /*glPushMatrix();


    glTranslatef(0,-0.5,0);
    glScalef(60,1,60);
   glTranslatef(-0.5,-1,-0.5);
    cube(1,1,1,0,8);
    glPopMatrix();




  /* for(int i=-10; i<=35; i++)
    {
        for(float j=-15; j<=14; j+=2)
        {
            glPushMatrix();
//  glTranslatef(0,-0.5,0);

            glScalef(2,.5,1);
            glTranslatef(j,-.999,-i);
            if(i%2==0)
                cube(1, 1, 1);
            else
                cube(0, 0, .5);
            glPopMatrix();
        }
    }

    /*for(int i=-10; i<=35; i++)
    {
        for(float j=-14; j<=14; j+=2)
        {
            glPushMatrix();
//    glTranslatef(0,-0.5,0);

            glScalef(2,.5,1);
            glTranslatef(j,-.999,-i);
            if(i%2!=0)
                cube(1, 1, 1);
            else
                cube(0, 0, .5);
            glPopMatrix();
        }
    }*/


}

//right wall
void wall1()
{
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,1);

//    glTranslatef(0,-0.5,0);
    glScalef(1,20,43);
    glTranslatef(-21,0,-0.7);
    cube2(1, 1, 1, 0.5, 2, 1);  // Adjust the alpha value as needed
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_BLEND);



}

//left Wall
void wall2()
{
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,1);
	glTranslatef(-14,-0.5,0);
    glScalef(1,20,43);
    glTranslatef(29,0,-0.7);
    cube2(1, 1, 1, 0.5, 2, 1);  // Adjust the alpha value as needed
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_BLEND);

}


//behind
void wall3()
{
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,1);
//    glTranslatef(0,-0.5,0);
    glScalef(36,20,1);
    glTranslatef(-.55,0,12);
    //cube(0.741, 0.718, 0.420,0,2);
    cube2(1, 1, 1, 0.5, 2, 1);  // Adjust the alpha value as needed

    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_BLEND);


}


void wall4()
{
    glPushMatrix();
   // glEnable(GL_BLEND);
   // glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   // glEnable(GL_TEXTURE_2D);
    //glBindTexture(GL_TEXTURE_2D,1);
//    glTranslatef(0,-0.5,0);
    glScalef(36,20,1);
    glTranslatef(-.55,0,12);
    //cube(0.741, 0.718, 0.420,0,2);
    cube2(1, 1, 1, 0.5, 2, 1);  // Adjust the alpha value as needed

    glPopMatrix();
   // glDisable(GL_TEXTURE_2D);
    //glDisable(GL_BLEND);


}


void door()
{
    //toppart
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,1);
//    glTranslatef(0,-0.5,0);
    glScalef(30,19,1);
    glTranslatef(-.7,-0,-31);
    //cube2(1,.69,.0,0.05);
    cube2(1, 1, 1, 0.5, 2, 1);  // Adjust the alpha value as needed
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_BLEND);




   //restHalfPart
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,1);
//    glTranslatef(0,-0.5,0);
    glScalef(22,7,1);
    glTranslatef(-.21,1.8,-31);
    //cube2(1,.69,.0,0.05);
    cube2(1, 1, 1, 0.5, 2, 1);  // Adjust the alpha value as needed
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_BLEND);


}


void door2()
{
    //toppart
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,1);
//    glTranslatef(0,-0.5,0);
    glScalef(37,19,1);
    glTranslatef(-.8,-0,-31);
    //cube2(1,.69,.0,0.05);
    cube2(1, 1, 1, 0.5, 2, 1);  // Adjust the alpha value as needed
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_BLEND);




   //restHalfPart
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,1);
//    glTranslatef(0,-0.5,0);
    glScalef(23,7,1);
    glTranslatef(-.3,1.8,-30);
    //cube2(1,.69,.0,0.05);
    cube2(1, 1, 1, 0.5, 2, 1);  // Adjust the alpha value as needed
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_BLEND);


}


//float k=0;
float angle1=0;
bool markdoor=0;
double window_val=0;
void spin()
{
    angle = (angle+k)*stop;
    k+=.001;
    if (angle >= 360)
        angle = 0;
    angle1+=.2;
    if (angle1 >= 360)
        angle1 = 0;
    bool ok=0;
    bool ok1=0;
    if(markdoor&&door_angle>-2)
    {
        door_angle-=.05,ok=1;
        if(door_angle<.1)
            window_val+=0.05;
        window_val=min( window_val,1.00);
        l_on4=1;


    }
    if(!markdoor&&door_angle<.5)
    {
        door_angle+=.05,ok=1;
        window_val-=.05;
        window_val=max(window_val,0.00);

    }
    if(!ok)
        l_on4=markdoor;

}

void headwall()
{
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,3);

//    glTranslatef(0,-0.5,0);
    glScalef(37,1,50);
    glTranslatef(-0.57,19,-0.7);
    //cube(0.690, 0.769, 0.871,0,4);
    Cube();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

}




void topBoard(){
       //restHalfPart
    glPushMatrix();
    //glEnable(GL_TEXTURE_2D);
   //glBindTexture(GL_TEXTURE_2D,1);
//    glTranslatef(0,-0.5,0);
  //  glColor3f(1.0, 0.0, 0.0);  // Set color to red

    glScalef(23,7,1);
    glTranslatef(-.3,1.8,-30);
    Cube();
    glPopMatrix();
  //  glDisable(GL_TEXTURE_2D);

}

void board()
{
    glPushMatrix();
//    glTranslatef(0,-0.5,0);
    glScalef(10,10,1);
    glTranslatef(-.7,.4,9);
    cube(1,1,1);
    glPopMatrix();


    glPushMatrix();
//    glTranslatef(0,-0.5,0);
    glScalef(31.5,11,1);
    glTranslatef(-.601,.32,9.5);
    cube(0,0,0);

}



double a=2;
double b=1;
double c= 10;
void fan()
{
    //fan stand
    float length = 10;
    float width = 0.3;
    glPushMatrix();
    glTranslatef(1,length/2,-4);
    glScalef(width,length,width);
    glTranslatef(-20,1,20);
    cube(0.4,0.4,0.1);
    glPopMatrix();


    glPushMatrix();
    glScalef(1,.1,1);
    glTranslatef(-5,150,2);
    cube(1, 1, 1);            // Set color as glColor3f(R,G,B)
    glRotatef(angle, 0, 0, 1);
    glRecti(-a, -a, a, a);
    cube(1, 0, 0);
    glRecti(-b, a, b, c);
    glRecti(-c, -b, -a, b);
    glRecti(-b, -c, b, -a);
    glRecti(a, -b, c, b);
    glPopMatrix();
}


void drop()
{

    glPushMatrix();
//wear drop front
    cube(113/255.0,74/255.0,44/255.0);
    //glColor3ub (113,74,44);
    glBegin(GL_POLYGON);
    glVertex3f (460, 660, 0);
    glVertex3f (470, 670, 0);
    glVertex3f (330, 670,0);
    glVertex3f (340, 660, 0);
    glVertex3f (340, 320, 0);
    glVertex3f (460, 320, 0);
    glEnd();


//wear drop front-drawer 3 - outer

    glPopMatrix();

    glPushMatrix();


    glTranslatef(0,0,0);
    glScalef(105,95,10);

    glPushMatrix();
    glTranslatef(3.32,4.6,-.49);
    cube(62/255.0,43/255.0,45/255.0);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(3.32,5.7,-.49);
    cube(62/255.0,43/255.0,45/255.0);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(3.32,3.5,-.49);
    cube(62/255.0,43/255.0,45/255.0);
    glPopMatrix();
    glPopMatrix();


    //wear drop front-drawer 1 - handel

    glPushMatrix();
    glTranslatef(1,0,0);
    glScalef(20,10,10);
    glPushMatrix();
    glTranslatef(19.5,38,-.5);
    cube(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(19.5,58,-.5);
    cube(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(19.5,48,-.5);
    cube(1,1,1);
    glPopMatrix();

    glPopMatrix();

//wear drop side

    cube(62/255.0,43/255.0,35/255.0);
    glColor3ub (62,43,35);
    glBegin(GL_POLYGON);
    glVertex3f (470, 670, 0);
    glVertex3f (500, 667, 0);
    glVertex3f (492, 657, 0);
    glVertex3f (492, 330, 0);
    glVertex3f (460, 320, 0);
    glVertex3f (460, 660, 0);
    glEnd();

    glPopMatrix();

}


void drop2()
{

    glPushMatrix();
    glPushMatrix();
//wear drop front
    cube(113/255.0,74/255.0,44/255.0);
    //glColor3ub (113,74,44);
    glBegin(GL_POLYGON);
    glVertex3f (460, 660, 0);
    glVertex3f (470, 670, 0);
    glVertex3f (330, 670,0);
    glVertex3f (340, 660, 0);
    glVertex3f (340, 320, 0);
    glVertex3f (460, 320, 0);
    glEnd();


//wear drop front-drawer 3 - outer

    glPopMatrix();

    glPushMatrix();


    glTranslatef(0,0,0);
    glScalef(105,95,10);

    glPushMatrix();
    glTranslatef(3.32,4.6,-1);
    glScalef(1,0.1,2);
    cube(62/255.0,43/255.0,45/255.0);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(3.32,5.7,-1);
    glScalef(1,0.1,2);
    cube(62/255.0,43/255.0,45/255.0);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(3.32,3.5,-1);
    glScalef(1,0.1,2);
    cube(62/255.0,43/255.0,45/255.0);
    glPopMatrix();
    glPopMatrix();


//wear drop side

   // cube(62/255.0,43/255.0,35/255.0);
    //glColor3ub (62,43,35);
    glBegin(GL_POLYGON);
    //glVertex3f (470, 670, 0);
    //glVertex3f (500, 667, 0);
    //glVertex3f (492, 657, 0);
    //glVertex3f (492, 330, 0);
    //glVertex3f (460, 320, 0);
    //glVertex3f (460, 660, 0);
    glEnd();

    glPopMatrix();
    glPopMatrix();


}


void drop3()
{

    glPushMatrix();
    glPushMatrix();
//wear drop front
    cube(0.7,0.5,0.4);
    //glColor3ub (113,74,44);
    glBegin(GL_POLYGON);
    glVertex3f (460, 660, 0);
    glVertex3f (470, 670, 0);
    glVertex3f (330, 670,0);
    glVertex3f (340, 660, 0);
    glVertex3f (340, 320, 0);
    glVertex3f (460, 320, 0);
    glEnd();


//wear drop front-drawer 3 - outer

    glPopMatrix();

    glPushMatrix();


    glTranslatef(0,0,0);
    glScalef(105,95,10);

    glPushMatrix();
    glTranslatef(3.32,4.6,-2);
    glScalef(1,0.1,2);
    cube(62/255.0,43/255.0,45/255.0);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(3.32,5.7,-2);
    glScalef(1,0.1,2);
    cube(62/255.0,43/255.0,45/255.0);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(3.32,3.5,-2);
    glScalef(1,0.1,2);
    cube(62/255.0,43/255.0,45/255.0);
    glPopMatrix();
    glPopMatrix();





//wear drop side

    //cube(62/255.0,43/255.0,35/255.0);
   // glColor3ub (62,43,35);
    glBegin(GL_POLYGON);
   // glVertex3f (470, 670, 0);
    //glVertex3f (500, 667, 0);
    //glVertex3f (492, 657, 0);
   // glVertex3f (492, 330, 0);
    //glVertex3f (460, 320, 0);
    //glVertex3f (460, 660, 0);
    glEnd();

    glPopMatrix();
    glPopMatrix();


}



void drop4()
{

    glPushMatrix();
    glPushMatrix();
//wear drop front
    cube(113/255.0,74/255.0,44/255.0);
    //glColor3ub (113,74,44);
    glBegin(GL_POLYGON);
  //  glVertex3f (460, 660, 0);
   // glVertex3f (470, 670, 0);
   // glVertex3f (330, 670,0);
   // glVertex3f (340, 660, 0);
   // glVertex3f (340, 320, 0);
   // glVertex3f (460, 320, 0);
    glEnd();


//wear drop front-drawer 3 - outer

    glPopMatrix();

    glPushMatrix();


    glTranslatef(0,0,0);
    glScalef(105,95,10);

    glPushMatrix();
    glTranslatef(3.32,4.6,-2);
    glScalef(1,0.1,2);
    //cube(62/255.0,43/255.0,45/255.0);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(3.32,5.7,-2);
    glScalef(1,0.1,2);
   // cube(62/255.0,43/255.0,45/255.0);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(3.32,3.5,-2);
    glScalef(1,0.1,2);
  //  cube(62/255.0,43/255.0,45/255.0);
    glPopMatrix();
    glPopMatrix();





//wear drop side

  //  cube(62/255.0,43/255.0,35/255.0);
  //  glColor3ub (62,43,35);
  //  glBegin(GL_POLYGON);
  //  glVertex3f (470, 670, 0);
   // glVertex3f (500, 667, 0);
   // glVertex3f (492, 657, 0);
  //  glVertex3f (492, 330, 0);
   // glVertex3f (460, 320, 0);
   // glVertex3f (460, 660, 0);
    glEnd();

    glPopMatrix();
    glPopMatrix();


}

void drop5()
{

    glPushMatrix();
    glPushMatrix();
//wear drop front
    cube(113/255.0,74/255.0,44/255.0);
    //glColor3ub (113,74,44);
    glBegin(GL_POLYGON);
    glVertex3f (460, 660, 0);
    glVertex3f (470, 670, 0);
    glVertex3f (330, 670,0);
    glVertex3f (340, 660, 0);
    glVertex3f (340, 320, 0);
    glVertex3f (460, 320, 0);
    glEnd();


//wear drop front-drawer 3 - outer

    glPopMatrix();

    glPushMatrix();


    glTranslatef(0,0,0);
    glScalef(105,95,10);

    glPushMatrix();
    glTranslatef(3.32,4.6,-2);
    glScalef(1,0.1,2);
    //cube(62/255.0,43/255.0,45/255.0);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(3.32,5.7,-2);
    glScalef(1,0.1,2);
    //cube(62/255.0,43/255.0,45/255.0);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(3.32,3.5,-2);
    glScalef(1,0.1,2);
    //cube(62/255.0,43/255.0,45/255.0);
    glPopMatrix();
    glPopMatrix();





//wear drop side

    //cube(62/255.0,43/255.0,35/255.0);
   // glColor3ub (62,43,35);
   // glBegin(GL_POLYGON);
  //  glVertex3f (470, 670, 0);
  //  glVertex3f (500, 667, 0);
  //  glVertex3f (492, 657, 0);
   // glVertex3f (492, 330, 0);
   // glVertex3f (460, 320, 0);
    //glVertex3f (460, 660, 0);
    glEnd();

    glPopMatrix();
    glPopMatrix();


}
void weardrop()
{
    glPushMatrix();
//    glTranslatef(0,-0.5,0);



    glTranslatef(9,-7,8);
//glRotatef(rot,0,1,1);
    //glScalef(.04,.022,.03);
    drop2();
    glPopMatrix();
}


void weardrop2()
{
    glPushMatrix();
   // glTranslatef(-42,-7,6.5);


    glTranslatef(-35,-7,1);

   //glTranslatef(9,-7,8);
//glRotatef(rot,0,1,1);
    glScalef(.04,.022,.03);
     drop4();
    glPopMatrix();
}


void weardrop3(){
    glPushMatrix();
//    glTranslatef(0,-0.5,0);



    glTranslatef(9,-7,8);
    //glRotatef(rot,0,1,1);
    glScalef(.04,.022,.03);
    drop3();
    glPopMatrix();
}

void weardrop5(){
    glPushMatrix();
//    glTranslatef(0,-0.5,0);



    glTranslatef(9,-7,8);
    //glRotatef(rot,0,1,1);
    glScalef(.04,.022,.03);
    drop5();
    glPopMatrix();

}

void projector()
{
     glPushMatrix();
    glScalef(2,.7,1.8);
    glTranslatef(-0.43,15,-.4);
    cube(1, 0, 0);
    glPopMatrix();

    glPushMatrix();
    glScalef(.5,3.4,.5);
    glTranslatef(0,3.2,0);
    cube(0.392, 0.3, 0.929);
    glPopMatrix();

    glPushMatrix();
    glScalef(.68,.68,.68);
    glTranslatef(0,15.45,1);
    cube(1,0,1);
    glPopMatrix();

    glPushMatrix();
    glScalef(.60,.60,.60);
    glTranslatef(0.05,17.55,1.4);
    cube(0,0,0);
    glPopMatrix();
}


void projector_board()
{
    glPushMatrix();
    glScalef(6,6,0.1);
    glTranslatef(-0.2,.8,130);
    cube(1, 1, 1);
    glPopMatrix();

}


void AC()
{
    glPushMatrix();
    glScalef(6,2,2);
    glTranslatef(-1.5,6,-10.5);
    cube(.8, .8,.8);
    glPopMatrix();



}

void AC2()
{
    glPushMatrix();
    glScalef(6,2,2);
    glTranslatef(1.5,8,5);
    cube(.8, .8,.8);
    glPopMatrix();



}


void clock1()
{

    glPushMatrix();
//clock outer
    glPushMatrix();
    glScalef(1.5,1.3,1);
    glTranslatef(-220,-200,1);
    cube(0,0,0);
    glBegin(GL_QUADS);
    glVertex3f (680, 800, 0);
    glVertex3f (630, 800, 0);
    glVertex3f (630, 900, 0);
    glVertex3f (680, 900, 0);
    glEnd();

//clock inner
    glPushMatrix();
    glTranslatef(0,0,-.98);
    cube(0.847, 0.749, 0.847);
    glBegin(GL_QUADS);
    glVertex3f (675, 805, 0);
    glVertex3f (635, 805, 0);
    glVertex3f (635, 895, 0);
    glVertex3f (675, 895, 0);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,-2);
////////////////////////////
    glPushMatrix();
    glTranslatef(653,847,1);
    glRotatef(angle1, 0, 0, 1);

    cube(0, 0, 0);
    glRecti(-b, a, b, 3*c);
    glPopMatrix();
    /////////////////////////////
//clock second
    cube(0,0,0);

    glBegin(GL_LINES);
    glVertex3f (655, 850, 0);
    glVertex3f (655, 870, 0);
    glEnd();





//clock hour
    cube(0,0,0);
    glBegin(GL_LINES);

//glBegin(GL_POINT_SIZE);
    glVertex3f (655, 850, 0);
    glVertex3f (645, 810, 0);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}
void clock2()
{


    glPushMatrix();
//    glTranslatef(0,-0.5,0);

    glTranslatef(-60,-20,9);
//glRotatef(rot,0,1,1);
    glScalef(.07,.04,.04);
    clock1();
    glPopMatrix();
}

void fan1()
{
    glPushMatrix();
    glTranslatef(1,-.5,-15);
    fan();
    glPopMatrix();
}


void fan2()
{
    glPushMatrix();
    glTranslatef(20,-.10,-5);
    fan();
    glPopMatrix();
}

void fan3()
{
    glPushMatrix();
    glTranslatef(-15,-.10,-5);
    fan();
    glPopMatrix();
}


float al1,dl1,sl1;
float al2,dl2,sl2;
float al3,dl3,sl3;
void light1(float a,float b,float c)
{
    glEnable(GL_LIGHT0);

    //light
    GLfloat l_no[] = {0, 0, 0, 1.0};
    GLfloat l_amb[] = {0.4+al1, 0.4+al1, 0.4+al1, 1.0};
    GLfloat l_dif[] = {.4+dl1,.4+dl1,.4+dl1,1};
    GLfloat l_spec[] = {.4+sl1,.4+sl1,.4+sl1,1};
    GLfloat l_pos[] = {a,b,c,1.0};

    if(l_on1)
        glLightfv(GL_LIGHT0, GL_AMBIENT, l_amb);
    else
        glLightfv(GL_LIGHT0, GL_AMBIENT, l_no);
    if(l_on1)
        glLightfv(GL_LIGHT0, GL_DIFFUSE, l_dif);
    else
        glLightfv(GL_LIGHT0, GL_DIFFUSE, l_no);
    if(l_on1)
        glLightfv(GL_LIGHT0, GL_SPECULAR, l_spec);
    else
        glLightfv(GL_LIGHT0, GL_SPECULAR, l_no);

    glLightfv(GL_LIGHT0, GL_POSITION, l_pos);


}

void light2(float a,float b,float c)
{
    glEnable(GL_LIGHT2);
    //light
    GLfloat l_no[] = {0, 0, 0, 1.0};
    GLfloat l_amb[] = {0.3+al2, 0.3+al2, 0.3+al2, 1.0};
    GLfloat l_dif[] = {.6+dl2,.6+dl2,.6+dl2,1};
    GLfloat l_spec[] = {5+sl2,5+sl2,5+sl2,1};
    GLfloat l_pos[] = {a,b,c,1.0};

    if(l_on3)
        glLightfv(GL_LIGHT2, GL_AMBIENT, l_amb);
    else
        glLightfv(GL_LIGHT2, GL_AMBIENT, l_no);
    if(l_on3)
        glLightfv(GL_LIGHT2, GL_DIFFUSE, l_dif);
    else
        glLightfv(GL_LIGHT2, GL_DIFFUSE, l_no);
    if(l_on3)
        glLightfv(GL_LIGHT2, GL_SPECULAR, l_spec);
    else
        glLightfv(GL_LIGHT2, GL_SPECULAR, l_no);

    glLightfv(GL_LIGHT2, GL_POSITION, l_pos);
    // GLfloat l_spt[] = {0,-1,0,1};
//    GLfloat spt_ct[] = {66};
//    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, l_spt);
//    glLightfv(GL_LIGHT2, GL_SPOT_CUTOFF, spt_ct);


}

void spot_light(float a,float b,float c)
{
    //light
    glEnable(GL_LIGHT1);

    GLfloat l_no[] = {0, 0, 0, 1.0};
    GLfloat l_amb[] = {1+al3, 0+al3, 0+al3, 1.0};
    GLfloat l_dif[] = {1+dl3,1+dl3,1+dl3,1};
    GLfloat l_spec[] = {1+sl3,1+sl3,1+sl3,1};
    GLfloat l_pos[] = {a,b,c,1.0};

    if(l_on2)
        glLightfv(GL_LIGHT1, GL_AMBIENT, l_amb);
    else
        glLightfv(GL_LIGHT1, GL_AMBIENT, l_no);
    if(l_on2)
        glLightfv(GL_LIGHT1, GL_DIFFUSE, l_dif);
    else
        glLightfv(GL_LIGHT1, GL_DIFFUSE, l_no);
    if(l_on2)
        glLightfv(GL_LIGHT1, GL_SPECULAR, l_spec);
    else
        glLightfv(GL_LIGHT1, GL_SPECULAR, l_no);

    glLightfv(GL_LIGHT1, GL_POSITION, l_pos);
    GLfloat l_spt[] = {0,-1,0,1};
    GLfloat spt_ct[] = {30};
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, l_spt);
    glLightfv(GL_LIGHT1, GL_SPOT_CUTOFF, spt_ct);

}

void window_light(float a,float b,float c)
{
    //light
    glEnable(GL_LIGHT3);

    GLfloat l_no[] = {0, 0, 0, 1.0};
    GLfloat l_amb[] = {.5* window_val, .5* window_val, .5* window_val, 1.0};
    GLfloat l_dif[] = {1* window_val,1* window_val,1* window_val,1};
    GLfloat l_spec[] = {1* window_val,1* window_val,1* window_val,1};
    GLfloat l_pos[] = {a,b,c,1.0};

    if(l_on4)
        glLightfv(GL_LIGHT3, GL_AMBIENT, l_amb);
    else
        glLightfv(GL_LIGHT3, GL_AMBIENT, l_no);
    if(l_on4)
        glLightfv(GL_LIGHT3, GL_DIFFUSE, l_dif);
    else
        glLightfv(GL_LIGHT3, GL_DIFFUSE, l_no);
    if(l_on4)
        glLightfv(GL_LIGHT3, GL_SPECULAR, l_spec);
    else
        glLightfv(GL_LIGHT3, GL_SPECULAR, l_no);

    glLightfv(GL_LIGHT3, GL_POSITION, l_pos);
    GLfloat l_spt[] = {0,-1,0,1};
    GLfloat spt_ct[] = {84};
    glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, l_spt);
    glLightfv(GL_LIGHT3, GL_SPOT_CUTOFF, spt_ct);

}


void light()
{

//light 1

    glPushMatrix();
    glPushMatrix();

    glRotatef(200, 0,1,0);
    float a=-5,b=16,c=9;
    light1(a,b,c);
    glPopMatrix();
    glTranslatef(a,b+1,c);
    glScalef(0.1,0.1,0.1);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.8,0.5,0.5,1);
    glPopMatrix();
    // cout<<l_height<<" "<<spt_cutoff<<endl;

//light2

    glPushMatrix();
    glPushMatrix();

    glRotatef(200, 0,1,0);
    a=15,b=17,c=-15;
    light2(a,b,c);
    glPopMatrix();
    glTranslatef(a,b+1,c);
    glScalef(0.1,0.1,0.1);
    glTranslatef(1,-0.5,-0.5);
    cube(1,1,1,2);
    glPopMatrix();


    //spot light
    glPushMatrix();
    glPushMatrix();
    glRotatef(-95, 0,1,0);
    a=15,b=30,c=-15;
    spot_light(a,b,c);

    glPopMatrix();
    glTranslatef(a,b+1,c);
    glScalef(0.1,0.1,0.1);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(1,1,1,true);
    glPopMatrix();


    //window light
    glPushMatrix();
    glPushMatrix();
    glRotatef(0, 0,1,0);
    a=35,b=15,c=-10;
   // window_light(a,b,c);

    glPopMatrix();
    glTranslatef(a,b+1,c);
    glScalef(0.1,0.1,0.1);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(1,1,1,true);
    glPopMatrix();
    // cout<<sl2<<endl;
    //  cout<<window_val<<endl;
    // cout<<l_height<<" "<<spt_cutoff<<endl;
}


void window()
{
    glPushMatrix();
    glPushMatrix();
//    glTranslatef(0,-0.5,0);
    glScalef(1,8,15);
    glTranslatef(28,.5,-1);
   // glColor4f(1.0, 1.0, 1.0, 0.5); // The fourth parameter (alpha) controls transparency
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,1);
    cube2(1, 1, 1, 0.1, 2, 1);  // Adjust the alpha value as needed
    glBindTexture(GL_TEXTURE_2D,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_BLEND);

    glPushMatrix();
//    glTranslatef(0,-0.5,0);
    glScalef(1,8,.2);
    glTranslatef(28,.5,-76);
   // glColor4f(1.0, 1.0, 1.0, 0.5); // Use glColor4f for RGBA with alpha
   // glEnable(GL_BLEND);
   // glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,1);
    cube(1,.59,.0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
   // glDisable(GL_BLEND);
       // Rotate the door based on the door_angle
    glRotatef(door_angle, 0, 1, 0);

    // Draw the door components
    glPushMatrix();
   // glEnable(GL_BLEND);
   // glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   // glEnable(GL_TEXTURE_2D);
   // glBindTexture(GL_TEXTURE_2D,1);
    glScalef(1, 0.2, 15);
    glTranslatef(27.9, 50, -1);
    cube(0, 0, 0);
    glPopMatrix();
   // glDisable(GL_TEXTURE_2D);
   // glDisable(GL_BLEND);

    glPushMatrix();
    //glEnable(GL_BLEND);
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);   // glEnable(GL_TEXTURE_2D);
  //  glBindTexture(GL_TEXTURE_2D,1);
    glScalef(1, 0.2, 15);
    glTranslatef(27.9, 30, -1);
    cube(0, 0, 0);
    glPopMatrix();
    //glDisable(GL_TEXTURE_2D);
   // glDisable(GL_BLEND);

    for (int i = 0; i >= -75; i -= 2)
    {
        glPushMatrix();
       // glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
      //  glEnable(GL_TEXTURE_2D);
       // glBindTexture(GL_TEXTURE_2D,1);
        glScalef(1, 8, .2);
        glTranslatef(27.9, .5, i);
        cube(0, 0, 0);
        glPopMatrix();
       // glDisable(GL_TEXTURE_2D);
        //glDisable(GL_BLEND);
    }

    glPopMatrix();

    light();
}

void windows()
{
    glPushMatrix();
    window();
    glPopMatrix();

    glPushMatrix();
    glRotatef(180,0,1,0);
   // window();
    glPopMatrix();
}



void room1(){
 // glEnable(GL_LIGHTING);
   // lightOne();
    //lightTwo();
   // lampLight();
   // glViewport(0, 0, 800, 600);


   // lightBulb1();
  //  lightBulb2();
    //lightBulb3();
   // glDisable(GL_LIGHTING);


    /*eyeX, eyeY, eyeZ Specifies the position of the eye point.
    centerX, centerY, centerZ Specifies the position of the reference point.
    upX, upY, upZ Specifies the direction of the up vector.
    */
    //  glViewport(0, 0, width, height);

    //axes();
  //  cse();
   // table();
    //flr();
    //wall1();


    wall2();
    wall3();
    glPushMatrix();
    glTranslatef(-.7,0,-41);
    wall3();
    glPopMatrix();
    headwall();

   // fan();
//    test();
   // window();
    //clock1();




    glPushMatrix();
    glTranslatef(1,0,-40);
    clock2();
    glPopMatrix();



    glPushMatrix();
    glScalef(5.2,1.2,2.2);
    glTranslatef(-5.3,0,25);
    glRotatef(90.0, 0.0, 1.0, 0.0);
    //weardrop3();
    glPopMatrix();


    glPushMatrix();
    glScalef(5.2,1.2,2.2);
    glTranslatef(-5.3,0,20);
    glRotatef(90.0, 0.0, 1.0, 0.0);
  //  weardrop3();
    glPopMatrix();

    glPushMatrix();
    glScalef(3.2,1.2,2.2);
    glTranslatef(-24.5,0,-5.5);
    //glRotatef(-90.0, 0.0, 1.0, 0.0);
   // glRotatef(-90.0, 0.0, 1.0, 0.0);
  //  weardrop3();
    glPopMatrix();


    light();
//projector();
//AC();
    glPushMatrix();
    glTranslatef(-60,0,0);
    AC2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-60,0,-42);
    AC2();
    glPopMatrix();


//projector_board();


    //  glTranslatef(1,-.5,-15);
    //
    //cout<<eyeX<<" "<<eyeY<<" "<<eyeZ<<" "<<centerX<<" "<<centerY<<" "<<centerZ<<" "<<rot<<endl;
//cout<<rot<<endl;
}

void room2(){
 // glEnable(GL_LIGHTING);
   // lightOne();
    //lightTwo();
   // lampLight();
   // glViewport(0, 0, 800, 600);


   // lightBulb1();
  //  lightBulb2();
    //lightBulb3();
   // glDisable(GL_LIGHTING);


    /*eyeX, eyeY, eyeZ Specifies the position of the eye point.
    centerX, centerY, centerZ Specifies the position of the reference point.
    upX, upY, upZ Specifies the direction of the up vector.
    */
    //  glViewport(0, 0, width, height);


    glPushMatrix();
    glTranslatef(10,0,-15);
    glRotatef(90.0, 0.0, 1.0, 0.0);
   // door2();
    glPopMatrix();

    glPushMatrix();
	glTranslatef(-70,-0.5,0);
    //glRotatef(90.0, 0.0, 1.0, 0.0);
    wall2();
    glPopMatrix();

    glPushMatrix();
	glTranslatef(-34,0,0);
    //glRotatef(90.0, 0.0, 1.0, 0.0);
    wall3();
    glPopMatrix();

    glPushMatrix();
	glTranslatef(-36,0,0);
    //glRotatef(90.0, 0.0, 1.0, 0.0);
    door();
    glPopMatrix();

    glPushMatrix();
	glTranslatef(-36,0,-0.5);
    //glRotatef(90.0, 0.0, 1.0, 0.0);
    headwall();
    glPopMatrix();


    glPushMatrix();
   // clock2();
    glPopMatrix();

    glPushMatrix();
    glScalef(5.2,1.2,2.2);
    glTranslatef(-5.3,0,25);
    glRotatef(90.0, 0.0, 1.0, 0.0);
   // weardrop3();
    glPopMatrix();

    light();

}

void room3(){
 // glEnable(GL_LIGHTING);
   // lightOne();
    //lightTwo();
   // lampLight();
   // glViewport(0, 0, 800, 600);


   // lightBulb1();
  //  lightBulb2();
    //lightBulb3();
   // glDisable(GL_LIGHTING);


    /*eyeX, eyeY, eyeZ Specifies the position of the eye point.
    centerX, centerY, centerZ Specifies the position of the reference point.
    upX, upY, upZ Specifies the direction of the up vector.
    */
    //  glViewport(0, 0, width, height);


    glPushMatrix();
    glTranslatef(10,0,-15);
    glRotatef(90.0, 0.0, 1.0, 0.0);
  //  door2();
    glPopMatrix();

    glPushMatrix();
	glTranslatef(-36,-0.5,-36);
    glScalef(1,1,1.27);
    //glRotatef(90.0, 0.0, 1.0, 0.0);
    wall1();
    glPopMatrix();

    glPushMatrix();
	glTranslatef(-0.5,-0.5,-43);
    glScalef(1,1,1.1);
    //glRotatef(90.0, 0.0, 1.0, 0.0);
    wall2();
    glPopMatrix();

    glPushMatrix();
	glTranslatef(1,0,-87);
    //glRotatef(90.0, 0.0, 1.0, 0.0);
    wall3();
    glPopMatrix();

    glPushMatrix();
	glTranslatef(-36,0,-43);
    //glRotatef(90.0, 0.0, 1.0, 0.0);
    door();
    glPopMatrix();

    glPushMatrix();
	glTranslatef(-36,0,-29);
    glScalef(1,1,1.3);
    headwall();
    glPopMatrix();

    glPushMatrix();
	glTranslatef(0,0,-30);
    //glRotatef(90.0, 0.0, 1.0, 0.0);
    glScalef(1,1,1.3);
    headwall();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1,0,-87);
    //clock2();
    glPopMatrix();

    glPushMatrix();
    glScalef(5.2,1.2,2.2);
    glTranslatef(-5.3,0,25);
    glRotatef(90.0, 0.0, 1.0, 0.0);
    //weardrop3();
    glPopMatrix();

    light();

}


void room4(){
 // glEnable(GL_LIGHTING);
   // lightOne();
    //lightTwo();
   // lampLight();
   // glViewport(0, 0, 800, 600);


   // lightBulb1();
  //  lightBulb2();
    //lightBulb3();
   // glDisable(GL_LIGHTING);


    /*eyeX, eyeY, eyeZ Specifies the position of the eye point.
    centerX, centerY, centerZ Specifies the position of the reference point.
    upX, upY, upZ Specifies the direction of the up vector.
    */
    //  glViewport(0, 0, width, height);


    glPushMatrix();
    glTranslatef(10,0,-15);
    glRotatef(90.0, 0.0, 1.0, 0.0);
  //  door2();
    glPopMatrix();

    glPushMatrix();
	glTranslatef(-36,-0.5,-36);
    glScalef(1,1,1.27);
    //glRotatef(90.0, 0.0, 1.0, 0.0);
    wall1();
    glPopMatrix();

    glPushMatrix();
	glTranslatef(-0.5,-0.5,-43);
    glScalef(1,1,1.1);
    //glRotatef(90.0, 0.0, 1.0, 0.0);
    wall2();
    glPopMatrix();


    //front wall without door
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,1);
	glTranslatef(-12,0,-87);
    //glRotatef(90.0, 0.0, 1.0, 0.0);
    glScalef(1.7,1,1.1);
    wall4();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_BLEND);


    //TopBanner
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,9);
	glTranslatef(-17,20,-87);
    //glRotatef(90.0, 0.0, 1.0, 0.0);
    glScalef(2,1,1.1);
    wall4();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    //glDisable(GL_BLEND);


    glPushMatrix();
	glTranslatef(-36,0,-43);
    //glRotatef(90.0, 0.0, 1.0, 0.0);
  //  wall4();
    glPopMatrix();

    glPushMatrix();
	glTranslatef(-36,0,-32);
    glScalef(1,1,1.3);
    headwall();
    glPopMatrix();

    glPushMatrix();
	glTranslatef(0,0,-32);
    //glRotatef(90.0, 0.0, 1.0, 0.0);
    glScalef(1,1,1.3);
    headwall();
    glPopMatrix();

    glPushMatrix();
    //clock2();
    glPopMatrix();

    glPushMatrix();
    glScalef(5.2,1.2,2.2);
    glTranslatef(-5.3,0,25);
    glRotatef(90.0, 0.0, 1.0, 0.0);
   // weardrop3();
    glPopMatrix();

    light();

}


void room5(){

    //TopBanner
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,1);
	glTranslatef(-17,20,-87);
    glScalef(2,1,1.1);
    wall4();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_BLEND);

    light();

}

void floorWall()
{
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,15);

//    glTranslatef(0,-0.5,0);
    glScalef(37,0.6,53);
    glTranslatef(-0.57,0,-0.7);
    //cube(0.690, 0.769, 0.871,0,4);
    Cube();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

}

void FullHouse(){


    //room1();

    glPushMatrix();
    //glScalef(5.2,1.2,2.2);
    glTranslatef(0,0,70);
    //glRotatef(90.0, 0.0, 1.0, 0.0);
    glScalef(1,1.2,2);
    room1();
    glPopMatrix();

    glPushMatrix();
    glScalef(1,1.2,2);
    glTranslatef(0,0,37);
    room2();
    glPopMatrix();


    glPushMatrix();
    //glTranslatef(-5,0,0);
    glScalef(1,1.2,2);
    glTranslatef(0,0,37);
    room3();
    glPopMatrix();



  //  glPushMatrix();
    //glScalef(5.2,1.2,2.2);
   // glTranslatef(40,0,-0.5);
    //room1();
   // glPopMatrix();

    }


void allFloor(){

//room1
    glPushMatrix();
  //  glTranslatef(0,-19,0);
   glTranslatef(0,0,70);

    glScalef(1,1,1.67);
    //glTranslatef(5.3,31,-25);
    floorWall();
    glPopMatrix();


    //room2

    glPushMatrix();
  //  glTranslatef(0,-19,0);
    //glScalef(1,0.2,1);
    glTranslatef(-36,0,-0.5);
    glScalef(1,1.2,1.8);
    glTranslatef(0,0,42);
    floorWall();
    glPopMatrix();



    //room3

    glPushMatrix();
  //  glTranslatef(0,-19,0);
    //glScalef(1,0.2,1);
    glTranslatef(-16,0,-32);
    glScalef(2,1.2,2);
    glTranslatef(0,0,7);
    floorWall();
    glPopMatrix();


    //room4

    glPushMatrix();
  //  glTranslatef(0,-19,0);
    //glScalef(1,0.2,1);
    glTranslatef(0,0,-32);
    glScalef(1,1.2,2);
    glTranslatef(0,0,7);
    //floorWall();
    glPopMatrix();



}


void topFLoor(){
        glPushMatrix();
        glPushMatrix();
        glTranslatef(0,21,0);
        glScalef(1,1,1);
        room1();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0,21,0);
        glScalef(1,1,1);
        room2();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0,21,0);
        glScalef(1,1,1);
        room4();
        glPopMatrix();
        glPopMatrix();

}


//right wall
void wall11()
{
    glPushMatrix();
//    glTranslatef(0,-0.5,0);
    glScalef(1,20,43);
    glTranslatef(-21,0,-0.7);
    cube2(0, 0, 0, 0.5, 2, 1);  // Adjust the alpha value as needed
    glPopMatrix();
}

//left Wall
void wall12()
{
    glPushMatrix();
	glTranslatef(-14,-0.5,0);
    glScalef(1,20,43);
    glTranslatef(29,0,-0.7);
    cube2(1, 1, 1, 0.5, 2, 1);  // Adjust the alpha value as needed
    glPopMatrix();
}

//behind
void wall13()
{
    glPushMatrix();
//    glTranslatef(0,-0.5,0);
    glScalef(36,20,1);
    glTranslatef(-.55,0,12);
    //cube(0.741, 0.718, 0.420,0,2);
    cube2(1, 1, 1, 0.5, 2, 1);  // Adjust the alpha value as needed

    glPopMatrix();
}


void wall14()
{
    glPushMatrix();
    glScalef(36,20,1);
    glTranslatef(-.55,0,12);
    cube2(1, 1, 1, 0.5, 2, 1);  // Adjust the alpha value as needed
    glPopMatrix();
}


void door15()
{
    //toppart
    glPushMatrix();
    glScalef(30,19,1);
    glTranslatef(-.7,-0,-31);
    cube2(1, 1, 1, 0.5, 2, 1);  // Adjust the alpha value as needed
    glPopMatrix();

   //restHalfPart
    glPushMatrix();
    glScalef(22,7,1);
    glTranslatef(-.3,1.8,-31);
    cube2(1, 1, 1, 0.5, 2, 1);  // Adjust the alpha value as needed
    glPopMatrix();
}

void door21()
{
    //toppart
    glPushMatrix();
    glScalef(37,19,1);
    glTranslatef(-.8,-0,-31);
    cube2(1, 1, 1, 0.5, 2, 1);  // Adjust the alpha value as needed
    glPopMatrix();

   //restHalfPart
    glPushMatrix();
    glScalef(23,7,1);
    glTranslatef(-.3,1.8,-30);
    cube2(1, 1, 1, 0.5, 2, 1);  // Adjust the alpha value as needed
    glPopMatrix();
}



void leftHouse(){

    glPushMatrix();
        glPushMatrix();
            glTranslatef(70,0,0);
            glScalef(0.9,0.9,0.9);
        //room1();
            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,12);
            wall12();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,12);
            wall13();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,1);
            door15();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,12);
            headwall();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


        glPopMatrix();
//--------------------------------------------------------------------------------
        glPushMatrix();
            glTranslatef(70,0,0);
            glScalef(0.9,0.9,0.9);
        //room2();
            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,1);
            glTranslatef(10,0,-15);
            glRotatef(90.0, 0.0, 1.0, 0.0);
            door21();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,12);
            glTranslatef(-70,-0.5,0);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            wall12();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,12);
            glTranslatef(-34,0,0);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            wall13();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,1);
            glTranslatef(-36,0,0);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            door15();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,12);
            glTranslatef(-36,0,-0.5);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            headwall();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


        glPopMatrix();
//----------------------------------------------------------------------------
        glPushMatrix();
            glTranslatef(70,0,0);
            glScalef(0.9,0.9,0.9);
       // room3();

            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,12);
            glTranslatef(-36,-0.5,-36);
            glScalef(1,1,1.27);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            wall11();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,12);
            glTranslatef(-0.5,-0.5,-43);
            glScalef(1,1,1.1);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            wall12();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,12);
            glTranslatef(-1,0,-87);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            wall13();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,12);
            glTranslatef(-36,0,-43);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            door15();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,12);
            glTranslatef(-36,0,-32);
            glScalef(1,1,1.3);
            headwall();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glTranslatef(0,0,-32);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            glScalef(1,1,1.3);
            headwall();
            glPopMatrix();

        glPopMatrix();

//-----------------------------------------------------------------
        glPushMatrix();
            glTranslatef(70,0,0);
            glScalef(0.9,0.9,0.9);
       // room5();
           //TopBanner
            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,13);
            glTranslatef(-17,20,-87);
            glScalef(2,1,1.1);
            wall14();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);
        glPopMatrix();

    glPopMatrix();



}


void leftHouse2(){

    glPushMatrix();
        glPushMatrix();
            glTranslatef(70,0,0);
            glScalef(0.9,0.9,0.9);
        //room1();
            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,14);
            wall12();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,14);
            wall13();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,11);
            door15();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,14);
            headwall();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


        glPopMatrix();
//--------------------------------------------------------------------------------
        glPushMatrix();
            glTranslatef(70,0,0);
            glScalef(0.9,0.9,0.9);
        //room2();
            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,14);
            glTranslatef(10,0,-15);
            glRotatef(90.0, 0.0, 1.0, 0.0);
            door21();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,14);
            glTranslatef(-70,-0.5,0);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            wall12();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,14);
            glTranslatef(-34,0,0);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            wall13();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,11);
            glTranslatef(-36,0,0);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            door15();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,14);
            glTranslatef(-36,0,-0.5);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            headwall();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


        glPopMatrix();
//----------------------------------------------------------------------------
        glPushMatrix();
            glTranslatef(70,0,0);
            glScalef(0.9,0.9,0.9);
       // room3();

            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,14);
            glTranslatef(-36,-0.5,-36);
            glScalef(1,1,1.27);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            wall11();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,14);
            glTranslatef(-0.5,-0.5,-43);
            glScalef(1,1,1.1);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            wall12();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,14);
            glTranslatef(-1,0,-87);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            wall13();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,14);
            glTranslatef(-36,0,-43);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            door15();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,14);
            glTranslatef(-36,0,-32);
            glScalef(1,1,1.3);
            headwall();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glTranslatef(0,0,-32);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            glScalef(1,1,1.3);
            headwall();
            glPopMatrix();

        glPopMatrix();

//-----------------------------------------------------------------


    glPopMatrix();


}

void left_topFLoor(){
        glPushMatrix();
            glTranslatef(70,0,0);
            glScalef(0.9,0.9,0.9);
        //room1();
            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,14);
            wall12();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,14);
            wall13();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,14);
            door15();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,14);
            headwall();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


        glPopMatrix();
//--------------------------------------------------------------------------------
        glPushMatrix();
            glTranslatef(70,0,0);
            glScalef(0.9,0.9,0.9);
        //room2();
            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,14);
            glTranslatef(10,0,-15);
            glRotatef(90.0, 0.0, 1.0, 0.0);
            door21();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,14);
            glTranslatef(-70,-0.5,0);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            wall12();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,14);
            glTranslatef(-34,0,0);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            wall13();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,11);
            glTranslatef(-36,0,0);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            door15();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,14);
            glTranslatef(-36,0,-0.5);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            headwall();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


        glPopMatrix();
//----------------------------------------------------------------------------

        glPushMatrix();
            glTranslatef(70,0,0);
            glScalef(0.9,0.9,0.9);
        //room4();

            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,14);
            glTranslatef(-36,-0.5,-36);
            glScalef(1,1,1.27);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            wall11();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,14);
            glTranslatef(-0.5,-0.5,-43);
            glScalef(1,1,1.1);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            wall12();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);



            //front wall without door
            glPushMatrix();;
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,14);
            glTranslatef(-17,0,-87);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            glScalef(2,1,1.1);
            wall14();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);






            glPushMatrix();
            glTranslatef(-36,0,-43);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
          //  wall4();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(-36,0,-32);
            glScalef(1,1,1.3);
            headwall();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(0,0,-32);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            glScalef(1,1,1.3);
            headwall();
            glPopMatrix();
        glPopMatrix();




}

void All_leftTop(){

        //TopFloor

    glPushMatrix();
    glTranslatef(70,19,0);
    //glScalef(0.9,0.9,0.9);
    left_topFLoor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(70,38,0);
    //glScalef(0.9,0.9,0.9);
    left_topFLoor();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(70,57,0);
    //glScalef(0.9,0.9,0.9);
    left_topFLoor();
    glPopMatrix();
/*
    glPushMatrix();
    glTranslatef(140,21,-40);
    glScalef(0.9,0.9,0.9);
    left_topFLoor();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(140,42,-40);
    glScalef(0.9,0.9,0.9);
    left_topFLoor();
    glPopMatrix(); */

}

void topDesign(){
        glPushMatrix();
    glTranslatef(-35,7,-40);
    glScalef(3.17,1,1);
    topBoard();
    glPopMatrix();


    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,8);
    glTranslatef(-32,14,-40);
    glScalef(2.7,1,1);
    topBoard();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
    //glEnable(GL_TEXTURE_2D);
   // glBindTexture(GL_TEXTURE_2D,7);
    glTranslatef(-25,14,-47);
    glScalef(0.5,1,1);
    topBoard();
    glPopMatrix();
    //glDisable(GL_TEXTURE_2D);



    glPushMatrix();
    glTranslatef(-35,21,-40);
    glScalef(3.17,1,1);
    topBoard();
    glPopMatrix();
}


void rightHouse2(){

    glPushMatrix();
        glPushMatrix();
            glTranslatef(70,0,0);
            glScalef(0.9,0.9,0.9);
        //room1();
            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,13);
            wall12();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,13);
            wall13();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,13);
            door15();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,13);
            headwall();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


        glPopMatrix();
//--------------------------------------------------------------------------------
        glPushMatrix();
            glTranslatef(70,0,0);
            glScalef(0.9,0.9,0.9);
        //room2();
            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,13);
            glTranslatef(10,0,-15);
            glRotatef(90.0, 0.0, 1.0, 0.0);
            door21();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,13);
            glTranslatef(-70,-0.5,0);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            wall12();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,13);
            glTranslatef(-34,0,0);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            wall13();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,11);
            glTranslatef(-36,0,0);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            door15();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,13);
            glTranslatef(-36,0,-0.5);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            headwall();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


        glPopMatrix();
//----------------------------------------------------------------------------
        glPushMatrix();
            glTranslatef(70,0,0);
            glScalef(0.9,0.9,0.9);
       // room3();

            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,13);
            glTranslatef(-36,-0.5,-36);
            glScalef(1,1,1.27);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            wall11();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,13);
            glTranslatef(-0.5,-0.5,-43);
            glScalef(1,1,1.1);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            wall12();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,13);
            glTranslatef(-1,0,-87);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            wall13();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,13);
            glTranslatef(-36,0,-43);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            door15();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,13);
            glTranslatef(-36,0,-32);
            glScalef(1,1,1.3);
            headwall();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glTranslatef(0,0,-32);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            glScalef(1,1,1.3);
            headwall();
            glPopMatrix();

        glPopMatrix();

//-----------------------------------------------------------------


    glPopMatrix();


}

void right_topFLoor(){
        glPushMatrix();
            glTranslatef(70,0,0);
            glScalef(0.9,0.9,0.9);
        //room1();
            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,13);
            wall12();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,13);
            wall13();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,13);
            door15();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,13);
            headwall();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


        glPopMatrix();
//--------------------------------------------------------------------------------
        glPushMatrix();
            glTranslatef(70,0,0);
            glScalef(0.9,0.9,0.9);
        //room2();
            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,13);
            glTranslatef(10,0,-15);
            glRotatef(90.0, 0.0, 1.0, 0.0);
            door21();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,13);
            glTranslatef(-70,-0.5,0);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            wall12();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,13);
            glTranslatef(-34,0,0);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            wall13();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,11);
            glTranslatef(-36,0,0);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            door15();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,13);
            glTranslatef(-36,0,-0.5);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            headwall();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


        glPopMatrix();
//----------------------------------------------------------------------------

        glPushMatrix();
            glTranslatef(70,0,0);
            glScalef(0.9,0.9,0.9);
        //room4();

            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,13);
            glTranslatef(-36,-0.5,-36);
            glScalef(1,1,1.27);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            wall11();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,13);
            glTranslatef(-0.5,-0.5,-43);
            glScalef(1,1,1.1);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            wall12();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);



            //front wall without door
            glPushMatrix();;
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,13);
            glTranslatef(-17,0,-87);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            glScalef(2,1,1.1);
            wall14();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);






            glPushMatrix();
            glTranslatef(-36,0,-43);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
          //  wall4();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(-36,0,-32);
            glScalef(1,1,1.3);
            headwall();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(0,0,-32);
            //glRotatef(90.0, 0.0, 1.0, 0.0);
            glScalef(1,1,1.3);
            headwall();
            glPopMatrix();
        glPopMatrix();




}

void All_rightTop(){

        //TopFloor

    glPushMatrix();
    glTranslatef(70,19,0);
    //glScalef(0.9,0.9,0.9);
    right_topFLoor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(70,38,0);
    //glScalef(0.9,0.9,0.9);
    right_topFLoor();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(70,57,0);
    //glScalef(0.9,0.9,0.9);
    right_topFLoor();
    glPopMatrix();
/*
    glPushMatrix();
    glTranslatef(140,21,-40);
    glScalef(0.9,0.9,0.9);
    left_topFLoor();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(140,42,-40);
    glScalef(0.9,0.9,0.9);
    left_topFLoor();
    glPopMatrix(); */

}





void sun(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_POLYGON);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.1416 / 180;
        float x = rx * cos(angle);
        float y = ry * sin(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}





void tree(){

    // House Tree
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,11);
    glColor3ub(128, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(50, 150);
    glVertex2d(65, 150);
    glVertex2d(65, 300);
    glVertex2d(50, 300);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    // Tree leaf
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,10);
    glTranslatef(35, 320, 0);  // Adjust the position as needed
    glColor3ub(0, 128, 0);
    sun(30, 40, 0, 0);  // Call the sun function at a specific position
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,10);
    glTranslatef(85, 320, 0);  // Adjust the position as needed
    glColor3ub(0, 128, 0);
    sun(30, 40, 0, 0);  // Call the sun function at a specific position
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,10);
    glTranslatef(45, 370, 0);  // Adjust the position as needed
    glColor3ub(0, 128, 0);
    sun(25, 30, 0, 0);  // Call the sun function at a specific position
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,10);
    glTranslatef(70, 370, 0);  // Adjust the position as needed
    glColor3ub(0, 128, 0);
    sun(30, 30, 0, 0);  // Call the sun function at a specific position
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,10);
    glTranslatef(55, 400, 0);  // Adjust the position as needed
    glColor3ub(0, 128, 0);
    sun(25, 30, 0, 0);  // Call the sun function at a specific position
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    light();

}
void tree2(){

    //center
    //smallTree
    glPushMatrix();
   // glRotatef(45,0,1,0);
    glScalef(0.1,0.1,0.1);
    glTranslatef(-5,-200,-1040);
  //  glRotatef(-90.0, 0.0, 1.0, 0.0);  // Adjust the angle as needed
    tree();
    glPopMatrix();


    //bigTree
    glPushMatrix();
   // glRotatef(45,0,1,0);
    glScalef(0.15,0.15,0.15);
    glTranslatef(40,-150,-550);
  //  glRotatef(-90.0, 0.0, 1.0, 0.0);  // Adjust the angle as needed
    tree();
    glPopMatrix();



    //leftSide

    //smallTree
    glPushMatrix();
   // glRotatef(45,0,1,0);
    glScalef(0.1,0.1,0.1);
    glTranslatef(620,-200,-1040);
  //  glRotatef(-90.0, 0.0, 1.0, 0.0);  // Adjust the angle as needed
    tree();
    glPopMatrix();

    //smallTree
    glPushMatrix();
   // glRotatef(45,0,1,0);
    glScalef(0.1,0.1,0.1);
    glTranslatef(650,-200,-1040);
  //  glRotatef(-90.0, 0.0, 1.0, 0.0);  // Adjust the angle as needed
    tree();
    glPopMatrix();

    //smallTree
    glPushMatrix();
    glScalef(0.1,0.1,0.1);
    glTranslatef(-550,-200,-1040);
    tree();
    glPopMatrix();
    //bigTree
    glPushMatrix();
    glScalef(0.15,0.15,0.15);
    glTranslatef(-500,-150,-550);
    tree();
    glPopMatrix();


    //rightSide

    //smallTree
    glPushMatrix();
    glScalef(0.1,0.1,0.1);
    glTranslatef(500,-200,-1040);
    tree();
    glPopMatrix();
    //bigTree
    glPushMatrix();
    glScalef(0.15,0.15,0.15);
    glTranslatef(500,-150,-550);
    tree();
    glPopMatrix();
}









void table()
{
    float length = .5;
    float height = 3;
    float width= .5;

    glPushMatrix();
    glTranslatef(length/2,0,0);
    glScalef(length*4,height,width);
    glTranslatef(0,0,0);
    cube(0.0,0.0,0.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(length/2,0,0);
    glScalef(length*4,height,width);
    glTranslatef(0,0,0);
    glRotatef(-90.0, 0.0, 0.0, 1.0);  // Adjust the angle as needed
    cube(0,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(length/2,0,0);
    glScalef(length,height,width);
    glTranslatef(0,0,3);
   // cube(0,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(length/2,0,0);
    //glRotatef(90.0, 0.0, 1.0, 0.0);  // Adjust the angle as needed
    glScalef(length*4,height,width);
    glTranslatef(0,0,4);
    cube(0,0,0);
    glPopMatrix();

    glPushMatrix();
    glScalef(length*4,height/6,width*5);
    glTranslatef(0.12,6,0);
    cube(1,.8,.4);
    glPopMatrix();

    //-----------------------stair
        glPushMatrix();
    glTranslatef(length/2,0,0);
    glScalef(length*4,height,width);
    glTranslatef(-1.5,05,38);
    glRotatef(60.0, 0.0, 0.0, 1.0);  // Adjust the angle as needed
   // cube(0,0,0);
    glPopMatrix();

    light();
}
void chair()
{
    float length = .5;
    float height = 2;
    float width= .5;


    glPushMatrix();
    glTranslatef(length/2,0,0);
    glScalef(length,height,width);
    glTranslatef(.5,0,-2);
    cube(1,0.8,0.4);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(length/2,0,0);
    glScalef(length,height,width);
    glTranslatef(3.5,0,-2);
    cube(1,0.8,0.4);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(length/2,0,0);
    glScalef(length,height,width);
    glTranslatef(.5,0,-4);
    cube(1,0.8,0.4);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(length/2,0,0);
    glScalef(length,height,width);
    glTranslatef(3.5,0,-4);
    cube(1,0.8,0.4);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(length/2,0,0);
    glScalef(length*4,height/6,width*4);
    glTranslatef(0.15,6,-1.2);
    cube(1,0.7,0.4);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(length/2,0,0);
    glScalef(length*4,height*1.2,width);
    glTranslatef(.15,1,-5);
    cube(1,0.7,0.4);
    glPopMatrix();

    light();

}

void pc(){
    float length = .5;
    float height = 2;
    float width= .5;

    glPushMatrix();
    glTranslatef(length/2,0,0);
    glScalef(length*4,height*1.2,width);
    glTranslatef(.15,1,-5);
    glScalef(1.2,0.9,0.4);
    //glRotatef(90.0, 0.0, 0.0, 1.0);  // Adjust the angle as needed
    cube(0,0,0);
    glPopMatrix();

}

void full_set()
{
    glPushMatrix();
    glScalef(7.5,1,1.3);
    glTranslatef(0.3,0,0);
    table();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5,0,0);
    chair();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10,0,0);
    chair();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(15,0,0);
    chair();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(15,01,5);
    pc();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(15,1.3,-2);
    glRotatef(90.0, 1.0, 0.0, 0.0);  // Adjust the angle as needed
   // glTranslatef(15,01,5);
    pc();
    glPopMatrix();


}


void allWearDrop(){

    //room1 weardrop1

    glPushMatrix();
    glScalef(5.2,1.5,4);
    glTranslatef(-5.3,0.5,26);
    glRotatef(90.0, 0.0, 1.0, 0.0);
    weardrop3();
    glPopMatrix();

    glPushMatrix();
    glScalef(5.2,1.5,4);
    glTranslatef(-5.3,5,26);
    glRotatef(90.0, 0.0, 1.0, 0.0);
    weardrop3();
    glPopMatrix();


    //room1 weardrop2

    glPushMatrix();
    glScalef(5.2,1.5,4);
    glTranslatef(-5.3,0.5,20);
    glRotatef(90.0, 0.0, 1.0, 0.0);
    weardrop3();
    glPopMatrix();

    glPushMatrix();
    glScalef(5.2,1.5,4);
    glTranslatef(-5.3,5,20);
    glRotatef(90.0, 0.0, 1.0, 0.0);
    weardrop3();
    glPopMatrix();



    //fornt
    glPushMatrix();
    glScalef(5.2,1.5,2.2);
    glTranslatef(-5.5,0.5,-5);
    glRotatef(90.0, 0.0, 1.0, 0.0);
    weardrop3();
    glPopMatrix();

    glPushMatrix();
    glScalef(5.2,1.5,2.2);
    glTranslatef(-5.5,5,-5);
    glRotatef(90.0, 0.0, 1.0, 0.0);
    weardrop3();
    glPopMatrix();

    light();

}

void fridge(){


    //right
    glPushMatrix();
    glEnable(GL_BLEND);
    glScalef(1,20,43);
    glTranslatef(-21,0,-0.7);
    cube(0.5,0.7,0.5);
    glPopMatrix();


    //left
    glPushMatrix();
	glTranslatef(-14,-0.5,0);
    glScalef(1,20,43);
    glTranslatef(29,0,-0.7);
    cube(0.5,0.7,0.5);
    glPopMatrix();


    //behindTexture
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,16);
    glScalef(36,20,1);
    glTranslatef(-.57,0,3);
    cube(0.5,0.7,0.5);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);



    //behind
    glPushMatrix();
    glScalef(36,20,1);
    glTranslatef(-.57,0,13);
    cube(0.5,0.7,0.5);
    glPopMatrix();



       //front
    glPushMatrix();
    glScalef(36,20,1);
    glTranslatef(-.57,0,-30);
    cubeT(1,1,1,0.3);
    glPopMatrix();


    light();
}

void fridgeRight(){


    //right
    glPushMatrix();
    glEnable(GL_BLEND);
    glScalef(1,20,43);
    glTranslatef(-21,0,-0.7);
    cube(0.5,0.7,0.5);
    glPopMatrix();


    //left
    glPushMatrix();
	glTranslatef(-14,-0.5,0);
    glScalef(1,20,43);
    glTranslatef(29,0,-0.7);
    cube(0.5,0.7,0.5);
    glPopMatrix();


    //behindTexture
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,92);
    glScalef(36,20,1);
    glTranslatef(-.57,0,3);
    cube(0.5,0.7,0.5);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);



    //behind
    glPushMatrix();
    glScalef(36,20,1);
    glTranslatef(-.57,0,13);
    cube(0.5,0.7,0.5);
    glPopMatrix();



       //front
    glPushMatrix();
    glScalef(36,20,1);
    glTranslatef(-.57,0,-30);
    cubeT(1,1,1,0.3);
    glPopMatrix();


    light();
}

void reckPart(){
        glPushMatrix();
        glScalef(70,1,85);
        glTranslatef(-0.57,5,-0.7);
        cubeT(0,0,0,1);
        glPopMatrix();

        glPushMatrix();
        glScalef(70,1,85);
        glTranslatef(-0.57,15,-0.7);
        cubeT(0,0,0,1);
        glPopMatrix();

        glPushMatrix();
        glScalef(70,1,85);
        glTranslatef(-0.57,25,-0.7);
        cubeT(0,0,0,1);
        glPopMatrix();


        glPushMatrix();
        glScalef(70,1,85);
        glTranslatef(-0.57,35,-0.7);
        cubeT(0,0,0,1);
        glPopMatrix();

}

void reck(){

    //right
    glPushMatrix();
    glEnable(GL_BLEND);
    glScalef(1,20,43);
    glTranslatef(-21,0,-0.7);
    cube(0.5,0.7,0.5);
    glPopMatrix();

    //left
    glPushMatrix();
	glTranslatef(-14,-0.5,0);
    glScalef(1,20,43);
    glTranslatef(29,0,-0.7);
    cube(0.5,0.7,0.5);
    glPopMatrix();

           //back
    glPushMatrix();
    glScalef(36,20,1);
    glTranslatef(-.57,0,-30);
    //cubeT(1,1,1,0.3);
    cube(0.5,0.7,0.5);
    glPopMatrix();

    //step

    glPushMatrix();
    glScalef(0.5,0.5,0.5);
    //glTranslatef(-.57,0,5);
    reckPart();
    glPopMatrix();


    light();
}


void fullreck(){
    glPushMatrix();
    glScalef(0.8,0.9,0.2);
    glTranslatef(-13,0,120);
    reck();
    glPopMatrix();


}



void reck2(){

    //right
    glPushMatrix();
    glEnable(GL_BLEND);
    glScalef(1,20,80);
    glTranslatef(-21,0,-0.7);
    cube(0.5,0.7,0.5);
    glPopMatrix();

    //left
    glPushMatrix();
	glTranslatef(-14,-0.5,0);
    glScalef(1,20,80);
    glTranslatef(29,0,-0.7);
    cube(0.5,0.7,0.5);
    glPopMatrix();


           //back
    glPushMatrix();
    glScalef(36,20,1);
    glTranslatef(-.57,0,-30);
    //cubeT(1,1,1,0.3);
    cube(0.5,0.7,0.5);
    glPopMatrix();
    //step

    glPushMatrix();
    glScalef(0.5,0.5,1.1);
    //glTranslatef(-.57,0,5);
    reckPart();
    glPopMatrix();


    light();
}


void fullreck2(){
    glPushMatrix();
    glScalef(0.8,0.9,0.2);
    glTranslatef(-13,0,120);
    reck2();
    glPopMatrix();


}


void reckPart3(){
        glPushMatrix();
        glScalef(70,1,85);
        glTranslatef(-0.57,10,-0.7);
        cubeT(0,0,0,1);
        glPopMatrix();


        glPushMatrix();
        glScalef(70,1,85);
        glTranslatef(-0.57,15,-0.7);
       // cubeT(0,0,0,1);
        glPopMatrix();

        glPushMatrix();
        glScalef(70,1,85);
        glTranslatef(-0.57,25,-0.7);
      //  cubeT(0,0,0,1);
        glPopMatrix();


        glPushMatrix();
        glScalef(70,1,85);
        glTranslatef(-0.57,35,-0.7);
       // cubeT(0,0,0,1);
        glPopMatrix();

}

void reck3(){

    //right
    glPushMatrix();
    glEnable(GL_BLEND);
    glScalef(1,5,43);
    glTranslatef(-20,0,-0.7);
    cube(0.5,0.7,0.5);
    glPopMatrix();

    //left
    glPushMatrix();
	glTranslatef(-14,0,0);
    glScalef(1,5,43);
    glTranslatef(29,0,-0.7);
    cube(0.5,0.7,0.5);
    glPopMatrix();

           //back
    glPushMatrix();
    glScalef(36,5,1);
    glTranslatef(-.57,0,-30);
    //cubeT(1,1,1,0.3);
    cube(0.5,0.7,0.5);
    glPopMatrix();


               //front
    glPushMatrix();
    glScalef(36,5,1);
    glTranslatef(-.57,0,11);
    //cubeT(1,1,1,0.3);
    cube(0.5,0.7,0.5);
    glPopMatrix();


    //step

    glPushMatrix();
    glScalef(0.5,0.5,0.5);
    //glTranslatef(-.57,0,5);
    reckPart3();
    glPopMatrix();


    light();
}


void fullreck3(){
    glPushMatrix();
    glScalef(0.8,0.9,0.2);
    glTranslatef(-13,0,120);
    reck3();
    glPopMatrix();


}






static void res(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (float)width / (float)height, 1, 500);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void drawSphere(float radius) {
    float PI = 3.141592f;
    float x, y, z, alpha, beta; // Storage for coordinates and angles
    int gradation = 20;

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 17); // Assuming texture ID 17

    glBegin(GL_TRIANGLE_FAN);

    for (alpha = 0.0f; alpha < PI; alpha += PI / gradation) {
        for (beta = 0.0f; beta < 2.01 * PI; beta += PI / gradation) {
            x = radius * cos(beta) * sin(alpha);
            y = radius * sin(beta) * sin(alpha);
            z = radius * cos(alpha);

            glTexCoord2f(beta / (2.0 * PI), alpha / PI);
            glVertex3f(x, y, z);

            x = radius * cos(beta + PI / gradation) * sin(alpha + PI / gradation);
            y = radius * sin(beta + PI / gradation) * sin(alpha + PI / gradation);
            z = radius * cos(alpha + PI / gradation);

            glTexCoord2f((beta + PI / gradation) / (2.0 * PI), (alpha + PI / gradation) / PI);
            glVertex3f(x, y, z);

            x = radius * cos(beta + PI / gradation) * sin(alpha);
            y = radius * sin(beta + PI / gradation) * sin(alpha);
            z = radius * cos(alpha);

            glTexCoord2f((beta + PI / gradation) / (2.0 * PI), alpha / PI);
            glVertex3f(x, y, z);

            x = radius * cos(beta) * sin(alpha);
            y = radius * sin(beta) * sin(alpha);
            z = radius * cos(alpha);

            glTexCoord2f(beta / (2.0 * PI), alpha / PI);
            glVertex3f(x, y, z);
        }
    }

    glEnd();
    glDisable(GL_TEXTURE_2D);
}



void allhouse(){

    glPushMatrix();
        FullHouse();
        glPopMatrix();

        glPushMatrix();
        topFLoor();
        glPopMatrix();


          glPushMatrix();
    leftHouse();
    glPopMatrix();

    glPushMatrix();
        glPushMatrix();
        glTranslatef(70,0,0);
        leftHouse2();
        glPopMatrix();
        All_leftTop();
    glPopMatrix();


    glPushMatrix();
        glPushMatrix();
        glTranslatef(-160,0,0);
        rightHouse2();
        glPopMatrix();
        glTranslatef(-230,0,0);
        All_rightTop();
    glPopMatrix();

}
void draw_scene() {
    // Define the vertices of the stair steps
    float stepHeight = 1.0f;
    float stepWidth = 1.0f;
    float stepDepth = 1.0f;
    int numSteps = 5;

    // Draw each step
    for (int i = 0; i < numSteps; ++i) {
        glBegin(GL_QUADS);
            glVertex3f(i * stepWidth, 0.0f, -numSteps * stepDepth / 2 + i * stepDepth);
            glVertex3f((i + 1) * stepWidth, 0.0f, -numSteps * stepDepth / 2 + i * stepDepth);
            glVertex3f((i + 1) * stepWidth, stepHeight, -numSteps * stepDepth / 2 + i * stepDepth);
            glVertex3f(i * stepWidth, stepHeight, -numSteps * stepDepth / 2 + i * stepDepth);
        glEnd();
    }
}


void fruitesReck(){



    //frutesReck
    glPushMatrix();
    glScalef(0.4,1.7,0.5);
    glTranslatef(-40,0,38);
    glRotatef(-180,0.0,1,0);
    fullreck3();
    glPopMatrix();

//frutesReck
    glPushMatrix();
    glScalef(0.4,1.1,0.5);
    glTranslatef(-40,0,30);
    glRotatef(-180,0.0,1,0);
    fullreck3();
    glPopMatrix();





    //frutesReck
    glPushMatrix();
    glScalef(0.4,0.6,0.5);
    glTranslatef(-40,0,21);
    glRotatef(-180,0.0,1,0);
    fullreck3();
    glPopMatrix();
}


void allreck(){
    //frontreck
    glPushMatrix();
    glScalef(0.8,1,1);
    glTranslatef(-40,0,0);
    fullreck();
    glPopMatrix();

       //frontreck
    glPushMatrix();
    glScalef(0.8,1,1);
    glTranslatef(-40,0,-60);
   // fullreck();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.8,1,0.6);
    glTranslatef(10,0,5);
    fullreck();
    glPopMatrix();

//left backreck
    glPushMatrix();
    glScalef(0.8,1.3,0.6);
    glTranslatef(-22,0,180);
    glRotatef(-180,0.0,1,0);
    fullreck();
    glPopMatrix();



    glPushMatrix();
    glScalef(0.8,1.3,0.6);
    glTranslatef(-53,0,180);
    glRotatef(-180,0.0,1,0);
    fullreck();
    glPopMatrix();

    //back1
    glPushMatrix();
    glScalef(0.8,1,1);
    glTranslatef(35,0,85);
    glRotatef(-90,0.0,1,0);
    fullreck();
    glPopMatrix();

    //back2
    glPushMatrix();
    glScalef(0.8,1,1);
    glTranslatef(35,0,55);
    glRotatef(-90,0.0,1,0);
    fullreck();
    glPopMatrix();

    //back3
    glPushMatrix();
    glScalef(0.8,1,0.5);
    glTranslatef(35,0,55);
    glRotatef(-90,0.0,1,0);
    fullreck();
    glPopMatrix();

    //right backreck
    glPushMatrix();
    glScalef(0.8,1.3,0.6);
    glTranslatef(-85,0,120);
    glRotatef(-270,0.0,1,0);
   // fullreck();
    glPopMatrix();

    //right1

    glPushMatrix();
    glScalef(0.8,1,1);
    glTranslatef(-85,0,60);
    glRotatef(-90,0.0,1,0);
    glRotatef(-180,0.0,1,0);
    fullreck();
    glPopMatrix();

    //right2

    glPushMatrix();
    glScalef(0.8,1,1);
    glTranslatef(-85,0,30);
    glRotatef(-90,0.0,1,0);
    glRotatef(-180,0.0,1,0);
    fullreck();
    glPopMatrix();


       //right3

    glPushMatrix();
    glScalef(0.8,1,1);
    glTranslatef(-85,0,-30);
    glRotatef(-90,0.0,1,0);
    glRotatef(-180,0.0,1,0);
    fullreck();
    glPopMatrix();

       //right4

    glPushMatrix();
    glScalef(0.8,1,1);
    glTranslatef(-85,0,-70);
    glRotatef(-90,0.0,1,0);
    glRotatef(-180,0.0,1,0);
    fullreck();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4,1,0.6);
    glTranslatef(-130,0,-30);
    glRotatef(90,0.0,1,.0);
  //  fullreck2();
    glPopMatrix();

    //draw_scene();



    glPushMatrix();
    glScalef(0.4,0.9,0.2);
    glTranslatef(-3,0,55);
    fridge();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.5,0.9,0.2);
    glTranslatef(-83,0,55);
    fridgeRight();
    glPopMatrix();

}

void apple(){

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,17);
    glTranslatef(-37,16,48);
    glRotatef(180,1,0,0);
    glRotatef(90,0,1,0);
    sphere(0.4,10,10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

}


void allapple(){

//row1

    glPushMatrix();
    glTranslatef(-3.2,-0.2,0);
    apple();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.4,-0.2,0);
    apple();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.6,-0.2,0);
    apple();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.8,-0.2,0);
    apple();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-0.2,0);
    apple();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8,-0.2,0);
    apple();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.6,-0.2,0);
    apple();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.2,-0.2,0);
    apple();
    glPopMatrix();


    //row2

    glPushMatrix();
    glTranslatef(-2.8,0.5,0);
    apple();
    glPopMatrix();
    glPushMatrix();

    glTranslatef(-2.0,0.5,0);
    apple();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.2,0.5,0);
    apple();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4,0.5,0);
    apple();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4,0.5,0);
    apple();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.2,0.5,0);
    apple();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2,0.5,0);
    apple();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.8,0.5,0);
    //apple();
    glPopMatrix();


    //row3
    glPushMatrix();
    glTranslatef(-2.4,1.2,0);
    apple();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.6,1.2,0);
    apple();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.8,1.2,0);
    apple();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1.2,0);
    apple();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8,1.2,0);
    apple();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.6,1.2,0);
    apple();
    glPopMatrix();


    //row4
    glPushMatrix();
    glTranslatef(-2,1.9,0);
    apple();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.2,1.9,0);
    apple();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4,1.9,0);
    apple();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4,1.9,0);
    apple();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.2,1.9,0);
    apple();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2,1.9,0);
   // apple();
    glPopMatrix();


    //row5
    glPushMatrix();
    glTranslatef(-1.6,2.6,0);
    apple();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.8,2.6,0);
    apple();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,2.6,0);
    apple();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8,2.6,0);
    apple();
    glPopMatrix();


    //row6
    glPushMatrix();
    glTranslatef(-1.2,3.3,0);
    apple();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4,3.3,0);
    apple();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4,3.3,0);
    apple();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.2,3.3,0);
   // apple();
    glPopMatrix();

}

void guava(){

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,21);
    glTranslatef(-37,16,48);
    glRotatef(180,1,0,0);
    glRotatef(90,0,1,0);
    sphere(0.4,11,11);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

}


void allguava(){

//row1

    glPushMatrix();
    glTranslatef(-3.2,-0.2,0);
    guava();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.4,-0.2,0);
    guava();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.6,-0.2,0);
    guava();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.8,-0.2,0);
    guava();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-0.2,0);
    guava();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8,-0.2,0);
    guava();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.6,-0.2,0);
    guava();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.2,-0.2,0);
    guava();
    glPopMatrix();


    //row2

    glPushMatrix();
    glTranslatef(-2.8,0.5,0);
    guava();
    glPopMatrix();
    glPushMatrix();

    glTranslatef(-2.0,0.5,0);
    guava();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.2,0.5,0);
    guava();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4,0.5,0);
    guava();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4,0.5,0);
    guava();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.2,0.5,0);
    guava();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2,0.5,0);
    guava();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.8,0.5,0);
    //apple();
    glPopMatrix();


    //row3
    glPushMatrix();
    glTranslatef(-2.4,1.2,0);
    guava();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.6,1.2,0);
    guava();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.8,1.2,0);
    guava();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1.2,0);
    guava();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8,1.2,0);
    guava();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.6,1.2,0);
    guava();
    glPopMatrix();


    //row4
    glPushMatrix();
    glTranslatef(-2,1.9,0);
    guava();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.2,1.9,0);
    guava();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4,1.9,0);
    guava();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4,1.9,0);
    guava();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.2,1.9,0);
    guava();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2,1.9,0);
   // apple();
    glPopMatrix();


    //row5
    glPushMatrix();
    glTranslatef(-1.6,2.6,0);
    guava();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.8,2.6,0);
    guava();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,2.6,0);
    guava();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8,2.6,0);
    guava();
    glPopMatrix();


    //row6
    glPushMatrix();
    glTranslatef(-1.2,3.3,0);
    guava();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4,3.3,0);
    guava();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4,3.3,0);
    guava();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.2,3.3,0);
   // apple();
    glPopMatrix();

}



void orange(){

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,18);
    glTranslatef(-37,16,48);
    glRotatef(180,1,0,0);
    glRotatef(90,0,1,0);
    sphere(0.4,10,10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

}


void allorange(){

//row1

    glPushMatrix();
    glTranslatef(-3.2,-0.2,0);
    orange();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.4,-0.2,0);
    orange();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.6,-0.2,0);
    orange();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.8,-0.2,0);
    orange();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-0.2,0);
    orange();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8,-0.2,0);
    orange();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.6,-0.2,0);
    orange();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.2,-0.2,0);
    orange();
    glPopMatrix();


    //row2

    glPushMatrix();
    glTranslatef(-2.8,0.5,0);
    orange();
    glPopMatrix();
    glPushMatrix();

    glTranslatef(-2.0,0.5,0);
    orange();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.2,0.5,0);
    orange();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4,0.5,0);
    orange();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4,0.5,0);
    orange();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.2,0.5,0);
    orange();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2,0.5,0);
    orange();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.8,0.5,0);
    //apple();
    glPopMatrix();


    //row3
    glPushMatrix();
    glTranslatef(-2.4,1.2,0);
    orange();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.6,1.2,0);
    orange();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.8,1.2,0);
    orange();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1.2,0);
    orange();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8,1.2,0);
    orange();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.6,1.2,0);
    orange();
    glPopMatrix();


    //row4
    glPushMatrix();
    glTranslatef(-2,1.9,0);
    orange();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.2,1.9,0);
    orange();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4,1.9,0);
    orange();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4,1.9,0);
    orange();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.2,1.9,0);
    orange();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2,1.9,0);
   // apple();
    glPopMatrix();


    //row5
    glPushMatrix();
    glTranslatef(-1.6,2.6,0);
    orange();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.8,2.6,0);
    orange();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,2.6,0);
    orange();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8,2.6,0);
    orange();
    glPopMatrix();


    //row6
    glPushMatrix();
    glTranslatef(-1.2,3.3,0);
    orange();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4,3.3,0);
    orange();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4,3.3,0);
    orange();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.2,3.3,0);
   // apple();
    glPopMatrix();

}


void grapes(){

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,22);
    glTranslatef(-37,16,48);
    glRotatef(180,1,0,0);
    glRotatef(90,0,1,0);
    glRotatef(-120,0,0,1);
    sphere(0.4,15,15);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

}
void allgrapes(){

//row1

    glPushMatrix();
    glTranslatef(-3.2,3.3,0);
   // grapes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.4,3.3,0);
   // grapes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.6,3.3,0);
    grapes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.8,3.3,0);
    grapes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,3.3,0);
    grapes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8,3.3,0);
    grapes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.6,3.3,0);
   // grapes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.2,3.3,0);
   // grapes();
    glPopMatrix();


    //row2

    glPushMatrix();
    glTranslatef(-2.8,0.5,0);
   // grapes();
    glPopMatrix();
    glPushMatrix();

    glTranslatef(-2.0,0.5,0);
    grapes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.2,0.5,0);
    grapes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4,0.5,0);
    grapes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4,0.5,0);
    grapes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.2,0.5,0);
    grapes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2,0.5,0);
   // grapes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.8,0.5,0);
    //apple();
    glPopMatrix();


    //row3
    glPushMatrix();
    glTranslatef(-2.4,1.2,0);
    grapes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.6,1.2,0);
    grapes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.8,1.2,0);
    grapes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1.2,0);
    grapes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8,1.2,0);
    grapes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.6,1.2,0);
    grapes();
    glPopMatrix();


    //row4
    glPushMatrix();
    glTranslatef(-2,1.9,0);
    grapes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.2,1.9,0);
    grapes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4,1.9,0);
    grapes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4,1.9,0);
    grapes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.2,1.9,0);
    grapes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2,1.9,0);
   // apple();
    glPopMatrix();


    //row5
    glPushMatrix();
    glTranslatef(-1.6,2.6,0);
    grapes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.8,2.6,0);
    grapes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,2.6,0);
    grapes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8,2.6,0);
    grapes();
    glPopMatrix();


    //row6
    glPushMatrix();
    glTranslatef(-1.2,-0.2,0);
    grapes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4,-0.2,0);
    grapes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4,-0.2,0);
    grapes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.2,-0.2,0);
   // apple();
    glPopMatrix();

}



void drawCylinder(float radius, float height, int segments) {
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= segments; ++i) {
        float theta = (2.0f * M_PI * i) / segments;
        float x = radius * cos(theta);
        float z = radius * sin(theta);

        glVertex3f(x, 0.0, z);
        glVertex3f(x, height, z);
    }
    glEnd();
}

void begun() {
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,19);
    glTranslatef(-37,16,48);
    glRotatef(180,1,0,0);
    glRotatef(90,0,1,0);
    sphere(0.4,10,10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void allbegun(){


//row1

    glPushMatrix();
    glScalef(0.5,1,0.5);
    glTranslatef(-3.2,-0.2,0);
   // begun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.4,-0.2,0);
    begun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.6,-0.2,0);
    begun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.8,-0.2,0);
    begun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-0.2,0);
    begun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8,-0.2,0);
    begun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.6,-0.2,0);
    begun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.2,-0.2,0);
    begun();
    glPopMatrix();


    //row2

    glPushMatrix();
    glTranslatef(-2.8,0.5,0);
    begun();
    glPopMatrix();
    glPushMatrix();

    glTranslatef(-2.0,0.5,0);
    begun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.2,0.5,0);
    begun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4,0.5,0);
    begun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4,0.5,0);
    begun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.2,0.5,0);
    begun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2,0.5,0);
    begun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.8,0.5,0);
    //apple();
    glPopMatrix();


    //row3
    glPushMatrix();
    glTranslatef(-2.4,1.2,0);
    begun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.6,1.2,0);
    begun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.8,1.2,0);
    begun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1.2,0);
    begun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8,1.2,0);
    begun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.6,1.2,0);
    begun();
    glPopMatrix();


    //row4
    glPushMatrix();
    glTranslatef(-2,1.9,0);
    begun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.2,1.9,0);
    begun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4,1.9,0);
    begun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4,1.9,0);
    begun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.2,1.9,0);
    begun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2,1.9,0);
    begun();
    glPopMatrix();


    //row5
    glPushMatrix();
    glTranslatef(-1.6,2.6,0);
    begun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.8,2.6,0);
    begun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,2.6,0);
    begun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8,2.6,0);
    begun();
    glPopMatrix();


    //row6
    glPushMatrix();
    glTranslatef(-1.2,3.3,0);
    begun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4,3.3,0);
    begun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4,3.3,0);
    begun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.2,3.3,0);
    begun();
    glPopMatrix();

}

void tomato() {
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,20);
    glTranslatef(-37,16,48);
    glRotatef(180,1,0,0);
    glRotatef(90,0,1,0);
    sphere(0.4,10,10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void alltomato(){

//row1

    glPushMatrix();
    glScalef(0.5,1,0.5);
    glTranslatef(-3.2,-0.2,0);
   // begun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.4,-0.2,0);
    tomato();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.6,-0.2,0);
    tomato();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.8,-0.2,0);
    tomato();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-0.2,0);
    tomato();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8,-0.2,0);
    tomato();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.6,-0.2,0);
    tomato();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.2,-0.2,0);
    tomato();
    glPopMatrix();


    //row2

    glPushMatrix();
    glTranslatef(-2.8,0.5,0);
    tomato();
    glPopMatrix();
    glPushMatrix();

    glTranslatef(-2.0,0.5,0);
    tomato();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.2,0.5,0);
    tomato();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4,0.5,0);
    tomato();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4,0.5,0);
    tomato();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.2,0.5,0);
    tomato();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2,0.5,0);
    tomato();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.8,0.5,0);
    //apple();
    glPopMatrix();


    //row3
    glPushMatrix();
    glTranslatef(-2.4,1.2,0);
    tomato();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.6,1.2,0);
    tomato();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.8,1.2,0);
    tomato();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1.2,0);
    tomato();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8,1.2,0);
    tomato();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.6,1.2,0);
    tomato();
    glPopMatrix();


    //row4
    glPushMatrix();
    glTranslatef(-2,1.9,0);
    tomato();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.2,1.9,0);
    tomato();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4,1.9,0);
    tomato();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4,1.9,0);
    tomato();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.2,1.9,0);
    tomato();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2,1.9,0);
    tomato();
    glPopMatrix();


    //row5
    glPushMatrix();
    glTranslatef(-1.6,2.6,0);
    tomato();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.8,2.6,0);
    tomato();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,2.6,0);
    tomato();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8,2.6,0);
    tomato();
    glPopMatrix();


    //row6
    glPushMatrix();
    glTranslatef(-1.2,3.3,0);
    tomato();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4,3.3,0);
    tomato();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4,3.3,0);
    tomato();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.2,3.3,0);
    tomato();
    glPopMatrix();

}


void cucumber() {
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,5);
    glTranslatef(-37,16,48);
    glRotatef(180,1,0,0);
  //  glRotatef(-45,0,0,1);
  //  glRotatef(90,0,1,0);
    sphere(0.4,8,13);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void allcucumber(){

//row1

    glPushMatrix();
    glScalef(5,5,5);
    glTranslatef(-3.2,-0.2,0);
   // begun();
    glPopMatrix();

    glPushMatrix();
    glScalef(1,4,1);
    glTranslatef(-2.4,-0.2,0);
   // cucumber();
    glPopMatrix();

    glPushMatrix();
    glScalef(1,4,1);
    glTranslatef(-1.6,-0.2,0);
    cucumber();
    glPopMatrix();

    glPushMatrix();
    glScalef(1,4,1);
    glTranslatef(-0.8,-0.2,0);
    cucumber();
    glPopMatrix();

    glPushMatrix();
    glScalef(1,4,1);
    glTranslatef(0,-0.2,0);
    cucumber();
    glPopMatrix();

    glPushMatrix();
    glScalef(1,4,1);
    glTranslatef(0.8,-0.2,0);
    cucumber();
    glPopMatrix();

    glPushMatrix();
    glScalef(1,4,1);
    glTranslatef(1.6,-0.2,0);
    cucumber();
    glPopMatrix();

    glPushMatrix();
    glScalef(1,4,1);
    glTranslatef(2.2,-0.2,0);
    cucumber();
    glPopMatrix();

    glPushMatrix();
    glScalef(1,4,1);
    glTranslatef(3,-0.25,0);
    cucumber();
    glPopMatrix();

    glPushMatrix();
    glScalef(1,4,1);
    glTranslatef(3.8,-0.25,0);
    cucumber();
    glPopMatrix();






}

void cucumber2() {
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,21);
    glTranslatef(-37,16,48);
    glRotatef(180,1,0,0);
  //  glRotatef(-45,0,0,1);
  //  glRotatef(90,0,1,0);
    sphere(0.4,8,13);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void allcucumber2(){

//row1

    glPushMatrix();
    glScalef(5,5,5);
    glTranslatef(-3.2,-0.2,0);
   // begun();
    glPopMatrix();

    glPushMatrix();
    glScalef(1,4,1);
    glTranslatef(-2.4,-0.2,0);
    cucumber2();
    glPopMatrix();

    glPushMatrix();
    glScalef(1,4,1);
    glTranslatef(-1.6,-0.2,0);
    cucumber2();
    glPopMatrix();

    glPushMatrix();
    glScalef(1,4,1);
    glTranslatef(-0.8,-0.2,0);
    cucumber2();
    glPopMatrix();

    glPushMatrix();
    glScalef(1,4,1);
    glTranslatef(0,-0.2,0);
    cucumber2();
    glPopMatrix();

    glPushMatrix();
    glScalef(1,4,1);
    glTranslatef(0.8,-0.2,0);
    cucumber2();
    glPopMatrix();

    glPushMatrix();
    glScalef(1,4,1);
    glTranslatef(1.6,-0.2,0);
    cucumber2();
    glPopMatrix();

    glPushMatrix();
    glScalef(1,4,1);
    glTranslatef(2.2,-0.2,0);
   // cucumber2();
    glPopMatrix();



}

void grapesGroup(){


    //grapeRow1

        glPushMatrix();
    glTranslatef(-25,3,50);
    glScalef(2.7,4.4,0.7);
    glScalef(0.1,0.1,0.1);
    //glTranslatef(-5,5,-15);
    allgrapes();
    glPopMatrix();

            glPushMatrix();
    glTranslatef(-26,3,50);
    glScalef(2.7,4.4,0.7);
    glScalef(0.1,0.1,0.1);
    //glTranslatef(-5,5,-15);
    allgrapes();
    glPopMatrix();

                glPushMatrix();
    glTranslatef(-27,3,50);
    glScalef(2.7,4.4,0.7);
    glScalef(0.1,0.1,0.1);
    //glTranslatef(-5,5,-15);
    allgrapes();
    glPopMatrix();

                    glPushMatrix();
    glTranslatef(-28,3,50);
    glScalef(2.7,4.4,0.7);
    glScalef(0.1,0.1,0.1);
    //glTranslatef(-5,5,-15);
    allgrapes();
    glPopMatrix();

                        glPushMatrix();
    glTranslatef(-29,3,50);
    glScalef(2.7,4.4,0.7);
    glScalef(0.1,0.1,0.1);
    //glTranslatef(-5,5,-15);
   // allgrapes();
    glPopMatrix();


    //grapeRow2

        glPushMatrix();
    glTranslatef(-25.5,3,49);
    glScalef(2.7,4.4,0.7);
    glScalef(0.1,0.1,0.1);
    //glTranslatef(-5,5,-15);
    allgrapes();
    glPopMatrix();

            glPushMatrix();
    glTranslatef(-26.5,3,49);
    glScalef(2.7,4.4,0.7);
    glScalef(0.1,0.1,0.1);
    //glTranslatef(-5,5,-15);
    allgrapes();
    glPopMatrix();

                glPushMatrix();
    glTranslatef(-27.5,3,49);
    glScalef(2.7,4.4,0.7);
    glScalef(0.1,0.1,0.1);
    //glTranslatef(-5,5,-15);
    allgrapes();
    glPopMatrix();

                    glPushMatrix();
    glTranslatef(-28.5,3,49);
    glScalef(2.7,4.4,0.7);
    glScalef(0.1,0.1,0.1);
    //glTranslatef(-5,5,-15);
    allgrapes();
    glPopMatrix();

                        glPushMatrix();
    glTranslatef(-29.5,3,49);
    glScalef(2.7,4.4,0.7);
    glScalef(0.1,0.1,0.1);
    //glTranslatef(-5,5,-15);
    //allgrapes();
    glPopMatrix();


    //grapeRow3

            glPushMatrix();
    glTranslatef(-25.5,3,48);
    glScalef(2.7,4.4,0.7);
    glScalef(0.1,0.1,0.1);
    //glTranslatef(-5,5,-15);
    allgrapes();
    glPopMatrix();

            glPushMatrix();
    glTranslatef(-26.5,3,48);
    glScalef(2.7,4.4,0.7);
    glScalef(0.1,0.1,0.1);
    //glTranslatef(-5,5,-15);
    allgrapes();
    glPopMatrix();

                glPushMatrix();
    glTranslatef(-27.5,3,48);
    glScalef(2.7,4.4,0.7);
    glScalef(0.1,0.1,0.1);
    //glTranslatef(-5,5,-15);
    allgrapes();
    glPopMatrix();

                    glPushMatrix();
    glTranslatef(-28.5,3,48);
    glScalef(2.7,4.4,0.7);
    glScalef(0.1,0.1,0.1);
    //glTranslatef(-5,5,-15);
    allgrapes();
    glPopMatrix();

                        glPushMatrix();
    glTranslatef(-29.5,3,48);
    glScalef(2.7,4.4,0.7);
    glScalef(0.1,0.1,0.1);
    //glTranslatef(-5,5,-15);
   // allgrapes();
    glPopMatrix();


    //grapeRow4

                glPushMatrix();
    glTranslatef(-25.5,2.5,47);
    glScalef(2.7,4.4,0.7);
    glScalef(0.1,0.1,0.1);
    //glTranslatef(-5,5,-15);
    allgrapes();
    glPopMatrix();

            glPushMatrix();
    glTranslatef(-26.5,2.5,47);
    glScalef(2.7,4.4,0.7);
    glScalef(0.1,0.1,0.1);
    //glTranslatef(-5,5,-15);
    allgrapes();
    glPopMatrix();

                glPushMatrix();
    glTranslatef(-27.5,2.5,47);
    glScalef(2.7,4.4,0.7);
    glScalef(0.1,0.1,0.1);
    //glTranslatef(-5,5,-15);
    allgrapes();
    glPopMatrix();

                    glPushMatrix();
    glTranslatef(-28.5,2.5,47);
    glScalef(2.7,4.4,0.7);
    glScalef(0.1,0.1,0.1);
    //glTranslatef(-5,5,-15);
    allgrapes();
    glPopMatrix();

                        glPushMatrix();
    glTranslatef(-29.5,2.5,47);
    glScalef(2.7,4.4,0.7);
    glScalef(0.1,0.1,0.1);
    //glTranslatef(-5,5,-15);
   // allgrapes();
    glPopMatrix();


        //grapeRow5

                glPushMatrix();
    glTranslatef(-24.5,3.5,51);
    glScalef(2.7,4.4,0.7);
    glScalef(0.1,0.1,0.1);
    //glTranslatef(-5,5,-15);
    allgrapes();
    glPopMatrix();

            glPushMatrix();
    glTranslatef(-25.5,3.5,51);
    glScalef(2.7,4.4,0.7);
    glScalef(0.1,0.1,0.1);
    //glTranslatef(-5,5,-15);
    allgrapes();
    glPopMatrix();

                glPushMatrix();
    glTranslatef(-26.5,3.5,51);
    glScalef(2.7,4.4,0.7);
    glScalef(0.1,0.1,0.1);
    //glTranslatef(-5,5,-15);
    allgrapes();
    glPopMatrix();

                    glPushMatrix();
    glTranslatef(-27.5,3.5,51);
    glScalef(2.7,4.4,0.7);
    glScalef(0.1,0.1,0.1);
    //glTranslatef(-5,5,-15);
    allgrapes();
    glPopMatrix();

                        glPushMatrix();
    glTranslatef(-28.5,3.5,51);
    glScalef(2.7,4.4,0.7);
    glScalef(0.1,0.1,0.1);
    //glTranslatef(-5,5,-15);
   // allgrapes();
    glPopMatrix();


            //grapeRow6

                glPushMatrix();
    glTranslatef(-24.5,3.5,52);
    glScalef(2.7,4.4,0.7);
    glScalef(0.1,0.1,0.1);
    //glTranslatef(-5,5,-15);
    allgrapes();
    glPopMatrix();

            glPushMatrix();
    glTranslatef(-25.5,3.5,52);
    glScalef(2.7,4.4,0.7);
    glScalef(0.1,0.1,0.1);
    //glTranslatef(-5,5,-15);
    allgrapes();
    glPopMatrix();

                glPushMatrix();
    glTranslatef(-26.5,3.5,52);
    glScalef(2.7,4.4,0.7);
    glScalef(0.1,0.1,0.1);
    //glTranslatef(-5,5,-15);
    allgrapes();
    glPopMatrix();

                    glPushMatrix();
    glTranslatef(-27.5,3.5,52);
    glScalef(2.7,4.4,0.7);
    glScalef(0.1,0.1,0.1);
    //glTranslatef(-5,5,-15);
    allgrapes();
    glPopMatrix();

                        glPushMatrix();
    glTranslatef(-28.5,3.5,52);
    glScalef(2.7,4.4,0.7);
    glScalef(0.1,0.1,0.1);
    //glTranslatef(-5,5,-15);
    allgrapes();
    glPopMatrix();
}

void cabage(){

    glPushMatrix();
  //  glEnable(GL_TEXTURE_2D);
   // glBindTexture(GL_TEXTURE_2D,23);
    glTranslatef(-37,16,48);
    glRotatef(180,1,0,0);
    glRotatef(90,0,1,0);
    Cube();
    glPopMatrix();
   // glDisable(GL_TEXTURE_2D);

}


void allcabage(){

//row1
    glScalef(1,1,0.5);
    glTranslatef(-0,-0.2,92);


//---------------------------------------------


//-------------------------------------------------
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,23);
    glScalef(7,6,4);
    glTranslatef(35,-12.5,-24);
    cabage();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,23);
    glScalef(7,6,4);
    glTranslatef(34.5,-12.5,-24);
    cabage();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
//----------------------------------------------
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,25);
    glScalef(7,6,4);
    glTranslatef(36,-12.5,-24.2);
    cabage();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,25);
    glScalef(7,6,4);
    glTranslatef(36.5,-12.5,-24.2);
    cabage();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //-----------------------------------fulkopy
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,24);
    glScalef(7,6,4);
    glTranslatef(33,-12.5,-24);
    cabage();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,24);
    glScalef(7,6,4);
    glTranslatef(32.5,-12.5,-24);
   // cabage();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,24);
    glScalef(7,6,4);
    glTranslatef(32,-12.5,-24);
    cabage();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

        glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,24);
    glScalef(7,6,4);
   // glTranslatef(31.5,-12.5,-24);
    cabage();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,24);
    glScalef(7,6,4);
    glTranslatef(31,-12.5,-24);
    cabage();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);



    //------------------------------------------------------------row2

       glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,23);
    glScalef(7,6,4);
    glTranslatef(35,-12.5,-24);
    cabage();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,23);
    glScalef(7,6,4);
    glTranslatef(34.5,-12.5,-24);
    cabage();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
//----------------------------------------------
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,25);
    glScalef(7,6,4);
    glTranslatef(36,-12.5,-24.2);
    cabage();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,25);
    glScalef(7,6,4);
    glTranslatef(36.5,-12.5,-24.2);
    cabage();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //-----------------------------------shim
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,26);
    glScalef(7,6,4);
    glTranslatef(33,-13.5,-24);
    cabage();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,26);
    glScalef(7,6,4);
    glTranslatef(32,-13.5,-24);
    cabage();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,26);
    glScalef(7,6,4);
    glTranslatef(31,-13.5,-24);
    cabage();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

        //-----------------------------------chili

            glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,27);
    glScalef(7,6,4);
    glTranslatef(36.5,-13.5,-24);
    cabage();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,27);
    glScalef(7,6,4);
    glTranslatef(36,-13.5,-24);
    cabage();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,27);
    glScalef(7,6,4);
    glTranslatef(35,-13.5,-24);
    cabage();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,27);
    glScalef(7,6,4);
    glTranslatef(34.5,-13.5,-24);
    cabage();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

        //-----------------------------------carrot

            glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,28);
    glScalef(7,6,4);
    glTranslatef(36.5,-14.5,-24);
    cabage();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,28);
    glScalef(7,6,4);
    glTranslatef(36,-14.5,-24);
    cabage();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,28);
    glScalef(7,6,4);
    glTranslatef(35,-14.5,-24);
    cabage();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,28);
    glScalef(7,6,4);
    glTranslatef(34.5,-14.5,-24);
    cabage();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

           //-----------------------------------cap2

            glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,29);
    glScalef(7,6,4);
    glTranslatef(33,-14.5,-24);
    cabage();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,29);
    glScalef(7,6,4);
    glTranslatef(32,-14.5,-24);
    cabage();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,29);
    glScalef(7,6,4);
    glTranslatef(31,-14.5,-24);
    cabage();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,29);
    glScalef(7,6,4);
    glTranslatef(30,-14.5,-24);
  //  cabage();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


}


void allFruits(){
     glPushMatrix();
   // glScalef(0.3,0.9,0.2);
    glTranslatef(-2,0,55);
    fruitesReck();
            glPushMatrix();
            //frutesReck
        glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,30);
        glScalef(0.4,1,0.5);
        glTranslatef(-40,2,38);
        glRotatef(-180,0.0,1,0);
       // fullreck3();
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);

        glPopMatrix();
    glPopMatrix();


    glPushMatrix();
   // glScalef(0.3,0.9,0.2);
    glTranslatef(-19,0,55);
    fruitesReck();
            glPushMatrix();
            //frutesReck
        glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,31);
        glScalef(0.4,1,0.5);
        glTranslatef(-40,2,38);
        glRotatef(-180,0.0,1,0);
       // fullreck3();
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);

        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(7,-52,-3.4);
        glPushMatrix();
        //glScalef(0.1,0.5,1);
        glTranslatef(17.4,-4,15.5);
       // glRotatef(180, 1,0,0);
        //glRotatef(60, 0,1,0);
        allcucumber();
        glPopMatrix();

        glPushMatrix();
        //glScalef(0.1,0.5,1);
        glTranslatef(14,-4,15);
       // glRotatef(180, 1,0,0);
        //glRotatef(60, 0,1,0);
        allcucumber2();
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(8,-53,-3.2);
        glPushMatrix();
        //glScalef(0.1,0.5,1);
        glTranslatef(17.4,-4,15.5);
       // glRotatef(180, 1,0,0);
        //glRotatef(60, 0,1,0);
        allcucumber();
        glPopMatrix();

        glPushMatrix();
        //glScalef(0.1,0.5,1);
        glTranslatef(14,-4,15);
       // glRotatef(180, 1,0,0);
        //glRotatef(60, 0,1,0);
        allcucumber2();
        glPopMatrix();
    glPopMatrix();


    glPushMatrix();
        glPushMatrix();
        glTranslatef(27,-13,8);
        allbegun();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(27,-14,7);
        allbegun();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(27,-14,6);
       // allbegun();
        glPopMatrix();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(21,-13,7.5);
    alltomato();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(22,-14,8);
    alltomato();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(10,-10.5,11);
    allapple();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10,-11.5,10);
    allapple();
    glPopMatrix();




    glPushMatrix();
    glTranslatef(10,-13,8);
    allguava();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10,-14,7);
    allguava();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5,-10,11);
    allorange();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5,-11,10);
    allorange();
    glPopMatrix();
//-------------------------------------------------------------------
    glPushMatrix();
    glTranslatef(4,-7,1.7);

    grapesGroup();
    glPopMatrix();

    glPushMatrix();
   // glTranslatef(4,-7,0);
    allcabage();
    glPopMatrix();

}
void reckAngle(){
       //angle
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,17);

    glScalef(36,5,1);
    glTranslatef(-.57,0,11);
    //cubeT(1,1,1,0.3);
    glRotatef(70,1,0,0);
    cube(0.5,0.7,0.5);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);



}

void glass(){
      glPushMatrix();
     glEnable(GL_TEXTURE_2D);
      glBindTexture(GL_TEXTURE_2D,32);
      glTranslatef(0.5,1.9,3);
      glScalef(0.3, 1.7, 0.08);
     // cubeColor(1,0, 0,0.6, 0.3, 0.7, 10);
     Cube();
      glPopMatrix();
     glDisable(GL_TEXTURE_2D);


      //showpiece on 3rd shelf left 2
      glPushMatrix();
        glEnable(GL_TEXTURE_2D);
      glBindTexture(GL_TEXTURE_2D,32);
      glTranslatef(0.7,1.9,3);
      glScalef(0.3, 0.8, 0.08);
     Cube();
      glPopMatrix();
        glDisable(GL_TEXTURE_2D);


      }

      void allglasses(){

            glPushMatrix();
       glTranslatef(-15,-1, 5);
       glScalef(3,2,3);
       glass();
       glPopMatrix();
                   glPushMatrix();
       glTranslatef(-13.5,-1, 5);
       glScalef(3,2,3);
       glass();
       glPopMatrix();
            glPushMatrix();
       glTranslatef(-12,-1, 5);
       glScalef(3,2,3);
       glass();
       glPopMatrix();

            glPushMatrix();
       glTranslatef(-10.5,-1, 5);
       glScalef(3,2,3);
       glass();
       glPopMatrix();

        glPushMatrix();
       glTranslatef(-9,-1, 5);
       glScalef(3,2,3);
       glass();
       glPopMatrix();

              glPushMatrix();
       glTranslatef(-7.5,-1, 5);
       glScalef(3,2,3);
       glass();
       glPopMatrix();

                glPushMatrix();
       glTranslatef(-6,-1, 5);
       glScalef(3,2,3);
       glass();
       glPopMatrix();

        glPushMatrix();
       glTranslatef(-4.5,-1, 5);
       glScalef(3,2,3);
       glass();
       glPopMatrix();

        glPushMatrix();
       glTranslatef(-3,-1, 5);
       glScalef(3,2,3);
       glass();
       glPopMatrix();

             glPushMatrix();
       glTranslatef(-1.5,-1, 5);
       glScalef(3,2,3);
       glass();
       glPopMatrix();

        glPushMatrix();
       glTranslatef(0,-1, 5);
       glScalef(3,2,3);
       glass();
       glPopMatrix();


            glPushMatrix();
       glTranslatef(1.5,-1, 5);
       glScalef(3,2,3);
       glass();
       glPopMatrix();

            glPushMatrix();
       glTranslatef(3,-1, 5);
       glScalef(3,2,3);
       glass();
       glPopMatrix();

            glPushMatrix();
       glTranslatef(4.5,-1, 5);
       glScalef(3,2,3);
       glass();
       glPopMatrix();
      }

void bottle(){
      glPushMatrix();
     glEnable(GL_TEXTURE_2D);
      glBindTexture(GL_TEXTURE_2D,32);
      glTranslatef(0.5,1.9,3);
      glScalef(0.3, 1.7, 0.08);
     // cubeColor(1,0, 0,0.6, 0.3, 0.7, 10);
     Cube();
      glPopMatrix();
     glDisable(GL_TEXTURE_2D);


      //showpiece on 3rd shelf left 2
      glPushMatrix();
        glEnable(GL_TEXTURE_2D);
      glBindTexture(GL_TEXTURE_2D,32);
      glTranslatef(0.7,1.9,3);
      glScalef(0.3, 0.8, 0.08);
     //Cube();
      glPopMatrix();
        glDisable(GL_TEXTURE_2D);


      }

    void allbottle(){

            glPushMatrix();
       glTranslatef(-12.0,-1, 5);
       glScalef(3,2,3);
       bottle();
       glPopMatrix();
                   glPushMatrix();
       glTranslatef(-10.8,-1, 5);
       glScalef(3,2,3);
       bottle();
       glPopMatrix();
            glPushMatrix();
       glTranslatef(-9.6,-1, 5);
       glScalef(3,2,3);
       bottle();
       glPopMatrix();

            glPushMatrix();
       glTranslatef(-8.4,-1, 5);
       glScalef(3,2,3);
       bottle();
       glPopMatrix();

        glPushMatrix();
       glTranslatef(-7.2,-1, 5);
       glScalef(3,2,3);
       bottle();
       glPopMatrix();

              glPushMatrix();
       glTranslatef(-6.0,-1, 5);
       glScalef(3,2,3);
       bottle();
       glPopMatrix();

                glPushMatrix();
       glTranslatef(-4.8,-1, 5);
       glScalef(3,2,3);
       bottle();
       glPopMatrix();

        glPushMatrix();
       glTranslatef(-3.6,-1, 5);
       glScalef(3,2,3);
       bottle();
       glPopMatrix();

        glPushMatrix();
       glTranslatef(-2.4,-1, 5);
       glScalef(3,2,3);
       bottle();
       glPopMatrix();

             glPushMatrix();
       glTranslatef(-1.2,-1, 5);
       glScalef(3,2,3);
       bottle();
       glPopMatrix();

        glPushMatrix();
       glTranslatef(0,-1, 5);
       glScalef(3,2,3);
       bottle();
       glPopMatrix();


            glPushMatrix();
       glTranslatef(1.2,-1, 5);
       glScalef(3,2,3);
       bottle();
       glPopMatrix();

            glPushMatrix();
       glTranslatef(2.4,-1, 5);
       glScalef(3,2,3);
      // bottle();
       glPopMatrix();

            glPushMatrix();
       glTranslatef(3.6,-1, 5);
       glScalef(3,2,3);
      // bottle();
       glPopMatrix();
      }

void masala(){
    glPushMatrix();
  //  glEnable(GL_TEXTURE_2D);
   // glBindTexture(GL_TEXTURE_2D,23);
    glTranslatef(-37,16,48);
   // glRotatef(180,1,0,0);
   //glRotatef(-90,0,1,0);
    Cube();
    glPopMatrix();
   // glDisable(GL_TEXTURE_2D);

      }

void  allmasala(){


    glScalef(0.3,0.5,0.5);
    glTranslatef(-0,-6.5,-70);


//---------------------------------------------


//-------------------------------------------------chips
                   glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,33);
   // glRotatef(90, 0,0,1);
    glScalef(7,6,4);
    glTranslatef(34,-12.5,-24);
    masala();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,33);
   // glRotatef(90, 0,0,1);
    glScalef(7,6,4);
    glTranslatef(35,-12.5,-24);
    masala();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

       glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,33);
   // glRotatef(90, 0,0,1);
    glScalef(7,6,4);
    glTranslatef(36,-12.5,-24);
    masala();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

           glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,33);
   // glRotatef(90, 0,0,1);
    glScalef(7,6,4);
    glTranslatef(37,-12.5,-24);
    masala();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);



    //chips2

    glPushMatrix();
            glTranslatef(22,0,0);

            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,34);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(35,-12.5,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,34);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(36,-12.5,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                   glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,34);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(37,-12.5,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

    glPopMatrix();


        //chips3

    glPushMatrix();
            glTranslatef(-30,0,0);

            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,35);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(35,-12.5,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,35);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(36,-12.5,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                   glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,35);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(37,-12.5,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

    glPopMatrix();

    //masalaAll

    glPushMatrix();
                glTranslatef(0,-9,0);


        //-------------------------------------------------chips
                glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,56);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(34,-12.5,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,57);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(35,-12.5,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,58);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(36,-12.5,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                   glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,59);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(37,-12.5,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);



            //chips2

            glPushMatrix();
                    glTranslatef(22,0,0);

                    glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,60);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(35,-12.5,-24);
                    masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

                       glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,61);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(36,-12.5,-24);
                    masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

                           glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,62);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(37,-12.5,-24);
                    masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

            glPopMatrix();


                //chips3

            glPushMatrix();
                    glTranslatef(-30,0,0);

                    glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,56);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(35,-12.5,-24);
                    masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

                       glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,57);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(36,-12.5,-24);
                    masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

                           glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,58);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(37,-12.5,-24);
                    masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

            glPopMatrix();


    glPopMatrix();

//---------------------------------------------rightAchar

        glPushMatrix();
                    glScalef(1,1.2,1);
                    glTranslatef(-130,-4,9);


                //-------------------------------------------------chips
            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,86);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(34,-12.5,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,87);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(35,-12.5,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,88);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(36,-12.5,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                   glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,89);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(37,-12.5,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);



            //chips2

            glPushMatrix();
                    glTranslatef(22,0,0);

                    glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,90);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(35,-12.5,-24);
                    masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

                       glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,91);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(36,-12.5,-24);
                    masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

                           glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,86);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(37,-12.5,-24);
                    masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

            glPopMatrix();


                //chips3

            glPushMatrix();
                    glTranslatef(-30,0,0);

                    glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,87);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(35,-12.5,-24);
                    masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

                       glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,88);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(36,-12.5,-24);
                    masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

                           glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,89);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(37,-12.5,-24);
                    masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

            glPopMatrix();

        glPopMatrix();

//---------------------------------------------------
//---------------------------------------------rightAchar

        glPushMatrix();
                    glScalef(1,1.2,1);
                    glTranslatef(-130,4,9);


                //-------------------------------------------------chips
            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,86);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(34,-12.5,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,87);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(35,-12.5,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,88);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(36,-12.5,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                   glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,89);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(37,-12.5,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);



            //chips2

            glPushMatrix();
                    glTranslatef(22,0,0);

                    glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,90);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(35,-12.5,-24);
                    masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

                       glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,91);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(36,-12.5,-24);
                    masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

                           glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,86);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(37,-12.5,-24);
                    masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

            glPopMatrix();


                //chips3

            glPushMatrix();
                    glTranslatef(-30,0,0);

                    glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,87);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(35,-12.5,-24);
                    masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

                       glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,88);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(36,-12.5,-24);
                    masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

                           glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,89);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(37,-12.5,-24);
                    masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

            glPopMatrix();

        glPopMatrix();

//---------------------------------------------------


            //noodles1

    glPushMatrix();
            glTranslatef(-30,0,0);

            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,36);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(35,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,36);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(36,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                   glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,36);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(37,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

    glPopMatrix();


                //noodles2

    glPushMatrix();
            glTranslatef(-9,0,0);

            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,37);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(35,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,37);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(36,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                   glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,37);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(37,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

    glPopMatrix();

                    //noodles3

    glPushMatrix();
            glTranslatef(11,0,0);

            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,38);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(35,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,38);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(36,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                   glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,38);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(37,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


                               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,38);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(38,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

    glPopMatrix();


    //------------------------------------------Toys

        glPushMatrix();
            glTranslatef(-65,0,105);
            glRotatef(90, 0,1,0);
           // glScalef(3,3,3);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,39);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(35,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,40);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(36,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                   glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,41);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(37,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


                               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,42);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(38,-11,-24);
           // masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

    glPopMatrix();

       //------------------------------------------Toys1

        glPushMatrix();
            glTranslatef(-65,-9,105);
            glRotatef(90, 0,1,0);
           // glScalef(3,3,3);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,52);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(35,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,53);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(36,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                   glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,48);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(37,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


                               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,49);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(38,-11,-24);
           // masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

    glPopMatrix();

       //------------------------------------------Toys1__1

        glPushMatrix();
            glTranslatef(-65,-18,105);
            glRotatef(90, 0,1,0);
           // glScalef(3,3,3);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,55);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(35,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,54);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(36,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                   glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,48);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(37,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


                               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,54);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(38,-11,-24);
           // masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

    glPopMatrix();




    //------------------------------------------Toys2

        glPushMatrix();
            glTranslatef(-65,0,127);
            glRotatef(90, 0,1,0);
           // glScalef(3,3,3);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,43);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(35,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,44);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(36,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                   glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,45);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(37,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


                               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,46);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(38,-11,-24);
           // masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

    glPopMatrix();

    //------------------------------------------Toys3

        glPushMatrix();
            glTranslatef(-65,0,148);
            glRotatef(90, 0,1,0);
           // glScalef(3,3,3);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,47);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(35,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,48);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(36,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                   glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,49);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(37,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


                               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,50);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(38,-11,-24);
           // masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

    glPopMatrix();

    //------------------------------------------Toys4

        glPushMatrix();
            glTranslatef(-65,0,171);
            glRotatef(90, 0,1,0);
           // glScalef(3,3,3);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,51);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(35,-11,-24);
           // masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,52);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(36,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                   glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,53);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(37,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


                               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,39);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(38,-11,-24);
           // masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

    glPopMatrix();


    //row2
    //------------------------------------------Toys2


                    glPushMatrix();
                    glTranslatef(-65,-9,127);
                    glRotatef(90, 0,1,0);
                   // glScalef(3,3,3);


                    glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,40);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(35,-11,-24);
                    masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

                       glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,41);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(36,-11,-24);
                    masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

                           glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,42);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(37,-11,-24);
                    masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);


                                       glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,43);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(38,-11,-24);
                   // masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

            glPopMatrix();

            //------------------------------------------Toys3

                glPushMatrix();
                    glTranslatef(-65,-9,148);
                    glRotatef(90, 0,1,0);
                   // glScalef(3,3,3);


                    glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,44);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(35,-11,-24);
                    masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

                       glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,45);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(36,-11,-24);
                    masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

                           glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,46);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(37,-11,-24);
                    masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);


                                       glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,47);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(38,-11,-24);
                   // masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

            glPopMatrix();

            //------------------------------------------Toys4

                glPushMatrix();
                    glTranslatef(-65,-9,171);
                    glRotatef(90, 0,1,0);
                   // glScalef(3,3,3);


                    glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,48);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(35,-11,-24);
                    //masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

                       glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,49);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(36,-11,-24);
                    masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

                           glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,50);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(37,-11,-24);
                    masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);


                                       glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,51);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(38,-11,-24);
                   // masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

            glPopMatrix();


              //row2
    //------------------------------------------Toyslast


                    glPushMatrix();
                    glTranslatef(-65,-18,127);
                    glRotatef(90, 0,1,0);
                   // glScalef(3,3,3);


                    glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,63);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(35,-11,-24);
                    masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

                       glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,64);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(36,-11,-24);
                    masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

                           glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,65);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(37,-11,-24);
                    masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);


                                       glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,66);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(38,-11,-24);
                   // masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

            glPopMatrix();

            //------------------------------------------Toys3

                glPushMatrix();
                    glTranslatef(-65,-18,148);
                    glRotatef(90, 0,1,0);
                   // glScalef(3,3,3);


                    glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,67);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(35,-11,-24);
                    masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

                       glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,68);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(36,-11,-24);
                    masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

                           glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,69);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(37,-11,-24);
                    masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);


                                       glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,70);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(38,-11,-24);
                   // masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

            glPopMatrix();

            //------------------------------------------Toys4

                glPushMatrix();
                    glTranslatef(-65,-18,171);
                    glRotatef(90, 0,1,0);
                   // glScalef(3,3,3);


                    glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,70);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(35,-11,-24);
                    //masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

                       glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,70);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(36,-11,-24);
                    masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

                           glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,65);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(37,-11,-24);
                    masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);


                                       glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,66);
                   // glRotatef(90, 0,0,1);
                    glScalef(7,6,4);
                    glTranslatef(38,-11,-24);
                   // masala();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

            glPopMatrix();


        //PLateGlass//------------------------------------------------------------PLateGlass

            glPushMatrix();
                    glTranslatef(0,0,60);


    //------------------------------------------Toys2

                    glPushMatrix();
                        glTranslatef(-65,0,127);
                        glRotatef(90, 0,1,0);
                       // glScalef(3,3,3);


                        glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,71);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(35,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                           glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,72);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(36,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                               glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,73);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(37,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);


                                           glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,46);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(38,-11,-24);
                       // masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                glPopMatrix();

                //------------------------------------------Toys3

                    glPushMatrix();
                        glTranslatef(-65,0,148);
                        glRotatef(90, 0,1,0);
                       // glScalef(3,3,3);


                        glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,74);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(35,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                           glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,75);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(36,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                               glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,76);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(37,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);


                                           glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,50);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(38,-11,-24);
                       // masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                glPopMatrix();

                //------------------------------------------Toys4

                    glPushMatrix();
                        glTranslatef(-65,0,171);
                        glRotatef(90, 0,1,0);
                       // glScalef(3,3,3);


                        glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,51);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(35,-11,-24);
                       // masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                           glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,77);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(36,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                               glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,78);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(37,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);


                                           glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,39);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(38,-11,-24);
                       // masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                glPopMatrix();


                //row2
                //------------------------------------------Toys2


                                glPushMatrix();
                                glTranslatef(-65,-9,127);
                                glRotatef(90, 0,1,0);
                               // glScalef(3,3,3);


                                glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,79);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(35,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,80);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(36,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                       glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,81);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(37,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);


                                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,43);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(38,-11,-24);
                               // masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                        glPopMatrix();

                        //------------------------------------------Toys3

                            glPushMatrix();
                                glTranslatef(-65,-9,148);
                                glRotatef(90, 0,1,0);
                               // glScalef(3,3,3);


                                glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,82);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(35,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,81);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(36,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                       glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,80);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(37,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);


                                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,47);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(38,-11,-24);
                               // masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                        glPopMatrix();

                        //------------------------------------------Toys4

                            glPushMatrix();
                                glTranslatef(-65,-9,171);
                                glRotatef(90, 0,1,0);
                               // glScalef(3,3,3);


                                glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,48);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(35,-11,-24);
                                //masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,80);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(36,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                       glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,71);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(37,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);


                                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,72);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(38,-11,-24);
                               // masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                        glPopMatrix();


                          //row2
                //------------------------------------------Toyslast


                                glPushMatrix();
                                glTranslatef(-65,-18,127);
                                glRotatef(90, 0,1,0);
                               // glScalef(3,3,3);


                                glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,72);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(35,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,73);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(36,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                       glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,74);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(37,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);


                                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,66);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(38,-11,-24);
                               // masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                        glPopMatrix();

                        //------------------------------------------Toys3

                            glPushMatrix();
                                glTranslatef(-65,-18,148);
                                glRotatef(90, 0,1,0);
                               // glScalef(3,3,3);


                                glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,83);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(35,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,84);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(36,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                       glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,85);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(37,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);


                                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,70);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(38,-11,-24);
                               // masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                        glPopMatrix();

                        //------------------------------------------Toys4

                            glPushMatrix();
                                glTranslatef(-65,-18,171);
                                glRotatef(90, 0,1,0);
                               // glScalef(3,3,3);


                                glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,71);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(35,-11,-24);
                                //masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,71);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(36,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                       glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,72);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(37,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);


                                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,66);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(38,-11,-24);
                               // masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                        glPopMatrix();
            glPopMatrix();



        //leftFruites//------------------------------------------------------------leftFruites

            glPushMatrix();
                    glTranslatef(-200,0,60);


    //------------------------------------------Toys2

                    glPushMatrix();
                        glTranslatef(-65,0,127);
                        glRotatef(90, 0,1,0);
                       // glScalef(3,3,3);


                        glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,71);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(35,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                           glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,72);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(36,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                               glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,73);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(37,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);


                                           glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,46);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(38,-11,-24);
                       // masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                glPopMatrix();

                //------------------------------------------Toys3

                    glPushMatrix();
                        glTranslatef(-65,0,148);
                        glRotatef(90, 0,1,0);
                       // glScalef(3,3,3);


                        glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,74);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(35,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                           glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,75);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(36,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                               glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,76);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(37,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);


                                           glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,50);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(38,-11,-24);
                       // masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                glPopMatrix();

                //------------------------------------------Toys4

                    glPushMatrix();
                        glTranslatef(-65,0,171);
                        glRotatef(90, 0,1,0);
                       // glScalef(3,3,3);


                        glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,51);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(35,-11,-24);
                       // masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                           glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,77);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(36,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                               glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,78);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(37,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);


                                           glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,39);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(38,-11,-24);
                       // masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                glPopMatrix();


                //row2
                //------------------------------------------Toys2


                                glPushMatrix();
                                glTranslatef(-65,-9,127);
                                glRotatef(90, 0,1,0);
                               // glScalef(3,3,3);


                                glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,79);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(35,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,80);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(36,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                       glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,81);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(37,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);


                                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,43);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(38,-11,-24);
                               // masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                        glPopMatrix();

                        //------------------------------------------Toys3

                            glPushMatrix();
                                glTranslatef(-65,-9,148);
                                glRotatef(90, 0,1,0);
                               // glScalef(3,3,3);


                                glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,82);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(35,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,81);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(36,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                       glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,80);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(37,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);


                                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,47);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(38,-11,-24);
                               // masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                        glPopMatrix();

                        //------------------------------------------Toys4

                            glPushMatrix();
                                glTranslatef(-65,-9,171);
                                glRotatef(90, 0,1,0);
                               // glScalef(3,3,3);


                                glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,48);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(35,-11,-24);
                                //masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,80);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(36,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                       glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,71);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(37,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);


                                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,72);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(38,-11,-24);
                               // masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                        glPopMatrix();


                          //row2
                //------------------------------------------Toyslast


                                glPushMatrix();
                                glTranslatef(-65,-18,127);
                                glRotatef(90, 0,1,0);
                               // glScalef(3,3,3);


                                glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,72);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(35,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,73);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(36,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                       glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,74);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(37,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);


                                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,66);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(38,-11,-24);
                               // masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                        glPopMatrix();

                        //------------------------------------------Toys3

                            glPushMatrix();
                                glTranslatef(-65,-18,148);
                                glRotatef(90, 0,1,0);
                               // glScalef(3,3,3);


                                glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,83);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(35,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,84);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(36,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                       glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,85);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(37,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);


                                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,70);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(38,-11,-24);
                               // masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                        glPopMatrix();

                        //------------------------------------------Toys4

                            glPushMatrix();
                                glTranslatef(-65,-18,171);
                                glRotatef(90, 0,1,0);
                               // glScalef(3,3,3);


                                glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,71);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(35,-11,-24);
                                //masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,71);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(36,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                       glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,72);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(37,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);


                                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,66);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(38,-11,-24);
                               // masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                        glPopMatrix();
            glPopMatrix();

        //leftFruites2//------------------------------------------------------------leftFruites

            glPushMatrix();
                    glTranslatef(-200,0,0);


    //------------------------------------------Toys2

                    glPushMatrix();
                        glTranslatef(-65,0,127);
                        glRotatef(90, 0,1,0);
                       // glScalef(3,3,3);


                        glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,71);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(35,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                           glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,72);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(36,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                               glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,73);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(37,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);


                                           glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,46);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(38,-11,-24);
                       // masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                glPopMatrix();

                //------------------------------------------Toys3

                    glPushMatrix();
                        glTranslatef(-65,0,148);
                        glRotatef(90, 0,1,0);
                       // glScalef(3,3,3);


                        glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,74);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(35,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                           glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,75);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(36,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                               glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,76);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(37,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);


                                           glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,50);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(38,-11,-24);
                       // masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                glPopMatrix();

                //------------------------------------------Toys4

                    glPushMatrix();
                        glTranslatef(-65,0,171);
                        glRotatef(90, 0,1,0);
                       // glScalef(3,3,3);


                        glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,51);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(35,-11,-24);
                       // masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                           glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,77);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(36,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                               glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,78);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(37,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);


                                           glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,39);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(38,-11,-24);
                       // masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                glPopMatrix();


                //row2
                //------------------------------------------Toys2


                                glPushMatrix();
                                glTranslatef(-65,-9,127);
                                glRotatef(90, 0,1,0);
                               // glScalef(3,3,3);


                                glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,79);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(35,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,80);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(36,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                       glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,81);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(37,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);


                                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,43);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(38,-11,-24);
                               // masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                        glPopMatrix();

                        //------------------------------------------Toys3

                            glPushMatrix();
                                glTranslatef(-65,-9,148);
                                glRotatef(90, 0,1,0);
                               // glScalef(3,3,3);


                                glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,82);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(35,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,81);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(36,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                       glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,80);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(37,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);


                                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,47);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(38,-11,-24);
                               // masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                        glPopMatrix();

                        //------------------------------------------Toys4

                            glPushMatrix();
                                glTranslatef(-65,-9,171);
                                glRotatef(90, 0,1,0);
                               // glScalef(3,3,3);


                                glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,48);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(35,-11,-24);
                                //masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,80);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(36,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                       glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,71);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(37,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);


                                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,72);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(38,-11,-24);
                               // masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                        glPopMatrix();


                          //row2
                //------------------------------------------Toyslast


                                glPushMatrix();
                                glTranslatef(-65,-18,127);
                                glRotatef(90, 0,1,0);
                               // glScalef(3,3,3);


                                glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,72);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(35,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,73);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(36,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                       glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,74);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(37,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);


                                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,66);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(38,-11,-24);
                               // masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                        glPopMatrix();

                        //------------------------------------------Toys3

                            glPushMatrix();
                                glTranslatef(-65,-18,148);
                                glRotatef(90, 0,1,0);
                               // glScalef(3,3,3);


                                glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,83);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(35,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,84);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(36,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                       glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,85);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(37,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);


                                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,70);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(38,-11,-24);
                               // masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                        glPopMatrix();

                        //------------------------------------------Toys4

                            glPushMatrix();
                                glTranslatef(-65,-18,171);
                                glRotatef(90, 0,1,0);
                               // glScalef(3,3,3);


                                glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,71);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(35,-11,-24);
                                //masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,71);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(36,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                       glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,72);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(37,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);


                                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,66);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(38,-11,-24);
                               // masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                        glPopMatrix();
            glPopMatrix();



     //----------------------------------frontReck

      glPushMatrix();
                glTranslatef(12,6.2,-17);

                    glScalef(0.8,0.8,0.8);

    //------------------------------------------Toys

        glPushMatrix();
            glTranslatef(-65,9,105);
            glRotatef(90, 0,1,0);
           // glScalef(3,3,3);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,93);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(35,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,93);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(36,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                   glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,93);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(37,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


                               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,93);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(38,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


                               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,93);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(34,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

    glPopMatrix();


     //------------------------------------------Toys

        glPushMatrix();
            glTranslatef(-65,0,105);
            glRotatef(90, 0,1,0);
           // glScalef(3,3,3);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,94);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(35,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,94);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(36,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                   glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,94);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(37,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


                               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,94);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(38,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


                               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,94);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(34,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

    glPopMatrix();

       //------------------------------------------Toys1

        glPushMatrix();
            glTranslatef(-65,-9,105);
            glRotatef(90, 0,1,0);
           // glScalef(3,3,3);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,95);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(35,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,95);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(36,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                   glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,95);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(37,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


                               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,95);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(38,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,95);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(34,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

    glPopMatrix();

       //------------------------------------------Toys1__1

        glPushMatrix();
            glTranslatef(-65,-18,105);
            glRotatef(90, 0,1,0);
           // glScalef(3,3,3);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,96);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(35,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,96);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(36,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                   glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,96);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(37,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


                               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,96);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(38,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);
                                          glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,96);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(34,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

    glPopMatrix();


      glPopMatrix();



        //leftFruites3//------------------------------------------------------------leftFruites

            glPushMatrix();
                    glTranslatef(-200,0,-120);


    //------------------------------------------Toys2

                    glPushMatrix();
                        glTranslatef(-65,0,127);
                        glRotatef(90, 0,1,0);
                       // glScalef(3,3,3);


                        glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,71);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(35,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                           glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,72);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(36,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                               glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,73);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(37,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);


                                           glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,46);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(38,-11,-24);
                       // masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                glPopMatrix();

                //------------------------------------------Toys3

                    glPushMatrix();
                        glTranslatef(-65,0,148);
                        glRotatef(90, 0,1,0);
                       // glScalef(3,3,3);


                        glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,74);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(35,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                           glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,75);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(36,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                               glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,76);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(37,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);


                                           glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,50);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(38,-11,-24);
                       // masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                glPopMatrix();

                //------------------------------------------Toys4

                    glPushMatrix();
                        glTranslatef(-65,0,171);
                        glRotatef(90, 0,1,0);
                       // glScalef(3,3,3);


                        glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,51);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(35,-11,-24);
                       // masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                           glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,77);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(36,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                               glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,78);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(37,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);


                                           glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,39);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(38,-11,-24);
                       // masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                glPopMatrix();


                //row2
                //------------------------------------------Toys2


                                glPushMatrix();
                                glTranslatef(-65,-9,127);
                                glRotatef(90, 0,1,0);
                               // glScalef(3,3,3);


                                glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,79);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(35,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,80);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(36,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                       glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,81);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(37,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);


                                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,43);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(38,-11,-24);
                               // masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                        glPopMatrix();

                        //------------------------------------------Toys3

                            glPushMatrix();
                                glTranslatef(-65,-9,148);
                                glRotatef(90, 0,1,0);
                               // glScalef(3,3,3);


                                glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,82);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(35,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,81);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(36,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                       glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,80);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(37,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);


                                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,47);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(38,-11,-24);
                               // masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                        glPopMatrix();

                        //------------------------------------------Toys4

                            glPushMatrix();
                                glTranslatef(-65,-9,171);
                                glRotatef(90, 0,1,0);
                               // glScalef(3,3,3);


                                glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,48);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(35,-11,-24);
                                //masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,80);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(36,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                       glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,71);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(37,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);


                                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,72);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(38,-11,-24);
                               // masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                        glPopMatrix();


                          //row2
                //------------------------------------------Toyslast


                                glPushMatrix();
                                glTranslatef(-65,-18,127);
                                glRotatef(90, 0,1,0);
                               // glScalef(3,3,3);


                                glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,72);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(35,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,73);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(36,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                       glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,74);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(37,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);


                                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,66);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(38,-11,-24);
                               // masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                        glPopMatrix();

                        //------------------------------------------Toys3

                            glPushMatrix();
                                glTranslatef(-65,-18,148);
                                glRotatef(90, 0,1,0);
                               // glScalef(3,3,3);


                                glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,83);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(35,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,84);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(36,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                       glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,85);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(37,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);


                                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,70);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(38,-11,-24);
                               // masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                        glPopMatrix();

                        //------------------------------------------Toys4

                            glPushMatrix();
                                glTranslatef(-65,-18,171);
                                glRotatef(90, 0,1,0);
                               // glScalef(3,3,3);


                                glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,71);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(35,-11,-24);
                                //masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,71);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(36,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                       glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,72);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(37,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);


                                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,66);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(38,-11,-24);
                               // masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                        glPopMatrix();
            glPopMatrix();



     //----------------------------------frontReck

      glPushMatrix();
                glTranslatef(12,6.2,-17);

                    glScalef(0.8,0.8,0.8);

    //------------------------------------------Toys

        glPushMatrix();
            glTranslatef(-65,9,105);
            glRotatef(90, 0,1,0);
           // glScalef(3,3,3);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,93);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(35,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,93);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(36,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                   glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,93);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(37,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


                               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,93);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(38,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


                               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,93);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(34,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

    glPopMatrix();


     //------------------------------------------Toys

        glPushMatrix();
            glTranslatef(-65,0,105);
            glRotatef(90, 0,1,0);
           // glScalef(3,3,3);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,94);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(35,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,94);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(36,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                   glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,94);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(37,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


                               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,94);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(38,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


                               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,94);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(34,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

    glPopMatrix();

       //------------------------------------------Toys1

        glPushMatrix();
            glTranslatef(-65,-9,105);
            glRotatef(90, 0,1,0);
           // glScalef(3,3,3);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,95);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(35,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,95);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(36,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                   glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,95);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(37,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


                               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,95);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(38,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,95);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(34,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

    glPopMatrix();

       //------------------------------------------Toys1__1

        glPushMatrix();
            glTranslatef(-65,-18,105);
            glRotatef(90, 0,1,0);
           // glScalef(3,3,3);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,96);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(35,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,96);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(36,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                   glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,96);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(37,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


                               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,96);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(38,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);
                                          glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,96);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(34,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

    glPopMatrix();


      glPopMatrix();



        //leftFruites4//------------------------------------------------------------leftFruites

            glPushMatrix();
                    glTranslatef(-200,0,-200);


    //------------------------------------------Toys2

                    glPushMatrix();
                        glTranslatef(-65,0,127);
                        glRotatef(90, 0,1,0);
                       // glScalef(3,3,3);


                        glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,71);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(35,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                           glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,72);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(36,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                               glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,73);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(37,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);


                                           glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,46);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(38,-11,-24);
                       // masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                glPopMatrix();

                //------------------------------------------Toys3

                    glPushMatrix();
                        glTranslatef(-65,0,148);
                        glRotatef(90, 0,1,0);
                       // glScalef(3,3,3);


                        glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,74);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(35,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                           glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,75);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(36,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                               glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,76);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(37,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);


                                           glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,50);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(38,-11,-24);
                       // masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                glPopMatrix();

                //------------------------------------------Toys4

                    glPushMatrix();
                        glTranslatef(-65,0,171);
                        glRotatef(90, 0,1,0);
                       // glScalef(3,3,3);


                        glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,51);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(35,-11,-24);
                       // masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                           glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,77);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(36,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                               glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,78);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(37,-11,-24);
                        masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);


                                           glPushMatrix();
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D,39);
                       // glRotatef(90, 0,0,1);
                        glScalef(7,6,4);
                        glTranslatef(38,-11,-24);
                       // masala();
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);

                glPopMatrix();


                //row2
                //------------------------------------------Toys2


                                glPushMatrix();
                                glTranslatef(-65,-9,127);
                                glRotatef(90, 0,1,0);
                               // glScalef(3,3,3);


                                glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,79);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(35,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,80);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(36,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                       glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,81);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(37,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);


                                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,43);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(38,-11,-24);
                               // masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                        glPopMatrix();

                        //------------------------------------------Toys3

                            glPushMatrix();
                                glTranslatef(-65,-9,148);
                                glRotatef(90, 0,1,0);
                               // glScalef(3,3,3);


                                glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,82);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(35,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,81);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(36,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                       glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,80);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(37,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);


                                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,47);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(38,-11,-24);
                               // masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                        glPopMatrix();

                        //------------------------------------------Toys4

                            glPushMatrix();
                                glTranslatef(-65,-9,171);
                                glRotatef(90, 0,1,0);
                               // glScalef(3,3,3);


                                glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,48);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(35,-11,-24);
                                //masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,80);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(36,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                       glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,71);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(37,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);


                                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,72);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(38,-11,-24);
                               // masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                        glPopMatrix();


                          //row2
                //------------------------------------------Toyslast


                                glPushMatrix();
                                glTranslatef(-65,-18,127);
                                glRotatef(90, 0,1,0);
                               // glScalef(3,3,3);


                                glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,72);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(35,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,73);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(36,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                       glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,74);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(37,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);


                                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,66);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(38,-11,-24);
                               // masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                        glPopMatrix();

                        //------------------------------------------Toys3

                            glPushMatrix();
                                glTranslatef(-65,-18,148);
                                glRotatef(90, 0,1,0);
                               // glScalef(3,3,3);


                                glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,83);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(35,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,84);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(36,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                       glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,85);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(37,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);


                                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,70);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(38,-11,-24);
                               // masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                        glPopMatrix();

                        //------------------------------------------Toys4

                            glPushMatrix();
                                glTranslatef(-65,-18,171);
                                glRotatef(90, 0,1,0);
                               // glScalef(3,3,3);


                                glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,71);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(35,-11,-24);
                                //masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,71);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(36,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                                       glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,72);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(37,-11,-24);
                                masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);


                                                   glPushMatrix();
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D,66);
                               // glRotatef(90, 0,0,1);
                                glScalef(7,6,4);
                                glTranslatef(38,-11,-24);
                               // masala();
                                glPopMatrix();
                                glDisable(GL_TEXTURE_2D);

                        glPopMatrix();
            glPopMatrix();



     //----------------------------------frontReck

      glPushMatrix();
                glTranslatef(12,6.2,-17);

                    glScalef(0.8,0.8,0.8);

    //------------------------------------------Toys

        glPushMatrix();
            glTranslatef(-65,9,105);
            glRotatef(90, 0,1,0);
           // glScalef(3,3,3);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,93);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(35,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,93);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(36,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                   glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,93);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(37,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


                               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,93);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(38,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


                               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,93);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(34,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

    glPopMatrix();


     //------------------------------------------Toys

        glPushMatrix();
            glTranslatef(-65,0,105);
            glRotatef(90, 0,1,0);
           // glScalef(3,3,3);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,94);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(35,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,94);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(36,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                   glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,94);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(37,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


                               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,94);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(38,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


                               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,94);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(34,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

    glPopMatrix();

       //------------------------------------------Toys1

        glPushMatrix();
            glTranslatef(-65,-9,105);
            glRotatef(90, 0,1,0);
           // glScalef(3,3,3);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,95);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(35,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,95);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(36,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                   glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,95);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(37,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


                               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,95);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(38,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,95);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(34,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

    glPopMatrix();

       //------------------------------------------Toys1__1

        glPushMatrix();
            glTranslatef(-65,-18,105);
            glRotatef(90, 0,1,0);
           // glScalef(3,3,3);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,96);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(35,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,96);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(36,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                   glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,96);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(37,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


                               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,96);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(38,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);
                                          glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,96);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(34,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

    glPopMatrix();


      glPopMatrix();


     //----------------------------------frontReck2

      glPushMatrix();
                glTranslatef(12,6.2,-60);

                    glScalef(0.8,0.8,0.8);

    //------------------------------------------Toys

        glPushMatrix();
            glTranslatef(-65,9,105);
            glRotatef(90, 0,1,0);
           // glScalef(3,3,3);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,97);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(35,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,97);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(36,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                   glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,97);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(37,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


                               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,97);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(38,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);
                               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,97);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(39,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


                               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,97);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(34,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

    glPopMatrix();


     //------------------------------------------Toys

        glPushMatrix();
            glTranslatef(-65,0,105);
            glRotatef(90, 0,1,0);
           // glScalef(3,3,3);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,98);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(35,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,98);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(36,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                   glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,98);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(37,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


                               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,98);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(38,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                                           glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,98);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(39,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


                               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,98);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(34,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

    glPopMatrix();

       //------------------------------------------Toys1

        glPushMatrix();
            glTranslatef(-65,-9,105);
            glRotatef(90, 0,1,0);
           // glScalef(3,3,3);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,99);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(35,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,99);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(36,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                   glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,99);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(37,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


                               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,99);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(38,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,99);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(39,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,99);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(34,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

    glPopMatrix();

       //------------------------------------------Toys1__1

        glPushMatrix();
            glTranslatef(-65,-17.2,105);
            glRotatef(90, 0,1,0);
           // glScalef(3,3,3);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,100);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(35,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,100);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(36,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                   glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,100);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(37,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


                               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,100);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(38,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,100);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(39,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);
                                          glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,100);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(34,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

    glPopMatrix();


         //------------------------------------------Toys1__1

        glPushMatrix();
            glTranslatef(-65,-25.8,105);
            glRotatef(90, 0,1,0);
           // glScalef(3,3,3);


            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,101);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(35,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,101);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(36,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                   glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,101);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(37,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);


                               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,101);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(38,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

                               glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,101);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(39,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);
                                          glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,101);
           // glRotatef(90, 0,0,1);
            glScalef(7,6,4);
            glTranslatef(34,-11,-24);
            masala();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

    glPopMatrix();


      glPopMatrix();


      }


void stairs(){


glPushMatrix();
     glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,102);
    glScalef(3.5,3,10);
    glTranslatef(-25.2,.00,-.5);
 //glRotatef(-360, 1.0, 1, 1.0);
    //cube(1.5,1,1.7);
    Cube();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    glPushMatrix();
     glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,102);
    glScalef(10,3,1);
    glTranslatef(-25.2,.00,-.5);
 //  glRotatef(-90, 0.0, 0, 1.0);
    //cube(1.5,1,1.7);
 //   Cube();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
     glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,102);
    glScalef(3.5,3,10);
    glTranslatef(-24.4,1.0,-.5);
 //glRotatef(-360, 1.0, 1, 1.0);
    //cube(1.5,1,1.7);
    Cube();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
     glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,102);
    glScalef(3.5,3,10);
    glTranslatef(-23.6,2.0,-.5);
 //glRotatef(-360, 1.0, 1, 1.0);
    //cube(1.5,1,1.7);
    Cube();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

     glPushMatrix();
     glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,102);
    glScalef(3.5,3,10);
    glTranslatef(-22.8,3.0,-.5);
 //glRotatef(-360, 1.0, 1, 1.0);
    //cube(1.5,1,1.7);
    Cube();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
     glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,102);
    glScalef(3.5,3,10);
    glTranslatef(-22.1,4.0,-.5);
 //glRotatef(-360, 1.0, 1, 1.0);
    //cube(1.5,1,1.7);
    Cube();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

     glPushMatrix();
     glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,102);
    glScalef(3.5,3,10);
    glTranslatef(-21.4,5.0,-.5);
 //glRotatef(-360, 1.0, 1, 1.0);
    //cube(1.5,1,1.7);
    Cube();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
     glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,102);
    glScalef(3.5,3,10);
    glTranslatef(-20.6,6.0,-.5);
 //glRotatef(-360, 1.0, 1, 1.0);
    //cube(1.5,1,1.7);
    Cube();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
     glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,102);
    glScalef(3.5,3,10);
    glTranslatef(-19.8,7.0,-.5);
 //glRotatef(-360, 1.0, 1, 1.0);
    //cube(1.5,1,1.7);
    Cube();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
        glPushMatrix();

     glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,102);
    glScalef(3.5,3,10);
    glTranslatef(-19,8.0,-.5);
 //glRotatef(-360, 1.0, 1, 1.0);
    //cube(1.5,1,1.7);
    Cube();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


        glPushMatrix();
     glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,102);
    glScalef(3.5,3,10);
    glTranslatef(-18.2,9.0,-.5);
 //glRotatef(-360, 1.0, 1, 1.0);
    //cube(1.5,1,1.7);
    Cube();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

     glPushMatrix();
     glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,102);
    glScalef(3.5,3,10);
    glTranslatef(-17.4,10.0,-.5);
 //glRotatef(-360, 1.0, 1, 1.0);
    //cube(1.5,1,1.7);
    Cube();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
     glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,102);
    glScalef(3.5,3,10);
    glTranslatef(-16.6,11.0,-.5);
 //glRotatef(-360, 1.0, 1, 1.0);
    //cube(1.5,1,1.7);
    Cube();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
     glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,102);
    glScalef(3.5,3,10);
    glTranslatef(-15.8,12.0,-.5);
 //glRotatef(-360, 1.0, 1, 1.0);
    //cube(1.5,1,1.7);
    Cube();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

     glPushMatrix();
     glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,102);
    glScalef(3.5,3,10);
    glTranslatef(-15,13.0,-.5);
 //glRotatef(-360, 1.0, 1, 1.0);
    //cube(1.5,1,1.7);
    Cube();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


}

void jainamaj(){

        glPushMatrix();
        glScalef(70,1,85);
        glScalef(0.5,0.5,0.5);
        glTranslatef(-0.57,5,-0.7);
        cube();
        glPopMatrix();

}
void stairTop(){

       //topCloth

                      glPushMatrix();
            glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,28);
    glTranslatef(-200,70,0);
    glScalef(2,4,2);
  // jainamaj();
    glPopMatrix();
        glDisable(GL_TEXTURE_2D);

    //pillar
    float length = 30;
    float width = 0.3;
    glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,28);
    glTranslatef(1,-110,-20);
    glScalef(1,50,1);
    glTranslatef(-80,0.9,10);
   // glScalef(1,100,1);
    //cube(1,1,1);
    glPopMatrix();
            glDisable(GL_TEXTURE_2D);

            //pillar2
               glPushMatrix();
                    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,28);
    glTranslatef(1,-110,-20);
    glScalef(3,100,3);
    glTranslatef(-80,0.9,-10);
   // glScalef(1,100,1);
   // cube(1,1,1);
    glPopMatrix();
            glDisable(GL_TEXTURE_2D);


                //fan stand
    glTranslatef(0,0.04,0);

    glPushMatrix();
    glTranslatef(1,length/2,-4);
    glScalef(0.3,9,1);
    glTranslatef(-157,-1.6,-87);
    cube(0.4,0.4,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1,length/2,-4);
    glScalef(0.3,9,1);
    glTranslatef(-190,-1.6,-87);
    cube(0.4,0.4,0.1);
    glPopMatrix();

                   //fan stand2

    glPushMatrix();
    glTranslatef(1,length/2,-4);
    glScalef(0.3,9,1);
    glTranslatef(-157,-1.4,-86);
    cube(0.4,0.4,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1,length/2,-4);
    glScalef(0.3,9,1);
    glTranslatef(-190,-1.4,-86);
    cube(0.4,0.4,0.1);
    glPopMatrix();

                   //fan stand2

    glPushMatrix();
    glTranslatef(1,length/2,-4);
    glScalef(0.3,9,1);
    glTranslatef(-157,-1.2,-85);
    cube(0.4,0.4,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1,length/2,-4);
    glScalef(0.3,9,1);
    glTranslatef(-190,-1.2,-85);
    cube(0.4,0.4,0.1);
    glPopMatrix();

                   //fan stand2

    glPushMatrix();
    glTranslatef(1,length/2,-4);
    glScalef(0.3,9,1);
    glTranslatef(-157,-1,-84);
    cube(0.4,0.4,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1,length/2,-4);
    glScalef(0.3,9,1);
    glTranslatef(-190,-1,-84);
    cube(0.4,0.4,0.1);
    glPopMatrix();

                      //fan stand2

    glPushMatrix();
    glTranslatef(1,length/2,-4);
    glScalef(0.3,9,1);
    glTranslatef(-157,-0.8,-83);
    cube(0.4,0.4,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1,length/2,-4);
    glScalef(0.3,9,1);
    glTranslatef(-190,-0.8,-83);
    cube(0.4,0.4,0.1);
    glPopMatrix();

                      //fan stand2

    glPushMatrix();
    glTranslatef(1,length/2,-4);
    glScalef(0.3,9,1);
    glTranslatef(-157,-0.6,-82);
    cube(0.4,0.4,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1,length/2,-4);
    glScalef(0.3,9,1);
    glTranslatef(-190,-0.6,-82);
    cube(0.4,0.4,0.1);
    glPopMatrix();

                       //fan stand2

    glPushMatrix();
    glTranslatef(1,length/2,-4);
    glScalef(0.3,9,1);
    glTranslatef(-157,-0.4,-81);
    cube(0.4,0.4,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1,length/2,-4);
    glScalef(0.3,9,1);
    glTranslatef(-190,-0.4,-81);
    cube(0.4,0.4,0.1);
    glPopMatrix();
                          //fan stand2

    glPushMatrix();
    glTranslatef(1,length/2,-4);
    glScalef(0.3,9,1);
    glTranslatef(-157,-0.2,-80);
    cube(0.4,0.4,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1,length/2,-4);
    glScalef(0.3,9,1);
    glTranslatef(-190,-0.2,-80);
    cube(0.4,0.4,0.1);
    glPopMatrix();
                           //fan stand2

    glPushMatrix();
    glTranslatef(1,length/2,-4);
    glScalef(0.3,9,1);
    glTranslatef(-157,0,-79);
    cube(0.4,0.4,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1,length/2,-4);
    glScalef(0.3,9,1);
    glTranslatef(-190,0,-79);
    cube(0.4,0.4,0.1);
    glPopMatrix();

                             //fan stand2

    glPushMatrix();
    glTranslatef(1,length/2,-4);
    glScalef(0.3,9,1);
    glTranslatef(-157,0.2,-78);
    cube(0.4,0.4,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1,length/2,-4);
    glScalef(0.3,9,1);
    glTranslatef(-190,0.2,-78);
    cube(0.4,0.4,0.1);
    glPopMatrix();

                             //fan stand2

    glPushMatrix();
    glTranslatef(1,length/2,-4);
    glScalef(0.3,9,1);
    glTranslatef(-157,0.4,-77);
    cube(0.4,0.4,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1,length/2,-4);
    glScalef(0.3,9,1);
    glTranslatef(-190,0.4,-77);
    cube(0.4,0.4,0.1);
    glPopMatrix();
                             //fan stand2

    glPushMatrix();
    glTranslatef(1,length/2,-4);
    glScalef(0.3,9,1);
    glTranslatef(-157,0.6,-76);
    cube(0.4,0.4,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1,length/2,-4);
    glScalef(0.3,9,1);
    glTranslatef(-190,0.6,-76);
    cube(0.4,0.4,0.1);
    glPopMatrix();                             //fan stand2

    glPushMatrix();
    glTranslatef(1,length/2,-4);
    glScalef(0.3,9,1);
    glTranslatef(-157,0.8,-75);
    cube(0.4,0.4,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1,length/2,-4);
    glScalef(0.3,9,1);
    glTranslatef(-190,0.8,-75);
    cube(0.4,0.4,0.1);
    glPopMatrix();

    //-------------//fan stand2
       glPushMatrix();
    glTranslatef(1,length/2,-4);
    glScalef(0.3,9,1);
    glTranslatef(-157,1,-74);
    cube(0.4,0.4,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1,length/2,-4);
    glScalef(0.3,9,1);
    glTranslatef(-190,1,-74);
    cube(0.4,0.4,0.1);
    glPopMatrix();

       //-------------//fan stand2
       glPushMatrix();
    glTranslatef(1,length/2,-4);
    glScalef(0.3,9,1);
    glTranslatef(-157,1,-73);
    cube(0.4,0.4,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1,length/2,-4);
    glScalef(0.3,9,1);
    glTranslatef(-190,1,-73);
    cube(0.4,0.4,0.1);
    glPopMatrix();

}



void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    //glMatrixMode( GL_PROJECTION );
   // glLoadIdentity();
    //gluPerspective(60,1,1,500);
    //gluOrtho2D(60,1,1,100);
   // glMatrixMode( GL_MODELVIEW );
   // glLoadIdentity();

	glFrustum(-3, 3, -3, 3, 2.0, 100.0);
    glLoadIdentity();
    gluLookAt(eyeX,eyeY,eyeZ, centerX,centerY,centerZ, 0,1,0);
    glRotatef(rot, 0,1,0);

    glPushMatrix();
    road();
    glPopMatrix();

    allreck();
        glPushMatrix();
    glTranslatef(-38,0,11);
    //glRotatef(90,0,1,0);
    allglasses();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.5,-0.5,0);
    glScalef(1,0.7,1.1);
    glRotatef(90,0,1,0);
    allbottle();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,3);
    //glScalef(0.25, 0.8, 0.1);
    allmasala();
    glPopMatrix();
    allFruits();



            glPushMatrix();
        glTranslatef(-51,-1,-55);
        glScalef(1,0.6,0.4);
            glRotatef(-90, 0,1,0);

            stairs();
        glPopMatrix();

                    glPushMatrix();
        //glTranslatef(-51,-1,-55);
       // glScalef(1,0.6,0.4);
          //  glRotatef(-90, 0,1,0);

            stairTop();
        glPopMatrix();







    glPushMatrix();
    glTranslatef(-25,05,40);
    glScalef(0.25, 0.8, 0.1);
    //reckAngle();
    glPopMatrix();

    glPushMatrix();
   // glEnable(GL_TEXTURE_2D);
    //glBindTexture(GL_TEXTURE_2D,17);

    // glScalef(2, 0, 2);
   //  glTranslatef(-20.0,0,-40);
    //drawCircle();
		//drawSphere(10);
    // glRotatef(-30,0.0,1,.0);
    glPopMatrix();
   // glDisable(GL_TEXTURE_2D);


    allWearDrop();
    allFloor();
    glPushMatrix();
    glTranslatef(0,0,0);
    tree2();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(5,0,-70);
    glScalef(2,2,2);
    glRotatef(-90.0, 0.0, 1.0, 0.0);  // Adjust the angle as needed
    full_set();
    glPopMatrix();

    allhouse();

    glPushMatrix();
    glTranslatef(-17,-20,-44);
    glScalef(0.8,3,1);
    glRotatef(90.0, 0.0, 1.0, 0.0);  // Adjust the angle as needed
    windows();
    glPopMatrix();






    glPushMatrix();
    glScalef(0.8,1,0.8);
    glTranslatef(-5,20,-30);
   // topDesign();
    glPopMatrix();
    floorWallsCeiling(300);




    glFlush();
    glutSwapBuffers();
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//DO NOT TOUCH!!!!


void LoadTexture(const char*filename)
{
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);
    glPixelStorei(GL_UNPACK_ALIGNMENT, ID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    BmpLoader bl(filename);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, bl.iWidth, bl.iHeight, GL_RGB, GL_UNSIGNED_BYTE, bl.textureData );
}


static void key(unsigned char key, int x, int y);

float l_val=.1;

static void light14(unsigned char light1, int x, int y)
{

    switch (light1)
    {

    case 27:
        glutKeyboardFunc(key);
        break;
    case '1':
        al1+=l_val;
        break;
    case '2':
        al1-=l_val;
        break;
    case '3':
        dl1+=l_val;
        break;
    case '4':
        dl1-=l_val;
        break;
    case '5':
        sl1+=l_val;
        break;
    case '6':
        sl1-=l_val;
        break;
    }
read:
    return;
}

static void light24(unsigned char light2, int x, int y)
{
    switch (light2)
    {

    case 27:
        glutKeyboardFunc(key);

        break;
    case '1':
        al2+=l_val;
        break;
    case '2':
        al2-=l_val;
        break;
    case '3':
        dl2+=l_val;
        break;
    case '4':
        dl2-=l_val;
        break;
    case '5':
        sl2+=l_val;
        break;
    case '6':
        sl2-=l_val;
        break;
    }
}

static void spot_light14(unsigned char spot_light, int x, int y)
{
    switch (spot_light)
    {

    case 27:

        glutKeyboardFunc(key);
        break;
    case '1':
        al3+=l_val;
        break;
    case '2':
        al3-=l_val;
        break;
    case '3':
        dl3+=l_val;
        break;
    case '4':
        dl3-=l_val;
        break;
    case '5':
        sl3+=l_val;
        break;
    case '6':
        sl3-=l_val;
        break;
    }
}

/*void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'a':
        case 'A':
            glTranslatef(5.0, 0.0, 0.0);
            break;

        case 'd':
        case 'D':
            glTranslatef(-5.0, 0.0, 0.0);
            break;

        case 'w':
        case 'W':
            glTranslatef(0.0, 0.0, 5.0);
            break;

        case 's':
        case 'S':
            glTranslatef(0.0, 0.0, -5.0);
            break;

        case 't':
        case 'T':
            if (is_depth)
            {
                is_depth = 0;
                glDisable(GL_DEPTH_TEST);
            }
            else
            {
                is_depth = 1;
                glEnable(GL_DEPTH_TEST);
            }

        #Fall-through...
        case 'o':
        case 'O':
            door_Xpos += 90.0;
            break;
    }
    display();
}*/
static void key(unsigned char key, int x, int y)
{
    switch (key)
    {

    case 27:
        exit(0);
        break;
    case '+':
        eyeZ++;
        //eyeY++;
        break;
    case '-':
        eyeZ--;
        // eyeY--;
        break;

    case 'a':
        eyeX++;

        //eyeY++;
        break;
    case 's':
        eyeX--;
        // eyeY--;
        break;

    case 'g':
        eyeY++;
        //eyeY++;
        break;
    case 'h':
        eyeY--;
        // eyeY--;
        break;

    case 'w':
        //centerX++;
        centerY++;
        //  centerZ++;
        break;
    case 'e':
        //  centerX--;
        centerY--;
        //  centerZ--;
        break;

    case 'o':
        centerX++;

        //centerY++;
        //  centerZ++;
        break;
    case 'p':
        centerX--;
        //centerY--;
        //  centerZ--;
        break;

    case 'k':
        centerZ++;
        //centerY++;
        //  centerZ++;
        break;
    case 'l':
        centerZ--;
        //centerY--;
        //  centerZ--;
        break;


    case ',':
        rot++;
        break;
    case '.':
        rot--;
        break;

    case '*':
        stop=0;
        break;

    case ';':
        angle=0,stop=1,k=0;
        break;

    case '1':
        l_height+=.1;
        break;
    case '2':
        l_height-=.1;
        break;

    case '3':
        spt_cutoff++;
        break;
    case '4':
        spt_cutoff--;
        break;
    case 't':
        l_on1=1-l_on1;
        break;

    case 'u':
        l_on2=1-l_on2;
        break;

    case 'y':
        l_on3=1-l_on3;
        break;
    case 'd':
        markdoor=1-markdoor;
        break;
    case 'b':
        glutKeyboardFunc(light14);
        break;
    case 'n':
        glutKeyboardFunc(light24);
        break;
    case 'm':
        glutKeyboardFunc(spot_light14);
        break;

    }
    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
    spin();
}


/*void init(void)
{

glClearColor(0.215686275, 0.450980392, 0.698039216, 1.0);

glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 1200.0, 0, 1200.0);


}*/
void init(void)
{
    glClearColor(0.0, 0.9, 0.9, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

int main (int argc, char **argv)
{
	glutInit(&argc, argv);
    glutInitWindowSize(width,height);
    glutInitWindowPosition(100,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("test");
    glutReshapeFunc(res);
    glutDisplayFunc(display);

    glutKeyboardFunc(key);
    glutIdleFunc(idle);
    LoadTexture("D:\\SuperShopFinal\\bmp\\white2.bmp"); //1
    LoadTexture("D:\\SuperShopFinal\\bmp\\paint1.bmp");//2
    LoadTexture("D:\\SuperShopFinal\\bmp\\blue.bmp");//3
    LoadTexture("D:\\SuperShopFinal\\bmp\\sky2.bmp");//4
    LoadTexture("D:\\SuperShopFinal\\bmp\\grass2.bmp");//5
    LoadTexture("D:\\SuperShopFinal\\bmp\\table2.bmp");//6
    LoadTexture("D:\\SuperShopFinal\\bmp\\logo.bmp");//7
    LoadTexture("D:\\SuperShopFinal\\bmp\\black.bmp");//8
    LoadTexture("D:\\SuperShopFinal\\bmp\\superShop.bmp");//9
    LoadTexture("D:\\SuperShopFinal\\bmp\\green2.bmp");//10
    LoadTexture("D:\\SuperShopFinal\\bmp\\darkBrown.bmp");//11
    LoadTexture("D:\\SuperShopFinal\\bmp\\wall.bmp");//12
    LoadTexture("D:\\SuperShopFinal\\bmp\\bottle2.bmp");//13
    LoadTexture("D:\\SuperShopFinal\\bmp\\white.bmp");//14
    LoadTexture("D:\\SuperShopFinal\\bmp\\floor2.bmp");//15
    LoadTexture("D:\\SuperShopFinal\\bmp\\fridge.bmp");//16
    LoadTexture("D:\\SuperShopFinal\\bmp\\apple2.bmp");//17
    LoadTexture("D:\\SuperShopFinal\\bmp\\Orange.bmp");//18
    LoadTexture("D:\\SuperShopFinal\\bmp\\begun2.bmp");//19
    LoadTexture("D:\\SuperShopFinal\\bmp\\tomato2.bmp");//20
    LoadTexture("D:\\SuperShopFinal\\bmp\\green2.bmp");//21
    LoadTexture("D:\\SuperShopFinal\\bmp\\grapes.bmp");//22
    LoadTexture("D:\\SuperShopFinal\\bmp\\cabage.bmp");//23
    LoadTexture("D:\\SuperShopFinal\\bmp\\fulkopy2.bmp");//24
    LoadTexture("D:\\SuperShopFinal\\bmp\\bit.bmp");//25
    LoadTexture("D:\\SuperShopFinal\\bmp\\bit2.bmp");//26
    LoadTexture("D:\\SuperShopFinal\\bmp\\chili.bmp");//27
    LoadTexture("D:\\SuperShopFinal\\bmp\\krla.bmp");//28
    LoadTexture("D:\\SuperShopFinal\\bmp\\cap2.bmp");//29
    LoadTexture("D:\\SuperShopFinal\\bmp\\fruits.bmp");//30
    LoadTexture("D:\\SuperShopFinal\\bmp\\veg2.bmp");//31
    LoadTexture("D:\\SuperShopFinal\\bmp\\bottle3.bmp");//32
    LoadTexture("D:\\SuperShopFinal\\bmp\\chips.bmp");//33
    LoadTexture("D:\\SuperShopFinal\\bmp\\chips2.bmp");//34
    LoadTexture("D:\\SuperShopFinal\\bmp\\chips4.bmp");//35
    LoadTexture("D:\\SuperShopFinal\\bmp\\noodles.bmp");//36
    LoadTexture("D:\\SuperShopFinal\\bmp\\noodles3.bmp");//37
    LoadTexture("D:\\SuperShopFinal\\bmp\\noodles4.bmp");//38
    LoadTexture("D:\\SuperShopFinal\\bmp\\toys.bmp");//39
    LoadTexture("D:\\SuperShopFinal\\bmp\\toys2.bmp");//40
    LoadTexture("D:\\SuperShopFinal\\bmp\\toys3.bmp");//41
    LoadTexture("D:\\SuperShopFinal\\bmp\\toys4.bmp");//42
    LoadTexture("D:\\SuperShopFinal\\bmp\\toys5.bmp");//43
    LoadTexture("D:\\SuperShopFinal\\bmp\\toys6.bmp");//44
    LoadTexture("D:\\SuperShopFinal\\bmp\\toys7.bmp");//45
    LoadTexture("D:\\SuperShopFinal\\bmp\\toys8.bmp");//46
    LoadTexture("D:\\SuperShopFinal\\bmp\\toys9.bmp");//47
    LoadTexture("D:\\SuperShopFinal\\bmp\\toys16.bmp");//48
    LoadTexture("D:\\SuperShopFinal\\bmp\\toys11.bmp");//49
    LoadTexture("D:\\SuperShopFinal\\bmp\\toys12.bmp");//50
    LoadTexture("D:\\SuperShopFinal\\bmp\\toys13.bmp");//51
    LoadTexture("D:\\SuperShopFinal\\bmp\\toys14.bmp");//52
    LoadTexture("D:\\SuperShopFinal\\bmp\\toys15.bmp");//53
    LoadTexture("D:\\SuperShopFinal\\bmp\\toys18.bmp");//54
    LoadTexture("D:\\SuperShopFinal\\bmp\\toys17.bmp");//55
    LoadTexture("D:\\SuperShopFinal\\bmp\\masala.bmp");//56
    LoadTexture("D:\\SuperShopFinal\\bmp\\masala2.bmp");//57
    LoadTexture("D:\\SuperShopFinal\\bmp\\masala7.bmp");//58
    LoadTexture("D:\\SuperShopFinal\\bmp\\masala4.bmp");//59
    LoadTexture("D:\\SuperShopFinal\\bmp\\masala5.bmp");//60
    LoadTexture("D:\\SuperShopFinal\\bmp\\masala6.bmp");//61
    LoadTexture("D:\\SuperShopFinal\\bmp\\masala7.bmp");//62
    LoadTexture("D:\\SuperShopFinal\\bmp\\birth1.bmp");//63
    LoadTexture("D:\\SuperShopFinal\\bmp\\birth2.bmp");//64
    LoadTexture("D:\\SuperShopFinal\\bmp\\birth3.bmp");//65
    LoadTexture("D:\\SuperShopFinal\\bmp\\birth4.bmp");//66
    LoadTexture("D:\\SuperShopFinal\\bmp\\birth5.bmp");//67
    LoadTexture("D:\\SuperShopFinal\\bmp\\birth6.bmp");//68
    LoadTexture("D:\\SuperShopFinal\\bmp\\birth7.bmp");//69
    LoadTexture("D:\\SuperShopFinal\\bmp\\birth8.bmp");//70
    LoadTexture("D:\\SuperShopFinal\\bmp\\plate.bmp");//71
    LoadTexture("D:\\SuperShopFinal\\bmp\\plate1.bmp");//72
    LoadTexture("D:\\SuperShopFinal\\bmp\\plate2.bmp");//73
    LoadTexture("D:\\SuperShopFinal\\bmp\\plate3.bmp");//74
    LoadTexture("D:\\SuperShopFinal\\bmp\\plate4.bmp");//75
    LoadTexture("D:\\SuperShopFinal\\bmp\\plate5.bmp");//76
    LoadTexture("D:\\SuperShopFinal\\bmp\\plate6.bmp");//77
    LoadTexture("D:\\SuperShopFinal\\bmp\\plate7.bmp");//78
    LoadTexture("D:\\SuperShopFinal\\bmp\\plate8.bmp");//79
    LoadTexture("D:\\SuperShopFinal\\bmp\\plate9.bmp");//80
    LoadTexture("D:\\SuperShopFinal\\bmp\\plate10.bmp");//81
    LoadTexture("D:\\SuperShopFinal\\bmp\\plate11.bmp");//82
    LoadTexture("D:\\SuperShopFinal\\bmp\\plate12.bmp");//83
    LoadTexture("D:\\SuperShopFinal\\bmp\\plate13.bmp");//84
    LoadTexture("D:\\SuperShopFinal\\bmp\\plate14.bmp");//85
    LoadTexture("D:\\SuperShopFinal\\bmp\\achar.bmp");//86
    LoadTexture("D:\\SuperShopFinal\\bmp\\achar2.bmp");//87
    LoadTexture("D:\\SuperShopFinal\\bmp\\achar3.bmp");//88
    LoadTexture("D:\\SuperShopFinal\\bmp\\achar4.bmp");//89
    LoadTexture("D:\\SuperShopFinal\\bmp\\achar5.bmp");//90
    LoadTexture("D:\\SuperShopFinal\\bmp\\achar6.bmp");//91
    LoadTexture("D:\\SuperShopFinal\\bmp\\fridge2.bmp");//92
    LoadTexture("D:\\SuperShopFinal\\bmp\\bottle4.bmp");//93
    LoadTexture("D:\\SuperShopFinal\\bmp\\bottle5.bmp");//94
    LoadTexture("D:\\SuperShopFinal\\bmp\\bottle6.bmp");//95
    LoadTexture("D:\\SuperShopFinal\\bmp\\bottle7.bmp");//96
    LoadTexture("D:\\SuperShopFinal\\bmp\\bottle8.bmp");//97
    LoadTexture("D:\\SuperShopFinal\\bmp\\bottle9.bmp");//98
    LoadTexture("D:\\SuperShopFinal\\bmp\\bottle10.bmp");//99
    LoadTexture("D:\\SuperShopFinal\\bmp\\bottle11.bmp");//100
    LoadTexture("D:\\SuperShopFinal\\bmp\\bottle12.bmp");//101
    LoadTexture("D:\\Mosque\\bmp\\m_backWall3.bmp");//102


























    glEnable(GL_DEPTH_TEST);
    glShadeModel( GL_SMOOTH );
    glEnable(GL_NORMALIZE);
    glEnable(GL_BLEND);

    glEnable(GL_LIGHTING);
    GLfloat globalAmbient[] = {0.0,0.0,0.0,1.0};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,globalAmbient);
    int t=1;
    printf("Warning!!! please turn off caps lock and use shift key before * key and + key.\n");
    printf("%d. Press 't' for off light1.\n",t++);
    printf("%d. Press 'y' for off light2.\n",t++);
    printf("%d. Press 'u' for off cse light.\n",t++);

    printf("%d. Press '*' for stop fans.\n",t++);
    printf("%d. Press ';' for start fans.\n",t++);
    printf("%d. Press 'd' for window open/close.\n",t++);
    printf("%d. Press 'w' for up.\n%d. press 'e' for down.\n%d. press 's' for right.\n%d. press 'a' for left.\n",t+1,t+2,t+3,t+4);
    t+=4;
    printf("%d. Press 'o' to move camera left.\n%d. Press 'p' to move camera right.\n",t+1,t+2);
    t+=2;
    printf("%d. Press '+' to zoom in.\n%d. Press '-' for zoom out.\n",t+1,t+2);
    t+=2;
    printf("%d. Press b,n,m for operate with light1,light2 and CSE light respectively.\n",t++);
    printf("   1. Press '1' for add ambient.\n");
    printf("   2. Press '2' for reduce ambient.\n");
    printf("   3. Press '3' for add diffuse.\n");
    printf("   4. Press '4' for reduce diffuse.\n");

    printf("   5. Press '5' for add specular light.\n");
    printf("   6. Press '6' for reduce specular light.\n");
    printf("   7. Press ESC key for exit this operation and goto main programme\n");

    printf("%d. Press ESC key for exit the main programme\n",t++);

    //init();
    glutMainLoop();


    return 0;
}
