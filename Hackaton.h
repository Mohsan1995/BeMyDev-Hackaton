//
// Created by Mohsan BUTT on 09/04/2017.
//

#ifndef BEMYDEV_HACKATON_H
#define BEMYDEV_HACKATON_H


#include <vector>
#include "Step.h"
#include "Team.h"

class Hackaton {

    std::vector<Step*> steps;
    std::vector<Team*> teams;
    Step* currentStep;
    int status;

public:

    Step *getCurrentStep() const;

    void setCurrentStep(Step *currentStep);

    void Hackaton::addSteps(Step &step);

    int getStatus() const;

    void setStatus(int status);
};


#endif //BEMYDEV_HACKATON_H
