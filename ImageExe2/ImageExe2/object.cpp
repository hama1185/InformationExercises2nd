#pragma warning(disable : 4996)
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <stdio.h>

#define PI 3.14159265

GLfloat Black[] = { 0, 0, 0, 1.0 };
GLfloat Red[] = { 1.0, 0.0, 0.0, 1.0 };
GLfloat Gray[] = { 0.30f, 0.30f, 0.30f, 1.0f };
GLfloat BigPost[] = { 0.752f, 0.721f, 0.564f, 1.0f };
GLfloat SmallPost[] = { 0.819f, 0.745f, 0.521f, 1.0f };
GLfloat Roof[] = {0.858f, 0.596f, 0.352f, 1.0f};
GLfloat Stone[] = { 0.517f, 0.509f, 0.4856f , 1.0f};
GLfloat Ground[] = {0.05f, 0.619f, 0.313f, 1.0f};
GLfloat Building[] = { 0.862f, 0.509f, 0.301f, 1.0f};
GLfloat Signboard[] = {0.98f, 0.99f, 1.0f, 1.0f};
GLfloat Branch[] = {0.52f, 0.29f, 0.169f, 1.0f};
GLfloat Leaf[] = {0.419f, 0.698f, 0.353f, 1.0f};
GLfloat Loadway[] = {0.709f, 0.576f, 0.439f, 1.0f};
GLfloat Ring[] = {0.827f, 0.847f, 0.780f, 1.0f};
GLfloat Pillar[] = {0.227f, 0.251f, 0.384f, 1.0f};
//GL_AMBIENT_AND_DIFFUSE
//GL_FRONT_AND_BACK


GLuint texid_1, texid_2, texid_3, texid_4, texid_5, texid_6;
static const char texture1[] = "../texture/stonetexture261x348.raw";
static const char texture2[] = "../texture/loadTexture445x273.raw";
static const char texture3[] = "../texture/leafTexture255x255.raw";
static const char texture4[] = "../texture/stone625x417.raw";
static const char texture5[] = "../texture/grandtexture255x255.raw";
static const char texture6[] = "../texture/back_560x372.raw";

#define TEX_W1 261
#define TEX_H1 348
#define TEX_W2 445
#define TEX_H2 273
#define TEX_W3 255
#define TEX_H3 256
#define TEX_W4 625
#define TEX_H4 417
#define TEX_W5 255
#define TEX_H5 255
#define TEX_W6 560
#define TEX_H6 372

void initTexture() {
    /* テクスチャの読み込みに使う配列 */
    GLubyte texture_buf1[TEX_H1][TEX_W1][4];
    GLubyte texture_buf2[TEX_H2][TEX_W2][4];
    GLubyte texture_buf3[TEX_H3][TEX_W3][4];
    GLubyte texture_buf4[TEX_H4][TEX_W4][4];
    GLubyte texture_buf5[TEX_H5][TEX_W5][4];
    GLubyte texture_buf6[TEX_H6][TEX_W6][4];
    FILE* fp;

    /* テクスチャ画像(1枚目)の読み込み */
    if ((fp = fopen(texture1, "rb")) != NULL) {
        fread(texture_buf1, sizeof texture_buf1, 1, fp);
        fclose(fp);
    }
    else {
        perror(texture1);
    }
    /* テクスチャ画像(2枚目)の読み込み */
    if ((fp = fopen(texture2, "rb")) != NULL) {
        fread(texture_buf2, sizeof texture_buf2, 1, fp);
        fclose(fp);
    }
    else {
        perror(texture2);
    }
    /* テクスチャ画像(3枚目)の読み込み */
    if ((fp = fopen(texture3, "rb")) != NULL) {
        fread(texture_buf3, sizeof texture_buf3, 1, fp);
        fclose(fp);
    }
    else {
        perror(texture3);
    }
    /* テクスチャ画像(4枚目)の読み込み */
    if ((fp = fopen(texture4, "rb")) != NULL) {
        fread(texture_buf4, sizeof texture_buf4, 1, fp);
        fclose(fp);
    }
    else {
        perror(texture4);
    }
    /* テクスチャ画像(5枚目)の読み込み */
    if ((fp = fopen(texture5, "rb")) != NULL) {
        fread(texture_buf5, sizeof texture_buf5, 1, fp);
        fclose(fp);
    }
    else {
        perror(texture5);
    }
    /* テクスチャ画像(6枚目)の読み込み */
    if ((fp = fopen(texture6, "rb")) != NULL) {
        fread(texture_buf6, sizeof texture_buf6, 1, fp);
        fclose(fp);
    }
    else {
        perror(texture6);
    }

    ////////// 1枚目のテクスチャの読み込み ////////////
    glGenTextures(1, &texid_1);  // テクスチャIDを生成
    glBindTexture(GL_TEXTURE_2D, texid_1);  // 生成したテクスチャIDに切り替える
    /* テクスチャ画像はバイト単位に詰め込まれている */
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    /* テクスチャの割り当て */
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, TEX_W1, TEX_H1,  // 縦横サイズはテクスチャ1用
        GL_RGBA, GL_UNSIGNED_BYTE, texture_buf1);
    /* テクスチャを拡大・縮小する方法の指定 */
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    /* テクスチャ環境 */
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D, 0);  // デフォルトにテクスチャIDに切り替える
     ////////////////////////////////////////////////////	

    ////////// 2枚目のテクスチャの読み込み ////////////
    glGenTextures(1, &texid_2);  // テクスチャIDを生成
    glBindTexture(GL_TEXTURE_2D, texid_2);  // 生成したテクスチャIDに切り替える
    /* テクスチャ画像はバイト単位に詰め込まれている */
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    /* テクスチャの割り当て */
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, TEX_W2, TEX_H2,  // 縦横サイズはテクスチャ1用
        GL_RGBA, GL_UNSIGNED_BYTE, texture_buf2);
    /* テクスチャを拡大・縮小する方法の指定 */
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    /* テクスチャ環境 */
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D, 0);  // デフォルトにテクスチャIDに切り替える
      ////////////////////////////////////////////////////	

    ////////// 3枚目のテクスチャの読み込み ////////////
    glGenTextures(1, &texid_3);  // テクスチャIDを生成
    glBindTexture(GL_TEXTURE_2D, texid_3);  // 生成したテクスチャIDに切り替える
    /* テクスチャ画像はバイト単位に詰め込まれている */
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    /* テクスチャの割り当て */
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, TEX_W3, TEX_H3,  // 縦横サイズはテクスチャ1用
        GL_RGBA, GL_UNSIGNED_BYTE, texture_buf3);
    /* テクスチャを拡大・縮小する方法の指定 */
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    /* テクスチャ環境 */
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D, 0);  // デフォルトにテクスチャIDに切り替える
      ////////////////////////////////////////////////////	

    ////////// 4枚目のテクスチャの読み込み ////////////
    glGenTextures(1, &texid_4);  // テクスチャIDを生成
    glBindTexture(GL_TEXTURE_2D, texid_4);  // 生成したテクスチャIDに切り替える
    /* テクスチャ画像はバイト単位に詰め込まれている */
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    /* テクスチャの割り当て */
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, TEX_W4, TEX_H4,  // 縦横サイズはテクスチャ1用
        GL_RGBA, GL_UNSIGNED_BYTE, texture_buf4);
    /* テクスチャを拡大・縮小する方法の指定 */
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    /* テクスチャ環境 */
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D, 0);  // デフォルトにテクスチャIDに切り替える
      ////////////////////////////////////////////////////	

    ////////// 5枚目のテクスチャの読み込み ////////////
    glGenTextures(1, &texid_5);  // テクスチャIDを生成
    glBindTexture(GL_TEXTURE_2D, texid_5);  // 生成したテクスチャIDに切り替える
    /* テクスチャ画像はバイト単位に詰め込まれている */
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    /* テクスチャの割り当て */
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, TEX_W5, TEX_H5,  // 縦横サイズはテクスチャ1用
        GL_RGBA, GL_UNSIGNED_BYTE, texture_buf5);
    /* テクスチャを拡大・縮小する方法の指定 */
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    /* テクスチャ環境 */
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D, 0);  // デフォルトにテクスチャIDに切り替える
      ////////////////////////////////////////////////////	

    ////////// 6枚目のテクスチャの読み込み ////////////
    glGenTextures(1, &texid_6);  // テクスチャIDを生成
    glBindTexture(GL_TEXTURE_2D, texid_6);  // 生成したテクスチャIDに切り替える
    /* テクスチャ画像はバイト単位に詰め込まれている */
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    /* テクスチャの割り当て */
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, TEX_W6, TEX_H6,  // 縦横サイズはテクスチャ1用
        GL_RGBA, GL_UNSIGNED_BYTE, texture_buf6);
    /* テクスチャを拡大・縮小する方法の指定 */
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    /* テクスチャ環境 */
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D, 0);  // デフォルトにテクスチャIDに切り替える
      ////////////////////////////////////////////////////

#if 0
      /* 混合する色の設定 */
    static const GLfloat blend[] = { 0.0, 1.0, 0.0, 1.0 };
    glTexEnvfv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, blend);
#endif

    /* アルファテストの比較関数 */
    glAlphaFunc(GL_GREATER, 0.5);
}

double to_deg(double r) {
    return r * 180.0 / (atan(1.0) * 4.0);
}

void cylinder(float radius, float height, int sides)
{
    double pi = 3.1415;
    //上面
    glNormal3d(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    double i;
    for (i = 0; i < sides; i++) {
        double t = pi * 2 / sides * (double)i;
        glVertex3d(radius * cos(t), height, radius * sin(t));
    }
    glEnd();
    //側面
    glBegin(GL_QUAD_STRIP);
    for (i = 0; i <= sides; i = i + 1) {
        double t = i * 2 * pi / sides;
        glNormal3f((GLfloat)cos(t), 0.0, (GLfloat)sin(t));
        glVertex3f((GLfloat)(radius * cos(t)), -height, (GLfloat)(radius * sin(t)));
        glVertex3f((GLfloat)(radius * cos(t)), height, (GLfloat)(radius * sin(t)));
    }
    glEnd();
    //下面
    glNormal3d(0.0, -1.0, 0.0);
    glBegin(GL_POLYGON);
    for (i = sides; i >= 0; --i) {
        double t = pi * 2 / sides * (double)i;
        glVertex3d(radius * cos(t), -height, radius * sin(t));
    }
    glEnd();
}
void stonepart(float width, float height, float depth) {
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Stone);
    
    /* アルファテスト開始 */
    glEnable(GL_ALPHA_TEST);
    /* テクスチャマッピング開始 */
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texid_1);  // テクスチャID=1を指定
    
    glBegin(GL_QUADS);
    //前
    glNormal3f(0.0, 0.0, 1.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(width / 2, height / 2, depth / 2);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(-width / 2, height / 2, depth / 2);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(-width / 2, -height / 2, depth / 2);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(width / 2, -height / 2, depth / 2);
    //左
    glNormal3f(1.0, 0.0, 0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(width / 2, height / 2, depth / 2);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(width / 2, height / 2, -depth / 2);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(width / 2, -height / 2, -depth / 2);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(width / 2, -height / 2, depth / 2);
    //右
    glNormal3f(-1.0, 0.0, 0.0);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(-width / 2, height / 2, -depth / 2);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(-width / 2, height / 2, depth / 2);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(-width / 2, -height / 2, depth / 2);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(-width / 2, -height / 2, -depth / 2);
    //後
    glNormal3f(0.0, 0.0, -1.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(width / 2, height / 2, -depth / 2);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(-width / 2, height / 2, -depth / 2);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(-width / 2, -height / 2, -depth / 2);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(width / 2, -height / 2, -depth / 2);
    //上
    glNormal3f(0.0, 1.0, 0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(width / 2, height / 2, depth / 2);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(-width / 2, height / 2, depth / 2);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(-width / 2, height / 2, -depth / 2);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(width / 2, height / 2, -depth / 2);
    //下
    glNormal3f(0.0, -1.0, 0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(width / 2, -height / 2, depth / 2);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(-width / 2, -height / 2, depth / 2);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(-width / 2, -height / 2, -depth / 2);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(width / 2, -height / 2, -depth / 2);
    glEnd();
    /* テクスチャマッピング終了 */
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
}
//横の棒
void cuboid(float width, float height, float depth)
{   

    glBegin(GL_QUADS);
    //前
    glNormal3f(0.0, 0.0, 1.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(width / 2, height / 2, depth / 2);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(-width / 2, height / 2, depth / 2);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(-width / 2, -height / 2, depth / 2);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(width / 2, -height / 2, depth / 2);
    //左
    glNormal3f(1.0, 0.0, 0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(width / 2, height / 2, depth / 2);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(width / 2, height / 2, -depth / 2);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(width / 2, -height / 2, -depth / 2);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(width / 2, -height / 2, depth / 2);
    //右
    glNormal3f(-1.0, 0.0, 0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(-width / 2, height / 2, -depth / 2);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(-width / 2, height / 2, depth / 2);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(-width / 2, -height / 2, depth / 2);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(-width / 2, -height / 2, -depth / 2);
    //後
    glNormal3f(0.0, 0.0, -1.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(width / 2, height / 2, -depth / 2);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(-width / 2, height / 2, -depth / 2);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(-width / 2, -height / 2, -depth / 2);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(width / 2, -height / 2, -depth / 2);
    //上
    glNormal3f(0.0, 1.0, 0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(width / 2, height / 2, depth / 2);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(-width / 2, height / 2, depth / 2);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(-width / 2, height / 2, -depth / 2);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(width / 2, height / 2, -depth / 2);
    //下
    glNormal3f(0.0, -1.0, 0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(width / 2, -height / 2, depth / 2);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(-width / 2, -height / 2, depth / 2);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(-width / 2, -height / 2, -depth / 2);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(width / 2, -height / 2, -depth / 2);
    glEnd();
}
//トーラス
void torus(int numc, int numt)
{
    int i, j, k;
    double s, t, x, y, z, twopi;

    twopi = 2 * PI;
    for (i = 0; i < numc/2; i++) {
        glBegin(GL_QUAD_STRIP);
        for (j = 0; j <= numt; j++) {
            for (k = 1; k >= 0; k--) {
                s = (i + k) % numc + 0.5;
                t = j % numt;

                x = (1 + .1 * cos(s * twopi / numc)) * cos(t * twopi / numt);
                y = (1 + .1 * cos(s * twopi / numc)) * sin(t * twopi / numt);
                z = .1 * sin(s * twopi / numc);
                glVertex3f(x, y, z);
            }
        }
        glEnd();
    }
}

void stage(){
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Ring);
    glTranslatef(0.0f, 0.2f, 0.0f);
    cylinder(3.0f, 0.2f, 20);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Pillar);
    glTranslatef(2.5f, 3.5f, 0.3f);
    cylinder(0.3f, 3.5f, 20);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Pillar);
    glTranslatef(-2.5f, 3.5f, 0.3f);
    cylinder(0.3f, 3.5f, 20);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Pillar);
    glTranslatef(-1.5f, 3.9f, 2.3f);
    cylinder(0.3f, 3.5f, 20);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Pillar);
    glTranslatef(1.5f, 3.9f, 2.3f);
    cylinder(0.3f, 3.5f, 20);
    glPopMatrix();
}

void building(float minLength, float maxLength, float depth, float height) {
    float sideLength = sqrtf(powf(depth, 2) + powf((maxLength / 2 - minLength / 2), 2));
    glPushMatrix();
    glTranslatef(-12.5f, height / 2 + 0.1f, -70.0f);//直進
    //前
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Building);//後で変える
    glBegin(GL_QUADS);
    glNormal3f(0.0, 0.0, 1.0);
    glTranslatef(0.0f, height / 2, depth / 2);
    glVertex3f(minLength / 2, height / 2, depth / 2);
    glVertex3f(-minLength / 2, height / 2, depth / 2);
    glVertex3f(-minLength / 2, -height / 2, depth / 2);
    glVertex3f(minLength / 2, -height / 2, depth / 2);
    glEnd();
    glPopMatrix();
    
    //後
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Building);//後で変える
    glBegin(GL_QUADS);
    glNormal3f(0.0, 0.0, -1.0);
    glTranslatef(0.0f, height / 2, -depth / 2);
    glVertex3f(maxLength / 2, height / 2, -depth / 2);
    glVertex3f(-maxLength / 2, height / 2, -depth / 2);
    glVertex3f(-maxLength / 2, -height / 2, -depth / 2);
    glVertex3f(maxLength / 2, -height / 2, -depth / 2);
    glEnd();
    glPopMatrix();
    //右
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Building);//後で変える
    glBegin(GL_QUADS);
    glNormal3f(1.0, 0.0, 0.8);
    glVertex3f(minLength / 2, height / 2, depth / 2);
    glVertex3f(maxLength / 2, height / 2, -depth / 2);
    glVertex3f(maxLength / 2, -height / 2, -depth / 2);
    glVertex3f(minLength / 2, -height / 2, depth / 2);
    glEnd();
    glPopMatrix();
    
    //左
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Building);//後で変える
    glBegin(GL_QUADS);
    glNormal3f(-1.0, 0.0, 0.8);
    glVertex3f(-maxLength / 2, height / 2, -depth / 2);
    glVertex3f(-minLength / 2, height / 2, depth / 2);
    glVertex3f(-minLength / 2, -height / 2, depth / 2);
    glVertex3f(-maxLength / 2, -height / 2, -depth / 2);
    
    glEnd();
    glPopMatrix();
    
    //上
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Building);//後で変える
    glBegin(GL_QUADS);
    glTranslatef(0.0f, height / 2, 0.0f);
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3f(minLength / 2, height / 2, depth / 2);
    glVertex3f(-minLength / 2, height / 2, depth / 2);
    glVertex3f(-maxLength / 2, height / 2, -depth / 2);
    glVertex3f(maxLength / 2, height / 2, -depth / 2);
    glEnd();
    glPopMatrix();
    
    //下
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Building);//後で変える
    glBegin(GL_QUADS);
    glTranslatef(0.0f, -height / 2, 0.0f);
    glNormal3f(0.0, -1.0, 0.0);
    glVertex3f(minLength / 2, -height / 2, depth / 2);
    glVertex3f(-minLength / 2, -height / 2, depth / 2);
    glVertex3f(-maxLength / 2, -height / 2, -depth / 2);
    glVertex3f(maxLength / 2, -height / 2, -depth / 2);
    glEnd();
    glPopMatrix();

    //上のリング
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Ring);
    glTranslatef(0, -10.0, 2.5);
    glRotatef(90, 1, 0, 0);
    glutSolidTorus(0.5, 3.0, 200, 8);
    glPopMatrix();

    //ステージ
    glPushMatrix();
    glTranslatef(0.0f, -17.5f, 2.5f);
    stage();
    glPopMatrix();

    glPopMatrix();
}

void post(int n) {//何段作るか
    glMaterialfv(GL_FRONT, GL_DIFFUSE, BigPost);
    /* アルファテスト開始 */
    glEnable(GL_ALPHA_TEST);
    /* テクスチャマッピング開始 */
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texid_4);
    glTranslatef(0, 0.3, 0);
    cuboid(0.8f, 0.6f , 2.75f);
    glTranslatef(0, 0.5, 0);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, SmallPost);
    cuboid(1.0f, 0.4f, 3.0f);

    for (int i = 0; i < (n - 1); i++) {
        glTranslatef(0, 0.5, 0);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, BigPost);
        cuboid(0.8f, 0.6f, 2.75f);
        glTranslatef(0, 0.5, 0);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, SmallPost);
        cuboid(1.0f, 0.4f, 3.0f);
    }
    /* テクスチャマッピング終了 */
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
}

//gateの屋根の設計
void roof(float width, float depth) {
    glPushMatrix();

    //前
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Roof);//後で変える
    glBegin(GL_POLYGON);
    glNormal3f(0.0, 0.0, 1.0);
    glVertex3f(width / 2, 0.0, depth / 2);
    glVertex3f(width / 2, 0.6, depth / 2);
    glVertex3f(width / 2 - 0.5, 0.6, depth / 2);
    glVertex3f(width / 2 - 1.2, 1.5, depth / 2);
    glVertex3f(-width / 2 + 1.2, 1.5, depth / 2);
    glVertex3f(-width / 2 + 0.5, 0.6, depth / 2);
    glVertex3f(-width / 2, 0.6, depth / 2);
    glVertex3f(-width / 2, 0.0, depth / 2);
    glEnd();
    glPopMatrix();

    //後ろ
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Roof);//後で変える
    glBegin(GL_POLYGON);
    glNormal3f(0.0, 0.0, -1.0);
    glVertex3f(width / 2, 0.0, -depth / 2);
    glVertex3f(width / 2, 0.6, -depth / 2);
    glVertex3f(width / 2 - 0.5, 0.6, -depth / 2);
    glVertex3f(width / 2 - 1.2, 1.5, -depth / 2);
    glVertex3f(-width / 2 + 1.2, 1.5, -depth / 2);
    glVertex3f(-width / 2 + 0.5, 0.6, -depth / 2);
    glVertex3f(-width / 2, 0.6, -depth / 2);
    glVertex3f(-width / 2, 0.0, -depth / 2);
    glEnd();
    glPopMatrix();

    //右側面
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Roof);//後で変える
    glBegin(GL_QUADS);
    glNormal3f(1.0, 0.0, 0.0);
    glVertex3f(width / 2, 0.6, depth / 2);
    glVertex3f(width / 2, 0.6, -depth / 2);
    glVertex3f(width / 2, 0.0, -depth / 2);
    glVertex3f(width / 2, 0.0, depth / 2);
    glEnd();
    glPopMatrix();

    //右ヘリの横部分
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Roof);//後で変える
    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3f(width / 2, 0.6, depth / 2);
    glVertex3f(width / 2, 0.6, -depth / 2);
    glVertex3f(width / 2 - 0.5, 0.6, -depth / 2);
    glVertex3f(width / 2 - 0.5, 0.6, depth / 2);
    glEnd();
    glPopMatrix();

    //右ヘリのななめ部分
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Roof);//後で変える
    glBegin(GL_QUADS);
    glNormal3f(1.0, 0.2, 0.0);
    glVertex3f(width / 2 - 0.5, 0.6, -depth / 2);
    glVertex3f(width / 2 - 0.5, 0.6, depth / 2);
    glVertex3f(width / 2 - 1.2, 1.5, depth / 2);
    glVertex3f(width / 2 - 1.2, 1.5, -depth / 2);
    glEnd();
    glPopMatrix();

    //右屋根の上の部分
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Roof);//後で変える
    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3f(width / 2 - 1.2, 1.5, depth / 2);
    glVertex3f(width / 2 - 1.2, 1.5, -depth / 2);
    glVertex3f(width / 2 - 1.5, 1.5, -depth / 2);
    glVertex3f(width / 2 - 1.5, 1.5, depth / 2);
    glEnd();
    glPopMatrix();

    //左側面
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Roof);//後で変える
    glBegin(GL_QUADS);
    glNormal3f(-1.0, 0.0, 0.0);
    glVertex3f(-width / 2, 0.6, depth / 2);
    glVertex3f(-width / 2, 0.6, -depth / 2);
    glVertex3f(-width / 2, 0.0, -depth / 2);
    glVertex3f(-width / 2, 0.0, depth / 2);
    glEnd();
    glPopMatrix();

    //左ヘリの横部分
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Roof);//後で変える
    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3f(-width / 2, 0.6, depth / 2);
    glVertex3f(-width / 2, 0.6, -depth / 2);
    glVertex3f(-width / 2 + 0.5, 0.6, -depth / 2);
    glVertex3f(-width / 2 + 0.5, 0.6, depth / 2);
    glEnd();
    glPopMatrix();

    //左ヘリのななめ部分
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Roof);//後で変える
    glBegin(GL_QUADS);
    glNormal3f(-1.0, 0.2, 0.0);
    glVertex3f(-width / 2 + 0.5, 0.6, -depth / 2);
    glVertex3f(-width / 2 + 0.5, 0.6, depth / 2);
    glVertex3f(-width / 2 + 1.2, 1.5, depth / 2);
    glVertex3f(-width / 2 + 1.2, 1.5, -depth / 2);
    glEnd();
    glPopMatrix();

    //左屋根の上の部分
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Roof);//後で変える
    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3f(-width / 2 + 1.2, 1.5, depth / 2);
    glVertex3f(-width / 2 + 1.2, 1.5, -depth / 2);
    glVertex3f(-width / 2 + 1.5, 1.5, -depth / 2);
    glVertex3f(-width / 2 + 1.5, 1.5, depth / 2);
    glEnd();
    glPopMatrix();

    //奥の線1
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Roof);//後で変える
    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3f(-width / 2 + 1.5, 1.5, -depth / 2);
    glVertex3f(-width / 2 + 1.5, 1.5, -depth / 2 + 0.4);
    glVertex3f(width / 2 - 1.5, 1.5, -depth / 2 + 0.4);
    glVertex3f(width / 2 - 1.5, 1.5, -depth / 2);
    glEnd();
    glPopMatrix();

    //奥の線2
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Roof);//後で変える
    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3f(-width / 2 + 1.5, 1.5, -0.1625);
    glVertex3f(-width / 2 + 1.5, 1.5, -0.4875);
    glVertex3f(width / 2 - 1.5, 1.5, -0.4875);
    glVertex3f(width / 2 - 1.5, 1.5, -0.1625);
    glEnd();
    glPopMatrix();

    //前の線
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Roof);//後で変える
    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3f(-width / 2 + 1.5, 1.5, depth / 2);
    glVertex3f(-width / 2 + 1.5, 1.5, depth / 2 - 0.4);
    glVertex3f(width / 2 - 1.5, 1.5, depth / 2 - 0.4);
    glVertex3f(width / 2 - 1.5, 1.5, depth / 2);
    glEnd();
    glPopMatrix();
    
    //前の線2
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Roof);//後で変える
    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3f(-width / 2 + 1.5, 1.5, 0.1625);
    glVertex3f(-width / 2 + 1.5, 1.5, 0.4875);
    glVertex3f(width / 2 - 1.5, 1.5, 0.4875);
    glVertex3f(width / 2 - 1.5, 1.5, 0.1625);
    glEnd();
    glPopMatrix();

    glPopMatrix();
}

void gate(float x, float y, float z, float width, int height) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glPushMatrix();
    //支柱その1
    glTranslatef(width / 2, 0, 0);//2.5
    post(height);
    glPopMatrix();

    //支柱その2
    glPushMatrix();
    glTranslatef(-width / 2, 0, 0);
    post(height);
    glPopMatrix();

    //横の棒・足元
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Roof);
    glTranslatef(0, height, 0);
    //glRotatef(90 + 2 * x, 0, 1, 0);
    //cuboid(width + 1, 0.12, 0.11 * 25);
    roof(width + 1, 0.11 * 25);
    glPopMatrix();
    glPopMatrix();
}

void ground() {
    static const GLfloat color[] = { 1, 1, 1, 1.0 };  /* 材質 (色) */
                                          //255,82,52
    int i, j;
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Ground);
    /* アルファテスト開始 */
    glEnable(GL_ALPHA_TEST);
    /* テクスチャマッピング開始 */
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texid_5);  // テクスチャID=1を指定
    for (i = -100; i < 100; i++) {
        for (j = -100; j < 100; j++) {
            glPushMatrix();
            glTranslatef(i, 0, j);
            /* １枚の４角形を描く */
            glNormal3d(0.0, 1.0, 0.0);
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
    /* テクスチャマッピング終了 */
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
}
//道の作成
void loadway() {
    int i, j;
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Loadway);
    /* アルファテスト開始 */
    //glEnable(GL_ALPHA_TEST);
    /* テクスチャマッピング開始 */
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texid_2);
    for (i = -3; i < 3; i++) {
        for (j = 0; j > -32; j--) {
            glPushMatrix();
            glTranslatef(i, 0, j);
            /* １枚の４角形を描く */
            glNormal3d(0.0, 1.0, 0.0);
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

    for (i = -3; i < 3; i++) {
        for (j = 0; j > -16; j--) {
            glPushMatrix();
            glTranslatef(j, 0, i -29);
            /* １枚の４角形を描く */
            glNormal3d(0.0, 1.0, 0.0);
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

    for (i = -3; i < 3; i++) {
        for (j = 0; j > -32; j--) {
            glPushMatrix();
            glTranslatef(i - 12.5, 0.1, j - 32);
            /* １枚の４角形を描く */
            glNormal3d(0.0, 1.0, 0.0);
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
    /* テクスチャマッピング終了 */
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}
//道のりの石垣
void wayStoneStep() {
    for (int i = 0; i <= 56; i++) {
        glPushMatrix();
        
        if (i >= 55) {
            glTranslatef(-16.5 - ( (double)i - 55 ), 0, -39.0f);
            glRotatef(90, 0, 1, 0);
        }
        else if (i > 35) {
            glTranslatef(-16.5, 0, -20-( i - 45 ));
            glRotatef(-90, 0, 1, 0);
        }
        else if (i >= 20) {//横向きになるとき
            glTranslatef(-i + 20.5, 0, -20);
            glRotatef(90, 0, 1, 0);
        }
        else {
            glTranslatef(0, 0, -i - 5);//直進
        }

        //右
        if (i < 30) {
            glPushMatrix();

            glTranslatef(4.5, 1.25, 0);
            if (i >= 20) {
                glTranslatef(10.0, 0, 0);//幅の調整
                if (i == 20) {//前向きと右向きの境目
                    glTranslatef(0, 0, 2.0);
                    stonepart(1.0f, 2.5f, 5.0f);
                }
                else {
                    stonepart(1.0f, 2.5f, 1.0f);
                }
            }

            else if (i == 19) {//前向きと右向きの境目
                glTranslatef(0, 0, -5);
                stonepart(1.0f, 2.5f, 12.0f);
            }
            else {
                stonepart(1.0f, 2.5f, 1.0f);
            }
            glPopMatrix();
        }
            
        
        //左
        if (i < 11 || i >= 25) {
            glPushMatrix();
            if (i == 35) {
                glTranslatef(-4.5, 1.25, 0.0);
                stonepart(1.0f, 2.5f, 3.0f);
            }
            else {
                glTranslatef(-4.5, 1.25, 0);
                stonepart(1.0f, 2.5f, 1.0f);
            }
            glPopMatrix();
        }
        glPopMatrix();
    }
}
//囲うための石垣
void surroundStoneStep() {
    for (int i = 0; i < 30; i++) {
        glPushMatrix();
        glMaterialfv(GL_FRONT, GL_DIFFUSE, Stone);
        glTranslatef(-12.5f, 0.0f, -35.5f - i);//直進  

        //右
        
        glPushMatrix();

        glTranslatef(5.0, 1.25, 0);

        stonepart(1.0f, 2.5f, 1.0f);
        
        glPopMatrix();
        
        //左
        glPushMatrix();
        glTranslatef(-5.0, 1.25, 0);
        stonepart(1.0f, 2.5f, 1.0f);
        glPopMatrix();

        glPopMatrix();
    }
}

void signboard() {
    glPushMatrix();
    //移動
    glTranslatef(-6.5f, 1.5f, -32.0f);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Signboard);
    glPushMatrix();
    glTranslatef(-1.5f, 0, 0);
    cylinder(0.25f, 1.5f, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5f, 0, 0);
    cylinder(-0.25f, 1.5f, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.5f, 0);
    cuboid(2.5f, 2.0f, 0.5f);
    glPopMatrix();

    glPopMatrix();
}

/*木の葉の描画*/
void leaf() {
    glPushMatrix();

    /* 図形の色 (白) */
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Leaf);
    /* アルファテスト開始 */
    glEnable(GL_ALPHA_TEST);
    /* テクスチャマッピング開始 */
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texid_3);  // テクスチャID=1を指定
    /* 図形の描画 */
    /* １枚の４角形を描く */
    glNormal3d(0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
    glTexCoord2d(0.0, 1.0);
    glVertex3d(-1.5, -1.5, 0.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3d(1.5, -1.5, 0.0);
    glTexCoord2d(1.0, 0.0);
    glVertex3d(1.5, 1.5, 0.0);
    glTexCoord2d(0.0, 0.0);
    glVertex3d(-1.5, 1.5, 0.0);
    glEnd();
    /* テクスチャマッピング終了 */
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

/*木の描画*/
void tree() {
    int i;
    /*葉の描画*/
    for (i = 0; i < 10; i++) {
        glPushMatrix();
        glRotated((float)(360.0f / (20.0f * i)), 0.0, 1.0, 0.0);
        glTranslated(0.0, 2.5, 0.0);
        leaf();
        glRotated(180, 0.0, 1.0, 0.0);
        leaf();
        glPopMatrix();
    }
    /*幹の描画*/
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Branch);
    cylinder(0.3f, 1.0f, 10);
    glPopMatrix();
}
//木の配置
void generateTree() {
    glPushMatrix();
    glTranslatef(-12.5f, 1.0f, -50.0f);
    
    glPushMatrix();
    glTranslatef(-7.5f, 0.0f, 0.0f);
    for (int i = 0; i < 4; i++) {
        tree();
        glTranslatef(0.0f, 0.0f, -4.0f);
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(7.5f, 0.0f, 0.0f);
    for (int i = 0; i < 4; i++) {
        tree();
        glTranslatef(0.0f, 0.0f, -4.0f);
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10.5f, 0.0f, -4.0f);
    for (int i = 0; i < 2; i++) {
        tree();
        glTranslatef(0.0f, 0.0f, -4.0f);
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10.5f, 0.0f, -4.0f);
    for (int i = 0; i < 2; i++) {
        tree();
        glTranslatef(0.0f, 0.0f, -4.0f);
    }
    glPopMatrix();

    glPopMatrix();
}