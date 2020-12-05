#include "Lists.h"
#include<iomanip>
#include "AuxVariables.h"

#ifndef PROIECTPOO_AUXFUNCTIONS_H
#define PROIECTPOO_AUXFUNCTIONS_H

void adaugare_operator(string nume_operator, string parola_operator){
    operatorsList.push_back(new Operator(nume_operator, parola_operator));
}

void adaugare_utilizator(string nume_utilizator, string parola_utilizator){
    usersList.push_back(new User(nume_utilizator,parola_utilizator));
}

void adaugare_zbor(string plecare, string sosire, int nr_locuri, string zi, string luna, string an, int id){
    flightsList.push_back(new Zbor(plecare, sosire, nr_locuri, new DataZbor(zi, luna, an), id));
}

void stergere_zbor(int id){
    for(flight_it=flightsList.begin(); flight_it!=flightsList.end(); flight_it++){
        if(flight_it.operator*()->numar_identificare != id)
            flightsListTBD.push_back((*flight_it));
    }
    flightsList.swap(flightsListTBD);
    flightsListTBD.clear();
}


void afisare_zboruri_operator(){
    cout<<"TABEL ZBORURI"<<"\n\n";
    cout<<setw(8)<<"PLECARI"<<setw(15)<<"DESTINATII"<<setw(20)<<"NUMAR LOCURI"<<setw(12)<<"DATA"<<setw(10)<<"ID"<<endl;
    for(flight_it=flightsList.begin(); flight_it!=flightsList.end(); flight_it++){
        cout<<setw(8)<<(*flight_it)->plecare<<setw(14)<<(*flight_it)->destinatie<<
            setw(15)<<(*flight_it)->numar_locuri<<setw(18)<<(*flight_it)->data_zbor<<
            setw(10)<<(*flight_it)->numar_identificare<<endl;
    }
}

void afisare_zboruri_utilizator(list<Zbor*> lista){
    cout<<"REZULTATELE CAUTARII"<<"\n\n";
    cout<<setw(8)<<"PLECARE"<<setw(15)<<"DESTINATIE"<<setw(20)<<"NUMAR LOCURI"<<setw(12)<<"DATA"<<setw(10)<<"ID"<<endl;
    for(flight_it=lista.begin(); flight_it!=lista.end(); flight_it++){
        cout<<setw(8)<<(*flight_it)->plecare<<setw(14)<<(*flight_it)->destinatie<<
            setw(15)<<(*flight_it)->numar_locuri<<setw(18)<<(*flight_it)->data_zbor<<
            setw(10)<<(*flight_it)->numar_identificare<<endl;
    }
}

list<Zbor*> cautare_zbor(string dep, string arr){
    for(flight_it=flightsList.begin(); flight_it!=flightsList.end(); flight_it++){
        if(flight_it.operator*()->plecare == dep && flight_it.operator*()->destinatie == arr)
            flightsListTBD.push_back((*flight_it));
    }
    return flightsListTBD;
}

int locuri_disponibile(int id){
    for(flight_it=flightsList.begin(); flight_it!=flightsList.end(); flight_it++){
        if(flight_it.operator*()->numar_identificare == id)
            return flight_it.operator*()->numar_locuri;
    }
}

void actualizare_locuri_zbor(int id, int nr){
    for(flight_it=flightsList.begin(); flight_it!=flightsList.end(); flight_it++){
        if(flight_it.operator*()->numar_identificare == id)
            flight_it.operator*()->numar_locuri-=nr;
    }
}

_List_iterator<Operator *> logareOperator(string name, string pass){
    for(operator_it=operatorsList.begin();operator_it != operatorsList.end();operator_it++)
    {
        if((*operator_it)->username == name)
        {
            if((*operator_it)->password == pass)
            {
                return operator_it;
            }
            else
            {
                cout << "Parola gresita";
                break;
            }
        }
    }
}

_List_iterator<User *> logareUtilizator(string name, string pass){
    for(user_it=usersList.begin();user_it != usersList.end();user_it++)
    {
        if((*user_it)->username == name)
        {
            if((*user_it)->password == pass)
            {
                return user_it;
            }
            else
            {
                cout << "Parola gresita";
                break;
            }
        }
    }
}

void inregistrare(string username, string passwd){
    adaugare_utilizator(username,passwd);
}

void show_start_menu(){
    cout<<"Alegeti o optiune: "<<"\n";
    cout<<"1. Logare"<<"\n";
    cout<<"2. Inregistrare"<<"\n";
    cout<<"3. Iesire"<<"\n";
    cin>>openChoice;
}

void show_operator_menu(){
    cout<<"Alegeti o optiune: "<<"\n";
    cout<<"1. Vizualizare zboruri"<<"\n";
    cout<<"2. Adaugare zbor"<<"\n";
    cout<<"3. Stergere zbor"<<"\n";
    cout<<"4. Iesire"<<"\n";
    cin>>operator_menu_choice;
}

void show_user_menu(){
    cout<<"Alegeti o optiune: "<<"\n";
    cout<<"1. Cautare zbor"<<"\n";
    cout<<"2. Rezervare zbor"<<"\n";
    cout<<"3. Iesire"<<"\n";
    cin>>user_menu_choice;
}

bool isChar(char c)
{
    return ((c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z'));
}

// Function to check the character
// is an digit or not
bool isDigit(const char c)
{
    return (c >= '0' && c <= '9');
}


bool is_validEmail(string email)
{
    // Check the first character
    // is an alphabet or not
    if (!isChar(email[0])) {

        // If it's not an alphabet
        // email id is not valid
        return 0;
    }
    // Variable to store position
    // of At and Dot
    int At = -1, Dot = -1;

    // Traverse over the email id
    // string to find position of
    // Dot and At
    for (int i = 0;
         i < email.length(); i++) {

        // If the character is '@'
        if (email[i] == '@') {

            At = i;
        }

            // If character is '.'
        else if (email[i] == '.') {

            Dot = i;
        }
    }

    // If At or Dot is not present
    if (At == -1 || Dot == -1)
        return 0;

    // If Dot is present before At
    if (At > Dot)
        return 0;

    // If Dot is present at the end
    return !(Dot >= (email.length() - 1));
}
#endif //PROIECTPOO_AUXFUNCTIONS_H
