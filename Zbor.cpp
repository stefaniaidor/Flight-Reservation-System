#include <string>
#include "DataZbor.cpp"

using namespace std;

class Zbor{
public:
    string plecare;
    string destinatie;
    string data_zbor;
    int numar_locuri;
    int numar_identificare;

    Zbor(string departure, string arrival, int seats, DataZbor *dataZbor, int id) {
        plecare = departure;
        destinatie = arrival;
        numar_locuri = seats;
        data_zbor = dataZbor->day + "-" + dataZbor->month + "-" + dataZbor->year;
        numar_identificare = id;
    }
};
