# Lab1

#include <GL/glew.h>
#include <iostream>
#include <GL/freeglut.h>
#include <glm/vec3.hpp>

GLuint VBO; //глобальная переменная для хранени указателя на буфер вершин

static void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT); //очистка цвета

    glEnableVertexAttribArray(0); //координаты вершин, используемые в буфере, рассматриваются как атрибут вершины с индексом 0
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    //glDrawArrays(GL_POINT, 0, 1); функция для отрисовки
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(0); //отключение атрибута вершины

    glutSwapBuffers(); //фоновый буфер меняется с буфером кадра
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv); //инициализация GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); //настройка опций (двойная буферизация и буфер цвета)
    glutInitWindowSize(1024, 768);  //создание и изменения окна
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tutorial 1");
    glutDisplayFunc(RenderSceneCB); //взаимодействие с оконной системой
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //вызов цвета


    GLenum res = glewInit(); //инициализация GLEW и проверка на ошибки
    if (res != GLEW_OK)
    {
        fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
        return 1;
    }

    glm::vec3 Vertices[3]; //создается массив из 2 экземпляра
    // Vertices[0] = glm::vec3(0.0f, 0.0f, 0.0f)Позиции x, y, z по 0
    Vertices[0] = glm::vec3(-1.0f, 1.0f, 0.0f);
    Vertices[1] = glm::vec3(-1.0f, -1.0f, 0.0f);
    Vertices[2] = glm::vec3(1.0f, 0.0f, 0.0f);

    glGenBuffers(1, &VBO); //генерация объектов перемен. типов(Кол-во объектов и сслыка на массив)
    glBindBuffer(GL_ARRAY_BUFFER, VBO); //привязка указателя к названию цели 
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW); //наполнение данными(название цели, размер данных в байтах, адрес массива вершин, флаг(исп. паттернов) )


    glutMainLoop(); //ждет события и передает их через функ обратного вызова
}
