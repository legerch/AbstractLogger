#ifndef GENPERSON_H
#define GENPERSON_H

#include "libraryglobal.h"

#include <string>

namespace gen{

class LIBRARYNAME_EXPORT Person
{

public:
    explicit Person(const std::string &name, int age);
    explicit Person();

public:
    const std::string& getName() const;
    void setName(const std::string &newName);

    int getAge() const;
    void setAge(int newAge);

    void clear();

public:
    LIBRARYNAME_EXPORT friend bool operator==(const Person &left, const Person &right);
    LIBRARYNAME_EXPORT friend bool operator!=(const Person &left, const Person &right);

private:
    std::string m_name;
    int m_age;
};

} // gen

#endif // GENPERSON_H
