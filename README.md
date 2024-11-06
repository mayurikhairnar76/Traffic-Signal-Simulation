Traffic Signal Simulation
This project is a simple traffic signal simulation in C++ that uses the graphics.h library. It creates a basic traffic light system and controls the movement of cars according to the traffic light's color.

Features
Traffic Light Structure: Displays a simple traffic light structure with three lights (red, yellow, and green).
Dynamic Light Control: Changes light color based on user input.
Car Movement: Moves cars on the screen and stops them according to the traffic signal.
User Interaction: Allows users to press keys to change the light color.
Code Overview
Key Components
Draw Traffic Light Structure:

The drawTrafficLight function draws the outer structure and individual boxes for each light (red, yellow, green).
Light Control:

The setLight function determines which light is currently active and colors it accordingly.
Car Drawing and Movement:

The drawCar function creates a simple car at the specified position.
Car movement is controlled by checking the traffic light status. When the light is red or yellow, the cars stop, and when it's green, they move.
User Input:

The program listens for key presses: R (red), Y (yellow), and G (green), to change the light color.
Functions
drawTrafficLight(int x, int y): Draws the traffic light structure at a given position.
setLight(int x, int y, int red, int yellow, int green): Sets the light color based on the active signal.
drawCar(int x, int y, int color): Draws a car at a specified position and color.
main(): Initializes graphics, handles car movements, and processes user input.
Traffic Light Control Logic
R or r key: Sets light to Red, stopping all cars near the traffic light.
Y or y key: Sets light to Yellow, temporarily stopping all cars.
G or g key: Sets light to Green, allowing all cars to move.
How to Use
Compile and Run: Compile the code using a compiler that supports graphics.h (e.g., Turbo C++).
Control Traffic Light:
Press R for red light.
Press Y for yellow light.
Press G for green light.
Observe Car Behavior:
Cars will stop at the red light, pause at yellow, and move at green.
Prerequisites
To run this program, you will need:

Turbo C++ or another IDE that supports graphics.h.
graphics.h and conio.h libraries must be included.
