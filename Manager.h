#pragma once
#include <sstream>
using namespace std;

class CardsReader {
private:
	stringstream read_data(string filename);
	void write_data(string filename, string data);
	void print_header();
	void correct_id();
	string a_file = "card_data.csv.csv";
	int max_id;
public:
	void print_all_cards();
	void print_card(int id);
	void delete_card(int id);
	void add_card(string bank_name, string number, string date);
	bool Luhn_algorithm(string number);
};