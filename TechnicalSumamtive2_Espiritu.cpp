#define GLEW_STATIC
#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include <math.h>

using namespace std;

// Global variables
float cloudScale = 16.0; //set standard scale of the cloud
GLfloat carPositionX = -800; //SET POSITION OF THE CAR
GLfloat carSpeed = 5.0; //SET MOVEMENT OF THE CAR
GLfloat screenWidth = 1000;
GLfloat spin = 0.0f; // Spin variable for plane 
bool isRotationEnabled = false; // Flag to indicate if rotation is enabled
GLfloat rotationSpeed = .5f; // Speed of rotation
const double PI = 3.14159; //Constant value of PI used in circle


// Function: Generates the sky/background
void init(void)
{
    glClearColor(0.529, 0.808, 0.922, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 1000.0, 0.0, 500.0);
}


//Function: Circle Use:
void circle(GLdouble rad)
{
    GLint points = 50;
    GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
    GLdouble theta = 0.0;

    glBegin(GL_POLYGON);
    {
        for( int i = 0; i <=50; i++, theta += delTheta )
        {
            glVertex2f(rad * cos(theta),rad * sin(theta));
        }
    }
    glEnd();
}


// Function: Sun Model
void Sun_Model(float x, float y, float z)
{
    glPushMatrix();
    glTranslatef(x, y, z);
    glColor3f(1.0, 1.0, 0.0); // R: 1, G: 1, B: 0
    circle(30);
    glPopMatrix();
}


// Function: Generates the floor
void field()
{
    // Field
    GLfloat fieldVertices[] = {
        0, 50,
        0, 70,
        1000, 70,
        1000, 50
    };

    GLfloat fieldColors[] = {
        0.0, 0.5, 0.0,
        0.0, 0.5, 0.0,
        0.0, 0.5, 0.0,
        0.0, 0.5, 0.0
    };

    GLuint fieldVBOs[2];
    glGenBuffers(2, fieldVBOs);

    glBindBuffer(GL_ARRAY_BUFFER, fieldVBOs[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(fieldVertices), fieldVertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, fieldVBOs[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(fieldColors), fieldColors, GL_STATIC_DRAW);

    // Field_Shadow
    GLfloat shadowVertices[] = {
        0, 0,
        0, 50,
        1000, 50,
        1000, 0
    };

    GLfloat shadowColors[] = {
        0.1, 1.293, 0.0,
        0.1, 1.293, 0.0,
        0.1, 1.293, 0.0,
        0.1, 1.293, 0.0
    };

    GLuint shadowVBOs[2];
    glGenBuffers(2, shadowVBOs);

    glBindBuffer(GL_ARRAY_BUFFER, shadowVBOs[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(shadowVertices), shadowVertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, shadowVBOs[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(shadowColors), shadowColors, GL_STATIC_DRAW);

    // Field
    glBindBuffer(GL_ARRAY_BUFFER, fieldVBOs[0]);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, fieldVBOs[1]);
    glEnableClientState(GL_COLOR_ARRAY);
    glColorPointer(3, GL_FLOAT, 0, 0);

    glDrawArrays(GL_POLYGON, 0, 4);

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    // Field_Shadow
    glBindBuffer(GL_ARRAY_BUFFER, shadowVBOs[0]);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, shadowVBOs[1]);
    glEnableClientState(GL_COLOR_ARRAY);
    glColorPointer(3, GL_FLOAT, 0, 0);

    glDrawArrays(GL_POLYGON, 0, 4);

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    // Clean up
    glDeleteBuffers(2, fieldVBOs);
    glDeleteBuffers(2, shadowVBOs);
}


// Function: Generates a cloud
void generateCloud(float xPos, float yPos)
{
    glPushMatrix();
    glTranslatef(xPos, yPos, 0.0);

    // Cloud color
    glColor3f(1.25, 0.924, 0.930);

    // Top_Left
    glPushMatrix();
    glTranslatef(320, 210, 0);
    circle(cloudScale);
    glPopMatrix();

    // Top
    glPushMatrix();
    glTranslatef(340, 225, 0);
    circle(cloudScale);
    glPopMatrix();

    // Right
    glPushMatrix();
    glTranslatef(360, 210, 0);
    circle(cloudScale);
    glPopMatrix();

    // middle_Fill
    glPushMatrix();
    glTranslatef(355, 210, 0);
    circle(cloudScale);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(350, 210, 0);
    circle(cloudScale);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(345, 204, 0);
    circle(cloudScale * 0.625);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(340, 204, 0);
    circle(cloudScale * 0.625);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(335, 204, 0);
    circle(cloudScale * 0.625);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(330, 204, 0);
    circle(cloudScale * 0.625);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(325, 204, 0);
    circle(cloudScale * 0.625);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(320, 204, 0);
    circle(cloudScale * 0.625);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(315, 204, 0);
    circle(cloudScale * 0.625);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(310, 204, 0);
    circle(cloudScale * 0.625);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(305, 204, 0);
    circle(cloudScale * 0.625);
    glPopMatrix();

    glPopMatrix();
}


// Function: Generates a car
void generateCar()
{
    // Car body
    GLfloat carBodyVertices[] = {
        -40, -15,
        -40, 15,
        40, 15,
        40, -15
    };

    GLfloat carBodyColors[] = {
        0.7, 0.2, 0.2,
        0.7, 0.2, 0.2,
        0.7, 0.2, 0.2,
        0.7, 0.2, 0.2
    };

    GLuint carBodyVBOs[2];
    glGenBuffers(2, carBodyVBOs);

    glBindBuffer(GL_ARRAY_BUFFER, carBodyVBOs[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(carBodyVertices), carBodyVertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, carBodyVBOs[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(carBodyColors), carBodyColors, GL_STATIC_DRAW);

    // Car body
    glBindBuffer(GL_ARRAY_BUFFER, carBodyVBOs[0]);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, carBodyVBOs[1]);
    glEnableClientState(GL_COLOR_ARRAY);
    glColorPointer(3, GL_FLOAT, 0, 0);

    glDrawArrays(GL_POLYGON, 0, 4);

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    // Clean up
    glDeleteBuffers(2, carBodyVBOs);

    // Car wheels
    GLfloat wheelRadius = 10.0;
    GLfloat wheelPosX[] = { -15.0, 15.0 };
    GLfloat wheelPosY = -10.0;
    GLfloat wheelColor[] = { 0.2, 0.2, 0.2 };

    for (int i = 0; i < 2; i++)
    {
        glPushMatrix();
        glTranslatef(wheelPosX[i], wheelPosY, 0.0);
        glColor3fv(wheelColor);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.0, 0.0);
        for (int angle = 0; angle <= 360; angle += 10)
        {
            float radian = angle * (3.14159 / 180.0);
            float x = wheelRadius * cos(radian);
            float y = wheelRadius * sin(radian);
            glVertex2f(x, y);
        }
        glEnd();
        glPopMatrix();
    }
}


void Plane_Parts()
{
    // Body of the plane
    GLfloat bodyVertices[] = {
        -20, -5,
        0, -5,
        30, 0,
        0, 5,
        -20, 5
    };

    // Front part of the plane
    GLfloat frontVertices[] = {
        -20, -5,
        -25, 0,
        -20, 5,
        -15, 0
    };

    // Tail of the plane
    GLfloat tailVertices[] = {
        30, -3,
        40, 0,
        30, 3,
        20, 0
    };

    // Wings of the plane
    GLfloat wingVertices[] = {
        0, -2,
        20, -6,
        25, 0,
        20, 6,
        0, 2
    };

    glEnableClientState(GL_VERTEX_ARRAY);

    // Draw the plane body
    glVertexPointer(2, GL_FLOAT, 0, bodyVertices);
    glColor3f(0.11, 0.23, 0.36);
    glDrawArrays(GL_POLYGON, 0, 5);

    // Draw the front part of the plane
    glVertexPointer(2, GL_FLOAT, 0, frontVertices);
    glColor3f(0.7, 0.7, 0.7);
    glDrawArrays(GL_QUADS, 0, 4);

    // Draw the tail of the plane
    glVertexPointer(2, GL_FLOAT, 0, tailVertices);
    glColor3f(0.11, 0.23, 0.36);
    glDrawArrays(GL_QUADS, 0, 4);

    // Save the current matrix
    glPushMatrix();

    // Apply translation and rotation to the wings
    glTranslatef(0, 0, 0);  // Adjust the values to position the wings
    glRotatef(-45, 0, 0, 1);  // Rotate the wings by -45 degrees around the Z-axis

    // Draw the wings of the plane
    glVertexPointer(2, GL_FLOAT, 0, wingVertices);
    glColor3f(0.7, 0.7, 0.7);
    glDrawArrays(GL_POLYGON, 0, 5);

    // Restore the saved matrix
    glPopMatrix();

    glDisableClientState(GL_VERTEX_ARRAY);
}


void Plane()
{
    // Draw the plane's cockpit
    glColor3f(0.20, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(150 - 50, 220 - 100, 0);
    glutSolidSphere(10, 20, 20);
    glPopMatrix();

    // Save the current matrix
    glPushMatrix();

    // Apply rotation to make the plane spin
    static float angle = 0.0f;  // Static variable to track the rotation angle
    angle += 1.0f;  // Increment the angle by 1 degree for each frame
    glTranslatef(150 - 50, 220 - 100, 0);
    glRotatef(angle, 0, 0, 1);  // Rotate the plane around the Z-axis

    // Draw the plane's body and wings
    glColor3f(0.20, 0.23, 0.36);
    Plane_Parts();

    // Restore the saved matrix
    glPopMatrix();
}



// Function: Display function
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    //Display: Sun
    Sun_Model(100,450,0);

    // Display: Field
    field();

    // Display: Clouds
    generateCloud(-300.0, 100.0 +75);
    generateCloud(-170.0, 120.0 +75);
    generateCloud(0.0, 100.0 +75);
    generateCloud(200.0, 150.0 +75);
    generateCloud(400.0, 110.0 +75);
    generateCloud(600.0, 115.0 +75);
    generateCloud(800.0, 125.0 +75);

    // Display: Car
    glPushMatrix();
    glTranslatef(carPositionX, 80, 0);
    generateCar();
    glPopMatrix();

    // Display: Plane
    glPushMatrix();
    glTranslatef(380, 220 - 50, 0);
    if (isRotationEnabled)
    {
        spin += rotationSpeed;
    }
    glRotatef(spin, 0.0f, 0.0f, 1.0f); // Rotate the plane
    Plane();
    glPopMatrix();

    glFlush();
}


// Timer function to control car movement
void timer(int value)
{
    carPositionX += carSpeed;
    if (carPositionX > screenWidth)
    {
        carPositionX = -800;
    }
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}


// Mouse scroll & click callback function
void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        // Add your desired action here
         isRotationEnabled = true; // Enable rotation when left button is clicked
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        isRotationEnabled = false; // Disable rotation when right button is clicked
    }
    else if (button == 3) // Scroll up
    {
        cloudScale += 0.25f;
    }
    else if (button == 4) // Scroll down
    {
        cloudScale -= 0.25f;
        if (cloudScale < 0.25f)
            cloudScale = 0.25f;
    }
    glutPostRedisplay();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Technical Summative 2");
    glutFullScreen(); //set size to fullscreen
    init();
    glutDisplayFunc(display);
    glutIdleFunc(display); // Call display function continuously when the system is idle
    glutTimerFunc(0, timer, 0); // Start the timer
    glutMouseFunc(mouse); // Register the mouse scroll callback function

    GLenum err = glewInit();
    if (err != GLEW_OK)
    {
        cerr << "GLEW initialization failed!" << endl;
        return 1;
    }
    glutMainLoop();
    return 0;
}

