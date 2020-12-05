#include <string>
using namespace std;

class DataZbor{
public:
    string day;
    string month;
    string year;

    DataZbor(string zi, string luna, string an){
        day = zi;
        month = luna;
        year = an;
    }
};