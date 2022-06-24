//Larry reppert
//6/5/2022
//Professor Mill
//CS-210
//Project 2
#include <iostream>
#include <string>
#include <iomanip> 
#include <math.h>
using namespace std;


#include "AirGead.h"
#include <format>




//Here are the Set values with unique names.
void AirGead::SetInitInvestAmount(int investAmounts) {
	investAmount = investAmounts;
}
void  AirGead::SetMonthlyDeposit(int monthlyDeposits) {
	monthlyDeposit = monthlyDeposits;
}
void  AirGead::SetAnnualInterest(int annualInterests) {
	annualInterest = annualInterests;
}
void AirGead::SetNumberOfYears(int numberOfYears) {
	numberOfYear = numberOfYears;
}
void AirGead::SetMonthlyInterests(double monthlyInterests) {
	monthlyInterest = monthlyInterests;
}
void AirGead::SetMonthlyCalculations(double monthlyCalculations) {
	monthlyCalculation = monthlyCalculations;
}
//Print statement to get the very first image displayed.
void  AirGead::Print() {
	string x;
	cout << charString(34, '*') << endl;
	cout << charString(11, '*') << " Data Input " << charString(11, '*') << endl;
	cout << "Intial Investment Amount: " << endl;
	cout << "Monthly Deposit: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of Years: " << endl;
	system("pause");
	
	
}
// This is where I will retrieve my varibles and catch bab inputs. 
void  AirGead::inputFormData() {
	string amount;
	string year;
	string deposit;
	string interest;
	cout << charString(34, '*') << endl;
	cout << charString(11, '*') << " Data Input " << charString(11, '*') << endl;
	// This will repeat until a positive value is entered
	for (;;) {
		cout << "Intial Investment Amount: $";
		getline(cin, amount);
		int inputAmount = stoi(amount);
		if ((int) inputAmount > 0 ) { 
			break;
		}else {
			cout << "Enter a valid positive number" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
		}

	}// This will repeat until a positive value is entered
	for (;;) {
	cout << "Monthly Deposit: $" ;
	getline(cin, deposit);
	int inputDeposit = stoi(deposit);
	if((int) inputDeposit > 0 ){
		break;
	}
	else {
		cout << "Enter a valid positive number" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	}

	}// This will repeat until a positive value is entered
	for (;;) {
	cout << "Annual Interest: %";
	getline(cin, interest);
	int inputInterest = stoi(interest);
	if ((int)inputInterest > 0) {
		break;
}
	else {
		cout << "Enter a valid positive number" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		}

	}// This will repeat until a positive value is entered
	for (;;) {

	cout << "Number of Years: ";
	getline(cin, year);
	int inputYear = stoi(year);
	if ((int)inputYear > 0) {
	break;
		}
	else {
		cout << "Enter a valid positive number" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		}

	}
	system("pause");
	int amounts = stoi(amount);
	int deposits = stoi(deposit);
	int interests = stoi(interest);
	int years = stoi(year);
	SetInitInvestAmount(amounts);
	SetMonthlyDeposit(deposits);
	SetAnnualInterest(interests);
	SetNumberOfYears(years);
}
// I calculate the interest first by year..
void AirGead::initCalculation() {
	int i;
	double interest = GetAnnualInterest();
	double amount = GetInitInvestAmount();
	double years = GetNumberOfYears();
	interest = interest / 100;

	cout << endl << endl;
	cout << "     Balance and Interest Without Additional Monthly Deposits     " <<endl;
	cout << charString(66, '=') << endl;
	cout << "  Year" << charString(12, ' ') << "Year End Balance" << charString(8, ' ') << "Year End Earned Interest" << endl;
	cout << charString(66, '-') << endl;
	for (i = 1; i <= years; i++)
	{
		// amount * interests + intial amount no deposit in this calculation
		double calculation = (amount * interest) + amount;
		double yearlyInterest = calculation - amount;

		cout << charString(5, ' ') << i << charString(24, ' ') << fixed << setprecision(2) << calculation << charString(28, ' ') << setprecision(2) << yearlyInterest <<endl;
		cout << endl;
		amount = calculation;
	}
	cout << endl;
	cout << endl;
	cout << endl;




}// I calculate the interest first by month adding it together to give a compounded interest value.
void AirGead::initDepositCalculation() {
	double interest = GetAnnualInterest();
	double amount = GetInitInvestAmount();
	double years = GetNumberOfYears();
	double deposit = GetMonthlyDeposit();
	double months = 12;
	double monthlyInter = 0.00;
	double amounts = 0.00;
	cout << endl << endl;
	int i;
	int j;
	// The following allows me to format based on right justified that way my values will line up when displayed.
	// The format is better for larger and growing values. 
	cout << "     Balance and Interest Without Additional Monthly Deposits     " << endl;
	cout << charString(66, '=') << endl;
	cout << setw (6); cout << right << "Year";
	cout << setw (28); cout << right << "Year End Balance";
	cout << setw (32); cout << right << "Year End Earned Interest" << endl;
	cout << charString(66, '-') << endl;
	// this outer loop will give the yearly total.
	for (i = 1; i <= years; i++)
	{
		amount;
		amounts;
		// This is the inner loop used to calculate monthly interest and add them together giving a compounded yearly total.
		for (j = 1; j <= months; j++) {
			//cout << interests << endl;

			double monthlyInterests = amount * ((interest / 100) / months);
			//cout << fixed << setprecision(5) << monthlyInterests << endl;
			double monthlyCalculations = amount + monthlyInterests + deposit;
			//cout << fixed << setprecision(5) << monthlyCalculations << endl;
			amount = monthlyCalculations;
			
			//cout << fixed << setprecision(3) << amounts << endl;
			monthlyInter = monthlyInterests + monthlyInter;
			//cout << fixed << setprecision(3) << monthlyInter << endl;
		}
		//cout << monthlyInter << endl;
		//I set the values prior to retrieving them but not in the inner loop so it won't reset 12 times
		SetMonthlyCalculations(amount);
		SetMonthlyInterests(monthlyInter);
		double calculation = GetMonthlyCalculations();
		double yearlyInterest = GetMonthlyInterests();
		//This format style is better than the other if i encounter larger values
		cout << setw(6); cout << right << i;
		cout << setw(28); cout << right << calculation;
		cout << setw(32); cout << right << yearlyInterest << endl;
		//cout << format("%-20s %-20s %-8s\n") % i % calculation % yearlyInterest;
		//cout << charString(5, ' ') << i << charString(22, ' ') << fixed << setprecision(2) << calculation << charString(28, ' ') << setprecision(2) << yearlyInterest << endl;
		cout << endl;
	}
	cout << endl;
	cout << endl;
	cout << endl;
}
// This privide a consistent border i used this code in last project and imported it over
string AirGead::charString(size_t n, char c) {

	int i;

	int size = (int)n;
	string outPut = "";
	for (i = 0; i < size; i++)
	{
		outPut = outPut + c;
	}

	return outPut;
}
//Here are the Getters
int AirGead::GetInitInvestAmount() const {
	return investAmount;
}
int AirGead::GetMonthlyDeposit() const {
	return monthlyDeposit;
}
int AirGead::GetAnnualInterest() const {
	return annualInterest;
}
int AirGead::GetNumberOfYears() const {
	return numberOfYear;
}
double AirGead::GetMonthlyInterests() const {
	return monthlyInterest;
}
double AirGead::GetMonthlyCalculations() const {
	return monthlyCalculation;
}


