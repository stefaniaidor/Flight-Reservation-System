#include "User.cpp"
#include <string>
#include <list>
using namespace std;

class Operator: public User{
public:
    Operator(string numeOperator, string parolaOperator) : User(numeOperator,parolaOperator)
    {
        type = "operator";
    }

};