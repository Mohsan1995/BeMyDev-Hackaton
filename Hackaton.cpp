
#include "Step.h"
#include "Hackaton.h"

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

void Hackaton::addSteps(Step &step) {

    std::vector::size_type size = this->steps.size();
    steps.resize(size+1);
    steps[size+1] = &step;

}
