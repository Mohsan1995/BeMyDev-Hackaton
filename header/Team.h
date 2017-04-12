#include <string>
#include <map>

#ifndef BEMYDEV_TEAM_H
#define BEMYDEV_TEAM_H

using namespace std;


class Team {

    int id;
    string name;
    int numberUser;
    double coefficiant;

public:
    int getId() const;

    void setId(int id);

    const string &getName() const;

    void setName(const string &name);

    int getNumberUser() const;

    void setNumberUser(int numberUser);

    double getCoefficiant() const;

    void setCoefficiant();

    Team();

    Team(const string &name, int numberUser);
};


#endif //BEMYDEV_TEAM_H
