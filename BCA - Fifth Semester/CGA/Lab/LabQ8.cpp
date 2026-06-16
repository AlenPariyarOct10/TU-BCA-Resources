#include <stdio.h>
#include <graphics.h>

float wxmin, wymin, wxmax, wymax; 
float vxmin, vymin, vxmax, vymax;

// Define region codes for clipping
#define INSIDE 0
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

// Function to compute the region code for a point
int computeCode(float x, float y) {
    int code = INSIDE;

    if (x < vxmin)      // to the left of viewport
        code |= LEFT;
    else if (x > vxmax) // to the right of viewport
        code |= RIGHT;
    if (y < vymin)      // below the viewport
        code |= BOTTOM;
    else if (y > vymax) // above the viewport
        code |= TOP;

    return code;
}

void cohenSutherlandClip(float x1, float y1, float x2, float y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    int accept = 0;

    while (1) {
        if ((code1 == 0) && (code2 == 0)) {
            accept = 1;
            break;
        } else if (code1 & code2) {
            break;
        } else {
            float x, y;
            int codeOut = (code1 != 0) ? code1 : code2;

            if (codeOut & TOP) {
                x = x1 + (x2 - x1) * (vymax - y1) / (y2 - y1);
                y = vymax;
            } else if (codeOut & BOTTOM) {
                x = x1 + (x2 - x1) * (vymin - y1) / (y2 - y1);
                y = vymin;
            } else if (codeOut & RIGHT) {
                y = y1 + (y2 - y1) * (vxmax - x1) / (x2 - x1);
                x = vxmax;
            } else if (codeOut & LEFT) {
                y = y1 + (y2 - y1) * (vxmin - x1) / (x2 - x1);
                x = vxmin;
            }

            if (codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    if (accept) {
        setcolor(GREEN);
        line(x1, y1, x2, y2);
    }
}

void windowToViewport(int xw, int yw, int *xv, int *yv) {
    *xv = (int)(vxmin + ((xw - wxmin) * (vxmax - vxmin) / (wxmax - wxmin)));
    *yv = (int)(vymin + ((yw - wymin) * (vymax - vymin) / (wymax - wymin)));
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xw1, yw1, xw2, yw2; 
    int xv1, yv1, xv2, yv2; 

    wxmin = 50;  wymin = 50;
    wxmax = 300; wymax = 300;

    vxmin = 350; vymin = 50;
    vxmax = 600; vymax = 300;

    setcolor(WHITE);
    rectangle(wxmin, wymin, wxmax, wymax);
	printf("This program is coded by Alen Pariyar. Roll No. 4\n");
    printf("Enter the coordinates of the line inside the window:\n");
    printf("x1, y1: ");
    scanf("%d %d", &xw1, &yw1);
    printf("x2, y2: ");
    scanf("%d %d", &xw2, &yw2);

    setcolor(WHITE);
    line(xw1, yw1, xw2, yw2);
    delay(2000);

    windowToViewport(xw1, yw1, &xv1, &yv1);
    windowToViewport(xw2, yw2, &xv2, &yv2);

    setcolor(GREEN);
    rectangle(vxmin, vymin, vxmax, vymax);

    cohenSutherlandClip(xv1, yv1, xv2, yv2);

    getch();
    closegraph();
    return 0;
}
