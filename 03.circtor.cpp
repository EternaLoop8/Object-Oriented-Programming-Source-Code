#include <iostream>
#include <cmath> // Required for sqrt() and round()

using namespace std;

enum ConsoleColor {
    cRESET = 0,
    cRED = 31,
    cGREEN = 32,
    cYELLOW = 33,
    cBLUE = 34,
    cMAGENTA = 35,
    cCYAN = 36,
    cWHITE = 37
};

class circle 
{
protected: 
    int xCo, yCo; // coordinates of center (not strictly needed for simple terminal centering, but kept for your class structure)
    int radius;
    ConsoleColor fillcolor;

public:
    // Constructor to initialize the circle
    circle(int r, ConsoleColor color) {
        radius = r;
        fillcolor = color;
        xCo = r;
        yCo = r;
    }

    // Function to draw the circle in the terminal grid
    void draw() {
        // ANSI escape code to change text color
        cout << "\033[" << fillcolor << "m";

        // Loop through a bounding box grid around the circle
        // Terminal text rows (Y) are taller, so we iterate through rows and columns
        for (int y = -radius; y <= radius; y++) {
            for (int x = -radius * 2; x <= radius * 2; x++) {
                
                // Adjust for terminal character aspect ratio (X is stretched by 2.0)
                double adjustedX = x / 2.0; 
                
                // Calculate distance from center (0,0)
                double distance = sqrt(adjustedX * adjustedX + y * y);

                // If distance is close to the radius, print a character
                // We use a small thickness threshold (e.g., 0.5) to make the border visible
                if (distance > radius - 0.5 && distance < radius + 0.5) {
                    cout << "*";
                } else {
                    cout << " "; // Print empty space inside and outside
                }
            }
            cout << endl; // Move to the next row
        }

        // Reset terminal color back to default
        cout << "\033[" << cRESET << "m";
    }
};

int main() {
    // Create a circle with a radius of 8 and a CYAN color
    circle myCircle(8, cCYAN);
    
    // Draw it to the VS Code terminal
    myCircle.draw();

    return 0;
}
