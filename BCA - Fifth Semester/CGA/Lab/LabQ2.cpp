#include <stdio.h>
#include <graphics.h>

void drawLine(int x1, int y1, int x2, int y2) {
    int dx, dy, p, x, y;
    
    // Calculate the differences in x and y
    dx = x2 - x1;
    dy = y2 - y1;

    // Initialize starting point
    x = x1;
    y = y1;

    // Decision parameter
    p = 2 * dy - dx;

    // Plot the first point
    putpixel(x, y, WHITE);

    // Iterate over x to draw the line
    while (x < x2) {
        x++;  // Increment x

        // Update decision parameter and corresponding y
        if (p < 0) {
            p = p + 2 * dy;
        } else {
            p = p + 2 * dy - 2 * dx;
            y++;  // Increment y if decision parameter is >= 0
        }

        // Plot the next point
        putpixel(x, y, WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;

    // Initialize graphics mode
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Input the two points
    printf("This program is coded by Alen Pariyar, Roll No. 4\n");
    printf("Enter the coordinates of the first point (x1, y1): ");
    scanf("%d%d", &x1, &y1);
    printf("Enter the coordinates of the second point (x2, y2): ");
    scanf("%d%d", &x2, &y2);

    // Call Bresenham's line drawing function
    drawLine(x1, y1, x2, y2);

    getch();  // Wait for key press
    closegraph();  // Close the graphics window

    return 0;
}
