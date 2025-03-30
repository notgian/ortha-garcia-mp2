/*********************************************************************************************************
This is to certify that this project is our own work, based on our combined personal efforts in studying and applying the concepts
learned. We have constructed the functions and their respective algorithms and corresponding code by ourselves. The
program was run, tested, and debugged by our own efforts. We further certify that we have not copied in part or whole or
otherwise plagiarized the work of other students and/or persons.
<Theon Schuyler S. Garcia>, DLSU ID# <12409537>, <Gian Lorenzo C. Ortha>, DLSU ID# <12414697>
*********************************************************************************************************/
#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "structures.h"

int stringToInt(String20 str);

/*
    ====================================
        Bus and Passenger Operations
    ====================================
*/

int getPassengerCount(struct Bus bus);

int isTripFull(struct Bus bus);

struct Bus* getBusFromTripNumber(struct Bus trips[], int n, int tripNumber);

void displayTripList(struct Bus trips[]);

struct Bus *getInputTripNumber(struct Bus trips[]);

int isValidTripNumber(int nTripNumber);

void printDropOffPointFromCode(int code);

void clearScreen();

void pauseAndContinueOnReturn();

/*
	============================
		Passenger Operations	
	============================
*/

void setPassenger(struct Passenger *passenger, int priority, String20 firstName, String20 lastName, int id, int dropOffPoint, int nReserve);

void inputPassenger(int priority, String20 firstName, String20 lastName, int id, int dropOffPoint, int seatNumber, struct Bus *bus, int nReserve);

int searchPassengerId(struct Bus trips[], int searchId);

void encodePassengerInformation(struct Bus trips[]);

void getBusFull(struct Bus trips[], int *nFullA, int *nFullB);

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

int scanPassengerInformation(FILE *fp, int *nTripNo, int *nEmbarkPoint, String20 lastName, String20 firstName, int *nId, int *nPriority, int *nDropOff);

void loadPassengerFromFile(struct Bus trips[]);

/* 
	======================
		MENU Functions
	======================
*/

int mainMenu();

int passengerMenu(struct Bus trips[], int *nFullA, int *nFullB);

int arrowsPersonnelMenu(struct Bus trips[], int *nFullA, int *nFullB);


#endif