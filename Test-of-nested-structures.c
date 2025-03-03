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
	struct{
		string20 firstName;
    	string20 lastName;		
	}Name;
    int dropOff; // TBD how the final implementation of drop-off points will be
    char seat;
};

struct bus {
	int nTripID;
	struct passenger person[16];
	int nPassengerCount;
};

struct trips{
	struct bus buses[21];
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
		printf("1 - Mamplasan Toll Exit\n2 - Phase 5, San Jose Vilage\n");
		printf("3 - Milagros Del Rosario Building - East Canopy\n");
	}
	else if(nTripNo == 102 || nTripNo == 104 || nTripNo == 106
			|| nTripNo == 108)
	{
		printf("==========Drop-Off Points==========\n");
		printf("4 - Laguna Blvd. Guard House(across Paseo PHOENIX Gasoline Station)\n");
		printf("6 -  Milagros Del Rosario (MRR) Building - East Canopy\n");
	}
}

void checkTripNum(int nTripNo, struct trips *arrow){
		switch(nTripNo)
		{
			case 1:
				setPassengerInfo(&arrow->buses[0]);
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
			case 10:	
			case 11:
			case 12:
			case 13:
			case 14:
			case 15:
			case 16:
			case 17:
			case 18:
			case 19:
			case 20:
			case 21:
			default:
				break;
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
int encodeTripNumber()
{
	int trip;
	printf("What trip will you be boarding?\n\n");
	displayTripList(0);
	
	printf("Enter Trip Number:");
	scanf("%d", &trip);
	
	return trip;
}	

//Takes the nested structure array "person" and allows each member to receive an inputted value.
void setPassengerInfo(struct bus *trip) 
{
		if(trip->nPassengerCount < 16)
		{
		printf("==========Enter Details Below==========\n");
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
		trip->person[trip->nPassengerCount - 1].seat = 'X';
		}
		
}


int main()
{
	int nMain, nPersonnelMenu, nPassengerMenu, nTripNumber, i, j;
	
	struct trips arrow;
	
	//Initializing the trip IDs
	arrow.buses[0].nTripID = 101;
	arrow.buses[1].nTripID = 102;
	arrow.buses[2].nTripID = 103;
	arrow.buses[3].nTripID = 104;
	arrow.buses[4].nTripID = 105;
	arrow.buses[5].nTripID = 106;
	arrow.buses[6].nTripID = 107;
	arrow.buses[7].nTripID = 108;
	arrow.buses[8].nTripID = 109;
	arrow.buses[9].nTripID = 150;
	arrow.buses[10].nTripID = 151;
	arrow.buses[11].nTripID = 152;
	arrow.buses[12].nTripID = 153;
	arrow.buses[13].nTripID = 154;
	arrow.buses[14].nTripID = 155;
	arrow.buses[15].nTripID = 156;
	arrow.buses[16].nTripID = 157;
	arrow.buses[17].nTripID = 158;
	arrow.buses[18].nTripID = 159;
	arrow.buses[19].nTripID = 160;
	arrow.buses[20].nTripID = 161;
	
	//Initializing starting passenger count.
	for(i = 0; i < 21; i++)
		arrow.buses[i].nPassengerCount = 0;
		
	//Initializing seats to be empty.
	for(i=0; i < 21; i++)
		for(j=0; j < 16; j++)
		arrow.buses[i].person[j].seat = 'O';
	
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
			switch(nPassengerMenu)
			{
				case 1: 
					printf("==========Desired Trip==========\n");
					nTripNumber = encodeTripNumber();
					checkTripNum(nTripNumber, &arrow);
					break;
				case 2:
					printf("Returning to Main Menu\n");
			}		
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