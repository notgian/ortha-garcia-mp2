#include <stdio.h>
#include <string.h>

#include "passenger-operations.c"

int main()
{

	int nMain, nPersonnelMenu, nPassengerMenu;

    struct Bus trips[22];

    String20 john = "john";
    String20 doe = "doe";

    initializeBuses(trips);

    inputPassenger(1, john, doe, 12313412, 1, 1, &trips[0]);
    inputPassenger(1, john, doe, 12313412, 1, 2, &trips[0]);
    inputPassenger(1, john, doe, 12313412, 1, 3, &trips[0]);
    inputPassenger(1, john, doe, 12313412, 1, 4, &trips[0]);
    inputPassenger(1, john, doe, 12313412, 1, 5, &trips[0]);
    inputPassenger(1, john, doe, 12313412, 1, 6, &trips[0]);
    inputPassenger(1, john, doe, 12313412, 1, 7, &trips[0]);
    inputPassenger(1, john, doe, 12313412, 1, 8, &trips[0]);
    inputPassenger(1, john, doe, 12313412, 1, 9, &trips[0]);
    inputPassenger(1, john, doe, 12313412, 1, 10, &trips[0]);
    inputPassenger(1, john, doe, 12313412, 1, 11, &trips[0]);
    inputPassenger(1, john, doe, 12313412, 1, 12, &trips[0]);
    inputPassenger(1, john, doe, 12313412, 1, 13, &trips[0]);
    inputPassenger(1, john, doe, 12313412, 1, 14, &trips[0]);
    inputPassenger(1, john, doe, 12313412, 1, 15, &trips[0]);
    inputPassenger(1, john, doe, 12313412, 1, 16, &trips[0]);
	
    // Just a note: This is a very difficult way to make the menu readable. Better way IMO is make mainMenu call itself recursively until it needs to move on to another screen. Moving to another screen can be handled in the main func, with the different menu functions returning a different number for a different screen state that needs to be handled w/in main
 	do
	{
		mainMenu();
        scanf("%d", &nMain);
        printf("\n\n");

		switch(nMain)
		{
		case 1: // Opens the passenger Menu
			passengerMenu();
			scanf("%d", &nPassengerMenu);
			printf("\n");

			switch(nPassengerMenu)
			{
				case 1: // Encode Passenger Information
					encodePassengerInformation(trips);
					break;
				case 2: // Returns to the main menu
					printf("Returning to Main Menu\n");
			}		
			break;
		case 2: // Opens the arrow personnel menu
			arrowsPersonnelMenu();
				scanf("%d", &nPersonnelMenu);
				switch(nPersonnelMenu)
				{
					case 1:
						displayTripList(0);
						printf("Which trip would you like to view?\n");

                        int nTripNumber;
						scanf("%d", &nTripNumber);

                        struct Bus *bus = getBusFromTripNumber(trips, 22, nTripNumber);
						displayPassengerCount(*bus, nTripNumber);

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