// RK4.h
#ifndef RK4_H
#define RK4_H

#include "Solver.h"

class RK4 : public Solver {
    Eigen::VectorXd solve(const std::function<Eigen::VectorXd(const Eigen::VectorXd&)>& systemDynamics,
                          const Eigen::VectorXd& initialState, double timeStep, int numSteps) override;
};

#endif // RK4.h

