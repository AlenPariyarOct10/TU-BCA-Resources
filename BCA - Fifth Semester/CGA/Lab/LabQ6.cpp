#include <stdio.h>
#include <graphics.h>

// Function to implement the Flood-Fill Algorithm
void floodFill(int x, int y, int oldColor, int newColor) {
    if (getpixel(x, y) == oldColor) {
        putpixel(x, y, newColor);
        floodFill(x + 1, y, oldColor, newColor);
        floodFill(x - 1, y, oldColor, newColor);
        floodFill(x, y + 1, oldColor, newColor);
        floodFill(x, y - 1, oldColor, newColor);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
	printf("This program is coded by Alen Pariyar, Roll No. 4\n");
    // Drawing a rectangle
    rectangle(100, 100, 200, 200);

    // Filling the rectangle using floodFill
    floodFill(150, 150, BLACK, RED);

    getch();
    closegraph();
    return 0;
}
