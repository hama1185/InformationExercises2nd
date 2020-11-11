#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <gl/gl.h>
#include <math.h>
#define M_PI 3.14159265358979 // 円周率
#define PART 150 // 分割数

// Twitterのアイコンを作成する.

void makeCircle(double x, double y, double r, double xbias, double ybias, int mode, int dose) {
    double rate;
    int n = PART;
    glColor3f(1.0, 1.0, 1.0); // 描画物体に白色を設定
    glBegin(GL_POLYGON); // ポリゴンの描画
    for (int i = 0; i < n; i++) {
        // 座標を計算
        rate = (double)i / n;
        x = xbias + r * cos(2.0 * M_PI * rate);
        y = ybias + r * sin(2.0 * M_PI * rate);
        if (mode == 0) {
            if (i <= dose) {
                glVertex3f(x, y, 0.0); // 頂点座標を指定
            }
        }
        else {
            if (i >= dose) {
                glVertex3f(x, y, 0.0); // 頂点座標を指定
            }
        }
    }
    glEnd();
}

void drawWing(int i) {
    glColor3f(1.0, 1.0, 1.0); // 描画物体に白色を設定
    glBegin(GL_POLYGON); // ポリゴンの描画　
    if (i == 1) {
        glVertex3f(-1.0, 0.3, 0.0);
        glVertex3f(0.25, -0.1, 0.0);
        glVertex3f(0.25, 0.08125, 0.0);//0.08125
    }
    else {
        double x = (double)i - 1;
        glVertex3f(-1.0, 0.3 - x * 0.2, 0.0);
        glVertex3f(0.25, x * -0.18 + 0.08, 0.0);
        glVertex3f(0.25, -0.1 - 0.18 * x, 0.0);//0.08125
    }
    glEnd();
}

void drawBackground() {
    glBegin(GL_QUADS);
    glColor3d(0.33, 0.67, 0.93);
    glVertex2d(-2.0, -2.0);
    glVertex2d(2.0, -2.0);
    glColor3d(0.33, 0.9, 1.0);
    glVertex2d(2.0, 2.0);
    glVertex2d(-2.0, 2.0);
    glEnd();
}

void drawUpBeak() {
    glColor3f(1.0, 1.0, 1.0); // 描画物体に白色を設定
    glBegin(GL_POLYGON); // ポリゴンの描画
    glVertex3f(1.0, 0.25, 0.0);
    //補完
    glVertex3f(1.25, 0.375, 0.0);
    //補完
    glVertex3f(1.0, 0.125, 0.0);
    glEnd();
}

void drawDownBeak() {
    glColor3f(1.0, 1.0, 1.0); // 描画物体に白色を設定
    glBegin(GL_POLYGON); // ポリゴンの描画
    glVertex3f(1.0, 0.125, 0.0);
    //補完　
    glVertex3f(1.25, 0.25, 0.0);
    //補完
    glVertex3f(1.0, -0.05, 0.0);
    glEnd();
}

void drawSpace() {
    glColor3f(1.0, 1.0, 1.0); // 描画物体に白色を設定
    glBegin(GL_QUADS);
    glVertex3f(0.25, 0.08125, 0.0);
    glVertex3f(0.25, -0.46, 0.0);
    glVertex3f(1.0, -0.05, 0.0);
    glVertex3f(1.0, 0.25, 0.0);
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);//ウインドウを塗りつぶす
    // 背景
    drawBackground();
    // 上胴体
    makeCircle(0.5, 0.5, 0.4, 0.6, 0.25, 0, 86);
    // 下胴体
    makeCircle(0.5, 0.5, 1.0, 0, 0, 1, 100);    
    // 上嘴
    drawUpBeak();
    // 下嘴
    drawDownBeak();
    // 羽
    drawWing(1);
    drawWing(2);
    drawWing(3);
    // 空白部分
    drawSpace();
    glFlush();
}

void resize(int w, int h)
{
    /* ウィンドウ全体をビューポートにする */
    glViewport(0, 0, w, h);

    /* 変換行列の初期化 */
    glLoadIdentity();

    /* スクリーン上の表示領域をビューポートの大きさに比例させる */
    glOrtho(-w / 200.0, w / 200.0, -h / 200.0, h / 200.0, -1.0, 1.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 'q':
    case 'Q':
    case '\033':  /* '\033' は ESC の ASCII コード */
        exit(0);
    default:
        break;
    }
}


void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyboard);
    init();
    glutMainLoop();
    return 0;
}
