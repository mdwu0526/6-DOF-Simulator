// MassSpringDamper.cpp

#include "MassSpringDamper.h"
// #include <iostream>

// Default Constructor
MassSpringDamper::MassSpringDamper() : M(0.0), K(0.0), C(0.0) {}

// Constructor
MassSpringDamper::MassSpringDamper(const double m, const double k, const double c) : M(m), K(k), C(c) {}

void MassSpringDamper::setParameters(const double m, const double k, const double c) {
    M = m;
    K = k;
    C = c;
} // setParameters()

Eigen::VectorXd MassSpringDamper::systemDynamics(const Eigen::VectorXd& prevState) {
    Eigen::VectorXd derivative(prevState.size());
    
    // Position derivative (velocity)
    derivative[0] = prevState[1];

    // Velocity derivative (acceleration)
    derivative[1] = ((-1 * prevState[1] * C) + (-1 * prevState[0] * K)) / M; 

    return derivative; 
} // SystemDynamics