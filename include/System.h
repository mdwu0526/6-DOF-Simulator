// System.h

#ifndef SYSTEM_H
#define SYSTEM_H

#include <functional>
#include <Eigen/Dense>
#include "Solver.h"

class System {
public:
    System();

    void setSolver(Solver* solver);

    void setSystemDynamics(std::function<Eigen::VectorXd(const Eigen::VectorXd&)> systemDynamics);

    Eigen::VectorXd solve(const Eigen::VectorXd& initialState, double timeStep, int numSteps);

private:
    Solver* _solver;
    std::function<Eigen::VectorXd(const Eigen::VectorXd&)> _systemDynamics;

};

#endif // SYSTEM_H