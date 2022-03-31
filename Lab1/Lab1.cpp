#include <iostream>
#include <GL/freeglut.h>

static void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tutorial 01");

    glutDisplayFunc(RenderSceneCB);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glutMainLoop();
    return 0;
}
