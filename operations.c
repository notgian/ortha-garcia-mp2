/*********************************************************************************************************
This is to certify that this project is our own work, based on our combined personal efforts in studying and applying the concepts
learned. We have constructed the functions and their respective algorithms and corresponding code by ourselves. The
program was run, tested, and debugged by our own efforts. We further certify that we have not copied in part or whole or
otherwise plagiarized the work of other students and/or persons.
<Theon Schuyler S. Garcia>, DLSU ID# <12409537>, <Gian Lorenzo C. Ortha>, DLSU ID# <12414697>
*********************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "operations.h"

/* 
	=============================
		Misc Helper Functions
	=============================
*/

/* stringToInt: Takes a string and returns its equivalent in integer form
   @param str - string to convert to int
   @return int - the string in int form
*/ 
int stringToInt(String20 str)
{
    int i;
    int n = 0;
    int length = (int) strlen(str);
    for (i=0; i < length; i++)
    {
        char ch = str[i];
        int digit = ch - '0';
        n += digit * pow(10, (length-i-1));
    }

    return n;
}

/*
	====================================
   		Bus and Passenger Operations
	====================================

NOTE FOR DROP OFF POINTS (SAME NUMBERS WILL BE USED FOR EMBARKATION POINTS):
- 10010 - Mamplasan Toll Exit
- 10020 - Phase 5, San Jose Vilage
- 10030 - Laguna Blvd. Guard House(across Paseo PHOENIX Gasoline Station)
- 10040 - Milagros Del Rosario Building - East Canopy

- 20010 - Petron Gasoline Station along Gil Puyat Avenue
- 20020 - College of St. Benilde (CSB) along Taft Avenue
- 20030 - Gate 4: Gokongwei Gate
- 20040 - Gate 2: North Gate (HSSH)
- 20050 - Gate 1: South Gate (LS Building Entrance)

*/

/* getPassengerCount: Takes a bus and returns the amount of passengers onboard
   @param bus - bus structure  
   @return int - the number of passengers onboard
*/ 

int 
getPassengerCount(struct Bus bus)
{
    int i;
    int count = 0;
    for (i=0; i<16; i++)
    {
        count += bus.passengers[i].onboard;
    }
    return count;
}

/* isTripFull: Takes a bus and returns 1 if the trip is full, 0 if not
   @param bus - bus structure  
   @return int - returns 1 if the trip is full, and 0 otherwise
*/ 
int 
isTripFull(struct Bus bus)
{
    int count = getPassengerCount(bus);
    if (count >=16) return 1;
    else return 0;
}

/* getBusFromTripNumber: Returns the pointer of a particular bus with a corresponding trip number.
   @param trips      - list of bus trips
   @param n          - number of total trips; only used for the loop
   @param tripNumber - trip number of the desired bus
   @return Bus*      - pointer to the bus with the corresponding trip number. Pointer is set to NULL if no bus is found.
*/ 
struct Bus* getBusFromTripNumber(struct Bus trips[], int n, int tripNumber)
{
	int i;
	struct Bus *returnBus = NULL; 
	for (i=0; i<n; i++)
	{
		if (trips[i].tripNumber == tripNumber)
		{
			returnBus = &trips[i];
			i = n;
		}
	}
	return returnBus;
}

/* displayTripList: displays the list of bus trips.
   @param nFull - determines if the special trips should be shown
   @return void
*/ 
void 
displayTripList(struct Bus trips[])
{
	struct Bus *currentManilaTrip = &trips[0];
	struct Bus *currentLagunaTrip = &trips[10];

	printf("\n|===============List of Trips===============|\n");
	printf("|====MANILA-LAGUNA====|====LAGUNA-MANILA====|\n");
	
	while (currentManilaTrip != NULL || currentLagunaTrip != NULL)
	{
		if (currentManilaTrip != NULL)
		{
			printf("|        AE-%3d       |", currentManilaTrip->tripNumber);
			currentManilaTrip = currentManilaTrip->next;
		}
		else
			printf("|                     |");

		if (currentLagunaTrip != NULL)
		{
			printf("        AE-%3d       |\n", currentLagunaTrip->tripNumber);
			currentLagunaTrip = currentLagunaTrip->next;
		}
		else
			printf("                     |\n");
			
	}
	printf("|===========================================|\n");
}

/* getInputTripNumber: takes user input for a certain bus' trip number and returns a pointer to that bus 
   @param trips - list of bus trips
   @return Bus* - pointer to the bus with the specified trip number
*/ 
struct Bus 
*getInputTripNumber(struct Bus trips[])
{
	int nTripNumber;
	struct Bus *bus;

	int validInput = 0;
	while (!validInput)
	{
		displayTripList(trips);
		printf("Please input a trip number from the list above.\n");
		
		scanf(" %d", &nTripNumber);

		if (!isValidTripNumber(nTripNumber))
			printf("\nInvalid trip number. Please enter a valid trip number.\n\n");
		else
		{
			bus = getBusFromTripNumber(trips, 22, nTripNumber);
			if (bus->dispatchable == 0)
			{
				printf("Bus selected is not currently dispatchable. Please enter a trip number listed.\n\n");	
			}
			else
				validInput = 1;
		}
		
		
	}

	return bus;
}

/* isValidTripNumber: Takes in an integer and determines if it a valid trip number in the context of the program
   @param nTripNumber - the number to check. 
   @return int - returns 1 if the trip number is valid, otherwise returns 0
*/
int 
isValidTripNumber(int nTripNumber)
{
	return (nTripNumber >= 101 && nTripNumber <= 110) || (nTripNumber >= 150 && nTripNumber <= 161);
}

/* printDropOffPointFromCode: Takes in a drop off point code and prints out the string version of the drop off point
   @param code - the drop off code
   @return void
*/
void 
printDropOffPointFromCode(int code)
{
	if (code == 10010) 
		printf("%-50s", "Mamplasan Toll Exit");
	else if (code == 10020) 
		printf("%-50s", "Phase 5, San Jose Vilage");
	else if (code == 10030) 
		printf("%-50s", "Laguna Blvd. Guard House");
	else if (code == 10040) 
		printf("%-50s", "Milagros Del Rosario Building - East Canopy");
	else if (code == 20010) 
		printf("%-50s", "Petron Gasoline Station along Gil Puyat Avenue");
	else if (code == 20020) 
		printf("%-50s", "College of St. Benilde (CSB) along Taft Avenue");
	else if (code == 20030) 
		printf("%-50s", "Gate 4: Gokongwei Gate");
	else if (code == 20040) 
		printf("%-50s", "Gate 2: North Gate (HSSH)");
	else if (code == 20050) 
		printf("%-50s", "Gate 1: South Gate (LS Building Entrance)");
}

void 
getDropOffPointFromCode(int code, String50 name)
{
	if (code == 10010) 
		strcpy(name, "Mamplasan Toll Exit");
	else if (code == 10020) 
		strcpy(name, "Phase 5, San Jose Vilage");
	else if (code == 10030) 
		strcpy(name, "Laguna Blvd. Guard House");
	else if (code == 10040) 
		strcpy(name, "Milagros Del Rosario Building - East Canopy");
	else if (code == 20010) 
		strcpy(name, "Petron Gasoline Station along Gil Puyat Avenue");
	else if (code == 20020) 
		strcpy(name, "College of St. Benilde (CSB) along Taft Avenue");
	else if (code == 20030) 
		strcpy(name, "Gate 4: Gokongwei Gate");
	else if (code == 20040) 
		strcpy(name, "Gate 2: North Gate (HSSH)");
	else if (code == 20050) 
		strcpy(name, "Gate 1: South Gate (LS Building Entrance)");
}

int
getDropOffPointFromString(String50 string)
{
	if (strcmp(string, "Mamplasan Toll Exit") == 0)
		return 10010;
	else if (strcmp(string, "Phase 5, San Jose Vilage") == 0)
		return 10020;
	else if (strcmp(string, "Laguna Blvd. Guard House") == 0)
		return 10030;
	else if (strcmp(string, "Milagros Del Rosario Building - East Canopy") == 0)
		return 10040;

	else if (strcmp(string, "Petron Gasoline Station along Gil Puyat Avenue") == 0)
		return 20010;
	else if (strcmp(string, "College of St. Benilde (CSB) along Taft Avenue") == 0)
		return 20020;
	else if (strcmp(string, "Gate 4: Gokongwei Gate") == 0)
		return 20030;
	else if (strcmp(string, "Gate 2: North Gate (HSSH)") == 0)
		return 20040;
	else if (strcmp(string, "Gate 1: South Gate (LS Building Entrance)") == 0)
		return 20050;
	
	return -1;
}

/* dropOffInRoute: Returns a value based on whether the specified drop off is in the specified route
   @param dropOff - the specified drop-off point to search for
   @param route   - the route to search the drop-off point for
   @return int    - returns 1 if the drop-off point point is present in the route, 0 otherwise
*/
int
dropOffInRoute(int dropOff, int route)
{
	// if (route == 100)

	return 0;

}

/* clearScreen: Clears the screen with ANSI regex
   @return void
*/
void clearScreen()
{
	printf("\e[1;1H\e[2J"); // Regex clear function
}

/* pauseAndContinueOnReturn: Pauses the program and waits for the user to input any character and press enter
   @return void
*/
void pauseAndContinueOnReturn()
{
	printf("\nType any character and press return to continue\n");
	scanf(" \n");
	getchar();
}

/*
	============================
		Passenger Operations	
	============================
*/

/* setPassenger: takes a pointer to a passenger and sets the corresponding properties
   @param passenger    - pointer to the passenger
   @param priority 	   - priority number of the passenger
   @param firstName    - first name of the passenger
   @param lastName     - last name of the passenger
   @param id           - id number of the passenger
   @param dropOffPoint - drop off point of the passenger, represented through an int
   @return void
*/ 
void
setPassenger(struct Passenger *passenger, int priority, String20 firstName, String20 lastName, int id, int dropOffPoint, int nReserve)
{
	passenger->priority = priority;
	strcpy(passenger->firstName, firstName);
	strcpy(passenger->lastName, lastName);
	passenger->id = id;
	passenger->dropOff = dropOffPoint;
	passenger->onboard = 1;
	passenger->reserved = nReserve;
}

/* inputPassenger: takes a passenger's properties and attempts to put them into a bus.
   @param priority 	   - priority number of the passenger
   @param firstName    - first name of the passenger
   @param lastName     - last name of the passenger
   @param id           - id number of the passenger
   @param dropOffPoint - drop off point of the passenger, represented through an int
   @param seatNumber   - seat number (index) to board the passenger onto. (-1) indicates automatic seat assignment.
   @param bus          - pointer to the bus the passenger will be boarded onto
   @return void
*/ 
void 
inputPassenger(int priority, String20 firstName, String20 lastName, int id, int dropOffPoint, int seatNumber, struct Bus *bus, int nReserve)
{
	struct Passenger dummyPassenger;
	dummyPassenger = createEmptyPassenger();
	dummyPassenger.id = -1;

	struct Passenger dummyPassengerB = dummyPassenger;
	dummyPassengerB.priority = 0;
	
	struct Passenger *displacedPassenger = &dummyPassenger;
	struct Passenger *tempPassenger = &dummyPassengerB;

	if (bus == NULL)
		printf("Sorry, %s %s, there are no more remaining bus trips that can accomodate you", firstName, lastName);

	else
	{
		// Check if the drop-off point is valid
		int validDropOff = 0;
		int lastValidRoutePoint = 0;
		int i;
		for (int k = 0; k < MAX_ROUTE_LENGTH; k++)
		{
			if (dropOffPoint == bus->route[k])
			{
				validDropOff = 1;
				k = MAX_ROUTE_LENGTH;
			}
			if (bus->route[k] != 0)
				lastValidRoutePoint = bus->route[k];
		}
		if (!validDropOff)
		{
			dropOffPoint = lastValidRoutePoint;
			printf("Provided drop-off point for trip AE-%d is not part of the route! Defaulting to final drop-off point at ", bus->tripNumber);
			printDropOffPointFromCode(lastValidRoutePoint);
			printf("\n");
		}

		if (isTripFull(*bus))
		{
			int seatTaken;

			if (nReserve && seatNumber != -1) // Passenger is reserving and seat is specified
			{
				if (bus->passengers[seatNumber-1].priority > priority)
				{
					tempPassenger = &(bus->passengers[seatNumber-1]);
					seatTaken = seatNumber;
				}
			}
			else if (!nReserve || (nReserve && seatNumber == -1)) // Current Passenger is not reserved or passenger is reserved but seat is not specified
			{
				// Check for the lowest priority passenger who is not reserved
				for (i = MAX_PASSENGERS - 1; i >= 0; i--)
				{
					if ( (bus->passengers[i].reserved != 1 && (bus->passengers[i].priority > priority || nReserve) ) &&
						(bus->passengers[i].priority > tempPassenger->priority))
					{
						tempPassenger = &(bus->passengers[i]);
						seatTaken = i+1;
					}
				}
			}			
			
			// Checking temppassenger to see if a passenger can be displaced
			if (tempPassenger->id != -1) // Current passenger is boarded successfully
			{
				printf("Passenger %s %s will be displaced in favor of passenger %s %s", tempPassenger->firstName, tempPassenger->lastName, firstName, lastName);
				
				*displacedPassenger = *tempPassenger;
				setPassenger(tempPassenger, priority, firstName, lastName, id, dropOffPoint, nReserve);

				printf("\nPassenger Input Successfully!\n");
				printf("   Name        : %s, %s\n", lastName, firstName);
				printf("   ID Number   : %d\n", id);
				printf("   Priority    : %d\n", priority);
				printf("   Seat Number : %d\n", seatTaken);
				printf("   Trip Number : AE-%d\n", bus->tripNumber);
			}

			// Checks for displaced passenger
			if (displacedPassenger->id == -1) // No passengers could be displaced
			{
				if (nReserve && seatNumber != -1) // Happens if the seat chosen is already occupied by a reserved passenger with a higher priority 
					printf("Cannot board! The seat %d is already being occupied by a higher-priority passenger who has reserved that seat. Please try again and pick a different seat. Aborting the boarding of %s %s\n", seatNumber, firstName, lastName);

				else // Board on next trip
				{
					printf("There are no more available seats for passenger %s %s in bus AE-%d. Attempting to board them on the next trip.\n", firstName, lastName, bus->tripNumber);
					inputPassenger(priority, 
						firstName, 
						lastName, 
						id, 
						dropOffPoint, 
						-1, 
						bus->next, 
						nReserve);
				}
			}
			else if (displacedPassenger->reserved) // Happens if a higher priority passenger reserves the seat of an already reserved passenger
			{ // Board onto the same trip
				printf("The seat of passenger %s %s has been reserved by a higher priority passenger and they will be moved to a normal seat within the same bus.\n", displacedPassenger->firstName, displacedPassenger->lastName);
					inputPassenger(displacedPassenger->priority, 
						displacedPassenger->firstName, 
						displacedPassenger->lastName, 
						displacedPassenger->id, 
						displacedPassenger->dropOff, 
						-1, 
						bus, 
						displacedPassenger->reserved);
			}
			else // Passenger displaced is not reserved
			{
				printf("The seat of Passenger %s %s has been taken by a higher priority passenger. Running checks for a lower priority passenger...	\n", displacedPassenger->firstName, displacedPassenger->lastName		);
				inputPassenger(displacedPassenger->priority, 
					displacedPassenger->firstName, 
					displacedPassenger->lastName, 
					displacedPassenger->id, 
					displacedPassenger->dropOff, 
					-1, 
					bus			, 
					displacedPassenger->reserved);
			}
		}
		else // If bus is not full
		{
			if (seatNumber == -1) // assign seat autoomatically
			{
				for (i = 0; i < MAX_PASSENGERS; i++)
				{
					if (bus->passengers[i].onboard == 0)
					{
						setPassenger(&(bus->passengers[i]),
									priority,
									firstName,
									lastName,
									id,
									dropOffPoint,
									nReserve);

						printf("\nPassenger Input Successfully!\n");
						printf("   Name        : %s, %s\n", lastName, firstName);
						printf("   ID Number   : %d\n", id);
						printf("   Priority    : %d\n", priority);
						printf("   Seat Number : %d\n", i + 1);
						printf("   Trip Number : AE-%d\n", bus->tripNumber);
						i = MAX_PASSENGERS;
					}
				}
				
			}

			else if (bus->passengers[seatNumber-1].onboard == 0) // Seat specified is empty anw
			{
				setPassenger(&(bus->passengers[seatNumber-1]),
							priority,
							firstName,
							lastName,
							id,
							dropOffPoint,
							nReserve);

				printf("\nPassenger Input Successfully!\n");
				printf("   Name        : %s, %s\n", lastName, firstName);
				printf("   ID Number   : %d\n", id);
				printf("   Priority    : %d\n", priority);
				printf("   Seat Number : %d\n", seatNumber);
				printf("   Trip Number : AE-%d\n", bus->tripNumber);
			}
			else // current passenger is reserving, and there is a passenger on the seat
			{
				if (bus->passengers[seatNumber-1].priority > priority)
				{
					printf("Moving a %s %s to another seat to accomodate %s %s.\n", bus->passengers[seatNumber-1].firstName, bus->passengers[seatNumber-1].lastName, firstName, lastName);

					printf("\nPassenger Input Successfully!\n");
					printf("   Name        : %s, %s\n", lastName, firstName);
					printf("   ID Number   : %d\n", id);
					printf("   Priority    : %d\n", priority);
					printf("   Seat Number : %d\n", seatNumber);
					printf("   Trip Number : AE-%d\n", bus->tripNumber);

					*displacedPassenger = bus->passengers[seatNumber-1];

					setPassenger(&(bus->passengers[seatNumber-1]), 
								priority, 
								firstName, 
								lastName, 
								id, 
								dropOffPoint, 
								nReserve);
					
					// Board displaced passenger onto the same bus	
					inputPassenger(displacedPassenger->priority, 
									displacedPassenger->firstName, 
									displacedPassenger->lastName, 
									displacedPassenger->id, 
									displacedPassenger->dropOff, 
									-1, 
									bus, 
									displacedPassenger->reserved);
				}
				else
				{
					printf("Higher or equal priority passenger is already occupying that seat. Please pick a different seat and try again.\n");
					bus->nReserveCount--;
				}
			}
		}
	}
}

/* searchPassengerId: Takes the list of trips and searches for a specified id among the passengers in all trips
   @param trips - list of all the bus trips
   @return int  - returns 1 if a passenger with the specified id is found, 0 otherwise 
*/
int
searchPassengerId(struct Bus trips[], int searchId)
{
	int i, j;
	int found = 0;
	for (i=0; i<MAX_TRIPS; i++)
	{
		for (j=0; j<MAX_PASSENGERS; j++)
		{
			if (trips[i].passengers[j].id == searchId)
			{
				found = 1;
				i = MAX_TRIPS;
				j = MAX_PASSENGERS;
			}
		}
	}

	return found;	
}

/* encodePassengerInformation: Combines the functions inputTripNumber and inputPassengerInformation and creates the logic for 
   @param trips - array of all the busses
   @return void
*/
void 
encodePassengerInformation(struct Bus trips[])
{
	clearScreen();
	printf("What trip will you be boarding? (Please input the 3-digit number of the trip excluding the \"AE\")\n\n");
	int tripNo = getInputTripNumber(trips)->tripNumber;

	clearScreen();
	struct Bus *bus = getBusFromTripNumber(trips, MAX_TRIPS, tripNo);
	
	printf("==========Enter Details Below==========\n");
	int priority, id, dropOff, nReserve;
	String20 firstName, lastName;

	int validInput = 0;
	int seat = -1;

	printf("ID Number:\n");
	while(!validInput)
	{
		scanf(" %d", &id);
		if (!(id >= 10000000 && id <= 99999999))		    
		{
			printf("\nInvalid ID number! Please input a valid 8-digit id number\n");
		}
		else if (searchPassengerId(trips, id))
		{
			printf("\nPassenger with ID number %d is already boarded on a different trip. Please input a different passenger id.\n", id);
		}
		else
			validInput = 1;
	}

	printf("First Name (NOTE: DO NOT INCLUDE ANY SPACES):\n");
	scanf(" %s", firstName);
	
	printf("Last Name: (NOTE: DO NOT INCLUDE ANY SPACES):\n");
	scanf(" %s", lastName);
	
	validInput = 0;
	while(!validInput)
	{
		printf("Priority Number: ");
		scanf(" %d", &priority);

		if (!(priority >= 1 && priority <= 6))
		{
			printf("\nInvalid Priority number! Please input a priority number from 1 to 6\n");
		}
		else
			validInput = 1;
	}
	
	validInput = 0;
	while(!validInput && bus->nReserveCount < 4)
	{
		printf("Do you want to reserve?\n");
		printf("1 - Yes\n");
		printf("0 - No\n");
		scanf(" %d", &nReserve);
		if(nReserve < 0 || nReserve > 1)
		{
			printf("\nInvalid input! Please input 1 for yes or 0 for no.\n");
		}
		else if (nReserve == 1)
		{
			int maxSeat = 13 + (getPassengerCount(*bus) >= 13) * 3;

			while( (seat < 0) || (seat > maxSeat) )
			{
				printf("Please input a seat number from 1 to %d:\n", maxSeat);
				scanf(" %d", &seat);
			}

			validInput = 1;
			bus->nReserveCount += 1;
		}
		else
			validInput = 1;
	}
	// int dropOffOptions = displayDropOff(bus->tripNumber); -- old 

	int d;
	int nDropOffOptions = 0;
	

	validInput = 0;
	while(!validInput)
	{
		printf("Drop off Point:\n");
		for (d=1; d<MAX_ROUTE_LENGTH; d++)
		{
			if (bus->route[d] != 0)
			{ 
				printf("   %d (%d) - ", d, bus->route[d]);
				printDropOffPointFromCode(bus->route[d]);
				printf("\n");
				nDropOffOptions++;
			}
		}
		scanf(" %d", &dropOff);

		if (!(dropOff >= 1 && dropOff <= nDropOffOptions))
		{
			printf("\nInvalid input. Please input a number between 1 to %d\n", nDropOffOptions);
		}
		else
			validInput = 1;
	}

	int dropOffId = bus->route[dropOff];

	inputPassenger(priority,
					firstName,
					lastName,
					id,
					dropOffId,
					seat, bus, nReserve);

	pauseAndContinueOnReturn();
}

/* getBusFull: sets two integers to the fullness of their corresponding trips
   @param trips - list of bus trips
   @param *nFullA - Represents whether or not Manila-Laguna are all full.
   @param *nFullB - Represents whether or not Laguna-Manila are all full.
   @return void
*/ 
void getBusFull(struct Bus trips[], int *nFullA, int *nFullB)
{
	int i;
	int counterA = 0;
	int counterB = 0;

	for (i=0; i<MAX_TRIPS; i++)
	{
		if (getPassengerCount(trips[i]) >= MAX_PASSENGERS)
		{
			if (i < MAX_TRIPS_MANILA)
				counterA++;
			else
				counterB++;
		}
	}
	//Checks if trips 101 -> 109 are full and enables the special trip if yes.
	if (counterA >= MAX_TRIPS_MANILA-1 && !*nFullA)
	{
		*nFullA = 1;
		trips[MAX_TRIPS_MANILA-1].dispatchable = 1;
		trips[MAX_TRIPS_MANILA-2].next = &trips[MAX_TRIPS_MANILA-1];
	}
	//Checks if trips 150 -> 160 are full and enables the special trip if yes.
	if (counterB >= MAX_TRIPS_LAGUNA-1 && !*nFullB)
	{
		*nFullB = 1;
		trips[MAX_TRIPS-1].dispatchable = 1;
		trips[MAX_TRIPS-2].next = &trips[MAX_TRIPS-1];
	}
}

/*
	============================
		PERSONNEL OPERATIONS
	============================
*/

/* displayPassengerCount: Takes a bus and displays the passenger count
   @param bus - bus to display the information of
   @return void
*/ 
void
displayPassengerCount(struct Bus bus)
{
	clearScreen();

	int nRow, nColumn, n;
	n = 0;
	int nPassengerCount = getPassengerCount(bus);
	
	if(nPassengerCount > 13 || bus.tripNumber == 110 || bus.tripNumber == 161)
		for(nRow = 0; nRow < 5; nRow++)
		{
			if(nRow < 3)
			{
				printf("+-----+-----+-----+-----+\n");
				for(nColumn = 0; nColumn < 4; nColumn++)
				{
					char seat = 'O';
					if (bus.passengers[n].onboard) seat = 'X';

					printf("|  %1c  ", seat);
					n++;
				}
				printf("|");
				printf("\n");
				printf("+-----+-----+-----+-----+\n");
			}
			else if(nRow == 3)
			{
			printf("+-----+-----+-----+-----+\n");
				for(nColumn = 0; nColumn < 4; nColumn++)
				{
					if(nColumn == 0)
						printf("|     ");
					else
					{
						char seat = 'O';
						if (bus.passengers[n].onboard) seat = 'X';
						printf("|  %1c  ", seat);
						n++;
					}
				}
				printf("|");
				printf("\n");
				printf("+-----+-----+-----+-----+\n");	
			}
			else
			{
				char seat = 'O';
				if (bus.passengers[n].onboard) seat = 'X';

				printf("+-----+-----+\n");
				printf("|  %1c  |  D  |\n", seat);
				printf("+-----+-----+\n");
			}
		}

	else
		for(nRow = 0; nRow < 5; nRow++)
		{
			if(nRow < 4)
			{
				printf("+-----+-----+-----+\n");
				for(nColumn = 0; nColumn < 3; nColumn++)
				{
					char seat = 'O';
					if (bus.passengers[n].onboard) seat = 'X';
					
					printf("|  %1c  ", seat);
					n++;
				}
				printf("|");
				printf("\n");
				printf("+-----+-----+-----+\n");
			}
			
			else
			{
				char seat = 'O';
				if (bus.passengers[n].onboard) seat = 'X';

				printf("+-----+-----+\n");
				printf("|  %1c  |  D  |\n", seat);
				printf("+-----+-----+\n");
			}
		}
	printf("Passenger Count: %d\n", getPassengerCount(bus));		
}

/* viewPassengerCount: Asks the user for a trip number and views the passenger count for the corresponding trip number
   @param trips - List of bus trips 
   @return void
*/
void 
viewPassengerCount(struct Bus trips[])
{
	clearScreen();
	struct Bus *bus = getInputTripNumber(trips);
	displayPassengerCount(*bus);
	pauseAndContinueOnReturn();
}

/* viewDropOffCount: Asks the user for a trip number and displays the number of passengers who will disembark on particular drop-off points.t
   @param trips - list of bus trips for processing
   @return void
*/
void 
viewDropOffCount(struct Bus trips[])
{
	clearScreen();


	struct Bus *bus = getInputTripNumber(trips);
	int nTripNo = bus->tripNumber;


	int routeCounter[MAX_ROUTE_LENGTH] = {0,0,0,0,0};

	int i, j;
	for (i=1; i<MAX_ROUTE_LENGTH; i++)
	{
		for (j=0; j<MAX_PASSENGERS; j++)
		{
			if (bus->route[i] == bus->passengers[j].dropOff && bus->route[i] != 0)
			{
				routeCounter[i]++;
			}
		}
	}


	printf("=======================================================\n");
	printf("Drop-off count for Trip Number AE-%d\n", nTripNo);
	
	for (i=1; i<MAX_ROUTE_LENGTH; i++)
	{
		if (bus->route[i])
		{
			printf("%d - ", routeCounter[i]);
			printDropOffPointFromCode(bus->route[i]);
			printf("\n");
		}	
		
	}

	printf("=======================================================\n");

	pauseAndContinueOnReturn();
}

/* viewPassengerInformation: Asks the user for a trip number and displays the trip's passenger information
   @param trips - list of bus trips for processing
   @return void
*/
void 
viewPassengerInformation(struct Bus trips[])
{
	clearScreen();

	struct Bus *bus = getInputTripNumber(trips);
	struct Passenger passengerListSorted[16];
	
	int i, j;
	// Copy all passengers to a list to sort by priority
	for (i=0; i < MAX_PASSENGERS; i++)
	{
		passengerListSorted[i] = bus->passengers[i];
	}

	// Sort Passengers By Priority
	for (i=0; i < MAX_PASSENGERS; i++)
	{ 
		for (j=i; j < MAX_PASSENGERS ; j++)
		{
			if (passengerListSorted[j].priority < passengerListSorted[i].priority)
			{
				struct Passenger tempPassenger = passengerListSorted[i];
				passengerListSorted[i] = passengerListSorted[j];
				passengerListSorted[j] = tempPassenger;
			}
		}
	}

	printf("===========================================================================\n");
	printf("      First Name      |      Last Name       |  ID NUMBER   |   Priority   \n");
	printf("===========================================================================\n");
	
	for (i=0; i<16; i++)
	{
		if (passengerListSorted[i].onboard)
		{
			printf(" %-20s | %-20s |   %d   | %6d\n", passengerListSorted[i].firstName, passengerListSorted[i].lastName, passengerListSorted[i].id, passengerListSorted[i].priority);
		}
	}

	printf("===========================================================================\n");

	pauseAndContinueOnReturn();
}

/* viewPassengerInformation: Asks the user for a last name and searches through the trips and displays the passenger/s with the last name
   @param trips - list of bus trips for processing
   @return void
*/
void 
searchPassenger(struct Bus trips[])
{
	String20 lastNameSearch;
	int validInput = 0;
	while (!validInput)
	{
		printf("Please enter the last name of the passenger you would like to search for. Do not include any spaces.\n");
		scanf(" %s", lastNameSearch);

		if (lastNameSearch[0] == '\0')
			printf("\nInput is empty! Please try again.\n\n");
		else
			validInput = 1;
	}

	int i, k;
	int found = 0;
	for (i=0; i < MAX_TRIPS; i++)
	{
		for (k=0; k < MAX_PASSENGERS; k++)
		{
			if (strcmp(trips[i].passengers[k].lastName, lastNameSearch) == 0)
			{
				found = 1;
				printf("\nPassenger Found!\n");
				printf("First Name  : %s\n", trips[i].passengers[k].firstName);
				printf("Last Name   : %s\n", trips[i].passengers[k].lastName);
				printf("Trip Number : AE-%d\n", trips[i].tripNumber);
				printf("Seat Number : %d\n", k+1);
				printf("ID Number   : %d\n", trips[i].passengers[k].id);
				printf("Priority    : %d\n", trips[i].passengers[k].priority);
			}
		}
	}

	if (!found)
		printf("No passenger(s) with last name %s found!\n", trips[i].passengers[k].lastName);
	
	pauseAndContinueOnReturn();
}

/* scanPassengerInformation: scans a passengers information from a file into particular variables
   @param fp            - file pointer of the file to be scanned
   @param *nTripNo      - pointer to the trip number variable to store the data
   @param *nEmbarkPoint - pointer to the embark point variable to store the data
   @param lastName      - last name string to store the data
   @param firstName     - first name string to store the data
   @param *nId          - pointer to the id variable to store the data
   @param *nPriority    - pointer to the priority variable to store the data
   @param *nDropOff     - pointer to drop-off point varialbe to store the data
   @return int          - returns the number of successfully scanned parameters
*/
int scanPassengerInformation(FILE *fp, int *nTripNo, int *nEmbarkPoint, String20 lastName, String20 firstName, int *nId, int *nPriority, int *nDropOff)
{
	/*
		Format for scanning passenger information:
		<trip number>
		<embarkation point>
		<passenger first name>, <passenger last name>
		<id number>
		<priority number>
		<drop-off point>
	*/
	int k = 0;

	k += fscanf(fp, " %d", nTripNo);
	k += fscanf(fp, " %d", nEmbarkPoint);
	k += fscanf(fp, " %[^,],", lastName);
	k += fscanf(fp, " %s", firstName);
	k += fscanf(fp, " %d", nId);
	k += fscanf(fp, " %d", nPriority);
	k += fscanf(fp, " %d", nDropOff);

	return k;
}

/* loadPassengerFromFile: loads passenger information from a file and attempts to board them onto a trip
   @param trips - list of bus trips
   @return void
*/
void loadPassengerFromFile(struct Bus trips[])
{
	clearScreen();

	String20 filename;
	printf("Input the name of the file (max 20 chars. and no spaces):\n");
	scanf(" %20s", filename);

	FILE *fp = NULL;


	fp = fopen(filename, "r");

	if (fp == NULL)
	{
		printf("File with the name %s not found!", filename);
	}
	else if (strlen(filename) < 4) // Protects against seg fault
	{
		printf("File extension not supported! This operation only supports .txt files.\n");
	}	
	else if (strcmp( (filename + strlen(filename) - 4), ".txt") != 0)
	{
		printf("File extension not supported! This operation only supports .txt files.\n");
	}
	else 
	{
		int nTripNo, nId, nPriority, nDropOff, nEmbarkPoint = 0;
		String20 firstName, lastName;
		String50 EmbarkString;
		String50 DropOffString;
		// String20 tempString;

		// Reading information from file 

		fscanf(fp, " Trip Number: %3d", &nTripNo);
		fscanf(fp, " Embarkation Point: %50[^\n\r]", EmbarkString);
		nEmbarkPoint = getDropOffPointFromString(EmbarkString);
		
		fscanf(fp, " Passenger Name: %20[^,]", lastName);
		fseek(fp, 1, SEEK_CUR);
		fscanf(fp, " %s", firstName);
		fscanf(fp, " ID Number: %d", &nId); 
		fscanf(fp, " Priority: %d", &nPriority);
		fscanf(fp, " Drop-Off Point: %50[^\n\r]", DropOffString);
		nDropOff = getDropOffPointFromString(DropOffString);
		
		fclose(fp);

		struct Bus *bus = NULL;

		if (!isValidTripNumber(nTripNo))
		{
			printf("Trip number provided is not valid! Aborting operation...\n");
		}
		else
		{
			bus = getBusFromTripNumber(trips, MAX_TRIPS, nTripNo);

			int validEmbark = 0;
			int validId = 0;
			int validPriority = 0;
			int validDropOff = 0;

			int i;
			for (i=0; i<MAX_ROUTE_LENGTH; i++)
			{
				if(nEmbarkPoint == bus->route[i])
					validEmbark = 1;
				if(nDropOff == bus->route[i])
					validDropOff = 1;
			}

			if (nId >= 10000000 && nId <= 99999999 && !searchPassengerId(trips, nId))
				validId = 1;

			if (nPriority >= 1 && nPriority <= 6)
				validPriority = 1;

			if (!validEmbark || !validId || !validPriority || !validDropOff)
			{
				printf("Invalid data encountered!!\n");
				if (!validEmbark)
					printf("Invalid embarkation point provided. Please ensure that the embarkation point is spelled properly or that it is on the route of the trip.\n");
				if (!validId)
					printf("Invalid ID number provided. Enter either an 8-digit ID number or an ID number of a passenger not currently onboard.\n");
				if (!validPriority)
					printf("Invalid priority number provided. Enter a priority number between 1 and 6.\n");
				if (!validDropOff)
					printf("Invalid drop-off point provided. Please ensure that the drop-off point is spelled properly or that it is on the route of the trip.\n");
			}
			else
			{
				printf("Information scanned successfully!\n");
				printf("Inputting passenger...\n");
				
				inputPassenger(nPriority,
							firstName,
							lastName,
							nId,
							nDropOff,
							-1,
							bus,
							0);	
			}
		}
	}

	pauseAndContinueOnReturn();
}

void loadTripFromFile()
{
	clearScreen();

	String20 filename;
	printf("Input the name of the file (max 20 chars. and no spaces):\n");
	scanf(" %20s", filename);

	FILE *fp;

	fp = fopen(filename, "r");

	if (fp == NULL)
	{
		printf("File with the name %s not found!", filename);
	}	
	else if (strlen(filename) < 4) // Protects against seg fault
	{
		printf("File extension not supported! This operation only supports .txt files.\n");
	}
	else if (strcmp( (filename + strlen(filename) - 4), ".txt") != 0)
	{
		printf("File extension not supported! This operation only supports .txt files.\n");
	}
	else
	{
		printf("Displaying trip information for %s...\n\n", filename);
		String100 readLine;
		int n = 0;

		while(fscanf(fp, " %100[^\n]", readLine) > 0)
		{
			n++;
			printf("%s\n", readLine);
			if (n == 6)
			{
				n = 0;
				printf("\n");
			}
			
		}		
	}

	pauseAndContinueOnReturn();
}

/* 
	======================
		MENU Functions
	======================
*/

/* mainMenu displays the main menu of the program
   @return int - returns the screenstate for the following iteration of the mainloop
*/
int 
mainMenu()
{
	clearScreen();

	printf("==========Main Menu==========\n");
	printf("Select user type: \n");
	printf("1 - Passenger \n");
	printf("2 - Arrows Personnel \n");
	printf("3 - Exit Program (End of Day)\n");
	printf("User type: ");

	char selection;
	scanf("%c", &selection);
	printf("\n");

	int screenState;

	if (selection == '1') 
		screenState = 200;
	else if (selection == '2')
		screenState = 300;
	else if (selection == '3')
		screenState = -1;
	else
		screenState = 100;

	return screenState;

	
}

/* passengerMenu displays the displays the different menu options for a passenger
   @param trips - list of bus trips for processing
   @param *nFullA - Represents whether or not Manila-Laguna are all full.
   @param *nFullB - Represents whether or not Laguna-Manila are all full.
   @return int - returns the screenstate for the following iteration of the mainloop
*/
int 
passengerMenu(struct Bus trips[], int *nFullA, int *nFullB)
{
	clearScreen();

	printf("==========Passenger Menu==========\n");
	printf("1 - Encode Passenger Information\n");
	printf("2 - Back to Main Menu\n");
	printf("Select an Option: ");

	char selection;
	scanf(" %c", &selection);
	printf("\n");

	int screenState;

	if (selection == '1') 
	{
		encodePassengerInformation(trips);

		screenState = 210;
	}
	else if (selection == '2')
		screenState = 100;
	else
		screenState = 200;
	
	getBusFull(trips, nFullA, nFullB);

	return screenState;

}

/* arrowsPersonnelMenu displays the displays the different menu options for a passenger
   @param trips - list of bus trips for processing
   @param *nFullA - Represents whether or not Manila-Laguna are all full.
   @param *nFullB - Represents whether or not Laguna-Manila are all full.
   @return int - returns the screenstate for the following iteration of the mainloop
*/
int 
arrowsPersonnelMenu(struct Bus trips[], int *nFullA, int *nFullB)
{
	clearScreen();

	printf("==========Arrows Personnel Menu==========\n");
	printf("1 - View Passenger Count\n");
	printf("2 - View Drop-Off Count\n");
	printf("3 - View Passenger Information\n");
	printf("4 - Load Passenger(Single Passenger) \n");
	printf("5 - Search Passenger\n");
	printf("6 - Load Recent Trip File for Viewing\n");
	printf("7 - Back to Main Menu\n");
	printf("Select an Option: \n");

	char selection;
	printf("\n%d, %d\n", *nFullA, *nFullB);
	scanf(" %c", &selection);
	printf("\n");

	int screenState;

	if (selection == '1')
	{
		viewPassengerCount(trips);
		screenState = 320;
	}
	else if (selection == '2') 
	{
		viewDropOffCount(trips);
		screenState = 320;
	}
	else if (selection == '3')
	{
		viewPassengerInformation(trips);
		screenState = 320;
	}
	else if (selection == '4')
	{
		loadPassengerFromFile(trips);
		screenState = 320;
	}
	else if (selection == '5')
	{
		searchPassenger(trips);
		screenState = 320;
	}
	else if (selection == '6')
	{
		loadTripFromFile();
		screenState = 320;
	}
	else if (selection == '7')
	{
		screenState = 100;
	}
	else
		screenState = 300;

	// Check if full
	if (!*nFullA || !*nFullB)
		getBusFull(trips, nFullA, nFullB);	

	return screenState;
}