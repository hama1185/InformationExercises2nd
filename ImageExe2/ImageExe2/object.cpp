#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <stdio.h>

GLfloat Black[] = { 0, 0, 0, 1.0 };
GLfloat Red[] = { 1.0, 0.0, 0.0, 1.0 };
GLfloat Gray[] = { 0.30, 0.30, 0.30, 1.0 };

void cylinder(float radius, float height, int sides)
{
    double pi = 3.1415;
    //���
    glNormal3d(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    double i;
    for (i = 0; i < sides; i++) {
        double t = pi * 2 / sides * (double)i;
        glVertex3d(radius * cos(t), height, radius * sin(t));
    }
    glEnd();
    //����
    glBegin(GL_QUAD_STRIP);
    for (i = 0; i <= sides; i = i + 1) {
        double t = i * 2 * pi / sides;
        glNormal3f((GLfloat)cos(t), 0.0, (GLfloat)sin(t));
        glVertex3f((GLfloat)(radius * cos(t)), -height, (GLfloat)(radius * sin(t)));
        glVertex3f((GLfloat)(radius * cos(t)), height, (GLfloat)(radius * sin(t)));
    }
    glEnd();
    //����
    glNormal3d(0.0, -1.0, 0.0);
    glBegin(GL_POLYGON);
    for (i = sides; i >= 0; --i) {
        double t = pi * 2 / sides * (double)i;
        glVertex3d(radius * cos(t), -height, radius * sin(t));
    }
    glEnd();
}
void cuboid(float width, float height, float depth)
{
    glBegin(GL_QUADS);
    //�O
    glNormal3f(0.0, 0.0, -1.0);
    glVertex3f(width / 2, height / 2, depth / 2);
    glVertex3f(-width / 2, height / 2, depth / 2);
    glVertex3f(-width / 2, -height / 2, depth / 2);
    glVertex3f(width / 2, -height / 2, depth / 2);
    //��
    glNormal3f(1.0, 0.0, 0.0);
    glVertex3f(width / 2, height / 2, depth / 2);
    glVertex3f(width / 2, height / 2, -depth / 2);
    glVertex3f(width / 2, -height / 2, -depth / 2);
    glVertex3f(width / 2, -height / 2, depth / 2);
    //�E
    glNormal3f(-1.0, 0.0, 0.0);
    glVertex3f(-width / 2, height / 2, -depth / 2);
    glVertex3f(-width / 2, height / 2, depth / 2);
    glVertex3f(-width / 2, -height / 2, depth / 2);
    glVertex3f(-width / 2, -height / 2, -depth / 2);
    //��
    glNormal3f(0.0, 0.0, 1.0);
    glVertex3f(width / 2, height / 2, -depth / 2);
    glVertex3f(-width / 2, height / 2, -depth / 2);
    glVertex3f(-width / 2, -height / 2, -depth / 2);
    glVertex3f(width / 2, -height / 2, -depth / 2);
    //��
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3f(width / 2, height / 2, depth / 2);
    glVertex3f(-width / 2, height / 2, depth / 2);
    glVertex3f(-width / 2, height / 2, -depth / 2);
    glVertex3f(width / 2, height / 2, -depth / 2);
    //��
    glNormal3f(0.0, -1.0, 0.0);
    glVertex3f(width / 2, -height / 2, depth / 2);
    glVertex3f(-width / 2, -height / 2, depth / 2);
    glVertex3f(-width / 2, -height / 2, -depth / 2);
    glVertex3f(width / 2, -height / 2, -depth / 2);
    glEnd();
}
void stair(float width, float height, float depth)
{
    static const GLfloat color[] = { 1.0, 1, 1, 1.0 };  /* �ގ� (�F) */
                                                        /* �ގ��̐ݒ� */
    //glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
    /* �A���t�@�e�X�g�J�n */
    //glEnable(GL_ALPHA_TEST);
    /* �e�N�X�`���}�b�s���O�J�n */
    //glEnable(GL_TEXTURE_2D);
    //glBindTexture(GL_TEXTURE_2D, texid_1);  // �e�N�X�`��ID=1���w��

    glBegin(GL_QUADS);
    //�O
    glNormal3f(0.0, 0.0, -1.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3d(width / 2, height / 2, depth / 2);
    glTexCoord2d(1.0, 1.0);
    glVertex3d(-width / 2, height / 2, depth / 2);
    glTexCoord2d(1.0, 0.0);
    glVertex3d(-width / 2, -height / 2, depth / 2);
    glTexCoord2d(0.0, 0.0);
    glVertex3d(width / 2, -height / 2, depth / 2);
    //��
    glNormal3f(1.0, 0.0, 0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3d(width / 2, height / 2, depth / 2);
    glTexCoord2d(1.0, 1.0);
    glVertex3d(width / 2, height / 2, -depth / 2);
    glTexCoord2d(1.0, 0.0);
    glVertex3d(width / 2, -height / 2, -depth / 2);
    glTexCoord2d(0.0, 0.0);
    glVertex3d(width / 2, -height / 2, depth / 2);
    //�E
    glNormal3f(-1.0, 0.0, 0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3d(-width / 2, height / 2, -depth / 2);
    glTexCoord2d(1.0, 1.0);
    glVertex3d(-width / 2, height / 2, depth / 2);
    glTexCoord2d(1.0, 0.0);
    glVertex3d(-width / 2, -height / 2, depth / 2);
    glTexCoord2d(0.0, 0.0);
    glVertex3d(-width / 2, -height / 2, -depth / 2);
    //��
    glNormal3f(0.0, 0.0, 1.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3d(width / 2, height / 2, -depth / 2);
    glTexCoord2d(1.0, 1.0);
    glVertex3d(-width / 2, height / 2, -depth / 2);
    glTexCoord2d(1.0, 0.0);
    glVertex3d(-width / 2, -height / 2, -depth / 2);
    glTexCoord2d(0.0, 0.0);
    glVertex3d(width / 2, -height / 2, -depth / 2);
    //��
    glNormal3f(0.0, 1.0, 0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3d(width / 2, height / 2, depth / 2);
    glTexCoord2d(1.0, 1.0);
    glVertex3d(-width / 2, height / 2, depth / 2);
    glTexCoord2d(1.0, 0.0);
    glVertex3d(-width / 2, height / 2, -depth / 2);
    glTexCoord2d(0.0, 0.0);
    glVertex3d(width / 2, height / 2, -depth / 2);
    //��
    glNormal3f(0.0, -1.0, 0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3d(width / 2, -height / 2, depth / 2);
    glTexCoord2d(1.0, 1.0);
    glVertex3d(-width / 2, -height / 2, depth / 2);
    glTexCoord2d(1.0, 0.0);
    glVertex3d(-width / 2, -height / 2, -depth / 2);
    glTexCoord2d(0.0, 0.0);
    glVertex3d(width / 2, -height / 2, -depth / 2);
    glEnd();
}
void tori(int x, int y, int z, int i) {
    glPushMatrix();
    if (i <= 90)
        glTranslatef((float)10 * sin(6.28 * x / 180), (float)0.5, (float)10 * cos(6.28 * z / 180));
    else if (i < 180)
        glTranslatef((float)-10 * sin(6.28 * x / 180), (float)0.5, (float)-20 - 10 * cos(6.28 * z / 180));
    else
        glTranslatef(0.4 * (i - 180), 0.5 + 0.25 * (i - 180), -30);

    //�x������1
    glPushMatrix();
    glTranslatef(0.40 * sin(6.28 * x / 180), 0.2, 0.40 * cos(6.28 * z / 180));
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Red);
    cylinder(0.06, 0.4, 10);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Black);
    glTranslatef(0, -0.4, 0);
    cylinder(0.061, 0.08, 10);
    glPopMatrix();

    //�x������2
    glPushMatrix();
    glTranslatef(-0.40 * sin(6.28 * x / 180), 0.2, -0.40 * cos(6.28 * z / 180));
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Red);
    cylinder(0.06, 0.4, 10);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Black);
    glTranslatef(0, -0.4, 0);
    cylinder(0.061, 0.08, 10);
    glPopMatrix();

    //���̖_�E����
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Red);
    glTranslatef(0, 0.56, 0);
    glRotatef(90 + 2 * x, 0, 1, 0);
    cuboid(1, 0.12, 0.12);
    glTranslatef(0, -0.2, 0);
    cuboid(1, 0.08, 0.08);
    glTranslatef(0, -0.8, 0);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Gray);
    stair(1.5, 0.4, 0.41);
    glPopMatrix();

    glPopMatrix();
}

void ground() {
    static const GLfloat color[] = { 1, 1, 1, 1.0 };  /* �ގ� (�F) */
                                          //255,82,52
    int i, j;
    for (i = -50; i < 50; i++) {
        for (j = -50; j < 50; j++) {
            glPushMatrix();
            glTranslatef(i, 0, j);
            /* �P���̂S�p�`��`�� */
            glNormal3d(0.0, 0.0, 1.0);
            glBegin(GL_QUADS);
            glTexCoord2d(0.0, 1.0);
            glVertex3d(0, 0, 0);
            glTexCoord2d(1.0, 1.0);
            glVertex3d(1.0, 0, 0);
            glTexCoord2d(1.0, 0.0);
            glVertex3d(1.0, 0, 1.0);
            glTexCoord2d(0.0, 0.0);
            glVertex3d(0, 0, 1.0);
            glEnd();
            glPopMatrix();
        }
    }
}