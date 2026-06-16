#include <stdio.h>
#include <graphics.h>

// Function to draw the circle points using 8-way symmetry
void drawCirclePoints(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

// Function to implement Midpoint Circle Drawing Algorithm
void midpointCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int p = 1 - r;  // Initial decision parameter

    // Plot the initial point at (0, r)
    drawCirclePoints(xc, yc, x, y);

    // Loop to plot points in each octant
    while (x <= y) {
        x++;

        // Update decision parameter and y-coordinate
        if (p < 0) {
            p = p + 2 * x + 1;
        } else {
            y--;
            p = p + 2 * x - 2 * y + 1;
        }

        // Plot the new points in all octants
        drawCirclePoints(xc, yc, x, y);
    }
}

int main() {
    int gd = DETECT, gm;
    int xc, yc, r;

    // Initialize graphics mode
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
   printf("This program is coded by Alen Pariyar, Roll No. 4\n");
    // Input the center and radius of the circle
    printf("Enter the center of the circle (xc, yc): ");
    scanf("%d%d", &xc, &yc);
    printf("Enter the radius of the circle: ");
    scanf("%d", &r);

    // Call the Midpoint Circle Drawing function
    midpointCircle(xc, yc, r);

    getch();  // Wait for key press
    closegraph();  // Close the graphics window

    return 0;
}
