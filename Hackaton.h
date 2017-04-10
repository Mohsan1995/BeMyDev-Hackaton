#include <vector>
#include <stdexcept>
#include "Team.h"
#include "Step.h"

#ifndef BEMYDEV_HACKATON_H
#define BEMYDEV_HACKATON_H

using namespace std;

enum HackatonStatus {
    PENDING, RUNNING, FINISHED
};

class Hackaton {

private:
    vector<Team**> teams;
    vector<Step**> steps;
    Step** currentStep;
    HackatonStatus statusType;

public:
    Hackaton();
    ~Hackaton();

    void addTeam(Team** team);
    void addStep(Step** step);

    Step* getCurrentStep();
    HackatonStatus getStatusType();

    void start();
    void stop();

    void finishCurrentStep();

    void finishStepWithResults(map<Team**, int> points);

private:
    void setCurrentStep(int pos);
};


#endif //BEMYDEV_HACKATON_H
