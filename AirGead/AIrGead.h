//Larry reppert
//6/5/2022
//Professor Mill
//CS-210
//Project 2
#pragma once
#ifndef AIRGEAD_H
#define AIRGEAD_H

#include <string>
using namespace std;
//I've created my class defining my varibles that i will use with setters and getters
class AirGead {
public:
	void SetInitInvestAmount(int investAmounts);
	void SetMonthlyDeposit(int monthlyDeposits);
	void SetAnnualInterest(int annualInterests);
	void SetNumberOfYears(int numberOfYears);
	void SetMonthlyCalculations(double monthlyCalculations);
	void SetMonthlyInterests(double monthlyInterests);
	void Print();
	void inputFormData();
	void initCalculation();
	void initDepositCalculation();
	string charString(size_t n, char c);
	int GetInitInvestAmount() const;
	int GetMonthlyDeposit() const;
	int GetAnnualInterest() const;
	int GetNumberOfYears() const;
	double GetMonthlyInterests() const;
	double GetMonthlyCalculations() const;
	// Private varibles
private:
	    int investAmount;
		int monthlyDeposit;
		int annualInterest;
		int numberOfYear;
		double monthlyInterest;
		double monthlyCalculation;
};
#endif