#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <cctype>
#include <sstream>
#include <istream>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

class dataBase{
    private:
    string username;
    string password;
    string type;
    int authentic=0;
    
    public:
    void authenticate(string user,string password,int *x) {
        ifstream fin;
        fin.open("database1.csv");
        if (!fin) {
            cout << "File not found" << endl;
            exit(0);
        }
        
        vector <string> users;
        vector <string> passwords;
        vector <string> type;
        string line;
        string word;
        string a, b, c;

        while (fin.good()) {
            getline(fin, line);
            stringstream ss(line);
            getline(ss, a, ';');
            users.push_back(a);
            getline(ss, b, ';');
            passwords.push_back(b);
            getline(ss, c, ';');
            type.push_back(c);
        }
        fin.close();

        int i = 0, j = 0, ok = 0;
        int n = users.size();
        while(i < n && ok == 0) {
            if(user == users[i])
                if(password == passwords[i])
                {
                    cout<<"Autentificare cu succes\n"
                        <<users[i]<<", bine ai revenit!\n";
                    this->password = password;
                    this->username = user;
                    this->type = type[i];
                    if(type[i] == "User")
                        (*x)=0;
                    else
                        (*x)=1;
                    this->authentic = 1;
                    ok = 1;
                }
                else {
                    cout << "Autentificarea nu a reusit , parola nu este corecta!\n";
                    ok = 1;
                    exit(1);
                }

            else if(password == passwords[i]) {
                if(user == users[i]) {
                    cout << "Autentificare cu succes\n";
                    this->password = password;
                    this->username = user;
                    this->type = type[i];
                    this->authentic = 1;
                    ok = 1;
                }
                else {
                    cout << "Autentificarea nu a reusit, userul nu este corect\n";
                    ok = 1;
                    exit(1);
                }
            }
            i++;
        }
        
        if (ok == 0)
          cout << "Userul nu exista , trebuie creat!\n";
    }

    string addUser(string username, string password, char type[]) {
        ifstream fin;
        fin.open("database1.csv");
        if (!fin) {
            cout << "File not found" << endl;
            exit(0);
        }

        vector <string> users;
        string line;
        string x;

        while (fin.good()) {
            getline(fin, line);
            stringstream ss(line);
            getline(ss,x,';');
            users.push_back(x);
        }
        fin.close();
        int i;
        int n = users.size();
        for(i = 0; i < n; i++) {
            if(users[i] == username) {
                return "Utilizartorul exista deja, incercati alt nume de utilizator sau conectati-va";
                exit(0);
            }
        }

        fstream fout;
        fout.open("database1.csv", ios::app | ios::out);
        if(!fout) 
            cout << "File not found" << endl;
        
        string a, b, c;
        a = username;
        b = password;
        c = type;
        int d = b.size();

        if (d < 6) {
            return "Parola este prea scurta, introduceti o parola mai complexa\n";
            exit(0);
        }
        int ok = 0;
        for(i = 0; i < d; i++) {
            if(strchr("!@#$%^&*():{}><:?",b[i])!=NULL) {
                ok=1;
            }
        }
        if(ok == 0)
            return "Parola nu contine niciun caracter special, introdceti o parola mai complexa\n";
        else {
            fout << "\n" << a << ";";
            fout << b << ";";
            fout << c;      
            return "Userul a fost adaugat cu succes!\n";
        }
        fout.close();                
    }

    void adaugareCursa(string plecare, string destinatie, string ora_plecare, string ora_destinatie) {
        fstream fout;
        fout.open("Program calatorii.csv",ios::app | ios::out);
        if (!fout) {
            cout << "File not found" << endl;
            exit(0);
        }
        fout << "\n" << plecare << ";";
        fout << destinatie << ";";
        fout << ora_plecare << ";";
        fout << ora_destinatie << ";";
        cout << "Cursa a fost adaugata cu succes!\n";
        fout.close();
    }

    void afisare_program_calatorii() {
        fstream fin;
        fin.open("Program calatorii.csv");
        if (!fin) 
            cout << "File not found" << endl;
        
        vector <string> plecare;
        vector <string> destinatie;
        vector <string> ora_plecare;
        vector <string> ora_destinatie;
        string a, b, c, d, line;

        while (fin.good()) {
            getline(fin, line);
            stringstream ss(line);
            getline(ss, a, ';');
            plecare.push_back(a);
            getline(ss, b, ';');
            destinatie.push_back(b);
            getline(ss, c, ';');
            ora_plecare.push_back(c);
            getline(ss, d, ';');
            ora_destinatie.push_back(d);
        }
        fin.close();
        cout << "                   Program\n";
        cout << "Plecare    Destinatie    Ora plecare  Ora sosire\n";
        int n = plecare.size();
        int i;
        for(i = 0; i < n; i++)
        cout << " " << plecare[i] << "   " << destinatie[i] << "     "
            << ora_plecare[i] << "     " << ora_destinatie[i] << endl;
        
    }

    void rezervare_calatorie(string plecare1 , string destinatie1,string ora_plecare1) {
        fstream fin;
        fin.open("Program calatorii.csv");
        if (!fin) {
            cout << "File not found" << endl;
        }
        vector <string> plecare;
        vector <string> destinatie;
        vector <string> ora_plecare;
        vector <string> ora_destinatie;
        string a, b, c, d, line;
        
        while(fin.good()) {
            getline(fin, line);
            stringstream ss(line);
            getline(ss, a, ';');
            plecare.push_back(a);
            getline(ss, b, ';');
            destinatie.push_back(b);
            getline(ss, c, ';');
            ora_plecare.push_back(c);
            getline(ss, d, ';');
            ora_destinatie.push_back(d);
        }
        fin.close();

        int i = 0;
        int ok = 0;
        int n = plecare.size();
        for(i = 0; i < n; i++){
            if (plecare[i] == plecare1 && destinatie[i] == destinatie1) {
                cout << plecare[i] << " " << destinatie1 << " " 
                    << ora_plecare[i] << " " << ora_destinatie[i] << endl;            
                ok++;
            }
        }
        if (ok == 0)
            cout << "Nu va putem face rezervare , cursa nu exista!";
        else {
            fstream fout;
            fout.open("Rezervare calatorie.csv", ios::app | ios::out);
            fout << "\n"<< this->username <<";";
            fout << plecare1 << ";";
            fout << destinatie1 << ";";
            fout << ora_plecare1 << ";";
            cout << "O rezervare pe numele " << this->username << " a fost creata!";
        }
    }

    void stergere_calatorie(string plecare1,string destinatie1,string ora_plecare1){
        fstream fin;
        fin.open("Program calatorii.csv");
        if (!fin) {
            cout << "File not found" << endl;
        }
        vector <string> plecare;
        vector <string> destinatie;
        vector <string> ora_plecare;
        vector <string> ora_destinatie;
        string a, b, c, d, line;

        while (fin.good()) {
            getline(fin, line);
            stringstream ss(line);
            getline(ss, a, ';');
            plecare.push_back(a);
            getline(ss, b, ';');
            destinatie.push_back(b);
            getline(ss, c, ';');
            ora_plecare.push_back(c);
            getline(ss, d, ';');
            ora_destinatie.push_back(d);
        } 
        
        int i = 0;
        int n = plecare.size();
        int ok = 0;
        fstream fout;

        fout.open("Program calatorii.update.csv",ios::app | ios::out);
        for(i = 0; i < n; i++) {
            if(plecare[i] == plecare1 && destinatie[i]== destinatie1 && ora_plecare[i]== ora_plecare1)
                ok++;
            else {
                fout << plecare[i] << ";";
                fout << destinatie[i] << ";";
                fout << ora_plecare[i] << ";";
                fout << ora_destinatie[i] << endl;
           }
        }
        if (ok == 0)
            cout<<"Cursa pe care ati vrut sa o stergeti nu exista!";
        fout.close();
        fin.close();
        remove("Program calatorii.csv");
        rename("Program calatorii.update.csv", "Program calatorii.csv");
    }

    void cautare_calatorie(string plecare1,string destinatie1,int *x) {
        fstream fin;
        fin.open("Program calatorii.csv");
        if (!fin) {
            cout << "File not found" << endl;
        }
        vector <string> plecare;
        vector <string> destinatie;
        vector <string> ora_plecare;
        vector <string> ora_destinatie;
        string a, b, c, d, line;

        while(fin.good()) {
            getline(fin, line);
            stringstream ss(line);
            getline(ss, a, ';');
            plecare.push_back(a);
            getline(ss, b, ';');
            destinatie.push_back(b);
            getline(ss, c, ';');
            ora_plecare.push_back(c);
            getline(ss, d, ';');
            ora_destinatie.push_back(d);
        }
        fin.close();

        int i = 0;
        (*x) = 0;
        int n = plecare.size();
        for(i = 0; i < n; i++){
            if(plecare[i] == plecare1 && destinatie[i] == destinatie1) {
                cout << plecare[i] << " " << destinatie1 << " " << ora_plecare[i] 
                    << " " << ora_destinatie[i] << endl;            
                (*x)++;
            }
        }
        if ((*x) == 0)
        cout << "Nu exista cursa cautata!";
    }
};

int main(){
    int choice;
    cout << "Bine ati venit!\n"; 
    jump: cout << "1.Conectare\n";
    cout << "2.Creare cont\n";
    cout << "3.Afisare program\n";
    cout << "4.Exit\n";
    cout << "Alegeti: ";
    cin >> choice;
    switch(choice) {
        case 1:
        {
            char a[25], b[25];
            cout << "Introduceti numele de utilizator: ";
            fflush(stdin);
            cin.getline(a, 25);
            cout << "\nIntroduceti parola: ";
            fflush(stdin);
            cin.getline(b, 25);
            int x;
            dataBase db;
            db.authenticate(a, b, &x);
            
            switch(x) {
                case 0:
                {
                    meniu_user:
                    cout << "Sunteti conectat cu drepturi de utilizator, puteti verifica sau rezerva curse!\n";
                    cout << "1.Cautati cursa\n";
                    cout << "2.Rezervati cursa\n";
                    cout << "3.Afisare program complet\n";
                    cout << "4.Exit\n";
                    cout << "Alegeti 1/2/3/4!: ";
                    int z;
                    cin >> z;
                    
                    switch(z) {

                        case 1: 
                        {   
                            cout << "Pentru a va cauta o cursa avem nevoie de urmatoarele informatii: \n";
                            dataBase db;
                            char a[25], b[25];
                            int ok;
                            cout << "Plecare: ";
                            fflush(stdin);
                            cin.getline(a, 25);
                            cout << "\nDestinatie: ";
                            fflush(stdin);
                            cin.getline(b, 25);
                            db.cautare_calatorie(a, b, &ok);
                            if(ok != 0) {
                                cout << "Doriti sa rezervati calatoria?\n";
                                cout << "1.Da\n";
                                cout << "2.Nu\n";
                                int j;
                                cout << "Alegeti 1/2: ";
                                cin >> j;
                                switch(j) {
                                    case 1: goto jump1;
                                    case 2: goto meniu_user;
                                }
                            } 
                            else 
                                break;
                            break;
                        }
                        jump1:  case 2: 
                        { 
                            cout << "Pentru a va rezerva calatoria avem nevoie de urmatoarele:\n";
                            char a[25], b[25], c[25];
                            cout << "Plecare: ";
                            fflush(stdin);
                            cin.getline(a, 25);
                            cout << "\nDestinatie: ";
                            fflush(stdin);
                            cin.getline(b, 25);
                            cout << "\nOra plecarii: ";
                            fflush(stdin);
                            cin.getline(c, 25);
                            db.rezervare_calatorie(a, b, c);
                            break;
                        }
                        case 3: 
                        {
                            dataBase db;
                            db.afisare_program_calatorii();
                            break;
                        }
                        case 4: break;
                        break;
                    }

                    break;

                case 1: 
                    {
                        cout << "Sunteti conectat cu drepturi de operator, puteti modifica sau adauga curse!\n";
                        cout << "Doriti meniul de operator sau va conectati ca si user?\n";
                        cout << "1.Operator\n";
                        cout << "2.User\n";
                        cout << "Alegeti 1/2: ";
                        int i;
                        cin >> i;
                        switch(i) {
                            case 1: goto meniu_operator;
                            case 2: goto meniu_user;
                        }
                        meniu_operator: cout << "1.Adauga cursa\n";
                        cout << "2.Stergeti cursa\n";
                        cout << "3.Exit\n";
                        cout << "Alegeti 1/2/3!: ";
                        
                        int z;
                        cin >> z;
                        switch(z) {
                            case 1: 
                            {
                                dataBase db;
                                char a[25], b[25], c[25], d[25];
                                int x;
                                cout << "Introduceti locul de plecare: ";
                                fflush(stdin);
                                cin.getline(a, 25);
                                cout << "\nIntroduceti destinatia: ";
                                fflush(stdin);
                                cin.getline(b, 25);
                                cout << "\nIntroduceti ora de plecare: ";
                                fflush(stdin);
                                cin.getline(c, 25);
                                cout << "\nIntroduceti ora sosire: ";
                                fflush(stdin);
                                cin.getline(d, 25);
                                db.adaugareCursa(a, b, c, d);
                                do {
                                    cout << "Introduceti alta cursa?\n";
                                    cout << "1.Da\n";
                                    cout << "2.Nu\n";
                                    cout << "1/2:";
                                    cin >> x;
                                    switch(x) {
                                        case 1:
                                        {
                                            cout << "Introduceti locul de plecare: ";
                                            fflush(stdin);
                                            cin.getline(a, 25);
                                            cout << "\nIntroduceti destinatia: ";
                                            fflush(stdin);
                                            cin.getline(b, 25);
                                            cout << "\nIntroduceti ora de plecare: ";
                                            fflush(stdin);
                                            cin.getline(c, 25);
                                            cout << "\nIntroduceti ora sosire: ";
                                            fflush(stdin);
                                            cin.getline(d, 25);
                                            db.adaugareCursa(a, b, c, d);
                                        }
                                        case 2: goto meniu_operator;
                                    }
                                } 
                                while(x != 2);
                                break;
                            }
                            case 2:
                            {
                                dataBase db;
                                char a[25], b[25], c[25];
                                cout << "Stergere:Locul de plecare: ";
                                fflush(stdin);
                                cin.getline(a, 25);
                                cout << "\nStergere:Destinatia: ";
                                fflush(stdin);
                                cin.getline(b, 25);
                                cout << "\nStergere:Ora de plecare: ";
                                fflush(stdin);
                                cin.getline(c, 25);
                                db.stergere_calatorie(a, b, c);
                            } 
                            case 3: break;                                
                        }
                    }
                    break; 
                }
            }
            break;
        }
                
        case 2:
        {
            char a[25], b[25], c[25];
            cout << "Introduceti numele de utilizator dorit: ";
            fflush(stdin);
            cin.getline(a, 25);
            jump2: cout << "Introduceti parola: ";
            cin.getline(b, 25);
            cout << "Introduceti tipul de permisiune!: ";
            cin.getline(c, 25);
            dataBase db;
            string response = db.addUser(a,b,c);
            cout << response << "\n";
            if (response == "Parola este prea scurta, introduceti o parola mai complexa\n" ||
                response == "Parola nu contine niciun caracter special, introdceti o parola mai complexa\n") {
                goto jump2;
            }
            goto jump;    
        }
        break;
        case 3:
        {
            dataBase db;
            db.afisare_program_calatorii();
            break;
        }
                
        case 4: break;
    }

    return 0;
}