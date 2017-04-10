#include <iostream>
#include <vector>


#ifndef BEMYDEV_STEP_H
#define BEMYDEV_STEP_H

using namespace std;

#include "Team.h"

enum StepStatus {
    PENDING, RUNNING, FINISHED
};

class Step {

public:
    Step(string name, int maxHeure, int numberHeure);

    const string &getName() const;

    void setName(const string &name);

    int getNumberHeure() const;

    void setNumberHeure(int numberHeure);

    int getMaxHeure() const;

    void setMaxHeure(int maxHeure);

    StepStatus getStatus() const;

    void setStatus(StepStatus status);

    const vector<Team, allocator<Team>> &getClassment() const;

    void setClassment(const vector<Team, allocator<Team>> &classment);

    void startStep();

    void finishStep();


private:
    string name;
    int numberHeure;
    int maxHeure;
    StepStatus status;
    vector<Team> classment;

};


#endif //BEMYDEV_STEP_H
