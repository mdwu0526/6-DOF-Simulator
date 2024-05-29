// System.cpp

#include "System.h"

System::System() : _solver(nullptr) {}

void System::setSolver(Solver* solver) {_solver = solver;} // setSolver()

void System::setSystemDynamics(std::function<Eigen::VectorXd(const Eigen::VectorXd&)> systemDynamics){
    _systemDynamics = systemDynamics;
} // setSystemDynamics()

Eigen::VectorXd System::solve(const Eigen::VectorXd& initialState, double timeStep, int numSteps){
    // Error-handling
    if (!_solver || !_systemDynamics) {
        return Eigen::VectorXd::Zero(initialState.size());
    } // if
    
    return _solver->solve(_systemDynamics, initialState, timeStep, numSteps);
} // solve()