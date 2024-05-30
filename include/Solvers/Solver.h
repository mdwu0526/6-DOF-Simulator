// Solver.h
#ifndef SOLVER_H
#define SOLVER_H

#include <Eigen/Dense>
#include <functional>

class Solver {
public:
    virtual Eigen::VectorXd solve(const std::function<Eigen::VectorXd(const Eigen::VectorXd&)>& SystemDynamics,
                                  const Eigen::VectorXd& iniitalState, double timeStep, int numSteps) = 0;
};

#endif // SOLVER_H