#include "Team.h"


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
    double coef = 0.05;

    for (int i = this->numberUser; i >= 0 ; --i) {
        coef+= 0.05;
    }
    this->coefficiant = coef;
}

const map<Step**, int> &Team::getNotesMaps() const {
    return points;
}

int Team::getPoints() {
    int total = 0;
    for (auto const& x : this->points) {
        total += x.second;
    }
    return total;
}

int Team::getNote(Step** step) {
    return this->points[step];
}

void Team::setPoint(Step** step, int point) {
    this->points[step] = point;
}

Team::Team() {
    this->numberUser = 1;
    this->coefficiant = 0.05;
}

Team::Team(const string &name, int numberUser) : name(name), numberUser(numberUser) {}