#include "person.h"

#include "logs/logmanager.h"

/*****************************/
/* Class documentations      */
/*****************************/

/*****************************/
/* Enum documentations       */
/*****************************/

/*****************************/
/* Structure documentations  */
/*****************************/

/*****************************/
/* Signals documentations    */
/*****************************/

/*****************************/
/* Macro definitions         */
/*****************************/

/*****************************/
/* Start namespace           */
/*****************************/

namespace libra{

/*****************************/
/* Constants definitions     */
/*****************************/

/*****************************/
/* Functions implementations */
/*****************************/

Person::Person(const std::string &name, int age)
{
    setName(name);
    setAge(age);

    LIBRA_LOG_DEBUG("Create person");
}

Person::Person()
{
    clear();
}

const std::string& Person::getName() const
{
    return m_name;
}

void Person::setName(const std::string &newName)
{
    m_name = newName;
}

int Person::getAge() const
{
    return m_age;
}

void Person::setAge(int newAge)
{
    m_age = newAge;
}

void Person::clear()
{
    m_name.clear();
    m_age = -1;

    LIBRA_LOG_INFO("Clear person");
}

bool operator==(const Person &left, const Person &right)
{
    return left.m_name == right.m_name
        && left.m_age == right.m_age;
}

bool operator!=(const Person &left, const Person &right)
{
    return !(left == right);
}

/*****************************/
/* End namespace             */
/*****************************/

} // namespace libra

/*****************************/
/* End file                  */
/*****************************/
