#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

using namespace std;


class EmptyText: public logic_error{

public:
    EmptyText(string msg): logic_error("Error Empty :" + msg){}

};

class InvalidDate : public logic_error
{
public :
    InvalidDate(string msg): logic_error(msg){}
};

class InvalidDay: public InvalidDate
{
public :
    InvalidDay(): InvalidDate("Invalid Day, pick a number from 1 to 31"){}

};

class InvalidYear: public InvalidDate
{
public :
    InvalidYear(): InvalidDate("User has to be over 17"){}

};

class DuplicateUser: public logic_error{

public:
    DuplicateUser(string username): logic_error(username+ " already exists" ){}

};
class PasswordMismatch: public logic_error{

public:
    PasswordMismatch(): logic_error("Passwords don’t match, try again" ){}

};





#endif // EXCEPTIONS_H
