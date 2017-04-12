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

template <typename T1, typename T2>
struct sortSecond {
    typedef pair<T1, T2> type;
    bool operator ()(type const& a, type const& b) const {
        return a.second > b.second;
    }
};

class Hackaton {

private:
    vector<Team*> teams;
    vector<Step*> steps;
    Step** currentStep;
    HackatonStatus statusType;

public:
    Hackaton();
    ~Hackaton();

    void addTeam(Team& team);
    void addStep(Step& step);

    Step* getCurrentStep();
    HackatonStatus getStatusType();

    const vector<Team *> &getTeams() const;

    void start();
    void stop();

    void finishCurrentStep();

    void finishStepWithResults(map<Team*, int> points);

private:
    void setCurrentStep(int pos);

    void printCenterString(string s, int size);
};


#endif //BEMYDEV_HACKATON_H
