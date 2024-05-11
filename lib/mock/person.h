#ifndef GENPERSON_H
#define GENPERSON_H

#include "libraglobal.h"

#include <string>

namespace libra{

class LIBRA_EXPORT Person
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
    LIBRA_EXPORT friend bool operator==(const Person &left, const Person &right);
    LIBRA_EXPORT friend bool operator!=(const Person &left, const Person &right);

private:
    std::string m_name;
    int m_age;
};

} // namespace libra

#endif // GENPERSON_H
