#include <iostream>

#ifndef BEMYDEV_STEP_H
#define BEMYDEV_STEP_H

using namespace std;


class Step {

public:
    Step(string name, int maxHeure, int numberHeure);
public:
    const string &getName() const;

    void setName(const string &name);

    int getNumberHeure() const;

    void setNumberHeure(int numberHeure);

    int getMaxHeure() const;

    void setMaxHeure(int maxHeure);

private:
    string name;
    int numberHeure;
    int maxHeure;
};


#endif //BEMYDEV_STEP_H
