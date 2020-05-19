#include<gl/glut.h>
#include<stdio.h>

int x, y;
int rotate_to = 0;
float rotate_angle = 0.0;
float trans_x, trans_y = 0.0;

void draw_pixel(float x1, float y1)
{
    glPointSize(10.0);
    glBegin(GL_POINTS);
    glVertex2f(x1, y1);
    glEnd();
}

void triangle(int x, int y)
{
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x+400, y+300);
    glVertex2f(x+300, y+10);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(1, 1, 1);
    draw_pixel(0.0, 0.0);

    if(rotate_to == 1)
    {
        trans_x = 0.0;
        trans_y = 0.0;
        rotate_angle += 0.9;
    }

    if(rotate_to == 2)
    {
        trans_x = x;
        trans_y = y;
        rotate_angle += 0.9;
        glColor3f(1.0, 0.0, 0.0);
        draw_pixel(x, y);
    }

    glTranslatef(trans_x, trans_y, 0.0);
    glRotatef(rotate_angle, 0.0, 0.0, 1.0);
    glTranslatef(-trans_x, -trans_y, 0.0);
    triangle(trans_x, trans_y);
    glutPostRedisplay();
    glutSwapBuffers();
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-800.0, 800.0, -800.0, 800.0);
    glMatrixMode(GL_MODELVIEW);
}

void rotatemenu(int option)
{
    if(option == 1)
        rotate_to = 1;
    if(option == 2)
        rotate_to = 2;
    if(option == 3)
        rotate_to = 3;
}

int main(int argc, char **argv)
{
    printf("Enter the fixed points( x, y) for triangle to be rotated\n");
    scanf("%d%d", &x, &y);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Rotate Triangle");
    init();
    glutDisplayFunc(display);
    glutCreateMenu(rotatemenu);
    glutAddMenuEntry("Rotate around ORIGIN", 1);
    glutAddMenuEntry("Rotate around FIXED POINT", 2);
    glutAddMenuEntry("Stop ROTATION", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;
}
