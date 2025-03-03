/*********************************************************************************************************
This is to certify that this project is my own work, based on my personal efforts in studying and applying the concepts
learned. I have constructed the functions and their respective algorithms and corresponding code by myself. The
program was run, tested, and debugged by my own efforts. I further certify that I have not copied in part or whole or
otherwise plagiarized the work of other students and/or persons.
<Theon Schuyler S. Garcia>, DLSU ID# <12409537> , 
*********************************************************************************************************/

#include <stdio.h>
#include <string.h>

typedef char string20[21];
typedef string20 passengers[16];
typedef char String30[31];

struct passenger{
	int nPriority;
    int idNo;
	struct {
		string20 firstName;
    	string20 lastName;		
	}Name;
    int dropOff; // TBD how the final implementation of drop-off points will be
};

struct bus {
	int nTripID;
	struct passenger person[16];
	int nPassengerCount;
};

/* mainMenu displays the main menu of the program
*/
void 
mainMenu()
{
	printf("==========Main Menu==========\n");
	printf("Select user type:\n");
	printf("1 - Passenger\n2 - Arrows Personnel\n3 - Exit Program (End of Day)\n");
	printf("User type: ");
}

//This function displays the different menu options for a passenger
void 
passengerMenu()
{
	printf("==========Passenger Menu==========\n");
	printf("1 - Encode Passenger Information\n2 - Back to Main Menu\n");
	printf("Select an Option: ");
}


//This function displays the different menu options for "Arrows Personnel"
void 
arrowsPersonnelMenu()
{
	printf("==========Arrows Personnel Menu==========\n");
	printf("1 - View Passenger Count\n2 - View Drop-Off Count\n");
	printf("3 - View Passenger Information\n4 - Load Passenger(Single Passenger)\n");
	printf("5 - Search Passenger\n6 - Load Recent Trip File for Viewing\n");
	printf("7 - Back to Main Menu\n");
	printf("Select an Option: ");
}

//This function displays the list of trips.
void 
displayTripList(int nFull)
{
	printf("==========List of Trips==========\n\n");
	//Manila
	printf("==========MANILA-LAGUNA==========\n");
	printf("1 - AE101\n2 - AE102\n3 - AE103\n4 - AE104\n5 - AE105\n");
	printf("6 - AE106\n7 - AE107\n8 - AE108\n9 - AE109\n");
	//Laguna
	printf("==========LAGUNA-MANILA==========\n");
	printf("10 - AE150\n11 - AE151\n12 - AE152\n13 - AE153\n14 - AE154\n");
	printf("15 - AE155\n16 - AE156\n17 - AE157\n18 - AE158\n19 - AE159\n20 - AE160\n");
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
		printf("1 - Mamplasan Toll Exit\n 2 - Phase 5, San Jose Vilage\n");
		printf("3 - Milagros Del Rosario Building - East Canopy");
	}
	else if(nTripNo == 102 || nTripNo == 104 || nTripNo == 106
			|| nTripNo == 108)
	{
		printf("==========Drop-Off Points==========\n");
		printf("4 - Laguna Blvd. Guard House(across Paseo PHOENIX Gasoline Station)\n");
		printf("6 -  Milagros Del Rosario (MRR) Building - East Canopy\n");
	}
}

//This function generates a display of the seat plan within a trip.
void 
viewPassengerCount(char arr[], int nRush)
{
	int nRow, nColumn, n;
	
	n = 0;
	
	if(nRush != 1)
		for(nRow = 0; nRow < 5; nRow++)
		{
			if(nRow < 4)
			{
				printf("+-----+-----+-----+\n");
				for(nColumn = 0; nColumn < 3; nColumn++)
				{
					printf("|  %1c  ", arr[n]);
					n++;
				}
				printf("|");
				printf("\n");
				printf("+-----+-----+-----+\n");
			}
			else
			{
				printf("+-----+-----+\n");
				printf("|  %1c  |  D  |\n", arr[n]);
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
					printf("|  %1c  ", arr[n]);
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
					
						printf("|  %1c  ", arr[n]);
						n++;
					}
				}
				printf("|");
				printf("\n");
				printf("+-----+-----+-----+-----+\n");	
			}
			else
			{
				printf("+-----+-----+\n");
				printf("|  %1c  |  D  |\n", arr[n]);
				printf("+-----+-----+\n");
			}
		}		
}

//Takes the input of the passenger and returns trip number for assignment.
int encodeTripNumber(int nFull)
{
	int trip;
	printf("What trip will you be boarding?\n\n");
	displayTripList(nFull);
	
	printf("Enter Trip Number:");
	scanf("%d", &trip);
	
	return trip;
}	

//Takes the nested structure array "person" and allows each member to receive an inputted value.
void setPassengerInfo(struct bus *trip) 
{
		if(trip->nPassengerCount < 16)
		{
		trip->nPassengerCount += 1;
		printf("ID Number: ");
		scanf("%d", &trip->person[trip->nPassengerCount - 1].idNo);
		printf("First Name: ");
		scanf("%s", trip->person[trip->nPassengerCount - 1].Name.firstName);
		printf("Last Name: ");
		scanf("%s", trip->person[trip->nPassengerCount - 1].Name.lastName);
		printf("Priority Number: ");
		scanf("%d", &trip->person[trip->nPassengerCount - 1].nPriority);
		
		displayDropOff(trip->nTripID);
		printf("Drop off Point: ");
		scanf("%d", &trip->person[trip->nPassengerCount - 1].dropOff);
		}
		else if
}


int main()
{
	int nMain, nPersonnelMenu, nPassengerMenu, nTripNumber;
	
	//Creating structs for the buses.
	struct bus AE101, AE102, AE103, AE104, AE105, AE106, AE107, AE108, AE109,
				AE150, AE151, AE152, AE153, AE154, AE155, AE156, AE157, AE158,
				AE159, AE160, AE161;
				
	//Initializing each structures' trip ID.
	AE101.nTripID = 101;
	AE102.nTripID = 102;
	AE103.nTripID = 103;
	AE104.nTripID = 104;
	AE105.nTripID = 105;
	AE106.nTripID = 106;
	AE107.nTripID = 107;
	AE108.nTripID = 108;
	AE109.nTripID = 109;
	AE150.nTripID = 150;
	AE151.nTripID = 151;
	AE152.nTripID = 152;
	AE153.nTripID = 153;
	AE154.nTripID = 154;
	AE155.nTripID = 155;
	AE156.nTripID = 156;
	AE157.nTripID = 157;
	AE158.nTripID = 158;
	AE159.nTripID = 159;
	AE160.nTripID = 160;
	AE161.nTripID = 161;
	
	//Initializing trips' passenger count.
	AE101.nPassengerCount = 0;
	AE102.nPassengerCount = 0;
	AE103.nPassengerCount = 0;
	AE104.nPassengerCount = 0;
	AE105.nPassengerCount = 0;
	AE106.nPassengerCount = 0;
	AE107.nPassengerCount = 0;
	AE108.nPassengerCount = 0;
	AE109.nPassengerCount = 0;
	AE150.nPassengerCount = 0;
	AE151.nPassengerCount = 0;
	AE152.nPassengerCount = 0;
	AE153.nPassengerCount = 0;
	AE154.nPassengerCount = 0;
	AE155.nPassengerCount = 0;
	AE156.nPassengerCount = 0;
	AE157.nPassengerCount = 0;
	AE158.nPassengerCount = 0;
	AE159.nPassengerCount = 0;
	AE160.nPassengerCount = 0;
	AE161.nPassengerCount = 0;
	
 	do
	{
		mainMenu();
			scanf("%d", &nMain);
			printf("\n\n");
	
		
		switch(nMain)
		{
		case 1:
			passengerMenu();
			scanf("%d", &nPassengerMenu);
			printf("\n");		
			break;
		case 2:
			arrowsPersonnelMenu();
				scanf("%d", &nPersonnelMenu);
				switch(nPersonnelMenu)
				{
					case 1:
						displayTripList(0);
						break;                    
					case 2:
						break;
					case 3:
						break;
					case 4:
						break;
					case 5:
						break;
					case 6:
						break;
					case 7:
						break;
					default:
						break;
					
				}
			printf("\n\n");
			break;
		default:
			break;
		}	
	} while(nMain != 3);
	return 0;
}