#include <iostream>
#include "Hackaton.h"


int main() {
    cout << "Hello, World!" << endl;
    Hackaton* hackaton = new Hackaton();

    Step* step1 = new Step("Step1", 4, 1);
    step1 = hackaton->addStep(&step1);

    Team* team1 = new Team("Team1", 4);
    cout << &team1 << endl;
    team1 = hackaton->addTeam(&team1);
    cout << team1->getId() << endl;
    cout << &team1 << endl;

    hackaton->start();

    map<Team**, int> points;
    points[&team1] = 15;

    hackaton->finishStepWithResults(points);
    return 0;
}