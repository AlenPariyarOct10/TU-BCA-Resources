#include <graphics.h>
#include <conio.h>

// Function to implement Boundary-Fill Algorithm
void boundaryFill(int x, int y, int fill_color, int boundary_color) {
    int current_color = getpixel(x, y);
    if (current_color != boundary_color && current_color != fill_color) {
        putpixel(x, y, fill_color);

        // Recursively call the boundary fill for the neighboring pixels
        boundaryFill(x + 1, y, fill_color, boundary_color); // Right
        boundaryFill(x - 1, y, fill_color, boundary_color); // Left
        boundaryFill(x, y + 1, fill_color, boundary_color); // Down
        boundaryFill(x, y - 1, fill_color, boundary_color); // Up
    }
}

int main() {
    int gd = DETECT, gm;
    
    // Initialize the graphics mode
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
	printf("This program is coded by Alen Pariyar, Roll No. 4\n");
    // Draw a rectangle (boundary)
    rectangle(100, 100, 200, 200);

    // Set the starting point and the colors
    int x = 150, y = 150;          // Starting point (inside the rectangle)
    int fill_color = 4;            // Red color
    int boundary_color = 15;       // White color (rectangle boundary)

    // Call Boundary-Fill Algorithm
    boundaryFill(x, y, fill_color, boundary_color);

    getch();  // Wait for a key press
    closegraph();  // Close the graphics mode

    return 0;
}
