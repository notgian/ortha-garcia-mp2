#include <stdio.h>
#include <string.h>

#include "structures.c"
#include "operations.c"

int main()
{
    struct Bus trips[22];

    String20 john = "john";
    String20 johnass = "johnass";
    String20 doe = "doe";

    initializeBuses(trips);

    // TODO: Remove since this was only for debugging
    int i;
    // for (i=0; i<MAX_TRIPS; i++)
    // {
    //     printf("\n\nAE-%d\n", trips[i].tripNumber);
    //     for (j=0; j<MAX_ROUTE_LENGTH; j++)
    //     {
    //         printf("%d\n", trips[i].route[j]);
    //     }
    // }

    for (i=0; i<MAX_TRIPS; i++)
    {
        printf("Trip Number: %d\n", trips[i].tripNumber);

        if (trips[i].next != NULL)
            printf("   Next: %d\n", trips[i].next->tripNumber);
    }

    

    inputPassenger(1, john, doe, 12313412, 10010, 1, &trips[0], 0);
    inputPassenger(1, john, doe, 12313412, 10010, 2, &trips[0], 0);
    inputPassenger(1, john, doe, 12313412, 10010, 3, &trips[0], 0);
    inputPassenger(2, john, doe, 12313412, 10010, 4, &trips[0], 0);
    inputPassenger(1, john, doe, 12313412, 10030, 5, &trips[0], 0);
    inputPassenger(1, john, doe, 12313412, 10030, 6, &trips[0], 0);
    inputPassenger(1, john, doe, 12313412, 10020, 7, &trips[0], 0);
    inputPassenger(1, john, doe, 12313412, 10020, 8, &trips[0], 0);
    inputPassenger(1, john, doe, 12313412, 10020, 9, &trips[0], 0);
    inputPassenger(2, john, doe, 12313412, 10020, 10, &trips[0], 0);
    inputPassenger(1, john, doe, 12313412, 10020, 11, &trips[0], 0);
    inputPassenger(1, john, doe, 12313412, 10010, 12, &trips[0], 0);
    inputPassenger(2, john, doe, 12313412, 10010, 13, &trips[0], 0);
    inputPassenger(1, john, doe, 12313412, 10010, 14, &trips[0], 0);
    inputPassenger(1, john, doe, 12313412, 10010, 15, &trips[0], 0);
    inputPassenger(1, johnass, john, 12313412, 10010, 16, &trips[0], 0);


	int screenState = 100;
    int nFullA = 0;
    int nFullB = 0;

	while (screenState > 0)
	{
		int parentMenu = screenState - screenState % 100;
		// int subMenu = screenState % 100;

		if (parentMenu == 100) // Selected menu is main menu
			screenState = mainMenu();
		
		else if (parentMenu == 200) // Selected menu is passenger
		{
			screenState = passengerMenu(trips, &nFullA, &nFullB);
		}
		else if (parentMenu == 300) // Selected Menu is arrow personnel
		{
			screenState = arrowsPersonnelMenu(trips, &nFullA, &nFullB);
		}
	}

	// TODO: Include logic here for closing up the program.

	printf("Closing program... \n Don't forget to include the logic here btw to whoever is coding this rn");
	
	
}