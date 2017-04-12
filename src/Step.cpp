#include "../header/Step.h"
#include "../header/Team.h"


Step::Step(string name, int maxHeure, int numberHeure) : name(name), maxHeure(maxHeure), numberHeure(numberHeure) {
    std::cout << "Construcotr step" << std::endl;
    status = StepStatus::PENDING2;
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

const map<Team*, int> &Step::getPoints() const {
    return points;
}

void Step::setPoints(const map<Team*, int> &points) {
    Step::points = points;
}

void Step::startStep() {
    cout << "Step START " + this->getName() << endl;
    status = StepStatus::RUNNING2;
}


void Step::finishStep() {
    cout << "Step END " + this->getName() << endl;
    status = StepStatus::FINISHED2;
}

Step::~Step() {
    for (auto it = points.begin(); it != points.end(); ++it){
        delete it->first;
        points.erase(it);
    }
}
