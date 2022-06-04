 #include <iostream>

#include <GL/gl.h>

#include <GL/glut.h>



#include <windows.h>

using namespace std;

GLfloat positionShip = 0.0f;

GLfloat speedShip = 0.01f;



GLfloat positionCloud = 0.0f;

GLfloat speedCloud = 0.004f;



GLfloat positionSun = 0.0f;

GLfloat speedSun = 0.01f;



GLfloat positionCar = 0.0f;

GLfloat speedCar = 0.01f;



GLfloat status;



void updateShip(int value) {



    if(positionShip > 1.5)

    {

        positionShip = -1.0f;

    }

    else if(positionShip < -1.5)

    {

        positionShip = .2;

    }

    positionShip += speedShip;

	glutPostRedisplay();

	glutTimerFunc(120, updateShip, 0);

}

void updateCloud(int value) {



    if(positionCloud > 1.8)

    {

        positionCloud = -1.0f;

    }

    positionCloud += speedCloud;

	glutPostRedisplay();

	glutTimerFunc(120, updateCloud, 0);

}

void updateCar(int value) {



    if(positionCar > 1.8)

    {

        positionCar = -1.0f;

    }

    else if(positionCar < -1.5)

    {



        positionCar = 1.3;

    }

    positionCar += speedCar;

	glutPostRedisplay();

	glutTimerFunc(120, updateCar, 0);

}



void handleKeypress(unsigned char key, int x, int y) {



	switch (key) {

    case 'u':

        positionSun = 0.45;

        break;

    case 'd':

        positionSun = 0.0;

        break;

    case 'i':

        speedShip += 0.01;

        break;

    case 's':

        speedShip -=0.01;

        break;

    case 'r':

        speedCar += 0.01;

        break;

    case 'b':

        speedCar -= 0.01;

        break;

    glutPostRedisplay();

	}

}

void display()

{

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glClear(GL_COLOR_BUFFER_BIT);



    /**SKY VIEW**/



	glBegin(GL_POLYGON);

	glColor3ub(162,197,229);

	glVertex2f(-1, .2);

	glVertex2f(1,.2);

	glVertex2f(1,1);

	glVertex2f(-1,1);

	glEnd();

	/**SKY VIEW END**/



	/**Sun Start**/

    glPushMatrix();

    glTranslatef(0,positionSun,0);



    glPushMatrix();

    glTranslated(0,.35,.1);

    glColor3ub(255,128,0);

    glutSolidSphere (0.15, 30, 30);

	glPopMatrix();



    glPopMatrix();

    /**Sun End**/


	/**Cloud Start**/

    /*Cloud 1*/

    glPushMatrix();

    glTranslatef(positionCloud,0,0);



    glPushMatrix();

    glTranslatef(-.85,.85,0);

    glColor3f(255,255,255);

    glutSolidSphere (0.1, 30, 30);

	glPopMatrix();



	glPushMatrix();

    glTranslatef(-.75,.85,0);

    glColor3f(255,255,255);

    glutSolidSphere (0.1, 30, 30);

	glPopMatrix();



	glPushMatrix();

    glTranslatef(-.65,.85,0);

    glColor3f(255,255,255);

    glutSolidSphere (0.1, 30, 30);

	glPopMatrix();

	/*Cloud 1 End*/

	/*Cloud 2*/

	glPushMatrix();

    glTranslatef(-.15,.85,0);

    glColor3f(255,255,255);

    glutSolidSphere (0.1, 30, 30);

	glPopMatrix();



	glPushMatrix();

    glTranslatef(-.05,.85,0);

    glColor3f(255,255,255);

    glutSolidSphere (0.1, 30, 30);

	glPopMatrix();



	glPushMatrix();

    glTranslatef(.05,.85,0);

    glColor3f(255,255,255);

    glutSolidSphere (0.1, 30, 30);

	glPopMatrix();

	/*Cloud 2 End*/

	/*Cloud 3*/

	glPushMatrix();

    glTranslatef(.45,.85,0);

    glColor3f(255,255,255);

    glutSolidSphere (0.1, 30, 30);

	glPopMatrix();

	glPushMatrix();

    glTranslatef(.55,.85,0);

    glColor3f(255,255,255);

    glutSolidSphere (0.1, 30, 30);

	glPopMatrix();

	glPushMatrix();

    glTranslatef(.65,.85,0);

    glColor3f(255,255,255);

    glutSolidSphere (0.1, 30, 30);

	glPopMatrix();



    glPopMatrix();

	/*Cloud 3 End*/

	/**Cloud End**/


	/**Hill 1**/

	glBegin(GL_POLYGON);

	glColor3ub(229,218,172);

	glVertex2f(-1, .2);

	glVertex2f(-.5, .2);

	glVertex2f(-.9, .5);

	glVertex2f(-1, .3);

	glEnd();

	/**Hill 1 End**/



    /**Hill 2**/

	glBegin(GL_POLYGON);

	glColor3ub(211, 191, 110);

	glVertex2f(-.6, .2);

	glVertex2f(0, .2);

	glVertex2f(-.2, .5);

	//glVertex2f(-1, .3);

	glEnd();

	/**Hill 2 End**/

    /**Hill 3**/

	glBegin(GL_POLYGON);

	glColor3ub(114, 98, 30);

	glVertex2f(-.7, .35);

	glVertex2f(-.55,.23);

	glVertex2f(-.4, .35);

	glVertex2f(-.55, .6);

	glEnd();

	/**Hill 3 End**/


	/**Hill 1**/

	glBegin(GL_POLYGON);

	glColor3ub(128,135,9);

	glVertex2f(1, .2);

	glVertex2f(.5, .2);

	glVertex2f(.9, .5);

	glVertex2f(1, .3);

	glEnd();

	/**Hill 1 End**/

    /**Hill 2**/

	glBegin(GL_POLYGON);

	glColor3ub(226,232,111);

	glVertex2f(.6, .2);

	glVertex2f(0, .2);

	glVertex2f(.2, .5);

	//glVertex2f(-1, .3);

	glEnd();

	/**Hill 2 End**/

    /**Hill 3**/

	glBegin(GL_POLYGON);

	glColor3ub(114, 98, 30);

	glVertex2f(.7, .35);

	glVertex2f(.55,.23);

	glVertex2f(.4, .35);

	glVertex2f(.55, .6);

	glEnd();

	/**Hill 3 End**/

    /**Ground Statring**/

    glPushMatrix();

    glTranslatef(0,0.1,0);


    glBegin(GL_POLYGON);

    glColor3ub(255,255,102);

    glVertex2f(-1,.2);

    glVertex2f(-1,-.5);

    glVertex2f(1,-.5);

    glVertex2f(1,.2);

    glEnd();

    /**Ground End**/

    /**House Roof 1**/

    glBegin(GL_POLYGON);

    glColor3ub(255,229,204);

    glVertex2f(-.8,.15);

    glVertex2f(-.9,-.05);

    glVertex2f(-.7,-.05);

    glEnd();

    /**House Roof 1 End**/

    /**House 1 Body Start**/

    glBegin(GL_POLYGON);

    glColor3ub(128,128,128);

    glVertex2f(-.9,-.05);

    glVertex2f(-.9,-.4);

    glVertex2f(-.7,-.4);

    glVertex2f(-.7,-.05);

    glEnd();

    /**House 1 Body End**/

    /**House 1 Footer Start**/

    glBegin(GL_POLYGON);

    glColor3ub(255,153,153);

    glVertex2f(-.95, -.4);

    glVertex2f(-.95,-.48);

    glVertex2f(-.65,-.48);

    glVertex2f(-.65,-.4);

    glEnd();

    /**House 1 Footer End**/

    /**House 1 Door**/

    glBegin(GL_POLYGON);

    glColor3ub(0,0,0);

    glVertex2f(-.82, -.4);

    glVertex2f(-.78,-.4);

    glVertex2f(-.78,-.25);

    glVertex2f(-.82,-.25);

    glEnd();

    /**House 1 Door End**/

    /**House 2 Start**/

    glPushMatrix();

    glTranslatef(.52,0,0);

    /**House 2 Roof**/

    glBegin(GL_POLYGON);

    glColor3ub(153,204,255);

    glVertex2f(-.8,.15);

    glVertex2f(-.9,-.05);

    glVertex2f(-.7,-.05);

    glEnd();

    /**House Roof 2 End**/

    /**House 2 Body Start**/

    glBegin(GL_POLYGON);

    glColor3ub(128,128,128);

    glVertex2f(-.9,-.05);

    glVertex2f(-.9,-.4);

    glVertex2f(-.7,-.4);

    glVertex2f(-.7,-.05);

    glEnd();

    /**House 2 Body End**/

    /**House 2 Footer Start**/

    glBegin(GL_POLYGON);

    glColor3ub(204,204,0);

    glVertex2f(-.95, -.4);

    glVertex2f(-.95,-.48);

    glVertex2f(-.65,-.48);

    glVertex2f(-.65,-.4);

    glEnd();

    /**House 2 Footer End**/

    /**House 2 Door**/

    glBegin(GL_POLYGON);

    glColor3ub(255,255,255);

    glVertex2f(-.82, -.4);

    glVertex2f(-.78,-.4);

    glVertex2f(-.78,-.25);

    glVertex2f(-.82,-.25);

    glEnd();

    /**House 2 Door End **/

    glPopMatrix();

    /**House 2 End**/

    /**Tree 1**/

    glBegin(GL_POLYGON);

    glColor3ub(102,51,0);

    glVertex2f(-.5,-.48);

    glVertex2f(-.45,-.48);

    glVertex2f(-.45,-.2);

    glVertex2f(-.5,-.2);

    glEnd();



    glBegin(GL_TRIANGLES);

     glColor3ub(0,153,76);

    glVertex2f(-.54,-.3);

    glVertex2f(-.4, -.3);

    glVertex2f(-.48,-.22);

    glEnd();



    glBegin(GL_TRIANGLES);

    glColor3ub(0,204,102);

    glVertex2f(-.54,-.25);

    glVertex2f(-.4,-.25);

    glVertex2f(-.48,-.18);

    glEnd();



    glBegin(GL_TRIANGLES);

    glColor3ub(0,255,128);

    glVertex2f(-.54,-.22);

    glVertex2f(-.4,-.22);

    glVertex2f(-.48,-.1);

    glEnd();

    /**Tree 1 End**/

    /**Tree 3**/

    glPushMatrix();

    glTranslatef(-.47,0.3,0);

    glBegin(GL_POLYGON);

    glColor3ub(102,51,0);

    glVertex2f(-.5,-.48);

    glVertex2f(-.45,-.48);

    glVertex2f(-.45,-.2);

    glVertex2f(-.5,-.2);

    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(0,153,76);

    glVertex2f(-.54,-.3);

    glVertex2f(-.4, -.3);

    glVertex2f(-.48,-.22);

    glEnd();


    glBegin(GL_TRIANGLES);

     glColor3ub(0,204,102);

    glVertex2f(-.54,-.25);

    glVertex2f(-.4,-.25);

    glVertex2f(-.48,-.18);

    glEnd();


    glBegin(GL_TRIANGLES);

     glColor3ub(0,255,128);

    glVertex2f(-.54,-.22);

    glVertex2f(-.4,-.22);

    glVertex2f(-.48,-.1);

    glEnd();

    glPopMatrix();

    /**Tree 3 End**/

    /**Tree 2 Start**/

    glPushMatrix();

    glTranslatef(-.4,0,0);

    glBegin(GL_POLYGON);

    glColor3ub(102,51,0);

    glVertex2f(-.2,-.2);

    glVertex2f(-.15,-.2);

    glVertex2f(-.15,0);

    glVertex2f(-.2,0);

    glEnd();


    glBegin(GL_TRIANGLES);

    glColor3ub(0,255,0);

    glVertex2f(-.28,-.05);

    glVertex2f(-.05,-.05);

    glVertex2f(-.177,.01);

    glEnd();


    glBegin(GL_TRIANGLES);

    glColor3ub(0,255,0);

    glVertex2f(-.28,-.01);

    glVertex2f(-.05,-.01);

    glVertex2f(-.177,.08);

    glEnd();


    glBegin(GL_TRIANGLES);

    glColor3ub(0,255,0);

    glVertex2f(-.28,.05);

    glVertex2f(-.05,.05);

    glVertex2f(-.177,.15);

    glEnd();

    glPopMatrix();

    /**Tree 2 End**/

    /**Tree 4 Start**/

    glPushMatrix();

    glTranslatef(0.15,-0.1,0);

    glBegin(GL_POLYGON);

    glColor3ub(102,51,0);

    glVertex2f(-.2,-.2);

    glVertex2f(-.15,-.2);

    glVertex2f(-.15,0);

    glVertex2f(-.2,0);

    glEnd();

    glPopMatrix();


    glPushMatrix();

    glTranslatef(-.08,-.05,0);

    glColor3ub(0,153,76);

    glutSolidSphere (0.07, 30, 30);

	glPopMatrix();


	glPushMatrix();

    glTranslatef(-.06,.01,0);

    glColor3ub(0,153,76);

    glutSolidSphere (0.08, 30, 30);

	glPopMatrix();


	glPushMatrix();

    glTranslatef(0,0,0);

    glColor3ub(0,153,76);

    glutSolidSphere (0.09, 30, 30);

	glPopMatrix();


	glPushMatrix();

    glTranslatef(0.03,-.06,0);

    glColor3ub(0,153,76);

    glutSolidSphere (0.07, 30, 30);

	glPopMatrix();

    /**Tree 4 End**/

    /**School Start**/

    glPushMatrix();

    glTranslatef(.1,0,0);

    glBegin(GL_POLYGON);

    glColor3ub(102,51,0);

    glVertex2f(.1,-.45);

    glVertex2f(.1,-.5);

    glVertex2f(.9,-.5);

    glVertex2f(.9,-.45);

    glEnd();


    glBegin(GL_POLYGON);

    glColor3ub(102,102,0);

    glVertex2f(.2,-.45);

    glVertex2f(.8,-.45);

    glVertex2f(.8,-.1);

    glVertex2f(.2,-.1);

    glEnd();


    glBegin(GL_POLYGON);

    glColor3ub(0,0,255);

    glVertex2f(.1,-.1);

    glVertex2f(.9,-.1);

    glVertex2f(.8,.1);

    glVertex2f(.2,.1);

    glEnd();


    glBegin(GL_POLYGON);

    glColor3ub(255,178,102);

    glVertex2f(.3,.05);

    glVertex2f(.3,-.05);

    glVertex2f(.7,-.05);

    glVertex2f(.7,.05);

    glEnd();


    glColor3ub(128, 6, 77);

    glRasterPos2f(.4, -0.015);

    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'S');

    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'C');

    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'H');

    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'O');

    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'O');

    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'L');

    /**School Door**/

    glBegin(GL_POLYGON);

    glColor3ub(255,255,255);

    glVertex2f(.45,-.45);

    glVertex2f(.55,-.45);

    glVertex2f(.55,-.2);

    glVertex2f(.45,-.2);

    glEnd();

    /**School Door End**/

    /**School Left Window**/

    glBegin(GL_POLYGON);

    glColor3ub(255,255,255);

    glVertex2f(.25,-.2);

    glVertex2f(.25,-.32);

    glVertex2f(.32,-.32);

    glVertex2f(.32,-.2);

    glEnd();



    glBegin(GL_POLYGON);

    glColor3ub(255,255,255);

    glVertex2f(.35,-.2);

    glVertex2f(.35,-.32);

    glVertex2f(.42,-.32);

    glVertex2f(.42,-.2);

    glEnd();

    /**School Left Window End**/

    /**School Right Window**/

    glBegin(GL_POLYGON);

    glColor3ub(255,255,255);

    glVertex2f(.58,-.2);

    glVertex2f(.58, -.32);

    glVertex2f(.65,-.32);

    glVertex2f(.65,-.2);

    glEnd();


    glBegin(GL_POLYGON);

    glColor3ub(255,255,255);

    glVertex2f(.68,-.2);

    glVertex2f(.68, -.32);

    glVertex2f(.75,-.32);

    glVertex2f(.75,-.2);

    glEnd();

    glPopMatrix();

    /**School Right Window End**/

    /**School End**/


    /**Road STart**/

    glBegin(GL_POLYGON);

    glColor3ub(32,32,32);

    glVertex2f(-1,-.5);

    glVertex2f(-1,-.8);

    glVertex2f(1,-.8);

    glVertex2f(1,-.5);

    glEnd();



    glBegin(GL_POLYGON);

    glColor3ub(255,255,255);

    glVertex2f(-.9,-.62);

    glVertex2f(-.9,-.68);

    glVertex2f(-.7,-.68);

    glVertex2f(-.7,-.62);

    glEnd();


    glBegin(GL_POLYGON);

    glColor3ub(255,255,255);

    glVertex2f(-.5,-.62);

    glVertex2f(-.5,-.68);

    glVertex2f(-.3,-.68);

    glVertex2f(-.3,-.62);

    glEnd();


    glBegin(GL_POLYGON);

    glColor3ub(255,255,255);

    glVertex2f(-.1,-.62);

    glVertex2f(-.1,-.68);

    glVertex2f(.1,-.68);

    glVertex2f(.1,-.62);

    glEnd();


    glBegin(GL_POLYGON);

    glColor3ub(255,255,255);

    glVertex2f(.3,-.62);

    glVertex2f(.3,-.68);

    glVertex2f(.5,-.68);

    glVertex2f(.5,-.62);

    glEnd();



    glBegin(GL_POLYGON);

    glColor3ub(255,255,255);

    glVertex2f(.7,-.62);

    glVertex2f(.7,-.68);

    glVertex2f(.9,-.68);

    glVertex2f(.9,-.62);

    glEnd();

    glPopMatrix();


    /**Road End**/

    /**River Start**/



    glBegin(GL_POLYGON);

    glColor3ub(0,0,204);

    glVertex2f(-1,-.7);

    glVertex2f(-1,-1);

    glVertex2f(1,-1);

    glVertex2f(1,-.7);

    glEnd();

    /**River End**/

    /**Boat 1 Start**/

    glPushMatrix();

    glTranslatef(positionShip,0,0);

    glBegin(GL_POLYGON);

    glColor3ub(51,25,0);

    glVertex2f(-1,-.9);

    glVertex2f(-.9,-.98);

    glVertex2f(-.5,-.98);

    glVertex2f(-.4,-.9);

    glEnd();



    glBegin(GL_TRIANGLES);

    glColor3ub(204,204,0);

    glVertex2f(-.8,-.9);

    glVertex2f(-.6,-.9);

    glVertex2f(-.7,-.8);

    glEnd();

    glPopMatrix();

    /**Boat 1 End**/


	/**Boat 2 Start**/

    glPushMatrix();

    glTranslatef(positionShip,0,0);

    glBegin(GL_POLYGON);

    glColor3ub(0,0,0);

    glVertex2f(.7,-.9);

    glVertex2f(.6,-.98);

    glVertex2f(.2,-.98);

    glVertex2f(.1,-.9);

    glEnd();


    glBegin(GL_TRIANGLES);

    glColor3ub(204,0,204);

    glVertex2f(.5,-.9);

    glVertex2f(.3,-.9);

    glVertex2f(.4,-.8);

    glEnd();

    glPopMatrix();

    /**Boat 2 End**/



    /**Car Start**/

    glPushMatrix();

    glTranslatef(positionCar,0,0);

    glPushMatrix();

    glTranslatef(0,.13,0);

    /**Car Body**/

    glBegin(GL_POLYGON);

    glColor3ub(192,192,192);

    glVertex2f(-.9,-.72);

    glVertex2f(-.9,-.76);

    glVertex2f(-.7,-.76);

    glVertex2f(-.7,-.72);

    glEnd();

    /**Car Body End**/


    /**Car Roof**/

    glBegin(GL_POLYGON);

    glColor3ub(201,255,255);

    glVertex2f(-.85,-.72);

    glVertex2f(-.75,-.72);

    glVertex2f(-.76,-.7);

    glVertex2f(-.85,-.7);

    glEnd();

    glPopMatrix();

    /**Car Roof End**/


    /**Car Wheel 1`**/

    glPushMatrix();

    glTranslated(-.85,-.65,.1);

    glColor3f(1,1,0);

    glutSolidSphere (0.035, 30, 30);

	glPopMatrix();

	/**Car Wheel 1 End**/


	/**Car Wheel 2**/

	glPushMatrix();

    glTranslated(-.75,-.65,.1);

    glColor3f(1,0,0);

    glutSolidSphere (0.035, 30, 30);

	glPopMatrix();

	/**Car Wheel 2 End**/


    glPopMatrix();


    /**Car End**/


	glFlush();

}


int main(int argc, char** argv) {



     glutInit(&argc, argv);

	glutInitWindowSize(1000, 650);

	glutInitWindowPosition(20, 20);

	glutCreateWindow("Village School View");

	glutDisplayFunc(display);

	glutKeyboardFunc(handleKeypress);

    glutTimerFunc(150, updateShip, 0);

    glutTimerFunc(150, updateCloud, 0);

    glutTimerFunc(150,updateCar,0);

	glutMainLoop();

	return 0;

}









