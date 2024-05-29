// RK4.cpp

// #include <iostream>
#include "RK4.h"

Eigen::VectorXd RK4::solve(const std::function<Eigen::VectorXd(const Eigen::VectorXd&)>& systemDynamics,
                           const Eigen::VectorXd& initialState, double timeStep, int numSteps) {
    
    double time = 0;

    int size = initialState.size();
    
    // Initialize all vectors
    Eigen::VectorXd K1(size);
    Eigen::VectorXd K2(size);
    Eigen::VectorXd K3(size);
    Eigen::VectorXd K4(size);

    // Create Output Vector with initial states
    Eigen::VectorXd Y = initialState;

    // Solve
    for(int i = 1; i < numSteps; ++i) {
        K1 = systemDynamics(Y);
        K2 = systemDynamics(Y + K1 * timeStep / 2);
        K3 = systemDynamics(Y + K2 * timeStep / 2);
        K4 = systemDynamics(Y + K3 * timeStep);

        // Predict by a time step
        Y = Y + timeStep * ((K1 + 2*K2 + 2*K3 + K4) / 6);

        // Advance time by a time step
        time += timeStep;

        // std::cout << "Time: " << time << '\n';
        // std::cout << "K1: " << K1.transpose() << '\n';
        // std::cout << "K2: " << K2.transpose() << '\n';
        // std::cout << "K3: " << K3.transpose() << '\n';
        // std::cout << "K4: " << K4.transpose() << '\n';
        // std::cout << "Y: " << Y.transpose() << '\n';

    } // for

    return Y;
} // solve()