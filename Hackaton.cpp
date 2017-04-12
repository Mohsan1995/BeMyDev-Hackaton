#include <map>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include "header/Hackaton.h"


Hackaton::Hackaton() {
    this->statusType = HackatonStatus::PENDING;
}

Hackaton::~Hackaton() {

    cout << "VAL " << endl;

    for (auto const& s : steps) {
        delete *s;
    }
    for (auto const& team : teams) {
        delete *team;
    }
}

void Hackaton::addTeam(Team** team) {
    this->teams.push_back(team);
    (*team)->setId(this->teams.size());
}

void Hackaton::addStep(Step** step) {
    this->steps.push_back(step);
}

Step* Hackaton::getCurrentStep() {
    return *this->currentStep;
}

HackatonStatus Hackaton::getStatusType() {
    return this->statusType;
}

void Hackaton::setCurrentStep(int pos) {
    this->currentStep = steps[pos];
    cout << "L'étape " << (*this->currentStep)->getName() << " commence" << endl;
}

void Hackaton::start() {
    if (this->statusType == HackatonStatus::RUNNING) {
        throw invalid_argument("Hackaton already started");
    } else if (this->statusType == HackatonStatus::FINISHED) {
        throw invalid_argument("Hackaton is finished");
    }

    //Todo: Ensure steps/teams not empty

    this->statusType = HackatonStatus::RUNNING;
    cout << "Le Hackaton commence" << endl;
    this->setCurrentStep(0);
}

void Hackaton::stop() {
    if (this->statusType == HackatonStatus::PENDING) {
        throw invalid_argument("Hackaton is not started");
    } else if (this->statusType == HackatonStatus::FINISHED) {
        throw invalid_argument("Hackaton is already finished");
    }

    this->statusType = HackatonStatus::FINISHED;
    cout << "Le Hackaton finis" << endl;

    map<Team**, int> mapResults;
    for (auto const& s : steps) {
        Step* step = *s;
        if (step->getStatus() == StepStatus::FINISHED2) {
            for (auto const& x : step->getPoints()) {
                int point = x.second;
                if (mapResults[x.first] != NULL) {
                    point += mapResults[x.first];
                }
                mapResults[x.first] = point;
            }
        }
    }
    vector<pair<Team**, int> > totalResult(mapResults.begin(), mapResults.end());
    sort(totalResult.begin(), totalResult.end(), sortSecond<Team**, int>());

    cout << "| Pos |      Team      |  Points  |";
    string separator = "|-----|----------------|----------|";
    for (auto const& s : steps) {
        printCenterString((*s)->getName(), 11);
        cout << "|";
        separator += "-----------|";
    }
    cout << endl << separator << endl;
    int pos=0;

    for (auto const& x : totalResult) {
        Team** t = x.first;
        Team* team = *t;
        cout << "| "
             << setw(3) << ++pos << " | "
             << setw(14) << (*t)->getName() << " | "
             << setw(8) << x.second << " |";

        for (auto const& s : steps) {
            cout << " " << setw(9) << ((map<Team**, int>) (*s)->getPoints())[t] << " |";
        }
        cout << endl;
    }
    cout << separator << endl << endl << endl;
}

void Hackaton::finishStepWithResults(map<Team**, int> points) {
    if (this->statusType == HackatonStatus::PENDING) {
        throw invalid_argument("Hackaton not started");
    }

    if (points.size() != this->teams.size()) {
        throw invalid_argument("Team size not match");
    }

    (*this->currentStep)->setPoints(points);
    vector<pair<Team**, int>> mapcopy(points.begin(), points.end());
    sort(mapcopy.begin(), mapcopy.end(), sortSecond<Team**, int>());

    cout <<  "\n\n\nFind de l'étape: " << (*this->currentStep)->getName() << endl;
    cout << "| Pos |      Team      |  Points  |" << endl;
    cout << "|-----|----------------|----------|" << endl;
    int pos=0;
    for (auto const& x : mapcopy) {
        Team* team = *x.first;
        cout << "| "
             << setw(3) << ++pos << " | "
             << setw(14) << (*x.first)->getName() << " | "
             << setw(8) << x.second << " |" << endl;
    }
    cout << "|-----|----------------|----------|" << endl << endl << endl;
    finishCurrentStep();
}

void Hackaton::finishCurrentStep() {
    (*this->currentStep)->finishStep();
    int stepsSize = steps.size();
    for (int i = 0; i <stepsSize; i++) {
        if (steps[i] == currentStep && i+1 < stepsSize) {
            setCurrentStep(i+1);
            return;
        }
    }
    stop();
}

void Hackaton::printCenterString(string s, int size) {
    int i1 = size - s.size();
    int pos = (int) ((i1) / 2);
    for (int i = 0; i < i1 ; i++) {
        if (i == pos)
            cout << s;
        cout << " ";
    }
}
