// Lorentz Force Calculator.cpp : Defines the entry point for the application.
//Caleb Leonard

#include "Lorentz Force Calculator.h"

using namespace std;
#include <iostream>

int main()
{
	float chargeq = 0;
	float factor = 1.0;
	char prefix = 0;

	double EFieldi = 0;
	double EFieldj = 0;
	double EFieldk = 0;

	double InstVeli = 0;
	double InstVelj = 0;
	double InstVelk = 0;

	double MagFieldi = 0;
	double MagFieldj = 0;
	double MagFieldk = 0;

	double ResForcei = 0;
	double ResForcej = 0;
	double ResForcek = 0;

	//cout << "Please enter your point charge value: ";
	//cin >> chargeq;


	cout << "SI Unit Prefixes\n" << "(T) Tera = 10^12\n" << "(G) Giga = 10^9\n" << "(M) Mega = 10^6\n" << "(k) kilo = 10^3\n" << "(b) base = 10^0\n";
	cout << "(c) centi = 10^-2\n" << "(m) milli = 10^-3\n" << "(u) micro = 10^-6\n" << "(n) nano = 10^-9\n" << "(p) pico = 10^-12\n";
	cout << "Please enter your point charge value (in Coulombs) as well as its SI unit prefix: "; 
	cin >> chargeq >> prefix;

	switch (prefix)
	{
	case 'T': 
		factor = 1e12;
		break;
	case 'G':
		factor = 1e9;
		break;
	case 'M':
		factor = 1e6;
		break;
	case 'k':
		factor = 1e3;
		break;
	case 'b':
		factor = 1e0;
		break;
	case 'c':
		factor = 1e-2;
		break;
	case 'm':
		factor = 1e-3;
		break;
	case 'u':
		factor = 1e-6;
		break;
	case 'n':
		factor = 1e-9;
		break;
	case 'p':
		factor = 1e-12;
		break;

	default:
		cout << "Your SI unit prefix selection is incorrect. Please enter an acceptable SI unit prefix: "; 
		break;
	}
	
	cout << "Your given charge and SI unit are: " << chargeq << " " << prefix << "C" << endl;

	cout << "Please enter your electric field vector (in order of i j k): ";
	cin >> EFieldi >> EFieldj >> EFieldk;

	cout << "Please enter your instantaneous velocity vector (in order of i j k): ";
	cin >> InstVeli >> InstVelj >> InstVelk;

	cout << "Please enter your magnetic field vector (in order of i j k): ";
	cin >> MagFieldi >> MagFieldj >> MagFieldk;

	ResForcei = (factor * chargeq) * (EFieldi + ((InstVelj * MagFieldk) - (InstVelk * MagFieldj)));
	ResForcej = (factor * chargeq) * (EFieldj + ((InstVelk * MagFieldi) - (InstVeli * MagFieldk)));
	ResForcek = (factor * chargeq) * (EFieldk + ((InstVeli * MagFieldj) - (InstVelj * MagFieldi)));

	cout << "The resulting force is: " << ResForcei << "i + " << ResForcej << "j + " << ResForcek << "k \n";
	return 0; 
}
