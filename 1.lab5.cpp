#include <iostream>
#include <cmath>

double dy_dx(double x, double y) {
    return x + y;
}


double euler(double x0, double y0, double h) {
    double y = y0 + h * dy_dx(x0, y0);
    return y;
}


double heun(double x0, double y0, double h) {
    double k1 = h * dy_dx(x0, y0);
    double k2 = h * dy_dx(x0 + h, y0 + k1);
    double y = y0 + 0.5 * (k1 + k2);
    return y;
}


double rungeKutta(double x0, double y0, double h) {
    double k1 = h * dy_dx(x0, y0);
    double k2 = h * dy_dx(x0 + 0.5 * h, y0 + 0.5 * k1);
    double k3 = h * dy_dx(x0 + 0.5 * h, y0 + 0.5 * k2);
    double k4 = h * dy_dx(x0 + h, y0 + k3);

    double y = y0 + (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
    return y;
}

int main() {
    double x_target = 0.4;
    double y_initial = 1.0;
    double h1 = 0.1;
    double h2 = 0.2;

    std::cout << "Using Euler's algorithm:" << std::endl;
    std::cout << "h = 0.1, y = " << euler(0, y_initial, h1) << std::endl;
    std::cout << "h = 0.2, y = " << euler(0, y_initial, h2) << std::endl;

    std::cout << "\nUsing Heun's algorithm:" << std::endl;
    std::cout << "h = 0.1, y = " << heun(0, y_initial, h1) << std::endl;
    std::cout << "h = 0.2, y = " << heun(0, y_initial, h2) << std::endl;

    std::cout << "\nUsing Runge-Kutta 4th order method:" << std::endl;
    std::cout << "h = 0.1, y = " << rungeKutta(0, y_initial, h1) << std::endl;
    std::cout << "h = 0.2, y = " << rungeKutta(0, y_initial, h2) << std::endl;

    return 0;
}

