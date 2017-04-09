//
// Created by Mohsan BUTT on 09/04/2017.
//

#ifndef BEMYDEV_STEP_H
#define BEMYDEV_STEP_H

#include <iostream>

class Step {

public:
    Step(int maxHeure, int numberHeure);
public:
    int getNumberHeure() const;

    void setNumberHeure(int numberHeure);

    int getMaxHeure() const;

    void setMaxHeure(int maxHeure);

private:
    int numberHeure;
    int maxHeure;


};


#endif //BEMYDEV_STEP_H
