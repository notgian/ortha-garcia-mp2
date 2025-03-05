/*********************************************************************************************************
This is to certify that this project is my own work, based on my personal efforts in studying and applying the concepts
learned. I have constructed the functions and their respective algorithms and corresponding code by myself. The
program was run, tested, and debugged by my own efforts. I further certify that I have not copied in part or whole or
otherwise plagiarized the work of other students and/or persons.
<Theon Schuyler S. Garcia>, DLSU ID# <12409537> , 
*********************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include "struct-initializations.c"

/*
==================================
   Bus and Passenger Operations
==================================

NOTE FOR DROP OFF POINTS:
1 - Mamplasan Toll Exit
2 - Phase 5, San Jose Vilage
3 - Milagros Del Rosario Building - East Canopy
4 - Laguna Blvd. Guard House(across Paseo PHOENIX Gasoline Station)
6 -  Milagros Del Rosario (MRR) Building - East Canopy


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

/*
========================
  Passenger Operations
========================
*/

/* setPassenger: takes a pointer to a passenger to set the corresponding properties
   @param passenger    - pointer to the passenger
   @param priority 	   - priority number of the passenger
   @param firstName    - first name of the passenger
   @param lastName     - last name of the passenger
   @param id           - id number of the passenger
   @param dropOffPoint - drop off point of the passenger, represented through an int
   @return void
*/ 
void
setPassenger(struct Passenger *passenger, int priority, String20 firstName, String20 lastName, int id, int dropOffPoint)
{
	passenger->priority = priority;
	strcpy(passenger->firstName, firstName);
	strcpy(passenger->lastName, lastName);
	passenger->id = id;
	passenger->dropOff = dropOffPoint;
	passenger->onboard = 1;
}

void 
inputPassenger(int priority, String20 firstName, String20 lastName, int id, int dropOffPoint, int seatNumber, struct Bus *bus)
{
    if (bus->tripNumber == -1)
    {
        printf("There are no more remaining bus trips!\n");
        return;
    }

    if (isTripFull(*bus))
    {
        // Check for the lowest passenger
        struct Passenger *firstLowestPassenger = NULL;
        int i;
        for (i=0; i<16; i++)
        {
            if (priority > bus->passengers[i].priority && bus->passengers[i].priority > 0)
            {
                firstLowestPassenger = &(bus->passengers[i]);
            }

        }


		if (firstLowestPassenger == NULL) 
		{
			printf("Sorry, passenger %s %s this trip (AE%d) cannot accomodate you.\n", firstName, lastName, bus->tripNumber);
		}
		else 
		{
			struct Passenger tempPassenger;
			// Move the firstLowestPassenger to a temporary variable to be moved to the next bus.
			setPassenger(&tempPassenger, 
						firstLowestPassenger->priority, 
						firstLowestPassenger->firstName,
						firstLowestPassenger->lastName,
						firstLowestPassenger->id,
						firstLowestPassenger->dropOff);
			// Move the current passenger into the seat of the firstLowestPassenger
			setPassenger(firstLowestPassenger,
						priority,
						firstName,
						lastName,
						id,
						dropOffPoint);

			printf("Passenger %s %s will be moved to the following trip to acommodate a higher priority passenger.\n", tempPassenger.firstName, tempPassenger.lastName);

			inputPassenger(
				tempPassenger.priority,
				tempPassenger.firstName,
				tempPassenger.lastName,
				tempPassenger.id,
				tempPassenger.dropOff,
				-1,
				bus->next
			);
			
		}
        
    }
    else
    {
        // Assign Passenger to trip
			// If seat num = -1 -> find the first free seat
			// else if seat indicated is taken -> display error and try tell user to try again

		if (seatNumber == -1) // indicates automatic assignment
		{
			int i;
			for (i=0; i<16; i++)
			{
				if (bus->passengers[seatNumber-1].onboard == 0)
				{
					setPassenger(&(bus->passengers[i]),
					priority,
					firstName,
					lastName,
					id,
					dropOffPoint);

					printf("Passenger Input Sucessfully! Seat Number %d\n", seatNumber);
					i=16;
				}
			}
		}
		else if (bus->passengers[seatNumber-1].onboard) // Needs to be changed for the bonus implementation
		{
			printf("There is already a passenger on seat\n");
		}
		else
		{

			setPassenger(&(bus->passengers[seatNumber-1]),
					priority,
					firstName,
					lastName,
					id,
					dropOffPoint);
			printf("Passenger Input Sucessfully!\n");
		}
		
    }

}

/* 

	GUI Functions

*/

/* mainMenu displays the main menu of the program
*/
void 
mainMenu()
{
	printf("==========Main Menu==========\n");
	printf("Select user type: \n");
	printf("1 - Passenger \n");
	printf("2 - Arrows Personnel \n");
	printf("3 - Exit Program (End of Day)\n");
	printf("User type: ");
}

//This function displays the different menu options for a passenger
void 
passengerMenu()
{
	printf("==========Passenger Menu==========\n");
	printf("1 - Encode Passenger Information\n");
	printf("2 - Back to Main Menu\n");
	printf("Select an Option: ");
}


//This function displays the different menu options for "Arrows Personnel"
void 
arrowsPersonnelMenu()
{
	printf("==========Arrows Personnel Menu==========\n");
	printf("1 - View Passenger Count\n");
	printf("2 - View Drop-Off Count\n");
	printf("3 - View Passenger Information\n");
	printf("4 - Load Passenger(Single Passenger) \n");
	printf("5 - Search Passenger\n");
	printf("6 - Load Recent Trip File for Viewing\n");
	printf("7 - Back to Main Menu\n");
	printf("Select an Option: \n");
}

//This function displays the list of trips.
void 
displayTripList(int nFull)
{
	printf("==========List of Trips==========\n\n");
	//Manila
	printf("==========MANILA-LAGUNA==========\n");
	printf("AE-101\n");
	printf("AE-102\n");
	printf("AE-103\n");
	printf("AE-104\n");
	printf("AE-105\n");
	printf("AE-106\n");
	printf("AE-107\n");
	printf("AE-108\n");
	printf("AE-109\n");
	
	//Laguna
	printf("==========LAGUNA-MANILA==========\n");
	printf("AE-150\n");
	printf("AE-151\n");
	printf("AE-152\n");
	printf("AE-153\n");
	printf("AE-154\n");
	printf("AE-155\n");
	printf("AE-156\n");
	printf("AE-157\n");
	printf("AE-158\n");
	printf("AE-159\n");
	printf("AE-160\n");
	
	//Special
	if(nFull == 1)
	{
		printf("==========SPECIAL==========\n");
		printf("21 - SPECIAL\n\n");
	}		
}

void displayDropOff(int nTripNo)
{
	if(nTripNo == 101 || nTripNo == 103 || nTripNo == 105
	   || nTripNo == 107 || nTripNo == 109)
	{
		printf("==========Drop-Off Points==========\n");
		printf("1 - Mamplasan Toll Exit\n");
		printf("2 - Phase 5, San Jose Vilage\n");
		printf("3 - Milagros Del Rosario Building - East Canopy\n");
	}
	else if(nTripNo == 102 || nTripNo == 104 || nTripNo == 106 || nTripNo == 108 || nTripNo == 110)
	{
		printf("==========Drop-Off Points==========\n");
		printf("4 - Laguna Blvd. Guard House(across Paseo PHOENIX Gasoline Station)\n");
		printf("5 -  Milagros Del Rosario Building - East Canopy\n");
	}
	else if(nTripNo == 151 || nTripNo == 153 || nTripNo == 155 || nTripNo == 157 || nTripNo == 159 || nTripNo == 161)
	{
		printf("==========Drop-Off Points==========\n");
		printf("6 - Petron Gasoline Station along Gil Puyat Avenue \n");
		printf("7 - Gate 4: Gokongwei Gate \n");
		printf("8 - Gate 2: North Gate (HSSH) \n");
		printf("9 - Gate 1: South Gate (LS Building Entrance) \n");
	}
	else if(nTripNo == 150 || nTripNo == 152 || nTripNo == 154 || nTripNo == 156 || nTripNo == 158 || nTripNo == 160)
	{
		printf("==========Drop-Off Points==========\n");
		printf("10 - College of St. Benilde (CSB) along Taft Avenue  \n");
		printf("11 - Gate 4: Gokongwei Gate \n");
		printf("12 - Gate 2: North Gate (HSSH) \n");
		printf("13 - Gate 1: South Gate (LS Building Entrance) \n");
	}
}

//This function generates a display of the seat plan within a trip.
void 
displayPassengerCount(struct Bus bus, int number)
{
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
}

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


/* inputTripNumber: Takes input from the user an
   @param bus - pointer to the bus the passenger will be encoded to
   @return int - the trip number the user input
*/
int 
inputTripNumber()
{
	int trip;
	printf("What trip will you be boarding? (Please input the 3-digit number of the trip exclusing the \"AE\")\n\n");
	
	displayTripList(0);
	
	printf("Enter Trip Number:");
	scanf("%d", &trip);

	if ( (trip >=101 && trip <= 109) || (trip >= 150 && trip <= 160) ) // IMPORTANT! Does not include logic for the special trips.
		return trip;
	else
	{
		printf("Please return a valid trip number and try again.\n");
		return inputTripNumber();
	}
}	

/* inputPassengerInformation: Takes input from the user for encoding the passenger information. 
   @param bus - pointer to the bus the passenger will be encoded to
   @return void
*/
void 
inputPassengerInformation(struct Bus *bus) 
{
	printf("==========Enter Details Below==========\n");
	int priority, id, dropOff;
	String20 firstName, lastName;

	printf("ID Number: ");
	scanf(" %d", &id);

	printf("First Name: ");
	scanf(" %s", firstName);

	printf("Last Name: ");
	scanf(" %s", lastName);
	
	printf("Priority Number: ");
	scanf(" %d", &priority);
	
	displayDropOff(bus->tripNumber);

	printf("Drop off Point: ");
	scanf(" %d", &dropOff);

	// Logic may be added here for implementation of bonus feature in the future

	inputPassenger(priority,
					firstName,
					lastName,
					id,
					dropOff,
					-1, bus);
}

/* encodePassengerInformation: Combines the functions inputTripNumber and inputPassengerInformation and creates the logic for 
   @param trips - array of all the busses
   @return void
*/
void 
encodePassengerInformation(struct Bus trips[])
{
	int tripNo = inputTripNumber();
	struct Bus *bus = getBusFromTripNumber(trips, 22, tripNo);

	inputPassengerInformation(bus);

	// Input Trip Number
	// Get Bus with corresponding trip number
		// If not full
			// Assign Passenger to trip (-1 for automatic assignment, specify number for specific assignment)
		// If full
			// If high priority passenger
				// Remove first lowest priority passenger and move them to next trip
			// else
				// remove passenger 
}