/*********************************************************************************************************
This is to certify that this project is my own work, based on my personal efforts in studying and applying the concepts
learned. I have constructed the functions and their respective algorithms and corresponding code by myself. The
program was run, tested, and debugged by my own efforts. I further certify that I have not copied in part or whole or
otherwise plagiarized the work of other students and/or persons.
<Theon Schuyler S. Garcia>, DLSU ID# <12409537>
*********************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <time.h>

typedef char string20[20];
typedef string20 passengers[16];

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

void 
passengerMenu()
{
	printf("==========Passenger Menu==========\n");
	printf("1 - Encode Passenger Information\n2 - Back to Main Menu\n");
	printf("Select an Option: ");
}

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
		

int main()
{
	int i, nMain, nPersonnelMenu, nPriority, nRush;
	
	//Manila Trip Arrays
	char AE101[16] = {'X','X','X','X','X','X','O','X','X','X','X','X','X','X','X','X'};
	passengers AE102 = {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'};
	passengers AE103 = {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'};	
	passengers AE104 = {};
	passengers AE105 = {};
	passengers AE106 = {};
	passengers AE107 = {};
	passengers AE108 = {};
	passengers AE109 = {};
	
	//Manila Special Array
	passengers AE110 = {};
	
	//Laguna Trip Arrays
	passengers AE150 = {};
	passengers AE151 = {};
	passengers AE152 = {};
	passengers AE153 = {};
	passengers AE154 = {};
	passengers AE155 = {};
	passengers AE156 = {};
	passengers AE157 = {};
	passengers AE158 = {};
	passengers AE159 = {};
	passengers AE160 = {};
	
	//Laguna Special Array
	passengers AE161 = {};
	
 
	mainMenu();
		scanf("%d", &nMain);
		printf("\n\n");
	
	switch(nMain)
	{
	case 1:
		passengerMenu();
		printf("\n\n");
		break;
	case 2:
		arrowsPersonnelMenu();
			scanf("%d", &nPersonnelMenu);
			switch(nPersonnelMenu)
			{
				case 1:
					viewPassengerCount(AE101, 0);
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
	return 0;
}