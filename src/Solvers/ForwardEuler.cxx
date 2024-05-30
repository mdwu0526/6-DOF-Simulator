// ForwardEuler.cpp

#include "Solvers/ForwardEuler.h"

Eigen::VectorXd ForwardEuler::solve(const std::function<Eigen::VectorXd(const Eigen::VectorXd&)>& systemDynamics,
                                    const Eigen::VectorXd& initialState, double timeStep, int numSteps){

    double time = 0;

    int size = initialState.size();

    Eigen::VectorXd Y = initialState;

    for (int i = 1; i < numSteps; ++i) {
        Y = Y + timeStep * systemDynamics(Y);

        time += timeStep;

    } // for

    return Y;
    
} // solve()