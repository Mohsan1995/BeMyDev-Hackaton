//
// Created by Mohsan BUTT on 09/04/2017.
//

#include "Team.h"

int Team::getId() const {
    return id;
}

void Team::setId(int id) {
    Team::id = id;
}

const std::string &Team::getName() const {
    return name;
}

void Team::setName(const std::string &name) {
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

const std::map<Step, int> &Team::getNote() const {
    return note;
}

void Team::setNote(const std::map<Step, int> &note) {
    Team::note = note;
}

void Team::addNote(Step step, int note) {
    this->note[step] = note;
}

Team::Team() {
    this->numberUser = 1;
    this->coefficiant = 0.05;
}

Team::Team(int id, const std::string &name) : id(id), name(name) {}


