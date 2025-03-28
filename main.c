#include <stdio.h>
#include <string.h>
#include <math.h>

#include "structures.c"
#include "operations.c"

int main()
{
    struct Bus trips[22];

    String20 john = "john";
    String20 doe = "doe";

    initializeBuses(trips);

    // TODO: Remove since this was only for debugging
    int i, j;

    for (i=0; i<MAX_TRIPS_MANILA-2; i++)
    {
        for (j=0; j<MAX_PASSENGERS; j++)
        {
            inputPassenger(1, john, doe, 12313412, 10010, -1, &trips[i], 0);
        }
    }

    for (i=MAX_TRIPS_MANILA; i<MAX_TRIPS-2; i++)
    {
        for (j=0; j<MAX_PASSENGERS; j++)
        {
            inputPassenger(1, john, doe, 12313412, 10010, -1, &trips[i], 0);
        }
    }

    for (j=1; j<MAX_PASSENGERS; j++)
    {
        inputPassenger(1, john, doe, 12313412, 10010, -1, &trips[MAX_TRIPS-1], 0);
    }

    for (j=1; j<MAX_PASSENGERS; j++)
    {
        inputPassenger(1, john, doe, 12313412, 10010, -1, &trips[MAX_TRIPS_MANILA-2], 0);
    }

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
    clearScreen();
    
    printf("Saving trip information before closing the program...\n");

    int validInput = 0;
    int day, month, year;
    String20 dateStr;
    while (!validInput)
    {
        printf("Please enter the date in this following format (pad zeroes if necessary for day and month): dd-mm-yyyy\n");
        scanf("%20s", dateStr);

        // Validate String Format
        int validStringFormat = 1;
        if (strlen(dateStr) == 10)
        {
            int i; // Validating that numbers are in the right place
            for (i=0; i<10; i++)
            {
                if (i != 2 && i != 5 && (dateStr[i] < '0' || dateStr[i] > '9')) // exclude the hyphens
                {
                    validStringFormat = 0;
                }
            }
        }
        
        if (validStringFormat)
        {
            String20 DDstr = {dateStr[0], dateStr[1], '\0'};
            String20 MMstr = {dateStr[3], dateStr[4], '\0'};;
            String20 YYYYstr = {dateStr[6], dateStr[7], dateStr[8], dateStr[9], '\0'};

            day = stringToInt(DDstr);
            month = stringToInt(MMstr);
            year = stringToInt(YYYYstr);

            printf("%s-%s-%s\n", DDstr, MMstr, YYYYstr);
            printf("%d-%d-%d\n", day, month, year);
        
            int validDay = 0;
            int validMonth = 0;
            int validYear = 0;

            // Validate Month
            if (month >= 1 && month <= 12)
                validMonth = 1;
            
            // Validate Day
            if ( (month == 1 || // Months with 31 days
                month == 3 || 
                month == 5 || 
                month == 7 || 
                month == 8 || 
                month == 10 || 
                month == 12) && day <= 31 ) 
                validDay = 1;

            else if ((month == 4 || // Months with 30 days
                    month == 6 || 
                    month == 9 || 
                    month == 11) && day <= 30)
                validDay = 1;

            else if (month == 2){ // February
                int leapYear = 0;

                if (year % 400 == 0) {
                    leapYear = 1;
                }
                else if (year % 4 == 0 && year % 100 != 0) {
                    leapYear = 1;
                }

                if (leapYear && day <= 29)
                    validDay = 1;
                else if (!leapYear && day <= 28)
                    validDay = 1;
            }

            // Validate Year
            if (year >= 1000 && year <= 9999)
                validYear = 1;

            // Finally validate input
            if (validDay && validMonth && validYear)
                validInput = 1;
        }
    }

    printf("Saving trip information for %02d-%02d-%4d...\n", day, month, year);

    // int i, j;
    FILE *fp;
    String20 filenamePrefix;
    sprintf(filenamePrefix, "%02d-%02d-%4d", day, month, year); // TODO: ask sir if this is allowed

    String20 fileNameTxt;

    strcpy(fileNameTxt, filenamePrefix);
    strcat(fileNameTxt, ".txt");

    fp = fopen(fileNameTxt, "w");

    for (i=0; i<MAX_TRIPS; i++)
    {
        String50 embarkPointName;
        getDropOffPointFromCode(trips[i].route[0], embarkPointName);

        for (j=0; j<MAX_PASSENGERS; j++)
        {
            if (trips[i].passengers[j].onboard)
            {
                String50 dropOffName;
                getDropOffPointFromCode(trips[i].passengers[j].dropOff, dropOffName);
                
                fprintf(fp, "Trip Number: %3d\n", trips[i].tripNumber);
                fprintf(fp, "Embarkation Point: %s\n", embarkPointName);
                fprintf(fp, "Passenger Name: %s, %s\n", trips[i].passengers[j].lastName, trips[i].passengers[j].firstName);
                fprintf(fp, "ID Number: %d\n", trips[i].passengers[j].id);
                fprintf(fp, "Priority: %d\n", trips[i].passengers[j].priority);
                fprintf(fp, "Drop-Off Point: %s\n\n", dropOffName);
            }
        }
    }

    fclose(fp);

	printf("Closing program...");
	
	
}