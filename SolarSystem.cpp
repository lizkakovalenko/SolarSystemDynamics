#include <iostream>
#include <cmath>

const double G = 6.67408e-11; // gravitational constant

// struct to store information about a celestial body
struct Body {
    double mass; // mass in kilograms
    double x, y, z; // position in 3D space
    double vx, vy, vz; // velocity in 3D space
    double ax, ay, az; // acceleration in 3D space
};

int main()
{
    // initialize bodies
    Body sun;
    sun.mass = 1.989e30;
    sun.x = 0;
    sun.y = 0;
    sun.z = 0;
    sun.vx = 0;
    sun.vy = 0;
    sun.vz = 0;
    sun.ax = 0;
    sun.ay = 0;
    sun.az = 0;

    Body earth;
    earth.mass = 5.972e24;
    earth.x = 1.496e11;
    earth.y = 0;
    earth.z = 0;
    earth.vx = 0;
    earth.vy = 2.978e4;
    earth.vz = 0;
    earth.ax = 0;
    earth.ay = 0;
    earth.az = 0;

    // simulation time step
    double dt = 86400; // one day in seconds
    int num_steps = 365; // number of steps in a year

    for (int i = 0; i < num_steps; i++) {
        // calculate distance between bodies
        double dx = earth.x - sun.x;
        double dy = earth.y - sun.y;
        double dz = earth.z - sun.z;
        double r = sqrt(dx*dx + dy*dy + dz*dz);

        // calculate force of gravity
        double f = G * earth.mass * sun.mass / (r*r);

        // calculate acceleration of earth
        earth.ax = f * dx / (earth.mass * r);
        earth.ay = f * dy / (earth.mass * r);
        earth.az = f * dz / (earth.mass * r);

        // update velocity and position of earth
        earth.vx += earth.ax * dt;
        earth.vy += earth.ay * dt;
        earth.vz += earth.az * dt;
        earth.x += earth.vx * dt;
        earth.y += earth.vy * dt;
        earth.z += earth.vz * dt;
    }

    std::cout << "Final position of Earth: (" << earth.x << ", " << earth.y << ", " << earth.z << ")" << std::endl;
    std::cout << "Final velocity of Earth: (" << earth.vx << ", " << earth.vy << ", " << earth.vz << ")" << std::endl;

    return 0;
}
