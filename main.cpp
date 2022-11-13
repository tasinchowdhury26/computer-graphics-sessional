#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <cstdlib>
#include <iostream>
void display_apartments();
using namespace std;

int day_mood = 1; // 1== day, 2 == afternoon, 3 == night
int car0x=350, car1x=25, car2x=250, trainx =300, planex=70;
int speed = 10;
bool move_now = false, rain = false;

float randomColor = 1 + (rand() % 9);

void display_trees();
void display_roadlights();
void drawCircle(float cx, float cy, float r, int num_segments);

void start_moving(int value)
{
    glutPostRedisplay();
    car0x = car0x+speed;
    car1x = car1x-speed;
    car2x = car2x-speed;
    planex = planex+(speed*1.1); //update: speed reduced (13 Nov 2022)
    trainx = trainx +(speed*1.6);//update: speed reduced (13 Nov 2022)

    if(car0x>500){
        car0x =0;
    }
    if(car1x<0){
        car1x = 500;
    }
    if(car2x<0){
        car2x = 500;
    }
    if(planex>500){
        planex= 0;
    }
    if(trainx>500){
        trainx = 0;
    }

    if(move_now == true){
        glutTimerFunc(100, start_moving, 0);
    }
}

void start_raining(int value)
{
    glutPostRedisplay();
    //rain start
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white
    glBegin(GL_LINES);
    for(int i = 0; i<1000; i=i+2){
        float randNum1 = rand()%(500 - (0) + 1) + (0);
        float randNum2 = rand()%(300- (0) + 1) + (0);
        glVertex2f(randNum1, randNum2);
        glVertex2f(randNum1, randNum2+2);
    }
    glEnd();
    //rain end

    if(rain == true){
        glutTimerFunc(100, start_raining, 0);
    }
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor ( 0.0,0.0,0.0, 0.0);
    glPushMatrix();


    //sky and apartment part start

    //sky and apartment part start
    if(day_mood<3){
        glColor3f(0.0f, 0.5f, 1.0f); //baby blur color
    }else{
        glColor3f(0.0f, 0.0f, 0.0f);//Black
    }
    glBegin(GL_POLYGON); //daclare sky and apartment area
    glVertex3f(0.0f,   160.0f, 0.0f);
    glVertex3f(500.0f, 160.0f, 0.0f);
    glVertex3f(500.0f, 300.0f, 0.0f);
    glVertex3f(0.0f,   300.0f, 0.0f);
    glEnd();

        //moon or sun part start
        float moon_or_sun_x1,moon_or_sun_y1,moon_or_sun_x2,moon_or_sun_y2;
        float circle_angle;
        double radius = 20;

        if(day_mood == 1 || day_mood == 2){
            moon_or_sun_x1 = 470,moon_or_sun_y1=275;
        } else {
            moon_or_sun_x1 = 55,moon_or_sun_y1=270;
        }

        if(day_mood ==1){
            glColor4f(1.0f, 1.0f, 0.0f, 0.0f); //yellow color
        }else if (day_mood == 2){
            glColor4f(1.0f, 0.5f, 0.0f, 0.0f); //orange color
        }else{
            glColor4f(1.0f, 1.0f, 1.0f, 0.0f); //white
        }

        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(moon_or_sun_x1,moon_or_sun_y1);


    for (circle_angle=1.0f;circle_angle<360.0f;circle_angle+=0.2)
        {
            moon_or_sun_x2 = moon_or_sun_x1+sin(circle_angle)*radius;
            moon_or_sun_y2 = moon_or_sun_y1+cos(circle_angle)*radius;
            glVertex2f(moon_or_sun_x2,moon_or_sun_y2);
        }
        glEnd();
        //moon or sun part end


        /*plane part starts*/
        if(day_mood<3){
            glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white body
        }else{
            glColor3f(0.5f, 0.5f, 0.5f);//Violet body
        }

        glBegin(GL_POLYGON);
        glVertex3f(planex,   268.0f, 0.0f);
        glVertex3f(planex+20.0f, 253.0f, 0.0f);
        glVertex3f(planex+95.0f, 253.0f, 0.0f);
        glVertex3f(planex+100.0f,   262.0f, 0.0f);
        glVertex3f(planex+88.0f,   268.0f, 0.0f);
        glEnd();
        if(day_mood ==1|| day_mood==2){
            glColor4f(1.0f, 1.0f, 0.0f, 0.0f);//yellow headlight
        } else {
            glColor4f(1.0f, 0.0f, 0.0f, 0.0f);//red
        }
        glBegin(GL_POLYGON);
        glVertex3f(planex+3.0f,   268.0f, 0.0f);
        glVertex3f(planex, 280.0f, 0.0f);
        glVertex3f(planex+10.0f, 280.0f, 0.0f);
        glVertex3f(planex+20.0f,   268.0f, 0.0f);
        glEnd();
        glColor3f(0.0f, 0.1f, 0.0f);//Forest Green wings
        glBegin(GL_POLYGON);
        glVertex3f(planex+55.0f,   253.0f, 0.0f);
        glVertex3f(planex+40.0f, 260.0f, 0.0f);
        glVertex3f(planex+48.0f, 260.0f, 0.0f);
        glVertex3f(planex+80.0f,   253.0f, 0.0f);
        glEnd();
        if(day_mood ==1|| day_mood==2){
            glColor3f(0.0f, 0.0f, 1.0f);//Blue
        } else {
            glColor4f(1.0f, 1.0f, 0.0f, 0.0f);//yellow headlight
        }
        glBegin(GL_POLYGON);
        glVertex3f(planex+98.0f,   262.0f, 0.0f);
        glVertex3f(planex+90.0f, 262.0f, 0.0f);
        glVertex3f(planex+90.0f, 265.0f, 0.0f);
        glEnd();

        /*plane part ends*/

    //show apartments
    display_apartments();

    //sky and apartment part end

    /*green horizon on the back starts*/

    glColor3f(0.1f, 0.7f, 0.3f);//Green
    glBegin(GL_POLYGON);
    glVertex3f(0.0f,   131.0f, 0.0f);
    glVertex3f(500.0f, 131.0f, 0.0f);
    glVertex3f(500.0f, 160.0f, 0.0f);
    glVertex3f(0.0f,   160.0f, 0.0f);
    glEnd();
    /*green horizon on the back ends*/

    /*rail line starts*/
    glColor3f(0.1f, 0.7f, 0.3f);//Green
    glBegin(GL_POLYGON);
    glVertex3f(0.0f,   140.0f, 0.0f);
    glVertex3f(500.0f, 140.0f, 0.0f);
    glVertex3f(500.0f, 160.0f, 0.0f);
    glVertex3f(0.0f,   160.0f, 0.0f);
    glEnd();

    //train starts
            //rail line
            glBegin(GL_POLYGON);
            glColor3f(0.0f, 0.0f, 0.0f);//Black
            glVertex3f(0.0f,   135.0f, 0.0f);
            glVertex3f(500.0f, 135.0f, 0.0f);
            glVertex3f(500.0f, 140.0f, 0.0f);
            glVertex3f(0.0f, 140.0f, 0.0f);
            glEnd();

            glColor4f(0.1f, 0.2f, 0.1f, 0.6f);//body
            glBegin(GL_POLYGON);
            glVertex3f(trainx,   140.0f, 0.0f);
            glVertex3f(trainx+25.0f, 140.0f, 0.0f);
            glVertex3f(trainx+25.0f, 155.0f, 0.0f);
            glVertex3f(trainx, 155.0f, 0.0f);

            glColor4f(0.4f, 0.1f, 0.1f, 0.0f); //frontPart
            glVertex3f(trainx+25.0f, 140.0f, 0.0f);
            glVertex3f(trainx+38.0f, 140.0f, 0.0f);
            glVertex3f(trainx+38.0f, 150.0f, 0.0f);
            glVertex3f(trainx+25.0f, 150.0f, 0.0f);
            glEnd();
    /*train part ends*/


    /*park part start*/

    //show the ground in the park
    glColor4f(0.7f, 0.5f, 0.2f, 1.0f);//orange/brown
    glBegin(GL_POLYGON);
    glVertex3f(0.0f,   71.0f, 0.0f);
    glVertex3f(500.0f, 71.0f, 0.0f);
    glVertex3f(500.0f, 130.0f, 0.0f);
    glVertex3f(0.0f,   130.0f, 0.0f);
    glEnd();

    //show trees in the park
    display_trees();

    //show roadlights
    display_roadlights();

    /*park part end*/

    //road part start
    glColor3f(0.1f, 0.1f, 0.1f); //dark gray color
    glBegin(GL_POLYGON);
    glVertex3f(0.0f,   10.0f, 0.0f);
    glVertex3f(500.0f, 10.0f, 0.0f);
    glVertex3f(500.0f, 70.0f, 0.0f);
    glVertex3f(0.0f,   70.0f, 0.0f);
    glEnd();
    //road part end

    //road top border part start
    for(int i = 0; i<10; i++){
        if(i%2 == 0){
            glColor4f(1.0f, 1.0f, 1.0f, 0.0f); //white color
            glBegin(GL_POLYGON);
            glVertex3f(i*50.0f,       70.0f, 0.0f);
            glVertex3f(i*50.0f+50.0f, 70.0f, 0.0f);
            glVertex3f(i*50.0f+50.0f, 75.0f, 0.0f);
            glVertex3f(i*50.0f,       75.0f, 0.0f);
            glEnd();
        }
        else{
            glColor3f(0.0f, 0.0f, 0.0f); //black color
            glBegin(GL_POLYGON);
            glVertex3f(i*50.0f,       70.0f, 0.0f);
            glVertex3f(i*50.0f+50.0f, 70.0f, 0.0f);
            glVertex3f(i*50.0f+50.0f, 75.0f, 0.0f);
            glVertex3f(i*50.0f,       75.0f, 0.0f);
            glEnd();
        }
    }
    //road top border part end
    /*car part starts*/

     //car 0
            glColor3f(0.0f, 0.0f, 1.0f);//Blue body
            glBegin(GL_POLYGON);
            glVertex3f(car0x,   38.0f, 0.0f);
            glVertex3f(car0x+52.0f,   38.0f, 0.0f);
            glVertex3f(car0x+52.0f,   42.0f, 0.0f);
            glVertex3f(car0x+47.0f, 55.0f, 0.0f);
            glVertex3f(car0x+42.0f, 55.0f, 0.0f);
            glVertex3f(car0x+35.0f, 65.0f, 0.0f);
            glVertex3f(car0x+13.0f,   65.0f, 0.0f);
            glVertex3f(car0x+8.0f,   55.0f, 0.0f);
            glVertex3f(car0x,   55.0f, 0.0f);
            glEnd();
            if(day_mood == 1){
                glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white headlight
            } else if(day_mood==2){
                glColor4f(1.0f, 1.0f, 0.0f, 0.0f);//yellow headlight
            } else {
                glColor4f(1.0f, 0.0f, 0.0f, 0.0f);//red
            }
            glBegin(GL_POLYGON);
            glVertex3f(car0x,        45.0f, 0.0f);
            glVertex3f(car0x+6.0f,   45.0f, 0.0f);
            glVertex3f(car0x+8.0f,   49.0f, 0.0f);
            glVertex3f(car0x,        49.0f, 0.0f);
            glEnd();
            glColor3f(0.0f, 0.0f, 0.0f);//Black tire back
            drawCircle(car0x+13,38,5.0,20);
            drawCircle(car0x+40,38,5.0,20);
    /*car0 part ends*/

    //car 1
            glColor3f(0.0f, 0.5f, 0.5f);//Blue-Green body
            glBegin(GL_POLYGON);
            glVertex3f(car1x,   18.0f, 0.0f);
            glVertex3f(car1x, 22.0f, 0.0f);
            glVertex3f(car1x+5.0f, 35.0f, 0.0f);
            glVertex3f(car1x+10.0f, 35.0f, 0.0f);
            glVertex3f(car1x+17.0f,   45.0f, 0.0f);
            glVertex3f(car1x+40.0f,   45.0f, 0.0f);
            glVertex3f(car1x+45.0f,   35.0f, 0.0f);
            glVertex3f(car1x+57.0f,   35.0f, 0.0f);
            glVertex3f(car1x+57.0f,   18.0f, 0.0f);
            glEnd();
            if(day_mood == 1){
                glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white headlight
            } else if(day_mood==2){
                glColor4f(1.0f, 1.0f, 0.0f, 0.0f);//yellow headlight
            } else {
                glColor4f(1.0f, 0.0f, 0.0f, 0.0f);//red
            }
            glBegin(GL_POLYGON);
            glVertex3f(car1x+57.0f,   25.0f, 0.0f);
            glVertex3f(car1x+51.0f,   25.0f, 0.0f);
            glVertex3f(car1x+49.0f,   29.0f, 0.0f);
            glVertex3f(car1x+57.0f,   29.0f, 0.0f);
            glEnd();
            glColor3f(0.0f, 0.0f, 0.0f);//Black tire back
            drawCircle(car1x+13,18,5.0,20);
            drawCircle(car1x+45,18,5.0,20);
    /*car part ends*/

    //car ২
            glColor3f(0.0f, 0.0f, 1.0f);//Blue body
            glBegin(GL_POLYGON);
            glVertex3f(car2x,   18.0f, 0.0f);
            glVertex3f(car2x, 22.0f, 0.0f);
            glVertex3f(car2x+5.0f, 35.0f, 0.0f);
            glVertex3f(car2x+10.0f, 35.0f, 0.0f);
            glVertex3f(car2x+17.0f,   45.0f, 0.0f);
            glVertex3f(car2x+40.0f,   45.0f, 0.0f);
            glVertex3f(car2x+45.0f,   35.0f, 0.0f);
            glVertex3f(car2x+57.0f,   35.0f, 0.0f);
            glVertex3f(car2x+57.0f,   18.0f, 0.0f);
            glEnd();
            if(day_mood == 1){
                glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white headlight
            } else if(day_mood==2){
                glColor4f(1.0f, 1.0f, 0.0f, 0.0f);//yellow headlight
            } else {
                glColor4f(1.0f, 0.0f, 0.0f, 0.0f);//red
            }
            glBegin(GL_POLYGON);
            glVertex3f(car2x+57.0f,   25.0f, 0.0f);
            glVertex3f(car2x+51.0f,   25.0f, 0.0f);
            glVertex3f(car2x+49.0f,   29.0f, 0.0f);
            glVertex3f(car2x+57.0f,   29.0f, 0.0f);
            glEnd();
            glColor3f(0.0f, 0.0f, 0.0f);//Black tire back
            drawCircle(car2x+13,18,5.0,20);
            drawCircle(car2x+45,18,5.0,20);
    /*car2 part ends*/


//road bottom border part start
    for(int i = 0; i<10; i++){
        if(i%2 == 0){
            glColor3f(0.0f, 0.0f, 0.0f); //black color
            glBegin(GL_POLYGON);
            glVertex3f(i*50.0f,       0.0f, 0.0f);
            glVertex3f(i*50.0f+50.0f, 0.0f, 0.0f);
            glVertex3f(i*50.0f+50.0f, 10.0f, 0.0f);
            glVertex3f(i*50.0f,       10.0f, 0.0f);
            glEnd();
        }
        else{
            glColor4f(1.0f, 1.0f, 1.0f, 0.0f); //white color
            glBegin(GL_POLYGON);
            glVertex3f(i*50.0f,       0.0f, 0.0f);
            glVertex3f(i*50.0f+50.0f, 0.0f, 0.0f);
            glVertex3f(i*50.0f+50.0f, 10.0f, 0.0f);
            glVertex3f(i*50.0f,       10.0f, 0.0f);
            glEnd();
        }
    }
    //road bottom border part end

    if(rain ==true){
        start_raining(1);
    }


	glPopMatrix();
	glFlush();
}

void changeDay(int value)
{
    glutPostRedisplay();
}


void init(void)
{
	glOrtho(0.0, 500.0, 0.0, 300.0, -1.0, 1.0);
}

void my_keyboard(unsigned char key, int x, int y)
{
	switch (key) {
		case 'm':
		case 'M':
            if(move_now ==false){
                move_now = true;
            }else{
                move_now = false;
            }
			start_moving(0);
			break;
        case 'd':
		case 'D':
            day_mood=1;
			changeDay(0);
			break;
        case 'a':
		case 'A':
            day_mood=2;
			changeDay(0);
			break;
        case 'n':
		case 'N':
            day_mood=3;
			changeDay(0);
			break;

        case 's':
		case 'S':
            if(speed>1){
                speed= speed -1;
                glutPostRedisplay();
            }
			break;
        case 'f':
		case 'F':
            if(speed<30){
                speed= speed +1;
                glutPostRedisplay();
            }
			break;
        case 'r':
		case 'R':
            if(rain == false){
                rain = true;
            }else{
                rain = false;
            }
            start_raining(1);
			break;

	  default:
            cout<<"invalid keypress";
			break;
	}
}

int main(int argc, char** argv)         //omit the arguments for windows
{
    glutInit(&argc, argv);              //omit this line for windows too
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (1280, 720);
	glutInitWindowPosition (150, 50);
	glutCreateWindow ("Horizon.");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(my_keyboard);
	glutMainLoop();
	return 0;   /* ANSI C requires main to return int. */
}


void display_apartments(){

    glColor3f(0.0f, 0.5f, 0.5f);//Blue-Green
    glColor3f(0.1f, 0.0f, 0.1f);//Dark Purple
    glColor3f(0.5f, 0.5f, 0.5f);//Violet
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);//purple
    glColor3f(2.0f, 0.5f, 1.0f);//Lilac

    for(int i = 2; i<12; i++){
        if(i%2 == 0){
            glColor3f(0.4f, 0.3f, 0.2f);//Custom Brown
            glBegin(GL_POLYGON);
            glVertex3f(i*35.0f,       160.0f, 0.0f);
            glVertex3f(i*35.0f+28.0f, 160.0f, 0.0f);
            glVertex3f(i*35.0f+28.0f, 220.0f, 0.0f);
            glVertex3f(i*35.0f,       220.0f, 0.0f);
            glEnd();

            //drawing windows
            for(int j=8;j<11;j++){
            if(day_mood==1){
                glColor3f(0.1f, 0.1f, 0.1f);//Dark grey
            } else if(day_mood==2) {
                glColor3f(0.1f, 0.1f, 0.1f);//Dark grey
            } else {
                glColor4f(1.0f, 1.0f, 0.0f, 0.0f);//yellow
            }
            glBegin(GL_POLYGON);
            glVertex3f(i*35.0f+4,  j*20+5, 0.0f);
            glVertex3f(i*35.0f+12, j*20+5, 0.0f);
            glVertex3f(i*35.0f+12, j*20+15, 0.0f);
            glVertex3f(i*35.0f+4,  j*20+15, 0.0f);
            glEnd();
            }

            //drawing windows
            for(int j=8;j<11;j++){
            if(day_mood==1){
                glColor3f(0.1f, 0.1f, 0.1f);//Dark grey
            } else if(day_mood==2) {
                glColor3f(0.1f, 0.1f, 0.1f);//Dark grey
            } else {
                glColor4f(1.0f, 1.0f, 0.0f, 0.0f);//yellow
            }
            glBegin(GL_POLYGON);
            glVertex3f(i*35.0f+16,  j*20+5, 0.0f);
            glVertex3f(i*35.0f+24, j*20+5, 0.0f);
            glVertex3f(i*35.0f+24, j*20+15, 0.0f);
            glVertex3f(i*35.0f+16,  j*20+15, 0.0f);
            glEnd();
            }

        }
        else{
            glColor3f(0.4f, 0.3f, 0.6f);//Custom Brown
            glBegin(GL_POLYGON);
            glVertex3f(i*35.0f,       160.0f, 0.0f);
            glVertex3f(i*35.0f+30.0f, 160.0f, 0.0f);
            glVertex3f(i*35.0f+30.0f, 240.0f, 0.0f);
            glVertex3f(i*35.0f,       240.0f, 0.0f);
            glEnd();

            //drawing windows
            for(int j=8;j<12;j++){
            if(day_mood==1){
                glColor3f(0.1f, 0.1f, 0.1f);//Dark grey
            } else if(day_mood==2) {
                glColor3f(0.1f, 0.1f, 0.1f);//Dark grey
            } else {
                glColor4f(1.0f, 1.0f, 0.0f, 0.0f);//yellow
            }
            glBegin(GL_POLYGON);
            glVertex3f(i*35.0f+4,  j*20+5, 0.0f);
            glVertex3f(i*35.0f+12, j*20+5, 0.0f);
            glVertex3f(i*35.0f+12, j*20+15, 0.0f);
            glVertex3f(i*35.0f+4,  j*20+15, 0.0f);
            glEnd();
            }

            //drawing windows
            for(int j=8;j<12;j++){
            if(day_mood==1){
                glColor3f(0.1f, 0.1f, 0.1f);//Dark grey
            } else if(day_mood==2) {
                glColor3f(0.1f, 0.1f, 0.1f);//Dark grey
            } else {
                glColor4f(1.0f, 1.0f, 0.0f, 0.0f);//yellow
            }
            glBegin(GL_POLYGON);
            glVertex3f(i*35.0f+16,  j*20+5, 0.0f);
            glVertex3f(i*35.0f+24, j*20+5, 0.0f);
            glVertex3f(i*35.0f+24, j*20+15, 0.0f);
            glVertex3f(i*35.0f+16,  j*20+15, 0.0f);
            glEnd();
            }
        }
    }
}

void display_roadlights(){
    int x_axis = 100;
    for( x_axis=100 ; x_axis<=400; x_axis = x_axis+100){
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);//Black
        glVertex2f(x_axis,75);
        glVertex2f(x_axis,120);

        glVertex2f(x_axis-20,120);
        glVertex2f(x_axis+20,120);
        glEnd();
        if(day_mood == 1){
            glColor4f(1.0f, 0.0f, 0.0f, 0.0f);//red
        } else if(day_mood==2){
            glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white headlight
        } else {
            glColor4f(1.0f, 1.0f, 0.0f, 0.0f);//yellow headlight
        }
        glBegin(GL_POLYGON);
        glVertex3f(x_axis-20,120.0f, 0.0f);
        glVertex3f(x_axis-20,117.0f, 0.0f);
        glVertex3f(x_axis-10,117.0f, 0.0f);
        glVertex3f(x_axis-10, 120.0f, 0.0f);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex3f(x_axis+20,120.0f, 0.0f);
        glVertex3f(x_axis+20,117.0f, 0.0f);
        glVertex3f(x_axis+10,117.0f, 0.0f);
        glVertex3f(x_axis+10, 120.0f, 0.0f);
        glEnd();


    }
}
void display_trees(){
    //tree 1
    glColor3f(0.0f, 1.0f, 0.0f);//Green
    glBegin(GL_POLYGON); //tree 1 top
    glVertex3f(70.0f,   155.0f, 0.0f);
    glVertex3f(55.0f, 115.0f, 0.0f);
    glVertex3f(85.0f, 115.0f, 0.0f);
    glEnd();
    glColor3f(0.0f, 1.0f, 0.0f);//Green
    glBegin(GL_POLYGON); //tree 1 middle
    glVertex3f(70.0f,   130.0f, 0.0f);
    glVertex3f(55.0f, 90.0f, 0.0f);
    glVertex3f(85.0f, 90.0f, 0.0f);
    glEnd();
    glColor3f(0.1f, 0.0f, 0.0f);//Brown
    glBegin(GL_POLYGON); //tree 1 bottom
    glVertex3f(70.0f,   100.0f, 0.0f);
    glVertex3f(68.0f, 70.0f, 0.0f);
    glVertex3f(72.0f, 70.0f, 0.0f);
    glEnd();

    //tree 2
    glColor3f(0.0f, 1.0f, 0.0f);//Green
    glBegin(GL_POLYGON); //tree 2 top
    glVertex3f(120.0f,   155.0f, 0.0f);
    glVertex3f(105.0f, 115.0f, 0.0f);
    glVertex3f(135.0f, 115.0f, 0.0f);
    glEnd();
    glColor3f(0.0f, 1.0f, 0.0f);//Green
    glBegin(GL_POLYGON); //tree 2 middle
    glVertex3f(120.0f,   130.0f, 0.0f);
    glVertex3f(105.0f, 90.0f, 0.0f);
    glVertex3f(135.0f, 90.0f, 0.0f);
    glEnd();
    glColor3f(0.1f, 0.0f, 0.0f);//Brown
    glBegin(GL_POLYGON); //tree 2 bottom
    glVertex3f(120.0f,   100.0f, 0.0f);
    glVertex3f(118.0f, 70.0f, 0.0f);
    glVertex3f(122.0f, 70.0f, 0.0f);
    glEnd();

    //tree 3
    glColor3f(0.0f, 1.0f, 0.0f);//Green
    glBegin(GL_POLYGON); //tree 3 top
    glVertex3f(170.0f,   155.0f, 0.0f);
    glVertex3f(155.0f, 115.0f, 0.0f);
    glVertex3f(185.0f, 115.0f, 0.0f);
    glEnd();
    glColor3f(0.0f, 1.0f, 0.0f);//Green
    glBegin(GL_POLYGON); //tree 3 middle
    glVertex3f(170.0f,   130.0f, 0.0f);
    glVertex3f(155.0f, 90.0f, 0.0f);
    glVertex3f(185.0f, 90.0f, 0.0f);
    glEnd();
    glColor3f(0.1f, 0.0f, 0.0f);//Brown
    glBegin(GL_POLYGON); //tree 3 bottom
    glVertex3f(170.0f,   100.0f, 0.0f);
    glVertex3f(168.0f, 70.0f, 0.0f);
    glVertex3f(172.0f, 70.0f, 0.0f);
    glEnd();

    //tree 4
    glColor3f(0.0f, 1.0f, 0.0f);//Green
    glBegin(GL_POLYGON); //tree 4 top
    glVertex3f(220.0f,   155.0f, 0.0f);
    glVertex3f(205.0f, 115.0f, 0.0f);
    glVertex3f(235.0f, 115.0f, 0.0f);
    glEnd();
    glColor3f(0.0f, 1.0f, 0.0f);//Green
    glBegin(GL_POLYGON); //tree 4 middle
    glVertex3f(220.0f,   130.0f, 0.0f);
    glVertex3f(205.0f, 90.0f, 0.0f);
    glVertex3f(235.0f, 90.0f, 0.0f);
    glEnd();
    glColor3f(0.1f, 0.0f, 0.0f);//Brown
    glBegin(GL_POLYGON); //tree 4 bottom
    glVertex3f(220.0f,   100.0f, 0.0f);
    glVertex3f(218.0f, 70.0f, 0.0f);
    glVertex3f(222.0f, 70.0f, 0.0f);
    glEnd();

    //tree 5
    glColor3f(0.0f, 1.0f, 0.0f);//Green
    glBegin(GL_POLYGON); //tree 5 top
    glVertex3f(270.0f,   155.0f, 0.0f);
    glVertex3f(255.0f, 115.0f, 0.0f);
    glVertex3f(285.0f, 115.0f, 0.0f);
    glEnd();
    glColor3f(0.0f, 1.0f, 0.0f);//Green
    glBegin(GL_POLYGON); //tree 5 middle
    glVertex3f(270.0f,   130.0f, 0.0f);
    glVertex3f(255.0f, 90.0f, 0.0f);
    glVertex3f(285.0f, 90.0f, 0.0f);
    glEnd();
    glColor3f(0.1f, 0.0f, 0.0f);//Brown
    glBegin(GL_POLYGON); //tree 5 bottom
    glVertex3f(270.0f,   100.0f, 0.0f);
    glVertex3f(268.0f, 70.0f, 0.0f);
    glVertex3f(272.0f, 70.0f, 0.0f);
    glEnd();

    //tree 6
    glColor3f(0.0f, 1.0f, 0.0f);//Green
    glBegin(GL_POLYGON); //tree 6 top
    glVertex3f(320.0f,   155.0f, 0.0f);
    glVertex3f(305.0f, 115.0f, 0.0f);
    glVertex3f(335.0f, 115.0f, 0.0f);
    glEnd();
    glColor3f(0.0f, 1.0f, 0.0f);//Green
    glBegin(GL_POLYGON); //tree 6 middle
    glVertex3f(320.0f,   130.0f, 0.0f);
    glVertex3f(305.0f, 90.0f, 0.0f);
    glVertex3f(335.0f, 90.0f, 0.0f);
    glEnd();
    glColor3f(0.1f, 0.0f, 0.0f);//Brown
    glBegin(GL_POLYGON); //tree 6 bottom
    glVertex3f(320.0f,   100.0f, 0.0f);
    glVertex3f(318.0f, 70.0f, 0.0f);
    glVertex3f(322.0f, 70.0f, 0.0f);
    glEnd();

    //tree 7
    glColor3f(0.0f, 1.0f, 0.0f);//Green
    glBegin(GL_POLYGON); //tree 7 top
    glVertex3f(370.0f,   155.0f, 0.0f);
    glVertex3f(355.0f, 115.0f, 0.0f);
    glVertex3f(385.0f, 115.0f, 0.0f);
    glEnd();
    glColor3f(0.0f, 1.0f, 0.0f);//Green
    glBegin(GL_POLYGON); //tree 7 middle
    glVertex3f(370.0f,   130.0f, 0.0f);
    glVertex3f(355.0f, 90.0f, 0.0f);
    glVertex3f(385.0f, 90.0f, 0.0f);
    glEnd();
    glColor3f(0.1f, 0.0f, 0.0f);//Brown
    glBegin(GL_POLYGON); //tree 7 bottom
    glVertex3f(370.0f,   100.0f, 0.0f);
    glVertex3f(368.0f, 70.0f, 0.0f);
    glVertex3f(372.0f, 70.0f, 0.0f);
    glEnd();

    //tree 7
    glColor3f(0.0f, 1.0f, 0.0f);//Green
    glBegin(GL_POLYGON); //tree 7 top
    glVertex3f(420.0f,   155.0f, 0.0f);
    glVertex3f(405.0f, 115.0f, 0.0f);
    glVertex3f(435.0f, 115.0f, 0.0f);
    glEnd();
    glColor3f(0.0f, 1.0f, 0.0f);//Green
    glBegin(GL_POLYGON); //tree 7 middle
    glVertex3f(420.0f,   130.0f, 0.0f);
    glVertex3f(405.0f, 90.0f, 0.0f);
    glVertex3f(435.0f, 90.0f, 0.0f);
    glEnd();
    glColor3f(0.1f, 0.0f, 0.0f);//Brown
    glBegin(GL_POLYGON); //tree 7 bottom
    glVertex3f(420.0f,   100.0f, 0.0f);
    glVertex3f(418.0f, 70.0f, 0.0f);
    glVertex3f(422.0f, 70.0f, 0.0f);
    glEnd();

}

void drawCircle(float cx, float cy, float r, int num_segments)
{
    float theta = 3.1415926 * 2 / float(num_segments);
    float tangetial_factor = tanf(theta);
    float radial_factor = cosf(theta);
    float x = r;//we start at angle = 0

    float y = 0;
    glLineWidth(2);
    glBegin(GL_TRIANGLE_FAN);
    for (int ii = 0; ii < num_segments; ii++)
    {
        glVertex2f(x + cx, y + cy);//output vertex

        float tx = -y;
        float ty = x;

        x += tx * tangetial_factor;
        y += ty * tangetial_factor;

        x *= radial_factor;
        y *= radial_factor;
    }
    glEnd();
}


