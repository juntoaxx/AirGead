//Larry reppert
//6/5/2022
//Professor Mill
//CS-210
//Project 2
#include <iostream>
#include <string>
using namespace std;

#include "AirGead.h"


int main() {
	// I created my object that i will get and set values for.
	AirGead myAirGead;
	myAirGead.Print();
	myAirGead.inputFormData();
	myAirGead.initCalculation();
	myAirGead.initDepositCalculation();
	//This is the selection screen to either quit or restart. 
	string sel;
	cout << "Type the Number 1 to enter new data into the calculator or all other selections to quit" << endl;
	getline(cin , sel);
	int checker = stoi(sel);
	if (checker == 1) {
		myAirGead.inputFormData();
		myAirGead.initCalculation();
		myAirGead.initDepositCalculation();

	}else{

		exit(3);
		return 0;
	}
}
