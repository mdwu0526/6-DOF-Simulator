// ForwardEuler.h
#ifndef FORWARDEULER_H
#define FORWARDEULER_H

#include "Solver.h"

class ForwardEuler : public Solver {
    Eigen::VectorXd solve(const std::function<Eigen::VectorXd(const Eigen::VectorXd&)>& systemDynamics,
                          const Eigen::VectorXd& initialState, double timeStep, int numSteps) override;
};

#endif // FORWARDEULER_H