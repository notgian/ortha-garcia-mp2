/*********************************************************************************************************
This is to certify that this project is our own work, based on our combined personal efforts in studying and applying the concepts
learned. We have constructed the functions and their respective algorithms and corresponding code by ourselves. The
program was run, tested, and debugged by our own efforts. We further certify that we have not copied in part or whole or
otherwise plagiarized the work of other students and/or persons.
<Theon Schuyler S. Garcia>, DLSU ID# <12409537>, <Gian Lorenzo C. Ortha>, DLSU ID# <12414697>
*********************************************************************************************************/
#include <stdio.h>
#include <string.h>

#include "structures.h"

/* createEmptyPassenger: returns a Passenger with all values set to an empty value or zero.
    @return Passenger with empty or zero values   
*/ 
struct Passenger 
createEmptyPassenger() 
{
    struct Passenger emptyPassenger;
    emptyPassenger.onboard = 0;
    emptyPassenger.priority = 7;
    emptyPassenger.id = 0;
    emptyPassenger.dropOff = 0;
    emptyPassenger.reserved = 0;

    return emptyPassenger;
}

/* setEmptyPassengers: Takes an array of passengers and sets them all to empty
   @param *passengerList - array of passengers 
   @param n - number of passengers to set
   @return void
   Pre-condition: n is less than the size of the passengerList
*/ 
void 
setEmptyPassengers(struct Passenger *passengerList, int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        passengerList[i] = createEmptyPassenger();
    }
}

/* initializeBuses: Takes an two arrays of Bus with size 10 and 12 respectively for Manila and Laguna trips. Initializes the values for all buses. 
                    NOTE - Contents of arrays do not matter, only size. They contents will be set by this function.
   @param busesManilaToLaguna - array of buses, size 10  
   @param busesLagunaToManila - index of buses, size 12
   @return void
   Pre-condition: the trips array has a size of 22
*/ 
void 
initializeBuses(struct Bus trips[22])
{
    int i;
    for (i=0; i<MAX_TRIPS; i++)
    {
        struct Bus busInst; 
        busInst.next = NULL; //This is an initialization of each bus' next. Safeguard against segmentation fault.
        trips[i] = busInst;
    }

    for (i=0; i<MAX_TRIPS; i++)
    {   
        trips[i].dispatchable = 1;

        trips[i].tripNumber = -1; 
        trips[i].nReserveCount = 0;
        setEmptyPassengers(trips[i].passengers, MAX_PASSENGERS);

        int i;
        for (i = 0; i < MAX_ROUTE_LENGTH; i++)
        {
            trips[i].route[i] = 0;
        }   
        
    }

    int initialTripNo_A = 101; //Starting trip for Manila
    int initialTripNo_B = 150; //Starting trip for Laguna

    // Setting trip numbers and routes for the Manila to Laguna trip
    for (i=0; i<10; i++)
    {
        trips[i].tripNumber = initialTripNo_A + i;
        if (initialTripNo_A + i == 110)  
            trips[i].dispatchable = 0;
        
        if (i % 2 == 0) // Odd numbered buses
        {
            trips[i].route[0] = 20050;
            trips[i].route[1] = 10010; 
            trips[i].route[2] = 10020;
            trips[i].route[3] = 10040;
        }
        else // Even numbered buses
        {
            trips[i].route[0] = 20050;
            trips[i].route[1] = 10030; 
            trips[i].route[2] = 10040;
        }

        trips[i].next = NULL; //Secondary safeguard to ensure all next pointers are null.
    }

    // Setting trip numbers for the Laguna to Manila trip
    for (i=0; i<12; i++)
    {
        trips[i+10].tripNumber = initialTripNo_B + i;
        if (initialTripNo_B + i == 161)
            trips[i+10].dispatchable = 0;

        if (i % 2 == 0) // Even numbered buses
        {
            trips[i+10].route[0] = 10040; 
            trips[i+10].route[1] = 20010; 
            trips[i+10].route[2] = 20030;
            trips[i+10].route[3] = 20040;
            trips[i+10].route[4] = 20050;
        }
        else  // Odd numbered buses
        {
            trips[i+10].route[0] = 10040;
            trips[i+10].route[1] = 20020; 
            trips[i+10].route[2] = 20030;
            trips[i+10].route[3] = 20040;
            trips[i+10].route[4] = 20050;
        }

        trips[i+10].next = NULL;
    }

    for (i=MAX_TRIPS_MANILA-3; i>=0; i--)
    {
        trips[i].next = &trips[i+1];
    }

    for (i=MAX_TRIPS_LAGUNA-3; i>=0; i--)
    {
        trips[i+10].next = &trips[i+11];
    }
}