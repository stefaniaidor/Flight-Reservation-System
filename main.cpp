#include<iostream>
#include "Auxfunctions.h"
using namespace std;

int main(){

    adaugare_operator("Operator","test");
    adaugare_operator("OperatorTest2","ParolaOperator2");

    adaugare_zbor("Barcelona","Roma",50,"25","05","2021",1111);
    adaugare_zbor("Bucuresti","Singapore",70,"10","07","2021",1112);

    LOOP:show_start_menu();

    while(openChoice != 3){
        if (openChoice == 1) {

            cout<<"1. Operator"<<"\n";
            cout<<"2. Utilizator"<<"\n";
            cout<<"3. Inapoi"<<"\n";
            cin>>loginChoice;
            if(loginChoice==3)
                goto LOOP;

            cout << "Username: ";
            cin >> loginUser;
            cout << "\n";
            cout << "Password: ";
            cin >> loginPassword;
            cout << "\n";

            if (loginChoice==1){
                logareOp = logareOperator(loginUser,loginPassword);
                logged_type = logareOp.operator*()->type;
                cout<<"Bine ati venit " + logareOp.operator*()->username + "!"<<"\n";

                show_operator_menu();

                while(operator_menu_choice < 5){
                    if(operator_menu_choice == 1)
                    {
                        afisare_zboruri_operator();
                        show_operator_menu();
                    }
                    else if(operator_menu_choice == 2)
                    {
                        cout<<"Introduceti detaliile noului zbor: "<<"\n";
                        cout<<"Oras plecare: "<<"\n";
                        cin>>cityDep;
                        cout<<"Oras sosire: "<<"\n";
                        cin>>cityArr;
                        cout<<"Numar de locuri: "<<"\n";
                        cin>>seats;
                        cout<<"Zi: "<<"\n";
                        cin>>day;
                        cout<<"Luna: "<<"\n";
                        cin>>month;
                        cout<<"An: "<<"\n";
                        cin>>year;
                        cout<<"Id: "<<"\n";
                        cin>>id_add;
                        adaugare_zbor(cityDep,cityArr,seats,day,month,year,id_add);
                        show_operator_menu();
                    }
                    else if(operator_menu_choice == 3)
                    {
                        cout<<"Introduceti id-ul zborului pe care doriti sa il stergeti: "<<"\n";
                        cin>>id_delete;
                        stergere_zbor(id_delete);
                        show_operator_menu();
                    }
                    else if(operator_menu_choice == 4)
                    {
                        goto LOOP;
                    }
                    else{
                        cout<<"Optiune invalida, alegeti alta optiune: ";
                        cin>>operator_menu_choice;
                    }
                }
            }
            else if(loginChoice==2) {
                logareUser = logareUtilizator(loginUser, loginPassword);
                logged_type = logareUser.operator*()->type;
                cout << "Bine ati venit " + logareUser.operator*()->username + "!" << "\n";
                show_user_menu();

                while (user_menu_choice < 4)
                {
                    if(user_menu_choice == 1)
                    {
                        cout<<"Introduceti punctul de plecare: ";
                        cin>>cityDep;
                        cout<<"\n";
                        cout<<"Introduceti punctul de sosire: ";
                        cin>>cityArr;
                        cout<<"\n";
                        flightsListTBD = cautare_zbor(cityDep,cityArr);

                        if(flightsListTBD.size() == 0)
                            cout<<"Niciun rezultat gasit pentru cautare";
                        else {
                            afisare_zboruri_utilizator(flightsListTBD);
                            flightsListTBD.clear();
                        }
                        show_user_menu();
                    }
                    else if(user_menu_choice == 2)
                    {
                        cout<<"Introduceti id-ul zborului dorit: ";
                        cin>>id_search;
                        cout<<"\n";
                        seats_av = locuri_disponibile(id_search);
                        if(seats_av>0){
                            cout<<"Pentru zborul dorit mai sunt "<<seats_av<<" locuri disponibile"<<endl;
                            cout<<"Introduceti numarul de locuri: "<<endl;
                            cin>>seats_res;
                            if(seats_av-seats_res<0){
                                cout<<"Ati selectat un numar indisponibil de locuri."<<endl;
                            }
                            else {
                                cout << "Rezervare efectuata cu succes. Va multumim!" << endl;
                                actualizare_locuri_zbor(id_search,seats_res);
                            }
                        }
                        else
                            cout<<"Pentru zborul selectat nu mai exista locuri disponibile";

                        show_user_menu();
                    }
                    else if(user_menu_choice == 3)
                        goto LOOP;
                }
            }


        } else if (openChoice == 2) {
            cout << "Username: ";
            cin >> loginUser;
            cout << "\n";
            cout << "Password: ";
            cin >> loginPassword;
            cout << "\n";

            try {
                inregistrare(loginUser, loginPassword);
                if(is_validEmail(loginUser))
                    cout<<"Inregistrare cu succes!";
                else
                    throw 'e';
            }
            catch (char e) {
                cout << "Nu s-a putut inregistra utilizatorul, adresa de mail invalida.";
            }

            goto LOOP;
        }
    }

}