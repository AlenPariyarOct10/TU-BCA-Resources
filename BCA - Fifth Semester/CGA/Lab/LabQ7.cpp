#include <graphics.h>
#include <stdio.h>
#include <math.h>

void translate(int *x, int *y, int tx, int ty);
void rotate(int *x, int *y, float angle, int pivotX, int pivotY);
void scale(int *x, int *y, float sx, float sy, int pivotX, int pivotY);
void shear(int *x, int *y, float shx, float shy);
void reflect(int *x, int *y, char axis);

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
 
    int x1 = 200, y1 = 100;
    int x2 = 150, y2 = 200;
    int x3 = 250, y3 = 200;
	outtextxy(250, 400, "Coded by Alen Pariyar");
    // Draw original triangle
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtextxy(x1, y1 - 20, "Original");

    // 2D Translation
    int tx, ty;
    printf("Enter translation values (tx ty): ");
    scanf("%d %d", &tx, &ty);
    translate(&x1, &y1, tx, ty);
    translate(&x2, &y2, tx, ty);
    translate(&x3, &y3, tx, ty);
    setcolor(YELLOW);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtextxy(x1, y1 - 20, "Translated");

    // 2D Rotation
    float angle;
    printf("Enter rotation angle (in degrees): ");
    scanf("%f", &angle);
    int pivotX = (x1 + x2 + x3) / 3;  
    int pivotY = (y1 + y2 + y3) / 3;
    rotate(&x1, &y1, angle, pivotX, pivotY);
    rotate(&x2, &y2, angle, pivotX, pivotY);
    rotate(&x3, &y3, angle, pivotX, pivotY);
    setcolor(GREEN);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtextxy(x1, y1 - 20, "Rotated");

    // 2D Scaling
    float sx, sy;
    printf("Enter scaling factors (sx sy): ");
    scanf("%f %f", &sx, &sy);
    scale(&x1, &y1, sx, sy, pivotX, pivotY);
    scale(&x2, &y2, sx, sy, pivotX, pivotY);
    scale(&x3, &y3, sx, sy, pivotX, pivotY);
    setcolor(RED);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtextxy(x1, y1 - 20, "Scaled");

    // 2D Shearing
    float shx, shy;
    printf("Enter shearing factors (shx shy): ");
    scanf("%f %f", &shx, &shy);
    shear(&x1, &y1, shx, shy);
    shear(&x2, &y2, shx, shy);
    shear(&x3, &y3, shx, shy);
    setcolor(CYAN);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtextxy(x1, y1 - 20, "Sheared");

    // 2D Reflection
    char axis;
    printf("Enter reflection axis (x/y): ");
    scanf(" %c", &axis);
    reflect(&x1, &y1, axis);
    reflect(&x2, &y2, axis);
    reflect(&x3, &y3, axis);
    setcolor(MAGENTA);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtextxy(x1, y1 - 20, "Reflected");

    getch();
    closegraph();
    return 0;
}

// Function definitions

// 2D Translation
void translate(int *x, int *y, int tx, int ty) {
    *x += tx;
    *y += ty;
}

// 2D Rotation
void rotate(int *x, int *y, float angle, int pivotX, int pivotY) {
    float radians = angle * (M_PI / 180.0);
    int newX = (int)(pivotX + (*x - pivotX) * cos(radians) - (*y - pivotY) * sin(radians));
    int newY = (int)(pivotY + (*x - pivotX) * sin(radians) + (*y - pivotY) * cos(radians));
    *x = newX;
    *y = newY;
}

// 2D Scaling
void scale(int *x, int *y, float sx, float sy, int pivotX, int pivotY) {
    *x = (int)(pivotX + (*x - pivotX) * sx);
    *y = (int)(pivotY + (*y - pivotY) * sy);
}

// 2D Shearing
void shear(int *x, int *y, float shx, float shy) {
    *x += (int)(shx * (*y));
    *y += (int)(shy * (*x));
}

// 2D Reflection
void reflect(int *x, int *y, char axis) {
    if (axis == 'x') {
        *y = -(*y);
    } else if (axis == 'y') {
        *x = -(*x);
    }
}
