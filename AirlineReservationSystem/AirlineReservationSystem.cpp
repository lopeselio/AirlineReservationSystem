// AirlineReservationSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "FlightProvider.h"
#include <string>
#include "Passenger.h"

using namespace std; 

FlightProvider flightProvider = FlightProvider();
std::vector<Flight*> flightdetails = flightProvider.GetFlights();
std::vector<Passenger*> passengers = {};



void displayFlightInfo() {
	std::cout << "Flight Information" << endl;
	std::cout << "Flight Number" << " Departure Location" << " Arrival Location" << " Departure Time" << " Arrival Time" << " Fare" << endl;
	

	for (unsigned i = 0; i < flightdetails.size(); i++) {
		flightdetails.at(i)->print();
	}
}

void bookFlight() {
	cout << "Name?" << endl;
	string name;
	cin >> name;

	Passenger* passenger = new Passenger(name);

	cout << "Flight Number?" << endl;
	int flightNumber;
	cin >> flightNumber;

	for (unsigned i = 0; i < flightdetails.size(); i++) {
		Flight* currentFlight = flightdetails.at(i);
		if (currentFlight->getFlightNumber() == flightNumber) {
			passenger->setFlight(currentFlight);
		}
	}

	cout << "Seat Number?" << endl;
	string seatNumber;
	cin >> seatNumber;

	passenger->setSeatNumber(seatNumber);

	passengers.push_back(passenger); 

}

void displayPassengerInfo() {
	string name; 
	cout << "Passenger Name?" << endl;
	cin >> name; 

	for (unsigned i = 0; i < passengers.size(); i++) {
		if (passengers.at(i)->getName() == name) {
			
			passengers.at(i)->print(); 
	
		}
	}
}

int main()
{
	bool shouldRun = true; 
	while (shouldRun) 
	{
		cout << "1. View Flight Schedule " << endl;
		cout << "2. Reserve a Seat" << endl;
		cout << "3. Display Passenger Info" << endl;
		cout << "4. Display Flight Details" << endl;
		cout << "5. User Ticket Information" << endl;
		cout << "6. Exit Program" << endl;

		int userSelection;
		cin >> userSelection;

		if (userSelection == 1) {
			displayFlightInfo();
		}

		if (userSelection == 2) {
			bookFlight();

		}

		if (userSelection == 3) {
			displayPassengerInfo();
		}

		if (userSelection == 6) {
			shouldRun = false; 
		}
	}

	for (unsigned i = 0; i < flightdetails.size(); i++)
	{
		delete flightdetails.at(i);
		flightdetails.at(i) = nullptr;
	}

}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
