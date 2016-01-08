/*	Title: make_inserts.cpp
*	Author: Michael Garod
*	Date: 11/20/16
*	Description: Reads a csv and uses the first entry of every line to create
*		a sql insert statement.
*	Input: The CSV used is generated from de_csv_generator.cpp
*	Output: A SQL file of inserts based off the CSV
*	Usage: No arguments are accepted.
*	
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

int main(int argc, char** argv){
	if (argc != 1){
		cout << argv[0] << " does not accept arguments\n";
		return 1;
	}

	ifstream input("FINAL_de_central_places.csv");
	string fileline;
	ofstream output("INSERT-de_cpt.sql");

	// Keep track of all inserts ever made to avoid duplicates
	unordered_map<string,string> mymap;

	// Discard the header line (titles of the columns)
	getline(input, fileline);

	while(getline(input, fileline)){
		stringstream eachline(fileline);
		string place;

		// From eachline extract the place (everything until the first ';')
		getline(eachline, place, ';');
		
		// If place is not in our map, insert into map and create the SQL
		if ( mymap.find(place) == mymap.end() ){
			mymap.insert({place,""});
			output << "INSERT INTO de_cpt (de_place) VALUES (\'" << place;
			output << "\');" << endl;
		}
		else{ // Do nothing
			cout << "Duplicate: " << place << endl;
		}
	}
	
	return 0;
}