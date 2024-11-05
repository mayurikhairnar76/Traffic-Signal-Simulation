#include <graphics.h>
#include <conio.h>
#include <iostream>

// Function to draw the traffic light structure
void drawTrafficLight(int x, int y) {
    setcolor(WHITE);
    rectangle(x, y, x + 60, y + 180);           // Outer frame
    rectangle(x + 15, y + 10, x + 45, y + 60);  // Red light box
    rectangle(x + 15, y + 70, x + 45, y + 120); // Yellow light box
    rectangle(x + 15, y + 130, x + 45, y + 180); // Green light box.
}

// Function to control which light is on
void setLight(int x, int y, int red, int yellow, int green) {
    setfillstyle(SOLID_FILL, red ? RED : BLACK);
    fillellipse(x + 30, y + 35, 15, 15);   // Red light
    setfillstyle(SOLID_FILL, yellow ? YELLOW : BLACK);
    fillellipse(x + 30, y + 95, 15, 15);   // Yellow light
    setfillstyle(SOLID_FILL, green ? GREEN : BLACK);
    fillellipse(x + 30, y + 155, 15, 15);  // Green light
}

// Function to draw a car at the given position
void drawCar(int x, int y, int color) {
    setfillstyle(SOLID_FILL, color);
    bar(x, y, x + 50, y + 20);         // Car body
    setfillstyle(SOLID_FILL, BLACK);
    fillellipse(x + 10, y + 20, 5, 5); // Wheel 1
    fillellipse(x + 40, y + 20, 5, 5); // Wheel 2
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int trafficLightX = 300, trafficLightY = 150; // Traffic light position
    int car1X = 50, car1Y = 300;                  // Car 1 starting position
    int car2X = 100, car2Y = 350;                 // Car 2 starting position
    int car3X = -100, car3Y = 400;                // Car 3 starting position

    int currentLight = 0;                         // 0 = Red, 1 = Yellow, 2 = Green
    int carSpeed = 5;                             // Car speed
    bool stopCar1 = false, stopCar2 = false, stopCar3 = false;

    while (1) {
        cleardevice();  // Clear the screen to refresh the frame

        // Draw traffic light structure and cars
        drawTrafficLight(trafficLightX, trafficLightY);
        
        // Draw the cars
        drawCar(car1X, car1Y, BLUE);
        drawCar(car2X, car2Y, GREEN);
        drawCar(car3X, car3Y, CYAN);

        // Set light based on the current state
        if (currentLight == 0) { // Red
            setLight(trafficLightX, trafficLightY, 1, 0, 0);
            stopCar1 = (car1X + 50 >= trafficLightX - 10 && car1X <= trafficLightX + 60);
            stopCar2 = (car2X + 50 >= trafficLightX - 10 && car2X <= trafficLightX + 60);
            stopCar3 = (car3X + 50 >= trafficLightX - 10 && car3X <= trafficLightX + 60);
        } else if (currentLight == 1) { // Yellow
            setLight(trafficLightX, trafficLightY, 0, 1, 0);
            stopCar1 = stopCar2 = stopCar3 = true; // Yellow light stops all cars temporarily
        } else if (currentLight == 2) { // Green
            setLight(trafficLightX, trafficLightY, 0, 0, 1);
            stopCar1 = stopCar2 = stopCar3 = false; // Green light allows all cars to move
        }

        // Move cars if not stopped
        if (!stopCar1) car1X += carSpeed;
        if (!stopCar2) car2X += carSpeed;
        if (!stopCar3) car3X += carSpeed;

        // Loop cars back to the start if they go off screen
        if (car1X > getmaxx()) car1X = -50;
        if (car2X > getmaxx()) car2X = -50;
        if (car3X > getmaxx()) car3X = -50;

        // Display user instructions
        setcolor(WHITE);
        outtextxy(200, 450, "Press R for Red, Y for Yellow, G for Green");

        // Check for user input to change light
        if (kbhit()) {
            char ch = getch();
            if (ch == 'r' || ch == 'R') currentLight = 0;  // Red
            if (ch == 'y' || ch == 'Y') currentLight = 1;  // Yellow
            if (ch == 'g' || ch == 'G') currentLight = 2;  // Green
        }

        delay(100);  // Small delay to control frame refresh rate
    }

    closegraph();
    return 0;
}

