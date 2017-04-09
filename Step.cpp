//
// Created by Mohsan BUTT on 09/04/2017.
//

#include "Step.h"

Step::Step(int maxHeure, int numberHeure) : maxHeure(maxHeure), numberHeure(numberHeure) {
    std::cout << "Construcotr step" << std::count;
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

Step::~Step() {
    std::cout << "Destructeur step" << std::endl;
}
