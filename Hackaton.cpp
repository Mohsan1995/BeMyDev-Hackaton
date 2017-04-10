#include <iomanip>
#include "Hackaton.h"


Hackaton::Hackaton() {
    this->statusType = HackatonStatus::PENDING;
}

Hackaton::~Hackaton() {

}

Team* Hackaton::addTeam(Team** team) {
    this->teams.push_back(team);
    (*team)->setId(this->teams.size());
    return *team;
}

Step* Hackaton::addStep(Step** step) {
    this->steps.push_back(step);
    return *step;
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

    //Todo: Print result
}

void Hackaton::finishStepWithResults(map<Team **, int> points) {
    if (points.size() != this->teams.size()) return;

    cout <<  "\n\n\nFind de l'étape: " << (*this->currentStep)->getName() << endl;
    cout << "|      Team      |  Point  |" << endl;
    cout << "|----------------|---------|" << endl;
    for (auto const& x : points) {
        Team** t = this->teams[(*x.first)->getId()-1];
        if (t == x.first) {
            Team* team = *t;
            team->setPoint(this->currentStep, x.second);
            cout << "| "
                 << setw(14) << team->getName() << ""
                 << " | "
                 << setw(7) << x.second << ""
                 << " |" << endl;
        }
    }
    cout << "|----------------|---------|\n\n" << endl;
    //Todo: Set next step or stop
}

void Hackaton::finishCurrentStep() {

}
