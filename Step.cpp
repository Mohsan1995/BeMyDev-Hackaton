#include "Step.h"


Step::Step(string name, int maxHeure, int numberHeure) : name(name), maxHeure(maxHeure), numberHeure(numberHeure) {
    std::cout << "Construcotr step" << std::endl;
    status = StepStatus::PENDING;
}

const string &Step::getName() const {
    return name;
}

void Step::setName(const string &name) {
    Step::name = name;
}

int Step::getNumberHeure() const {
    return numberHeure;
}

void Step::setNumberHeure(int numberHeure) {
    Step::numberHeure = numberHeure;
}

int Step::getMaxHeure() const {
    return maxHeure;
}

void Step::setMaxHeure(int maxHeure) {
    Step::maxHeure = maxHeure;
}

StepStatus Step::getStatus() const {
    return status;
}

void Step::setStatus(StepStatus status) {
    Step::status = status;
}

const vector<Team, allocator<Team>> &Step::getClassment() const {
    return classment;
}

void Step::setClassment(const vector<Team, allocator<Team>> &classment) {
    Step::classment = classment;
}

void Step::startStep() {
    cout << "Step START " + this->getName() << endl;
    status = StepStatus::RUNNING;
}


void Step::finishStep() {
    cout << "Step END " + this->getName() << endl;
    status = StepStatus::FINISHED;


}
