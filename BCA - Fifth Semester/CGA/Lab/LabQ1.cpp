#include <stdio.h>
#include <graphics.h>
#include <math.h>

void drawLine(int x1, int y1, int x2, int y2) {
    int dx, dy, steps, k;
    float xIncrement, yIncrement, x = x1, y = y1;

    // Calculate the differences in x and y
    dx = x2 - x1;
    dy = y2 - y1;

    // Determine the number of steps needed
    steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    // Calculate the increment in x and y for each step
    xIncrement = dx / (float)steps;
    yIncrement = dy / (float)steps;

    // Plot the first point
    putpixel(round(x), round(y), WHITE);

    // Loop to plot the points for each step
    for (k = 0; k < steps; k++) {
        x += xIncrement;
        y += yIncrement;
        putpixel(round(x), round(y), WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
	printf("This program is coded by Alen Pariyar, Roll No. 4\n");
    printf("Enter the coordinates of the first point (x1, y1): ");
    scanf("%d%d", &x1, &y1);
    printf("Enter the coordinates of the second point (x2, y2): ");
    scanf("%d%d", &x2, &y2);

    drawLine(x1, y1, x2, y2);

    getch(); 
    closegraph();

    return 0;
}
