#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <gl/gl.h>
#include <math.h>
#define M_PI 3.14159265358979 // 円周率
#define PART 150 // 分割数

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    int n = PART;
    int i = PART;
    double rate;
    double x, y, r = 0.5;
    double xbias = 0.5;
    double ybias = 0.25;
    // 上胴体
    glColor3f(1.0, 1.0, 1.0); // 描画物体に白色を設定
    glBegin(GL_POLYGON); // ポリゴンの描画
    for (i = 0; i < n; i++) {
        // 座標を計算
        rate = (double)i / n;
        x = xbias + r * cos(2.0 * M_PI * rate);
        y = ybias + r * sin(2.0 * M_PI * rate);
        if (i <= 75) {
            glVertex3f(x, y, 0.0); // 頂点座標を指定
        }
    }

    // 下胴体
    glColor3f(1.0, 1.0, 1.0); // 描画物体に白色を設定
    glBegin(GL_POLYGON); // ポリゴンの描画
    r = 1.0;
    for (i = 0; i < n; i++) {
        // 座標を計算
        rate = (double)i / n;
        x = r * cos(2.0 * M_PI * rate);
        y = r * sin(2.0 * M_PI * rate);
        if (i >= 90) {
            glVertex3f(x, y, 0.0); // 頂点座標を指定
        }
    }

    // 嘴

    
    glEnd();

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
    glClearColor(0.33, 0.67, 0.93, 1.0);
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
