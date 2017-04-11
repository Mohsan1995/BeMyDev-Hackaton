#include <iostream>
#include "Hackaton.h"


int main() {
    cout << "Hello, World!" << endl;
    Hackaton* hackaton = new Hackaton();

    Step* step1 = new Step("Step1", 4, 1);
    hackaton->addStep(&step1);

    Step* step2 = new Step("Step2", 6, 2);
    hackaton->addStep(&step2);

    Team* team1 = new Team("Team1", 4);
    hackaton->addTeam(&team1);

    Team* team2 = new Team("Team2", 7);
    hackaton->addTeam(&team2);

    Team* team3 = new Team("Team3", 5);
    hackaton->addTeam(&team3);

    Team* team4 = new Team("Team4", 3);
    hackaton->addTeam(&team4);

    hackaton->start();

    map<Team**, int> points;

    points[&team1] = 24;
    points[&team2] = 19;
    points[&team3] = 48;
    points[&team4] = 15;
    hackaton->finishStepWithResults(points);


    points[&team1] = 12;
    points[&team2] = 8;
    points[&team3] = 47;
    points[&team4] = 34;
    hackaton->finishStepWithResults(points);
    return 0;
}