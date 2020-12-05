#include <string>
using namespace std;

class User {
public:

    string username;
    string password;
    string type;

    User(string name, string pass){
        username = name;
        password = pass;
        type = "utilizator";
    }
};

