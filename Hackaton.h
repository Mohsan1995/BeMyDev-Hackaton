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
    const std::vector<Step *, std::allocator<Step *>> &getSteps() const;

    void setSteps(const std::vector<Step *, std::allocator<Step *>> &steps);

    const std::vector<Team *, std::allocator<Team *>> &getTeams() const;

    void setTeams(const std::vector<Team *, std::allocator<Team *>> &teams);

    Step *getCurrentStep() const;

    void setCurrentStep(Step *currentStep);

    int getStatus() const;

    void setStatus(int status);
};


#endif //BEMYDEV_HACKATON_H
