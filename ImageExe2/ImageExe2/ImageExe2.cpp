#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include "object.h"

#define WIDTH 640
#define HEIGHT 480
float rx, ry, view_x, view_y, view_z;
int rv = 0; //view回転
int rs = 0; //回転スイッチ


double radians(double deg) {
    return deg * 3.14 / 180;
}

void idle(void)
{
    glutPostRedisplay();
}

static double width, height;
void resize(int w, int h) {
    width = (double)w;
    height = (double)h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-w/200,w/200,-h/200,h/200,-1,1);
    //視野角,アスペクト比(ウィンドウの幅/高さ),描画する範囲(最も近い距離,最も遠い距離)
    gluPerspective(30.0, (double)w / (double)h, 1.0, 500.0);

    glMatrixMode(GL_MODELVIEW);
}

//ドラッグされているか
int draged;
//視線の中心
int ry_center;
//マウスがドラッグされたら呼ばれる
void mouseDraged(int x, int y) {
    draged = 1;

}
//マウスのx座標から、横方向の回転に変換する
double xToRy(int x) {
    return (x - width / 2) / (float)width * 180 - ry_center;
}
//マウスのy座標から、縦方向の回転に変換する
double yToRx(int y) {
    return (y - height / 2) / (float)height * 90;
}
//マウスがクリックされたら呼ばれる
void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        if (draged == 1) {//ドラッグが解除されたら
            ry_center += xToRy(x) - ry;//視線の中心をズラす。

            draged = 0;
        }
    }

}
//マウスが動いたら
void mouseMoved(int x, int y) {
    ry = xToRy(x);
    rx = yToRx(y);

}
void keyboard(unsigned char key, int x, int y) {
    float step = 1;

    switch (key) {
    case 'q':
    case 'Q':
    case '\033':  // '\033' は ESC の ASCII コード 
        exit(0);
    case 'a':
    case 'A':
        view_z -= step * sin(radians(ry));
        view_x -= step * cos(radians(ry));
        break;

    case 'd':
    case 'D':
        view_z += step * sin(radians(ry));
        view_x += step * cos(radians(ry));
        break;

    case 'w':
    case 'W':
        view_z -= step * cos(radians(ry));
        view_x += step * sin(radians(ry));
        break;

    case 's':
    case 'S':
        view_z += step * cos(radians(ry));
        view_x -= step * sin(radians(ry));
        break;

    case 'r':
    case 'R':
        view_y += step;
        break;

    case 'f':
    case 'F':
        view_y -= step;
        break;

    default:
        break;
    }
    glutPostRedisplay();
}
//特殊キーが押されたら
void specialKey(int key, int x, int y) {
    glutPostRedisplay();
}
void display(void)
{
    //設定
    //static GLfloat light0pos[] = { 0, 50.0, 50.0, 1.0 };
    static GLfloat light0pos[] = { 0, 40, -20, 1 };
    //static GLfloat light1pos[] = { -50.0, 50.0, 0, 1.0 };
    static GLfloat light1pos[] = { 0, 1, 20, 1 };
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    //視点位置と視点方向
    gluLookAt(0, 1.5, 0, 0, 2, -1, 0.0, 1.0, 0.0);
    glRotated(rx, 1, 0, 0);
    glRotated(ry, 0, 1, 0);
    //視点を移動
    glTranslated(-view_x, view_y, -view_z);
    //	 光源の位置設定
    //glLightfv(GL_LIGHT0, GL_POSITION, light0pos);
    glLightfv(GL_LIGHT1, GL_POSITION, light1pos);



    int i;
    static int r = 0; /* 回転角 */
    //描画
    //glPushMatrix();
    //glTranslatef(20, 0, -20);
    ground();

    // glPushMatrix();
    //	mqoCallModel(model);
    //glTranslatef(0, 0, -10);
    //  for (i = 249; i >= 0; i--) {
    //      if (i <= 90)
    //          tori(i, 0, i, i);
    //      else if (i < 180)
    //          tori(i - 90, 0, i - 90, i);
    //      else
    //          tori(0, i, 0, i);

    //  }
    //glPopMatrix();
    gate(0.0f, 0.2f ,-10.0f);
    //glPopMatrix();
    gate(-30.0f, 0.2f, -50.0f);
    glutSwapBuffers();
    
    switch (rs) {
    case 1:
        if (++rv >= 360) rv = 0;
        break;
    case -1:
        if (--rv <= 0) rv = 360;
        break;
    default:
        break;
    }
}
void init() {
    glClearColor(0.32, 0.75, 0.88, 1.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutMouseFunc(mouse);
    glutIdleFunc(idle);
    glutPassiveMotionFunc(mouseMoved);
    glutMotionFunc(mouseDraged);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKey);
    init();
    glutMainLoop();
    return 0;
}