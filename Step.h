#include <iostream>
#include <vector>
#include "Team.h"

#ifndef BEMYDEV_STEP_H
#define BEMYDEV_STEP_H

using namespace std;

enum StepStatus {
    PENDING2, RUNNING2, FINISHED2
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
