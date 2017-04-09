//
// Created by Mohsan BUTT on 09/04/2017.
//

#ifndef BEMYDEV_TEAM_H
#define BEMYDEV_TEAM_H


#include <string>
#include <map>
#include "Step.h"

class Team {

    int id;
    std::string name;
    int numberUser;
    double coefficiant;
    std::map<Step, int> note;

public:
    int getId() const;

    void setId(int id);

    const std::string &getName() const;

    void setName(const std::string &name);

    int getNumberUser() const;

    void setNumberUser(int numberUser);

    double getCoefficiant() const;

    void setCoefficiant();

    const std::map<Step, int> &getNote() const;

    void setNote(const std::map<Step, int> &note);

    void addNote(Step step, int note);

    Team();

    Team(int id, const std::string &name);

};


#endif //BEMYDEV_TEAM_H
