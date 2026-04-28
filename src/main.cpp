#include <GL/freeglut.h>

#include "include/Game.h"
#include "include/Input.h"

// Game Configuration (Resolution / Title)
const int windowWidth = 800;
const int windowHeight = 600;
const char *windowTitle = "Arkanoid";

// GLUT Helper Functions
int g_lastTimeMs = 0;

void displayCallback()
{
    gameRender();
    glutSwapBuffers();
}

void idleCallback()
{
    const int currentTimeMs = glutGet(GLUT_ELAPSED_TIME);
    const int deltaMs = currentTimeMs - g_lastTimeMs;
    g_lastTimeMs = currentTimeMs;

    const double deltaSeconds = deltaMs / 1000.0;
    gameUpdate(deltaSeconds);

    glutPostRedisplay();
}

void keyboardDownCallback(unsigned char key, int x, int y)
{
    inputKeyDown(key, x, y);
    gameOnKeyDown(key, x, y);
}

void keyboardUpCallback(unsigned char key, int x, int y)
{
    inputKeyUp(key, x, y);
    gameOnKeyUp(key, x, y);
}

void specialDownCallback(int key, int x, int y)
{
    inputSpecialKeyDown(key, x, y);
    gameOnSpecialKeyDown(key, x, y);
}

void specialUpCallback(int key, int x, int y)
{
    inputSpecialKeyUp(key, x, y);
    gameOnSpecialKeyUp(key, x, y);
}

void mouseCallback(int button, int state, int x, int y)
{
    inputMouse(button, state, x, y);
    gameOnMouse(button, state, x, y);
}

void motionCallback(int x, int y)
{
    inputMotion(x, y);
    gameOnMotion(x, y);
}

void shutdownCallback()
{
    gameShutdown();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow(windowTitle);

    gameInitialize();

    g_lastTimeMs = glutGet(GLUT_ELAPSED_TIME);

    glutDisplayFunc(displayCallback);
    glutIdleFunc(idleCallback);
    glutKeyboardFunc(keyboardDownCallback);
    glutKeyboardUpFunc(keyboardUpCallback);
    glutSpecialFunc(specialDownCallback);
    glutSpecialUpFunc(specialUpCallback);
    glutMouseFunc(mouseCallback);
    glutMotionFunc(motionCallback);
    glutPassiveMotionFunc(motionCallback);

    atexit(shutdownCallback);
    glutMainLoop();
    return 0;
}
