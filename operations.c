/*********************************************************************************************************
This is to certify that this project is my own work, based on my personal efforts in studying and applying the concepts
learned. I have constructed the functions and their respective algorithms and corresponding code by myself. The
program was run, tested, and debugged by my own efforts. I further certify that I have not copied in part or whole or
otherwise plagiarized the work of other students and/or persons.
<Theon Schuyler S. Garcia>, DLSU ID# <12409537> , 
*********************************************************************************************************/

#include <stdio.h>
#include <string.h>

#include "operations.h"

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

/* getBusFromTripNumber: Returns the pointer of a particular bus with a corresponding trip number
   @param trips      - list of bus trips
   @param n          - number of total trips; only used for the loop
   @param tripNumber - trip number of the desired bus
   @return bus*      - pointer to the bus with the corresponding trip number. Pointer is set to NULL if no bus is found.
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

	//   printf("|====MANILA-LAGUNA====|====LAGUNA-MANILA====|\n");
	//   printf("|        AE-101       |        AE-150       |\n");
	//   printf("|        AE-102       |        AE-151       |\n");
	//   printf("|        AE-103       |        AE-152       |\n");
	//   printf("|        AE-104       |        AE-153       |\n");
	//   printf("|        AE-105       |        AE-154       |\n");
	//   printf("|        AE-106       |        AE-155       |\n");
	//   printf("|        AE-107       |        AE-156       |\n");
	//   printf("|        AE-108       |        AE-157       |\n");
	//   printf("|        AE-109       |        AE-158       |\n");
	//   printf("|                     |        AE-159       |\n");
	//   printf("|                     |        AE-160       |\n");

	// printf("|===========================================|\n");

}

/* displayDropOff: displays the list of drop off points
   @param nTripNo - trip number that determines which drop off points are available for the route of the bus
   @return int - returns the number of total options for the drop off points to choose from
*/ 
int displayDropOff(int nTripNo)
{
	int options = -1;
	if(nTripNo == 101 || nTripNo == 103 || nTripNo == 105 || nTripNo == 107 || nTripNo == 109)
	{
		printf("==========Drop-Off Points==========\n");
		printf("1 - Mamplasan Toll Exit\n");
		printf("2 - Phase 5, San Jose Vilage\n");
		printf("3 - Milagros Del Rosario Building - East Canopy\n");
		options = 3;
	}
	else if(nTripNo == 102 || nTripNo == 104 || nTripNo == 106 || nTripNo == 108 || nTripNo == 110)
	{
		printf("==========Drop-Off Points==========\n");
		printf("1 - Laguna Blvd. Guard House(across Paseo PHOENIX Gasoline Station)\n");
		printf("2 -  Milagros Del Rosario Building - East Canopy\n");
		options = 2;
	}
	else if(nTripNo == 151 || nTripNo == 153 || nTripNo == 155 || nTripNo == 157 || nTripNo == 159 || nTripNo == 161)
	{
		printf("==========Drop-Off Points==========\n");
		printf("1 - Petron Gasoline Station along Gil Puyat Avenue \n");
		printf("2 - Gate 4: Gokongwei Gate \n");
		printf("3 - Gate 2: North Gate (HSSH) \n");
		printf("4 - Gate 1: South Gate (LS Building Entrance) \n");
		options = 4;
	}
	else if(nTripNo == 150 || nTripNo == 152 || nTripNo == 154 || nTripNo == 156 || nTripNo == 158 || nTripNo == 160)
	{
		printf("==========Drop-Off Points==========\n");
		printf("1 - College of St. Benilde (CSB) along Taft Avenue  \n");
		printf("2 - Gate 4: Gokongwei Gate \n");
		printf("3 - Gate 2: North Gate (HSSH) \n");
		printf("4 - Gate 1: South Gate (LS Building Entrance) \n");
		options = 4;
	}

	return options;
	
}

void clearScreen()
{
	printf("\e[1;1H\e[2J"); // Regex clear function
}

void pauseAndContinueOnReturn()
{
	printf("\nType any character and press return to continue\n");
	scanf(" \n");
	getchar();
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

int
dropOffInRoute(int dropOff, int route)
{
	// if (route == 100)

	return 0;

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
	if (bus->tripNumber == -1)
    {
        printf("There are no more remaining bus trips!\n");
    }

	// Check first if valid dropOff
	int validDropOff = 0;
	int lastValidRoutePoint = 0;
	int k;
	for (k=0; k<MAX_ROUTE_LENGTH; k++)
	{
//		printf("%d   |   %d\n", dropOffPoint, bus->route[k]);
		if (dropOffPoint == bus->route[k])
		{
			validDropOff = 1;
			k=MAX_ROUTE_LENGTH;
		}
		if (bus->route[k] != 0)
			lastValidRoutePoint = bus->route[k];

	}
	if (!validDropOff) // Default drop off point
	{
		dropOffPoint = lastValidRoutePoint;
		printf("Provided drop-off point for trip AE-%d is not part of the route! defaulting to final drop-off point at ", bus->tripNumber);
		printDropOffPointFromCode(lastValidRoutePoint);
		printf("\n");
	}

    if (isTripFull(*bus))
    {
        // Check for the lowest priority passenger
        struct Passenger *lastLowestPriorityPassenger = NULL;
        int i;
		int seat = 0;
        for (i=MAX_PASSENGERS-1; i>=0; i--)
        {
            if (priority > bus->passengers[i].priority && bus->passengers[i].priority > 0)
            {
                lastLowestPriorityPassenger = &(bus->passengers[i]);
				seat = i;
				i = 0;
            }

        }


		if (lastLowestPriorityPassenger == NULL) 
		{
			printf("Sorry, passenger %s %s this trip (AE%d) cannot accomodate you.\n", firstName, lastName, bus->tripNumber);
		}
		else 
		{
			struct Passenger tempPassenger;
			// Move the firstLowestPassenger to a temporary variable to be moved to the next bus.
			setPassenger(&tempPassenger, 
						lastLowestPriorityPassenger->priority, 
						lastLowestPriorityPassenger->firstName,
						lastLowestPriorityPassenger->lastName,
						lastLowestPriorityPassenger->id,
						lastLowestPriorityPassenger->dropOff,
						lastLowestPriorityPassenger->reserved);

			// Move the current passenger into the seat of the lastLowestPassenger

			setPassenger(lastLowestPriorityPassenger,
						priority,
						firstName,
						lastName,
						id,
						dropOffPoint,
						nReserve);

			printf("\nPassenger Input Sucessfully!\n");
			printf("   Name        : %s, %s\n", lastName, firstName);
			printf("   ID Number   : %d\n", id);
			printf("   Priority    : %d\n", priority);
			printf("   Seat Number : %d\n", seat);
			printf("   Trip Number : AE-%d\n", bus->tripNumber);
			
			// Moving lowest priority passenger to next trip
			printf("\nPassenger %s %s will be moved to the following trip to acommodate a higher priority passenger.\n", tempPassenger.firstName, tempPassenger.lastName);

			inputPassenger(
				tempPassenger.priority,
				tempPassenger.firstName,
				tempPassenger.lastName,
				tempPassenger.id,
				tempPassenger.dropOff,
				-1,
				bus->next,
				tempPassenger.reserved);
			
		}
        
    }

    else
    {
		if (seatNumber == -1 && nReserve != 1) // Automatic seat assignment
		{
			int i;
			for (i=0; i<16; i++)
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

					printf("\nPassenger Input Sucessfully!\n");
					printf("   Name        : %s, %s\n", lastName, firstName);
					printf("   ID Number   : %d\n", id);
					printf("   Priority    : %d\n", priority);
					printf("   Seat Number : %d\n", i);
					printf("   Trip Number : AE-%d\n", bus->tripNumber);

					i=16;
				}
			}
		}
//		else if () // TODO: Needs to be changed for the bonus implementation

		else if(seatNumber == -1 && nReserve == 1 && bus->nReserveCount < 5)
		{
			printf("What seat do you want to occupy?\n");
			scanf("%d", &seatNumber);
			setPassenger(&(bus->passengers[seatNumber-1]),
					priority,
					firstName,
					lastName,
					id,
					dropOffPoint,
					nReserve);
			
			printf("\nPassenger Input Sucessfully!\n");
			printf("   Name        : %s, %s\n", lastName, firstName);
			printf("   ID Number   : %d\n", id);
			printf("   Priority    : %d\n", priority);
			printf("   Seat Number : %d\n", seatNumber);
			printf("   Trip Number : AE-%d\n", bus->tripNumber);
		}
		else 
		{
			setPassenger(&(bus->passengers[seatNumber-1]),
					priority,
					firstName,
					lastName,
					id,
					dropOffPoint,
					nReserve);
			
			printf("\nPassenger Input Sucessfully!\n");
			printf("   Name        : %s, %s\n", lastName, firstName);
			printf("   ID Number   : %d\n", id);
			printf("   Priority    : %d\n", priority);
			printf("   Seat Number : %d\n", seatNumber);
			printf("   Trip Number : AE-%d\n", bus->tripNumber);
		}
		
    }
    

}

/* inputTripNumber: Takes input from the user an attempts to board them onto a particular bus.
   @param bus - pointer to the bus the passenger will be encoded to
   @return int - the trip number the user input
*/
int 
inputTripNumber(struct Bus trips[])
{
	int trip;
	printf("What trip will you be boarding? (Please input the 3-digit number of the trip excluding the \"AE\")\n\n");
	
	// TODO: Implement the nFull function
	displayTripList(trips);
	
	printf("Enter Trip Number:");
	scanf("%d", &trip);

	if ( (trip >=101 && trip <= 109) || (trip >= 150 && trip <= 160) ) // IMPORTANT! Does not include logic for the special trips.
		return trip;
	else
	{
		printf("Please return a valid trip number and try again.\n");
		return inputTripNumber(trips);
	}
}

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

/* inputPassengerInformation: Takes input from the user for encoding the passenger information. 
   @param bus - pointer to the bus the passenger will be encoded to
   @return void
*/
void 
inputPassengerInformation(int tripNo, struct Bus trips[]) 
{
	int result = 0;
	struct Bus *bus = getBusFromTripNumber(trips, MAX_TRIPS, tripNo);
	
	printf("==========Enter Details Below==========\n");
	int priority, id, dropOff, nReserve;
	String20 firstName, lastName;

	int validInput = 0;

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

	validInput = 0;
	printf("First Name (NOTE: DO NOT INCLUDE ANY SPACES):\n");
	while(!validInput)
	{
		scanf(" %s", firstName); // TODO: Fix this and for last name too
		if (strcmp(firstName, "(NOTE -- DO NOT INCLUDE ANY SPACES. USE UNDERSCORE OR HYPHEN)") == 0)
		{
			printf("\nNo first name found! Please input a valid string!\n");
		}
		else
			validInput = 1;
	}

	validInput = 0;
	while(!validInput)
	{
		printf("Last Name: (NOTE: DO NOT INCLUDE ANY SPACES):\n");
		scanf(" %s", lastName);

		if (strcmp(firstName, "") == 0)
		{
			printf("\nNo last name found! Plase input a valid string!\n");
		}
		else
			validInput = 1;
	}
	
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
		scanf("%d", &nReserve);
		if(nReserve < 0 && nReserve > 1)
		{
			printf("\nInvalid input! Please input a priority number from 1 for yes or 0 for no.\n");
		}
		else
		{
			validInput = 1;
			bus->nReserveCount += 1;
		}
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
	
	// TODO: Logic may be added here for implementation of bonus feature in the future

	inputPassenger(priority,
					firstName,
					lastName,
					id,
					dropOffId,
					-1, bus, nReserve);
	
}

/* encodePassengerInformation: Combines the functions inputTripNumber and inputPassengerInformation and creates the logic for 
   @param trips - array of all the busses
   @return void
*/
void 
encodePassengerInformation(struct Bus trips[])
{
	clearScreen();
	int tripNo = inputTripNumber(trips);

	clearScreen();
	inputPassengerInformation(tripNo, trips);

	pauseAndContinueOnReturn();
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
	
	if(nPassengerCount <= 13)
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

	else
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
	
	// TODO: Remove this before submission
	printf("FOR DEBUGGING PURPOSES!\n");
	printf("Passenger List\n");
	int x;
	for (x=0; x<MAX_PASSENGERS; x++)
	{
		if (bus.passengers[x].onboard)
		{
			printf("%s, %s; ID: %d; Drop off %d; Priority: %d\n", bus.passengers[x].lastName, bus.passengers[x].firstName, bus.passengers[x].id, bus.passengers[x].dropOff, bus.passengers[x].priority);
		}
	}
}

/* viewPassengerCount: Asks the user for a trip number and views the passenger count for the corresponding trip number
   @param trips - List of bus trips 
   @return void
*/
void 
viewPassengerCount(struct Bus trips[])
{
	clearScreen();

	int nTripNumber;
	int validInput = 0;
	while (!validInput)
	{
		displayTripList(trips);
		printf("Which trip would you like to view?\n");
		scanf("%d", &nTripNumber);

		if (!isValidTripNumber(nTripNumber))
			printf("\nInvalid trip number. Please enter a valid trip number!\n\n");
		else
			validInput = 1;
	}

	struct Bus *bus = getBusFromTripNumber(trips, 22, nTripNumber);
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

	int nTripNo;

	int validInput = 0;
	while (!validInput)
	{
		displayTripList(trips);
		printf("Which trip's drop-off information would you like to view?\n");
		scanf(" %d", &nTripNo);

		if (!isValidTripNumber(nTripNo) )
			printf("\nInvalid trip number. Please enter a valid trip number!\n\n");
		else
			validInput = 1;
	}

	struct Bus *bus = getBusFromTripNumber(trips, 22, 101);	

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
	printf("Drop-off count for Trip Number AE-%d\n", 101);
	
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



	// Drop offs are counted for all possible drop offs regardless of the trip number

	// int dropOff10010 = 0;
	// int dropOff10020 = 0; 
	// int dropOff10030 = 0; 
	// int dropOff10040 = 0; 

	// int dropOff20010 = 0; 
	// int dropOff20020 = 0;
	// int dropOff20030 = 0;
	// int dropOff20040 = 0;
	// int dropOff20050 = 0;


	// int i;

	// for (i=0; i<16; i++)
	// {
	// 	if (bus->passengers[i].dropOff == 10010)
	// 		dropOff10010++;
	// 	if (bus->passengers[i].dropOff == 10020)
	// 		dropOff10020++;
	// 	if (bus->passengers[i].dropOff == 10030)
	// 		dropOff10030++;
	// 	if (bus->passengers[i].dropOff == 10040)
	// 		dropOff10040++;

	// 	if (bus->passengers[i].dropOff == 20010)
	// 		dropOff20010++;
	// 	if (bus->passengers[i].dropOff == 20020)
	// 		dropOff20020++;
	// 	if (bus->passengers[i].dropOff == 20030)
	// 		dropOff20030++;
	// 	if (bus->passengers[i].dropOff == 20040)
	// 		dropOff20040++;
	// 	if (bus->passengers[i].dropOff == 20050)
	// 		dropOff20050++;
		
	// }

	// printf("=======================================================\n");
	// printf("Drop-off count for Trip Number AE-%d\n", nTripNumber);

	// // Conditionals for the trip number are only considered here to decrease code redundancy
	// if (nTripNumber == 101 || nTripNumber == 103 || nTripNumber == 105 || nTripNumber == 109)
	// {
	// 	printDropOffPointFromCode(10010);
	// 	printf("- %d\n", dropOff10010);
	// 	printDropOffPointFromCode(10020);
	// 	printf("- %d\n", dropOff10020);
	// 	printDropOffPointFromCode(10030);
	// 	printf("- %d\n", dropOff10030);
	// }

	// else if (nTripNumber == 102 || nTripNumber == 104 || nTripNumber == 106 || nTripNumber == 108 || nTripNumber == 110)
	// {
	// 	printf("%d - ", dropOff10040);
	// 	printDropOffPointFromCode(10040);
	// 	printf("\n%d - ", dropOff10030);
	// 	printDropOffPointFromCode(1030);
	// }

	// else if (nTripNumber == 151 || nTripNumber == 153 || nTripNumber == 155 || nTripNumber == 157 || nTripNumber == 159 || nTripNumber == 161)
	// {
	// 	printf("%d - ", dropOff20010);
	// 	printDropOffPointFromCode(20010);
	// 	printf("\n%d - ", dropOff20010);
	// 	printDropOffPointFromCode(20030);
	// 	printf("\n%d - ", dropOff20010);
	// 	printDropOffPointFromCode(20040);
	// 	printf("\n%d - ", dropOff20010);
	// 	printDropOffPointFromCode(20050);
	// }

	// else if (nTripNumber == 150 || nTripNumber == 152 || nTripNumber == 154 || nTripNumber == 156 || nTripNumber == 158 || nTripNumber == 160)
	// {
	// 	printf("%d - ", dropOff20020);
	// 	printDropOffPointFromCode(20020);
	// 	printf("\n%d - ", dropOff20010);
	// 	printDropOffPointFromCode(20030);
	// 	printf("\n%d - ", dropOff20010);
	// 	printDropOffPointFromCode(20040);
	// 	printf("\n%d - ", dropOff20010);
	// 	printDropOffPointFromCode(20050);
	// }
	// printf("=======================================================\n");


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

	int nTripNumber;
	int validInput = 0;
	while (!validInput)
	{
		displayTripList(trips);
		printf("Which trip's passenger information would you like to view?\n");
		int *pInt = &nTripNumber;
		scanf("%d", pInt);

		if (!isValidTripNumber(nTripNumber))
			printf("\nInvalid trip number. Please enter a valid trip number!\n\n");
		else
			validInput = 1;
	}

	struct Bus *bus = getBusFromTripNumber(trips, 22, nTripNumber);
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
// [/] 1 - View Passenger Count
// [/] 2 - View Drop-Off Count
// [/] 3 - View Passenger Information
// [ ] 4 - Load Passenger(Single Passengerpa) 
// [/] 5 - Search Passenger
// [ ] 6 - Load Recent Trip File for Viewing
// [ ] 7 - Back to Main Menu

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

	return screenState;

}

/* arrowsPersonnelMenu displays the displays the different menu options for a passenger
   @param trips - list of bus trips for processing
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
		screenState = 320;
	}
	else if (selection == '5')
	{
		searchPassenger(trips);
		screenState = 320;
	}
	else if (selection == '6')
	{
		screenState = 320;
	}
	else if (selection == '7')
	{
		screenState = 100;
	}
	else
		screenState = 300;

	return screenState;
}