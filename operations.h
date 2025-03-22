#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "structures.h"

/*
    ====================================
        Bus and Passenger Operations
    ====================================
*/

int getPassengerCount(struct Bus bus);

int isTripFull(struct Bus bus);

struct Bus* getBusFromTripNumber(struct Bus trips[], int n, int tripNumber);

void displayTripList(int nFull);

int displayDropOff(int nTripNo);

int isValidTripNumber(int nTripNumber);

void printDropOffPointFromCode(int code);

/*
	============================
		Passenger Operations	
	============================
*/

void setPassenger(struct Passenger *passenger, int priority, String20 firstName, String20 lastName, int id, int dropOffPoint, int nReserve);

void inputPassenger(int priority, String20 firstName, String20 lastName, int id, int dropOffPoint, int seatNumber, struct Bus *bus, int nReserve);

int inputTripNumber();

void inputPassengerInformation(struct Bus *bus);

void encodePassengerInformation(struct Bus trips[]);

/*
	============================
		PERSONNEL OPERATIONS
	============================
*/

void displayPassengerCount(struct Bus bus);

void viewPassengerCount(struct Bus trips[]);

void viewDropOffCount(struct Bus trips[]);

void viewDropOffCount(struct Bus trips[]);

void viewPassengerInformation(struct Bus trips[]);

void searchPassenger(struct Bus trips[]);

/* 
	======================
		MENU Functions
	======================
*/

int mainMenu();

int passengerMenu(struct Bus trips[]);

int arrowsPersonnelMenu(struct Bus trips[]);


#endif