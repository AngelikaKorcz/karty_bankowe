#include <iostream>
#include "Manager.h"

using namespace std;

int main() {


    CardsReader a;
    while (true)
    {
        int wybor, id;
        string nazwa, data, numer;

        cout << "Wybierz opcje: " << endl;
        cout << "1.Pokaz wszystkie karty." << endl;
        cout << "2.Pokaz wybrana karte." << endl;
        cout << "3.Dodaj karte." << endl;
        cout << "4.Usun karte." << endl;
        cout << "5.Wyjdz z programu." << endl;
        cin >> wybor;
        switch (wybor) {
        case 1:
            cout << endl;
            a.print_all_cards();
            cout << endl;
            break;
        case 2:
            cout << endl;
            cout << "Podaj id karty: ";
            cin >> id;
            a.print_card(id);
            cout << endl;
            break;
        case 3:
            cout << endl;
            cout << "Nazwa banku: "; cin >> nazwa;
            cout << "Numer karty: "; cin >> numer;
            cout << "Data wygasniecia karty" << endl; cin >> data;
            if (a.Luhn_algorithm(numer) == true)
            {
                a.add_card(nazwa, numer, data);
                cout << "Dodana karta: " << nazwa << "," << numer << "," << data << endl;
            }
            else
            {
                cout << "Podany numer karty jest bledny! " << endl;
            }
            
            break;
        case 4:
            cout << "Podaj id karty: ";
            cin >> id;
            a.delete_card(id);
            cout << "Usunieto karte o indeksie: " << id << endl;
            break;
        case 5:
            cout << "Opuszczanie programu..." << endl;
            return 0;
        default:
            cout << "Nie mozna wykonac operacji. Podaj inny numer." << endl;
            break;

       
        }
    }

}