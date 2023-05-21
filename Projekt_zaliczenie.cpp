// Projekt_zaliczenie.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Manager.h"

using namespace std;

template <class Container>
void split_string(const string& str, Container& cont, char delim = ' ')
{
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delim)) {
        cont.push_back(token);
    }
}

string left(const string s, const int w) {
    stringstream ss, spaces;
    int padding = w - s.size();
    for (int i = 0; i < padding; ++i)
        spaces << " ";
    ss << s << spaces.str();
    return ss.str();
}

stringstream CardsReader::read_data(string filename) {
    ifstream ReadFile(filename);
    stringstream buffer;
    buffer << ReadFile.rdbuf();
    ReadFile.close();
    return buffer;
}

void CardsReader::write_data(string filename, string data) {
    ofstream WriteCardsFile(filename);
    WriteCardsFile << data;
    WriteCardsFile.close();
}


void CardsReader::print_header() {
    cout << left("ID:", 5);
    cout << left("Bank name:", 20);
    cout << left("Card number:", 30);
    cout << left("Date:", 10);
    cout << endl;
}

void CardsReader::print_all_cards() {
    string line;
    stringstream a = read_data(a_file);
    print_header();
    while (getline(a, line)) {
        vector <string> cards;
        split_string(line, cards, ',');
        max_id = stoi(cards[0]);
        cout << left(cards[0], 5);
        cout << left(cards[1], 20);
        cout << left(cards[2], 30);
        cout << left(cards[3], 10);
        cout << endl;
    }
}

void CardsReader::print_card(int id) {
    string line;
    stringstream a = read_data(a_file);
    while (getline(a, line)) {
        vector <string> cards;
        split_string(line, cards, ',');

        if (cards[0] == to_string(id)) {
            print_header();
            cout << left(cards[0], 5);
            cout << left(cards[1], 20);
            cout << left(cards[2], 30);
            cout << left(cards[3], 10);
            cout << endl;

        }
    }
}


void CardsReader::add_card(string bank_name, string number, string date) {
    string temp;
    int id = max_id + 1;
    temp = to_string(id) + ',' + bank_name + ',' + number + ',' + date;
    string a_temp = read_data(a_file).str();
    a_temp = a_temp + "\n" + temp;
    write_data(a_file, a_temp);
}

bool CardsReader::Luhn_algorithm(string number)
{
    int sum = 0;
    for (int i = number.length() - 1; i >= 0; i--)
    {
        int temp = number[i] - '0';
        if (i % 2 == 0)
        {
            temp *= 2;
            if (temp > 9)
                temp -= 9;
        }
        sum += temp;
    }
    return (sum % 10 == 0);
}

void CardsReader::delete_card(int id) {
    string line;
    stringstream a = read_data(a_file);
    string temp;
    while (getline(a, line)) {
        vector <string> cards;
        split_string(line, cards, ',');
        if (cards[0] != to_string(id))
            temp = temp + line + "\n";

    }
    write_data(a_file, temp);
    correct_id();
}

void CardsReader::correct_id() {
    string line;
    stringstream a = read_data(a_file);
    int j = 1;
    string temp;

    while (getline(a, line)) {
        vector <string> cards;
        split_string(line, cards, ',');
        temp = temp + to_string(j) + "," + cards[1] + "," + cards[2] + "," + cards[3] + "\n";
        j++;
    }
    temp.erase(temp.length() - 1);
    write_data(a_file, temp);
}


