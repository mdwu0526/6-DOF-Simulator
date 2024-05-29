// main.cpp

#include <iostream>

#include "RK4.h"
#include "MassSpringDamper.h"

int main() {
    RK4 rk4Solver;
    MassSpringDamper sys;

    // Set the solver to Runge-Kutta 4
    sys.setSolver(&rk4Solver);

    // Initialize Parameters
    double m = 1;
    double c = 1;
    double k = 1;
    sys.setParameters(m, c, k);

    double timeStep = 0.01;
    int numSteps = 1000;

    // Set iniital condition
    Eigen::VectorXd x0(2);
    x0 << 1, 0;

    sys.setSystemDynamics([&sys](const Eigen::VectorXd& prevState){
        return sys.systemDynamics(prevState);
    });

    // Solve
    Eigen::VectorXd x = sys.solve(x0, timeStep, numSteps);

    // Print
    std::cout << x << std::endl;

    return 0;
} // main()