#include "Step.h"


Step::Step(string name, int maxHeure, int numberHeure) : name(name), maxHeure(maxHeure), numberHeure(numberHeure) {
    std::cout << "Construcotr step" << std::endl;
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