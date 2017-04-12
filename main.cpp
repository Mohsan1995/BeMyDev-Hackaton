#include <iostream>
#include "header/Hackaton.h"


int main() {
    Hackaton* hackaton = new Hackaton();

    while (hackaton->getStatusType() == HackatonStatus::PENDING) {
        cout << endl << endl << "Menu:" << endl
             << "1: Ajouter Equipe" << endl
             << "2: Ajouter Etape" << endl
             << "3: Démarer Hackaton" << endl << endl
             << "->";

        char input;
        cin >> input;
        switch (input) {
            case '1': {
                string teamName;
                int number;
                cout << "Nom d'équipe: ";
                cin >> teamName;

                cout << "Nombre de membres: ";
                cin >> number;

                Team* team = new Team(teamName, number);
                hackaton->addTeam(*team);
                cout << "Ajout de l'équipe " << teamName << " numéro " << team->getId() << " de " << number << " membres" << endl;
                break;
            }

            case '2': {
                string stepName;
                int maxTime;
                cout << "Nom d'étape: ";
                cin >> stepName;

                cout << "Temps max: ";
                cin >> maxTime;

                Step* step = new Step(stepName, maxTime, 1);
                hackaton->addStep(*step);
                cout << "Ajout de l'étape " << stepName << " de " << maxTime << " heures " << endl;
                break;
            }

            case '3': {
                hackaton->start();
                break;
            }
        }
    };


    while (hackaton->getStatusType() == HackatonStatus::RUNNING) {
        cout << endl << endl << "Menu:" << endl
             << "1: Terminer l'étape actuel" << endl
             << "2: Finir le hackaton" << endl << endl
             << "->";

        char input;
        cin >> input;
        switch (input) {
            case '1': {
                map<Team*, int> points;
                cout << "Attribution des points." << endl;
                for (auto & t : hackaton->getTeams()) {
                    Team* team = t;
                    cout << "Point pour l'équipe " << t->getName() << " :";

                    int point;
                    cin >> point;
                    cout << team << endl;
                    cout << &team << endl;
                    points[team] = point / team->getCoefficiant();
                }

                hackaton->finishStepWithResults(points);
                break;
            }

            case '2': {
                hackaton->stop();
                break;
            }
        }
    }

    delete hackaton;

    return 0;
}