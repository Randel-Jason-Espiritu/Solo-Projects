#define GLEW_STATIC

#include <GL/glew.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

float cameraAngle = 0.0f;
float cameraPitch = 0.0f;
float targetCameraAngle = 0.0f;
float targetCameraPitch = 0.0f;

void displayObject();
void init();
void handleKeypress(unsigned char key, int x, int y);
void update(int value);

void GLAPIENTRY MessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1024, 768);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Labaratory9");

    init();

    glutDisplayFunc(displayObject);
    glutKeyboardFunc(handleKeypress);

    GLenum err = glewInit();

    if (err == GLEW_OK) {
        glEnable(GL_DEBUG_OUTPUT);
        glDebugMessageCallback(MessageCallback, 0);
        printf("OpenGL version supported by this platform (%s): \n", glGetString(GL_VERSION));
        printf("OpenGL vendor (%s): \n", glGetString(GL_VENDOR));
        glutTimerFunc(0, update, 0);
        glutMainLoop();
    }
}

void displayObject() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // Apply rotation and pitch to the camera
    glRotatef(cameraPitch, 1.0f, 0.0f, 0.0f);
    glRotatef(cameraAngle, 0.0f, 1.0f, 0.0f);

    //General Light
    GLfloat lmodelambient[] = {0.2, 0.2, 0.2, 1.0};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodelambient);

    //Material
    GLfloat math_ambient[] = {1.0f, 0.0f, 0.0f, 0.0f}; //Red
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, math_ambient);

    //Spotlight1
    GLfloat lightposition0[] = {-1.0f, 0.0f, 2.0f, 1.0f};
    GLfloat lightcolor0[] = {1.0f, 1.0f, 0.0f, 1.0f}; //Yellow
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightcolor0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightposition0);

    //Spotlight2
    GLfloat lightposition1[] = {0.0f, 4.0f, 0.0f, 1.0f};
    GLfloat lightcolor1[] = {0.0f, 0.0f, 1.0f, 1.0f}; //Blue
    GLfloat spotdirection1[] = {0.0f, -1.0f, 0.0f};
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightcolor1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightposition1);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spotdirection1);

    //Spotlight3
    GLfloat lightposition2[] = {1.0f, 0.0f, 2.0f, 1.0f};
    GLfloat lightcolor2[] = {0.0f, 1.0f, 0.0f, 1.0f}; //Green
    glLightfv(GL_LIGHT2, GL_DIFFUSE, lightcolor2);
    glLightfv(GL_LIGHT2, GL_POSITION, lightposition2);

    //Spotlight4
    GLfloat lightposition3[] = {1.0f, -4.0f, 2.0f, 1.0f};
    GLfloat lightcolor3[] = {0.0f, 1.0f, 1.0f, 1.0f}; //Cyan
    GLfloat spotdirection3[] = {0.0f, 1.0f, 0.0f};
    glLightfv(GL_LIGHT3, GL_DIFFUSE, lightcolor3);
    glLightfv(GL_LIGHT3, GL_POSITION, lightposition3);
    glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, spotdirection3);

    //Spotlight5
    GLfloat lightposition4[] = {2.0f, 1.0f, -1.0f, 0.0f};
    GLfloat lightcolor4[] = {1.0f, 0.0f, 1.f, 1.0f}; //Magenta
    GLfloat spotdirection4[] = {0.0f, 0.0f, -1.0f};
    glLightfv(GL_LIGHT4, GL_DIFFUSE, lightcolor4);
    glLightfv(GL_LIGHT4, GL_POSITION, lightposition4);
    glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, spotdirection4);

    // Icosahedron
    glutSolidIcosahedron();

    glFlush();
    glutSwapBuffers();
}

void init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1024.0 / 768.0, 1.0, 10.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);

    // Enable additional spotlights
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
    glEnable(GL_LIGHT3);
    glEnable(GL_LIGHT4);
}

void handleKeypress(unsigned char key, int x, int y) {
    if (key == 'a') {
        targetCameraAngle -= 5.0f;
    }
    else if (key == 'd') {
        targetCameraAngle += 5.0f;
    }
    else if (key == 'w') {
        targetCameraPitch -= 5.0f;
    }
    else if (key == 's') {
        targetCameraPitch += 5.0f;
    }
    else if (key == '1') {
        // Focus spotlights to the first face/point of the Icosahedron
        targetCameraAngle = 0.0f;
        targetCameraPitch = 0.0f;
    }
    else if (key == '2') {
        // Focus spotlights to the second face/point of the Icosahedron
        targetCameraAngle = 180.0f;
        targetCameraPitch = 0.0f;
    }
    else if (key == '3') {
        // Focus spotlights to the third face/point of the Icosahedron
        targetCameraAngle = 90.0f;
        targetCameraPitch = 90.0f;
    }

    glutPostRedisplay();
}

void update(int value) {
    // Perform animation by smoothly rotating the camera towards the target angles
    cameraAngle += (targetCameraAngle - cameraAngle) * 0.1f;
    cameraPitch += (targetCameraPitch - cameraPitch) * 0.1f;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);  // Update every 16 milliseconds (60 FPS)
}

void GLAPIENTRY MessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam) {
    fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n", (type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR**" : ""), type, severity, message);
}

