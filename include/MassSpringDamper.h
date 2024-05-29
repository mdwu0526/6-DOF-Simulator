// MassSpringDamper.h

#ifndef MASSSPRINGDAMPER_H
#define MASSSPRINGDAMPER_H

#include <Eigen/Dense>
#include <vector>
#include "System.h"

class MassSpringDamper : public System {
public:
    MassSpringDamper();

    MassSpringDamper(const double m, const double k, const double c);

    void setParameters(const double m, const double k, const double c);

    Eigen::VectorXd systemDynamics(const Eigen::VectorXd& prevState);

private:
    std::vector<Eigen::VectorXd> output;
    double M;
    double K;
    double C;
};

#endif // MASSSPRINGDAMPER_H