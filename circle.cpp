#include<GL/glut.h>
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<cstdlib>

float r,cx,cy;

void myInit()

{

glClearColor(1.0,1.0,1.0,0.0);

glColor3f(0.0f,0.0f,0.0f);

glPointSize(1);

glMatrixMode(GL_PROJECTION);

glLoadIdentity();

gluOrtho2D(0.0,640.0,0.0,480.0);

}

void plot(float x,float y)
{
glBegin(GL_POINTS);
glVertex2d(cx+x,cy+y);
glVertex2d(cx-x,cy+y);
glVertex2d(cx+x,cy-y);
glVertex2d(cx-x,cy-y);
glVertex2d(cx+y,cy+x);
glVertex2d(cx-y,cy+x);
glVertex2d(cx+y,cy-x);
glVertex2d(cx-y,cy-x);
glEnd();
glFlush();
}
void myDisplay()
{

glClear(GL_COLOR_BUFFER_BIT);
float x,y,p;
x=0;
y=r;
plot(0,r);
p=1-r;
while(x<=y)
{
    if(p<0)
    {
    x=x+1;
    p=p+(2*x)+1;
    plot(x,y);
    std::cout<<"("<<x+cx<<","<<y+cy<<")\n";
    }
    else
    {
    x=x+1;
    y=y-1;
    p=p+(2*x)-(2*y)+1;
    plot(x,y);
    std::cout<<"("<<x+cx<<","<<y+cy<<")\n";
    }
}

}

int main(int argc,char* argv[])

{
std::cout<<"\nEnter the radius of the circle\n";
std::cin>>r;
std::cout<<"\nEnter the centre of the circle\n";
std::cin>>cx>>cy;

glutInit(&argc,argv);

glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

glutInitWindowSize(640,480);

glutCreateWindow("Circle");

glutDisplayFunc(myDisplay);

myInit();

glutMainLoop();

return 1;

}
