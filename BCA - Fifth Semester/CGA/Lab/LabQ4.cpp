#include <stdio.h>
#include <graphics.h>

// Function to draw the ellipse points using 4-way symmetry
void drawEllipsePoints(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
}

// Function to implement Midpoint Ellipse Drawing Algorithm
void midpointEllipse(int xc, int yc, int rx, int ry) {
    float dx, dy, d1, d2, x, y;
    x = 0;
    y = ry;

    // Initial decision parameter of region 1
    d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;

    // For region 1
    while (dx < dy) {
        // Plot the points based on 4-way symmetry
        drawEllipsePoints(xc, yc, x, y);

        // Checking and updating decision parameter based on midpoint value
        if (d1 < 0) {
            x++;
            dx = dx + (2 * ry * ry);
            d1 = d1 + dx + (ry * ry);
        } else {
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);
        }
    }

    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);

    while (y >= 0) {
        drawEllipsePoints(xc, yc, x, y);

        if (d2 > 0) {
            y--;
            dy = dy - (2 * rx * rx);
            d2 = d2 + (rx * rx) - dy;
        } else {
            y--;
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d2 = d2 + dx - dy + (rx * rx);
        }
    }
}

int main() {
    int xc, yc, rx, ry;
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

	printf("This program is coded by Alen Pariyar, Roll No. 4\n");
    printf("Enter the center of the ellipse (xc, yc): ");
    scanf("%d %d", &xc, &yc);
    printf("Enter the x-radius (rx) and y-radius (ry) of the ellipse: ");
    scanf("%d %d", &rx, &ry);

    midpointEllipse(xc, yc, rx, ry);

    getch();
    closegraph();

    return 0;
}
