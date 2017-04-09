//
// Created by Mohsan BUTT on 09/04/2017.
//

#include "Hackaton.h"

const std::vector<Step *, std::allocator<Step *>> &Hackaton::getSteps() const {
    return steps;
}

void Hackaton::setSteps(const std::vector<Step *, std::allocator<Step *>> &steps) {
    Hackaton::steps = steps;
}

const std::vector<Team *, std::allocator<Team *>> &Hackaton::getTeams() const {
    return teams;
}

void Hackaton::setTeams(const std::vector<Team *, std::allocator<Team *>> &teams) {
    Hackaton::teams = teams;
}

Step *Hackaton::getCurrentStep() const {
    return currentStep;
}

void Hackaton::setCurrentStep(Step *currentStep) {
    Hackaton::currentStep = currentStep;
}

int Hackaton::getStatus() const {
    return status;
}

void Hackaton::setStatus(int status) {
    Hackaton::status = status;
}
