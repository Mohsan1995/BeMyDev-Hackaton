#include "header/Team.h"


int Team::getId() const {
    return id;
}

void Team::setId(int id) {
    Team::id = id;
}

const string &Team::getName() const {
    return name;
}

void Team::setName(const string &name) {
    Team::name = name;
}

int Team::getNumberUser() const {
    return numberUser;
}

void Team::setNumberUser(int numberUser) {
    Team::numberUser = numberUser;
    this->setCoefficiant();
}

double Team::getCoefficiant() const {
    return coefficiant;
}

void Team::setCoefficiant() {
    this->coefficiant = 0.75 + (this->numberUser * 0.05);
}

Team::Team() {
    this->numberUser = 1;
    this->setCoefficiant();
}

Team::Team(const string &name, int numberUser) : name(name), numberUser(numberUser) {
    this->setCoefficiant();
}